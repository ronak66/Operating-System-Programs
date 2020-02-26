# File Managment Scripts Descriptions

1. Create the following types of a files using (i) shell command (ii) system call
	* soft link (symlink system call)
	* hard link (link system call)
	* FIFO (mkfifo Library Function or mknod system call)


2. Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.

3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call

4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.



5.  Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.

6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls

7. Write a program to copy file1 into file2 ($cp file1 file2).

8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.

9. Write a program to print the following information about a given file.
	* inode
	* number of hard links
	* uid 
	* gid 
	* size
	* block size
	* number of blocks
	* time of last access
	* time of last modification
	* time of last change



10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
	* check the return value of lseek
	* open the file with od and check the empty spaces in between the data.
	


11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
	* use dup
	* use dup2
	* use fcntl


12. Write a program to find out the opening mode of a file. Use fcntl.
	
13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).

14. Write a program to find the type of a file.
	* Input should be taken from command line.
	* program should be able to identify any type of a file.

15. Write a program to display the environmental variable of the user (use environ).

16. Write a program to perform mandatory locking.
	* Implement write lock
	* Implement read lock


17. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.

18. Write a program to perform Record locking.
	* Implement write lock
	* Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.


