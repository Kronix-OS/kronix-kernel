#include <kronix/arch/amd64/init/limine.h>
#include <optional>

KRONIX_NORETURN
extern "C" void kronix_limine_boot_setup(void) noexcept { }

namespace kronix {
namespace arch {
namespace amd64 {
namespace init {
namespace limine {

namespace {

KRONIX_LIMINE_REQUEST_WRAP(".limine_requests", LIMINE_BASE_REVISION(3));
KRONIX_LIMINE_REQUEST_WRAP(".limine_requests_start", LIMINE_REQUESTS_START_MARKER);
KRONIX_LIMINE_REQUEST_WRAP(".limine_requests_end", LIMINE_REQUESTS_END_MARKER);

} // namespace

KRONIX_NOTHROW
extern std::optional<int> revision(void)
{
	if (
	  LIMINE_LOADED_BASE_REV_VALID
	  && LIMINE_BASE_REVISION_SUPPORTED
	  && (LIMINE_API_REVISION == LIMINE_LOADED_BASE_REVISION))
		return LIMINE_API_REVISION;
	return std::nullopt;
}

KRONIX_LIMINE_REQUEST(
  bootloader_info_request,
  {
	.id = LIMINE_BOOTLOADER_INFO_REQUEST,
  });
/*
extern struct ::limine_base_revision BASE_REVISION : BaseRevision                      =
BaseRevision::new (); extern struct ::limine_bootloader_info_request BOOTLOADER_INFO_REQUEST :
BootloaderInfoRequest   = BootloaderInfoRequest::new (); extern struct
::limine_date_at_boot_request BOOT_TIME_REQUEST : DateAtBootRequest             =
DateAtBootRequest::new (); extern struct ::limine_device_tree_blob_request DTB_REQUEST :
DeviceTreeBlobRequest               = DeviceTreeBlobRequest::new (); extern struct
::limine_efimemorymaprequest EFI_MEMMAP_REQUEST : EfiMemoryMapRequest          =
EfiMemoryMapRequest::new (); extern struct ::limine_efisystemtablerequest EFI_SYSTBL_REQUEST :
EfiSystemTableRequest        = EfiSystemTableRequest::new (); extern struct
::limine_firmwaretyperequest FIRMWARE_TYPE_REQUEST : FirmwareTypeRequest       =
FirmwareTypeRequest::new (); extern struct ::limine_framebufferrequest FRAMEBUFFER_REQUEST :
FramebufferRequest          = FramebufferRequest::new (); extern struct ::limine_hhdmrequest
HHDM_REQUEST : HhdmRequest                        = HhdmRequest::new (); extern struct
::limine_executableaddressrequest KERNEL_ADDRESS_REQUEST : ExecutableAddressRequest =
ExecutableAddressRequest::new (); extern struct ::limine_executablecmdlinerequest
KERNEL_CMDLINE_REQUEST : ExecutableCmdlineRequest = ExecutableCmdlineRequest::new (); extern struct
::limine_memorymaprequest MEMMAP_REQUEST : MemoryMapRequest                 = MemoryMapRequest::new
(); extern struct ::limine_modulerequest MODULES_REQUEST : ModuleRequest = ModuleRequest::new
().with_internal_modules(
							&[&InternalModule::new ()
								 .with_path(c "/zerOS-boot-modules/debug-info.zko")
								 .with_cmdline(c "")
								 .with_flags(ModuleFlags::empty())]);
extern struct ::limine_mprequest MP_REQUEST : MpRequest                  = MpRequest::new
().with_flags(MP_REQUEST_FLAGS); extern struct ::limine_pagingmoderequest PAGING_MODE_REQUEST :
PagingModeRequest = PagingModeRequest::new () .with_min_mode(paging::Mode::FOUR_LEVEL)
													.with_max_mode(paging::Mode::FIVE_LEVEL);
extern struct ::limine_rsdprequest RSDP_REQUEST : RsdpRequest            = RsdpRequest::new ();
extern struct ::limine_smbiosrequest SMBIOS_REQUEST : SmbiosRequest        = SmbiosRequest::new ();
extern struct ::limine_stacksizerequest STACK_SIZE_REQUEST : StackSizeRequest =
StackSizeRequest::new ().with_size(1024 * 1024);
}

mod __markers
{
 use limine::request::{ RequestsEndMarker, RequestsStartMarker };

#[used]
#[unsafe(link_section = ".requests_start_marker")]
 static _START_MARKER : RequestsStartMarker = RequestsStartMarker::new ();
#[used]
#[unsafe(link_section = ".requests_end_marker")]
 static _END_MARKER : RequestsEndMarker = RequestsEndMarker::new ();
} */
} // namespace limine
} // namespace init
} // namespace amd64
} // namespace arch
} // namespace kronix
