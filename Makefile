export PREFIX = $(THEOS)/toolchain/Xcode11.xctoolchain/usr/bin/

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = ReBoom
ReBoom_FILES = $(wildcard Hooks/*.x) Hooks/Common.m
ReBoom_FRAMEWORKS = UIKit CoreFoundation

# if LEGACY=1 is passed via command line
ifeq ($(LEGACY),1)
	export ARCHS = armv7 armv7s
	export SDKVERSION = 6.0

	ReBoom_FILES := $(filter-out Hooks/KeyboardControls.x, $(ReBoom_FILES))
	THEOS_PACKAGE_NAME = com.icraze.reboom.32bit
else
	export ARCHS = arm64
	export SDKVERSION = 7.0

	THEOS_PACKAGE_NAME = com.icraze.reboom
endif

ReBoom_CFLAGS = -DVERSION_STRING='"ReBoom v$(THEOS_PACKAGE_BASE_VERSION)"'

include $(THEOS_MAKE_PATH)/tweak.mk

# change info for legacy (32-bit) builds
before-package::
ifeq ($(LEGACY),1)
	@sed -i.bak -e '' 's/^Package: .*/Package: com.icraze.reboom.32bit/' $(THEOS_STAGING_DIR)/DEBIAN/control && rm -f $(THEOS_STAGING_DIR)/DEBIAN/control.bak
	@sed -i.bak -e '' 's/^Conflicts: .*/Conflicts: com.icraze.reboom/' $(THEOS_STAGING_DIR)/DEBIAN/control && rm -f $(THEOS_STAGING_DIR)/DEBIAN/control.bak
	@sed -i.bak -e '' 's/^Name: .*/Name: ReBoom (32-bit)/' $(THEOS_STAGING_DIR)/DEBIAN/control && rm -f $(THEOS_STAGING_DIR)/DEBIAN/control.bak
endif

after-install::
	install.exec "killall -9 Boom!"
