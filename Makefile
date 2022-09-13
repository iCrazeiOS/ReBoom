export ARCHS = arm64 arm64e
export PREFIX = $(THEOS)/toolchain/Xcode11.xctoolchain/usr/bin/
export SDKVERSION = 12.2

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = ReBoom
ReBoom_FILES = $(wildcard Hooks/*.x) Hooks/Common.m
# ReBoom_CFLAGS = -fobjc-arc # causes segfault when clicking on alert button?..
ReBoom_FRAMEWORKS = UIKit CoreFoundation

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	install.exec "killall -9 Boom!"
