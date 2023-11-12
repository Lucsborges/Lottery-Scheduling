#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "files.h"

#define MAX_WORD_LENGTH 20

/*  Function: readFile
    Reads the input file and stores the processes in the processes array
    Returns the number of processes read
    Returns 0 in case of error
*/ 
int readFile(Process **processes){
    FILE *file;
    file = fopen("teste.txt", "r");
    if(file == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 0;
    }

    // Count the number of lines in the file
    int line_count = 0;
    char ch;
    while(!feof(file)){
        ch = fgetc(file);
        if(ch == '\n'){
            line_count++;
        }
    }

    // Allocate memory for the processes array
    *processes = (Process*)malloc(sizeof(Process) * line_count);

    // Reset the file pointer to the beginning of the file
    rewind(file);

    // Store each process
    for(int i = 0; i < line_count; i++){
        fscanf(file, "%s %d", (*processes)[i].name, &(*processes)[i].priority);
    }

    fclose(file);

    return line_count;
}