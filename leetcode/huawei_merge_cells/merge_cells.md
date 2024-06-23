cd command
1. cd:  go to /home/user
2. cd -: go to the last directory
3. cd <absolute_directory>: start with /, go to the absolute directory
4. cd <relative_directory>: not start with /, go to the relative directory
5. multiple / in the path will be replaced by a single /
6. special directory . and .. are supported

Some restrictions on inputs
1. no first cd - command

Input:
first line is the number of commands n, 1 <= n <= 100
next n lines are the commands
length of the command is less than 10000
Each path exists!

Output:
1. start with /, and no / at the end.
2. No . and .. in the output, No sequential / in the output
Output the final directory after all the commands