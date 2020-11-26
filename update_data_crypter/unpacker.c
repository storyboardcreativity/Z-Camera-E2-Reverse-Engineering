#include <openssl/aes.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <memory.h>

#include "output.h"
#include "parameters.h"
#include "version_specific.h"

int main(int argc, char **argv)
{
    show_prologue();

    input_parameters_t parameters = process_parameters(argc, argv);
    if (parameters.parsing_error_occured)
    {
        show_error("Errors occured at parameters processing!");
        show_usage(argv[0]);
        return -1;
    }

    if (!verify_parameters(parameters))
    {
        show_usage(argv[0]);
        return -1;
    }

    E2_FW_version_t version = get_version_enum(parameters.selected_version);
    if (version == unknown)
    {
        show_error("Unknown firmware version: \"%s\"", parameters.selected_version);
        show_usage(argv[0]);
        return -1;
    }

    uint8_t aes_ivec[17];
    init_aes_ivec(&aes_ivec, version);

    uint8_t aes_key[17];
    init_aes_key(&aes_key, version);

    AES_KEY aes_key_obj;
    AES_set_encrypt_key(aes_key, 128LL, &aes_key_obj);

    show_log("AES initialized. Opening files...");

    FILE *fp_in = fopen(parameters.input_file_path, "rb");
    if (!fp_in)
    {
        show_error("Could not open input file!");
        return -1;
    }

    FILE *fp_out = fopen(parameters.output_file_path, "wb");
    if (!fp_out)
    {
        show_error("Could not open output file!");
        fclose(fp_in);
        return -1;
    }

    show_log("Files opened. Processing blocks...");

    uint8_t bytes_in[16];
    uint8_t bytes_out[17];
    int block_size;
    int aes_num = 0;

    for (int i = 1; true; ++i)
    {
        block_size = fread(bytes_in, 1, 16, fp_in);
        if (block_size <= 0)
            break;

        AES_cfb128_encrypt(
            bytes_in, bytes_out, block_size,
            &aes_key_obj, aes_ivec, &aes_num,
            parameters.is_encrypt_mode_on ? AES_ENCRYPT : AES_DECRYPT);
        fwrite(bytes_out, 1, block_size, fp_out);

        if (i % 700000 == 0)
            show_log("Wrote %d'th block.", i);
    }

    show_log("Finished process. Closing files...");

    fclose(fp_in);
    fclose(fp_out);

    show_log("Done!");

    return 0;
}