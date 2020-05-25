.code32

.include "target/x86/common/boot.inc"

/*
** GAS apparently not allow us to do .rept/.endr with an assigned increment
** So Yes, it's ugly
*/

.section .text

.global isr

isr:
.int_gate_0:
    pushl $0x0
    .byte 0x68
    .byte 0
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_1:
    pushl $0x0
    .byte 0x68
    .byte 1
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_2:
    pushl $0x0
    .byte 0x68
    .byte 2
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_3:
    pushl $0x0
    .byte 0x68
    .byte 3
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_4:
    pushl $0x0
    .byte 0x68
    .byte 4
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_5:
    pushl $0x0
    .byte 0x68
    .byte 5
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_6:
    pushl $0x0
    .byte 0x68
    .byte 6
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_7:
    pushl $0x0
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
    pushl $0x0
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
    pushl $0x0
    .byte 0x68
    .byte 15
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_16:
    pushl $0x0
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
    pushl $0x0
    .byte 0x68
    .byte 18
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_19:
    pushl $0x0
    .byte 0x68
    .byte 19
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_20:
    pushl $0x0
    .byte 0x68
    .byte 20
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_21:
    pushl $0x0
    .byte 0x68
    .byte 21
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_22:
    pushl $0x0
    .byte 0x68
    .byte 22
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_23:
    pushl $0x0
    .byte 0x68
    .byte 23
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_24:
    pushl $0x0
    .byte 0x68
    .byte 24
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_25:
    pushl $0x0
    .byte 0x68
    .byte 25
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_26:
    pushl $0x0
    .byte 0x68
    .byte 26
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_27:
    pushl $0x0
    .byte 0x68
    .byte 27
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_28:
    pushl $0x0
    .byte 0x68
    .byte 28
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_29:
    pushl $0x0
    .byte 0x68
    .byte 29
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_30:
    pushl $0x0
    .byte 0x68
    .byte 30
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_31:
    pushl $0x0
    .byte 0x68
    .byte 31
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_32:
    pushl $0x0
    .byte 0x68
    .byte 32
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_33:
    pushl $0x0
    .byte 0x68
    .byte 33
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_34:
    pushl $0x0
    .byte 0x68
    .byte 34
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_35:
    pushl $0x0
    .byte 0x68
    .byte 35
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_36:
    pushl $0x0
    .byte 0x68
    .byte 36
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_37:
    pushl $0x0
    .byte 0x68
    .byte 37
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_38:
    pushl $0x0
    .byte 0x68
    .byte 38
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_39:
    pushl $0x0
    .byte 0x68
    .byte 39
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_40:
    pushl $0x0
    .byte 0x68
    .byte 40
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_41:
    pushl $0x0
    .byte 0x68
    .byte 41
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_42:
    pushl $0x0
    .byte 0x68
    .byte 42
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_43:
    pushl $0x0
    .byte 0x68
    .byte 43
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_44:
    pushl $0x0
    .byte 0x68
    .byte 44
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_45:
    pushl $0x0
    .byte 0x68
    .byte 45
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_46:
    pushl $0x0
    .byte 0x68
    .byte 46
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_47:
    pushl $0x0
    .byte 0x68
    .byte 47
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_48:
    pushl $0x0
    .byte 0x68
    .byte 48
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_49:
    pushl $0x0
    .byte 0x68
    .byte 49
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_50:
    pushl $0x0
    .byte 0x68
    .byte 50
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_51:
    pushl $0x0
    .byte 0x68
    .byte 51
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_52:
    pushl $0x0
    .byte 0x68
    .byte 52
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_53:
    pushl $0x0
    .byte 0x68
    .byte 53
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_54:
    pushl $0x0
    .byte 0x68
    .byte 54
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_55:
    pushl $0x0
    .byte 0x68
    .byte 55
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_56:
    pushl $0x0
    .byte 0x68
    .byte 56
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_57:
    pushl $0x0
    .byte 0x68
    .byte 57
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_58:
    pushl $0x0
    .byte 0x68
    .byte 58
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_59:
    pushl $0x0
    .byte 0x68
    .byte 59
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_60:
    pushl $0x0
    .byte 0x68
    .byte 60
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_61:
    pushl $0x0
    .byte 0x68
    .byte 61
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_62:
    pushl $0x0
    .byte 0x68
    .byte 62
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_63:
    pushl $0x0
    .byte 0x68
    .byte 63
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_64:
    pushl $0x0
    .byte 0x68
    .byte 64
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_65:
    pushl $0x0
    .byte 0x68
    .byte 65
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_66:
    pushl $0x0
    .byte 0x68
    .byte 66
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_67:
    pushl $0x0
    .byte 0x68
    .byte 67
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_68:
    pushl $0x0
    .byte 0x68
    .byte 0x68
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_69:
    pushl $0x0
    .byte 0x68
    .byte 69
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_70:
    pushl $0x0
    .byte 0x68
    .byte 70
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_71:
    pushl $0x0
    .byte 0x68
    .byte 71
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_72:
    pushl $0x0
    .byte 0x68
    .byte 72
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_73:
    pushl $0x0
    .byte 0x68
    .byte 73
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_74:
    pushl $0x0
    .byte 0x68
    .byte 74
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_75:
    pushl $0x0
    .byte 0x68
    .byte 75
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_76:
    pushl $0x0
    .byte 0x68
    .byte 76
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_77:
    pushl $0x0
    .byte 0x68
    .byte 77
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_78:
    pushl $0x0
    .byte 0x68
    .byte 78
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_79:
    pushl $0x0
    .byte 0x68
    .byte 79
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_80:
    pushl $0x0
    .byte 0x68
    .byte 80
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_81:
    pushl $0x0
    .byte 0x68
    .byte 81
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_82:
    pushl $0x0
    .byte 0x68
    .byte 82
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_83:
    pushl $0x0
    .byte 0x68
    .byte 83
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_84:
    pushl $0x0
    .byte 0x68
    .byte 84
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_85:
    pushl $0x0
    .byte 0x68
    .byte 85
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_86:
    pushl $0x0
    .byte 0x68
    .byte 86
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_87:
    pushl $0x0
    .byte 0x68
    .byte 87
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_88:
    pushl $0x0
    .byte 0x68
    .byte 88
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_89:
    pushl $0x0
    .byte 0x68
    .byte 89
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_90:
    pushl $0x0
    .byte 0x68
    .byte 90
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_91:
    pushl $0x0
    .byte 0x68
    .byte 91
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_92:
    pushl $0x0
    .byte 0x68
    .byte 92
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_93:
    pushl $0x0
    .byte 0x68
    .byte 93
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_94:
    pushl $0x0
    .byte 0x68
    .byte 94
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_95:
    pushl $0x0
    .byte 0x68
    .byte 95
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_96:
    pushl $0x0
    .byte 0x68
    .byte 96
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_97:
    pushl $0x0
    .byte 0x68
    .byte 97
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_98:
    pushl $0x0
    .byte 0x68
    .byte 98
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_99:
    pushl $0x0
    .byte 0x68
    .byte 99
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_100:
    pushl $0x0
    .byte 0x68
    .byte 100
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_101:
    pushl $0x0
    .byte 0x68
    .byte 101
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_102:
    pushl $0x0
    .byte 0x68
    .byte 102
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_103:
    pushl $0x0
    .byte 0x68
    .byte 103
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_104:
    pushl $0x0
    .byte 0x68
    .byte 104
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_105:
    pushl $0x0
    .byte 0x68
    .byte 105
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_106:
    pushl $0x0
    .byte 0x68
    .byte 106
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_107:
    pushl $0x0
    .byte 0x68
    .byte 107
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_108:
    pushl $0x0
    .byte 0x68
    .byte 108
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_109:
    pushl $0x0
    .byte 0x68
    .byte 109
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_110:
    pushl $0x0
    .byte 0x68
    .byte 110
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_111:
    pushl $0x0
    .byte 0x68
    .byte 111
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_112:
    pushl $0x0
    .byte 0x68
    .byte 112
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_113:
    pushl $0x0
    .byte 0x68
    .byte 113
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_114:
    pushl $0x0
    .byte 0x68
    .byte 114
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_115:
    pushl $0x0
    .byte 0x68
    .byte 115
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_116:
    pushl $0x0
    .byte 0x68
    .byte 116
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_117:
    pushl $0x0
    .byte 0x68
    .byte 117
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_118:
    pushl $0x0
    .byte 0x68
    .byte 118
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_119:
    pushl $0x0
    .byte 0x68
    .byte 119
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_120:
    pushl $0x0
    .byte 0x68
    .byte 120
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_121:
    pushl $0x0
    .byte 0x68
    .byte 121
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_122:
    pushl $0x0
    .byte 0x68
    .byte 122
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_123:
    pushl $0x0
    .byte 0x68
    .byte 123
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_124:
    pushl $0x0
    .byte 0x68
    .byte 124
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_125:
    pushl $0x0
    .byte 0x68
    .byte 125
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_126:
    pushl $0x0
    .byte 0x68
    .byte 126
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_127:
    pushl $0x0
    .byte 0x68
    .byte 127
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_128:
    pushl $0x0
    .byte 0x68
    .byte 128
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_129:
    pushl $0x0
    .byte 0x68
    .byte 129
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_130:
    pushl $0x0
    .byte 0x68
    .byte 130
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_131:
    pushl $0x0
    .byte 0x68
    .byte 131
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_132:
    pushl $0x0
    .byte 0x68
    .byte 132
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_133:
    pushl $0x0
    .byte 0x68
    .byte 133
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_134:
    pushl $0x0
    .byte 0x68
    .byte 134
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_135:
    pushl $0x0
    .byte 0x68
    .byte 135
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_136:
    pushl $0x0
    .byte 0x68
    .byte 136
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_137:
    pushl $0x0
    .byte 0x68
    .byte 137
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_138:
    pushl $0x0
    .byte 0x68
    .byte 138
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_139:
    pushl $0x0
    .byte 0x68
    .byte 139
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_140:
    pushl $0x0
    .byte 0x68
    .byte 140
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_141:
    pushl $0x0
    .byte 0x68
    .byte 141
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_142:
    pushl $0x0
    .byte 0x68
    .byte 142
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_143:
    pushl $0x0
    .byte 0x68
    .byte 143
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_144:
    pushl $0x0
    .byte 0x68
    .byte 144
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_145:
    pushl $0x0
    .byte 0x68
    .byte 145
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_146:
    pushl $0x0
    .byte 0x68
    .byte 146
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_147:
    pushl $0x0
    .byte 0x68
    .byte 147
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_148:
    pushl $0x0
    .byte 0x68
    .byte 148
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_149:
    pushl $0x0
    .byte 0x68
    .byte 149
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_150:
    pushl $0x0
    .byte 0x68
    .byte 150
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_151:
    pushl $0x0
    .byte 0x68
    .byte 151
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_152:
    pushl $0x0
    .byte 0x68
    .byte 152
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_153:
    pushl $0x0
    .byte 0x68
    .byte 153
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_154:
    pushl $0x0
    .byte 0x68
    .byte 154
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_155:
    pushl $0x0
    .byte 0x68
    .byte 155
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_156:
    pushl $0x0
    .byte 0x68
    .byte 156
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_157:
    pushl $0x0
    .byte 0x68
    .byte 157
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_158:
    pushl $0x0
    .byte 0x68
    .byte 158
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_159:
    pushl $0x0
    .byte 0x68
    .byte 159
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_160:
    pushl $0x0
    .byte 0x68
    .byte 160
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_161:
    pushl $0x0
    .byte 0x68
    .byte 161
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_162:
    pushl $0x0
    .byte 0x68
    .byte 162
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_163:
    pushl $0x0
    .byte 0x68
    .byte 163
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_164:
    pushl $0x0
    .byte 0x68
    .byte 164
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_165:
    pushl $0x0
    .byte 0x68
    .byte 165
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_166:
    pushl $0x0
    .byte 0x68
    .byte 166
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_167:
    pushl $0x0
    .byte 0x68
    .byte 167
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_168:
    pushl $0x0
    .byte 0x68
    .byte 168
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_169:
    pushl $0x0
    .byte 0x68
    .byte 169
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_170:
    pushl $0x0
    .byte 0x68
    .byte 170
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_171:
    pushl $0x0
    .byte 0x68
    .byte 171
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_172:
    pushl $0x0
    .byte 0x68
    .byte 172
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_173:
    pushl $0x0
    .byte 0x68
    .byte 173
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_174:
    pushl $0x0
    .byte 0x68
    .byte 174
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_175:
    pushl $0x0
    .byte 0x68
    .byte 175
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_176:
    pushl $0x0
    .byte 0x68
    .byte 176
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_177:
    pushl $0x0
    .byte 0x68
    .byte 177
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_178:
    pushl $0x0
    .byte 0x68
    .byte 178
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_179:
    pushl $0x0
    .byte 0x68
    .byte 179
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_180:
    pushl $0x0
    .byte 0x68
    .byte 180
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_181:
    pushl $0x0
    .byte 0x68
    .byte 181
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_182:
    pushl $0x0
    .byte 0x68
    .byte 182
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_183:
    pushl $0x0
    .byte 0x68
    .byte 183
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_184:
    pushl $0x0
    .byte 0x68
    .byte 184
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_185:
    pushl $0x0
    .byte 0x68
    .byte 185
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_186:
    pushl $0x0
    .byte 0x68
    .byte 186
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_187:
    pushl $0x0
    .byte 0x68
    .byte 187
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_188:
    pushl $0x0
    .byte 0x68
    .byte 188
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_189:
    pushl $0x0
    .byte 0x68
    .byte 189
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_190:
    pushl $0x0
    .byte 0x68
    .byte 190
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_191:
    pushl $0x0
    .byte 0x68
    .byte 191
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_192:
    pushl $0x0
    .byte 0x68
    .byte 192
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_193:
    pushl $0x0
    .byte 0x68
    .byte 193
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_194:
    pushl $0x0
    .byte 0x68
    .byte 194
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_195:
    pushl $0x0
    .byte 0x68
    .byte 195
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_196:
    pushl $0x0
    .byte 0x68
    .byte 196
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_197:
    pushl $0x0
    .byte 0x68
    .byte 197
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_198:
    pushl $0x0
    .byte 0x68
    .byte 198
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_199:
    pushl $0x0
    .byte 0x68
    .byte 199
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_200:
    pushl $0x0
    .byte 0x68
    .byte 200
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_201:
    pushl $0x0
    .byte 0x68
    .byte 201
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_202:
    pushl $0x0
    .byte 0x68
    .byte 202
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_203:
    pushl $0x0
    .byte 0x68
    .byte 203
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_204:
    pushl $0x0
    .byte 0x68
    .byte 204
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_205:
    pushl $0x0
    .byte 0x68
    .byte 205
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_206:
    pushl $0x0
    .byte 0x68
    .byte 206
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_207:
    pushl $0x0
    .byte 0x68
    .byte 207
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_208:
    pushl $0x0
    .byte 0x68
    .byte 208
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_209:
    pushl $0x0
    .byte 0x68
    .byte 209
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_210:
    pushl $0x0
    .byte 0x68
    .byte 210
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_211:
    pushl $0x0
    .byte 0x68
    .byte 211
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_212:
    pushl $0x0
    .byte 0x68
    .byte 212
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_213:
    pushl $0x0
    .byte 0x68
    .byte 213
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_214:
    pushl $0x0
    .byte 0x68
    .byte 214
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_215:
    pushl $0x0
    .byte 0x68
    .byte 215
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_216:
    pushl $0x0
    .byte 0x68
    .byte 216
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_217:
    pushl $0x0
    .byte 0x68
    .byte 217
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_218:
    pushl $0x0
    .byte 0x68
    .byte 218
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_219:
    pushl $0x0
    .byte 0x68
    .byte 219
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_220:
    pushl $0x0
    .byte 0x68
    .byte 220
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_221:
    pushl $0x0
    .byte 0x68
    .byte 221
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_222:
    pushl $0x0
    .byte 0x68
    .byte 222
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_223:
    pushl $0x0
    .byte 0x68
    .byte 223
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_224:
    pushl $0x0
    .byte 0x68
    .byte 224
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_225:
    pushl $0x0
    .byte 0x68
    .byte 225
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_226:
    pushl $0x0
    .byte 0x68
    .byte 226
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_227:
    pushl $0x0
    .byte 0x68
    .byte 227
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_228:
    pushl $0x0
    .byte 0x68
    .byte 228
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_229:
    pushl $0x0
    .byte 0x68
    .byte 229
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_230:
    pushl $0x0
    .byte 0x68
    .byte 230
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_231:
    pushl $0x0
    .byte 0x68
    .byte 231
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_232:
    pushl $0x0
    .byte 0x68
    .byte 232
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_233:
    pushl $0x0
    .byte 0x68
    .byte 233
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_234:
    pushl $0x0
    .byte 0x68
    .byte 234
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_235:
    pushl $0x0
    .byte 0x68
    .byte 235
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_236:
    pushl $0x0
    .byte 0x68
    .byte 236
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_237:
    pushl $0x0
    .byte 0x68
    .byte 237
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_238:
    pushl $0x0
    .byte 0x68
    .byte 238
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_239:
    pushl $0x0
    .byte 0x68
    .byte 239
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_240:
    pushl $0x0
    .byte 0x68
    .byte 240
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_241:
    pushl $0x0
    .byte 0x68
    .byte 241
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_242:
    pushl $0x0
    .byte 0x68
    .byte 242
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_243:
    pushl $0x0
    .byte 0x68
    .byte 243
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_244:
    pushl $0x0
    .byte 0x68
    .byte 244
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_245:
    pushl $0x0
    .byte 0x68
    .byte 245
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_246:
    pushl $0x0
    .byte 0x68
    .byte 246
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_247:
    pushl $0x0
    .byte 0x68
    .byte 247
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_248:
    pushl $0x0
    .byte 0x68
    .byte 248
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_249:
    pushl $0x0
    .byte 0x68
    .byte 249
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_250:
    pushl $0x0
    .byte 0x68
    .byte 250
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_251:
    pushl $0x0
    .byte 0x68
    .byte 251
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_252:
    pushl $0x0
    .byte 0x68
    .byte 252
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_253:
    pushl $0x0
    .byte 0x68
    .byte 253
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_254:
    pushl $0x0
    .byte 0x68
    .byte 254
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler

.int_gate_255:
    pushl $0x0
    .byte 0x68
    .byte 255
    .byte 0
    .byte 0
    .byte 0
    jmp interrupt_handler
