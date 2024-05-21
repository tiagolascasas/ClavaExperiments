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
typedef struct l_struct_OC_I2D l_struct_OC_I2D;
typedef struct l_struct_OC__IO_FILE l_struct_OC__IO_FILE;

/* Structure contents */
struct l_struct_OC_I2D {
  unsigned int field0;
  unsigned int field1;
  signed int field2[307200];
};

struct l_struct_OC__IO_FILE {
  unsigned int field0;
   char *field1;
   char *field2;
   char *field3;
   char *field4;
   char *field5;
   char *field6;
   char *field7;
   char *field8;
   char *field9;
   char *field10;
   char *field11;
  l_struct_OC_I2D *field12;
  l_struct_OC__IO_FILE *field13;
  unsigned int field14;
  unsigned int field15;
  unsigned long long field16;
  unsigned short field17;
  unsigned char field18;
   char field19[1];
   char *field20;
  unsigned long long field21;
  l_struct_OC_I2D *field22;
  l_struct_OC_I2D *field23;
  l_struct_OC__IO_FILE *field24;
   char *field25;
  unsigned long long field26;
  unsigned int field27;
   char field28[20];
};


/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
l_struct_OC_I2D *readImage( char *llvm_cbe_pathName);
void iMallocHandle(signed int , signed int , l_struct_OC_I2D **);


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str1[19] = "File pointer error";
static  char aesl_internal__OC_str[3] = "rb";
static  char aesl_internal__OC_str2[64] = "ERROR in BMP read: The input file is not in standard BMP format";


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

