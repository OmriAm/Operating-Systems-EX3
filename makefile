CC=gcc			#define compiler
CFLAGS= -g -Wall	#define flags
 
OBJ1= lencmp.o
OBJ2= lexcmp.o
OBJ3= digcmp.o
OBJ4 = loopcmp.o
#SRCS= lencmp.c
#OBJS = lencmp.o

EXECS=prog1 prog2 prog3 exe

all: $(EXECS)

prog1: $(OBJ1)
	$(CC) $(OBJ1) -o $@
prog2: $(OBJ2)
	$(CC) $(OBJ2) -o $@
prog3: $(OBJ3)
	$(CC) $(OBJ3) -o $@
exe: $(OBJ4)
	$(CC) $(OBJ4) -o $@
	
%.o:%.c %.h
	$(CC) $(CFLAGS) -c $^
	
#$(EXECS): $(OBJS)
#	$(CC) $(OBJS) -o $@


clean:
	rm -f $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(EXECS)
	#rm -f $(OBJS) $(EXECS)

