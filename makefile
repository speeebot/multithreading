
CC=clang
CFLAGS=-g -Wall -pthread
OBJS=multithread.o
BIN=bin/multithread

all: $(BIN)

#-c tells compiler to skip linking phase and generate object files instead
#automatic variables: $@ is target name and $^ is dependencies

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -r $(BIN) *.o *.dSYM
