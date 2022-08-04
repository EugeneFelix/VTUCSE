      AREA ASCEND, CODE, READONLY
      ENTRY
      MOV R0, #0X00000003
NP    MOV R1, #03
      MOV R2, #0X40000000
NCMP  LDR R3 [R2]
      ADD R2, R2, #04
      LDR R4, [R2]
      CMP R3, R4
      BLT NOEXCHG
      STR R3, [R2]
      SUB R2, R2, #04
      STR R4, [R2]
      ADD R2, R2 #04
NOEX  SUB R1, R1, #01
      CMP R1, #0
      BNE NCMP
      SUB R0, R0, #01
      BNE NP
STOP  B STOP
      END
