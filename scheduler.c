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
        print_usage();
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
    
    /* Cleanup */
    int i;
    if(processes != NULL){
        /* Cleanup fields */
        for(i = 0; i < num_processes; i++){
            /* .identifier */
            processes->identifier = 0;            
            /* .burst_length */
            processes->burst_length = 0;            
            /* .priority */
            processes->priority = 0;           
            /* .waiting */
            processes->waiting = 0;
            /* .turnaround */
            processes->turnaround = 0;
        }
        free(processes);
        processes = NULL;
    }
    
    return 0;
}

void print_pre_process_information(algorithm_type algorithm, int quantum, char *filename){
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
}

void print_process_information(int num_processes, cpu_process **processes){
    int i;
    /* Arrival order */
    printf("Arrival Order: ");
    for(i = 0; i < num_processes - 1; i++){
        printf("%d, ", (*processes)[i].identifier);        
    }
    printf("%d\n", (*processes)[i].identifier);
    
    /* Process information */
    printf("Process Information: \n");
    for(i = 0; i < num_processes; i++){
        printf("%*d      ", 2, (*processes)[i].identifier);
        printf("%*d      ", 2, (*processes)[i].burst_length);
        printf("%*d\n", 2, (*processes)[i].priority);
    }
    
    /* Print running message */
    printf("-------------------------------\n");
    printf("Running...\n");
    printf("-------------------------------\n");
}

void print_usage(){
    printf("Usage : ./scheduler -s <algorithm-number> <filename> -q <quantum>\n");
}

void simulate_fcfs(int num_processes, cpu_process **processes){
    int wait_time = 0;
    int turnaround_time = 0;
    int total_wait_time = 0;
    int total_turnaround_time = 0;
    int i;
    
    for(i = 0; i < num_processes; i++){
        wait_time = turnaround_time;
        turnaround_time += (*processes)[i].burst_length;
        printf("%*d      ", 2, (*processes)[i].identifier);
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
}

void simulate_sjf(int num_processes, cpu_process **processes){
    int wait_time = 0;
    int turnaround_time = 0;
    int total_wait_time = 0;
    int total_turnaround_time = 0;
    int i, j;
	int shortest = 0;
    
	for(i = 0; i < num_processes; i++){
		/* Initialize shortest to a candidate value */
		for(j = num_processes; j >= 0; j--){
			if((*processes)[j].waiting == -1){
				shortest = j;
			}
		}
		/* Determine shortest remaining job */
		for(j = 0; j < num_processes; j++){
			if((*processes)[j].waiting == -1 && (*processes)[j].burst_length < (*processes)[shortest].burst_length){
				shortest = j;
			}
		}
		
		wait_time = turnaround_time;
		turnaround_time += (*processes)[shortest].burst_length;
		
		(*processes)[shortest].waiting = wait_time;
		(*processes)[shortest].turnaround = turnaround_time;
		
		total_wait_time += wait_time;
		total_turnaround_time += turnaround_time;
	}

    for(i = 0; i < num_processes; i++){
		//wait_time = turnaround_time;
		//turnaround_time += (*processes)[shortest].burst_length;
		printf("%*d      ", 2, (*processes)[i].identifier);
		printf("%*d      ", 2, (*processes)[i].burst_length);
		printf("%*d      ", 2, (*processes)[i].priority);
		printf("%*d      ", 2, (*processes)[i].waiting);
		printf("%*d      \n", 2, (*processes)[i].turnaround);
		/* Increment totals for averages */
		//total_wait_time += wait_time;
		//total_turnaround_time += turnaround_time;
	}

    printf("Avg. Waiting Time    : %*.02lf\n", 2, ((double)total_wait_time / num_processes));
    printf("Avg. Turnaround Time : %*.02lf\n", 2, ((double)total_turnaround_time / num_processes));
    printf("-------------------------------\n");
}

void simulate_priority(int num_processes, cpu_process **processes){
    int wait_time = 0;
    int turnaround_time = 0;
    int total_wait_time = 0;
    int total_turnaround_time = 0;
    int i, j;
	int priority = 0;
    
	for(i = 0; i < num_processes; i++){
		/* Initialize highest-priority to a candidate value */
		for(j = num_processes; j >= 0; j--){
			if((*processes)[j].waiting == -1){
				priority = j;
			}
		}
		/* Determine highest-priority remaining job */
		for(j = 0; j < num_processes; j++){
			if((*processes)[j].waiting == -1 && (*processes)[j].priority < (*processes)[priority].priority){
				priority = j;
			}
		}
		
		wait_time = turnaround_time;
		turnaround_time += (*processes)[priority].burst_length;
		
		(*processes)[priority].waiting = wait_time;
		(*processes)[priority].turnaround = turnaround_time;
		
		total_wait_time += wait_time;
		total_turnaround_time += turnaround_time;
	}

    for(i = 0; i < num_processes; i++){
		//wait_time = turnaround_time;
		//turnaround_time += (*processes)[priority].burst_length;
		printf("%*d      ", 2, (*processes)[i].identifier);
		printf("%*d      ", 2, (*processes)[i].burst_length);
		printf("%*d      ", 2, (*processes)[i].priority);
		printf("%*d      ", 2, (*processes)[i].waiting);
		printf("%*d      \n", 2, (*processes)[i].turnaround);
		/* Increment totals for averages */
		//total_wait_time += wait_time;
		//total_turnaround_time += turnaround_time;
	}

    printf("Avg. Waiting Time    : %*.02lf\n", 2, ((double)total_wait_time / num_processes));
    printf("Avg. Turnaround Time : %*.02lf\n", 2, ((double)total_turnaround_time / num_processes));
    printf("-------------------------------\n");
}

void simulate_rr(int num_processes, cpu_process **processes, int quantum){
    int wait_time = 0;
    int turnaround_time = 0;
    int total_wait_time = 0;
    int total_turnaround_time = 0;
	int max_subprocesses;
	int total_runtime = 0;
	int i;
	
	/* Determine max number of subprocesses possible */
	for(i = 0; i < num_processes; i++){
		total_runtime += (*processes)[i].burst_length;
	}
	max_subprocesses = (total_runtime / quantum) + 1;
	
	/* Make enough room in processes for all possible subprocesses */
	/* PROBLEM AREA */
    (*processes) = (cpu_process *)realloc((*processes), (sizeof(cpu_process) * (max_subprocesses)));
    if( NULL == (*processes) ) {
        fprintf(stderr, "Error: Failed to allocate memory! Critical failure on %d!", __LINE__);
        exit(-1);
    }
	
	for(i = 0; i < num_processes - 1; i++){
		if((*processes)[i].burst_length > quantum){
			
			(*processes)[num_processes].identifier = (*processes)[i].identifier;
			(*processes)[num_processes].burst_length = (*processes)[i].burst_length - quantum;
			(*processes)[num_processes].priority = (*processes)[i].priority;
			
			(*processes)[i].burst_length = quantum;
			
			num_processes++;
		}
		
		wait_time = turnaround_time;
		turnaround_time += (*processes)[i].burst_length;
		
		(*processes)[i].waiting = wait_time;
		(*processes)[i].turnaround = turnaround_time;
		
		total_wait_time += wait_time;
		total_turnaround_time += turnaround_time;
	}
	
	// Here we'll have to step through the whole array once more to get the Average
	// Wait/Turnaround times, because it's much more involved with Round Robin; not a simple average
	
}
