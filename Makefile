export ARCHS = armv7 armv7s arm64
export PREFIX = $(THEOS)/toolchain/Xcode11.xctoolchain/usr/bin/
export SDKVERSION = 6.0

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = ReBoom
ReBoom_FILES = $(wildcard Hooks/*.x) Hooks/Common.m
ReBoom_FRAMEWORKS = UIKit CoreFoundation

ifeq ($(SDKVERSION),6.0)
	ReBoom_FILES := $(filter-out Hooks/KeyboardControls.x, $(ReBoom_FILES))
endif

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	install.exec "killall -9 Boom!"
