#include <stdio.h>
#include "tmtracing.h"

void trace_dump_buffer (const trace_buffer_t *buf) {
	int i, count=0;
	assert (buf != NULL);
	for (i = buf->pos;  i < BUFFER_SIZE;  i++) {
		if (buf->data[i] != 0)
			break;
	}
	for (;  i < BUFFER_SIZE;  i+=6) {
		printf ("%12d = %ld %ld %ld %ld %ld %ld\n", count++, 
				buf->data[i+0], buf->data[i+1], buf->data[i+2], 
				buf->data[i+3], buf->data[i+4], buf->data[i+5]);			
	}
	for (i = 0;  i < buf->pos;  i++) {
		if (buf->data[i] != 0)
			break;
	}
	for (;  i < buf->pos;  i+=6) {
		printf ("%12d = %ld %ld %ld %ld %ld %ld\n", count++, 
				buf->data[i+0], buf->data[i+1], buf->data[i+2], 
				buf->data[i+3], buf->data[i+4], buf->data[i+5]);			
	}
}