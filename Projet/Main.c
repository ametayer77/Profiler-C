






/* AUTEURS : Metayer Ambre 
*  Creation 09-10-2018
∗  Modification  22-10-2018*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*Pour Mac*/


#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif




#define BILLION 1000000000L 


#define PROFILE struct timespec start; struct timespec stop; \
        current_utc_time(&start); current_utc_time(&stop); \
        double accum = (start.tv_sec ) + (double)(start.tv_nsec ) / (double)BILLION; \
        printf("%s -- time : %.6lfs \n",__FUNCTION__, accum);

#define return current_utc_time(&stop); \
        accum = ( stop.tv_sec ) + (double)( stop.tv_nsec ) / (double)BILLION; \
        printf("END -- time :  %.6lfs \n", accum); return






/*Pour les Mac qui ne posède pas clock_gettime*/


void current_utc_time(struct timespec *ts) {

    #ifdef __MACH__ 
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





int fact (int n) {

    PROFILE
    int res;

    if (n <= 1) {
        return 1;
    }

    else {
        res = n * fact(n-1);
        return res;
    }
    
    
    
}




int main(int argc, char **argv, char **arge) {



    
    PROFILE
    fact(5);



  return 0;
}


