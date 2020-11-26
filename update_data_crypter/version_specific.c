#include <stdint.h>
#include <string.h>

#include "version_specific.h"

/* ===================== AES IVEC ===================== */

const uint8_t aes_ivec__v_0_93[17] =
{
    0x00, 0x01, 0x02, 0x03,
    0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B,
    0x0C, 0x0D, 0x0E, 0x0F,
    0x00
};

const uint8_t aes_ivec__v_0_96[17] =
{
    0x00, 0x01, 0x02, 0x03,
    0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B,
    0x0C, 0x0D, 0x0E, 0x0F,
    0x00
};

/* ===================== AES KEY ===================== */

const uint8_t aes_key__v_0_93[17] =
{
    0x53, 0x7E, 0x15, 0x16,
    0x28, 0xAE, 0xD2, 0xA6,
    0xAB, 0xF7, 0x15, 0x88,
    0x09, 0xCF, 0x22, 0x3C,
    0x00
};

const uint8_t aes_key__v_0_96[17] =
{
    0xCF, 0x55, 0x5B, 0xB7,
    0xBF, 0x0E, 0x45, 0x6E,
    0x94, 0x10, 0xD0, 0x15,
    0xD7, 0x5F, 0xE3, 0x5B,
    0x00
};

E2_FW_version_t get_version_enum(char* version_string)
{
    if (strcmp(version_string, "0.93") == 0)
        return v0_93;
    if (strcmp(version_string, "0.96") == 0)
        return v0_96;
    return unknown;
}

void init_aes_ivec(uint8_t (*aes_ivec_dest)[17], E2_FW_version_t version)
{
    switch (version)
    {
    case v0_93:
        memcpy(*aes_ivec_dest, aes_ivec__v_0_93, sizeof(*aes_ivec_dest));
        break;
    
    case v0_96:
        memcpy(*aes_ivec_dest, aes_ivec__v_0_96, sizeof(*aes_ivec_dest));
        break;
    }
}

void init_aes_key(uint8_t (*aes_key_dest)[17], E2_FW_version_t version)
{
    switch (version)
    {
    case v0_93:
        memcpy(*aes_key_dest, aes_key__v_0_93, sizeof(*aes_key_dest));
        break;
    
    case v0_96:
        memcpy(*aes_key_dest, aes_key__v_0_96, sizeof(*aes_key_dest));
        break;
    }
}
