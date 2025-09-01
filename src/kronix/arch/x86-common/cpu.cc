#include <kronix/arch/x86-common/cpu.h>
#include <kronix/cpp/assembly.h>

#ifdef __cplusplus

KRONIX_NORETURN
extern void kronix::arch::x86_common::cpu::hcf(void) noexcept
{
	irq::disable();
	while (true)
		halt();
}

#endif
