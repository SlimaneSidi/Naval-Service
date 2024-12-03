CC := gcc
CFLAGS := -Wall -O2 -o

BUILDDIR := ./build
INCLUDE := ./include
SRC := ./src
SAVE := ./save

SRCFILES := main.c moteur.c menu.c nomBateaux.c
SAVEFILES := save.c

OBJFILES := $(patsubst %.c, $(BUILDDIR)/%.o, $(SRCFILES))
SAVEOBJFILES := $(patsubst %.c, $(BUILDDIR)/%.o, $(SAVEFILES))

all: $(BUILDDIR) exec

$(BUILDDIR):
	mkdir $(BUILDDIR)

exec: $(OBJFILES) $(SAVEOBJFILES)
	$(CC) $(CFLAGS) $@ $^ -lm -lX11 -lglut -lGL -pthread 

$(BUILDDIR)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $@ -c $< -Wno-unused-result

$(BUILDDIR)/%.o: $(SAVE)/%.c
	$(CC) $(CFLAGS) $@ -c $< -Wno-unused-result

lean:
	rm -f $(BUILDDIR)/*.o
	rm -fr $(BUILDDIR)
	rm -f exec

csave:
	rm -f sauvegarde.bin