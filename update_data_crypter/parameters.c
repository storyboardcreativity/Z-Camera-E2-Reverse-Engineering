#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "parameters.h"
#include "output.h"

input_parameters_t process_parameters(int argc, char **argv)
{
    input_parameters_t parameters;
    memset(&parameters, 0x00, sizeof(input_parameters_t));

    for (int i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], "-d") == 0)
        {
            if (parameters.is_mode_initialized)
            {
                show_error("Processing mode is declared twice!");
                parameters.parsing_error_occured = true;
                break;
            }

            parameters.is_mode_initialized = true;
            parameters.is_encrypt_mode_on = false;
        }
        else if (strcmp(argv[i], "-e") == 0)
        {
            if (parameters.is_mode_initialized)
            {
                show_error("Processing mode is declared twice!");
                parameters.parsing_error_occured = true;
                break;
            }

            parameters.is_mode_initialized = true;
            parameters.is_encrypt_mode_on = true;
        }
        else if (strncmp(argv[i], "-v", 2) == 0)
        {
            if (parameters.selected_version != NULL)
            {
                show_error("Version is declared twice!");
                show_error("Previous declaration: \"%s\"", &parameters.selected_version[-2]);
                show_error("Current declaration: \"%s\"", argv[i]);
                parameters.parsing_error_occured = true;
                break;
            }
            parameters.selected_version = &argv[i][2];
        }
        else if (strcmp(argv[i], "-i") == 0)
        {
            if (parameters.input_file_path != NULL)
            {
                show_error("Input file path is declared twice!");
                show_error("Previous declaration: \"%s\"", parameters.input_file_path);
                show_error("Current declaration: \"%s\"", argv[i]);
                parameters.parsing_error_occured = true;
                break;
            }

            ++i;
            if (i >= argc)
            {
                show_error("Missing input file path after \"-i\" parameter!");
                parameters.parsing_error_occured = true;
                break;
            }
            parameters.input_file_path = argv[i];
        }
        else if (strcmp(argv[i], "-o") == 0)
        {
            if (parameters.output_file_path != NULL)
            {
                show_error("Output file path is declared twice!");
                show_error("Previous declaration: \"%s\"", parameters.output_file_path);
                show_error("Current declaration: \"%s\"", argv[i]);
                parameters.parsing_error_occured = true;
                break;
            }

            ++i;
            if (i >= argc)
            {
                show_error("Missing output file path after \"-o\" parameter!");
                parameters.parsing_error_occured = true;
                break;
            }
            parameters.output_file_path = argv[i];
        }
        else
        {
            show_error("Unknown argument: \"%s\"", argv[i]);
            parameters.parsing_error_occured = true;
            break;
        }
    }

    return parameters;
}

bool verify_parameters(input_parameters_t parameters)
{
    show_log("Selected settings:");
    show_log("------------------");

    bool params_ok = true;
    if (!parameters.is_mode_initialized)
    {
        show_error("Processing mode was not specified!");
        params_ok = false;
    }
    else
        show_log("Mode: %s", parameters.is_encrypt_mode_on ? "encrypt" : "decrypt");

    if (parameters.selected_version == NULL)
    {
        show_error("Firmware version was not specified!");
        params_ok = false;
    }
    else
        show_log("Firmware version: %s", parameters.selected_version);

    if (parameters.input_file_path == NULL)
    {
        show_error("Input file path was not specified!");
        params_ok = false;
    }
    else
        show_log("Input file: %s", parameters.input_file_path);

    if (parameters.output_file_path == NULL)
    {
        show_error("Output file path was not specified!");
        params_ok = false;
    }
    else
        show_log("Output file: %s", parameters.output_file_path);
    
    show_log("------------------\n");
    
    return params_ok;
}