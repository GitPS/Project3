/*
 * Ryan Gittins and Phillip Sime
 *
 * CS441: Project 3
 * 
 * 2013-11-02
 *
 */
#include "support.h"

int parse_command_line_arguments(int argc, char *argv[], char *filename, algorithm_type *algorithm, int *quantum){
    int i;    
    int filename_found = 1;
    int algorithm_found = 1;
    int quantum_found = 1;
    
    for(i = 1; i < argc; i++){
        /* Check for alrogithm type flag */
        if(strncmp("-s", argv[i], strlen("-s")) == 0){
            /* Check to see if there is another argument and assign that value to algorithm_type */
            if(i + 1 < argc){
               int algorithm_identifier = strtol(argv[i + 1], NULL, 10);
               // TODO Error handling for non-integer char.
               switch(algorithm_identifier){
                   case 1:
                       *algorithm = FCFS;
                       algorithm_found = 0;
                       break;
                   case 2:
                       *algorithm = SJF;
                       algorithm_found = 0;
                       break;
                   case 3:
                       *algorithm = PRIORITY;
                       algorithm_found = 0;
                       break;
                   case 4:
                       *algorithm = RR;
                       algorithm_found = 0;
                       break;
                   default:
                       *algorithm = NONE;
                       break;
                }
                /* Skip the next argument since we just used it */
                i++;                
            }
        }                
        /* Check for quantum type flag */
        else if(strncmp("-q", argv[i], strlen("-q")) == 0){
            /* Check to see if there is another argument and assign that value to quantum */
            if(i + 1 < argc){
                *quantum = strtol(argv[i + 1], NULL, 10);
                // TODO Error handling for non-integer char.
                quantum_found = 0;
                /* Skip the next argument since we just used it */
                i++;
            }
        }
        /* Treat everything else as a filename, but only assign 1 filename. */
        else if(filename_found != 0){
            strcpy(filename, argv[i]);
            filename_found = 0;
        }
    }
    
    /* Check that filename and algorithm were found */
    if(filename_found != 0 || algorithm_found != 0){
        return -1;
    }
    
    /* Check that quantum was found if using Round-Robin */
    if(*algorithm == RR){
        if(quantum_found != 0){
            return -1;
        }
    }
    /* If we aren't using Round-Robin, make sure that quantum is 0 */
    else{
        *quantum = 0;
    }
    
    return 0;
}