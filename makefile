TARGET=./bin/perfectsense
SRC_DIR=./src
OBJ_DIR=./build
SRC_FILES=$(wildcard $(SRC_DIR)/*.c)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
CCFLAGS=-Wall -I/usr/local/include
LIBFLAGS=-L/usr/local/lib -lgsl -lgslcblas -lm 

perfectsense: $(OBJ_FILES)
	mkdir -p bin
	gcc -o ./bin/$@ $^ $(LIBFLAGS) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p build
	gcc $(CCFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR)/*
	rm -rf $(TARGET)
