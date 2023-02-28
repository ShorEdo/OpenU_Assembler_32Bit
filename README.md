# OpenU_Assembler_32Bit
Assembler for an imaginary 32-bit computer, this project is an assignment in a C programming course at the open university (20465).



##### Task Summery: Create an assembler for fictional assembly language defined by openu course.

##### Implementation Overview and general approach:

#### Objectives (Goals): ### 
1) Efficiency in memory: It was important to us allocate memory dynmically and make its size fit exact as required for each specific memory image output of the program.

2) Seperation of concern: we tried to split the program to indepent components that will be responsible for well defined tasks and that the sharing of data between files will be through some kind of encapsolution method such as state getters/setters and scoping global variable to be static so that they will be scoped to the single file that they belongs to.

3) Absctration of data structures and variable use to fit our needs by definning different typedef structs types enums and constants.

