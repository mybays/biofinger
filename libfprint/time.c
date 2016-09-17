/* 
author: jbenet
os x, compile with: gcc -o testo test.c 
linux, compile with: gcc -o testo test.c -lrt
*/
 
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
 
#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif
 
 
void current_utc_time(struct timespec *ts) {
 
#ifdef __MACH__ // OS X does not have clock_gettime, use clock_get_time
  clock_serv_t cclock;
  mach_timespec_t mts;
  host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
  clock_get_time(cclock, &mts);
  mach_port_deallocate(mach_task_self(), cclock);
  ts->tv_sec = mts.tv_sec;
  ts->tv_nsec = mts.tv_nsec;
#else
  clock_gettime(CLOCK_REALTIME, ts);
#endif
 
}
 
 
int main(int argc, char **argv) {
 
  struct timespec ts;
  current_utc_time(&ts);
 
  printf("s:  %lu\n", ts.tv_sec);
  printf("ns: %lu\n", ts.tv_nsec);
  return 0;
 
}
