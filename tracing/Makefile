CFLAGS=-g $(TRACE_CFLAGS)
LIB=libtracing.a
OBJS=tmtracing.o

$(LIB): $(OBJS)
	ar cr $(LIB) $<

%.o: %.c
	gcc -c $(CFLAGS) $<

clean:
	rm -f $(LIB) $(OBJS)