l_struct_OC_I2D *readImage( char *llvm_cbe_pathName) {
  static  unsigned long long aesl_llvm_cbe_signature_count = 0;
   char llvm_cbe_signature[2];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_file_size_count = 0;
  signed int llvm_cbe_file_size;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_reserved1_count = 0;
  signed short llvm_cbe_reserved1;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_reserved2_count = 0;
  signed short llvm_cbe_reserved2;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_loc_of_bitmap_count = 0;
  signed int llvm_cbe_loc_of_bitmap;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_size_of_infoheader_count = 0;
  signed int llvm_cbe_size_of_infoheader;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_width_count = 0;
  signed int llvm_cbe_width;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_height_count = 0;
  signed int llvm_cbe_height;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_number_of_planes_count = 0;
  signed short llvm_cbe_number_of_planes;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_bits_per_pixel_count = 0;
  signed short llvm_cbe_bits_per_pixel;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_compression_method_count = 0;
  signed int llvm_cbe_compression_method;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_bytes_of_bitmap_count = 0;
  signed int llvm_cbe_bytes_of_bitmap;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_hori_reso_count = 0;
  signed int llvm_cbe_hori_reso;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_vert_reso_count = 0;
  signed int llvm_cbe_vert_reso;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_no_of_colors_count = 0;
  signed int llvm_cbe_no_of_colors;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_no_of_imp_colors_count = 0;
  signed int llvm_cbe_no_of_imp_colors;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_tempb_count = 0;
   char llvm_cbe_tempb;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_tempg_count = 0;
   char llvm_cbe_tempg;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_tempr_count = 0;
   char llvm_cbe_tempr;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_srcImage_count = 0;
  l_struct_OC_I2D *llvm_cbe_srcImage;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
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
  l_struct_OC__IO_FILE *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
   char *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  unsigned long long llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
   char *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  unsigned long long llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
   char *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  unsigned long long llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
   char *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  unsigned long long llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
   char *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  unsigned long long llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
   char *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  unsigned long long llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
   char *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  unsigned long long llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
   char *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  unsigned long long llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
   char *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  unsigned long long llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
   char *llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  unsigned long long llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
   char *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  unsigned long long llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
   char *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  unsigned long long llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
   char *llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  unsigned long long llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
   char *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  unsigned long long llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
   char *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  unsigned long long llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
   char *llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  unsigned long long llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  unsigned int llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  signed int *llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  unsigned int llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  signed int *llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  unsigned int llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  unsigned char llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
   char *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  unsigned char llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  unsigned short llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  unsigned int llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  unsigned long long llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  unsigned int llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge311_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge311_2e_us;
  unsigned int llvm_cbe_storemerge311_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  unsigned long long llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  unsigned char llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  unsigned int llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  signed int *llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  unsigned int llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  unsigned int llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  unsigned int llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  unsigned long long llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  signed int *llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  unsigned int llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge215_2e_us_2e_in_count = 0;
  unsigned int llvm_cbe_storemerge215_2e_us_2e_in;
  unsigned int llvm_cbe_storemerge215_2e_us_2e_in__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge215_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge215_2e_us;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge15_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge15_2e_us;
  unsigned int llvm_cbe_storemerge15_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  unsigned long long llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  unsigned long long llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  unsigned long long llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  unsigned char llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  unsigned int llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  signed int *llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  unsigned int llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  unsigned int llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  unsigned int llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  unsigned long long llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  signed int *llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  unsigned int llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond16_count = 0;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge8_2e_us_2e_in_count = 0;
  unsigned int llvm_cbe_storemerge8_2e_us_2e_in;
  unsigned int llvm_cbe_storemerge8_2e_us_2e_in__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge8_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge8_2e_us;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  unsigned int llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  l_struct_OC_I2D *llvm_cbe_tmp__75;
  l_struct_OC_I2D *llvm_cbe_tmp__75__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @readImage\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call noalias %%struct._IO_FILE* @fopen(i8* %%pathName, i8* getelementptr inbounds ([3 x i8]* @aesl_internal_.str, i64 0, i64 0)) nounwind, !dbg !14 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_23_count);
  llvm_cbe_tmp__1 = (l_struct_OC__IO_FILE *)aesl_fopen(( char *)llvm_cbe_pathName, ( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__1);
}
  if (((llvm_cbe_tmp__1) == (((l_struct_OC__IO_FILE *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__76;
  } else {
    goto llvm_cbe_tmp__77;
  }

llvm_cbe_tmp__76:
if (AESL_DEBUG_TRACE)
printf("\n  call void @perror(i8* getelementptr inbounds ([19 x i8]* @aesl_internal_.str1, i64 0, i64 0)) nounwind, !dbg !18 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_50_count);
  perror(( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 19
#endif
])));
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_tmp__75__PHI_TEMPORARY = (l_struct_OC_I2D *)((l_struct_OC_I2D *)/*NULL*/0);   /* for PHI node */
  goto llvm_cbe_tmp__78;

llvm_cbe_tmp__77:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [2 x i8]* %%signature, i64 0, i64 0, !dbg !14 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__2 = ( char *)(&llvm_cbe_signature[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = call i64 @fread(i8* %%5, i64 2, i64 1, %%struct._IO_FILE* %%1) nounwind, !dbg !14 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_53_count);
  fread(( char *)llvm_cbe_tmp__2, 2ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",2ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__3);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = bitcast i32* %%file_size to i8*, !dbg !15 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_54_count);
  llvm_cbe_tmp__4 = ( char *)(( char *)(&llvm_cbe_file_size));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = call i64 @fread(i8* %%7, i64 4, i64 1, %%struct._IO_FILE* %%1) nounwind, !dbg !15 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_55_count);
  fread(( char *)llvm_cbe_tmp__4, 4ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",4ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__5);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = bitcast i16* %%reserved1 to i8*, !dbg !15 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__6 = ( char *)(( char *)(&llvm_cbe_reserved1));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = call i64 @fread(i8* %%9, i64 2, i64 1, %%struct._IO_FILE* %%1) nounwind, !dbg !15 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_57_count);
  fread(( char *)llvm_cbe_tmp__6, 2ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",2ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__7);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = bitcast i16* %%reserved2 to i8*, !dbg !15 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__8 = ( char *)(( char *)(&llvm_cbe_reserved2));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = call i64 @fread(i8* %%11, i64 2, i64 1, %%struct._IO_FILE* %%1) nounwind, !dbg !15 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_59_count);
  fread(( char *)llvm_cbe_tmp__8, 2ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",2ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__9);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = bitcast i32* %%loc_of_bitmap to i8*, !dbg !15 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__10 = ( char *)(( char *)(&llvm_cbe_loc_of_bitmap));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = call i64 @fread(i8* %%13, i64 4, i64 1, %%struct._IO_FILE* %%1) nounwind, !dbg !15 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_61_count);
  fread(( char *)llvm_cbe_tmp__10, 4ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",4ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__11);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = bitcast i32* %%size_of_infoheader to i8*, !dbg !15 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__12 = ( char *)(( char *)(&llvm_cbe_size_of_infoheader));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = call i64 @fread(i8* %%15, i64 4, i64 1, %%struct._IO_FILE* %%1) nounwind, !dbg !15 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_63_count);
  fread(( char *)llvm_cbe_tmp__12, 4ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",4ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__13);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = bitcast i32* %%width to i8*, !dbg !15 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__14 = ( char *)(( char *)(&llvm_cbe_width));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = call i64 @fread(i8* %%17, i64 4, i64 1, %%struct._IO_FILE* %%1) nounwind, !dbg !15 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_65_count);
  fread(( char *)llvm_cbe_tmp__14, 4ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",4ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__15);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = bitcast i32* %%height to i8*, !dbg !15 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__16 = ( char *)(( char *)(&llvm_cbe_height));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = call i64 @fread(i8* %%19, i64 4, i64 1, %%struct._IO_FILE* %%1) nounwind, !dbg !15 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_67_count);
  fread(( char *)llvm_cbe_tmp__16, 4ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",4ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__17);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = bitcast i16* %%number_of_planes to i8*, !dbg !15 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_68_count);
  llvm_cbe_tmp__18 = ( char *)(( char *)(&llvm_cbe_number_of_planes));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = call i64 @fread(i8* %%21, i64 2, i64 1, %%struct._IO_FILE* %%1) nounwind, !dbg !15 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_69_count);
  fread(( char *)llvm_cbe_tmp__18, 2ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",2ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__19);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = bitcast i16* %%bits_per_pixel to i8*, !dbg !15 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_70_count);
  llvm_cbe_tmp__20 = ( char *)(( char *)(&llvm_cbe_bits_per_pixel));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = call i64 @fread(i8* %%23, i64 2, i64 1, %%struct._IO_FILE* %%1) nounwind, !dbg !15 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_71_count);
  fread(( char *)llvm_cbe_tmp__20, 2ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",2ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__21);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = bitcast i32* %%compression_method to i8*, !dbg !16 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_72_count);
  llvm_cbe_tmp__22 = ( char *)(( char *)(&llvm_cbe_compression_method));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = call i64 @fread(i8* %%25, i64 4, i64 1, %%struct._IO_FILE* %%1) nounwind, !dbg !16 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_73_count);
  fread(( char *)llvm_cbe_tmp__22, 4ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",4ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__23);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = bitcast i32* %%bytes_of_bitmap to i8*, !dbg !16 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_74_count);
  llvm_cbe_tmp__24 = ( char *)(( char *)(&llvm_cbe_bytes_of_bitmap));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = call i64 @fread(i8* %%27, i64 4, i64 1, %%struct._IO_FILE* %%1) nounwind, !dbg !16 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_75_count);
  fread(( char *)llvm_cbe_tmp__24, 4ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",4ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__25);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = bitcast i32* %%hori_reso to i8*, !dbg !16 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__26 = ( char *)(( char *)(&llvm_cbe_hori_reso));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = call i64 @fread(i8* %%29, i64 4, i64 1, %%struct._IO_FILE* %%1) nounwind, !dbg !16 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_77_count);
  fread(( char *)llvm_cbe_tmp__26, 4ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",4ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__27);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = bitcast i32* %%vert_reso to i8*, !dbg !16 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__28 = ( char *)(( char *)(&llvm_cbe_vert_reso));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = call i64 @fread(i8* %%31, i64 4, i64 1, %%struct._IO_FILE* %%1) nounwind, !dbg !16 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_79_count);
  fread(( char *)llvm_cbe_tmp__28, 4ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",4ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__29);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = bitcast i32* %%no_of_colors to i8*, !dbg !16 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__30 = ( char *)(( char *)(&llvm_cbe_no_of_colors));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = call i64 @fread(i8* %%33, i64 4, i64 1, %%struct._IO_FILE* %%1) nounwind, !dbg !16 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_81_count);
  fread(( char *)llvm_cbe_tmp__30, 4ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",4ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__31);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = bitcast i32* %%no_of_imp_colors to i8*, !dbg !16 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__32 = ( char *)(( char *)(&llvm_cbe_no_of_imp_colors));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = call i64 @fread(i8* %%35, i64 4, i64 1, %%struct._IO_FILE* %%1) nounwind, !dbg !16 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_83_count);
  fread(( char *)llvm_cbe_tmp__32, 4ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",4ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__33);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = load i32* %%height, align 4, !dbg !18 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_90_count);
  llvm_cbe_tmp__34 = (unsigned int )*(&llvm_cbe_height);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i32* %%width, align 4, !dbg !18 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_97_count);
  llvm_cbe_tmp__35 = (unsigned int )*(&llvm_cbe_width);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  call void @iMallocHandle(i32 %%37, i32 %%38, %%struct.I2D** %%srcImage) nounwind, !dbg !18 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_98_count);
  iMallocHandle(llvm_cbe_tmp__34, llvm_cbe_tmp__35, (l_struct_OC_I2D **)(&llvm_cbe_srcImage));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__34);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__35);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load %%struct.I2D** %%srcImage, align 8, !dbg !18 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_105_count);
  llvm_cbe_tmp__36 = (l_struct_OC_I2D *)*(&llvm_cbe_srcImage);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = getelementptr inbounds %%struct.I2D* %%39, i64 0, i32 1, !dbg !18 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_106_count);
  llvm_cbe_tmp__37 = (signed int *)(&llvm_cbe_tmp__36->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = load i32* %%40, align 4, !dbg !18 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_107_count);
  llvm_cbe_tmp__38 = (unsigned int )*llvm_cbe_tmp__37;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__38);
  if ((((signed int )llvm_cbe_tmp__38) < ((signed int )1u))) {
    goto llvm_cbe_tmp__79;
  } else {
    goto llvm_cbe_tmp__80;
  }

llvm_cbe_tmp__80:
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds %%struct.I2D* %%39, i64 0, i32 0, !dbg !18 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_111_count);
  llvm_cbe_tmp__39 = (signed int *)(&llvm_cbe_tmp__36->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = load i32* %%44, align 4, !dbg !18 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_112_count);
  llvm_cbe_tmp__40 = (unsigned int )*llvm_cbe_tmp__39;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__40);
  if ((((signed int )llvm_cbe_tmp__40) < ((signed int )1u))) {
    goto llvm_cbe_tmp__79;
  } else {
    goto llvm_cbe_tmp__81;
  }

llvm_cbe_tmp__81:

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 2)) fprintf(stderr, "%s:%d: warning: Read access out of array 'signature' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = load i8* %%5, align 1, !dbg !18 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__41 = (unsigned char )*llvm_cbe_tmp__2;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__41);
  if (((llvm_cbe_tmp__41&255U) == (((unsigned char )66)&255U))) {
    goto llvm_cbe_tmp__82;
  } else {
    goto llvm_cbe_tmp__79;
  }

llvm_cbe_tmp__82:
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds [2 x i8]* %%signature, i64 0, i64 1, !dbg !18 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_118_count);
  llvm_cbe_tmp__42 = ( char *)(&llvm_cbe_signature[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 2
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 2)) fprintf(stderr, "%s:%d: warning: Read access out of array 'signature' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load i8* %%51, align 1, !dbg !18 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_119_count);
  llvm_cbe_tmp__43 = (unsigned char )*llvm_cbe_tmp__42;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__43);
  if (((llvm_cbe_tmp__43&255U) == (((unsigned char )77)&255U))) {
    goto llvm_cbe_tmp__83;
  } else {
    goto llvm_cbe_tmp__79;
  }

llvm_cbe_tmp__83:
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = load i16* %%bits_per_pixel, align 2, !dbg !18 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_128_count);
  llvm_cbe_tmp__44 = (unsigned short )*(&llvm_cbe_bits_per_pixel);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__44);
  switch (((unsigned short )(llvm_cbe_tmp__44&65535ull))) {
  default:
    goto llvm_cbe_tmp__79;
;
  case ((unsigned short )(((unsigned short )24)&65535ull)):
    goto llvm_cbe_tmp__84;
  case ((unsigned short )(((unsigned short )8)&65535ull)):
    goto llvm_cbe_tmp__84;
  }
llvm_cbe_tmp__79:
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([64 x i8]* @aesl_internal_.str2, i64 0, i64 0)) nounwind, !dbg !18 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_131_count);
  printf(( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 64
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__45);
}
  llvm_cbe_tmp__75__PHI_TEMPORARY = (l_struct_OC_I2D *)((l_struct_OC_I2D *)/*NULL*/0);   /* for PHI node */
  goto llvm_cbe_tmp__78;

