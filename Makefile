CC=g++
CFLAGS=-std=c++11 -static-libstdc++
SC=src/*
NECO=src/gui/*
OB=src/gui/images/*


DOXYFILE = doxyconfig
DOXY_DIR = doc

all:	deska.o bludiste2015  bludiste2015-gui 

deska.o: ./src/deska.cpp
	$(CC) $(CFLAGS) -c ./src/deska.cpp -o ./src/deska.o
	
bludisce.o: ./src/deska.cpp
	$(CC) $(CFLAGS) -c ./src/bludiste.cpp -o ./src/bludiste.o
bludiste2015: ./src/bludiste.o	
	$(CC) $(CFLAGS) ./src/bludiste.o -o bludiste2015 ./src/deska.o
clean:
	rm -f autosave.txt *.o  *.zip bludiste2015 ./src/*.o ./src/gui/*.o ./src/gui/bludiste2015
run-cli:
	./bludiste2015
run:
	./src/gui/bludiste2015
bludiste2015-gui:
	
	cd src/gui/ && \
	qmake QMAKE_CXX=g++-4.9 -o Makefile bludiste.pro && \
	make -j 4
	
	
doxygen:
	@command -v doxygen >/dev/null 2>&1 \
		&& { doxygen $(DOXYFILE); true; } \
		|| echo "icp-make: Doxygen not installed."
pack:
	zip xkonde03-xcerve15.zip  Makefile $(SC) $(NECO) $(OB) README doxyconfig vitez.txt
	