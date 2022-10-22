#include <string.h>
#include <stdlib.h>

struct codemap {
        const char *name;
        unsigned char code;
};

static struct codemap modifiers[] = {
        {"LCTRL",  0x01},
        {"LSHIFT", 0x02},
        {"LALT",   0x04},
        {"LMETA",  0x08},
        {"RCTRL",  0x10},
        {"RSHIFT", 0x20},
        {"RALT",   0x40},
        {"RMETA",  0x80},
};

static struct codemap scancodes[] = {
        {"A", 0x04},
        {"B", 0x05},
        {"C", 0x06},
        {"D", 0x07},
        {"E", 0x08},
        {"F", 0x09},
        {"G", 0x0a},
        {"H", 0x0b},
        {"I", 0x0c},
        {"J", 0x0d},
        {"K", 0x0e},
        {"L", 0x0f},
        {"M", 0x10},
        {"N", 0x11},
        {"O", 0x12},
        {"P", 0x13},
        {"Q", 0x14},
        {"R", 0x15},
        {"S", 0x16},
        {"T", 0x17},
        {"U", 0x18},
        {"V", 0x19},
        {"W", 0x1a},
        {"X", 0x1b},
        {"Y", 0x1c},
        {"Z", 0x1d},
        {"1", 0x1e},
        {"2", 0x1f},
        {"3", 0x20},
        {"4", 0x21},
        {"5", 0x22},
        {"6", 0x23},
        {"7", 0x24},
        {"8", 0x25},
        {"9", 0x26},
        {"0", 0x27},

        {"ENTER", 0x28},
        {"ESC", 0x29},
        {"BACKSPACE", 0x2a},
        {"TAB", 0x2b},
        {"SPACE", 0x2c}, {" ", 0x2c},
        {"MINUS", 0x2d}, {"-", 0x2d}, // - and _
        {"EQUAL", 0x2e}, {"=", 0x2e}, // = and +
        {"LEFTBRACE", 0x2f}, {"[", 0x2f},  // [ and {
        {"RIGHTBRACE", 0x30}, {"]", 0x30}, // ] and }
        {"BACKSLASH", 0x31}, {"\\", 0x31},  // \ and |
        {"POUND", 0x32}, {"#", 0x32}, // Non-US # and ~
        {"SEMICOLON", 0x33}, {";", 0x33}, // ; and :
        {"QUOTE", 0x34}, {"'", 0x34}, // ' and "
        {"GRAVE", 0x35}, {"`", 0x35}, // ` and ~
        {"COMMA", 0x36}, {",", 0x36}, // , and <
        {"PERIOD", 0x37}, {".", 0x37}, // . and >
        {"SLASH", 0x38}, {"/", 0x38}, // / and ?
        {"CAPSLOCK", 0x39}, // Caps Lock

        {"F1", 0x3a},
        {"F2", 0x3b},
        {"F3", 0x3c},
        {"F4", 0x3d},
        {"F5", 0x3e},
        {"F6", 0x3f},
        {"F7", 0x40},
        {"F8", 0x41},
        {"F9", 0x42},
        {"F10", 0x43},
        {"F11", 0x44},
        {"F12", 0x45},

        {"PRINTSCREEN", 0x46},
        {"SCROLLLOCK", 0x47},
        {"PAUSE", 0x48},
        {"INSERT", 0x49},
        {"HOME", 0x4a},
        {"PAGEUP", 0x4b},
        {"DELETE", 0x4c},
        {"END", 0x4d},
        {"PAGEDOWN", 0x4e},
        {"RIGHT", 0x4f},
        {"LEFT", 0x50},
        {"DOWN", 0x51},
        {"UP", 0x52},

        {"NUMLOCK", 0x53},
        {"KP/", 0x54}, // Keypad /
        {"KP*", 0x55}, // Keypad *
        {"KP-", 0x56}, // Keypad -
        {"KP+", 0x57}, // Keypad +
        {"KPENTER", 0x58}, // Keypad ENTER
        {"KP1", 0x59}, // Keypad 1 and End
        {"KP2", 0x5a}, // Keypad 2 and Down Arrow
        {"KP3", 0x5b}, // Keypad 3 and PageDn
        {"KP4", 0x5c}, // Keypad 4 and Left Arrow
        {"KP5", 0x5d}, // Keypad 5
        {"KP6", 0x5e}, // Keypad 6 and Right Arrow
        {"KP7", 0x5f}, // Keypad 7 and Home
        {"KP8", 0x60}, // Keypad 8 and Up Arrow
        {"KP9", 0x61}, // Keypad 9 and Page Up
        {"KP0", 0x62}, // Keypad 0 and Insert
        {"KP.", 0x63}, // Keypad . and Delete

