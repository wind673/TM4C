
#ifndef __HIBERNATE_H__
#define __HIBERNATE_H__

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
// Macros need to configure wake events for HibernateWakeSet()
//
//*****************************************************************************
#define HIBERNATE_WAKE_PIN      0x00000010
#define HIBERNATE_WAKE_RTC      0x00000008
#define HIBERNATE_WAKE_LOW_BAT  0x00000200

//*****************************************************************************
//
// Macros needed to configure low battery detect for HibernateLowBatSet()
//
//*****************************************************************************
#define HIBERNATE_LOW_BAT_DETECT                                              \
                                0x00000020
#define HIBERNATE_LOW_BAT_ABORT 0x000000A0
#define HIBERNATE_LOW_BAT_1_9V  0x00000000
#define HIBERNATE_LOW_BAT_2_1V  0x00002000
#define HIBERNATE_LOW_BAT_2_3V  0x00004000
#define HIBERNATE_LOW_BAT_2_5V  0x00006000

//*****************************************************************************
//
// Macros defining interrupt source bits for the interrupt functions.
//
//*****************************************************************************
#define HIBERNATE_INT_WR_COMPLETE                                             \
                                0x00000010
#define HIBERNATE_INT_PIN_WAKE  0x00000008
#define HIBERNATE_INT_LOW_BAT   0x00000004
#define HIBERNATE_INT_RTC_MATCH_0                                             \
                                0x00000001

//*****************************************************************************
//
// Macros defining oscillator configuration options for the
// HibernateClockConfig() function.
//
//*****************************************************************************
#define HIBERNATE_OSC_LOWDRIVE  0x00000000
#define HIBERNATE_OSC_HIGHDRIVE 0x00020000
#define HIBERNATE_OSC_DISABLE   0x00010000

//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************
extern void HibernateGPIORetentionEnable(void);
extern void HibernateGPIORetentionDisable(void);
extern bool HibernateGPIORetentionGet(void);
extern void HibernateEnableExpClk(uint32_t ui32HibClk);
extern void HibernateDisable(void);
extern void HibernateRTCEnable(void);
extern void HibernateRTCDisable(void);
extern void HibernateWakeSet(uint32_t ui32WakeFlags);
extern uint32_t HibernateWakeGet(void);
extern void HibernateLowBatSet(uint32_t ui32LowBatFlags);
extern uint32_t HibernateLowBatGet(void);
extern void HibernateRTCSet(uint32_t ui32RTCValue);
extern uint32_t HibernateRTCGet(void);
extern void HibernateRTCMatchSet(uint32_t ui32Match, uint32_t ui32Value);
extern uint32_t HibernateRTCMatchGet(uint32_t ui32Match);
extern void HibernateRTCTrimSet(uint32_t ui32Trim);
extern uint32_t HibernateRTCTrimGet(void);
extern void HibernateDataSet(uint32_t *pui32Data, uint32_t ui32Count);
extern void HibernateDataGet(uint32_t *pui32Data, uint32_t ui32Count);
extern void HibernateRequest(void);
extern void HibernateIntEnable(uint32_t ui32IntFlags);
extern void HibernateIntDisable(uint32_t ui32IntFlags);
extern void HibernateIntRegister(void (*pfnHandler)(void));
extern void HibernateIntUnregister(void);
extern uint32_t HibernateIntStatus(bool bMasked);
extern void HibernateIntClear(uint32_t ui32IntFlags);
extern uint32_t HibernateIsActive(void);
extern void HibernateRTCSSMatchSet(uint32_t ui32Match, uint32_t ui32Value);
extern uint32_t HibernateRTCSSMatchGet(uint32_t ui32Match);
extern uint32_t HibernateRTCSSGet(void);
extern void HibernateClockConfig(uint32_t ui32Config);
extern void HibernateBatCheckStart(void);
extern uint32_t HibernateBatCheckDone(void);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // __DRIVERLIB_HIBERNATE_H__
