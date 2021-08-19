CC = gcc
CFLAGS = -pedantic -ansi -Werror -O2
LFLAGS = -static -s
BIN = diffeq

$(BIN): main.o diffeq.o
	$(CC) -o $@ $^ $(LFLAGS)
 
%.o: %.c diffeq.h
	$(CC) -c $< $(CFLAGS)
 
.PHONY : clean
clean:
	$(RM) $(BIN) *.o
