/*
 * Ryan Gittins and Phillip Sime
 *
 * CS441: Project 3
 * 
 * 2013-11-02
 *
 */
#include "scheduler.h"

int main(int argc, char * argv[]) {
    char filename[MAXFILENAME];
    algorithm_type algorithm;
    int quantum = 0;
    int ret = 0;
    
    cpu_process *processes = NULL;
    int num_processes = 1;
    
    processes = (cpu_process*) malloc(sizeof(cpu_process) * num_processes);
    if( NULL == processes ) {
        fprintf(stderr, "Error: Failed to allocate memory! Critical failure on %d!", __LINE__);
        exit(-1);
    }
    
    /* Parse command line arguments */
    ret = parse_command_line_arguments(argc, argv, filename, &algorithm, &quantum);
    if(ret == -1){
        fprintf(stderr, "Error: Command line arguments were not valid!\n");
        exit(-1);        
    }
    
    /* Parse input file */
    ret = parse_file_into_processes(filename, &num_processes, &processes);
    if(ret == -1){
        fprintf(stderr, "Error: There was a problem with the input file %s!\n", filename);
        exit(-1);
    }
    
    /* DEBUG START */
    
    int i;
    for(i = 0; i < num_processes; i++){
        printf("----- PROCESS %d INFORMATION -----\n", (i + 1));
        printf("Identifier: %d\n", processes[i].indetifier);
        printf("Burst Length: %d\n", processes[i].burst_length);
        printf("Priority: %d\n", processes[i].priority);
        printf("----- END INFORMATION -----\n\n");    
    }
    
    switch(algorithm){
        case FCFS:
            printf("Algorithm : FCFS\n");
            break;
        case SJF:
            printf("Algorithm : SJF\n");
            break;
        case PRIORITY:
            printf("Algorithm : PRIORITY\n");
            break;
        case RR:
            printf("Algorithm : RR\n");
            break;
        default:
            printf("This shouldn't happen :(\n");
            break;
    }
    printf("Quantum : %d\n", quantum);
    printf("File : %s\n", filename);
    /* DEBUG END */
    
    return 0;
}