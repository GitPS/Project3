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

Thus, a complete command for this program might look like `./scheduler -s 4 tests/test1.txt -q 3` or `./scheduler -s 2 tests/test2.txt`.  Note that the order of the flags does not matter and the quantum, if specified, will be ignored for all scheduling algorithms except Round Robin.  If the user does not specify a proper command, the process will remind the user of the proper syntax and terminate.

__Test Cases__

`test1.txt`  This test is identical to the one given as an example in the Project Overview.  Its contents appear on page two and two examples of its use appear on page four.  This is a basic sanity check to ensure the results produced by the program are identical to the results on page four.

`test2.txt`  This test was built in order to demonstrate that Round Robin can handle many rounds without issue.  It is intended to be run with a low quantum (~3) so all processes are split across several rounds.  This test also demonstrates that the process identifiers do not need to be in any way consecutive or ordered.

`test3.txt`  This test contains 100 processes and was built as a stress test.  All tests have the same burst lengths and priorities, so this test also demonstrates the program's maintenance of arrival order in the event of a tie.

`test4.txt`  This test demonstrates a graceful failure and controlled termination of the program the in event of execution on a malformed test.  This test contains an alphabetic character where a digit is expected.

`test5.txt`  This test demonstrates an attempt at handling malformed data.  In the event of a missing value, the program assigns a default value of zero.  In this test, one of the processes is missing a priority level, and the program handles it as it would handle a process with priority zero.

`test6.txt`  This test demonstrates another successful attempt at handling malformed data.  If there is extra data beyond the required values on any given line, the program simply ignores it and continues reading the rest of the file without any problems.

__Examples__

TODO

__Known Bugs and Problem Areas__
* No bugs or problem areas are known at this time.

