
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void GetReportedMemory() {
    FILE *maxmem = popen("cat /proc/meminfo | grep \"MemTotal\" | cut -d\":\" -f2", "r");
    char ProcBuf[100];
    char *eptr;
    while (fgets(ProcBuf, sizeof(ProcBuf), maxmem) != NULL) {

        //printf("%s", ProcBuf);
        int TotalMem = strtof(ProcBuf, &eptr);
        printf("Total Memory in KB: %i\n", TotalMem);
        printf("Toal Memory in GB: %i\n", TotalMem / 1000);

    }     
    pclose(maxmem);
}