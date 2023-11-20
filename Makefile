CC = gcc
CFLAGS = -Wall -lm -Iheaders
OBJDIR = objects
BINDIR = bin
SRC_DIR = sources

SRC = $(wildcard $(SRC_DIR)/*.c)
EXEC = $(BINDIR)/project
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJDIR)/%.o,$(SRC))

all: $(EXEC)

$(EXEC): $(OBJ)
	mkdir -p $(BINDIR)
	$(CC) -o $@ $^ $(CFLAGS)

$(OBJDIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(OBJDIR)

mrproper: clean
	rm -rf $(BINDIR)