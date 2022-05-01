export ARCHS = arm64 arm64e
export PREFIX = $(THEOS)/toolchain/Xcode11.xctoolchain/usr/bin/
export SDKVERSION = 12.2

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = ReBoom
ReBoom_FILES = Tweak.xm
ReBoom_FRAMEWORKS = UIKit CoreFoundation
ReBoom_CFLAGS = -fobjc-arc

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	install.exec "killall -9 Boom!"
