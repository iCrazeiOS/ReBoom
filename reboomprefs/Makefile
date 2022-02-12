include $(THEOS)/makefiles/common.mk

BUNDLE_NAME = ReBoomPrefs
ReBoomPrefs_FILES = RBMRootListController.m
ReBoomPrefs_INSTALL_PATH = /Library/PreferenceBundles
ReBoomPrefs_FRAMEWORKS = UIKit
ReBoomPrefs_PRIVATE_FRAMEWORKS = Preferences

include $(THEOS_MAKE_PATH)/bundle.mk

internal-stage::
	$(ECHO_NOTHING)mkdir -p $(THEOS_STAGING_DIR)/Library/PreferenceLoader/Preferences$(ECHO_END)
	$(ECHO_NOTHING)cp entry.plist $(THEOS_STAGING_DIR)/Library/PreferenceLoader/Preferences/ReBoomPrefs.plist$(ECHO_END)
