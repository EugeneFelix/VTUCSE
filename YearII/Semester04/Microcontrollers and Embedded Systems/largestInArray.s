;;;; r0 is used for loading addresses
;;;; r1 is used to store result
;;;; r2 and r3 hold values tp be compared.
;;;; r5 holds count
    AREA LRG, CODE, READONLY
      ENTRY
      MOV R5, #5
      LDR R0, A
      LDR R2, [R0]
NEXT  ADD R0, #4
      LDR R3, [R0]
      CMP R2, R3
      BHS LARGE
      MOV R2, R3
LARGE SUBS R5, #1
      BNE NEXT
      LDR R1, RES
      STR R2, [R1]
XSS   B XSS
      ;; Memory stuff
A     DCD 0X40000000
RES   DCD 0X40000020
      END
