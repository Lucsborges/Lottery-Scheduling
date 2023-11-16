#include "functions.h"


extern Process *processes;
extern int n_processes, n_processesReady;
extern pid_t pid_atual;


void ProcessManager(){
    int cpid;
    if(n_processesReady < n_processes){
        cpid = createProcess();                  // creates a process and stops it
        processes[n_processesReady].pid = cpid; 
        n_processesReady++;
        alarm(2);
        printf("Processo %d criado. N %d\n", cpid, n_processesReady);
    } 

    LotteryScheduling();
    
}



int createProcess(){
    int pid;
    if ((pid = fork()) == 0) {
        runProcess();
        exit(0);
    }
    kill(pid, SIGSTOP); // Process is created and stopped
    int status;
    waitpid(pid, &status, WNOHANG);
    return pid;
}





void LotteryScheduling(){
    kill(pid_atual, SIGSTOP);
    
    printf("lottery\n");
    /*
        Codigo de decisao de quem vai rodar

        pid = processo que vai rodar
    */
    
    alarm(6);
    kill(pid_atual, SIGCONT);
}


void runProcess() {
    for(long double i = 0; i < MAX_TEMP; i++); 
}