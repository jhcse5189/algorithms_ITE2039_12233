SHELL = /bin/sh
.SUFFIXES:
.SUFFIXES: .cpp .o

CXX=g++

SRCDIR=src/
INC=include/
LIBS=lib/

TARGET_SRC:=$(SRCDIR)main.cpp
TARGET_OBJ:=$(SRCDIR)main.o

SRCS_FOR_LIB:=$(SRCDIR)dyn.cpp
OBJS_FOR_LIB:=$(SRCS_FOR_LIB:.cpp=.o)

CFLAGS+= -g -fPIC -I $(INC)

TARGET=main

all: $(TARGET)

$(TARGET): $(TARGET_OBJ)
	$(CXX) $(CFLAGS) -o $(SRCDIR)dyn.o -c $(SRCDIR)dyn.cpp
	make static_library
	$(CXX) $(CFLAGS) -o $@ $^ -L $(LIBS) -lbpt

clean:
	rm $(TARGET) $(TARGET_OBJ) $(OBJS_FOR_LIB) $(LIBS)*

library:
	g++ -shared -Wl,-soname,libbpt.so -o $(LIBS)libbpt.so $(OBJS_FOR_LIB)

static_library:
	ar cr $(LIBS)libbpt.a $(OBJS_FOR_LIB)
