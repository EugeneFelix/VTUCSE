      AREA COUNTZO, CODE, READONLY
      ENTRY
      LDR R0, MEMORY
      LDR R1, [RO]
      MOV R4, #32
ROTAT RORS R1, #1
      BCS ONES
      ADD R3, R3, #1
      B NEXT
ONES  ADD R2, R2, #1
NEXT  ADD R4, R4, #-1
      CMP R4, #0
      BNE ROTAT
      ADD R0, R0, #4
      STRB R2, [R0]
      ADD R0, R0, #4
      STRB R3, [R0] 
      END
