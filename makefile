OBJ_FLDR=build/
SRC_FLDR=src/
BIN_FLDR=bin/
OBJ_STR=$(OBJ_FLDR)lib.o $(OBJ_FLDR)sc.o $(OBJ_FLDR)myTerm.o $(OBJ_FLDR)myBigChars.o $(OBJ_FLDR)myReadkey.o $(OBJ_FLDR)interface.o
OBJ_F=lib.o sc.o myTerm.o myBigChars.o myReadkey.o interface.o




TESTS=binFldr buildFldr

.PHONY: all clean

all: $(TESTS) $(OBJ_F)
	gcc $(OBJ_STR) -o $(BIN_FLDR)sc
	./$(BIN_FLDR)sc

lib.o: $(SRC_FLDR)lib.c
	gcc -c $(SRC_FLDR)lib.c -o $(OBJ_FLDR)lib.o

sc.o: $(SRC_FLDR)sc.c
	gcc  -c $(SRC_FLDR)sc.c -o $(OBJ_FLDR)sc.o

myTerm.o: $(SRC_FLDR)myTerm.c
	gcc  -c $(SRC_FLDR)myTerm.c -o $(OBJ_FLDR)myTerm.o

myBigChars.o: $(SRC_FLDR)myBigChars.c
	gcc -c $(SRC_FLDR)myBigChars.c -o $(OBJ_FLDR)myBigChars.o

myReadkey.o: $(SRC_FLDR)myReadkey.c
	gcc  -c $(SRC_FLDR)myReadkey.c -o $(OBJ_FLDR)myReadkey.o

interface.o: $(SRC_FLDR)interface.c
	gcc -c $(SRC_FLDR)interface.c -o $(OBJ_FLDR)interface.o

binFldr:
	[ -d $(BIN_FLDR) ] || mkdir $(BIN_FLDR)

buildFldr:
	[ -d $(OBJ_FLDR) ] || mkdir $(OBJ_FLDR)

clean:
	rm -rf $(OBJ_FLDR)*.*
	rm -rf $(BIN_FLDR)*
