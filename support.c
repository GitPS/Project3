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

int parse_file_into_processes(char *filename, int *num_processes, cpu_process **processes){
    FILE *fd = NULL;
    char buffer[1024];
    char *fgets_rtn = NULL;
    
    /* Open File */
    fd = fopen(filename, "r");
    if(NULL == fd){
        fprintf(stderr, "Error: Cannot open the file %s for reading!\n", filename);
        return -1;
    }
    
    /* Read File */
    int i = -1;
    while(0 == feof(fd) && i != *num_processes){
        char * str_ptr  = NULL;
        fgets_rtn = fgets(buffer, 1024, fd);
        
        if( NULL == fgets_rtn) {
            break;
        }
        
        /* If this is the first line in the file it contains the process count */
        if(i == -1){
            str_ptr = strtok(buffer, " ");
            *num_processes = strtol(str_ptr, NULL, 10);
            /* Add correct amount of space in the processes array */
            (*processes) = (cpu_process *)realloc((*processes), (sizeof(cpu_process) * (*num_processes)));
            if( NULL == (*processes) ) {
                fprintf(stderr, "Error: Failed to allocate memory! Critical failure on %d!", __LINE__);
                exit(-1);
            }
        }    
        /* All other lines should be treated as a process */
        else{
            int j = 0;
            for( str_ptr = strtok(buffer, " ");
                NULL   != str_ptr && *str_ptr != '\n';
                str_ptr = strtok(NULL, " ") ) {
                int temp = strtol(str_ptr, NULL, 10);
                switch(j){
                    case 0:
                        (*processes)[i].indetifier = temp;
                        break;
                    case 1:
                        (*processes)[i].burst_length = temp;
                        break;
                    case 2:
                        (*processes)[i].priority = temp;
                        break;
                    default:
                        break;
                }
                j++;
            }
        }
        i++;
    }
    return 0;
}

int is_valid_int(char *str){
    int length = strlen(str);
    int i = 0;

    // Check for leading spaces.
    if(isspace(str[0])){
        i = 1;
        while(isspace(str[i])){
            i++;
        }
    }

    // Check for leading + or - signs.
    if(str[i] == '+' || str[i] == '-'){
            i++;
    }

    // At this point we have verified that the only remaning characters should be digits if this is an integer.
    for(i = i; i < length; i++){
        if(!isdigit(str[i])){
            // Is not an integer.
            return -1;          
        }
    }   
    // Is an integer.
    return 0;
}

