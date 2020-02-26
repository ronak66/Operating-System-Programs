# Scripts Descriptions

1. Write a program to find out time taken to execute getpid system call. Use time stamp counter.


2. Find out the priority of your running program. Modify the priority with nice command.


3. Write a program, call fork and print the parent and child process id.


4. Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.


5.  Write a program to create a Zombie state of the running program.

6. Write a program to create an orphan process.

7. Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).


8. Write a program to execute an executable program.
	* use some executable program
	* pass some input to an executable program. (for example execute an executable of $./a.out name)



9.  Write a program to execute ls -Rl by the following system calls
	* execl
	* execlp
	* execle
	* execv
	* execvp

10. Write a program to get maximum and minimum real time priority.




11. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).



12. Write a program to run a script at a specific time using a Daemon process.


