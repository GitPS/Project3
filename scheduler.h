/*
 * Ryan Gittins and Phillip Sime
 *
 * CS441: Project 3
 * 
 * 2013-11-02
 *
 */
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "support.h"

/* Structures */

/* Global Variables */

 /*
 * Max length of the filename
 */
int MAXFILENAME = 256;

/* Function Declarations */

/*
 * Print scheduling algorithm information, quantum, and filename of data file.
 *   algorithm : Enum containing the scheduling algorithm chosen
 *   qauntum : Quantum that was chosen or 0 if no quantum applies
 *   filename : File that data was read from
 * Returns 0 on success
 */
int print_pre_process_information(algorithm_type algorithm, int quantum, char *filename);

/*
 * Print process information including arrival order, process identifier, 
 * CPU burst length, and priority.
 *   num_processes : Number of processes that were read in from file
 *   processes : Array containing the CPU processes 
 * Returns 0 on success
 */
int print_process_information(int num_processes, cpu_process **processes);

/*
 * Simulates the use of a First Come, First Served scheduling algorithm.
 *   num_processes : Number of processes that were read in from file
 *   processes : Array containing the CPU processes 
 * Returns 0 on success
 */
int simulate_fcfs(int num_processes, cpu_process **processes);

/*
 * Simulates the use of a Shortest Job First scheduling algorithm.
 *   num_processes : Number of processes that were read in from file
 *   processes : Array containing the CPU processes 
 * Returns 0 on success
 */
int simulate_sjf(int num_processes, cpu_process **processes);

/*
 * Simulates the use of a Priority scheduling algorithm.
 *   num_processes : Number of processes that were read in from file
 *   processes : Array containing the CPU processes 
 * Returns 0 on success
 */
int simulate_priority(int num_processes, cpu_process **processes);

/*
 * Simulates the use of a Round-Robin scheduling algorithm.
 *   num_processes : Number of processes that were read in from file
 *   processes : Array containing the CPU processes 
 *   quantum : Quantum to use
 * Returns 0 on success
 */
int simulate_rr(int num_processes, cpu_process **processes, int quantum);

/*
 * Print debuf information.
 */
int print_debug(int num_processes, cpu_process **processes, algorithm_type algorithm, int quantum, char *filename);

#endif