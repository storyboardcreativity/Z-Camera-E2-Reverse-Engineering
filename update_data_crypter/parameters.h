#pragma once

typedef struct input_parameters
{
    bool parsing_error_occured;

    bool is_mode_initialized;
    bool is_encrypt_mode_on;

    char *input_file_path;
    char *output_file_path;
    char *selected_version;
} input_parameters_t;

input_parameters_t process_parameters(int argc, char **argv);
bool verify_parameters(input_parameters_t parameters);