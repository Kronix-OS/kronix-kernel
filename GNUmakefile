override MAKEFLAGS += -rR
export MAKEFLAGS

include config.mk
include third-party/gmsl/gmsl
include gnumake/kronixpy.mk
include gnumake/utils.mk

export TOP-DIR := $(realpath $(dir $(realpath $(firstword $(MAKEFILE_LIST)))))
export BUILD-DIR := $(TOP-DIR)/build
export TOOLCHAIN-DIR := $(TOP-DIR)/toolchain/install

export CC := $(call TOOLCHAIN-COMPONENT,gcc)
export CXX := $(call TOOLCHAIN-COMPONENT,g++)
export CPP := $(call TOOLCHAIN-COMPONENT,cpp)
export AR := $(call TOOLCHAIN-COMPONENT,gcc-ar)
ifeq ($(call or,$(call seq,size,$(KRONIX-PROFILE)),$(call seq,release,$(KRONIX-PROFILE))),$(true))
	LD := $(call TOOLCHAIN-COMPONENT,gcc)
else
	LD := $(call TOOLCHAIN-COMPONENT,ld)
endif
export LD
export GCC-TARGET-ARCH := $(call first,$(call split,-,$(notdir $(call TOOLCHAIN-COMPONENT,gcc))))

export KERNEL-SECTIONS := text bootcode rodata eh_frame eh_frame_hdr percpu data bss

.PHONY: all
all: all-$(KRONIX-ARCH)

.PHONY: all-amd64 all-x86-64 all-x86_64
all-amd64: generate-section-info
all-x86-64: all-amd64
all-x86_64: all-amd64

.PHONY: generate-section-info
generate-section-info: linker/linker-amd64.ld include/kronix/generated/linker-map.h

linker/linker-amd64.ld: linker/linker-amd64.ld.template Pipfile Pipfile.lock
	mkdir -p $(abspath include/kronix/generated)
	$(call GENERATE-SECTION-INFO,$<,$@,include/kronix/generated/linker-map.h,$(KERNEL-SECTIONS))

include/kronix/generated/linker-map.h: linker/linker-amd64.ld.template Pipfile Pipfile.lock
	mkdir -p $(abspath $@)
	$(call GENERATE-SECTION-INFO,linker/linker-amd64.ld,$@,$<,$(KERNEL-SECTIONS))

Pipfile.lock: Pipfile
	pipenv install
	pipenv lock

.DEFAULT_GOAL: all