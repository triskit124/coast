#
# This makefile is cobbled together from some great examples here:
# https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
# https://stackoverflow.com/questions/3774568/makefile-issue-smart-way-to-scan-directory-tree-for-c-files
# https://github.com/Adelin0s/Nocturn-Engine/blob/master/source/src/Makefile
#

.PHONY: depend clean run


# define optional build configurations
#
USING_VALGRIND 		= false
USING_ASAN 			= false


# define the final target to build
#
TARGET = coast


# the compiler: gcc for C program, g++ for C++
#
CC = g++


# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#  -O3 optimization flag
#
CFLAGS = -std=c++17 -Wall -Wextra -Wpedantic

ifeq ($(USING_VALGRIND), true)
CFLAGS += -g -O0
else
CFLAGS += -O3
endif


# Define directories
#
LIBDIR = lib
DOCDIR = doc
INCDIR = include
BUILDDIR = build
SRCDIRS = src\
		  src/component\
		  src/core\
	      src/math\
		  src/render\


# define any directories containing header files other than /usr/include
#
INCLUDES = -I./$(INCDIR)


# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
#
LFLAGS =


# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
#
LIBS =


# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# get a list of build directories
#
BUILDDIRS = $(foreach dir, $(SRCDIRS), $(BUILDDIR)/$(dir))


# get a list of the C++ source files
#
SOURCES = $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.cc))


# create a list of the C++ object files to build
#
OBJS = $(patsubst %.cc, $(BUILDDIR)/%.o, $(SOURCES))


all: $(BUILDDIR)/$(TARGET)


$(BUILDDIR)/$(TARGET): $(OBJS)
	@echo "\nBuilding "$(TARGET)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(BUILDDIR)/$(TARGET) $(OBJS) $(LFLAGS) $(LIBS)
	@echo "\n\n🌊 All Done! 🌊"


$(BUILDDIR)/%.o: %.cc $(BUILDDIRS)
	@echo "\nBuilding "$@" from "$<
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@


$(BUILDDIRS):
	$(shell mkdir -p $(BUILDDIRS))


valgrind: $(BUILDDIR)/$(TARGET)
	valgrind --leak-check=yes $(BUILDDIR)/$(TARGET)


clean:
	rm -rf $(BUILDDIR)


run:
	./$(BUILDDIR)/$(TARGET)
