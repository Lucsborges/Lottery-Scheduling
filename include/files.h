#ifndef FILES_H
#define FILES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <stdbool.h>

#define MAX_N_PROCESSES 11
#define MAX_WORD_LENGTH 20

typedef struct Process{
    char    name[MAX_WORD_LENGTH];
    int     priority;
    pid_t   pid;
    int     ready;
} Process;


int readFile(Process **processes);



#endif
