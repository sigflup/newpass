CC=cc
PREFIX=/usr/local

newpass: main.c
	${CC} main.c -o newpass

install: newpass
	cp newpass ${PREFIX}/bin
clean:
	rm newpass
