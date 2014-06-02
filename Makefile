# trace and log tl2 calls
TRACE_CFLAGS=#-DTL2_TRACE -I../tracing
TRACE_LDLAGS=#-L../../tracing
LIBS=#-ltracing
MAKEFLAGS=TRACE_CFLAGS=$(TRACE_CFLAGS) TRACE_LDLAGS=$(TRACE_LDLAGS) LIBS=$(LIBS)

SUBDIRS=tl2-x86-0.9.6 tracing stamp-0.9.10

all:
	for i in $(SUBDIRS); do make -C $$i ; done

clean:
	for i in $(SUBDIRS); do make -C $$i clean ; done

