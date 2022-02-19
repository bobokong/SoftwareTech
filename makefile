CC=gcc

CFLAGS=-g -O2 
# `ncurses5-config --cflags --libs`

IDIR=src
ODIR=build

# LAB2B.c 
sources=ch2_a.c ch2_c.c

SOURCES=$(patsubst %,$(IDIR)/%, $(sources))
OBJS=$(patsubst %.c,$(ODIR)/%.exe, $(sources))
# OBJS = $(patsubst %,$(ODIR)/%, $(_OBJS))

main: $(OBJS)

$(OBJS): $(ODIR)/%.exe: $(IDIR)/%.c
	$(CC) $(CFLAGS) $< -o $@ 

# $(ODIR)/%: $(IDIR)/%.c
# 	$(CC) $(CFLAGS) $< -o $@ 

# $(OBJS): $(SOURCES)
# 	$(CC) $(CFLAGS) -o $@ $<

clean:
	@rm *.exe build/*.exe src/*.exe $(OBJS) -f
