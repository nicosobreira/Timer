CC=gcc
CFLAGS=-Wall
LDFLAGS=-lncurses

BDIR=./bin
SDIR=./src
ODIR=./obj

BIN=$(BDIR)/timer
SRCS=$(wildcard $(SDIR)/*.c)
OBJS=$(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))

all: $(BIN)

$(BIN): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@

run: all
	@printf "\tRunning %s...\n" $(BIN)
	@$(BIN)

clean:
	$(RM) -r $(BDIR)/* $(ODIR)/*
