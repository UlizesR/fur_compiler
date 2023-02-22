exec = a.out
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags = -g -Wall -lm -ldl -fPIC -rdynamic 

$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

#install:
# make
# make liba.a
# mkdir -p /us/local/include/a
# cp -r . /src/include/* /us/local/include/a/.
# cp ./liba.a /usr/local/lib/.
# cp ./a.out /usr/local/bin/a 

clean:
	-rm *.out
	-rm src/*.o
	-rm *.a
	-rm src/*.a

lint:
	clang-tidy src/*.c src/include/*.h 