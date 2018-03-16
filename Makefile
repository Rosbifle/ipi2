
APPLI = honshu
CSRC= jugement.c manipulation.c save.c structures.c
CC = gcc

CFLAGS = -Wall -Wextra -ansi -I. 

COBJ=$(CSRC:.c=.o)


.c.o:
	$(CC) $(CFLAGS) -c $*.c

$(APPLI):	$(COBJ)
	$(CC) -o $(APPLI) $(COBJ) -lm

clean:
	-rm *.o *[~%] core *.bak


jugement.o: structures.h
manipulation.o: manipulation.h structures.h
save.o: structures.h
structures.o: structures.h
