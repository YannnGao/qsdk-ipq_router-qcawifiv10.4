
ifndef CC
   CC = gcc
endif

ifndef AR
   AR = ar
endif

ifndef BLUETOPIA_PATH
   BLUETOPIA_PATH = ../../../../Bluetopia
endif

INCLDDIRS = -I../../../include                             \
	    -I../../../include/server                      \
	    -I$(BLUETOPIA_PATH)/include                    \
	    -I$(BLUETOPIA_PATH)/profiles/GATT/include      \
	    -I$(BLUETOPIA_PATH)/profiles_gatt/BAS/include  \
	    -I$(BLUETOPIA_PATH)/profiles_gatt/DIS/include  \
	    -I$(BLUETOPIA_PATH)/profiles_gatt/HIDS/include \
	    -I$(BLUETOPIA_PATH)/profiles_gatt/SCPS/include

CFLAGS = -Wall $(DEFS) $(INCLDDIRS) $(GLOBINCLDDIRS) -O2 -fno-strict-aliasing $(GLOBCFLAGS)

LDLIBS = -lpthread

OBJS = BTPMHOGM.o HOGMGR.o

.PHONY:
all: libBTPMHOGM.a

libBTPMHOGM.a: $(OBJS)
	$(AR) r $@ $?

.PHONY: clean veryclean realclean
clean veryclean realclean:
	-rm -f *.o
	-rm -f *~
	-rm -f libBTPMHOGM.a

