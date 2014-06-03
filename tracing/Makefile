CC=gcc
CFLAGS=-g $(TRACE_CFLAGS)
LIB=libtracing.a
OBJS=tmtracing.o

$(LIB): $(OBJS)
	ar cr $(LIB) $<

%.o: %.c
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(LIB) $(OBJS)
