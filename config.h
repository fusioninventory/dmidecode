/*
 * Configuration
 */

#ifndef CONFIG_H
#define CONFIG_H

/* Default memory device file */
#if defined(__BEOS__) || defined(__HAIKU__)
#define DEFAULT_MEM_DEV "/dev/misc/mem"
#else
#ifdef __sun
#define DEFAULT_MEM_DEV "/dev/xsvc"
#else
#define DEFAULT_MEM_DEV "/dev/mem"
#endif
#endif

/* Use mmap or not */
#ifndef __BEOS__
#define USE_MMAP
#endif

/* Use memory alignment workaround or not */
#if defined(__ia64__) || defined(__LP64__)
#define ALIGNMENT_WORKAROUND
#endif

/* Use API calls to get SMBIOS data */
#if defined(__APPLE__) // TODO: || defined(__WIN32)
#define USE_API_CALLS
#endif

/* Avoid unaligned memcpy on /dev/mem */
#ifdef __aarch64__
#define USE_SLOW_MEMCPY
#endif

#endif
