CC=gcc
CFLAGS=-g $(TRACE_CFLAGS)
LIB=libtracing.a
OBJS=tmtracing.o

$(LIB): $(OBJS)
	ar cr $(LIB) $<
	strip -N trace_reset_buffer -N trace_new_buffer -N trace_event $(LIB)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(LIB) $(OBJS)
