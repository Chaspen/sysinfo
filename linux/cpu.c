#include <stdio.h>
#include <stdlib.h>
#include <string.h>




double GetReportedMaxClockSpeed() {
    
    FILE *maxspeed = popen("cat /proc/cpuinfo | grep \"MHz\" | cut -d\":\" -f2", "r");
    char ProcBuf[100];
    char *eptr;
    while (fgets(ProcBuf, sizeof(ProcBuf), maxspeed) != NULL) {

        //printf("%s", ProcBuf);
        double CoreClock = strtod(ProcBuf, &eptr);
        printf("%f\n", CoreClock);
    
        //array
        //return CoreClock;
    } 
    
    //print size of pointer
    //printf("%zu\n", sizeof(maxspeed));

    //print last 8 numbers of string
    //int len = strlen(str);

    
    pclose(maxspeed);
}


int main() {
    GetReportedMaxClockSpeed();
    return 0;
}