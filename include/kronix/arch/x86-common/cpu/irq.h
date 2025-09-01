#pragma once

#include <kronix/cpp/assembly.h>

#ifdef __cplusplus
namespace kronix {
namespace arch {
namespace x86_common {
namespace cpu {
namespace irq {

/**
 * @brief Enable interrupts.
 */
static inline void enable(void) noexcept
{
	KRONIX_ASM("sti" : : : "memory");
}

/**
 * @brief Disable interrupts.
 */
static inline void disable(void) noexcept
{
	KRONIX_ASM("cli" : : : "memory");
}

} // namespace irq
} // namespace cpu
} // namespace x86_common
} // namespace arch
} // namespace kronix
#endif
