/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;
/* Structure forward decls */
typedef struct l_struct_OC_F2D l_struct_OC_F2D;

/* Structure contents */
struct l_struct_OC_F2D {
  unsigned int field0;
  unsigned int field1;
  float field2[1];
};


/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
l_struct_OC_F2D *fDeepCopy(l_struct_OC_F2D *llvm_cbe_in);
void fMallocHandle(signed int , signed int , l_struct_OC_F2D **);


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

l_struct_OC_F2D *fDeepCopy(l_struct_OC_F2D *llvm_cbe_in) {
  static  unsigned long long aesl_llvm_cbe_out_count = 0;
  l_struct_OC_F2D *llvm_cbe_out;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  signed int *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  signed int *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  unsigned int llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond6_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge12_2e_us;
  unsigned int llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  unsigned int llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  unsigned long long llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  float *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  float llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  signed int *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  unsigned long long llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  float *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge3_2e_us;
  unsigned int llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  l_struct_OC_F2D *llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @fDeepCopy\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.F2D* %%in, i64 0, i32 1, !dbg !3 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_7_count);
  llvm_cbe_tmp__1 = (signed int *)(&llvm_cbe_in->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !3 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_8_count);
  llvm_cbe_tmp__2 = (unsigned int )*llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.F2D* %%in, i64 0, i32 0, !dbg !3 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_12_count);
  llvm_cbe_tmp__3 = (signed int *)(&llvm_cbe_in->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !3 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_13_count);
  llvm_cbe_tmp__4 = (unsigned int )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  call void @fMallocHandle(i32 %%2, i32 %%4, %%struct.F2D** %%out) nounwind, !dbg !4 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_17_count);
  fMallocHandle(llvm_cbe_tmp__2, llvm_cbe_tmp__4, (l_struct_OC_F2D **)(&llvm_cbe_out));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__2);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__4);
}
  if ((((signed int )llvm_cbe_tmp__2) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  } else {
    goto llvm_cbe_tmp__21;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
  if ((((signed int )llvm_cbe_tmp__4) > ((signed int )0u))) {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    goto llvm_cbe__2e__crit_edge5;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3.us = phi i32 [ %%8, %%7 ], [ 0, %%.preheader.lr.ph  for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_storemerge3_2e_us_count);
  llvm_cbe_storemerge3_2e_us = (unsigned int )llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3.us = 0x%X",llvm_cbe_storemerge3_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__5);
printf("\n = 0x%X",0u);
}
  llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__22;

llvm_cbe_tmp__23:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add nsw i32 %%storemerge3.us, 1, !dbg !5 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_27_count);
  llvm_cbe_tmp__5 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__5&4294967295ull)));
  if (((llvm_cbe_tmp__5&4294967295U) == (llvm_cbe_tmp__2&4294967295U))) {
    goto llvm_cbe__2e__crit_edge5;
  } else {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__5;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__22:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12.us = phi i32 [ 0, %%.lr.ph.us ], [ %%23, %%9  for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_storemerge12_2e_us_count);
  llvm_cbe_storemerge12_2e_us = (unsigned int )llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12.us = 0x%X",llvm_cbe_storemerge12_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__19);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i32* %%3, align 4, !dbg !3 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__6 = (unsigned int )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = mul nsw i32 %%10, %%storemerge3.us, !dbg !3 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__7 = (unsigned int )((unsigned int )(llvm_cbe_tmp__6&4294967295ull)) * ((unsigned int )(llvm_cbe_storemerge3_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__7&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add nsw i32 %%11, %%storemerge12.us, !dbg !3 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__8 = (unsigned int )((unsigned int )(llvm_cbe_tmp__7&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge12_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__8&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sext i32 %%12 to i64, !dbg !3 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__9 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds %%struct.F2D* %%in, i64 0, i32 2, i64 %%13, !dbg !3 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__10 = (float *)(&llvm_cbe_in->field2[(((signed long long )llvm_cbe_tmp__9))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__9));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load float* %%14, align 1, !dbg !3 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__11 = (float )*llvm_cbe_tmp__10;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__11, *(int*)(&llvm_cbe_tmp__11));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load %%struct.F2D** %%out, align 8, !dbg !3 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__12 = (l_struct_OC_F2D *)*(&llvm_cbe_out);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.F2D* %%16, i64 0, i32 0, !dbg !3 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__13 = (signed int *)(&llvm_cbe_tmp__12->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i32* %%17, align 4, !dbg !3 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__14 = (unsigned int )*llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = mul nsw i32 %%18, %%storemerge3.us, !dbg !3 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_47_count);
  llvm_cbe_tmp__15 = (unsigned int )((unsigned int )(llvm_cbe_tmp__14&4294967295ull)) * ((unsigned int )(llvm_cbe_storemerge3_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__15&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = add nsw i32 %%19, %%storemerge12.us, !dbg !3 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__16 = (unsigned int )((unsigned int )(llvm_cbe_tmp__15&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge12_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__16&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = sext i32 %%20 to i64, !dbg !3 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__17 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds %%struct.F2D* %%16, i64 0, i32 2, i64 %%21, !dbg !3 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_50_count);
  llvm_cbe_tmp__18 = (float *)(&llvm_cbe_tmp__12->field2[(((signed long long )llvm_cbe_tmp__17))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__17));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%15, float* %%22, align 1, !dbg !3 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_51_count);
  *llvm_cbe_tmp__18 = llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = add nsw i32 %%storemerge12.us, 1, !dbg !5 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__19 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__19&4294967295ull)));
  if (((llvm_cbe_tmp__19&4294967295U) == (llvm_cbe_tmp__4&4294967295U))) {
    goto llvm_cbe_tmp__23;
  } else {
    llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__19;   /* for PHI node */
    goto llvm_cbe_tmp__22;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
llvm_cbe__2e__crit_edge5:
  goto llvm_cbe_tmp__21;

llvm_cbe_tmp__21:
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load %%struct.F2D** %%out, align 8, !dbg !5 for 0x%llxth hint within @fDeepCopy  --> \n", ++aesl_llvm_cbe_71_count);
  llvm_cbe_tmp__20 = (l_struct_OC_F2D *)*(&llvm_cbe_out);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @fDeepCopy}\n");
  return llvm_cbe_tmp__20;
}

