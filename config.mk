
# the booloader to use in the disk image
KRONIX-BOOTLOADER := limine

# the architecture to build kronix for
KRONIX-ARCH := amd64

# the cpu/mcu/µarch to build kronix for
# can be any option that is valid as an argument to
# gcc's -march option
KRONIX-UARCH := native

# the cpu/mcu/µarch to tune kronix for
# can be any option that is valid as an argument to
# gcc's -mtune option
KRONIX-TUNE := native

# the profile to build the kernel with
# either :
#   - debug
#   - size
#   - debug-release
#   - release
KRONIX-PROFILE := debug