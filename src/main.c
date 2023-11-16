#include "functions.h"
#include "files.h"

/* 
Colocar as explicacoes sobre execucao

*/
Process *processes;
int n_processes, n_processesReady = 0, alarm_count = 0, deadpid;
pid_t pid_atual = 0, pid;



int main(){
    n_processes = readFile(&processes);
  
    signal(SIGALRM, ProcessManager);
    signal(SIGCHLD, ZombieKiller);
    

    ProcessManager();



    while(countReady() > 0) { 
        int status;
        deadpid = waitpid(pid, &status, WNOHANG);
        if(deadpid){
            processReadyFalse(deadpid);
        }
    }

    free(processes);
    return 0;
}

/*
TODO:

    LotteryScheduling


*/