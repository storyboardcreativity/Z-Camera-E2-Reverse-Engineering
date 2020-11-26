#pragma once

#include <stdint.h>

typedef enum E2_FW_version
{
    unknown,
    v0_93,
    v0_96
} E2_FW_version_t;

E2_FW_version_t get_version_enum(char* version_string);
void init_aes_ivec(uint8_t (*aes_ivec_dest)[17], E2_FW_version_t version);
void init_aes_key(uint8_t (*aes_key_dest)[17], E2_FW_version_t version);
