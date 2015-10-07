#Author Rickard Maokei Johansson rickard.joh@gmail.com
LIBS = ./libpower.so

all: libpower.o libpower.so

libpower.o: libpower.c libpower.h
	gcc -c -Wall -Werror -fPIC libpower.c libpower.h

libpower.so: libpower.o
	gcc -shared -o libpower.so libpower.o

test: test.c libpower.so
	gcc $(LIBS) -Wall test.c -o Test -lm

install:
	mv libpower.so /usr/lib/
	echo Installation done!

uninstall:
	rm /usr/lib/libpower.so
	echo Uninstall done, have a nice day!

clean:	
	echo Cleaning time YEAH!
	rm *.o
	rm *.so
	rm *.gch Test
	echo Done cleaning!
