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
    
    /* Print pre-processing information */
    print_pre_process_information(algorithm, quantum, filename);
    
    /* Print process information */
    print_process_information(num_processes, &processes);
    
    /* Simulate scheduling of selected algorithm */
    switch(algorithm){
        case FCFS:
            simulate_fcfs(num_processes, &processes);           
            break;
        case SJF:
            simulate_sjf(num_processes, &processes);
            break;
        case PRIORITY:
            simulate_priority(num_processes, &processes);
            break;
        case RR:
            simulate_rr(num_processes, &processes, quantum);
            break;
        case NONE:
            break;
    }
    
    /* Debug information */
    //print_debug(num_processes, &processes, algorithm, quantum, filename);
    
    return 0;
}

int print_pre_process_information(algorithm_type algorithm, int quantum, char *filename){
    switch(algorithm){
        case FCFS:
            printf("Scheduler    :  1 FCFS\n");
            break;
        case SJF:
            printf("Scheduler    :  2 SJF\n");
            break;
        case PRIORITY:
            printf("Scheduler    :  3 PRIORITY\n");
            break;
        case RR:
            printf("Scheduler    :  4 RR\n");
            break;
        case NONE:
            printf("Scheduler    : None assigned\n");
            break;
    }
    printf("Quantum      : %*d\n", 2, quantum);
    printf("Sch. File    : %s\n", filename);
    printf("-------------------------------\n");
    
    return 0;
}

int print_process_information(int num_processes, cpu_process **processes){
    int i;
    /* Arrival order */
    printf("Arrival Order: ");
    for(i = 0; i < num_processes - 1; i++){
        printf("%d, ", (*processes)[i].indetifier);        
    }
    printf("%d\n", (*processes)[i].indetifier);
    
    /* Process information */
    printf("Process Information: \n");
    for(i = 0; i < num_processes; i++){
        printf("%*d      ", 2, (*processes)[i].indetifier);
        printf("%*d      ", 2, (*processes)[i].burst_length);
        printf("%*d\n", 2, (*processes)[i].priority);
    }
    
    /* Print running message */
    printf("-------------------------------\n");
    printf("Running...\n");
    printf("-------------------------------\n");
    
    return 0;
}

int simulate_fcfs(int num_processes, cpu_process **processes){
    int wait_time = 0;
    int turnaround_time = 0;
    int total_wait_time = 0;
    int total_turnaround_time = 0;
    int i;
    
    for(i = 0; i < num_processes; i++){
        wait_time = turnaround_time;
        turnaround_time += (*processes)[i].burst_length;
        printf("%*d      ", 2, (*processes)[i].indetifier);
        printf("%*d      ", 2, (*processes)[i].burst_length);
        printf("%*d      ", 2, (*processes)[i].priority);
        printf("%*d      ", 2, wait_time);
        printf("%*d      \n", 2, turnaround_time);
        /* Increment totals for averages */
        total_wait_time += wait_time;
        total_turnaround_time += turnaround_time;
    }
    printf("Avg. Waiting Time    : %*.02lf\n", 2, ((double)total_wait_time / num_processes));
    printf("Avg. Turnaround Time : %*.02lf\n", 2, ((double)total_turnaround_time / num_processes));
    printf("-------------------------------\n");
    return 0;
}

int simulate_sjf(int num_processes, cpu_process **processes){
    
    return 0;
}

int simulate_priority(int num_processes, cpu_process **processes){
    
    return 0;
}

int simulate_rr(int num_processes, cpu_process **processes, int quantum){
    
    return 0;
}


int print_debug(int num_processes, cpu_process **processes, algorithm_type algorithm, int quantum, char *filename){
    int i;
    for(i = 0; i < num_processes; i++){
        printf("----- PROCESS %d INFORMATION -----\n", (i + 1));
        printf("Identifier: %d\n", (*processes)[i].indetifier);
        printf("Burst Length: %d\n", (*processes)[i].burst_length);
        printf("Priority: %d\n", (*processes)[i].priority);
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
    return 0;
}