llvm_cbe_tmp__84:
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = load i32* %%loc_of_bitmap, align 4, !dbg !16 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__46 = (unsigned int )*(&llvm_cbe_loc_of_bitmap);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = sext i32 %%59 to i64, !dbg !16 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__47 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = call i32 @fseek(%%struct._IO_FILE* %%1, i64 %%60, i32 0) nounwind, !dbg !16 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_141_count);
  fseek((l_struct_OC__IO_FILE *)llvm_cbe_tmp__1, llvm_cbe_tmp__47, 0u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",llvm_cbe_tmp__47);
printf("\nArgument  = 0x%X",0u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__48);
}
  if (((llvm_cbe_tmp__44&65535U) == (((unsigned short )8)&65535U))) {
    goto llvm_cbe_tmp__85;
  } else {
    goto llvm_cbe_tmp__86;
  }

llvm_cbe_tmp__85:
  if ((((signed int )llvm_cbe_tmp__34) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader9_2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e_loopexit13;
  }

llvm_cbe__2e_preheader9_2e_lr_2e_ph:
  if ((((signed int )llvm_cbe_tmp__35) > ((signed int )0u))) {
    llvm_cbe_storemerge215_2e_us_2e_in__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__34;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph12_2e_us;
  } else {
    goto llvm_cbe__2e__2e_loopexit13_crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph12.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph12_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge215.us.in = phi i32 [ %%storemerge215.us, %%.loopexit10.us ], [ %%37, %%.preheader9.lr.ph  for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_storemerge215_2e_us_2e_in_count);
  llvm_cbe_storemerge215_2e_us_2e_in = (unsigned int )llvm_cbe_storemerge215_2e_us_2e_in__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge215.us.in = 0x%X",llvm_cbe_storemerge215_2e_us_2e_in);
printf("\nstoremerge215.us = 0x%X",llvm_cbe_storemerge215_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__34);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge215.us = add nsw i32 %%storemerge215.us.in, -1, !dbg !20 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_storemerge215_2e_us_count);
  llvm_cbe_storemerge215_2e_us = (unsigned int )((unsigned int )(llvm_cbe_storemerge215_2e_us_2e_in&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge215.us = 0x%X\n", ((unsigned int )(llvm_cbe_storemerge215_2e_us&4294967295ull)));
  llvm_cbe_storemerge311_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__87;

llvm_cbe__2e_loopexit10_2e_us:
  if ((((signed int )llvm_cbe_storemerge215_2e_us) > ((signed int )0u))) {
    llvm_cbe_storemerge215_2e_us_2e_in__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge215_2e_us;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph12_2e_us;
  } else {
    goto llvm_cbe__2e__2e_loopexit13_crit_edge;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__87:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge311.us = phi i32 [ 0, %%.lr.ph12.us ], [ %%77, %%66  for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_storemerge311_2e_us_count);
  llvm_cbe_storemerge311_2e_us = (unsigned int )llvm_cbe_storemerge311_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge311.us = 0x%X",llvm_cbe_storemerge311_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__59);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = call i64 @fread(i8* %%tempg, i64 1, i64 1, %%struct._IO_FILE* %%1) nounwind, !dbg !16 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_156_count);
  fread(( char *)(&llvm_cbe_tempg), 1ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",1ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__49);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = load i8* %%tempg, align 1, !dbg !19 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_161_count);
  llvm_cbe_tmp__50 = (unsigned char )*(&llvm_cbe_tempg);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = zext i8 %%68 to i32, !dbg !19 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_162_count);
  llvm_cbe_tmp__51 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__50&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = load %%struct.I2D** %%srcImage, align 8, !dbg !19 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_167_count);
  llvm_cbe_tmp__52 = (l_struct_OC_I2D *)*(&llvm_cbe_srcImage);
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = getelementptr inbounds %%struct.I2D* %%70, i64 0, i32 0, !dbg !19 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_168_count);
  llvm_cbe_tmp__53 = (signed int *)(&llvm_cbe_tmp__52->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = load i32* %%71, align 4, !dbg !19 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_169_count);
  llvm_cbe_tmp__54 = (unsigned int )*llvm_cbe_tmp__53;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = mul nsw i32 %%72, %%storemerge215.us, !dbg !19 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_170_count);
  llvm_cbe_tmp__55 = (unsigned int )((unsigned int )(llvm_cbe_tmp__54&4294967295ull)) * ((unsigned int )(llvm_cbe_storemerge215_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__55&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = add nsw i32 %%73, %%storemerge311.us, !dbg !19 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_171_count);
  llvm_cbe_tmp__56 = (unsigned int )((unsigned int )(llvm_cbe_tmp__55&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge311_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__56&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = sext i32 %%74 to i64, !dbg !19 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_172_count);
  llvm_cbe_tmp__57 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = getelementptr inbounds %%struct.I2D* %%70, i64 0, i32 2, i64 %%75, !dbg !19 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_173_count);
  llvm_cbe_tmp__58 = (signed int *)(&llvm_cbe_tmp__52->field2[(((signed long long )llvm_cbe_tmp__57))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__57));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%69, i32* %%76, align 4, !dbg !19 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_174_count);
  *llvm_cbe_tmp__58 = llvm_cbe_tmp__51;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = add nsw i32 %%storemerge311.us, 1, !dbg !19 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_175_count);
  llvm_cbe_tmp__59 = (unsigned int )((unsigned int )(llvm_cbe_storemerge311_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__59&4294967295ull)));
  if (((llvm_cbe_tmp__59&4294967295U) == (llvm_cbe_tmp__35&4294967295U))) {
    goto llvm_cbe__2e_loopexit10_2e_us;
  } else {
    llvm_cbe_storemerge311_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__59;   /* for PHI node */
    goto llvm_cbe_tmp__87;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph12.us' */
llvm_cbe_tmp__86:
  if (((llvm_cbe_tmp__44&65535U) == (((unsigned short )24)&65535U))) {
    goto llvm_cbe_tmp__88;
  } else {
    llvm_cbe_tmp__75__PHI_TEMPORARY = (l_struct_OC_I2D *)((l_struct_OC_I2D *)/*NULL*/0);   /* for PHI node */
    goto llvm_cbe_tmp__78;
  }

llvm_cbe_tmp__88:
  if ((((signed int )llvm_cbe_tmp__34) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e_loopexit6;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
  if ((((signed int )llvm_cbe_tmp__35) > ((signed int )0u))) {
    llvm_cbe_storemerge8_2e_us_2e_in__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__34;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    goto llvm_cbe__2e__2e_loopexit6_crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge8.us.in = phi i32 [ %%storemerge8.us, %%.loopexit.us ], [ %%37, %%.preheader.lr.ph  for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_storemerge8_2e_us_2e_in_count);
  llvm_cbe_storemerge8_2e_us_2e_in = (unsigned int )llvm_cbe_storemerge8_2e_us_2e_in__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge8.us.in = 0x%X",llvm_cbe_storemerge8_2e_us_2e_in);
printf("\nstoremerge8.us = 0x%X",llvm_cbe_storemerge8_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__34);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge8.us = add nsw i32 %%storemerge8.us.in, -1, !dbg !20 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_storemerge8_2e_us_count);
  llvm_cbe_storemerge8_2e_us = (unsigned int )((unsigned int )(llvm_cbe_storemerge8_2e_us_2e_in&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge8.us = 0x%X\n", ((unsigned int )(llvm_cbe_storemerge8_2e_us&4294967295ull)));
  llvm_cbe_storemerge15_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__89;

llvm_cbe__2e_loopexit_2e_us:
  if ((((signed int )llvm_cbe_storemerge8_2e_us) > ((signed int )0u))) {
    llvm_cbe_storemerge8_2e_us_2e_in__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge8_2e_us;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    goto llvm_cbe__2e__2e_loopexit6_crit_edge;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__89:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge15.us = phi i32 [ 0, %%.lr.ph.us ], [ %%97, %%84  for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_storemerge15_2e_us_count);
  llvm_cbe_storemerge15_2e_us = (unsigned int )llvm_cbe_storemerge15_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15.us = 0x%X",llvm_cbe_storemerge15_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__72);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = call i64 @fread(i8* %%tempb, i64 1, i64 1, %%struct._IO_FILE* %%1) nounwind, !dbg !17 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_206_count);
  fread(( char *)(&llvm_cbe_tempb), 1ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",1ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__60);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = call i64 @fread(i8* %%tempg, i64 1, i64 1, %%struct._IO_FILE* %%1) nounwind, !dbg !18 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_207_count);
  fread(( char *)(&llvm_cbe_tempg), 1ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",1ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__61);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = call i64 @fread(i8* %%tempr, i64 1, i64 1, %%struct._IO_FILE* %%1) nounwind, !dbg !18 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_208_count);
  fread(( char *)(&llvm_cbe_tempr), 1ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",1ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__62);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = load i8* %%tempg, align 1, !dbg !20 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_213_count);
  llvm_cbe_tmp__63 = (unsigned char )*(&llvm_cbe_tempg);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = zext i8 %%88 to i32, !dbg !20 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_214_count);
  llvm_cbe_tmp__64 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__63&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = load %%struct.I2D** %%srcImage, align 8, !dbg !19 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_221_count);
  llvm_cbe_tmp__65 = (l_struct_OC_I2D *)*(&llvm_cbe_srcImage);
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = getelementptr inbounds %%struct.I2D* %%90, i64 0, i32 0, !dbg !19 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_222_count);
  llvm_cbe_tmp__66 = (signed int *)(&llvm_cbe_tmp__65->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = load i32* %%91, align 4, !dbg !19 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_223_count);
  llvm_cbe_tmp__67 = (unsigned int )*llvm_cbe_tmp__66;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__67);
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = mul nsw i32 %%92, %%storemerge8.us, !dbg !19 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_224_count);
  llvm_cbe_tmp__68 = (unsigned int )((unsigned int )(llvm_cbe_tmp__67&4294967295ull)) * ((unsigned int )(llvm_cbe_storemerge8_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__68&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = add nsw i32 %%93, %%storemerge15.us, !dbg !19 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_225_count);
  llvm_cbe_tmp__69 = (unsigned int )((unsigned int )(llvm_cbe_tmp__68&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge15_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__69&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%95 = sext i32 %%94 to i64, !dbg !19 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_226_count);
  llvm_cbe_tmp__70 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%llX\n", llvm_cbe_tmp__70);
if (AESL_DEBUG_TRACE)
printf("\n  %%96 = getelementptr inbounds %%struct.I2D* %%90, i64 0, i32 2, i64 %%95, !dbg !19 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_227_count);
  llvm_cbe_tmp__71 = (signed int *)(&llvm_cbe_tmp__65->field2[(((signed long long )llvm_cbe_tmp__70))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%llX",((signed long long )llvm_cbe_tmp__70));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%89, i32* %%96, align 4, !dbg !19 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_228_count);
  *llvm_cbe_tmp__71 = llvm_cbe_tmp__64;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = add nsw i32 %%storemerge15.us, 1, !dbg !19 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_229_count);
  llvm_cbe_tmp__72 = (unsigned int )((unsigned int )(llvm_cbe_storemerge15_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__72&4294967295ull)));
  if (((llvm_cbe_tmp__72&4294967295U) == (llvm_cbe_tmp__35&4294967295U))) {
    goto llvm_cbe__2e_loopexit_2e_us;
  } else {
    llvm_cbe_storemerge15_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__72;   /* for PHI node */
    goto llvm_cbe_tmp__89;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
llvm_cbe__2e__2e_loopexit6_crit_edge:
  goto llvm_cbe__2e_loopexit6;

llvm_cbe__2e_loopexit6:
  goto llvm_cbe_tmp__90;

llvm_cbe__2e__2e_loopexit13_crit_edge:
  goto llvm_cbe__2e_loopexit13;

llvm_cbe__2e_loopexit13:
  goto llvm_cbe_tmp__90;

llvm_cbe_tmp__90:
if (AESL_DEBUG_TRACE)
printf("\n  %%100 = call i32 @fclose(%%struct._IO_FILE* %%1) nounwind, !dbg !18 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_252_count);
  fclose((l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__73);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%101 = load %%struct.I2D** %%srcImage, align 8, !dbg !20 for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_259_count);
  llvm_cbe_tmp__74 = (l_struct_OC_I2D *)*(&llvm_cbe_srcImage);
  llvm_cbe_tmp__75__PHI_TEMPORARY = (l_struct_OC_I2D *)llvm_cbe_tmp__74;   /* for PHI node */
  goto llvm_cbe_tmp__78;

llvm_cbe_tmp__78:
if (AESL_DEBUG_TRACE)
printf("\n  %%103 = phi %%struct.I2D* [ %%101, %%99 ], [ null, %%56 ], [ null, %%3 ], [ null, %%79  for 0x%llxth hint within @readImage  --> \n", ++aesl_llvm_cbe_261_count);
  llvm_cbe_tmp__75 = (l_struct_OC_I2D *)llvm_cbe_tmp__75__PHI_TEMPORARY;
  if (AESL_DEBUG_TRACE)
      printf("\nEND @readImage}\n");
  return llvm_cbe_tmp__75;
}

