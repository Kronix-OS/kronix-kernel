#pragma once

#undef KRONIX_ASM
/**
 * @def KRONIX_ASM
 * @brief Start an inline assembly block
 */
#define KRONIX_ASM(...) __asm__ __volatile__(__VA_ARGS__)
