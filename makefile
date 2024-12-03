CC := gcc
CFLAGS := -Wall -O2 -o

BUILDDIR := ./build
INCLUDE := ./include
SRC := ./src
SAVE := ./save

SRCFILES := main.c moteur.c menu.c nomBateaux.c
SAVEFILES := save.c

SRCFILES := main.c moteur.c menu.c nomBateaux.c visuals.c ourdrawings.c
OBJFILES := $(patsubst %.c, $(BUILDDIR)/%.o, $(SRCFILES))
SAVEOBJFILES := $(patsubst %.c, $(BUILDDIR)/%.o, $(SAVEFILES))

export MESA_LOADER_DRIVER_OVERRIDE = zink
export LIBGL_ALWAYS_SOFTWARE = 1

all: $(BUILDDIR) exec

$(BUILDDIR):
	mkdir $(BUILDDIR)

exec: $(OBJFILES) $(SAVEOBJFILES)
	$(CC) $(CFLAGS) $@ $^ lib/gfxlib/libisentlib.a -lm -lX11 -lglut -lGL -pthread 

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
