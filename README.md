# Dual building for 3DS and Switch Homebrew

## Abstract
Nintendo 3DS and Switch homebrew is built with 2 libraries, libctru and libnx for 3DS and Switch respectively. This whole repo is specifically for demonstrating how it could be done and why it could be a good or bad idea. You really shouldn't do this unless you know what you're doing.

The two makefiles for the systems (Makefile.3ds and Makefile.nx) are simply modified standard devkitPro brand Makefiles for each system, the only modifications are for the generated .elf files to have a suffix related to their respective system, two separate build folders for the project build files for each system, and some minor tweaks to make it work from another Makefile. The regular Makefile is just a sort of relayer, running `make` will build both 3DS and Switch binaries, where as `make nx` or `make 3ds` will build only for their systems.

## License
I don't care, just give credit where credit is due.