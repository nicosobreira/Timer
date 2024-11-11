CC=gcc
CFLAGS=-Wall

BDIR=./bin
SDIR=./src
ODIR=./obj

BIN=$(BDIR)/timer
SRCS=$(wildcard $(SDIR)/*.c)
OBJS=$(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))

all: $(BIN)

$(BIN): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@

run: all
	@echo -e "\tRunning $(BIN)...\n"
	@$(BIN)

clean:
	$(RM) -r $(BDIR)/* $(ODIR)/*
