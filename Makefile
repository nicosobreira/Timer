TDIR=./bin/
TARGET=$(TDIR)timer

CC=gcc
CFLAGS=-Wall

SDIR=./src
SRC=$(shell find $(SDIR) -type f -name *.c)

all:
	mkdir -p $(TDIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: all
	@./$(TARGET)

clean:
	$(RM) $(TDIR)
