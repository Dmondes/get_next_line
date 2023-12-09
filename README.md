# get_next_line
1. Function reads from fd and stores the line in the memory pointed
2. Buffer to read data, track position and size
3. Read the first line from the file (return value)
4. Check for newline chars, anything after is next iteration else take full nbytes size
5. Call the function again to get the next line
6. Malloc for the extracted line, free when it is appended to *line
7. Returns NULL once all lines are read/ error with function

New concepts: read(), static variable, open()
Function: works for both file and std input

Forbidden 
libft, lseek(), global variables

ssize_t read(int fildes, void *buf, size_t nbyte)
read nbytes of data
file descriptor fildes
buffer pointed by buf

returns number of bytes actually read is returned
end of file, 0 is returned
1 is returned, global variable errno is set to indicate error

Use linked list
