
// Check from http://stackoverflow.com/questions/1505582/determining-32-vs-64-bit-in-c

// Check windows
#if _WIN32 || _WIN64
#if _WIN64
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

// Check GCC
#if __GNUC__
#if __x86_64__ || __ppc64__
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif


#ifndef __RDTSC_H_DEFINED__
#define __RDTSC_H_DEFINED__


//#if defined(__i386__)

//static __inline__ unsigned long long rdtsc(void)
//{
//  unsigned long long int x;
//     __asm__ volatile (".byte 0x0f, 0x31" : "=A" (x));
//     return x;
//}
//#elif defined(__x86_64__)

////typedef unsigned long long int unsigned long long;

//static __inline__ unsigned long long rdtsc(void)
//{
//  unsigned hi, lo;
//  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
//  return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
//}

//#elif defined(__powerpc__)

//typedef unsigned long long int unsigned long long;

//static __inline__ unsigned long long rdtsc(void)
//{
//  unsigned long long int result=0;
//  unsigned long int upper, lower,tmp;
//  __asm__ volatile(
//                "0:                  \n"
//                "\tmftbu   %0           \n"
//                "\tmftb    %1           \n"
//                "\tmftbu   %2           \n"
//                "\tcmpw    %2,%0        \n"
//                "\tbne     0b         \n"
//                : "=r"(upper),"=r"(lower),"=r"(tmp)
//                );
//  result = upper;
//  result = result<<32;
//  result = result|lower;

//  return(result);
//}

//#else

//#error "No tick counter is available!"

//#endif


///*  $RCSfile:  $   $Author: kazutomo $
// *  $Revision: 1.6 $  $Date: 2005/04/13 18:49:58 $
// */

#include <stdlib.h>

typedef struct {
    unsigned long long time_stamp;
    unsigned int core_id;
} tsc_t;


static __inline__ tsc_t rdtsc (void) {
    unsigned long cycles_high, cycles_low, core_id;
    tsc_t ts;

#ifdef ENVIRONMENT32
    __asm__ __volatile__ (
        "CPUID\n\t"          /* serialize      */
        "RDTSC\n\t"         /* read the clock */
        "mov %%edx, %0\n\t"
        "mov %%eax, %1\n\t"
        "mov %%ecx, %2\n\t"
        : "=r" (cycles_high), "=r" (cycles_low), "=r" (core_id)
        : /* no input */
        : "%eax", "%ebx", "%ecx"
    );
#elif defined ENVIRONMENT64
    __asm__ __volatile__ (
        "CPUID\n\t"          /* serialize      */
        "RDTSC\n\t"         /* read the clock */
        "mov %%rdx, %0\n\t"
        "mov %%rax, %1\n\t"
        "mov %%rcx, %2\n\t"
        : "=r" (cycles_high), "=r" (cycles_low), "=r" (core_id)
        : /* no input */
        : "%rax", "%rbx", "%rcx"
    );
#endif

    ts.time_stamp = (((unsigned long long) cycles_high << 32) | cycles_low);
    ts.core_id = (unsigned int) core_id;

    return ts;
}


#endif

