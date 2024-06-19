#include <Base.h>
#include <Library/IoLib.h>
#include <Library/DebugLib.h>
#include <Library/MemoryMapHelperLib.h>
#include <Library/SerialPortLib.h>

UINTN gUartBaseAddress = 0;

#define S3C_UFCON      (0x08)
#define S3C_UTRSTAT    (0x10)
#define S3C_UFSTAT     (0x18)
#define S3C_TX         (0x20)
#define S3C_RX         (0x24)

#define TXFULL (BIT24)
#define RXFULL (BIT8)

#define S3C_UFCON_FIFO   (BIT0)
#define S3C_UTRSTAT_TXFE (BIT3)

RETURN_STATUS
EFIAPI
SerialPortInitialize (
  VOID
  )
{
  ARM_MEMORY_REGION_DESCRIPTOR_EX UartMemoryRegion;
  EFI_STATUS Status = LocateMemoryMapAreaByName ("UART", &UartMemoryRegion);
  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "Failed to UART MMIO Address!\n"));

    return RETURN_DEVICE_ERROR;
  }

  gUartBaseAddress = UartMemoryRegion.Address;

  return RETURN_SUCCESS;
}

VOID
SamsungBusyUart (
  VOID
)
{
  while (!(MmioRead32(gUartBaseAddress + S3C_UTRSTAT) & S3C_UTRSTAT_TXFE));
}

VOID
SamsungBusyUartFifo (
  VOID
)
{
  while (MmioRead32(gUartBaseAddress + S3C_UFSTAT) & TXFULL);
}

VOID
SamsungPutChar (
  IN UINT8 Char
)
{
  if (MmioRead32(gUartBaseAddress + S3C_UFCON) & S3C_UFCON_FIFO) {
    SamsungBusyUartFifo();
  } else {
    SamsungBusyUart();
  }
  MmioWrite32(gUartBaseAddress + S3C_TX, Char);
}

UINTN
EFIAPI
SerialPortWrite (
  IN UINT8     *Buffer,
  IN UINTN     NumberOfBytes
)
{
  for (UINTN i = 0; i < NumberOfBytes; i++) {
    SamsungPutChar(Buffer[i]);
  }
  return NumberOfBytes;
}

UINTN
EFIAPI
SerialPortRead (
  OUT UINT8     *Buffer,
  IN  UINTN     NumberOfBytes
)
{
  return 0;
}

BOOLEAN
EFIAPI
SerialPortPoll (
  VOID
  )
{
  return FALSE;
}

RETURN_STATUS
EFIAPI
SerialPortSetControl (
  IN UINT32 Control
  )
{
  return RETURN_UNSUPPORTED;
}

RETURN_STATUS
EFIAPI
SerialPortGetControl (
  OUT UINT32 *Control
  )
{
  return RETURN_UNSUPPORTED;
}

RETURN_STATUS
EFIAPI
SerialPortSetAttributes (
  IN OUT UINT64             *BaudRate,
  IN OUT UINT32             *ReceiveFifoDepth,
  IN OUT UINT32             *Timeout,
  IN OUT EFI_PARITY_TYPE    *Parity,
  IN OUT UINT8              *DataBits,
  IN OUT EFI_STOP_BITS_TYPE *StopBits
  )
{
  return RETURN_UNSUPPORTED;
}