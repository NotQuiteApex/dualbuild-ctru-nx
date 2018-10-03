all:
	make -f Makefile.3ds
	make -f Makefile.nx

3ds:
	make -f Makefile.3ds

nx:
	make -f Makefile.nx

clean:
	make -f Makefile.3ds clean
	make -f Makefile.nx clean
