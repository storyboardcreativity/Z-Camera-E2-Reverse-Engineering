#pragma once

#include <stdint.h>

typedef enum E2_FW_version
{
    unknown,
    v0_87,
    v0_88,
    v0_93,
    v0_94,
    v0_95,
    v0_96,
    v0_97,
    v0_97_1,
    v0_98,
    v0_98_1,
    v0_98_2
} E2_FW_version_t;

E2_FW_version_t get_version_enum(char* version_string);
void init_aes_ivec(uint8_t (*aes_ivec_dest)[17], E2_FW_version_t version);
void init_aes_key(uint8_t (*aes_key_dest)[17], E2_FW_version_t version);
