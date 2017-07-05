# brainfuck-interpreter
*Small brainfuck interpreter written in C++*


## COMPILING
Only requirements to compile the program are a C++11 compiler and Linux system.
`g++ std=c++11 main.cpp parser.cpp interpreter.cpp functions.cpp`


## USAGE
binary [OPTIONS -pn] [FILE]

Options:
-p : Plain text output. The interpreter output won't contain bold characters
-n : No output. The interpreter will not output the content of the used cells at each instruction run.

Both *options* and *file* can be omitted.

If options are omitted the interpreter will run outputting the content of the used cells for each instruction run. The current evaluated cell will be written in bold.

If the file is omitted the interpreter will ask the user to input the code directly.

To stop the program at input (for example in cat programs `,[.,]`) the user can type `!@`. If need to input `!@` the user can type `\!@`.


## CODE
The interpreter follows brainfuck original standard.

| Symbol | Instruction |
|:---:|:---|
| > |	Move to cell on the right (pointer ++) |
| < |	Move to cell on the left (pointer --) |
| + |	Increment the value of the current cell |
| - |	Decrement the value of the current cell |
| . |	Output the character signified by the current cell |
| , |	Input a character and store it in the current cell |
| [ |	Jump past the matching ] if the current cell is 0 |
| ] |	Jump back to the matching [ if the current cell is not zero |

It uses 8bit cells in an array of 30000 cells. Wrapping of the array and cells is implemented.

The following extra symbols are also recognized:

| Symbol | Instruction |
|:---:|:---|
| ! or # | Consider the line as comment |
| @ | Terminate execution here |
