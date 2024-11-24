cc=gcc
CFLAGS=-Iinclude
OUT=executeme
SRC=main.c printer.c

$(OUT): $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

clean:
	rm -r $(OUT)
