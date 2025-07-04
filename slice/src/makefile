################################################################################
#                                                                              #
# makefile.os                                                                  #
#                                                                              #
# slice utility                                                                #
#                                                                              #
# version 1.3.0 release 1                                                      #
#                                                                              #
# copyright (c) 2020-2025 Code Construct Systems (CCS) [CONFIDENTIAL]          #
#                                                                              #
################################################################################

# Open Systems OS/OE port

#
# slice utility application name
#
TARGET = slice

#
# Application installation location
#
INSTALLATION = ../bin

#
# C++ compiler flags
#
CC = gcc
CFLAGS = -c -std=c99

#
# C compiler definitions flags
#
CDEFINITIONS = \
	-D_ARCH_64 \
	-D_POSIX_SOURCE

#
# C compiler debug and optimize flags
#
CDEBUG = -g
COPTIMIZE = -O3 -fno-strict-overflow

#
# Object files
#
OBJECTS = \
	slice.o \
	options.c \
	port.o

#
# C compiler debug and optimize flags
#
CDEBUG = -g
COPTIMIZE = -O3 -fno-strict-overflow

#
# C compiler warnings flags
#
CWARNINGS = \
	-Werror \
	-Wall \
	-Wextra \
	-Wwrite-strings \
	-Winit-self \
	-Wcast-align \
	-Wpointer-arith \
	-Wstrict-aliasing \
	-Wformat=2 \
	-Wmissing-declarations \
	-Wmissing-include-dirs \
	-Wno-unused-parameter \
	-Wuninitialized \
	-Wold-style-definition \
	-Wstrict-prototypes \
	-Wmissing-prototypes

#
# Object files
#
OBJECTS = \
	slice.o \
	options.o \
	port.o

all: $(TARGET)

#
# Rule for creating slice utility application file
#
$(TARGET): $(OBJECTS)
	@echo "building application: $@"
	@$(CC) $(OBJECTS) -lm -o $@

#
# Rule for creating object files
#
.c.o:
	@echo "building: $@"
	@$(CC) $(CFLAGS) $(INCLUDE) $(CWARNINGS) $(CDEBUG) $(COPTIMIZE) $(CDEFINITIONS) -o $@ $<

#
# Rule for deploying application and other files
#
deploy: $(TARGET)
	cp -f $(TARGET) $(INSTALLATION)
	cp -f $(TARGET).doc $(INSTALLATION)

#
# Rule for cleaning out generated files
#
clean:
	@rm -f *.o
	@rm -f $(TARGET)
