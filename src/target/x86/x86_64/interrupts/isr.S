.code64

.include "target/x86/common/boot.inc"

.section .text

.global interrupt_handler

/*
** Prepare dispatcher
*/

interrupt_handler:
    push %rbp
    push %rdi
    push %rsi
    push %rbx
    push %rdx
    push %rcx
    push %rax
    push %r8
    push %r9
    push %r10
    push %r11
    push %r12
    push %r13
    push %r14
    push %r15

    /* Get the particular handler */
    movq  32(%rsp), %rsi # int nbr
    imulq $0x4, %rsi
    movq  $isr_data_handler, %rax
    addq  %rsi, %rax

    mov %ds, %rax
    pushq %rax
    mov %es, %rax
    pushq %rax
    mov %fs, %rax
    pushq %rax
    mov %gs, %rax
    pushq %rax

    movw $KERNEL_DATA_SELECTOR, %ax
    movw %ax, %ds
    movw %ax, %es
    movw %ax, %fs
    movw %ax, %gs

    pushq %rsp

    cmpq $0x0, (%rax)
    jne .particular_handler

    call interrupt_dispatch

.back_to_isr:

    addq $0x8, %rsp

    popq %rax
    mov %ax, %gs
    popq %rax
    mov %ax, %fs
    popq %rax
    mov %ax, %es
    popq %rax
    mov %ax, %ds

    pop %r15
    pop %r14
    pop %r13
    pop %r12
    pop %r11
    pop %r10
    pop %r9
    pop %r8
    pop %rax
    pop %rcx
    pop %rdx
    pop %rbx
    pop %rsi
    pop %rdi
    pop %rbp

    addq $0x10, %rsp

    iretq

.particular_handler:
    call *(%rax)
    jmp .back_to_isr

/*
** Particular handler registered here
*/

.section .data

.global isr_data_handler

isr_data_handler:
.rept 256
    .4byte 0x0
.endr

.section .text

.global isr_register_handler

/* void isr_register_handler(int nbr, void *func) */
isr_register_handler:
    pushq %rcx

    movq  $isr_data_handler, %rcx
    imulq $0x8, %rdi
    addq  %rcx, %rdi
    movq  %rsi, (%rcx)

    popq %rcx
    ret

.global isr_unregister_handler

/* void isr_unregister_handler(int nbr) */
isr_unregister_handler:
    pushq %rcx

    movq  $isr_data_handler, %rcx
    imulq $0x8, %rdi
    addq  %rcx, %rdi
    movq $0x0, (%rcx)

    popq %rcx
    ret

/*
** GAS apparently not allow us to do .rept/.endr with an assigned increment
** So Yes, it's ugly
*/

.section .text

.global isr

isr:

.int_gate_0:
    pushq $0x0
    pushq $0
    jmp interrupt_handler

.int_gate_1:
    pushq $0x0
    pushq $1
    jmp interrupt_handler

.int_gate_2:
    pushq $0x0
    pushq $2
    jmp interrupt_handler

.int_gate_3:
    pushq $0x0
    pushq $3
    jmp interrupt_handler

.int_gate_4:
    pushq $0x0
    pushq $4
    jmp interrupt_handler

.int_gate_5:
    pushq $0x0
    pushq $5
    jmp interrupt_handler

.int_gate_6:
    pushq $0x0
    pushq $6
    jmp interrupt_handler

.int_gate_7:
    pushq $0x0
    pushq $7
    jmp interrupt_handler

.int_gate_8:
    nop
    nop
    pushq $8
    jmp interrupt_handler

.int_gate_9:
    pushq $0x0
    pushq $9
    jmp interrupt_handler

.int_gate_10:
    nop
    nop
    pushq $10
    jmp interrupt_handler

.int_gate_11:
    nop
    nop
    pushq $11
    jmp interrupt_handler

.int_gate_12:
    nop
    nop
    pushq $12
    jmp interrupt_handler

.int_gate_13:
    nop
    nop
    pushq $13
    jmp interrupt_handler

.int_gate_14:
    nop
    nop
    pushq $14
    jmp interrupt_handler

.int_gate_15:
    pushq $0x0
    pushq $15
    jmp interrupt_handler

.int_gate_16:
    pushq $0x0
    pushq $16
    jmp interrupt_handler

.int_gate_17:
    nop
    nop
    pushq $17
    jmp interrupt_handler

.int_gate_18:
    pushq $0x0
    pushq $18
    jmp interrupt_handler

