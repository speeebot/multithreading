CC=gcc
CFLAGS=-g -Wall -pthread

.PHONY : all
all: multithread multithread_mutex

multithread: multithread.o
	$(CC) $(CFLAGS) $< -o $@

multithread_mutex: multithread_mutex.o
	$(CC) $(CFLAGS) $< -o $@

#-c tells compiler to skip linking phase and generate object files instead
#automatic variables: $@ is target name and $^ is dependencies
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -r *.o 
