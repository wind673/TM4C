
#ifndef __FPU_H__
#define __FPU_H__

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
// Values that can be passed to FPUHalfPrecisionSet as the ui32Mode parameter.
//
//*****************************************************************************
#define FPU_HALF_IEEE           0x00000000
#define FPU_HALF_ALTERNATE      0x04000000

//*****************************************************************************
//
// Values that can be passed to FPUNaNModeSet as the ui32Mode parameter.
//
//*****************************************************************************
#define FPU_NAN_PROPAGATE       0x00000000
#define FPU_NAN_DEFAULT         0x02000000

//*****************************************************************************
//
// Values that can be passed to FPUFlushToZeroModeSet as the ui32Mode
// parameter.
//
//*****************************************************************************
#define FPU_FLUSH_TO_ZERO_DIS   0x00000000
#define FPU_FLUSH_TO_ZERO_EN    0x01000000

//*****************************************************************************
//
// Values that can be passed to FPURoundingModeSet as the ui32Mode parameter.
//
//*****************************************************************************
#define FPU_ROUND_NEAREST       0x00000000
#define FPU_ROUND_POS_INF       0x00400000
#define FPU_ROUND_NEG_INF       0x00800000
#define FPU_ROUND_ZERO          0x00c00000

//*****************************************************************************
//
// Prototypes.
//
//*****************************************************************************
extern void FPUEnable(void);
extern void FPUDisable(void);
extern void FPUStackingEnable(void);
extern void FPULazyStackingEnable(void);
extern void FPUStackingDisable(void);
extern void FPUHalfPrecisionModeSet(uint32_t ui32Mode);
extern void FPUNaNModeSet(uint32_t ui32Mode);
extern void FPUFlushToZeroModeSet(uint32_t ui32Mode);
extern void FPURoundingModeSet(uint32_t ui32Mode);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __DRIVERLIB_FPU_H__
