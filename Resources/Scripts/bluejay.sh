#!/bin/bash

# Build an Android kernel that is actually UEFI disguised as the Kernel
cat ./BootShim/AARCH64/BootShim.quirky.bin "./Build/bluejayPkg/${_TARGET_BUILD_MODE}_CLANGDWARF/FV/BLUEJAY_UEFI.fd" > "./Build/bluejayPkg/${_TARGET_BUILD_MODE}_CLANGDWARF/FV/BLUEJAY_UEFI.fd-bootshim"||exit 1
lz4 -c < "./Build/bluejayPkg/${_TARGET_BUILD_MODE}_CLANGDWARF/FV/BLUEJAY_UEFI.fd-bootshim" > "./Build/bluejayPkg/${_TARGET_BUILD_MODE}_CLANGDWARF/FV/BLUEJAY_UEFI.fd-bootshim.gz"||exit 1
cat "./Build/bluejayPkg/${_TARGET_BUILD_MODE}_CLANGDWARF/FV/BLUEJAY_UEFI.fd-bootshim.gz" ./Resources/DTBs/bluejay.dtb > ./Resources/bootpayload.bin||exit 1

python3 ./Resources/Scripts/mkbootimg.py \
  --kernel ./Resources/bootpayload.bin \
  --ramdisk ./Resources/ramdisk \
  --os_version "${BOOTIMG_OS_VERSION}" \
	--os_patch_level "${BOOTIMG_OS_PATCH_LEVEL}" \
  --pagesize 4096 \
	--kernel_offset 0x00000000 \
	--ramdisk_offset 0x00000000 \
	--tags_offset 0x00000000 \
	--os_version "13.0.0" \
	--os_patch_level "2022-10" \
  --header_version 4  \
  -o "boot.img" \
  ||_error "\nFailed to create Android Boot Image!\n"

mv boot.img Mu-bluejay.img||exit 1
