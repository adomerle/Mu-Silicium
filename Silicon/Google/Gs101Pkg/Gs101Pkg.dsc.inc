##
#  Copyright (c) 2011 - 2022, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2020, Intel Corporation. All rights reserved.
#  Copyright (c) 2018, Bingxing Wang. All rights reserved.
#  Copyright (c) Microsoft Corporation.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
##

[Defines]
  USE_CUSTOM_GIC     = 0
  USE_CUSTOM_TIMER   = 0
  USE_PHYSICAL_TIMER = 0

[BuildOptions]
  *_*_AARCH64_CC_FLAGS = -march=armv8.2-a+crypto+rcpc

[PcdsFixedAtBuild]
  # Timer
  gArmTokenSpaceGuid.PcdArmArchTimerFreqInHz|24576000
  gArmTokenSpaceGuid.PcdArmArchTimerSecIntrNum|19
  gArmTokenSpaceGuid.PcdArmArchTimerIntrNum|20
  gArmTokenSpaceGuid.PcdArmArchTimerVirtIntrNum|27
  gArmTokenSpaceGuid.PcdArmArchTimerHypIntrNum|26

  # GIC
  gArmTokenSpaceGuid.PcdGicDistributorBase|0x10400000
  gArmTokenSpaceGuid.PcdGicRedistributorsBase|0x10440000
  gArmTokenSpaceGuid.PcdGicInterruptInterfaceBase|25

  # ACPI
  gEfiMdeModulePkgTokenSpaceGuid.PcdAcpiDefaultOemRevision|0x00000101

  # SmBios
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosProcessorModel|"Google Tensor GS101 @ 2.8 GHz"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosProcessorRetailModel|"GS101"

  # CPU
  gArmPlatformTokenSpaceGuid.PcdCoreCount|8
  gArmPlatformTokenSpaceGuid.PcdClusterCount|3

[Components]
  Gs101Pkg/Drivers/SmBiosTableDxe/SmBiosTableDxe.inf

!include GooglePkg/GooglePkg.dsc.inc

[LibraryClasses]
  PlatformPeiLib|Gs101Pkg/Library/PlatformPeiLib/PlatformPeiLib.inf
  PlatformPrePiLib|Gs101Pkg/Library/PlatformPrePiLib/PlatformPrePiLib.inf
  HwResetSystemLib|ArmPkg/Library/ArmSmcPsciResetSystemLib/ArmSmcPsciResetSystemLib.inf
  ResetSystemLib|ArmPkg/Library/ArmSmcPsciResetSystemLib/ArmSmcPsciResetSystemLib.inf
  SoCPlatformLib|Gs101Pkg/Library/SoCPlatformLib/SoCPlatformLib.inf

!if $(TARGET) == DEBUG
  SerialPortLib|Gs101Pkg/Library/SerialPortLib/SerialPortLib.inf
!endif