        {"\\|", 0x64}, // Non-US \ and |
        {"APPLICATION", 0x65},
        {"POWER", 0x66},
        {"KP=", 0x67}, // Keypad =

        {"F13", 0x68},
        {"F14", 0x69},
        {"F15", 0x6a},
        {"F16", 0x6b},
        {"F17", 0x6c},
        {"F18", 0x6d},
        {"F19", 0x6e},
        {"F20", 0x6f},
        {"F21", 0x70},
        {"F22", 0x71},
        {"F23", 0x72},
        {"F24", 0x73},

        {"OPEN", 0x74}, // Execute
        {"HELP", 0x75},
        {"PROPS", 0x76}, // Menu
        {"FRONT", 0x77}, // Select
        {"STOP", 0x78},
        {"AGAIN", 0x79},
        {"UNDO", 0x7a},
        {"CUT", 0x7b},
        {"COPY", 0x7c},
        {"PASTE", 0x7d},
        {"FIND", 0x7e},
        {"MUTE", 0x7f},
        {"VOLUMEUP", 0x80}, // Volume Up
        {"VOLUMEDOWN", 0x81}, // Volume Down
        {"LKCAPSLOCK", 0x82}, //  Locking Caps Lock
        {"LKNUMLOCK", 0x83}, //  Locking Num Lock
        {"LKSCROLLLOLCK", 0x84}, //  Locking Scroll Lock
        {"KP,", 0x85}, // Keypad Comma
        {"KP=", 0x86}, //  Keypad Equal Sign
        {"INT1", 0x87}, {"_", 0x87}, // International1
        {"INT2", 0x87}, {"KANA", 0x88}, // International2
        {"INT3", 0x87}, {"YEN", 0x89}, // International3
        {"INT4", 0x8a}, {"HENKAN", 0x8a}, // International4
        {"INT5", 0x8b}, {"MUHENKAN", 0x8b}, // International5
        {"INT6", 0x8c}, // International6
        {"INT7", 0x8d}, // International7
        {"INT8", 0x8e}, // International8
        {"INT9", 0x8f}, // International9
        {"LANG1", 0x90}, {"HANGEUL", 0x90},
        {"LANG2", 0x91}, {"HANJA", 0x91},
        {"LANG3", 0x92}, {"KATAKANA", 0x92},
        {"LANG4", 0x93}, {"HIRAGANA", 0x93},
        {"LANG5", 0x94}, {"ZENKAKUHANKAKU", 0x94},
        {"LANG6", 0x95},
        {"LANG7", 0x96},
        {"LANG8", 0x97},
        {"LANG9", 0x98},

        {"ALTERASE", 0x99}, // Alternate Erase
        {"SYSREQ", 0x9a}, // SysReq/Attention
        {"CANCEL", 0x9b}, // Cancel
        {"CLEAR", 0x9c}, // Clear
        {"PRIOR", 0x9d}, // Prior
        {"RETURN", 0x9e}, // Return
        {"SEPARATOR", 0x9f}, // Separator
        {"OUT", 0xa0}, //  Out
        {"OPER", 0xa1}, //  Oper
        {"CLEAR/AGAIN", 0xa2}, //  Clear/Again
        {"CRSEL", 0xa3}, //  CrSel/Props
        {"EXSEL", 0xa4}, //  ExSel

