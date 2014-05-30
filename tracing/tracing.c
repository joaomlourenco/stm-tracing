#include <stdio.h>
#include "rdtsc.h"

int main (int argc, char *argv[]) {
    tsc_t t1 = rdtsc ();
    printf ("ts=%llu cid=%u\n", t1.time_stamp, t1.core_id);

    do {
        t1 = rdtsc ();
        printf ("ts=%llu cid=%u\n", t1.time_stamp, t1.core_id);
    } while (t1.core_id == 0);
   
    tsc_t t2 = rdtsc ();
    printf ("ts=%llu cid=%u\n", t2.time_stamp, t2.core_id);
    
    return 1;
}