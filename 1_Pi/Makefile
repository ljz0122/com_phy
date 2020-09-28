CC = /usr/bin/gcc
LD = /usr/bin/ar -rcs
FLAGS = -O3 -Wall -fmessage-length=0 -lm -lgmp -lmpfr

INCLUDE = -I./include
LIBS = pi_calc

SRCDIR = src
OUTPUTDIR = bin
LIBSDIR = libs

$(shell mkdir $(OUTPUTDIR))
$(shell mkdir $(LIBSDIR))

SRC = $(wildcard $(SRCDIR)/*.c)
SRCS = $(filter-out $(SRCDIR)/pi.c,$(SRC))
OBJ = $(patsubst %c,%o,$(SRCS))
OBJS = $(patsubst src/%,$(LIBSDIR)/%,$(OBJ))
LIB_PATH = $(LIBSDIR)/lib$(LIBS).a
MAIN_SRC = src/pi.c

TARGET = $(OUTPUTDIR)/pi

.PHONY: $(TARGET)

$(TARGET): $(LIB_PATH)
	$(CC) $(MAIN_SRC) -o $(TARGET) $(INCLUDE) -L$(LIBSDIR) -l$(LIBS) $(FLAGS)

$(LIB_PATH): $(OBJS)
	$(LD) $@ $^

$(LIBSDIR)/pi_calc.o: $(SRCDIR)/pi_calc.c
	$(CC) -c $< -o $@ $(LIBSDIR)/custom_math.o $(INCLUDE) $(FLAGS)

$(LIBSDIR)/custom_math.o: $(SRCDIR)/custom_math.c
	$(CC) -c $< -o $@ $(INCLUDE) $(FLAGS)

clean:
	rm -rf bin

libs_clean:
	rm -rf bin
	rm -rf libs