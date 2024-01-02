#ifndef CPUCYCLES_H
#define CPUCYCLES_H

#include <stdint.h>

#ifdef USE_RDPMC  /* Needs echo 2 > /sys/devices/cpu/rdpmc */

static inline uint64_t cpucycles(void) {
  const uint32_t ecx = (1U << 30) + 1;
  uint64_t result;

  __asm__ volatile ("rdpmc; shlq $32,%%rdx; orq %%rdx,%%rax"
    : "=a" (result) : "c" (ecx) : "rdx");

  return result;
}

#else

static inline uint64_t cpucycles(void) {
  uint64_t result;

   __asm__ volatile ("rdtsc; shlq $32,%%rdx; orq %%rdx,%%rax"
     : "=a" (result) : : "%rdx");
  //__asm__ volatile ("rdcycle %0" : "=r" (result));
  // __asm__ volatile ( "csrr %0, mcycle" : "=r" (result));
 

  return result;
}

#endif

uint64_t cpucycles_overhead(void);

#endif
