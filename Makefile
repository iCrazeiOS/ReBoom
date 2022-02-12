export ARCHS = arm64 arm64e
export PREFIX = $(THEOS)/toolchain/Xcode11.xctoolchain/usr/bin/
export SDKVERSION = 14.4

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = BoomPatches
BoomPatches_FILES = Tweak.xm
BoomPatches_FRAMEWORKS = UIKit CoreFoundation
BoomPatches_FRAMEWORKS_CFLAGS = -fobjc-arc

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	install.exec "killall -9 Boom!"
SUBPROJECTS += boompatchesprefs
include $(THEOS_MAKE_PATH)/aggregate.mk
