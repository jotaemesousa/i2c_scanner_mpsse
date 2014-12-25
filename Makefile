LDFLAGS=-lmpsse

all: i2c_scanner

i2c_scanner:
	$(CC) $(CFLAGS) main.c -o i2c_scanner $(LDFLAGS)

clean:
	rm -f *.dSYM
	rm -f i2c_scanner

distclean: clean