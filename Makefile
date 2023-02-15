CFLAGS=-std=c++11

CPPSRC := $(wildcard *.cpp)
CSRC := $(wildcard *.c)
OBJ := $(CPPSRC:.cpp=.o) $(CSRC:.c=.o)
DEP := $(wildcard *.h)



libwiringgcc.a : $(OBJ)
	ar -crs $@ $^

%.o: %.cpp $(DEP)
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.c $(DEP)
	$(CC) -c -o $@ $<

clean :
	rm *.o *.a libwiringcc.a || set status 0