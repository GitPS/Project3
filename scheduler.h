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

/*
 * CPU scheduling algorithms:
 *   FCFS - First Come, First Served
 *   SJF - Shortest-Job First
 *   PRIORITY - Priority
 *   RR - Round-Robin
 */
enum algorithm{
    FCFS,
    SJF,
    PRIORITY,
    RR
};
typedef enum algorithm algorithm;

/*
 * Structure to hold CPU job and scheduling information.
 */
struct cpu_process{
    int indetifier;
    int burst_length;
    int priority;
};
typedef struct cpu_process cpu_process;

/* Global Variables */

/* Function Declarations */

#endif