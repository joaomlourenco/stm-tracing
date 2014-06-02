#ifndef __TMTRACING_H_DEFINED__
#define __TMTRACING_H_DEFINED__

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "rdtsc.h"

// each BUFFER_SIZE = 128 MBytes
#define BUFFER_SIZE	(1<<27)
#define BUF_MASK	(BUFFER_SIZE-1)


typedef struct {
	unsigned long *data;
	unsigned int pos;
} trace_buffer_t;


///////////////////
// PRIVATE methods
	
	
	
//////////////////
// PUBLIC methods
inline void trace_reset_buffer (trace_buffer_t *buf) {
	printf ("%s : %s\n", __FILE__, __FUNCTION__);
	assert (buf != NULL);
	assert (buf->data != NULL);
	memset (buf->data, 0, BUFFER_SIZE);
	buf->pos = 0;
}

inline trace_buffer_t *trace_new_buffer (void) {
	printf ("%s : %s\n", __FILE__, __FUNCTION__);
	trace_buffer_t *buf = malloc (sizeof (trace_buffer_t));
	assert (buf != NULL);
	buf->data = malloc (BUFFER_SIZE);
	trace_reset_buffer (buf);
	return buf;
}

void trace_dump_buffer (const trace_buffer_t *buf);

inline void trace_event (trace_buffer_t *buf, const void *data, unsigned int nbytes) {
	printf ("%s : %s\n", __FILE__, __FUNCTION__);
	tsc_t t = rdtsc ();
	unsigned long *b = buf->data;
	b[buf->pos++] = t.time_stamp >> 32;  		buf->pos &= BUF_MASK;
	b[buf->pos++] = (unsigned long)t.time_stamp;  	buf->pos &= BUF_MASK;
	b[buf->pos++] = (unsigned long)t.core_id;  	buf->pos &= BUF_MASK;
	b[buf->pos++] = ((unsigned long *)data)[0];  	buf->pos &= BUF_MASK;
	b[buf->pos++] = ((unsigned long *)data)[1];  	buf->pos &= BUF_MASK;
	b[buf->pos++] = ((unsigned long *)data)[2];  	buf->pos &= BUF_MASK;
}

#endif