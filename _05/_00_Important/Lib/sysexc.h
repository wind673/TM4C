
#ifndef __SYSEXC_H__
#define __SYSEXC_H__

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
// Values that can be passed to SysExcIntEnable, SysExcIntDisable, and
// SysExcIntClear as the ui32IntFlags parameter, and returned from
// SysExcIntStatus.
//
//*****************************************************************************
#define SYSEXC_INT_FP_IXC       0x00000020  // FP Inexact exception interrupt
#define SYSEXC_INT_FP_OFC       0x00000010  // FP Overflow exception interrupt
#define SYSEXC_INT_FP_UFC       0x00000008  // FP Underflow exception interrupt
#define SYSEXC_INT_FP_IOC       0x00000004  // FP Invalid operation interrupt
#define SYSEXC_INT_FP_DZC       0x00000002  // FP Divide by zero exception int
#define SYSEXC_INT_FP_IDC       0x00000001  // FP Input denormal exception int

//*****************************************************************************
//
// Prototypes.
//
//*****************************************************************************
extern void SysExcIntRegister(void (*pfnHandler)(void));
extern void SysExcIntUnregister(void);
extern void SysExcIntEnable(uint32_t ui32IntFlags);
extern void SysExcIntDisable(uint32_t ui32IntFlags);
extern uint32_t SysExcIntStatus(bool bMasked);
extern void SysExcIntClear(uint32_t ui32IntFlags);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __DRIVERLIB_SYSEXC_H__
