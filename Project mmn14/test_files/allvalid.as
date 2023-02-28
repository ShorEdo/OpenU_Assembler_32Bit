; All the valid commands/instruction by the booklet.
; to run correectly change in globals the max line of instructions to at least 2000.
; Some data at start..
X: .string "First String!"
label0: .data -1
label00: .data -1, 1, -2, 78, 90, 45328, -95743
label89: .string "H e l l o			. We like chars, so let's put some : 	"
.extern label1
XYZ123XYZ: .data 0	,   0  ,	 0  ,  0,   	 0, 	0 , 	0
.entry XYZ123XYZ
struct1: .struct 9,"ab"

; mov 0123,123
mov #0, label0
mov #-1, r0
mov #9 ,struct1.1
mov r0, r1
mov r0, label0
mov r0, struct1.1
mov label0, label1
mov label0, r0
mov label0, struct1.1
mov struct1.1, label0
mov struct1.2 , r2
mov struct1.1, struct1.1

; cmp 0123,0123
cmp #0, label0
cmp #-1, r0
cmp #9, #-298
cmp #3, struct1.1
cmp r0, r1
cmp r0, label0
cmp r0, #-928
cmp r0, struct1.1
cmp label0, label1
cmp label0, r0
cmp label0, #129475
cmp label0, struct1.1
cmp struct1.1, label0
cmp struct1.1, r0
cmp struct1.1, #1
cmp struct1.1, struct1.2

; add 0123,123
add #3957, label00
add #-1, r0
add #199 , struct1.1
add r2, r3
add r7, label89
add r3, struct1.2
add X1234YZASFJKFDSA524bsdasfjdgdaf, label11
add label0, r6
add label0, struct1.2
add struct1.1, label0
add struct1.1, r1
add struct1.1, struct1.1

; sub 0123,123
sub #3957, label00
sub #-1, r0
sub #3, struct1.1
sub r2, r3
sub r7, label89
sub r3, struct1.1
sub fasdiu3245dghfgshdsf78dhkj12345, label11
sub label0, r6
sub label0, struct1.2
sub struct1.1, label00
sub struct1.1, r0
sub struct1.1, struct1.2

; lea 12,123
lea label0, fasdiu3245dghfgshdsf78dhkj12345
lea label11, r4
lea label0, struct1.2
lea struct1.1 ,label0
lea struct1.1 , r4
lea struct1.1 , struct1.2

; clr 123
clr r5
clr XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
clr struct1.2

; not 123
not r6
not X
not struct1.1

; inc 123
inc r7
inc X1234YZASFJKFDSA524bsdasfjdgdaf
inc struct1.1

; dec 123
dec r0
dec fasdiu3245dghfgshdsf78dhkj12345
dec struct1.1

; jmp 123
jmp label0
jmp r0
jmp struct1.1

; Put some data here:

ALPHABETAGAMA123: .string "ALPHABETAGAMA123"
.entry ALPHABETAGAMA123

; bne 123
CCC1: bne X
bne CCC1
bne r1
bne struct1.1

; jsr 123
C5: jsr X
jsr C5
jsr r3
jsr struct1.1

; get 123
get r2
get label0
get struct1.1

; prn 0123
prn r5
prn #-32
prn mychars
prn struct1.1

rts
rts

hlt

label11: .data 9
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX: .string " "
.entry XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
X1234YZASFJKFDSA524bsdasfjdgdaf: .data 5
.entry X1234YZASFJKFDSA524bsdasfjdgdaf
label01: .data -000000, +000000, +000001, -000004
mychars: .string "mychars!@#$%^&#*() 	\/+-=_"

.extern fasdiu3245dghfgshdsf78dhkj12345
;vvvvvvvvvvvvvvvvveeeeeeeeeeeeeeeeerrrrrrrrrrrrrrrryyyyyyyyyyyyyylongcomment Hello World.
