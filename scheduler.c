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
    
    ret = parse_command_line_arguments(argc, argv, filename, &algorithm, &quantum);
    if(ret == -1){
        fprintf(stderr, "Error: Command line arguments were not valid!\n");
        exit(-1);        
    }
    
    /* DEBUG START */
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