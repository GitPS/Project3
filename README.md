#### CS 441 Project 3 ####

__Authors__

Ryan Gittins and Phillip Sime

2013-11-12

__Summary__

This software ...

__Build__

To build this software, simply navigate to the directory containing the Makefile and all other included files on a unix-based machine or virtual machine. Type the command `make` into the terminal to trigger the build. This will cause the gcc build commands listed in the Makefile to execute, compiling the source code into an executable file.

__Usage__

To use this software, simply run the command `./scheduler` with a `-s` flag, followed by a single digit from one through four which selects the scheduling algorithm.  1 specifies "First-Come, First-Served", 2 specifies "Shortest Job First", 3 specifies "Priority", and 4 specifies "Round Robin".  If "Round Robin" is selected, then the user must also specify the desired quantum with a `-q` flag followed by the number.

The user must also input the filename and path (if applicable) of a textfile where the first line states the number of processes which are to be scheduled and each of the remaining lines specifies an identifier, burst length, and priority for that process, delimited by a single space.

Thus, a complete command for this program might look like `./scheduler -s 4 test1.txt -q 3` or `./scheduler -s 2 test2.txt`.  Note that the order of the flags does not matter and the quantum, if specified, will be ignored for all scheduling algorithms except Round Robin.  If the user does not specify a proper command, the process will remind the user of the proper syntax and terminate.

__Test Cases__

TODO

__Examples__

TODO

__Known Bugs and Problem Areas__
* No bugs or problem areas are known at this time.

