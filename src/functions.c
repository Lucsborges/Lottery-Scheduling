#include "functions.h"


int putOnQueue(Process **processes, int n_processes){

    for(int i = 0; i < n_processes; i++){
        printf("%s %d\n", (*processes)[i].name, (*processes)[i].priority);

        if(fork() == 0){
            runProcess();
        }
        else{
            printf("Processo pai %d\n", getpid());
        }



    }
    // Codigo do pai



    return 1;
}


void runProcess(){
    for(int i = 0; i < 10; i++);
    printf("Processo %d acabou\n", getpid());
    exit(0);
}