.int_gate_19:
    pushq $0x0
    pushq $19
    jmp interrupt_handler

.int_gate_20:
    pushq $0x0
    pushq $20
    jmp interrupt_handler

.int_gate_21:
    pushq $0x0
    pushq $21
    jmp interrupt_handler

.int_gate_22:
    pushq $0x0
    pushq $22
    jmp interrupt_handler

.int_gate_23:
    pushq $0x0
    pushq $23
    jmp interrupt_handler

.int_gate_24:
    pushq $0x0
    pushq $24
    jmp interrupt_handler

.int_gate_25:
    pushq $0x0
    pushq $25
    jmp interrupt_handler

.int_gate_26:
    pushq $0x0
    pushq $26
    jmp interrupt_handler

.int_gate_27:
    pushq $0x0
    pushq $27
    jmp interrupt_handler

.int_gate_28:
    pushq $0x0
    pushq $28
    jmp interrupt_handler

.int_gate_29:
    pushq $0x0
    pushq $29
    jmp interrupt_handler

.int_gate_30:
    pushq $0x0
    pushq $30
    jmp interrupt_handler

.int_gate_31:
    pushq $0x0
    pushq $31
    jmp interrupt_handler

.int_gate_32:
    pushq $0x0
    pushq $32
    jmp interrupt_handler

.int_gate_33:
    pushq $0x0
    pushq $33
    jmp interrupt_handler

.int_gate_34:
    pushq $0x0
    pushq $34
    jmp interrupt_handler

.int_gate_35:
    pushq $0x0
    pushq $35
    jmp interrupt_handler

.int_gate_36:
    pushq $0x0
    pushq $36
    jmp interrupt_handler

.int_gate_37:
    pushq $0x0
    pushq $37
    jmp interrupt_handler

.int_gate_38:
    pushq $0x0
    pushq $38
    jmp interrupt_handler

.int_gate_39:
    pushq $0x0
    pushq $39
    jmp interrupt_handler

.int_gate_40:
    pushq $0x0
    pushq $40
    jmp interrupt_handler

.int_gate_41:
    pushq $0x0
    pushq $41
    jmp interrupt_handler

.int_gate_42:
    pushq $0x0
    pushq $42
    jmp interrupt_handler

.int_gate_43:
    pushq $0x0
    pushq $43
    jmp interrupt_handler

.int_gate_44:
    pushq $0x0
    pushq $44
    jmp interrupt_handler

.int_gate_45:
    pushq $0x0
    pushq $45
    jmp interrupt_handler

.int_gate_46:
    pushq $0x0
    pushq $46
    jmp interrupt_handler

.int_gate_47:
    pushq $0x0
    pushq $47
    jmp interrupt_handler

.int_gate_48:
    pushq $0x0
    pushq $48
    jmp interrupt_handler

.int_gate_49:
    pushq $0x0
    pushq $49
    jmp interrupt_handler

.int_gate_50:
    pushq $0x0
    pushq $50
    jmp interrupt_handler

.int_gate_51:
    pushq $0x0
    pushq $51
    jmp interrupt_handler

.int_gate_52:
    pushq $0x0
    pushq $52
    jmp interrupt_handler

.int_gate_53:
    pushq $0x0
    pushq $53
    jmp interrupt_handler

.int_gate_54:
    pushq $0x0
    pushq $54
    jmp interrupt_handler

.int_gate_55:
    pushq $0x0
    pushq $55
    jmp interrupt_handler

.int_gate_56:
    pushq $0x0
    pushq $56
    jmp interrupt_handler

.int_gate_57:
    pushq $0x0
    pushq $57
    jmp interrupt_handler

.int_gate_58:
    pushq $0x0
    pushq $58
    jmp interrupt_handler

.int_gate_59:
    pushq $0x0
    pushq $59
    jmp interrupt_handler

.int_gate_60:
    pushq $0x0
    pushq $60
    jmp interrupt_handler

.int_gate_61:
    pushq $0x0
    pushq $61
    jmp interrupt_handler

.int_gate_62:
    pushq $0x0
    pushq $62
    jmp interrupt_handler

.int_gate_63:
    pushq $0x0
    pushq $63
    jmp interrupt_handler

.int_gate_64:
    pushq $0x0
    pushq $64
    jmp interrupt_handler

.int_gate_65:
    pushq $0x0
    pushq $65
    jmp interrupt_handler

