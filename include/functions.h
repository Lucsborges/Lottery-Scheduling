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

 
#define PROCESS_PATH "./processo"
#define PROCESS_NAME "processo"


//7000000000 


void runProcess();

void LotteryScheduling();

int createProcess();

void ProcessManager();

void processReadyFalse(pid_t deadpid);

int countReady();

int preencheEndTA(int pid);

#endif


