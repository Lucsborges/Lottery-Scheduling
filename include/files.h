#ifndef FILES_H
#define FILES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_N_PROCESSES 10
#define MAX_WORD_LENGTH 20

typedef struct Process{
    char name[MAX_WORD_LENGTH];
    int priority;
} Process;

int readFile(Process **processes);






#endif
