CC=gcc
CFLAGS=-g -Wall

BDIR=./bin
SDIR=./src
ODIR=./obj

BIN=$(BDIR)/timer
SRCS=$(wildcard $(SDIR)/*.c)
OBJS=$(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(BDIR)
	@mkdir -p $(SDIR)
	@mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	@./$(BIN)

clean:
	$(RM) -r $(BDIR)/* $(ODIR)/*
