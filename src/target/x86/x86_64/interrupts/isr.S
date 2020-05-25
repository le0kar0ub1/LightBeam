.code64

.include "target/x86/common/boot.inc"

/*
** GAS apparently not allow us to do .rept/.endr with an assigned increment
** So Yes, it's ugly
*/

.section .text

.global isr

isr:
.int_gate_0:
    pushq $0x0
    .byte 0x68
    .byte 0
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_1:
    pushq $0x0
    .byte 0x68
    .byte 1
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_2:
    pushq $0x0
    .byte 0x68
    .byte 2
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_3:
    pushq $0x0
    .byte 0x68
    .byte 3
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_4:
    pushq $0x0
    .byte 0x68
    .byte 4
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_5:
    pushq $0x0
    .byte 0x68
    .byte 5
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_6:
    pushq $0x0
    .byte 0x68
    .byte 6
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_7:
    pushq $0x0
    .byte 0x68
    .byte 7
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_8:
    nop
    nop
    .byte 0x68
    .byte 8
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_9:
    pushq $0x0
    .byte 0x68
    .byte 9
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_10:
    nop
    nop
    .byte 0x68
    .byte 10
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_11:
    nop
    nop
    .byte 0x68
    .byte 11
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_12:
    nop
    nop
    .byte 0x68
    .byte 12
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_13:
    nop
    nop
    .byte 0x68
    .byte 13
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_14:
    nop
    nop
    .byte 0x68
    .byte 14
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_15:
    pushq $0x0
    .byte 0x68
    .byte 15
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_16:
    pushq $0x0
    .byte 0x68
    .byte 16
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_17:
    nop
    nop
    .byte 0x68
    .byte 17
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_18:
    pushq $0x0
    .byte 0x68
    .byte 18
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_19:
    pushq $0x0
    .byte 0x68
    .byte 19
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_20:
    pushq $0x0
    .byte 0x68
    .byte 20
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_21:
    pushq $0x0
    .byte 0x68
    .byte 21
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_22:
    pushq $0x0
    .byte 0x68
    .byte 22
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_23:
    pushq $0x0
    .byte 0x68
    .byte 23
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_24:
    pushq $0x0
    .byte 0x68
    .byte 24
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_25:
    pushq $0x0
    .byte 0x68
    .byte 25
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_26:
    pushq $0x0
    .byte 0x68
    .byte 26
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_27:
    pushq $0x0
    .byte 0x68
    .byte 27
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_28:
    pushq $0x0
    .byte 0x68
    .byte 28
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_29:
    pushq $0x0
    .byte 0x68
    .byte 29
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_30:
    pushq $0x0
    .byte 0x68
    .byte 30
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_31:
    pushq $0x0
    .byte 0x68
    .byte 31
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_32:
    pushq $0x0
    .byte 0x68
    .byte 32
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_33:
    pushq $0x0
    .byte 0x68
    .byte 33
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_34:
    pushq $0x0
    .byte 0x68
    .byte 34
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_35:
    pushq $0x0
    .byte 0x68
    .byte 35
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_36:
    pushq $0x0
    .byte 0x68
    .byte 36
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_37:
    pushq $0x0
    .byte 0x68
    .byte 37
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_38:
    pushq $0x0
    .byte 0x68
    .byte 38
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_39:
    pushq $0x0
    .byte 0x68
    .byte 39
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_40:
    pushq $0x0
    .byte 0x68
    .byte 40
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_41:
    pushq $0x0
    .byte 0x68
    .byte 41
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_42:
    pushq $0x0
    .byte 0x68
    .byte 42
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_43:
    pushq $0x0
    .byte 0x68
    .byte 43
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_44:
    pushq $0x0
    .byte 0x68
    .byte 44
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_45:
    pushq $0x0
    .byte 0x68
    .byte 45
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_46:
    pushq $0x0
    .byte 0x68
    .byte 46
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_47:
    pushq $0x0
    .byte 0x68
    .byte 47
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_48:
    pushq $0x0
    .byte 0x68
    .byte 48
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_49:
    pushq $0x0
    .byte 0x68
    .byte 49
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_50:
    pushq $0x0
    .byte 0x68
    .byte 50
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_51:
    pushq $0x0
    .byte 0x68
    .byte 51
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_52:
    pushq $0x0
    .byte 0x68
    .byte 52
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_53:
    pushq $0x0
    .byte 0x68
    .byte 53
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_54:
    pushq $0x0
    .byte 0x68
    .byte 54
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_55:
    pushq $0x0
    .byte 0x68
    .byte 55
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_56:
    pushq $0x0
    .byte 0x68
    .byte 56
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_57:
    pushq $0x0
    .byte 0x68
    .byte 57
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_58:
    pushq $0x0
    .byte 0x68
    .byte 58
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_59:
    pushq $0x0
    .byte 0x68
    .byte 59
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_60:
    pushq $0x0
    .byte 0x68
    .byte 60
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_61:
    pushq $0x0
    .byte 0x68
    .byte 61
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_62:
    pushq $0x0
    .byte 0x68
    .byte 62
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_63:
    pushq $0x0
    .byte 0x68
    .byte 63
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_64:
    pushq $0x0
    .byte 0x68
    .byte 64
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_65:
    pushq $0x0
    .byte 0x68
    .byte 65
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_66:
    pushq $0x0
    .byte 0x68
    .byte 66
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_67:
    pushq $0x0
    .byte 0x68
    .byte 67
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_68:
    pushq $0x0
    .byte 0x68
    .byte 0x68
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_69:
    pushq $0x0
    .byte 0x68
    .byte 69
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_70:
    pushq $0x0
    .byte 0x68
    .byte 70
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_71:
    pushq $0x0
    .byte 0x68
    .byte 71
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_72:
    pushq $0x0
    .byte 0x68
    .byte 72
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_73:
    pushq $0x0
    .byte 0x68
    .byte 73
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_74:
    pushq $0x0
    .byte 0x68
    .byte 74
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_75:
    pushq $0x0
    .byte 0x68
    .byte 75
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_76:
    pushq $0x0
    .byte 0x68
    .byte 76
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_77:
    pushq $0x0
    .byte 0x68
    .byte 77
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_78:
    pushq $0x0
    .byte 0x68
    .byte 78
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_79:
    pushq $0x0
    .byte 0x68
    .byte 79
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_80:
    pushq $0x0
    .byte 0x68
    .byte 80
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_81:
    pushq $0x0
    .byte 0x68
    .byte 81
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_82:
    pushq $0x0
    .byte 0x68
    .byte 82
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_83:
    pushq $0x0
    .byte 0x68
    .byte 83
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_84:
    pushq $0x0
    .byte 0x68
    .byte 84
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_85:
    pushq $0x0
    .byte 0x68
    .byte 85
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_86:
    pushq $0x0
    .byte 0x68
    .byte 86
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_87:
    pushq $0x0
    .byte 0x68
    .byte 87
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_88:
    pushq $0x0
    .byte 0x68
    .byte 88
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_89:
    pushq $0x0
    .byte 0x68
    .byte 89
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_90:
    pushq $0x0
    .byte 0x68
    .byte 90
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_91:
    pushq $0x0
    .byte 0x68
    .byte 91
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_92:
    pushq $0x0
    .byte 0x68
    .byte 92
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_93:
    pushq $0x0
    .byte 0x68
    .byte 93
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_94:
    pushq $0x0
    .byte 0x68
    .byte 94
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_95:
    pushq $0x0
    .byte 0x68
    .byte 95
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_96:
    pushq $0x0
    .byte 0x68
    .byte 96
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_97:
    pushq $0x0
    .byte 0x68
    .byte 97
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_98:
    pushq $0x0
    .byte 0x68
    .byte 98
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_99:
    pushq $0x0
    .byte 0x68
    .byte 99
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_100:
    pushq $0x0
    .byte 0x68
    .byte 100
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_101:
    pushq $0x0
    .byte 0x68
    .byte 101
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_102:
    pushq $0x0
    .byte 0x68
    .byte 102
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_103:
    pushq $0x0
    .byte 0x68
    .byte 103
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_104:
    pushq $0x0
    .byte 0x68
    .byte 104
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_105:
    pushq $0x0
    .byte 0x68
    .byte 105
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_106:
    pushq $0x0
    .byte 0x68
    .byte 106
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_107:
    pushq $0x0
    .byte 0x68
    .byte 107
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_108:
    pushq $0x0
    .byte 0x68
    .byte 108
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_109:
    pushq $0x0
    .byte 0x68
    .byte 109
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_110:
    pushq $0x0
    .byte 0x68
    .byte 110
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_111:
    pushq $0x0
    .byte 0x68
    .byte 111
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_112:
    pushq $0x0
    .byte 0x68
    .byte 112
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_113:
    pushq $0x0
    .byte 0x68
    .byte 113
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_114:
    pushq $0x0
    .byte 0x68
    .byte 114
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_115:
    pushq $0x0
    .byte 0x68
    .byte 115
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_116:
    pushq $0x0
    .byte 0x68
    .byte 116
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_117:
    pushq $0x0
    .byte 0x68
    .byte 117
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_118:
    pushq $0x0
    .byte 0x68
    .byte 118
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_119:
    pushq $0x0
    .byte 0x68
    .byte 119
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_120:
    pushq $0x0
    .byte 0x68
    .byte 120
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_121:
    pushq $0x0
    .byte 0x68
    .byte 121
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_122:
    pushq $0x0
    .byte 0x68
    .byte 122
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_123:
    pushq $0x0
    .byte 0x68
    .byte 123
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_124:
    pushq $0x0
    .byte 0x68
    .byte 124
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_125:
    pushq $0x0
    .byte 0x68
    .byte 125
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_126:
    pushq $0x0
    .byte 0x68
    .byte 126
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_127:
    pushq $0x0
    .byte 0x68
    .byte 127
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_128:
    pushq $0x0
    .byte 0x68
    .byte 128
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_129:
    pushq $0x0
    .byte 0x68
    .byte 129
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_130:
    pushq $0x0
    .byte 0x68
    .byte 130
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_131:
    pushq $0x0
    .byte 0x68
    .byte 131
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_132:
    pushq $0x0
    .byte 0x68
    .byte 132
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_133:
    pushq $0x0
    .byte 0x68
    .byte 133
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_134:
    pushq $0x0
    .byte 0x68
    .byte 134
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_135:
    pushq $0x0
    .byte 0x68
    .byte 135
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_136:
    pushq $0x0
    .byte 0x68
    .byte 136
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_137:
    pushq $0x0
    .byte 0x68
    .byte 137
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_138:
    pushq $0x0
    .byte 0x68
    .byte 138
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_139:
    pushq $0x0
    .byte 0x68
    .byte 139
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_140:
    pushq $0x0
    .byte 0x68
    .byte 140
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_141:
    pushq $0x0
    .byte 0x68
    .byte 141
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_142:
    pushq $0x0
    .byte 0x68
    .byte 142
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_143:
    pushq $0x0
    .byte 0x68
    .byte 143
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_144:
    pushq $0x0
    .byte 0x68
    .byte 144
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_145:
    pushq $0x0
    .byte 0x68
    .byte 145
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_146:
    pushq $0x0
    .byte 0x68
    .byte 146
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_147:
    pushq $0x0
    .byte 0x68
    .byte 147
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_148:
    pushq $0x0
    .byte 0x68
    .byte 148
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_149:
    pushq $0x0
    .byte 0x68
    .byte 149
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_150:
    pushq $0x0
    .byte 0x68
    .byte 150
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_151:
    pushq $0x0
    .byte 0x68
    .byte 151
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_152:
    pushq $0x0
    .byte 0x68
    .byte 152
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_153:
    pushq $0x0
    .byte 0x68
    .byte 153
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_154:
    pushq $0x0
    .byte 0x68
    .byte 154
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_155:
    pushq $0x0
    .byte 0x68
    .byte 155
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_156:
    pushq $0x0
    .byte 0x68
    .byte 156
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_157:
    pushq $0x0
    .byte 0x68
    .byte 157
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_158:
    pushq $0x0
    .byte 0x68
    .byte 158
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_159:
    pushq $0x0
    .byte 0x68
    .byte 159
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_160:
    pushq $0x0
    .byte 0x68
    .byte 160
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_161:
    pushq $0x0
    .byte 0x68
    .byte 161
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_162:
    pushq $0x0
    .byte 0x68
    .byte 162
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_163:
    pushq $0x0
    .byte 0x68
    .byte 163
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_164:
    pushq $0x0
    .byte 0x68
    .byte 164
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_165:
    pushq $0x0
    .byte 0x68
    .byte 165
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_166:
    pushq $0x0
    .byte 0x68
    .byte 166
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_167:
    pushq $0x0
    .byte 0x68
    .byte 167
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_168:
    pushq $0x0
    .byte 0x68
    .byte 168
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_169:
    pushq $0x0
    .byte 0x68
    .byte 169
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_170:
    pushq $0x0
    .byte 0x68
    .byte 170
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_171:
    pushq $0x0
    .byte 0x68
    .byte 171
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_172:
    pushq $0x0
    .byte 0x68
    .byte 172
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_173:
    pushq $0x0
    .byte 0x68
    .byte 173
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_174:
    pushq $0x0
    .byte 0x68
    .byte 174
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_175:
    pushq $0x0
    .byte 0x68
    .byte 175
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_176:
    pushq $0x0
    .byte 0x68
    .byte 176
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_177:
    pushq $0x0
    .byte 0x68
    .byte 177
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_178:
    pushq $0x0
    .byte 0x68
    .byte 178
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_179:
    pushq $0x0
    .byte 0x68
    .byte 179
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_180:
    pushq $0x0
    .byte 0x68
    .byte 180
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_181:
    pushq $0x0
    .byte 0x68
    .byte 181
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_182:
    pushq $0x0
    .byte 0x68
    .byte 182
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_183:
    pushq $0x0
    .byte 0x68
    .byte 183
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_184:
    pushq $0x0
    .byte 0x68
    .byte 184
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_185:
    pushq $0x0
    .byte 0x68
    .byte 185
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_186:
    pushq $0x0
    .byte 0x68
    .byte 186
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_187:
    pushq $0x0
    .byte 0x68
    .byte 187
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_188:
    pushq $0x0
    .byte 0x68
    .byte 188
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_189:
    pushq $0x0
    .byte 0x68
    .byte 189
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_190:
    pushq $0x0
    .byte 0x68
    .byte 190
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_191:
    pushq $0x0
    .byte 0x68
    .byte 191
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_192:
    pushq $0x0
    .byte 0x68
    .byte 192
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_193:
    pushq $0x0
    .byte 0x68
    .byte 193
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_194:
    pushq $0x0
    .byte 0x68
    .byte 194
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_195:
    pushq $0x0
    .byte 0x68
    .byte 195
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_196:
    pushq $0x0
    .byte 0x68
    .byte 196
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_197:
    pushq $0x0
    .byte 0x68
    .byte 197
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_198:
    pushq $0x0
    .byte 0x68
    .byte 198
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_199:
    pushq $0x0
    .byte 0x68
    .byte 199
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_200:
    pushq $0x0
    .byte 0x68
    .byte 200
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_201:
    pushq $0x0
    .byte 0x68
    .byte 201
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_202:
    pushq $0x0
    .byte 0x68
    .byte 202
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_203:
    pushq $0x0
    .byte 0x68
    .byte 203
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_204:
    pushq $0x0
    .byte 0x68
    .byte 204
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_205:
    pushq $0x0
    .byte 0x68
    .byte 205
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_206:
    pushq $0x0
    .byte 0x68
    .byte 206
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_207:
    pushq $0x0
    .byte 0x68
    .byte 207
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_208:
    pushq $0x0
    .byte 0x68
    .byte 208
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_209:
    pushq $0x0
    .byte 0x68
    .byte 209
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_210:
    pushq $0x0
    .byte 0x68
    .byte 210
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_211:
    pushq $0x0
    .byte 0x68
    .byte 211
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_212:
    pushq $0x0
    .byte 0x68
    .byte 212
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_213:
    pushq $0x0
    .byte 0x68
    .byte 213
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_214:
    pushq $0x0
    .byte 0x68
    .byte 214
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_215:
    pushq $0x0
    .byte 0x68
    .byte 215
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_216:
    pushq $0x0
    .byte 0x68
    .byte 216
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_217:
    pushq $0x0
    .byte 0x68
    .byte 217
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_218:
    pushq $0x0
    .byte 0x68
    .byte 218
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_219:
    pushq $0x0
    .byte 0x68
    .byte 219
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_220:
    pushq $0x0
    .byte 0x68
    .byte 220
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_221:
    pushq $0x0
    .byte 0x68
    .byte 221
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_222:
    pushq $0x0
    .byte 0x68
    .byte 222
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_223:
    pushq $0x0
    .byte 0x68
    .byte 223
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_224:
    pushq $0x0
    .byte 0x68
    .byte 224
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_225:
    pushq $0x0
    .byte 0x68
    .byte 225
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_226:
    pushq $0x0
    .byte 0x68
    .byte 226
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_227:
    pushq $0x0
    .byte 0x68
    .byte 227
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_228:
    pushq $0x0
    .byte 0x68
    .byte 228
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_229:
    pushq $0x0
    .byte 0x68
    .byte 229
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_230:
    pushq $0x0
    .byte 0x68
    .byte 230
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_231:
    pushq $0x0
    .byte 0x68
    .byte 231
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_232:
    pushq $0x0
    .byte 0x68
    .byte 232
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_233:
    pushq $0x0
    .byte 0x68
    .byte 233
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_234:
    pushq $0x0
    .byte 0x68
    .byte 234
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_235:
    pushq $0x0
    .byte 0x68
    .byte 235
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_236:
    pushq $0x0
    .byte 0x68
    .byte 236
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_237:
    pushq $0x0
    .byte 0x68
    .byte 237
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_238:
    pushq $0x0
    .byte 0x68
    .byte 238
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_239:
    pushq $0x0
    .byte 0x68
    .byte 239
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_240:
    pushq $0x0
    .byte 0x68
    .byte 240
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_241:
    pushq $0x0
    .byte 0x68
    .byte 241
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_242:
    pushq $0x0
    .byte 0x68
    .byte 242
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_243:
    pushq $0x0
    .byte 0x68
    .byte 243
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_244:
    pushq $0x0
    .byte 0x68
    .byte 244
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_245:
    pushq $0x0
    .byte 0x68
    .byte 245
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_246:
    pushq $0x0
    .byte 0x68
    .byte 246
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_247:
    pushq $0x0
    .byte 0x68
    .byte 247
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_248:
    pushq $0x0
    .byte 0x68
    .byte 248
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_249:
    pushq $0x0
    .byte 0x68
    .byte 249
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_250:
    pushq $0x0
    .byte 0x68
    .byte 250
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_251:
    pushq $0x0
    .byte 0x68
    .byte 251
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_252:
    pushq $0x0
    .byte 0x68
    .byte 252
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_253:
    pushq $0x0
    .byte 0x68
    .byte 253
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_254:
    pushq $0x0
    .byte 0x68
    .byte 254
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_255:
    pushq $0x0
    .byte 0x68
    .byte 255
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler
