CC := gcc
CFL := -std=gnu99 -ggdb -fPIC
TOOLCHAIN :=
OUT_EXECUTABLE_NAME := unpacker0
ARCH :=
LIBS := -lssl -lcrypto
SOURCE_FILES := unpacker.c output.c parameters.c version_specific.c

all:
	$(TOOLCHAIN)$(CC) $(CFL) $(ARCH) $(SOURCE_FILES) $(LIBS) -o $(OUT_EXECUTABLE_NAME)

clear:
	rm -f *.o
	rm -f $(OUT_EXECUTABLE_NAME)