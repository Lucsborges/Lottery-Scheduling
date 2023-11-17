#include "functions.h"
#include "files.h"


Process *processes;
int n_processes, n_processesReady = 0, alarm_count = 0, deadpid;
pid_t pid_atual = 0, pid;
clock_t *startTA, *endTA, startMS, endMS;

int main(){
    signal(SIGALRM, ProcessManager);
    n_processes = readFile(&processes);
    printf("=== Lottery Scheduling ===\n");
    printf("Total Number of Processes: %d\n", n_processes);
    
    startTA = (clock_t*)malloc(sizeof(clock_t) * n_processes);
    endTA = (clock_t*)malloc(sizeof(clock_t) * n_processes);
    
    ProcessManager();


    /*
        Loop that runs until all processes are finished
        sets the ready flag to false for the process when it finishes
    */

    while(countReady()) { 
        int status;
        deadpid = waitpid(pid, &status, WNOHANG);
        if(deadpid){
            int i = preencheEndTA(deadpid);
            printf("Turnaround %s (pid %d):  %.2fs\n", processes[i].name, deadpid, (double)(endTA[i] - startTA[i]) / CLOCKS_PER_SEC);
            processReadyFalse(deadpid);
            if (countReady() == 0)  break;
            LotteryScheduling();
            alarm(6);
            alarm_count = 0;
        }
    }
    endMS = clock();
    printf("Makespan:  %.2fs\n",  (double)(endMS - startMS) / CLOCKS_PER_SEC);
    printf("Se murió\n");
    free(startTA);
    free(endTA);
    free(processes);
    return 0;
}
