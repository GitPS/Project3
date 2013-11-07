/*
 * Ryan Gittins and Phillip Sime
 *
 * CS441: Project 3
 * 
 * 2013-11-02
 *
 */
#ifndef SUPPORT_H
#define SUPPORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Defines */

#define TRUE  0
#define FALSE 1

/* Structures */

/*
 * CPU scheduling algorithms:
 *   FCFS - First Come, First Served
 *   SJF - Shortest-Job First
 *   PRIORITY - Priority
 *   RR - Round-Robin
 *   NONE - No algorithm assigned 
 */
enum algorithm_type{
    FCFS,
    SJF,
    PRIORITY,
    RR,
    NONE
};
typedef enum algorithm_type algorithm_type;

/*
 * Structure to hold CPU job and scheduling information.
 */
struct cpu_process{
    int identifier;
    int burst_length;
    int priority;
};
typedef struct cpu_process cpu_process;

/* Global Variables */

/* Function Declartions */

/*
 * Parses the command line arguments to determine the file name to read from, the algorithm
 * type, and the quantum (if applicable).
 *   file_name : Name of the file to read data from.
 *   algorithm : The algorithm that the CPU scheduler will use.
 *   quantum : The quantum to use if Round-Robin is chosen.  Otherwise 0.
 * Return 0 on success, -1 otherwise.
 */
int parse_command_line_arguments(int argc, char *argv[], char *filename, algorithm_type *algorithm, int *quantum);

/*
 * Parses the provided file to create an array of processes.
 *   file_name : Name of the file to read data from.
 *   num_processes : Size of processes array.
 *   processes : Array of processes.
 * Return 0 on success, -1 otherwise.
 */
int parse_file_into_processes(char *filename, int *num_processes, cpu_process **processes); 

/*
 * Takes an input string to check if it is a syntaticaly correct integer.
 *
 * Paramters:
 *   str : String to check
 *
 * Returns:
 *  0 if it is a valid integer.
 *  -1 if it is not a valid integer.
 *
 */
int is_valid_int(char *str);
#endif