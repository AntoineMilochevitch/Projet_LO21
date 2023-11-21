CC = gcc
CFLAGS = -Wall -lm -Iheaders `sdl2-config --cflags` `pkg-config --cflags SDL2_ttf`
LDFLAGS = `sdl2-config --libs` `pkg-config --libs SDL2_ttf`
OBJDIR = objects
BINDIR = bin
SRC_DIR = sources

SRC = $(wildcard $(SRC_DIR)/*.c)
EXEC = $(BINDIR)/project
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJDIR)/%.o,$(SRC))

all: $(EXEC)

$(EXEC): $(OBJ)
	mkdir -p $(BINDIR)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(OBJDIR)

mrproper: clean
	rm -rf $(BINDIR)