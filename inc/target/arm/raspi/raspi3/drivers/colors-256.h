#ifndef __COLORS256_H_
#define __COLORS256_H_

#include "kernel/def/typedef.h"
#include "kernel/def/keyword.h"

struct colors256Xterm_t
{
    char const *s;
    u8_t id;
    u32_t hex;
} __packed;

/* enum colors256XtermEnum */
#define Black  0
#define Maroon  1
#define Green  2
#define Olive  3
#define Navy  4
#define Purple  5
#define Teal  6
#define Silver  7
#define Grey  8
#define Red  9
#define Lime  10
#define Yellow  11
#define Blue  12
#define Fuchsia  13
#define Aqua  14
#define White  15
#define Grey0  16
#define NavyBlue  17
#define DarkBlue  18
// #define Blue3  19
// #define Blue3  20
// #define Blue1  21
#define DarkGreen  22
// #define DeepSkyBlue4  23
// #define DeepSkyBlue4  24
// #define DeepSkyBlue4  25
// #define DodgerBlue3  26
// #define DodgerBlue2  27
// #define Green4  28
// #define SpringGreen4  29
// #define Turquoise4  30
// #define DeepSkyBlue3  31
// #define DeepSkyBlue3  32
// #define DodgerBlue1  33
// #define Green3  34
// #define SpringGreen3  35
#define DarkCyan  36
#define LightSeaGreen  37
// #define DeepSkyBlue2  38
// #define DeepSkyBlue1  39
// #define Green3  40
// #define SpringGreen3  41
// #define SpringGreen2  42
// #define Cyan3  43
#define DarkTurquoise  44
// #define Turquoise2  45
// #define Green1  46
// #define SpringGreen2  47
// #define SpringGreen1  48
#define MediumSpringGreen  49
// #define Cyan2  50
// #define Cyan1  51
#define DarkRed  52
// #define DeepPink4  53
// #define Purple4  54
// #define Purple4  55
// #define Purple3  56
#define BlueViolet  57
// #define Orange4  58
#define Grey37  59
// #define MediumPurple4  60
// #define SlateBlue3  61
// #define SlateBlue3  62
// #define RoyalBlue1  63
// #define Chartreuse4  64
// #define DarkSeaGreen4  65
// #define PaleTurquoise4  66
#define SteelBlue  67
// #define SteelBlue3  68
#define CornflowerBlue  69
// #define Chartreuse3  70
// #define DarkSeaGreen4  71
#define CadetBlue  72
// #define CadetBlue  73
// #define SkyBlue3  74
// #define SteelBlue1  75
// #define Chartreuse3  76
// #define PaleGreen3  77
// #define SeaGreen3  78
// #define Aquamarine3  79
#define MediumTurquoise  80
// #define SteelBlue1  81
// #define Chartreuse2  82
// #define SeaGreen2  83
// #define SeaGreen1  84
// #define SeaGreen1  85
// #define Aquamarine1  86
// #define DarkSlateGray2  87
// #define DarkRed  88
// #define DeepPink4  89
// #define DarkMagenta  90
#define DarkMagenta  91
#define DarkViolet  92
// #define Purple  93
// #define Orange4  94
// #define LightPink4  95
// #define Plum4  96
// #define MediumPurple3  97
// #define MediumPurple3  98
// #define SlateBlue1  99
// #define Yellow4  100
// #define Wheat4  101
// #define Grey53  102
// #define LightSlateGrey  103
#define MediumPurple  104
#define LightSlateBlue  105
// #define Yellow4  106
// #define DarkOliveGreen3  107
#define DarkSeaGreen  108
// #define LightSkyBlue3  109
// #define LightSkyBlue3  110
// #define SkyBlue2  111
// #define Chartreuse2  112
// #define DarkOliveGreen3  113
// #define PaleGreen3  114
// #define DarkSeaGreen3  115
// #define DarkSlateGray3  116
// #define SkyBlue1  117
// #define Chartreuse1  118
// #define LightGreen  119
#define LightGreen  120
// #define PaleGreen1  121
// #define Aquamarine1  122
// #define DarkSlateGray1  123
// #define Red3  124
// #define DeepPink4  125
#define MediumVioletRed  126
// #define Magenta3  127
// #define DarkViolet  128
// #define Purple  129
// #define DarkOrange3  130
#define IndianRed  131
// #define HotPink3  132
// #define MediumOrchid3  133
#define MediumOrchid  134
// #define MediumPurple2  135
#define DarkGoldenrod  136
// #define LightSalmon3  137
#define RosyBrown  138
// #define Grey63  139
// #define MediumPurple2  140
// #define MediumPurple1  141
// #define Gold3  142
#define DarkKhaki  143
// #define NavajoWhite3  144
#define Grey69  145
// #define LightSteelBlue3  146
#define LightSteelBlue  147
// #define Yellow3  148
// #define DarkOliveGreen3  149
// #define DarkSeaGreen3  150
// #define DarkSeaGreen2  151
// #define LightCyan3  152
// #define LightSkyBlue1  153
#define GreenYellow  154
// #define DarkOliveGreen2  155
// #define PaleGreen1  156
// #define DarkSeaGreen2  157
// #define DarkSeaGreen1  158
// #define PaleTurquoise1  159
// #define Red3  160
// #define DeepPink3  161
// #define DeepPink3  162
// #define Magenta3  163
// #define Magenta3  164
// #define Magenta2  165
// #define DarkOrange3  166
// #define IndianRed  167
// #define HotPink3  168
// #define HotPink2  169
#define Orchid  170
// #define MediumOrchid1  171
// #define Orange3  172
// #define LightSalmon3  173
// #define LightPink3  174
// #define Pink3  175
// #define Plum3  176
#define Violet  177
// #define Gold3  178
// #define LightGoldenrod3  179
#define Tan  180
// #define MistyRose3  181
// #define Thistle3  182
// #define Plum2  183
// #define Yellow3  184
// #define Khaki3  185
// #define LightGoldenrod2  186
// #define LightYellow3  187
// #define Grey84  188
// #define LightSteelBlue1  189
// #define Yellow2  190
// #define DarkOliveGreen1  191
// #define DarkOliveGreen1  192
// #define DarkSeaGreen1  193
// #define Honeydew2  194
// #define LightCyan1  195
// #define Red1  196
// #define DeepPink2  197
// #define DeepPink1  198
// #define DeepPink1  199
// #define Magenta2  200
// #define Magenta1  201
// #define OrangeRed1  202
// #define IndianRed1  203
// #define IndianRed1  204
// #define HotPink  205
#define HotPink  206
// #define MediumOrchid1  207
#define DarkOrange  208
// #define Salmon1  209
#define LightCoral  210
// #define PaleVioletRed1  211
// #define Orchid2  212
// #define Orchid1  213
// #define Orange1  214
#define SandyBrown  215
// #define LightSalmon1  216
// #define LightPink1  217
// #define Pink1  218
// #define Plum1  219
// #define Gold1  220
// #define LightGoldenrod2  221
// #define LightGoldenrod2  222
// #define NavajoWhite1  223
// #define MistyRose1  224
// #define Thistle1  225
// #define Yellow1  226
// #define LightGoldenrod1  227
// #define Khaki1  228
// #define Wheat1  229
// #define Cornsilk1  230
#define Grey100  231
// #define Grey3  232
#define Grey7  233
// #define Grey11  234
#define Grey15  235
#define Grey19  236
// #define Grey23  237
#define Grey27  238
#define Grey30  239
#define Grey35  240
#define Grey39  241
// #define Grey42  242
#define Grey46  243
#define Grey50  244
// #define Grey54  245
#define Grey58  246
// #define Grey62  247
#define Grey66  248
#define Grey70  249
// #define Grey74  250
#define Grey78  251
// #define Grey82  252
#define Grey85  253
#define Grey89  254
// #define Grey93  255


#define _RGB256toESCFRT(x) "\e[38;5;"#x"m"
#define _RGB256toESCBCK(x) "\e[48;5;"#x"m"

#define RGB256toESCFRT(x) _RGB256toESCFRT(x)
#define RGB256toESCBCK(x) _RGB256toESCBCK(x)

#define RGB256_TO_HEX(r, g, b) ((r << 16) + (g << 8) + (b))
#define BGR256_TO_HEX(b, g, r) ((b << 16) + (g << 8) + (r))
#define GRB256_TO_HEX(g, t, b) ((g << 16) + (r << 8) + (b))
#define BRG256_TO_HEX(b, r, g) ((b << 16) + (r << 8) + (g))

#endif