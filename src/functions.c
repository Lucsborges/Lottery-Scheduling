#include "functions.h"


extern Process *processes;
extern int n_processes, n_processesReady, alarm_count, deadpid;
extern pid_t pid_atual;
extern clock_t *startTA, *endTA, startMS, endMS;


/*
    Function: ProcessManager
    - Creates and stops a process every 2 seconds ultil all processes are created
    - Sets the ready flag to true for every process
    - The First Process is started right away since it is the only one ready on time zero
    - Calls LotteryScheduling every 6 seconds
*/
void ProcessManager(){
    int cpid;
    if(n_processesReady < n_processes){
        
        cpid = createProcess();
        
        processes[n_processesReady].pid = cpid;
        processes[n_processesReady].ready = 1;
        n_processesReady++;
        if (n_processesReady == 1){
            startMS = clock();
            pid_atual = cpid;
            kill(pid_atual, SIGCONT);
        }
        //printf("Processo %d criado. N %d\n", cpid, n_processesReady);
        //for(int i = 0; i < n_processes; i++){
        //printf("%s %d %d\n", processes[i].name, processes[i].pid, processes[i].ready);
        //}
    } 
    
    alarm(2);
    if (alarm_count == 3){
        LotteryScheduling();
        alarm_count = 0;
    }
    alarm_count++;
}


/*
    Function: createProcess
    - Creates a process and stops it
    - Returns the pid of the created process
*/
int createProcess(){
    int pid;
    startTA[n_processesReady] = clock();
    if ((pid = fork()) == 0) {
        runProcess();
        printf("Turnaround Processo %d:  %.2fs\n", getpid(), (double)(endTA - startTA) / CLOCKS_PER_SEC);
        exit(0);
    }
    kill(pid, SIGSTOP); // Process is stopped (to be started by LotteryScheduling)
    return pid;
}

int preencheEndTA(int pid){
    for(int i = 0; i < n_processes; i++){
        if(processes[i].pid == pid){
            endTA[i] = clock();
            return i;
        }
    }
    return 0;
}



/*
    Function: LotteryScheduling
    - Function responsible for choosing the next process to run:
        - Stops the current process
        - Chooses the next process to run
        - Starts the next process
*/
void LotteryScheduling(){
    kill(pid_atual, SIGSTOP);
    int totalTickets = 0;
    srand(time(NULL));

    // Run through all ready processes to calculate the total number of tickets
    for(int i = 0; i < n_processes; i++){
        if(processes[i].ready){
            totalTickets += processes[i].priority + 1;
        }
    }

    int *tickets = (int *)malloc(totalTickets * sizeof(int));

    //printf("==================================\n");
    

    // Initialize the tickets array with sequential values
    for (int i = 0; i < totalTickets; i++) {
        tickets[i] = i;
    }

    // Shuffle the tickets array
    for (int i = totalTickets - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Trocar tickets[i] e tickets[j]
        int temp = tickets[i];
        tickets[i] = tickets[j];
        tickets[j] = temp;
    }

    // Choose a random ticket
    int ticketSorteado = tickets[rand() % totalTickets];

    // Run through all ready processes until the one with the chosen ticket is found
    int cont = 0;
    for (int i = 0; i < n_processes; i++) {
        if(!processes[i].ready){
            continue;
        }
        for(int j = 0; j < processes[i].priority + 1; j++){
            if(ticketSorteado == tickets[cont++]){
                pid_atual = processes[i].pid;
                kill(pid_atual, SIGCONT);
                //printf("Processo %d sorteado\n", pid_atual);
                break;
            }
        }
    }

    free(tickets);
    return;
}

/*
    Function: countReady
    - Counts the number of ready processes
    - Returns the number of ready processes
*/
int countReady(){
    int n_ready = 0;
    for(int i = 0; i < n_processes; i++){
        if(processes[i].ready){
            n_ready++;
        }
    }
    return n_ready;
}    


/*
    Function: runProcess
    - Runs a process for aproximately 30 seconds
*/
void runProcess() {
    if (execl("./processo", "processo",  NULL) < 0){
        printf("Erro ao executar o processo\n");
        exit(0);
    }
    return;
}

/*
    Function: processReadyFalse
    - Sets the ready flag to false for the process that just died
*/
void processReadyFalse(pid_t deadpid){
    //printf("Processo de pid %d \n", deadpid);

    for(int i = 0; i < n_processes; i++){
        if(processes[i].pid == deadpid ){
            //printf("Processo de pid %d morreu \n", deadpid);
            processes[i].ready = 0;
            break;
        }
    }
    //for(int i = 0; i < n_processes; i++){
    //    printf("%s %d %d\n", processes[i].name, processes[i].pid, processes[i].ready);
    //}
    return;
}

