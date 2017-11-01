
#ifndef __FLASH_H__
#define __FLASH_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Values that can be passed to FlashProtectSet(), and returned by
// FlashProtectGet().
//
//*****************************************************************************
typedef enum
{
    FlashReadWrite,                         // Flash can be read and written
    FlashReadOnly,                          // Flash can only be read
    FlashExecuteOnly                        // Flash can only be executed
}
tFlashProtection;

//*****************************************************************************
//
// Values passed to FlashIntEnable(), FlashIntDisable() and FlashIntClear() and
// returned from FlashIntStatus().
//
//*****************************************************************************
#define FLASH_INT_PROGRAM     0x00000002 // Programming Interrupt Mask
#define FLASH_INT_ACCESS      0x00000001 // Access Interrupt Mask
#define FLASH_INT_EEPROM      0x00000004 // EEPROM Interrupt Mask
#define FLASH_INT_VOLTAGE_ERR 0x00000200 // Voltage Error Interrupt Mask
#define FLASH_INT_DATA_ERR    0x00000400 // Invalid Data Interrupt Mask
#define FLASH_INT_ERASE_ERR   0x00000800 // Erase Error Interrupt Mask
#define FLASH_INT_PROGRAM_ERR 0x00002000 // Program Verify Error Interrupt Mask

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern int32_t FlashErase(uint32_t ui32Address);
extern int32_t FlashProgram(uint32_t *pui32Data, uint32_t ui32Address,
                            uint32_t ui32Count);
extern tFlashProtection FlashProtectGet(uint32_t ui32Address);
extern int32_t FlashProtectSet(uint32_t ui32Address,
                               tFlashProtection eProtect);
extern int32_t FlashProtectSave(void);
extern int32_t FlashUserGet(uint32_t *pui32User0, uint32_t *pui32User1);
extern int32_t FlashUserSet(uint32_t ui32User0, uint32_t ui32User1);
extern int32_t FlashUserSave(void);
extern void FlashIntRegister(void (*pfnHandler)(void));
extern void FlashIntUnregister(void);
extern void FlashIntEnable(uint32_t ui32IntFlags);
extern void FlashIntDisable(uint32_t ui32IntFlags);
extern uint32_t FlashIntStatus(bool bMasked);
extern void FlashIntClear(uint32_t ui32IntFlags);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __DRIVERLIB_FLASH_H__
