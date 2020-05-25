.code32

.include "target/x86/common/boot.inc"

.section .text

.global interrupt_handler

/*
** Prepare dispatcher
*/

interrupt_handler:
    cli
    pushal

    pushl %ds
    pushl %es
    pushl %fs
    pushl %gs

    movw $KERNEL_DATA_SELECTOR, %ax
    movw %ax, %ds
    movw %ax, %es
    movw %ax, %fs
    movw %ax, %gs

    pushl %esp

    call interrupt_dispatch

    addl $0x4, %esp

    popl %gs
    popl %fs
    popl %es
    popl %ds

    popal

    addl $0x8, %esp

    iret

/*
** GAS apparently not allow us to do .rept/.endr with an assigned increment
** So Yes, it's ugly
*/

.section .text

.global isr

isr:

.int_gate_0:
    pushl $0x0
    pushl $0
    jmp interrupt_handler

.int_gate_1:
    pushl $0x0
    pushl $1
    jmp interrupt_handler

.int_gate_2:
    pushl $0x0
    pushl $2
    jmp interrupt_handler

.int_gate_3:
    pushl $0x0
    pushl $3
    jmp interrupt_handler

.int_gate_4:
    pushl $0x0
    pushl $4
    jmp interrupt_handler

.int_gate_5:
    pushl $0x0
    pushl $5
    jmp interrupt_handler

.int_gate_6:
    pushl $0x0
    pushl $6
    jmp interrupt_handler

.int_gate_7:
    pushl $0x0
    pushl $7
    jmp interrupt_handler

.int_gate_8:
    nop
    nop
    pushl $8
    jmp interrupt_handler

.int_gate_9:
    pushl $0x0
    pushl $9
    jmp interrupt_handler

.int_gate_10:
    nop
    nop
    pushl $10
    jmp interrupt_handler

.int_gate_11:
    nop
    nop
    pushl $11
    jmp interrupt_handler

.int_gate_12:
    nop
    nop
    pushl $12
    jmp interrupt_handler

.int_gate_13:
    nop
    nop
    pushl $13
    jmp interrupt_handler

.int_gate_14:
    nop
    nop
    pushl $14
    jmp interrupt_handler

.int_gate_15:
    pushl $0x0
    pushl $15
    jmp interrupt_handler

.int_gate_16:
    pushl $0x0
    pushl $16
    jmp interrupt_handler

.int_gate_17:
    nop
    nop
    pushl $17
    jmp interrupt_handler

.int_gate_18:
    pushl $0x0
    pushl $18
    jmp interrupt_handler

.int_gate_19:
    pushl $0x0
    pushl $19
    jmp interrupt_handler

.int_gate_20:
    pushl $0x0
    pushl $20
    jmp interrupt_handler

.int_gate_21:
    pushl $0x0
    pushl $21
    jmp interrupt_handler

.int_gate_22:
    pushl $0x0
    pushl $22
    jmp interrupt_handler

.int_gate_23:
    pushl $0x0
    pushl $23
    jmp interrupt_handler

.int_gate_24:
    pushl $0x0
    pushl $24
    jmp interrupt_handler

.int_gate_25:
    pushl $0x0
    pushl $25
    jmp interrupt_handler

.int_gate_26:
    pushl $0x0
    pushl $26
    jmp interrupt_handler

.int_gate_27:
    pushl $0x0
    pushl $27
    jmp interrupt_handler

.int_gate_28:
    pushl $0x0
    pushl $28
    jmp interrupt_handler

.int_gate_29:
    pushl $0x0
    pushl $29
    jmp interrupt_handler

.int_gate_30:
    pushl $0x0
    pushl $30
    jmp interrupt_handler

.int_gate_31:
    pushl $0x0
    pushl $31
    jmp interrupt_handler

.int_gate_32:
    pushl $0x0
    pushl $32
    jmp interrupt_handler

.int_gate_33:
    pushl $0x0
    pushl $33
    jmp interrupt_handler

.int_gate_34:
    pushl $0x0
    pushl $34
    jmp interrupt_handler

.int_gate_35:
    pushl $0x0
    pushl $35
    jmp interrupt_handler

