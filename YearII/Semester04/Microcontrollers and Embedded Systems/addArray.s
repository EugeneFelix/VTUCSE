;;;; r1 has size of array.
;;;; r3 has address of first array element
;;;; r4, r5 contain 2 elemnts currently being compared

   AREA addArray, CODE, READONLY

START
     MOV R1, #0x3
     MOV R3, #0x40000000
     LDR R4, [R3]
LOOP
     ADD R3, R3, #4
     LDR R5, [R3]
     ADD R4, R4, R5
     SUB R1, R1, #1
     CMP R1, #0;
     BNE LOOP
     ;Memory stuff
     MOV R6, #0X4000001C
STOP B STOP
END
