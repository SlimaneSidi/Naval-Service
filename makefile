CC := gcc
CFLAGS := -Wall -O2 -o

BUILDDIR := ./build
INCLUDE := ./include
SRC := ./src
SRCFILES := main.c func.c
OBJFILES := $(patsubst %.c, $(BUILDDIR)/%.o, $(SRCFILES))

all: $(BUILDDIR) exec

$(BUILDDIR):
	mkdir $(BUILDDIR)

exec: $(OBJFILES)
	$(CC) $(CFLAGS) $@ $^ -lm -lX11 -lglut -lGL -pthread 

$(BUILDDIR)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $@ -c $< -Wno-unused-result

clean:
	rm -f $(BUILDDIR)/*.o
	rm -fr $(BUILDDIR)
	rm -f exec