.int_gate_36:
    pushl $0x0
    pushl $36
    jmp interrupt_handler

.int_gate_37:
    pushl $0x0
    pushl $37
    jmp interrupt_handler

.int_gate_38:
    pushl $0x0
    pushl $38
    jmp interrupt_handler

.int_gate_39:
    pushl $0x0
    pushl $39
    jmp interrupt_handler

.int_gate_40:
    pushl $0x0
    pushl $40
    jmp interrupt_handler

.int_gate_41:
    pushl $0x0
    pushl $41
    jmp interrupt_handler

.int_gate_42:
    pushl $0x0
    pushl $42
    jmp interrupt_handler

.int_gate_43:
    pushl $0x0
    pushl $43
    jmp interrupt_handler

.int_gate_44:
    pushl $0x0
    pushl $44
    jmp interrupt_handler

.int_gate_45:
    pushl $0x0
    pushl $45
    jmp interrupt_handler

.int_gate_46:
    pushl $0x0
    pushl $46
    jmp interrupt_handler

.int_gate_47:
    pushl $0x0
    pushl $47
    jmp interrupt_handler

.int_gate_48:
    pushl $0x0
    pushl $48
    jmp interrupt_handler

.int_gate_49:
    pushl $0x0
    pushl $49
    jmp interrupt_handler

.int_gate_50:
    pushl $0x0
    pushl $50
    jmp interrupt_handler

.int_gate_51:
    pushl $0x0
    pushl $51
    jmp interrupt_handler

.int_gate_52:
    pushl $0x0
    pushl $52
    jmp interrupt_handler

.int_gate_53:
    pushl $0x0
    pushl $53
    jmp interrupt_handler

.int_gate_54:
    pushl $0x0
    pushl $54
    jmp interrupt_handler

.int_gate_55:
    pushl $0x0
    pushl $55
    jmp interrupt_handler

.int_gate_56:
    pushl $0x0
    pushl $56
    jmp interrupt_handler

.int_gate_57:
    pushl $0x0
    pushl $57
    jmp interrupt_handler

.int_gate_58:
    pushl $0x0
    pushl $58
    jmp interrupt_handler

.int_gate_59:
    pushl $0x0
    pushl $59
    jmp interrupt_handler

.int_gate_60:
    pushl $0x0
    pushl $60
    jmp interrupt_handler

.int_gate_61:
    pushl $0x0
    pushl $61
    jmp interrupt_handler

.int_gate_62:
    pushl $0x0
    pushl $62
    jmp interrupt_handler

.int_gate_63:
    pushl $0x0
    pushl $63
    jmp interrupt_handler

.int_gate_64:
    pushl $0x0
    pushl $64
    jmp interrupt_handler

.int_gate_65:
    pushl $0x0
    pushl $65
    jmp interrupt_handler

.int_gate_66:
    pushl $0x0
    pushl $66
    jmp interrupt_handler

.int_gate_67:
    pushl $0x0
    pushl $67
    jmp interrupt_handler

.int_gate_68:
    pushl $0x0
    pushl $68
    jmp interrupt_handler

.int_gate_69:
    pushl $0x0
    pushl $69
    jmp interrupt_handler

.int_gate_70:
    pushl $0x0
    pushl $70
    jmp interrupt_handler

.int_gate_71:
    pushl $0x0
    pushl $71
    jmp interrupt_handler

.int_gate_72:
    pushl $0x0
    pushl $72
    jmp interrupt_handler

.int_gate_73:
    pushl $0x0
    pushl $73
    jmp interrupt_handler

.int_gate_74:
    pushl $0x0
    pushl $74
    jmp interrupt_handler

.int_gate_75:
    pushl $0x0
    pushl $75
    jmp interrupt_handler

.int_gate_76:
    pushl $0x0
    pushl $76
    jmp interrupt_handler

.int_gate_77:
    pushl $0x0
    pushl $77
    jmp interrupt_handler

.int_gate_78:
    pushl $0x0
    pushl $78
    jmp interrupt_handler

.int_gate_79:
    pushl $0x0
    pushl $79
    jmp interrupt_handler

