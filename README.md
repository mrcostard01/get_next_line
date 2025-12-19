_This project has been created as part of the 42 curriculum by wipion_

This project is about creating a function (get_next_line),
that display the text from a file descriptor.

I've compiled this project using cc with the flags -Wall -Werror -Wextra.

for this project i used the man of read as a ressource, 
to get the library and understand how the read function works.

My algorithm is splited in 3 functions

- get_read :
a function that copy the whole text of a file descriptor

- get_one_line :
a function that copy caracters until it meet a '\n' or a null byte

- get_line_after :
a function that copy the line after

my main function is going to return the first line of the text that wasn't read.
The text is going to be contained in a static variable, because we want 
to copy the content from differents functions in the same file.
