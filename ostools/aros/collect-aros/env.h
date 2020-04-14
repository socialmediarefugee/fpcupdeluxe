#ifndef _ENV_H_
#define _ENV_H_

/*
 * Under Windows we can't use paths provided by configure because they are UNIX-style
 * and we don't use MSYS
 */
#ifdef _WIN32
#ifndef _STANDALONE_
#define _STANDALONE_
#endif
#endif

#ifdef _NATIVE_
#define LD_NAME      "/Developer/bin/ld"
#define STRIP_NAME   "/Developer/bin/strip"
#define NM_NAME      "/Developer/bin/nm"
#define OBJDUMP_NAME "/Developer/bin/objdump"
#endif
#ifdef _CROSS_
#define LD_NAME      "i386-aros-ld.exe"
#define STRIP_NAME   "i386-aros-strip.exe"
#define NM_NAME      "i386-aros-nm.exe"
#define OBJDUMP_NAME "i386-aros-objdump.exe"
#endif
#ifdef _STANDALONE_
#define LD_NAME      "i386-aros-ld.exe"
#define STRIP_NAME   "i386-aros-strip.exe"
#define NM_NAME      "i386-aros-nm.exe"
#define OBJDUMP_NAME "i386-aros-objdump.exe"
#endif

#ifndef LD_NAME
/* The following lines will be patched by AROS-SDK-Install */
#define LD_NAME      "@orig_target_ld@"
#define STRIP_NAME   "@aros_target_strip@"
#define NM_NAME      "@aros_target_nm@"
#define OBJDUMP_NAME "@aros_target_objdump@"
#endif

#define TARGET_CPU_i386

/*
 * Having these conditions here helps to bootstrap a crosscompiler.
 * You don't have to look up a value in configure script any more.
 */
#ifdef TARGET_CPU_m68k
#define OBJECT_FORMAT "-mm68kelf"
#endif
#ifdef TARGET_CPU_ppc
#define OBJECT_FORMAT "-melf32ppc"
#endif
#ifdef TARGET_CPU_i386
#define OBJECT_FORMAT "-melf_i386"
#endif
#ifdef TARGET_CPU_x86_64
#define OBJECT_FORMAT "-melf_x86_64"
#endif
#ifdef TARGET_CPU_aarch64
#define OBJECT_FORMAT "-maarch64elf_aros"
#endif
#if defined(TARGET_CPU_arm)
#define OBJECT_FORMAT "-marmelf_aros"
#endif
#if defined(TARGET_CPU_armeb)
#define OBJECT_FORMAT "-marmelfb_aros"
#define OBJECT_FORMAT_EXTRA_FINAL "--be8"
#endif
#ifdef TARGET_CPU_sparc
#define OBJECT_FORMAT "-melf_sparc"
#endif
#ifndef OBJECT_FORMAT
#error Unknown object format for your target CPU
#endif

#undef TARGET_FORMAT_EXE
#if defined(TARGET_CPU_arm) || defined(TARGET_CPU_armeb)
#define TARGET_FORMAT_EXE
#endif

#endif /* !_ENV_H */
