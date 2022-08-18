    AREA multiply, code, readonly
    ENTRY
    LDR r1, =0x6400
    LDR r2, =0x3200
    MUL r3, r1, r2
    NOP
    NOP
    END
