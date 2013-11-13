/*
 * Ryan Gittins and Phillip Sime
 *
 * CS441: Project 3
 * 
 * 2013-11-12
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
void print_pre_process_information(algorithm_type algorithm, int quantum, char *filename);

/*
 * Print process information including arrival order, process identifier, 
 * CPU burst length, and priority.
 *   num_processes : Number of processes that were read in from file
 *   processes : Array containing the CPU processes
 */
void print_process_information(int num_processes, cpu_process **processes);

/*
 * Print usage information for execution of program.
 */
void print_usage();

/*
 * Simulates the use of a First Come, First Served scheduling algorithm.
 *   num_processes : Number of processes that were read in from file
 *   processes : Array containing the CPU processes 
 */
void simulate_fcfs(int num_processes, cpu_process **processes);

/*
 * Simulates the use of a Shortest Job First scheduling algorithm.
 *   num_processes : Number of processes that were read in from file
 *   processes : Array containing the CPU processes 
 */
void simulate_sjf(int num_processes, cpu_process **processes);

/*
 * Simulates the use of a Priority scheduling algorithm.
 *   num_processes : Number of processes that were read in from file
 *   processes : Array containing the CPU processes 
 */
void simulate_priority(int num_processes, cpu_process **processes);

/*
 * Simulates the use of a Round-Robin scheduling algorithm.
 *   num_processes : Number of processes that were read in from file
 *   processes : Array containing the CPU processes 
 *   quantum : Quantum to use
 */
void simulate_rr(int num_processes, cpu_process **processes, int quantum);

/*
 * Prints a line containing process attributes and stats
 *   identifier : The process's unique identifier
 *   burst_length : The processes's cpu burst length
 *   priority : The processes's priority level
 *   waiting : The wait time of the process
 *   turnaround : The turnaround time of the process
 */
void print_process_stats(int identifier, int burst_length, int priority, int waiting, int turnaround);

/*
 * Prints the average waiting/turnaround times and the footer
 *   waiting : The group's average waiting time
 *   turnaround : The group's average turnaround time
 */
void print_averages_footer(double waiting, double turnaround);

#endif