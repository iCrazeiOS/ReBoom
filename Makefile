export ARCHS = arm64 arm64e
export PREFIX = $(THEOS)/toolchain/Xcode11.xctoolchain/usr/bin/
export SDKVERSION = 14.4

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = ReBoom
ReBoom_FILES = Tweak.xm
ReBoom_FRAMEWORKS = UIKit CoreFoundation
ReBoom_FRAMEWORKS_CFLAGS = -fobjc-arc

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	install.exec "killall -9 Boom!"
SUBPROJECTS += reboomprefs
include $(THEOS_MAKE_PATH)/aggregate.mk
