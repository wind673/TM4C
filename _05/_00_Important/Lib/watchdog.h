
#ifndef __WATCHDOG_H__
#define __WATCHDOG_H__

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
// The type of interrupt that can be generated by the watchdog.
//
//*****************************************************************************
#define WATCHDOG_INT_TYPE_INT   0x00000000
#define WATCHDOG_INT_TYPE_NMI   0x00000004

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern bool WatchdogRunning(uint32_t ui32Base);
extern void WatchdogEnable(uint32_t ui32Base);
extern void WatchdogResetEnable(uint32_t ui32Base);
extern void WatchdogResetDisable(uint32_t ui32Base);
extern void WatchdogLock(uint32_t ui32Base);
extern void WatchdogUnlock(uint32_t ui32Base);
extern bool WatchdogLockState(uint32_t ui32Base);
extern void WatchdogReloadSet(uint32_t ui32Base, uint32_t ui32LoadVal);
extern uint32_t WatchdogReloadGet(uint32_t ui32Base);
extern uint32_t WatchdogValueGet(uint32_t ui32Base);
extern void WatchdogIntRegister(uint32_t ui32Base, void (*pfnHandler)(void));
extern void WatchdogIntUnregister(uint32_t ui32Base);
extern void WatchdogIntEnable(uint32_t ui32Base);
extern uint32_t WatchdogIntStatus(uint32_t ui32Base, bool bMasked);
extern void WatchdogIntClear(uint32_t ui32Base);
extern void WatchdogIntTypeSet(uint32_t ui32Base, uint32_t ui32Type);
extern void WatchdogStallEnable(uint32_t ui32Base);
extern void WatchdogStallDisable(uint32_t ui32Base);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __DRIVERLIB_WATCHDOG_H__
