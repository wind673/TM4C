
#ifndef __SW_CRC_H__
#define __SW_CRC_H__

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
// Prototypes for the functions.
//
//*****************************************************************************
extern uint8_t Crc8CCITT(uint8_t ui8Crc, const uint8_t *pui8Data,
                         uint32_t ui32Count);
extern uint16_t Crc16(uint16_t ui16Crc, const uint8_t *pui8Data,
                      uint32_t ui32Count);
extern uint16_t Crc16Array(uint32_t ui32WordLen, const uint32_t *pui32Data);
extern void Crc16Array3(uint32_t ui32WordLen, const uint32_t *pui32Data,
                        uint16_t *pui16Crc3);
extern uint32_t Crc32(uint32_t ui32Crc, const uint8_t *pui8Data,
                      uint32_t ui32Count);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __DRIVERLIB_SW_CRC_H__