.int_gate_80:
    pushl $0x0
    pushl $80
    jmp interrupt_handler

.int_gate_81:
    pushl $0x0
    pushl $81
    jmp interrupt_handler

.int_gate_82:
    pushl $0x0
    pushl $82
    jmp interrupt_handler

.int_gate_83:
    pushl $0x0
    pushl $83
    jmp interrupt_handler

.int_gate_84:
    pushl $0x0
    pushl $84
    jmp interrupt_handler

.int_gate_85:
    pushl $0x0
    pushl $85
    jmp interrupt_handler

.int_gate_86:
    pushl $0x0
    pushl $86
    jmp interrupt_handler

.int_gate_87:
    pushl $0x0
    pushl $87
    jmp interrupt_handler

.int_gate_88:
    pushl $0x0
    pushl $88
    jmp interrupt_handler

.int_gate_89:
    pushl $0x0
    pushl $89
    jmp interrupt_handler

.int_gate_90:
    pushl $0x0
    pushl $90
    jmp interrupt_handler

.int_gate_91:
    pushl $0x0
    pushl $91
    jmp interrupt_handler

.int_gate_92:
    pushl $0x0
    pushl $92
    jmp interrupt_handler

.int_gate_93:
    pushl $0x0
    pushl $93
    jmp interrupt_handler

.int_gate_94:
    pushl $0x0
    pushl $94
    jmp interrupt_handler

.int_gate_95:
    pushl $0x0
    pushl $95
    jmp interrupt_handler

.int_gate_96:
    pushl $0x0
    pushl $96
    jmp interrupt_handler

.int_gate_97:
    pushl $0x0
    pushl $97
    jmp interrupt_handler

.int_gate_98:
    pushl $0x0
    pushl $98
    jmp interrupt_handler

.int_gate_99:
    pushl $0x0
    pushl $99
    jmp interrupt_handler

.int_gate_100:
    pushl $0x0
    pushl $100
    jmp interrupt_handler

.int_gate_101:
    pushl $0x0
    pushl $101
    jmp interrupt_handler

.int_gate_102:
    pushl $0x0
    pushl $102
    jmp interrupt_handler

.int_gate_103:
    pushl $0x0
    pushl $103
    jmp interrupt_handler

.int_gate_104:
    pushl $0x0
    pushl $104
    jmp interrupt_handler

.int_gate_105:
    pushl $0x0
    pushl $105
    jmp interrupt_handler

.int_gate_106:
    pushl $0x0
    pushl $106
    jmp interrupt_handler

.int_gate_107:
    pushl $0x0
    pushl $107
    jmp interrupt_handler

.int_gate_108:
    pushl $0x0
    pushl $108
    jmp interrupt_handler

.int_gate_109:
    pushl $0x0
    pushl $109
    jmp interrupt_handler

.int_gate_110:
    pushl $0x0
    pushl $110
    jmp interrupt_handler

.int_gate_111:
    pushl $0x0
    pushl $111
    jmp interrupt_handler

.int_gate_112:
    pushl $0x0
    pushl $112
    jmp interrupt_handler

.int_gate_113:
    pushl $0x0
    pushl $113
    jmp interrupt_handler

.int_gate_114:
    pushl $0x0
    pushl $114
    jmp interrupt_handler

.int_gate_115:
    pushl $0x0
    pushl $115
    jmp interrupt_handler

.int_gate_116:
    pushl $0x0
    pushl $116
    jmp interrupt_handler

.int_gate_117:
    pushl $0x0
    pushl $117
    jmp interrupt_handler

.int_gate_118:
    pushl $0x0
    pushl $118
    jmp interrupt_handler

.int_gate_119:
    pushl $0x0
    pushl $119
    jmp interrupt_handler

.int_gate_120:
    pushl $0x0
    pushl $120
    jmp interrupt_handler

.int_gate_121:
    pushl $0x0
    pushl $121
    jmp interrupt_handler

.int_gate_122:
    pushl $0x0
    pushl $122
    jmp interrupt_handler

.int_gate_123:
    pushl $0x0
    pushl $123
    jmp interrupt_handler

