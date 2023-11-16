#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "files.h"

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <sys/wait.h>

#define MAX_TEMP 3000000000    
//7000000000 

int putOnQueue(Process **processes, int n_processes, Process **processesReady);

void runProcess();

void LotteryScheduling();

int createProcess();

void processoContador(int n);

void ProcessManager();

void ZombieKiller(int sig);

void processReadyFalse(pid_t pid);

int countReady();

#endif


