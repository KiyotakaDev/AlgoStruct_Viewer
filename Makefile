cc=gcc
OUT=algostruct
SRC=main.c

$(OUT): $(SRC)
	$(cc) $(SRC) -o $(OUT)

clean:
	rm $(OUT)