.int_gate_124:
    pushl $0x0
    pushl $124
    jmp interrupt_handler

.int_gate_125:
    pushl $0x0
    pushl $125
    jmp interrupt_handler

.int_gate_126:
    pushl $0x0
    pushl $126
    jmp interrupt_handler

.int_gate_127:
    pushl $0x0
    pushl $127
    jmp interrupt_handler

.int_gate_128:
    pushl $0x0
    pushl $128
    jmp interrupt_handler

.int_gate_129:
    pushl $0x0
    pushl $129
    jmp interrupt_handler

.int_gate_130:
    pushl $0x0
    pushl $130
    jmp interrupt_handler

.int_gate_131:
    pushl $0x0
    pushl $131
    jmp interrupt_handler

.int_gate_132:
    pushl $0x0
    pushl $132
    jmp interrupt_handler

.int_gate_133:
    pushl $0x0
    pushl $133
    jmp interrupt_handler

.int_gate_134:
    pushl $0x0
    pushl $134
    jmp interrupt_handler

.int_gate_135:
    pushl $0x0
    pushl $135
    jmp interrupt_handler

.int_gate_136:
    pushl $0x0
    pushl $136
    jmp interrupt_handler

.int_gate_137:
    pushl $0x0
    pushl $137
    jmp interrupt_handler

.int_gate_138:
    pushl $0x0
    pushl $138
    jmp interrupt_handler

.int_gate_139:
    pushl $0x0
    pushl $139
    jmp interrupt_handler

.int_gate_140:
    pushl $0x0
    pushl $140
    jmp interrupt_handler

.int_gate_141:
    pushl $0x0
    pushl $141
    jmp interrupt_handler

.int_gate_142:
    pushl $0x0
    pushl $142
    jmp interrupt_handler

.int_gate_143:
    pushl $0x0
    pushl $143
    jmp interrupt_handler

.int_gate_144:
    pushl $0x0
    pushl $144
    jmp interrupt_handler

.int_gate_145:
    pushl $0x0
    pushl $145
    jmp interrupt_handler

.int_gate_146:
    pushl $0x0
    pushl $146
    jmp interrupt_handler

.int_gate_147:
    pushl $0x0
    pushl $147
    jmp interrupt_handler

.int_gate_148:
    pushl $0x0
    pushl $148
    jmp interrupt_handler

.int_gate_149:
    pushl $0x0
    pushl $149
    jmp interrupt_handler

.int_gate_150:
    pushl $0x0
    pushl $150
    jmp interrupt_handler

.int_gate_151:
    pushl $0x0
    pushl $151
    jmp interrupt_handler

.int_gate_152:
    pushl $0x0
    pushl $152
    jmp interrupt_handler

.int_gate_153:
    pushl $0x0
    pushl $153
    jmp interrupt_handler

.int_gate_154:
    pushl $0x0
    pushl $154
    jmp interrupt_handler

.int_gate_155:
    pushl $0x0
    pushl $155
    jmp interrupt_handler

.int_gate_156:
    pushl $0x0
    pushl $156
    jmp interrupt_handler

.int_gate_157:
    pushl $0x0
    pushl $157
    jmp interrupt_handler

.int_gate_158:
    pushl $0x0
    pushl $158
    jmp interrupt_handler

.int_gate_159:
    pushl $0x0
    pushl $159
    jmp interrupt_handler

.int_gate_160:
    pushl $0x0
    pushl $160
    jmp interrupt_handler

.int_gate_161:
    pushl $0x0
    pushl $161
    jmp interrupt_handler

.int_gate_162:
    pushl $0x0
    pushl $162
    jmp interrupt_handler

.int_gate_163:
    pushl $0x0
    pushl $163
    jmp interrupt_handler

.int_gate_164:
    pushl $0x0
    pushl $164
    jmp interrupt_handler

.int_gate_165:
    pushl $0x0
    pushl $165
    jmp interrupt_handler

.int_gate_166:
    pushl $0x0
    pushl $166
    jmp interrupt_handler

.int_gate_167:
    pushl $0x0
    pushl $167
    jmp interrupt_handler

