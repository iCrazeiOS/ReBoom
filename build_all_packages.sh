#!/bin/bash

# remove old builds
rm -rf .theos packages

# arm64, rootful
make clean package FINALPACKAGE=1

# arm64, rootless
make clean package FINALPACKAGE=1 THEOS_PACKAGE_SCHEME=rootless

# armv7/armv7s, rootful
make clean package FINALPACKAGE=1 LEGACY=1

# clean up
rm -rf .theos
