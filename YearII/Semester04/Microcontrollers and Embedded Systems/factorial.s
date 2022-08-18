      AREA FACT, CODE, READONLY
      ENTRY
      MOV R0, #7
      MOV R1, R0
LOOP  SUBS R1, R1, #1
      CMP R1, #0
XSS   B XSS
      MUL R3, R1, R0
      MOV R0, R3
      BNE LOOP
      END
