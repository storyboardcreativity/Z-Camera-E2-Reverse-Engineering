#include <stdio.h>
#include <stdarg.h>

#include "output.h"
#include "sc_logo.h"

void show_log(char *err_str, ...)
{
    va_list ptr;
    va_start(ptr, err_str);
    vprintf(err_str, ptr);
    printf("\n");
    va_end(ptr);
}

void show_error(char *err_str, ...)
{
    va_list ptr;
    va_start(ptr, err_str);
    printf("[ERROR] ");
    vprintf(err_str, ptr);
    printf("\n");
    va_end(ptr);
}

void show_prologue()
{
    printf("%s", storyboard_creativity_logo);
    printf("================================================================\n");
    printf("Storyboard Creativity | Z-CAM E2 update_data.bin packer/unpacker\n");
    printf("================================================================\n\n");
}

void show_usage(char *argv0)
{
    printf("\n================================================================\n");
    printf("Usage: %s <-d/-e> <-v#> -i <input_file_path> -o <output_file_path>\n\n", argv0);

    printf("\t-d - decrypt\n");
    printf("\t-e - encrypt\n");
    printf("\t-v# - firmware version (allowed: 0.87, 0.88, 0.93, 0.94, 0.95, 0.96, 0.97, 0.97.1, 0.98, 0.98.1, 0.98.2)\n\n");

    printf("Example (decrypt): %s -d -v0.96 -i update_data.bin -o update_data.zip\n", argv0);
    printf("Example (encrypt): %s -e -v0.96 -i update_data.zip -o update_data.bin\n", argv0);
}
