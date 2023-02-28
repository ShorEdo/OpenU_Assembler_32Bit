;errors for the commands and some.

X: .string "First String!"
label0: .data -1
label00: .data -1, 1, -2, 78, 90, 45328, -95743
label89: .string "H e l l o			. We like chars, so let's put some : 	"
.extern label1
XYZ123XYZ: .data 0	,   0  ,	 0  ,  0,   	 0, 	0 , 	0
.entry XYZ123XYZ
struct1: .struct 9,"ab"

;long white and words after.
                                                                                                 out of bound.

mov #1, #1
mov label0, #2
mov struct1.1, #3
mov r2, #4


add #1, #1
add label0, #2
add struct1.1, #3
add r2, #4

 
sub #1, #1
sub label0, #2
sub struct1.1, #3
sub r2, #4

