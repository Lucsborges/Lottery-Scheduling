#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include "files.h"
#include <sys/types.h>
#include <unistd.h>

#define NUM_30s 100000000



int putOnQueue(Process **processes, int n_processes);

void runProcess();






#endif