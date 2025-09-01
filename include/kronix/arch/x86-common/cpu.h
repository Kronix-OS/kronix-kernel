#pragma once

#include <kronix/arch/x86-common/cpu/irq.h>
#include <kronix/cpp/attributes.h>

#ifdef __cplusplus
namespace kronix {
namespace arch {
namespace x86_common {
namespace cpu {

/**
 * @brief Halt.
 * @details Hangs the CPU until the next interrupt.
 */
static inline void halt(void) noexcept
{
	KRONIX_ASM("hlt" : : : "memory");
}

/**
 * @brief Halt and catch fire.
 * @details Just hangs indefinitely.
 */
KRONIX_NORETURN
extern void hcf(void) noexcept;

} // namespace cpu
} // namespace x86_common
} // namespace arch
} // namespace kronix
#endif