        {"00", 0xb0}, // Keypad 00
        {"000", 0xb1}, // Keypad 000
        {"THOUSANDSSEPARATOR", 0xb2}, // Thousands Separator
        {"DECIMALSEPARATOR", 0xb3}, // Decimal Separator
        {"CURRENCYUNIT", 0xb4}, // Currency Unit
        {"CURRENCYSUBUNIT", 0xb5}, // Currency Sub-unit
        {"KP(", 0xb6}, // Keypad (
        {"KP)", 0xb7}, // Keypad )
        {"KP{", 0xb8}, //  Keypad {
        {"KP}", 0xb9}, // Keypad }
        {"KPTAB", 0xba}, // Keypad Tab
        {"KPBACKSPACE", 0xbb}, // Keypad Backspace
        {"KPA", 0xbc}, // Keypad A
        {"KPB", 0xbd}, // Keypad B
        {"KPC", 0xbe}, // Keypad C
        {"KPD", 0xbf}, // Keypad D
        {"KPE", 0xc0}, // Keypad E
        {"KPF", 0xc1}, // Keypad F
        {"KPXOR", 0xc2}, // Keypad XOR
        {"KP^", 0xc3}, // Keypad ^
        {"KP%", 0xc4}, // Keypad %
        {"KP<", 0xc5}, // Keypad <
        {"KP>", 0xc6}, // Keypad >
        {"KP&", 0xc7}, // Keypad &
        {"KP&&", 0xc8}, // Keypad &&
        {"KP|", 0xc9}, // Keypad |
        {"KP||", 0xca}, // Keypad ||
        {"KP:", 0xcb}, // Keypad :
        {"KP#", 0xcc}, // Keypad #
        {"KPSPACE", 0xcd}, // Keypad Space
        {"KP@", 0xce}, // Keypad @
        {"KP!", 0xcf}, // Keypad !
        {"KPMS", 0xd0}, // Keypad Memory Store
        {"KPMR", 0xd1}, // Keypad Memory Recall
        {"KPMC", 0xd2}, // Keypad Memory Clear
        {"KPM+", 0xd3}, // Keypad Memory Add
        {"KPM-", 0xd4}, // Keypad Memory Subtract
        {"KPM*", 0xd5}, // Keypad Memory Multiply
        {"KPM/", 0xd6}, // Keypad Memory Divide
        {"KP+-", 0xd7}, // Keypad +/-
        {"KPCLEAR", 0xd8}, // Keypad Clear
        {"KPCLEARENTRY", 0xd9}, // Keypad Clear Entry
        {"KPBIN", 0xda}, // Keypad Binary
        {"KPOCT", 0xdb}, // Keypad Octal
        {"KPDEC", 0xdc}, // Keypad Decimal
        {"KPHEX", 0xdd}, // Keypad Hexadecimal

        {"LEFTCTRL", 0xe0}, // Left Control
        {"LEFTSHIFT", 0xe1}, // Left Shift
        {"LEFTALT", 0xe2}, // Left Alt
        {"LEFTMETA", 0xe3}, // Left GUI
        {"RIGHTCTRL", 0xe4}, // Right Control
        {"RIGHTSHIFT", 0xe5}, // Right Shift
        {"RIGHTALT", 0xe6}, // Right Alt
        {"RIGHTMETA", 0xe7}, // Right GUI

        {"MEDIAPLAYPAUSE", 0xe8},
        {"MEDIASTOPCD", 0xe9},
        {"MEDIAPREVIOUSSONG", 0xea},
        {"MEDIANEXTSONG", 0xeb},
        {"MEDIAEJECTCD", 0xec},
        {"MEDIAVOLUMEUP", 0xed},
        {"MEDIAVOLUMEDOWN", 0xee},
        {"MEDIAMUTE", 0xef},
        {"MEDIAWWW", 0xf0},
        {"MEDIABACK", 0xf1},
        {"MEDIAFORWARD", 0xf2},
        {"MEDIASTOP", 0xf3},
        {"MEDIAFIND", 0xf4},
        {"MEDIASCROLLUP", 0xf5},
        {"MEDIASCROLLDOWN", 0xf6},
        {"MEDIAEDIT", 0xf7},
        {"MEDIASLEEP", 0xf8},
        {"MEDIACOFFEE", 0xf9},
        {"MEDIAREFRESH", 0xfa},
        {"MEDIACALC", 0xfb},
};

unsigned char get_modifier_bitmask(const char *name)
{
        for (int i = 0; i < sizeof(modifiers) / sizeof(modifiers[0]); i++) {
                if (strcasecmp(name, modifiers[i].name) == 0) {
                        return modifiers[i].code;
                }
        }
        return 0;
}

unsigned char get_scan_code(const char *name)
{
        if (name[0] == '#') {
                return atoi(name + 1) & 0xff;
        }
        for (int i = 0; i < sizeof(scancodes) / sizeof(scancodes[0]); i++) {
                if (strcasecmp(name, scancodes[i].name) == 0) {
                        return scancodes[i].code;
                }
        }
        return 0;
}
