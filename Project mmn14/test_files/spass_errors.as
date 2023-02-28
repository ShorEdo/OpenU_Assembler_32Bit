;second pass errors made by Edo Shor.

;just setting up some data.
.extern X
C: .struct 1,"0"
V: .data 1
B: .string "a"
.entry C

;no label? second pass will tell you.

lea abc, abc

.entry didntdeclaredasalabel

;double declaration of labels and extern entry mix up.

.entry C,X

.entry B,B

;wrong use of label and struct.

mov C.1,C

inc B.1


