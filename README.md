# brainfuck-interpreter
*Small brainfuck interpreter written in C++*

**COMPILING**
Only requirements to compile the program are a C++11 compiler and Linux system.
`g++ std=c++11 main.cpp parser.cpp interpreter.cpp functions.cpp`

**USAGE**
binary [OPTIONS -pn] [FILE]

Options:
  -p : **p**lain text output. The interpreter output won't contain bold characters.
  -n : **n**o output. The interpreter will not output the content of the used cells at each instruction run.
  
Both *options* and *file* can be omitted.
If options are omitted the interpreter will run outputting the content of the used cells for each instruction run. The current evaluated cell will be written in bold.
If the file is omitted the interpreter will ask the user to input the code directly.

**CODE**
The interpreter follows brainfuck original standard.
It uses 8bit cells in an array of 30000 cells. Wrapping of the array and cells is implemented.

The following instructions are recognized:
> 	Move the pointer to the right
< 	Move the pointer to the left
+ 	Increment the memory cell under the pointer
- 	Decrement the memory cell under the pointer
. 	Output the character signified by the cell at the pointer
, 	Input a character and store it in the cell at the pointer
[ 	Jump past the matching ] if the cell under the pointer is 0
] 	Jump back to the matching [ if the cell under the pointer is nonzero

The following extra symbols are also recognized:
! # Consider the rest of the line as comment, do not parse
\   Consider the next character as comment
@   End parsing here

