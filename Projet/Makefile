test: Main.o 
	gcc -o  test Main.o -lrt


Main.o: Main.c 
	gcc -c -O2 -Wall Main.c


clean:
	rm -f *.o


mrproper: clean
	rm -f test


install: test
	mkdir ../bin
	mv test ../bin/test
	make mrproper

uninstall: mrproper
	rm -f ../bin/test
	rm -rf ../bin