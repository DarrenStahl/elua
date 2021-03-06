// TM4C123GXL CPU definition

#ifndef __CPU_TM4C123GXL_H__
#define __CPU_TM4C123GXL_H__

#define TARGET_IS_BLIZZARD_RB1
#define PART_TM4C123GH6PM

#include <stdint.h>
#include <stdbool.h>

#include "proxima/spi_help.h"

#include "driverlib/sysctl.h"
#include "rom_map.h"
#include "stacks.h"
#include "hw_memmap.h"
#include "platform_ints.h"
#include "hw_ints.h"

#define NUM_PIO               6
#define NUM_SPI               4
#define NUM_UART              7
#define NUM_TIMER             6
#define NUM_PWM               0
#define NUM_ADC               12
#define NUM_CAN               0
#define NUM_I2C               2

#define ADC_BIT_RESOLUTION    10
#define ADC_PIN_CONFIG

// CPU frequency (needed by the CPU module and MMCFS code, 0 if not used)
#define CPU_FREQUENCY         MAP_SysCtlClockGet()

// PIO prefix ('0' for P0, P1, ... or 'A' for PA, PB, ...)
#define PIO_PREFIX            'A'
// Pins per port configuration:
// #define PIO_PINS_PER_PORT (n) if each port has the same number of pins, or
// #define PIO_PIN_ARRAY { n1, n2, ... } to define pins per port in an array
// Use #define PIO_PINS_PER_PORT 0 if this isn't needed
#define PIO_PIN_ARRAY         { 8, 8, 8, 8, 6, 5 }

// Internal Flash data
#define INTERNAL_FLASH_SIZE             ( 256 * 1024 )
#define INTERNAL_FLASH_WRITE_UNIT_SIZE  4
#define INTERNAL_FLASH_SECTOR_SIZE      1024
#define INTERNAL_FLASH_START_ADDRESS    0

// SD Card info
#define MMCFS_SPI_NUM 2
#define MMCFS_CUSTOM_CS
#define MMCFS_SELECT_FUNC(a) select_chip(1)
#define MMCFS_DESELECT_FUNC(a) select_chip(0)
#define MMCFS_CSSETUP_FUNC setup_select

#define SRAM_SIZE ( 0x8000 )
// Allocator data: define your free memory zones here in two arrays
// (start address and end address)
#define INTERNAL_RAM1_FIRST_FREE        end
#define INTERNAL_RAM1_LAST_FREE         ( SRAM_BASE + SRAM_SIZE - STACK_SIZE_TOTAL - 1 )

#define PLATFORM_CPU_CONSTANTS_INTS\
  _C( INT_UART_RX ),

#endif // #ifndef __CPU_TM4C123GXL_H__

