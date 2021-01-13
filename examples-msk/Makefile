# ObjC

OBJCFLAGS = $(shell gnustep-config --objc-flags)
OBJCLIBS = $(shell gnustep-config --base-libs)

INCPATH=$(shell pwd)/../include
LIBPATH=$(shell pwd)/../lib/ubuntu-20.04-clang-10.0-runtime-2.0
# LIBPATH=$(shell pwd)/../lib/raspbian-10-clang-7.0-runtime-1.9-ARM

# scale player
scaleplayer: scaleplayer.m
	clang -mtune=cortex-a53 -O3 -g -o scaleplayer -fblocks -fobjc-arc -x objective-c -DOS_OBJECT_USE_OBJC=0 -I$(INCPATH) $(OBJCFLAGS) scaleplayer.m $(OBJCLIBS) -L$(LIBPATH) -l:libmclarensynthkit.a -l:libalsasoundkit.a -ldispatch -lasound

# tiny example
tiny: tiny.m
	clang -mtune=cortex-a53 -O3 -g -o tiny -fblocks -fobjc-arc -x objective-c -DOS_OBJECT_USE_OBJC=0 -I$(INCPATH) $(OBJCFLAGS) tiny.m $(OBJCLIBS) -L$(LIBPATH) -l:libmclarensynthkit.a -l:libalsasoundkit.a -ldispatch -lasound
