.code64

.section .text

.global kernelmain

kernelmain:
    hlt
    jmp kernelmain