.int_gate_66:
    pushq $0x0
    pushq $66
    jmp interrupt_handler

.int_gate_67:
    pushq $0x0
    pushq $67
    jmp interrupt_handler

.int_gate_68:
    pushq $0x0
    pushq $68
    jmp interrupt_handler

.int_gate_69:
    pushq $0x0
    pushq $69
    jmp interrupt_handler

.int_gate_70:
    pushq $0x0
    pushq $70
    jmp interrupt_handler

.int_gate_71:
    pushq $0x0
    pushq $71
    jmp interrupt_handler

.int_gate_72:
    pushq $0x0
    pushq $72
    jmp interrupt_handler

.int_gate_73:
    pushq $0x0
    pushq $73
    jmp interrupt_handler

.int_gate_74:
    pushq $0x0
    pushq $74
    jmp interrupt_handler

.int_gate_75:
    pushq $0x0
    pushq $75
    jmp interrupt_handler

.int_gate_76:
    pushq $0x0
    pushq $76
    jmp interrupt_handler

.int_gate_77:
    pushq $0x0
    pushq $77
    jmp interrupt_handler

.int_gate_78:
    pushq $0x0
    pushq $78
    jmp interrupt_handler

.int_gate_79:
    pushq $0x0
    pushq $79
    jmp interrupt_handler

.int_gate_80:
    pushq $0x0
    pushq $80
    jmp interrupt_handler

.int_gate_81:
    pushq $0x0
    pushq $81
    jmp interrupt_handler

.int_gate_82:
    pushq $0x0
    pushq $82
    jmp interrupt_handler

.int_gate_83:
    pushq $0x0
    pushq $83
    jmp interrupt_handler

.int_gate_84:
    pushq $0x0
    pushq $84
    jmp interrupt_handler

.int_gate_85:
    pushq $0x0
    pushq $85
    jmp interrupt_handler

.int_gate_86:
    pushq $0x0
    pushq $86
    jmp interrupt_handler

.int_gate_87:
    pushq $0x0
    pushq $87
    jmp interrupt_handler

.int_gate_88:
    pushq $0x0
    pushq $88
    jmp interrupt_handler

.int_gate_89:
    pushq $0x0
    pushq $89
    jmp interrupt_handler

.int_gate_90:
    pushq $0x0
    pushq $90
    jmp interrupt_handler

.int_gate_91:
    pushq $0x0
    pushq $91
    jmp interrupt_handler

.int_gate_92:
    pushq $0x0
    pushq $92
    jmp interrupt_handler

.int_gate_93:
    pushq $0x0
    pushq $93
    jmp interrupt_handler

.int_gate_94:
    pushq $0x0
    pushq $94
    jmp interrupt_handler

.int_gate_95:
    pushq $0x0
    pushq $95
    jmp interrupt_handler

.int_gate_96:
    pushq $0x0
    pushq $96
    jmp interrupt_handler

.int_gate_97:
    pushq $0x0
    pushq $97
    jmp interrupt_handler

.int_gate_98:
    pushq $0x0
    pushq $98
    jmp interrupt_handler

.int_gate_99:
    pushq $0x0
    pushq $99
    jmp interrupt_handler

.int_gate_100:
    pushq $0x0
    pushq $100
    jmp interrupt_handler

.int_gate_101:
    pushq $0x0
    pushq $101
    jmp interrupt_handler

.int_gate_102:
    pushq $0x0
    pushq $102
    jmp interrupt_handler

.int_gate_103:
    pushq $0x0
    pushq $103
    jmp interrupt_handler

.int_gate_104:
    pushq $0x0
    pushq $104
    jmp interrupt_handler

.int_gate_105:
    pushq $0x0
    pushq $105
    jmp interrupt_handler

.int_gate_106:
    pushq $0x0
    pushq $106
    jmp interrupt_handler

.int_gate_107:
    pushq $0x0
    pushq $107
    jmp interrupt_handler

.int_gate_108:
    pushq $0x0
    pushq $108
    jmp interrupt_handler

.int_gate_109:
    pushq $0x0
    pushq $109
    jmp interrupt_handler

.int_gate_110:
    pushq $0x0
    pushq $110
    jmp interrupt_handler

.int_gate_111:
    pushq $0x0
    pushq $111
    jmp interrupt_handler

.int_gate_112:
    pushq $0x0
    pushq $112
    jmp interrupt_handler

.int_gate_113:
    pushq $0x0
    pushq $113
    jmp interrupt_handler

.int_gate_114:
    pushq $0x0
    pushq $114
    jmp interrupt_handler

.int_gate_115:
    pushq $0x0
    pushq $115
    jmp interrupt_handler

.int_gate_116:
    pushq $0x0
    pushq $116
    jmp interrupt_handler

.int_gate_117:
    pushq $0x0
    pushq $117
    jmp interrupt_handler

.int_gate_118:
    pushq $0x0
    pushq $118
    jmp interrupt_handler

.int_gate_119:
    pushq $0x0
    pushq $119
    jmp interrupt_handler

.int_gate_120:
    pushq $0x0
    pushq $120
    jmp interrupt_handler

.int_gate_121:
    pushq $0x0
    pushq $121
    jmp interrupt_handler

.int_gate_122:
    pushq $0x0
    pushq $122
    jmp interrupt_handler

.int_gate_123:
    pushq $0x0
    pushq $123
    jmp interrupt_handler

.int_gate_124:
    pushq $0x0
    pushq $124
    jmp interrupt_handler

.int_gate_125:
    pushq $0x0
    pushq $125
    jmp interrupt_handler

.int_gate_126:
    pushq $0x0
    pushq $126
    jmp interrupt_handler

.int_gate_127:
    pushq $0x0
    pushq $127
    jmp interrupt_handler

.int_gate_128:
    pushq $0x0
    pushq $128
    jmp interrupt_handler

.int_gate_129:
    pushq $0x0
    pushq $129
    jmp interrupt_handler

.int_gate_130:
    pushq $0x0
    pushq $130
    jmp interrupt_handler

.int_gate_131:
    pushq $0x0
    pushq $131
    jmp interrupt_handler

.int_gate_132:
    pushq $0x0
    pushq $132
    jmp interrupt_handler

.int_gate_133:
    pushq $0x0
    pushq $133
    jmp interrupt_handler

.int_gate_134:
    pushq $0x0
    pushq $134
    jmp interrupt_handler

.int_gate_135:
    pushq $0x0
    pushq $135
    jmp interrupt_handler

.int_gate_136:
    pushq $0x0
    pushq $136
    jmp interrupt_handler

.int_gate_137:
    pushq $0x0
    pushq $137
    jmp interrupt_handler

.int_gate_138:
    pushq $0x0
    pushq $138
    jmp interrupt_handler

.int_gate_139:
    pushq $0x0
    pushq $139
    jmp interrupt_handler

.int_gate_140:
    pushq $0x0
    pushq $140
    jmp interrupt_handler

.int_gate_141:
    pushq $0x0
    pushq $141
    jmp interrupt_handler

.int_gate_142:
    pushq $0x0
    pushq $142
    jmp interrupt_handler

.int_gate_143:
    pushq $0x0
    pushq $143
    jmp interrupt_handler

.int_gate_144:
    pushq $0x0
    pushq $144
    jmp interrupt_handler

.int_gate_145:
    pushq $0x0
    pushq $145
    jmp interrupt_handler

.int_gate_146:
    pushq $0x0
    pushq $146
    jmp interrupt_handler

.int_gate_147:
    pushq $0x0
    pushq $147
    jmp interrupt_handler

.int_gate_148:
    pushq $0x0
    pushq $148
    jmp interrupt_handler

.int_gate_149:
    pushq $0x0
    pushq $149
    jmp interrupt_handler

.int_gate_150:
    pushq $0x0
    pushq $150
    jmp interrupt_handler

.int_gate_151:
    pushq $0x0
    pushq $151
    jmp interrupt_handler

.int_gate_152:
    pushq $0x0
    pushq $152
    jmp interrupt_handler

.int_gate_153:
    pushq $0x0
    pushq $153
    jmp interrupt_handler

.int_gate_154:
    pushq $0x0
    pushq $154
    jmp interrupt_handler

.int_gate_155:
    pushq $0x0
    pushq $155
    jmp interrupt_handler

.int_gate_156:
    pushq $0x0
    pushq $156
    jmp interrupt_handler

.int_gate_157:
    pushq $0x0
    pushq $157
    jmp interrupt_handler

.int_gate_158:
    pushq $0x0
    pushq $158
    jmp interrupt_handler

.int_gate_159:
    pushq $0x0
    pushq $159
    jmp interrupt_handler

.int_gate_160:
    pushq $0x0
    pushq $160
    jmp interrupt_handler

