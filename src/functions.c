#include "functions.h"


extern Process *processes;
extern int n_processes, n_processesReady, alarm_count, deadpid;
extern pid_t pid_atual;


void ProcessManager(){
    int cpid;
    if(n_processesReady < n_processes){
        cpid = createProcess();                  // creates a process and stops it
        
        processes[n_processesReady].pid = cpid;
        processes[n_processesReady].ready = 1;
        n_processesReady++;
        //if (n_processesReady == 1){
        //    pid_atual = cpid;
        //    kill(pid_atual, SIGCONT);
        //}
        printf("Processo %d criado. N %d\n", cpid, n_processesReady);

        for(int i = 0; i < n_processes; i++){
        printf("%s %d %d\n", processes[i].name, processes[i].pid, processes[i].ready);
        }
    } 

    alarm(2);
    if (alarm_count == 3){
        LotteryScheduling();
        alarm_count = 0;
    }
    alarm_count++;
}

int createProcess(){
    int pid;
    if ((pid = fork()) == 0) {
        runProcess();
        exit(0);
    }

    //kill(pid, SIGSTOP); // Process is created and stopped
    
    return pid;
}




void LotteryScheduling(){
    //for(int i = 0; i < n_processes; i++){
    //    printf("%s %d %d\n", processes[i].name, processes[i].pid, processes[i].ready);
    //}
    printf("==================================\n");
    //kill(pid_atual, SIGSTOP);

    int n_ready = countReady();

    printf("Numero de processos ready: %d \n", n_ready);

    //int total_tickets = 0;
    // Percorre todos os processos prontos e soma os tickets
    //for(int i = 0; i < n_processesReady; i++){
     //   total_tickets += processes[i].tickets;
   // }



    printf("lottery\n");
    /*
        Codigo de decisao de quem vai rodar

        pid_atual = processo que vai rodar
    */
    
    //alarm(6);
        
}

int countReady(){
    int n_ready = 0;
    for(int i = 0; i < n_processes; i++){
        if(processes[i].ready){
            n_ready++;
        }
    }
    return n_ready;
}    


void runProcess() {
    for(long double i = 0; i < MAX_TEMP; i++);
}

void ZombieKiller(int sig){}

void processReadyFalse(pid_t deadpid){
    printf("Processo de pid %d \n", deadpid);

    for(int i = 0; i < n_processes; i++){
        printf("Processo de pid %d testou com %d\n", deadpid, processes[i].pid);
        if(processes[i].pid == deadpid ){
            printf("Processo de pid %d false \n", deadpid);
            processes[i].ready = 0;
            break;
        }
    }
    for(int i = 0; i < n_processes; i++){
        printf("%s %d %d\n", processes[i].name, processes[i].pid, processes[i].ready);
    }
}

