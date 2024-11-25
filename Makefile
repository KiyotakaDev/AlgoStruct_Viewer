cc=gcc
CFLAGS=-Iinclude
OUT=algostruct
SRC=main.c ./src/*

$(OUT): $(SRC)
	$(cc) $(SRC) $(CFLAGS) -o $(OUT)

clean:
	rm $(OUT)
