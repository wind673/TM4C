
#ifndef __CPU_H__
#define __CPU_H__

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
// Prototypes.
//
//*****************************************************************************
extern uint32_t CPUcpsid(void);
extern uint32_t CPUcpsie(void);
extern uint32_t CPUprimask(void);
extern void CPUwfi(void);
extern uint32_t CPUbasepriGet(void);
extern void CPUbasepriSet(uint32_t ui32NewBasepri);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __DRIVERLIB_CPU_H__
