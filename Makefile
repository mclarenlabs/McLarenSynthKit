# ObjC

OBJCFLAGS = $(shell gnustep-config --objc-flags)
OBJCLIBS = $(shell gnustep-config --objc-libs)

INCPATH=$(shell pwd)/../include
LIBPATH=$(shell pwd)/../lib/ubuntu-20.04-clang-10.0-runtime-2.0

# VSCode+clangd uses compile_flags.txt to understand how the project is set up
compile_flags.txt: Makefile
	echo "-x" > compile_flags.txt
	echo "objective-c" >> compile_flags.txt
	echo $(OBJCFLAGS) -I$(INCPATH) | sed 's/ /\n/g' >> compile_flags.txt