.int_gate_168:
    pushl $0x0
    pushl $168
    jmp interrupt_handler

.int_gate_169:
    pushl $0x0
    pushl $169
    jmp interrupt_handler

.int_gate_170:
    pushl $0x0
    pushl $170
    jmp interrupt_handler

.int_gate_171:
    pushl $0x0
    pushl $171
    jmp interrupt_handler

.int_gate_172:
    pushl $0x0
    pushl $172
    jmp interrupt_handler

.int_gate_173:
    pushl $0x0
    pushl $173
    jmp interrupt_handler

.int_gate_174:
    pushl $0x0
    pushl $174
    jmp interrupt_handler

.int_gate_175:
    pushl $0x0
    pushl $175
    jmp interrupt_handler

.int_gate_176:
    pushl $0x0
    pushl $176
    jmp interrupt_handler

.int_gate_177:
    pushl $0x0
    pushl $177
    jmp interrupt_handler

.int_gate_178:
    pushl $0x0
    pushl $178
    jmp interrupt_handler

.int_gate_179:
    pushl $0x0
    pushl $179
    jmp interrupt_handler

.int_gate_180:
    pushl $0x0
    pushl $180
    jmp interrupt_handler

.int_gate_181:
    pushl $0x0
    pushl $181
    jmp interrupt_handler

.int_gate_182:
    pushl $0x0
    pushl $182
    jmp interrupt_handler

.int_gate_183:
    pushl $0x0
    pushl $183
    jmp interrupt_handler

.int_gate_184:
    pushl $0x0
    pushl $184
    jmp interrupt_handler

.int_gate_185:
    pushl $0x0
    pushl $185
    jmp interrupt_handler

.int_gate_186:
    pushl $0x0
    pushl $186
    jmp interrupt_handler

.int_gate_187:
    pushl $0x0
    pushl $187
    jmp interrupt_handler

.int_gate_188:
    pushl $0x0
    pushl $188
    jmp interrupt_handler

.int_gate_189:
    pushl $0x0
    pushl $189
    jmp interrupt_handler

.int_gate_190:
    pushl $0x0
    pushl $190
    jmp interrupt_handler

.int_gate_191:
    pushl $0x0
    pushl $191
    jmp interrupt_handler

.int_gate_192:
    pushl $0x0
    pushl $192
    jmp interrupt_handler

.int_gate_193:
    pushl $0x0
    pushl $193
    jmp interrupt_handler

.int_gate_194:
    pushl $0x0
    pushl $194
    jmp interrupt_handler

.int_gate_195:
    pushl $0x0
    pushl $195
    jmp interrupt_handler

.int_gate_196:
    pushl $0x0
    pushl $196
    jmp interrupt_handler

.int_gate_197:
    pushl $0x0
    pushl $197
    jmp interrupt_handler

.int_gate_198:
    pushl $0x0
    pushl $198
    jmp interrupt_handler

.int_gate_199:
    pushl $0x0
    pushl $199
    jmp interrupt_handler

.int_gate_200:
    pushl $0x0
    pushl $200
    jmp interrupt_handler

.int_gate_201:
    pushl $0x0
    pushl $201
    jmp interrupt_handler

.int_gate_202:
    pushl $0x0
    pushl $202
    jmp interrupt_handler

.int_gate_203:
    pushl $0x0
    pushl $203
    jmp interrupt_handler

.int_gate_204:
    pushl $0x0
    pushl $204
    jmp interrupt_handler

.int_gate_205:
    pushl $0x0
    pushl $205
    jmp interrupt_handler

.int_gate_206:
    pushl $0x0
    pushl $206
    jmp interrupt_handler

.int_gate_207:
    pushl $0x0
    pushl $207
    jmp interrupt_handler

.int_gate_208:
    pushl $0x0
    pushl $208
    jmp interrupt_handler

.int_gate_209:
    pushl $0x0
    pushl $209
    jmp interrupt_handler

.int_gate_210:
    pushl $0x0
    pushl $210
    jmp interrupt_handler

.int_gate_211:
    pushl $0x0
    pushl $211
    jmp interrupt_handler

