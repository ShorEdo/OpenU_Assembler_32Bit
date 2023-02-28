;; First pass errors - mostly syntax validation, but also double definitions!

; label errors
LABEL: .data -0,5,6,7,2,6
CODELABEL: mov r0,r1
LOCALCODE: add r0,r1
LOCALDATA: .string "Some local data"
LABEL: .string "Same label twice!"
CODELABEL: .data "Again!"
.extern LOCALCODE
.extern LOCALDATA
.extern WHATEVEREXT
.extern LONGLONGLONGLONGLONGLONGLABELvery
.extern 1nvalidLabel
.extern Label@With4t
.extern
WHATEVEREXT: .string "Another definition!"
VERY_VERY_VERY_VERY_VERY_LONG_LABEL_DEFINITION_SO_ITS_ILLEGAL: .data 0
SOME*INVALID&CHARS%HERE: .data 5
2tartWithNumISILLEGAL: .data -6
ALLVALIDBUTLASTI$: .string "more invalid!"


; data and string errors
.string "No closing
.string No opening"
.string Not at all
.data ,5,6,-7
.data 5,,6,-7
.data 5,6,,-7
.data 5,6,-7,
.data 5 6 -7
.data 5 6 , -7
.data 5 , 6 -7,
.data 0.5
.data 5.9
.data -0.1
.data .5
; 2^23+1
.data 8388609
.data -8388609
.data -5,8388609,-8388609

; Operand count errors
mov
mov r0
mov r0,LABEL,#5
cmp
cmp LABEL
cmp #-0,MYLABEL,HERE
add
add r7
add #5,#6,#7
sub
sub LABEL
sub #4,LABEL,r0
lea
lea operand
clr
clr ope,rand
not
not r4, label
inc
inc r6,r5,r4
dec
dec lambdaX,XequalsY
jmp
jmp somewhere,around
bne
bne &realtivelyjump,notToday
jsr
jsr WeLikeJumpingAround,ButShouldBeError

prn
prn #48,#56
prn #4,#0,#9
rts hello
rts hello,goodbye




; More General syntax errors
mov $,#5
mov 6.7
mov 123
mov VERYVERYVERYVERYVERYLONGLABELWITH36C
mov $SomeLabel
.entry LONGLONGLONGLONGLONGLONGLONGLONGLABEL1234
.extern REALLYREALLYREALLYREALLYREALLYREALLYLONG

label : illegal
lable!:illegal
label: mov .string "Hello World!"
labell: mov .data "Hello World!"
label .data "Hello World!" mov r0,#5

string: .string "mystr"
entry: .data 12
extern: .data +5

TOOOOOOOOOOOOOOOOOOOOOOLOOOOOOOOOOOOOOOOOOONGGGGGGGGGGGGGGGGGGTOOOOOOPROCESSSSSSS
.extern HELLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLOO

