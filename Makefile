# trace and log tl2 calls
TRACE_CFLAGS=-I../tracing\ -DTL2_TRACE
TRACE_LDFLAGS=-L../../tracing
TRACE_LIB=-ltracing
MAKEFLAGS=TRACE_CFLAGS=$(TRACE_CFLAGS) TRACE_LDFLAGS=$(TRACE_LDFLAGS) TRACE_LIB=$(TRACE_LIB)

SUBDIRS=tracing tl2-x86-0.9.6 stamp-0.9.10

all:
	for i in $(SUBDIRS); do make -C $$i ; done

clean:
	for i in $(SUBDIRS); do make -C $$i clean ; done

