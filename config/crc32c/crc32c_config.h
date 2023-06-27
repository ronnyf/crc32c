// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CRC32C_CRC32C_CONFIG_H_
#define CRC32C_CRC32C_CONFIG_H_

#if __APPLE__
#import <TargetConditionals.h>
#import <mach/machine.h>
#endif // __APPLE__

// Define to 1 if building for a big-endian platform.
#define BYTE_ORDER_BIG_ENDIAN TARGET_RT_BIG_ENDIAN

// Define to 1 if the compiler has the __builtin_prefetch intrinsic.
#if defined(__clang__)

#define HAVE_BUILTIN_PREFETCH 1
#if !defined(__has_builtin)
#error something is wrong here
#endif

#else
#define HAVE_BUILTIN_PREFETCH 0
#endif // defined(__clang__)

// Define to 1 if targeting X86 and the compiler has the _mm_prefetch intrinsic.
#define HAVE_MM_PREFETCH 0

// Define to 1 if targeting X86 and the compiler has the _mm_crc32_u{8,32,64}
// intrinsics.
#define HAVE_SSE42 0

// Define to 1 if targeting ARM and the compiler has the __crc32c{b,h,w,d} and
// the vmull_p64 intrinsics.

#if __ARM_FEATURE_CRC32
#define HAVE_ARM64_CRC32C 1
#else
#define HAVE_ARM64_CRC32C 0
#endif

// Define to 1 if the system libraries have the getauxval function in the
// <sys/auxv.h> header. Should be true on Linux and Android API level 20+.
#define HAVE_STRONG_GETAUXVAL 0

// Define to 1 if the compiler supports defining getauxval as a weak symbol.
// Should be true for any compiler that supports __attribute__((weak)).
#define HAVE_WEAK_GETAUXVAL 0

// Define to 1 if CRC32C tests have been built with Google Logging.
#define CRC32C_TESTS_BUILT_WITH_GLOG TARGET_RT_BIG_ENDIAN

#endif  // CRC32C_CRC32C_CONFIG_H_