.int_gate_161:
    pushq $0x0
    pushq $161
    jmp interrupt_handler

.int_gate_162:
    pushq $0x0
    pushq $162
    jmp interrupt_handler

.int_gate_163:
    pushq $0x0
    pushq $163
    jmp interrupt_handler

.int_gate_164:
    pushq $0x0
    pushq $164
    jmp interrupt_handler

.int_gate_165:
    pushq $0x0
    pushq $165
    jmp interrupt_handler

.int_gate_166:
    pushq $0x0
    pushq $166
    jmp interrupt_handler

.int_gate_167:
    pushq $0x0
    pushq $167
    jmp interrupt_handler

.int_gate_168:
    pushq $0x0
    pushq $168
    jmp interrupt_handler

.int_gate_169:
    pushq $0x0
    pushq $169
    jmp interrupt_handler

.int_gate_170:
    pushq $0x0
    pushq $170
    jmp interrupt_handler

.int_gate_171:
    pushq $0x0
    pushq $171
    jmp interrupt_handler

.int_gate_172:
    pushq $0x0
    pushq $172
    jmp interrupt_handler

.int_gate_173:
    pushq $0x0
    pushq $173
    jmp interrupt_handler

.int_gate_174:
    pushq $0x0
    pushq $174
    jmp interrupt_handler

.int_gate_175:
    pushq $0x0
    pushq $175
    jmp interrupt_handler

.int_gate_176:
    pushq $0x0
    pushq $176
    jmp interrupt_handler

.int_gate_177:
    pushq $0x0
    pushq $177
    jmp interrupt_handler

.int_gate_178:
    pushq $0x0
    pushq $178
    jmp interrupt_handler

.int_gate_179:
    pushq $0x0
    pushq $179
    jmp interrupt_handler

.int_gate_180:
    pushq $0x0
    pushq $180
    jmp interrupt_handler

.int_gate_181:
    pushq $0x0
    pushq $181
    jmp interrupt_handler

.int_gate_182:
    pushq $0x0
    pushq $182
    jmp interrupt_handler

.int_gate_183:
    pushq $0x0
    pushq $183
    jmp interrupt_handler

.int_gate_184:
    pushq $0x0
    pushq $184
    jmp interrupt_handler

.int_gate_185:
    pushq $0x0
    pushq $185
    jmp interrupt_handler

.int_gate_186:
    pushq $0x0
    pushq $186
    jmp interrupt_handler

.int_gate_187:
    pushq $0x0
    pushq $187
    jmp interrupt_handler

.int_gate_188:
    pushq $0x0
    pushq $188
    jmp interrupt_handler

.int_gate_189:
    pushq $0x0
    pushq $189
    jmp interrupt_handler

.int_gate_190:
    pushq $0x0
    pushq $190
    jmp interrupt_handler

.int_gate_191:
    pushq $0x0
    pushq $191
    jmp interrupt_handler

.int_gate_192:
    pushq $0x0
    pushq $192
    jmp interrupt_handler

.int_gate_193:
    pushq $0x0
    pushq $193
    jmp interrupt_handler

.int_gate_194:
    pushq $0x0
    pushq $194
    jmp interrupt_handler

.int_gate_195:
    pushq $0x0
    pushq $195
    jmp interrupt_handler

.int_gate_196:
    pushq $0x0
    pushq $196
    jmp interrupt_handler

.int_gate_197:
    pushq $0x0
    pushq $197
    jmp interrupt_handler

.int_gate_198:
    pushq $0x0
    pushq $198
    jmp interrupt_handler

.int_gate_199:
    pushq $0x0
    pushq $199
    jmp interrupt_handler

.int_gate_200:
    pushq $0x0
    pushq $200
    jmp interrupt_handler

.int_gate_201:
    pushq $0x0
    pushq $201
    jmp interrupt_handler

.int_gate_202:
    pushq $0x0
    pushq $202
    jmp interrupt_handler

.int_gate_203:
    pushq $0x0
    pushq $203
    jmp interrupt_handler

.int_gate_204:
    pushq $0x0
    pushq $204
    jmp interrupt_handler

.int_gate_205:
    pushq $0x0
    pushq $205
    jmp interrupt_handler

.int_gate_206:
    pushq $0x0
    pushq $206
    jmp interrupt_handler

.int_gate_207:
    pushq $0x0
    pushq $207
    jmp interrupt_handler

.int_gate_208:
    pushq $0x0
    pushq $208
    jmp interrupt_handler

