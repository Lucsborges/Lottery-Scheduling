#include "functions.h"
#include "files.h"

/* 
Colocar as explicacoes sobre execucao

*/
Process *processes;
int n_processes, n_processesReady = 0;
pid_t pid_atual = 0, pid;



int main(){

    n_processes = readFile(&processes);
  
    signal(SIGALRM,ProcessManager);
    

    ProcessManager();


    //LotteryScheduling();

    // printf("Lista de processos:\n");	
    // for(int i = 0; i < n_processes; i++){
    //     printf("%s %d\n", processes[i].name, processes[i].priority);
    // }

    while(1) pause();


    free(processes);
    return 0;
}

/*
TODO:

    LotteryScheduling


*/