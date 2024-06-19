#include <Library/DeviceMemoryMapLib.h>

STATIC
ARM_MEMORY_REGION_DESCRIPTOR_EX
gDeviceMemoryDescriptorEx[] = {
  // Name, Address, Length, HobOption, ResourceAttribute, ArmAttributes, ResourceType, MemoryType

  // DDR Regions
  {"CPU Vectors",        0x80001000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
  {"UEFI Stack",         0x80002000, 0x00040000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
  {"DXE Heap",           0x80042000, 0x03C00000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK},
  {"RAM Partition",      0x83C42000, 0x0C5BE000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK},
  {"GSA",                0x90200000, 0x00400000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"UEFI FD",            0x92000000, 0x00200000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
  {"RAM Partition",      0x90600000, 0x01A00000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK},
  {"TPU",                0x93000000, 0x01000000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"AOC",                0x94000000, 0x03000000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"RAM Partition",      0x97000000, 0x20200000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK},
  // Memory Hole (0xB7200000 ->  0xC0000000)
  {"RAM Partition",      0xC0000000, 0x20000000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK},
  // Memory Hole (0xE0000000 ->  0xE2500000)
  {"RAM Partition",      0xE2500000, 0x16300000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK},
  {"ABL",                0xF8800000, 0x02000000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"RAM Partition",      0xFA800000, 0x00400000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK},
  {"Display Reserved",   0xFAC00000, 0x01124000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_THROUGH},
  {"RAM Partition",      0xFBD24000, 0x016CC000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK},
  {"DSS Log",            0xFD3F0000, 0x0000E000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"Debug Kinfo",        0xFD3FE000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"RAM Partition",      0xFD3FF000, 0x00401000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK},
  {"BLDR Log",           0xFD800000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"BLDR Log History",   0xFD900000, 0x00002000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"RAM Partition",      0xFD902000, 0x026FE000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK},
  // Memory Hole (0x100000000 -> 0x880000000)
  {"RAM Partition",      0x880000000, 0x980000000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK},

  // Register Regions
  {"GIC Distributor",    0x10400000, 0x00010000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   DEVICE},
  {"GIC Redistributors", 0x10440000, 0x00100000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   DEVICE},
  {"UART",               0x10A00000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   DEVICE},
  {"UFS HCI",            0x14700000, 0x00002000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   DEVICE},
  {"UFS UNIPRO",         0x14780000, 0x0000A000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   DEVICE},
  {"UFS UFSP",           0x14600000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   DEVICE},
  {"UFS PHY",            0x14704000, 0x00003000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   DEVICE},
  {"Pinctrl Alive",      0x174D0000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   DEVICE},
  {"Pinctrl Far Alive",  0x174E0000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   DEVICE},
  {"Pinctrl GSACTRL",    0x17940000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   DEVICE},
  {"Pinctrl GSACORE",    0x17A80000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   DEVICE},

  // Terminator for MMU
  {"Terminator", 0, 0, 0, 0, 0, 0, 0}
};

ARM_MEMORY_REGION_DESCRIPTOR_EX*
GetDeviceMemoryMap ()
{
  return gDeviceMemoryDescriptorEx;
}
