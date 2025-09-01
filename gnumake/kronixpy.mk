override KRONIXPY := pipenv run kronixpy
override GENERATE-SECTION-INFO = $(KRONIXPY) generate secinfo -i $(1) -l $(2) -c $(3) $(4)
override TOOLCHAIN-COMPONENT = $(call MEMOSHELL,$(KRONIXPY) toolchain -d $(TOOLCHAIN-DIR) kernel -a $(KRONIX-ARCH) print $(1))