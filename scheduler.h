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
 * Print debuf information.
 */
int print_debug(int num_processes, cpu_process **processes, algorithm_type algorithm, int quantum, char *filename);

#endif