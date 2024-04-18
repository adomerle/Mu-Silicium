#include <Library/BaseLib.h>
#include <Library/DeviceMemoryMapLib.h>

STATIC
ARM_MEMORY_REGION_DESCRIPTOR_EX
gDeviceMemoryDescriptorEx[] = {
  // Name, Address, Length, HobOption,
  // ResourceAttribute, ArmAttributes,
  // ResourceType, MemoryType

  // DDR Regions
  {"UEFI FD", 0x80000000, 0x00200000, AddMem,
   EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
   EfiBootServicesData, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK},
  
  {"CPU Vectors", 0x80200000, 0x00001000, AddMem,
   EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
   EfiBootServicesData, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK},

  {"UEFI Stack", 0x80201000, 0x00040000, AddMem,
   EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
   EfiBootServicesData, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK},
  
  {"DXE Heap", 0x80241000, 0x03C00000, AddMem,
   EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
   EfiConventionalMemory, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK},
  
  {"RAM Partition", 0x83E81000, 0x7C17F000, AddMem,
   EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
   EfiConventionalMemory, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK},

  // Register regions
  {"Gic", 0x50040000, 0x00002000, AddDev,
   EFI_RESOURCE_MEMORY_MAPPED_IO, EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE,
   EfiMemoryMappedIO, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE},
  
  {"Tegra Timer", 0x60005000, 0x00001000, AddDev,
   EFI_RESOURCE_MEMORY_MAPPED_IO, EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE,
   EfiMemoryMappedIO, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE},

  // Terminator for MMU
  {"Terminator", 0, 0, 0, 0, 0, 0, 0}
};

ARM_MEMORY_REGION_DESCRIPTOR_EX*
GetDeviceMemoryMap ()
{
  return gDeviceMemoryDescriptorEx;
}
