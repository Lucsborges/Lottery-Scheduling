#include "functions.h"
#include <files.h>
#include <stdlib.h>
#include <time.h>

/* 
Colocar as explicacoes sobre execucao

*/

int main(){

    Process *processes;
    int n_processes = readFile(&processes);

    putOnQueue(&processes, n_processes);


    // printf("Lista de processos:\n");	
    // for(int i = 0; i < n_processes; i++){
    //     printf("%s %d\n", processes[i].name, processes[i].priority);
    // }

    






    free(processes);

    return 0;
}