.int_gate_212:
    pushl $0x0
    pushl $212
    jmp interrupt_handler

.int_gate_213:
    pushl $0x0
    pushl $213
    jmp interrupt_handler

.int_gate_214:
    pushl $0x0
    pushl $214
    jmp interrupt_handler

.int_gate_215:
    pushl $0x0
    pushl $215
    jmp interrupt_handler

.int_gate_216:
    pushl $0x0
    pushl $216
    jmp interrupt_handler

.int_gate_217:
    pushl $0x0
    pushl $217
    jmp interrupt_handler

.int_gate_218:
    pushl $0x0
    pushl $218
    jmp interrupt_handler

.int_gate_219:
    pushl $0x0
    pushl $219
    jmp interrupt_handler

.int_gate_220:
    pushl $0x0
    pushl $220
    jmp interrupt_handler

.int_gate_221:
    pushl $0x0
    pushl $221
    jmp interrupt_handler

.int_gate_222:
    pushl $0x0
    pushl $222
    jmp interrupt_handler

.int_gate_223:
    pushl $0x0
    pushl $223
    jmp interrupt_handler

.int_gate_224:
    pushl $0x0
    pushl $224
    jmp interrupt_handler

.int_gate_225:
    pushl $0x0
    pushl $225
    jmp interrupt_handler

.int_gate_226:
    pushl $0x0
    pushl $226
    jmp interrupt_handler

.int_gate_227:
    pushl $0x0
    pushl $227
    jmp interrupt_handler

.int_gate_228:
    pushl $0x0
    pushl $228
    jmp interrupt_handler

.int_gate_229:
    pushl $0x0
    pushl $229
    jmp interrupt_handler

.int_gate_230:
    pushl $0x0
    pushl $230
    jmp interrupt_handler

.int_gate_231:
    pushl $0x0
    pushl $231
    jmp interrupt_handler

.int_gate_232:
    pushl $0x0
    pushl $232
    jmp interrupt_handler

.int_gate_233:
    pushl $0x0
    pushl $233
    jmp interrupt_handler

.int_gate_234:
    pushl $0x0
    pushl $234
    jmp interrupt_handler

.int_gate_235:
    pushl $0x0
    pushl $235
    jmp interrupt_handler

.int_gate_236:
    pushl $0x0
    pushl $236
    jmp interrupt_handler

.int_gate_237:
    pushl $0x0
    pushl $237
    jmp interrupt_handler

.int_gate_238:
    pushl $0x0
    pushl $238
    jmp interrupt_handler

.int_gate_239:
    pushl $0x0
    pushl $239
    jmp interrupt_handler

.int_gate_240:
    pushl $0x0
    pushl $240
    jmp interrupt_handler

.int_gate_241:
    pushl $0x0
    pushl $241
    jmp interrupt_handler

.int_gate_242:
    pushl $0x0
    pushl $242
    jmp interrupt_handler

.int_gate_243:
    pushl $0x0
    pushl $243
    jmp interrupt_handler

.int_gate_244:
    pushl $0x0
    pushl $244
    jmp interrupt_handler

.int_gate_245:
    pushl $0x0
    pushl $245
    jmp interrupt_handler

.int_gate_246:
    pushl $0x0
    pushl $246
    jmp interrupt_handler

.int_gate_247:
    pushl $0x0
    pushl $247
    jmp interrupt_handler

.int_gate_248:
    pushl $0x0
    pushl $248
    jmp interrupt_handler

.int_gate_249:
    pushl $0x0
    pushl $249
    jmp interrupt_handler

.int_gate_250:
    pushl $0x0
    pushl $250
    jmp interrupt_handler

.int_gate_251:
    pushl $0x0
    pushl $251
    jmp interrupt_handler

.int_gate_252:
    pushl $0x0
    pushl $252
    jmp interrupt_handler

.int_gate_253:
    pushl $0x0
    pushl $253
    jmp interrupt_handler

.int_gate_254:
    pushl $0x0
    pushl $254
    jmp interrupt_handler

.int_gate_255:
    pushl $0x0
    pushl $255
    jmp interrupt_handler
