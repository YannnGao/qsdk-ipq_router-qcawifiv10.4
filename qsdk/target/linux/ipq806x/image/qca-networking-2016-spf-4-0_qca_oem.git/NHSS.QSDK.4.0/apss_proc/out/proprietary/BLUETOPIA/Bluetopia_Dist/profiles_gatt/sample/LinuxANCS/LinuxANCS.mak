
ifndef CC
   CC = gcc
endif

INCLDDIRS = -I../../../profiles/GATT/include      \
	    -I../../../profiles_gatt/ANCS/include \
	    -I../../DIS/include                   \
	    -I../../GAPS/include                  \
	    -I../../../include                    \
	    -I../../../debug/include

ifndef SYSTEMLIBS
   SYSTEMLIBS = -lpthread -lm
endif

CFLAGS = -Wall $(DEFS) $(INCLDDIRS) $(GLOBINCLDDIRS) -O2 -fno-strict-aliasing $(GLOBCFLAGS)

LDFLAGS = -L../../../lib -L../../../profiles/GATT/lib -L../../DIS/lib -L../../GAPS/lib -L../../../debug/lib -L../../../profiles_gatt/ANCS/lib $(GLOBLDFLAGS)

LDLIBS = -lSS1BTPS -lSS1BTGAT -lSS1BTDIS -lSS1BTGAP -lBTPSVEND -lSS1BTDBG -lSS1BTANC $(SYSTEMLIBS) $(GLOBLDLIBS)

OBJS = LinuxANCS.o

.PHONY:
all: LinuxANCS

LinuxANCS: $(OBJS)

.PHONY: clean veryclean realclean
clean veryclean realclean:
	-rm -f *.o
	-rm -f *~
	-rm -f LinuxANCS

