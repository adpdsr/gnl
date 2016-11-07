#get_next_line
  
42 school project (Paris, France)
  
##Synopsis
  
int		get_next_line(int const fd, char **line)  
  
get_next_line() function reads a line from one or multiple given filedescriptors. The newline delimiter character is included as part of the line, unless the end of the file is reached. The result is saved through the string's pointer given in parameters. The function return 1 while reading, 0 if the file is ended, -1 in an error occured.
