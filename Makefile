cc=gcc
CFLAGS=-Iinclude
OUT=algostruct
SRC=main.c

$(OUT): $(SRC)
	$(cc) $(SRC) $(CFLAGS) -o $(OUT)

clean:
	rm $(OUT)