.int_gate_209:
    pushq $0x0
    pushq $209
    jmp interrupt_handler

.int_gate_210:
    pushq $0x0
    pushq $210
    jmp interrupt_handler

.int_gate_211:
    pushq $0x0
    pushq $211
    jmp interrupt_handler

.int_gate_212:
    pushq $0x0
    pushq $212
    jmp interrupt_handler

.int_gate_213:
    pushq $0x0
    pushq $213
    jmp interrupt_handler

.int_gate_214:
    pushq $0x0
    pushq $214
    jmp interrupt_handler

.int_gate_215:
    pushq $0x0
    pushq $215
    jmp interrupt_handler

.int_gate_216:
    pushq $0x0
    pushq $216
    jmp interrupt_handler

.int_gate_217:
    pushq $0x0
    pushq $217
    jmp interrupt_handler

.int_gate_218:
    pushq $0x0
    pushq $218
    jmp interrupt_handler

.int_gate_219:
    pushq $0x0
    pushq $219
    jmp interrupt_handler

.int_gate_220:
    pushq $0x0
    pushq $220
    jmp interrupt_handler

.int_gate_221:
    pushq $0x0
    pushq $221
    jmp interrupt_handler

.int_gate_222:
    pushq $0x0
    pushq $222
    jmp interrupt_handler

.int_gate_223:
    pushq $0x0
    pushq $223
    jmp interrupt_handler

.int_gate_224:
    pushq $0x0
    pushq $224
    jmp interrupt_handler

.int_gate_225:
    pushq $0x0
    pushq $225
    jmp interrupt_handler

.int_gate_226:
    pushq $0x0
    pushq $226
    jmp interrupt_handler

.int_gate_227:
    pushq $0x0
    pushq $227
    jmp interrupt_handler

.int_gate_228:
    pushq $0x0
    pushq $228
    jmp interrupt_handler

.int_gate_229:
    pushq $0x0
    pushq $229
    jmp interrupt_handler

.int_gate_230:
    pushq $0x0
    pushq $230
    jmp interrupt_handler

.int_gate_231:
    pushq $0x0
    pushq $231
    jmp interrupt_handler

.int_gate_232:
    pushq $0x0
    pushq $232
    jmp interrupt_handler

.int_gate_233:
    pushq $0x0
    pushq $233
    jmp interrupt_handler

.int_gate_234:
    pushq $0x0
    pushq $234
    jmp interrupt_handler

.int_gate_235:
    pushq $0x0
    pushq $235
    jmp interrupt_handler

.int_gate_236:
    pushq $0x0
    pushq $236
    jmp interrupt_handler

.int_gate_237:
    pushq $0x0
    pushq $237
    jmp interrupt_handler

.int_gate_238:
    pushq $0x0
    pushq $238
    jmp interrupt_handler

.int_gate_239:
    pushq $0x0
    pushq $239
    jmp interrupt_handler

.int_gate_240:
    pushq $0x0
    pushq $240
    jmp interrupt_handler

.int_gate_241:
    pushq $0x0
    pushq $241
    jmp interrupt_handler

.int_gate_242:
    pushq $0x0
    pushq $242
    jmp interrupt_handler

.int_gate_243:
    pushq $0x0
    pushq $243
    jmp interrupt_handler

.int_gate_244:
    pushq $0x0
    pushq $244
    jmp interrupt_handler

.int_gate_245:
    pushq $0x0
    pushq $245
    jmp interrupt_handler

.int_gate_246:
    pushq $0x0
    pushq $246
    jmp interrupt_handler

.int_gate_247:
    pushq $0x0
    pushq $247
    jmp interrupt_handler

.int_gate_248:
    pushq $0x0
    pushq $248
    jmp interrupt_handler

.int_gate_249:
    pushq $0x0
    pushq $249
    jmp interrupt_handler

.int_gate_250:
    pushq $0x0
    pushq $250
    jmp interrupt_handler

.int_gate_251:
    pushq $0x0
    pushq $251
    jmp interrupt_handler

.int_gate_252:
    pushq $0x0
    pushq $252
    jmp interrupt_handler

.int_gate_253:
    pushq $0x0
    pushq $253
    jmp interrupt_handler

.int_gate_254:
    pushq $0x0
    pushq $254
    jmp interrupt_handler

.int_gate_255:
    pushq $0x0
    pushq $255
    jmp interrupt_handler
