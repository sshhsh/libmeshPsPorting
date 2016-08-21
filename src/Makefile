CFLAGS = -Werror \
	 -Wunused \
	 -Wuninitialized \
	 -Wreturn-type \
	 -Wmissing-prototypes \
	 -Wmissing-declarations \
	 -Wunreachable-code \

ifdef OPENWRT_BUILD
CFLAGS += -DARCH_BIG_ENDIAN -DOPENWRT_BUILD -fhonour-copts
endif

CFLAGS+= -DDEBUG_ENABLE

INCLUDES = -I ./include

libmeshPsPorting: test.c main.c
	$(CC) $(INCLUDES) $(CFLAGS) -o libmeshPsPorting test.c main.c -lsqlite3

clean:
	rm -f *.o
