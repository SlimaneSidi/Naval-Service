CC := gcc
CFLAGS := -Wall -O2 -o

BUILDDIR := ./build
INCLUDE := ./include
SRC := ./src
SRCFILES := main.c moteur.c menu.c nomBateaux.c visuals.c
OBJFILES := $(patsubst %.c, $(BUILDDIR)/%.o, $(SRCFILES))

export MESA_LOADER_DRIVER_OVERRIDE = zink
export LIBGL_ALWAYS_SOFTWARE = 1

all: $(BUILDDIR) exec

$(BUILDDIR):
	mkdir $(BUILDDIR)

exec: $(OBJFILES)
	$(CC) $(CFLAGS) $@ $^ lib/gfxlib/libisentlib.a -lm -lX11 -lglut -lGL -pthread 

$(BUILDDIR)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $@ -c $< -Wno-unused-result

lean:
	rm -f $(BUILDDIR)/*.o
	rm -fr $(BUILDDIR)
	rm -f exec
