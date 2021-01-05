# ObjC

OBJCFLAGS = $(shell gnustep-config --objc-flags)
OBJCLIBS = $(shell gnustep-config --base-libs)

INCPATH=$(shell pwd)/../include
LIBPATH=$(shell pwd)/../lib/ubuntu-20.04-clang-10.0-runtime-2.0

askseqdump: askseqdump.m
	clang -O3 -g -o askseqdump -fblocks -fobjc-arc -x objective-c -DOS_OBJECT_USE_OBJC=0 -I$(INCPATH) $(OBJCFLAGS) askseqdump.m $(OBJCLIBS) -L$(LIBPATH) -l:libalsasoundkit.a -ldispatch -lasound

askseqlist: askseqlist.m
	clang -O3 -g -o askseqlist -fblocks -fobjc-arc -x objective-c -DOS_OBJECT_USE_OBJC=0 -I$(INCPATH) $(OBJCFLAGS) askseqlist.m $(OBJCLIBS) -L$(LIBPATH) -l:libalsasoundkit.a -ldispatch -lasound

askpcmlist: askpcmlist.m
	clang -O3 -g -o askpcmlist -fblocks -fobjc-arc -x objective-c -DOS_OBJECT_USE_OBJC=0 -I$(INCPATH) $(OBJCFLAGS) askpcmlist.m $(OBJCLIBS) -L$(LIBPATH) -l:libalsasoundkit.a -ldispatch -lasound

miniosc1: miniosc1.m
	clang -O3 -g -o miniosc1 -fblocks -fobjc-arc -x objective-c -DOS_OBJECT_USE_OBJC=0 -I$(INCPATH) $(OBJCFLAGS) miniosc1.m $(OBJCLIBS) -L$(LIBPATH) -l:libalsasoundkit.a -ldispatch -lasound

minisynth1: minisynth1.m
	clang -O3 -g -o minisynth1 -fblocks -fobjc-arc -x objective-c -DOS_OBJECT_USE_OBJC=0 -I$(INCPATH) $(OBJCFLAGS) minisynth1.m $(OBJCLIBS) -L$(LIBPATH) -l:libalsasoundkit.a -ldispatch -lasound
