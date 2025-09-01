#pragma once

#undef LIMINE_API_REVISION
#define LIMINE_API_REVISION 3

#include <kronix/cpp/attributes.h>

#include <limine.h>

#undef KRONIX_LIMINE_REQUEST_WRAP
#define KRONIX_LIMINE_REQUEST_WRAP(section, ...) \
	KRONIX_KEEP KRONIX_UNUSED KRONIX_SECTION(section) extern volatile __VA_ARGS__

#undef KRONIX_LIMINE_REQUEST
#define KRONIX_LIMINE_REQUEST(name, ...) \
	KRONIX_LIMINE_REQUEST_WRAP(          \
	  ".limine_requests", struct ::limine_##name name __VA_ARGS__)

#ifdef __cplusplus

namespace kronix {
namespace arch {
namespace amd64 {
namespace init {
namespace limine {

KRONIX_LIMINE_REQUEST(bootloader_info_request);

} // namespace limine
} // namespace init
} // namespace amd64
} // namespace arch
} // namespace kronix

KRONIX_NORETURN
extern "C" void kronix_limine_boot_setup(void) noexcept;

#else

KRONIX_NORETURN
extern void kronix_limine_boot_setup(void);

#endif
