
CC = gcc -g -Wall -Wextra -ansi
CCUNIT = $(CC) -lcunit

SRCDIR = src
OBJDIR = obj
BINDIR = bin
TESTDIR = tests
INCDIR = inc

$(BINDIR)/test.o: $(TESTDIR)/HonShu_test.c  $(SRCDIR)/save.c $(SRCDIR)/jugement.c $(SRCDIR)/structures.c
	$(CC) -c $(TESTDIR)/HonShu_test.c $(SRCDIR)/save.c $(SRCDIR)/jugement.c $(SRCDIR)/structures.c
$(BINDIR)/main.o: $(SRCDIR)/main.c $(SRCDIR)/save.c $(SRCDIR)/structures.c
	$(CC) -c $(SRCDIR)/main.c $(SRCDIR)/save.c $(SRCDIR)/structures.c

$(BINDIR)/save.o: $(SRCDIR)/save.c $(SRCDIR)/structures.c
	$(CC) -c $(SRCDIR)/save.c $(SRCDIR)/structures.c

$(BINDIR)/jugement.o: $(SRCDIR)/jugement.c $(SRCDIR)/structures.c
	$(CC) -c $(SRCDIR)/jugement.c $(SRCDIR)/structures.c

$(BINDIR)/structures.o: $(SRCDIR)/structures.c
	$(CC) -c structures.c


test: $(TESTDIR)/HonShu_test

clean:
	rm $(OBJDIR)/*.o
	rm $(TESTDIR)/test
