#ifndef _TINYMAX7219_H_
#define _TINYMAX7219_H_

#ifdef __AVR__
	#include <avr/pgmspace.h>
#elif defined(ESP8266) || defined(ESP32)
	#include <pgmspace.h>
#endif

#define ________    0x00
#define _______X    0x01
#define ______X_    0x02
#define ______XX    0x03
#define _____X__    0x04
#define _____X_X    0x05
#define _____XX_    0x06
#define _____XXX    0x07
#define ____X___    0x08
#define ____X__X    0x09
#define ____X_X_    0x0a
#define ____X_XX    0x0b
#define ____XX__    0x0c
#define ____XX_X    0x0d
#define ____XXX_    0x0e
#define ____XXXX    0x0f
#define ___X____    0x10
#define ___X___X    0x11
#define ___X__X_    0x12
#define ___X__XX    0x13
#define ___X_X__    0x14
#define ___X_X_X    0x15
#define ___X_XX_    0x16
#define ___X_XXX    0x17
#define ___XX___    0x18
#define ___XX__X    0x19
#define ___XX_X_    0x1a
#define ___XX_XX    0x1b
#define ___XXX__    0x1c
#define ___XXX_X    0x1d
#define ___XXXX_    0x1e
#define ___XXXXX    0x1f
#define __X_____    0x20
#define __X____X    0x21
#define __X___X_    0x22
#define __X___XX    0x23
#define __X__X__    0x24
#define __X__X_X    0x25
#define __X__XX_    0x26
#define __X__XXX    0x27
#define __X_X___    0x28
#define __X_X__X    0x29
#define __X_X_X_    0x2a
#define __X_X_XX    0x2b
#define __X_XX__    0x2c
#define __X_XX_X    0x2d
#define __X_XXX_    0x2e
#define __X_XXXX    0x2f
#define __XX____    0x30
#define __XX___X    0x31
#define __XX__X_    0x32
#define __XX__XX    0x33
#define __XX_X__    0x34
#define __XX_X_X    0x35
#define __XX_XX_    0x36
#define __XX_XXX    0x37
#define __XXX___    0x38
#define __XXX__X    0x39
#define __XXX_X_    0x3a
#define __XXX_XX    0x3b
#define __XXXX__    0x3c
#define __XXXX_X    0x3d
#define __XXXXX_    0x3e
#define __XXXXXX    0x3f
#define _X______    0x40
#define _X_____X    0x41
#define _X____X_    0x42
#define _X____XX    0x43
#define _X___X__    0x44
#define _X___X_X    0x45
#define _X___XX_    0x46
#define _X___XXX    0x47
#define _X__X___    0x48
#define _X__X__X    0x49
#define _X__X_X_    0x4a
#define _X__X_XX    0x4b
#define _X__XX__    0x4c
#define _X__XX_X    0x4d
#define _X__XXX_    0x4e
#define _X__XXXX    0x4f
#define _X_X____    0x50
#define _X_X___X    0x51
#define _X_X__X_    0x52
#define _X_X__XX    0x53
#define _X_X_X__    0x54
#define _X_X_X_X    0x55
#define _X_X_XX_    0x56
#define _X_X_XXX    0x57
#define _X_XX___    0x58
#define _X_XX__X    0x59
#define _X_XX_X_    0x5a
#define _X_XX_XX    0x5b
#define _X_XXX__    0x5c
#define _X_XXX_X    0x5d
#define _X_XXXX_    0x5e
#define _X_XXXXX    0x5f
#define _XX_____    0x60
#define _XX____X    0x61
#define _XX___X_    0x62
#define _XX___XX    0x63
#define _XX__X__    0x64
#define _XX__X_X    0x65
#define _XX__XX_    0x66
#define _XX__XXX    0x67
#define _XX_X___    0x68
#define _XX_X__X    0x69
#define _XX_X_X_    0x6a
#define _XX_X_XX    0x6b
#define _XX_XX__    0x6c
#define _XX_XX_X    0x6d
#define _XX_XXX_    0x6e
#define _XX_XXXX    0x6f
#define _XXX____    0x70
#define _XXX___X    0x71
#define _XXX__X_    0x72
#define _XXX__XX    0x73
#define _XXX_X__    0x74
#define _XXX_X_X    0x75
#define _XXX_XX_    0x76
#define _XXX_XXX    0x77
#define _XXXX___    0x78
#define _XXXX__X    0x79
#define _XXXX_X_    0x7a
#define _XXXX_XX    0x7b
#define _XXXXX__    0x7c
#define _XXXXX_X    0x7d
#define _XXXXXX_    0x7e
#define _XXXXXXX    0x7f
#define X_______    0x80
#define X______X    0x81
#define X_____X_    0x82
#define X_____XX    0x83
#define X____X__    0x84
#define X____X_X    0x85
#define X____XX_    0x86
#define X____XXX    0x87
#define X___X___    0x88
#define X___X__X    0x89
#define X___X_X_    0x8a
#define X___X_XX    0x8b
#define X___XX__    0x8c
#define X___XX_X    0x8d
#define X___XXX_    0x8e
#define X___XXXX    0x8f
#define X__X____    0x90
#define X__X___X    0x91
#define X__X__X_    0x92
#define X__X__XX    0x93
#define X__X_X__    0x94
#define X__X_X_X    0x95
#define X__X_XX_    0x96
#define X__X_XXX    0x97
#define X__XX___    0x98
#define X__XX__X    0x99
#define X__XX_X_    0x9a
#define X__XX_XX    0x9b
#define X__XXX__    0x9c
#define X__XXX_X    0x9d
#define X__XXXX_    0x9e
#define X__XXXXX    0x9f
#define X_X_____    0xa0
#define X_X____X    0xa1
#define X_X___X_    0xa2
#define X_X___XX    0xa3
#define X_X__X__    0xa4
#define X_X__X_X    0xa5
#define X_X__XX_    0xa6
#define X_X__XXX    0xa7
#define X_X_X___    0xa8
#define X_X_X__X    0xa9
#define X_X_X_X_    0xaa
#define X_X_X_XX    0xab
#define X_X_XX__    0xac
#define X_X_XX_X    0xad
#define X_X_XXX_    0xae
#define X_X_XXXX    0xaf
#define X_XX____    0xb0
#define X_XX___X    0xb1
#define X_XX__X_    0xb2
#define X_XX__XX    0xb3
#define X_XX_X__    0xb4
#define X_XX_X_X    0xb5
#define X_XX_XX_    0xb6
#define X_XX_XXX    0xb7
#define X_XXX___    0xb8
#define X_XXX__X    0xb9
#define X_XXX_X_    0xba
#define X_XXX_XX    0xbb
#define X_XXXX__    0xbc
#define X_XXXX_X    0xbd
#define X_XXXXX_    0xbe
#define X_XXXXXX    0xbf
#define XX______    0xc0
#define XX_____X    0xc1
#define XX____X_    0xc2
#define XX____XX    0xc3
#define XX___X__    0xc4
#define XX___X_X    0xc5
#define XX___XX_    0xc6
#define XX___XXX    0xc7
#define XX__X___    0xc8
#define XX__X__X    0xc9
#define XX__X_X_    0xca
#define XX__X_XX    0xcb
#define XX__XX__    0xcc
#define XX__XX_X    0xcd
#define XX__XXX_    0xce
#define XX__XXXX    0xcf
#define XX_X____    0xd0
#define XX_X___X    0xd1
#define XX_X__X_    0xd2
#define XX_X__XX    0xd3
#define XX_X_X__    0xd4
#define XX_X_X_X    0xd5
#define XX_X_XX_    0xd6
#define XX_X_XXX    0xd7
#define XX_XX___    0xd8
#define XX_XX__X    0xd9
#define XX_XX_X_    0xda
#define XX_XX_XX    0xdb
#define XX_XXX__    0xdc
#define XX_XXX_X    0xdd
#define XX_XXXX_    0xde
#define XX_XXXXX    0xdf
#define XXX_____    0xe0
#define XXX____X    0xe1
#define XXX___X_    0xe2
#define XXX___XX    0xe3
#define XXX__X__    0xe4
#define XXX__X_X    0xe5
#define XXX__XX_    0xe6
#define XXX__XXX    0xe7
#define XXX_X___    0xe8
#define XXX_X__X    0xe9
#define XXX_X_X_    0xea
#define XXX_X_XX    0xeb
#define XXX_XX__    0xec
#define XXX_XX_X    0xed
#define XXX_XXX_    0xee
#define XXX_XXXX    0xef
#define XXXX____    0xf0
#define XXXX___X    0xf1
#define XXXX__X_    0xf2
#define XXXX__XX    0xf3
#define XXXX_X__    0xf4
#define XXXX_X_X    0xf5
#define XXXX_XX_    0xf6
#define XXXX_XXX    0xf7
#define XXXXX___    0xf8
#define XXXXX__X    0xf9
#define XXXXX_X_    0xfa
#define XXXXX_XX    0xfb
#define XXXXXX__    0xfc
#define XXXXXX_X    0xfd
#define XXXXXXX_    0xfe
#define XXXXXXXX    0xff

const uint8_t __font6x8[] PROGMEM {
_X_X____,
________,
XXXXX___,
X_______,
XXXX____,
X_______,
XXXXX___,
________,
_X_X____,
//
________,
_XXX____,
X___X___,
XXXXX___,
X_______,
_XXX____,
________,
//
X_______,
XXX_____,
XXXX____,
XXXXX___,
XXXX____,
XXX_____,
X_______,
________,
// 0x20
________,
________,
________,
________,
________,
________,
________,
________,
// 0x21
__X_____,
__X_____,
__X_____,
__X_____,
__X_____,
________,
__X_____,
________,
// 0x22
_X__X___,
_X__X___,
_X__X___,
________,
________,
________,
________,
________,
// 0x23
_X_X____,
_X_X____,
XXXXX___,
_X_X____,
XXXXX___,
_X_X____,
_X_X____,
________,
// 0x24
__X_____,
_XXXX___,
X_X_____,
_XXX____,
__X_X___,
XXXX____,
__X_____,
________,
// 0x25
XX______,
XX__X___,
___X____,
__X_____,
_X______,
X__XX___,
___XX___,
________,
// 0x26
_XX_____,
X__X____,
X_X_____,
_X______,
X_X_X___,
X__X____,
_XX_X___,
________,
// 0x27
_XX_____,
__X_____,
_X______,
________,
________,
________,
________,
________,
// 0x28
___X____,
__X_____,
_X______,
_X______,
_X______,
__X_____,
___X____,
________,
// 0x29
_X______,
__X_____,
___X____,
___X____,
___X____,
__X_____,
_X______,
________,
// 0x2A
________,
_X_X____,
__X_____,
XXXXX___,
__X_____,
_X_X____,
________,
________,
// 0x2B
________,
__X_____,
__X_____,
XXXXX___,
__X_____,
__X_____,
________,
________,
// 0x2C
________,
________,
________,
________,
________,
_XX_____,
__X_____,
_X______,
// 0x2D
________,
________,
________,
XXXXX___,
________,
________,
________,
________,
// 0x2E
________,
________,
________,
________,
________,
_XX_____,
_XX_____,
________,
// 0x2F
________,
____X___,
___X____,
__X_____,
_X______,
X_______,
________,
________,
// 0x30
_XXX____,
X___X___,
X__XX___,
X_X_X___,
XX__X___,
X___X___,
_XXX____,
________,
// 0x31
__X_____,
_XX_____,
__X_____,
__X_____,
__X_____,
__X_____,
_XXX____,
________,
// 0x32
_XXX____,
X___X___,
____X___,
__XX____,
_X______,
X_______,
XXXXX___,
________,
// 0x33
_XXX____,
X___X___,
____X___,
__XX____,
____X___,
X___X___,
_XXX____,
________,
// 0x34
___X____,
__XX____,
_X_X____,
X__X____,
XXXXX___,
___X____,
___X____,
________,
// 0x35
XXXXX___,
X_______,
XXXX____,
____X___,
____X___,
X___X___,
_XXX____,
________,
// 0x36
__XX____,
_X______,
X_______,
XXXX____,
X___X___,
X___X___,
_XXX____,
________,
// 0x37
XXXXX___,
____X___,
___X____,
__X_____,
_X______,
_X______,
_X______,
________,
// 0x38
_XXX____,
X___X___,
X___X___,
_XXX____,
X___X___,
X___X___,
_XXX____,
________,
// 0x39
_XXX____,
X___X___,
X___X___,
_XXXX___,
____X___,
___X____,
_XX_____,
________,
// 0x3A
________,
_XX_____,
_XX_____,
________,
_XX_____,
_XX_____,
________,
________,
// 0x3B
________,
________,
_XX_____,
_XX_____,
________,
_XX_____,
__X_____,
_X______,
// 0x3C
___X____,
__X_____,
_X______,
X_______,
_X______,
__X_____,
___X____,
________,
// 0x3D
________,
________,
XXXXX___,
________,
XXXXX___,
________,
________,
________,
// 0x3E
X_______,
_X______,
__X_____,
___X____,
__X_____,
_X______,
X_______,
________,
// 0x3F
_XXX____,
X___X___,
____X___,
___X____,
__X_____,
________,
__X_____,
________,
// 0x40
_XXX____,
X___X___,
____X___,
_XX_X___,
X_X_X___,
X_X_X___,
_XXX____,
________,
// 0x41
_XXX____,
X___X___,
X___X___,
XXXXX___,
X___X___,
X___X___,
X___X___,
________,
// 0x42
XXXX____,
X___X___,
X___X___,
XXXX____,
X___X___,
X___X___,
XXXX____,
________,
// 0x43
_XXX____,
X___X___,
X_______,
X_______,
X_______,
X___X___,
_XXX____,
________,
// 0x44
XXX_____,
X__X____,
X___X___,
X___X___,
X___X___,
X__X____,
XXX_____,
________,
// 0x45
XXXXX___,
X_______,
X_______,
XXXX____,
X_______,
X_______,
XXXXX___,
________,
// 0x46
XXXXX___,
X_______,
X_______,
XXXX____,
X_______,
X_______,
X_______,
________,
// 0x47
_XXX____,
X___X___,
X_______,
X_______,
X__XX___,
X___X___,
_XXXX___,
________,
// 0x48
X___X___,
X___X___,
X___X___,
XXXXX___,
X___X___,
X___X___,
X___X___,
________,
// 0x49
_XXX____,
__X_____,
__X_____,
__X_____,
__X_____,
__X_____,
_XXX____,
________,
// 0x4A
__XXX___,
___X____,
___X____,
___X____,
___X____,
X__X____,
_XX_____,
________,
// 0x4B
X___X___,
X__X____,
X_X_____,
XX______,
X_X_____,
X__X____,
X___X___,
________,
// 0x4C
X_______,
X_______,
X_______,
X_______,
X_______,
X_______,
XXXXX___,
________,
// 0x4D
X___X___,
XX_XX___,
X_X_X___,
X_X_X___,
X___X___,
X___X___,
X___X___,
________,
// 0x4E
X___X___,
X___X___,
XX__X___,
X_X_X___,
X__XX___,
X___X___,
X___X___,
________,
// 0x4F
_XXX____,
X___X___,
X___X___,
X___X___,
X___X___,
X___X___,
_XXX____,
________,
// 0x50
XXXX____,
X___X___,
X___X___,
XXXX____,
X_______,
X_______,
X_______,
________,
// 0x51
_XXX____,
X___X___,
X___X___,
X___X___,
X_X_X___,
X__X____,
_XX_X___,
________,
// 0x52
XXXX____,
X___X___,
X___X___,
XXXX____,
X_X_____,
X__X____,
X___X___,
________,
// 0x53
_XXX____,
X___X___,
X_______,
_XXX____,
____X___,
X___X___,
_XXX____,
________,
// 0x54
XXXXX___,
__X_____,
__X_____,
__X_____,
__X_____,
__X_____,
__X_____,
________,
// 0x55
X___X___,
X___X___,
X___X___,
X___X___,
X___X___,
X___X___,
_XXX____,
________,
// 0x56
X___X___,
X___X___,
X___X___,
X___X___,
X___X___,
_X_X____,
__X_____,
________,
// 0x57
X___X___,
X___X___,
X___X___,
X_X_X___,
X_X_X___,
X_X_X___,
_X_X____,
________,
// 0x58
X___X___,
X___X___,
_X_X____,
__X_____,
_X_X____,
X___X___,
X___X___,
________,
// 0x59
X___X___,
X___X___,
X___X___,
_X_X____,
__X_____,
__X_____,
__X_____,
________,
// 0x5A
XXXXX___,
____X___,
___X____,
__X_____,
_X______,
X_______,
XXXXX___,
________,
// 0x5B
_XXX____,
_X______,
_X______,
_X______,
_X______,
_X______,
_XXX____,
________,
// 0x5C
________,
X_______,
_X______,
__X_____,
___X____,
____X___,
________,
________,
// 0x5D
_XXX____,
___X____,
___X____,
___X____,
___X____,
___X____,
_XXX____,
________,
// 0x5E
__X_____,
_X_X____,
X___X___,
________,
________,
________,
________,
________,
// 0x5F
________,
________,
________,
________,
________,
________,
________,
XXXXX___,
// 0x60
_X______,
__X_____,
___X____,
________,
________,
________,
________,
________,
// 0x61
________,
________,
_XXX____,
____X___,
_XXXX___,
X___X___,
_XXXX___,
________,
// 0x62
X_______,
X_______,
X_XX____,
XX__X___,
X___X___,
X___X___,
XXXX____,
________,
// 0x63
________,
________,
_XXX____,
X_______,
X_______,
X___X___,
_XXX____,
________,
// 0x64
____X___,
____X___,
_XX_X___,
X__XX___,
X___X___,
X___X___,
_XXXX___,
________,
// 0x65
________,
________,
_XXX____,
X___X___,
XXXXX___,
X_______,
_XXX____,
________,
// 0x66
__XX____,
_X__X___,
_X______,
XXX_____,
_X______,
_X______,
_X______,
________,
// 0x67
________,
________,
_XXXX___,
X___X___,
X___X___,
_XXXX___,
____X___,
_XXX____,
// 0x68
X_______,
X_______,
X_XX____,
XX__X___,
X___X___,
X___X___,
X___X___,
________,
// 0x69
__X_____,
________,
_XX_____,
__X_____,
__X_____,
__X_____,
_XXX____,
________,
// 0x6A
___X____,
________,
__XX____,
___X____,
___X____,
___X____,
X__X____,
_XX_____,
// 0x6B
X_______,
X_______,
X__X____,
X_X_____,
XX______,
X_X_____,
X__X____,
________,
// 0x6C
_XX_____,
__X_____,
__X_____,
__X_____,
__X_____,
__X_____,
_XXX____,
________,
// 0x6D
________,
________,
XX_X____,
X_X_X___,
X___X___,
X___X___,
X___X___,
________,
// 0x6E
________,
________,
X_XX____,
XX__X___,
X___X___,
X___X___,
X___X___,
________,
// 0x6F
________,
________,
_XXX____,
X___X___,
X___X___,
X___X___,
_XXX____,
________,
// 0x70
________,
________,
XXXX____,
X___X___,
X___X___,
XXXX____,
X_______,
X_______,
// 0x71
________,
________,
_XXXX___,
X___X___,
X___X___,
_XXXX___,
____X___,
____X___,
// 0x72
________,
________,
X_XX____,
XX__X___,
X_______,
X_______,
X_______,
________,
// 0x73
________,
________,
_XXXX___,
X_______,
_XXX____,
____X___,
XXXX____,
________,
// 0x74
_X______,
_X______,
XXX_____,
_X______,
_X______,
_X__X___,
__XX____,
________,
// 0x75
________,
________,
X___X___,
X___X___,
X___X___,
X__XX___,
_XX_X___,
________,
// 0x76
________,
________,
X___X___,
X___X___,
X___X___,
_X_X____,
__X_____,
________,
// 0x77
________,
________,
X___X___,
X___X___,
X_X_X___,
X_X_X___,
_X_X____,
________,
// 0x78
________,
________,
X___X___,
_X_X____,
__X_____,
_X_X____,
X___X___,
________,
// 0x79
________,
________,
X___X___,
X___X___,
X___X___,
_XXXX___,
____X___,
_XXX____,
// 0x7A
________,
________,
XXXXX___,
___X____,
__X_____,
_X______,
XXXXX___,
________,
// 0x7B
___X____,
__X_____,
__X_____,
_X______,
__X_____,
__X_____,
___X____,
________,
// 0x7C
__X_____,
__X_____,
__X_____,
__X_____,
__X_____,
__X_____,
__X_____,
________,
// 0x7D
_X______,
__X_____,
__X_____,
___X____,
__X_____,
__X_____,
_X______,
________,
// 0x7E
_XX_X___,
X__X____,
________,
________,
________,
________,
________,
________,
// 0x7F *********************

// 0xC0
_XXX____,
X___X___,
X___X___,
XXXXX___,
X___X___,
X___X___,
X___X___,
________,
// 0xC1
XXXXX___,
X_______,
X_______,
XXXX____,
X___X___,
X___X___,
XXXX____,
________,
// 0xC2
XXXX____,
X___X___,
X___X___,
XXXX____,
X___X___,
X___X___,
XXXX____,
________,
// 0xC3
XXXXX___,
X_______,
X_______,
X_______,
X_______,
X_______,
X_______,
________,
// 0xC4
__XX____,
_X_X____,
_X_X____,
_X_X____,
_X_X____,
XXXXX___,
X___X___,
________,
// 0xC5
XXXXX___,
X_______,
X_______,
XXXX____,
X_______,
X_______,
XXXXX___,
________,
// 0xC6
X_X_X___,
X_X_X___,
X_X_X___,
_XXX____,
X_X_X___,
X_X_X___,
X_X_X___,
________,
// 0xC7
_XXX____,
X___X___,
____X___,
___X____,
____X___,
X___X___,
_XXX____,
________,
// 0xC8
X___X___,
X___X___,
X__XX___,
X_X_X___,
XX__X___,
X___X___,
X___X___,
________,
// 0xC9
X_X_X___,
X___X___,
X__XX___,
X_X_X___,
XX__X___,
X___X___,
X___X___,
________,
// 0xCA
X___X___,
X___X___,
X__X____,
XXX_____,
X__X____,
X___X___,
X___X___,
________,
// 0xCB
__XXX___,
_X__X___,
X___X___,
X___X___,
X___X___,
X___X___,
X___X___,
________,
// 0xCC
X___X___,
XX_XX___,
XX_XX___,
X_X_X___,
X_X_X___,
X___X___,
X___X___,
________,
// 0xCD
X___X___,
X___X___,
X___X___,
XXXXX___,
X___X___,
X___X___,
X___X___,
________,
// 0xCE
_XXX____,
X___X___,
X___X___,
X___X___,
X___X___,
X___X___,
_XXX____,
________,
// 0xCF
XXXXX___,
X___X___,
X___X___,
X___X___,
X___X___,
X___X___,
X___X___,
________,
// 0xD0
XXXX____,
X___X___,
X___X___,
X___X___,
XXXX____,
X_______,
X_______,
________,
// 0xD1
_XXX____,
X___X___,
X_______,
X_______,
X_______,
X___X___,
_XXX____,
________,
// 0xD2
XXXXX___,
__X_____,
__X_____,
__X_____,
__X_____,
__X_____,
__X_____,
________,
// 0xD3
X___X___,
X___X___,
X___X___,
X___X___,
_XXXX___,
____X___,
XXXX____,
________,
// 0xD4
_XXX____,
X_X_X___,
X_X_X___,
X_X_X___,
X_X_X___,
_XXX____,
__X_____,
________,
// 0xD5
X___X___,
X___X___,
_X_X____,
__X_____,
_X_X____,
X___X___,
X___X___,
________,
// 0xD6
X___X___,
X___X___,
X___X___,
X___X___,
X___X___,
X___X___,
XXXXX___,
____X___,
// 0xD7
X___X___,
X___X___,
X___X___,
X___X___,
XXXXX___,
____X___,
____X___,
________,
// 0xD8
X_X_X___,
X_X_X___,
X_X_X___,
X_X_X___,
X_X_X___,
X_X_X___,
XXXXX___,
________,
// 0xD9
X_X_X___,
X_X_X___,
X_X_X___,
X_X_X___,
X_X_X___,
X_X_X___,
XXXXX___,
____X___,
// 0xDA
XX______,
_X______,
_X______,
_XXX____,
_X__X___,
_X__X___,
_XXX____,
________,
// 0xDB
X___X___,
X___X___,
X___X___,
XX__X___,
X_X_X___,
X_X_X___,
XX__X___,
________,
// 0xDC
_X______,
_X______,
_X______,
_XXX____,
_X__X___,
_X__X___,
_XXX____,
________,
// 0xDD
_XXX____,
X___X___,
____X___,
__XXX___,
____X___,
X___X___,
_XXX____,
________,
// 0xDE
X__X____,
X_X_X___,
X_X_X___,
XXX_X___,
X_X_X___,
X_X_X___,
X__X____,
________,
// 0xDF
_XXXX___,
X___X___,
X___X___,
X___X___,
_XXXX___,
_X__X___,
X___X___,
________,
// 0xE0
________,
________,
_XXX____,
____X___,
_XXXX___,
X___X___,
_XXXX___,
________,
// 0xE1
___XX___,
_XX_____,
X_______,
XXXX____,
X___X___,
X___X___,
_XXX____,
________,
// 0xE2
________,
________,
XXXX____,
X___X___,
XXXX____,
X___X___,
XXXX____,
________,
// 0xE3
________,
________,
XXXXX___,
X_______,
X_______,
X_______,
X_______,
________,
// 0xE4
________,
________,
__XX____,
_X_X____,
_X_X____,
XXXXX___,
X___X___,
________,
// 0xE5
________,
________,
_XXX____,
X___X___,
XXXXX___,
X_______,
_XXX____,
________,
// 0xE6
________,
________,
X_X_X___,
X_X_X___,
_XXX____,
X_X_X___,
X_X_X___,
________,
// 0xE7
________,
________,
_XXX____,
X___X___,
___X____,
X___X___,
_XXX____,
________,
// 0xE8
________,
________,
X___X___,
X__XX___,
X_X_X___,
XX__X___,
X___X___,
________,
// 0xE9
_XXX____,
________,
X___X___,
X__XX___,
X_X_X___,
XX__X___,
X___X___,
________,
// 0xEA
________,
________,
X___X___,
X__X____,
XXX_____,
X__X____,
X___X___,
________,
// 0xEB
________,
________,
__XXX___,
_X__X___,
X___X___,
X___X___,
X___X___,
________,
// 0xEC
________,
________,
X___X___,
XX_XX___,
X_X_X___,
X___X___,
X___X___,
________,
// 0xED
________,
________,
X___X___,
X___X___,
XXXXX___,
X___X___,
X___X___,
________,
// 0xEE
________,
________,
_XXX____,
X___X___,
X___X___,
X___X___,
_XXX____,
________,
// 0xEF
________,
________,
XXXXX___,
X___X___,
X___X___,
X___X___,
X___X___,
________,
// 0xF0
________,
________,
XXXX____,
X___X___,
XXXX____,
X_______,
X_______,
________,
// 0xF1
________,
________,
_XXX____,
X___X___,
X_______,
X___X___,
_XXX____,
________,
// 0xF2
________,
________,
XXXXX___,
__X_____,
__X_____,
__X_____,
__X_____,
________,
// 0xF3
________,
________,
X___X___,
X___X___,
_XXXX___,
____X___,
XXXX____,
________,
// 0xF4
________,
________,
_XXX____,
X_X_X___,
X_X_X___,
_XXX____,
__X_____,
________,
// 0xF5
________,
________,
X___X___,
_X_X____,
__X_____,
_X_X____,
X___X___,
________,
// 0xF6
________,
________,
X___X___,
X___X___,
X___X___,
X___X___,
XXXXX___,
____X___,
// 0xF7
________,
________,
X___X___,
X___X___,
XXXXX___,
____X___,
____X___,
________,
// 0xF8
________,
________,
X_X_X___,
X_X_X___,
X_X_X___,
X_X_X___,
XXXXX___,
________,
// 0xF9
________,
________,
X_X_X___,
X_X_X___,
X_X_X___,
X_X_X___,
XXXXX___,
____X___,
// 0xFA
________,
________,
XX______,
_X______,
_XXX____,
_X__X___,
_XXX____,
________,
// 0xFB
________,
________,
X___X___,
X___X___,
XX__X___,
X_X_X___,
XX__X___,
________,
// 0xFC
________,
________,
_X______,
_X______,
_XXX____,
_X__X___,
_XXX____,
________,
// 0xFD
________,
________,
_XXX____,
X___X___,
__XXX___,
X___X___,
_XXX____,
________,
// 0xFE
________,
________,
X__X____,
X_X_X___,
XXX_X___,
X_X_X___,
X__X____,
________,
// 0xFF
________,
________,
_XXXX___,
X___X___,
_XXXX___,
_X__X___,
X___X___,
________
};

// width и height - в матрицах, например 5 на 1
template < uint8_t width, uint8_t height, uint8_t CS, uint8_t DAT, uint8_t CLK >
class TinyMAX7219 {
public:
	TinyMAX7219() {
		pinMode(CS, OUTPUT);
		pinMode(DAT, OUTPUT);
		pinMode(CLK, OUTPUT);
		sendCMD(0x0f, 0x00);	// отключить режим теста
		sendCMD(0x09, 0x00);	// выключить декодирование
		sendCMD(0x0a, 0x00);	// яркость - 0
		sendCMD(0x0b, 0x0f);	// отображаем всё
		sendCMD(0x0C, 0x01);	// включить
		fill(0); update();		// очистить
	}

	// установить яркость [0-15]
	void setBright(uint8_t value) { sendCMD(0x0a, value); } // яркость 0-15, 8x8: 0/8/15 - 30/310/540 ma
	
	// переключить питание
	//void setPower(bool value) { sendCMD(0x0c, (uint8_t)value); }
	
	// залить байтом 0 - очистить, FF - закрасить
	void fill(uint8_t data) { for (uint16_t i = 0; i < (width*height*8); i++) { buffer[i] = data; } }
	
	// установить точку
	void dot(int16_t x, int16_t y) {
		int16_t pos = getPosition(x, y);
		if (pos >= 0) bitWrite(buffer[pos], _bx, 1);
	}

	// получить точку
	bool get(int16_t x, int16_t y) {
		int16_t pos = getPosition(x, y);
		if (pos >= 0) return bitRead(buffer[pos], _bx);
		else return 0;
	}

	uint8_t __map_ch(uint8_t ch) {
		if (ch==168) return 0; // Ё
		if (ch==184) return 1; // ё
		if (ch>=0xC0) return ch - 94;
		else return ch - 29;
	}
	
	void drawChar(int16_t x, int16_t y, char ch) {
		uint8_t * font_ptr = (uint8_t *)&__font6x8[__map_ch((uint8_t)ch)<<3];
		for (int16_t yi = y; yi < (y+8); yi++) {
			uint8_t bb = pgm_read_byte(font_ptr++);
			for (int16_t xi = x; xi < (x+5); xi++) {
				if (bb&0x80) { dot(xi, yi); }
				bb <<= 1;
			}
		}
	}

	// Возвращает длину символа - 1 или 2: text += matrix.drawUtf8Char(x, y, text);
	uint8_t drawUtf8Char(int16_t x, int16_t y, const char *str) {
		uint8_t ch, out = 32, ret = 1;

		ch = *str++;
		if (ch < 0x80) { out = ch; }
		else if (ch == 0xD0) {
			ch = *str++; ret = 2;
			if (ch == 0x81) { out = 0xA8; }
			else if (ch >= 0x90 && ch <= 0xBF) { out = ch + 0x30; }
		}
		else if (ch == 0xD1) {
			ch = *str++; ret = 2;
			if (ch == 0x91) { out = 0xB8; }
			else if (ch >= 0x80 && ch <= 0x8F) { out = ch + 0x70; }
		}
		drawChar(x, y, out);
		return ret;
	}

	// обновить
	void update() {
		uint16_t count = 0;
		for (uint8_t k = 0; k < 8; k++) {
			digitalWrite(CS, 0); // beginData();
			for (uint16_t i = 0; i < (width*height); i++) sendData(8 - k, buffer[count++]);
			digitalWrite(CS, 1); // endData();
		}
	}
	
	// отправка данных напрямую в матрицу (строка, байт)
	void sendByte(uint8_t address, uint8_t value) {
		digitalWrite(CS, 0); // beginData();
		sendData(address + 1, value);
		digitalWrite(CS, 1); // endData();
	}
	
	// поворот матриц (0, 1, 2, 3 на 90 град по часовой стрелке)
	void setRotation(uint8_t rot) { _rot = rot; }

	uint8_t buffer[width * height * 8];

private:
	int16_t getPosition(int16_t x, int16_t y) {
		if (x >= 0 && x < width * 8 && y >= 0 && y < height * 8) {
			int16_t b = y;
			switch (_rot) {
				case 1: y = (y & 0xF8) + (x & 7); x = (x & 0xF8) + 7 - (b & 7); break;
				case 2: x = (x & 0xF8) + 7 - (x & 7); y = (y & 0xF8) + 7 - (y & 7); break;
				case 3: y = (y & 0xF8) + 7 - (x & 7); x = (x & 0xF8) + (b & 7); break;
			}
			if ((y >> 3) & 1) {                 // если это нечётная матрица: (y / 8) % 2
				x = width * 8 - 1 - x;          // отзеркалить x
				y = (y & 0xF8) + (7 - (y & 7)); // отзеркалить y: (y / 8) * 8 + (7 - (y % 8));
			}
			_bx = x & 7;
			return width * (height - 1 - (y >> 3)) + (width - 1 - (x >> 3)) + (y & 7) * width * height; // позиция в буфере
		}
		return -1;
	}
	
	void sendData(uint8_t address, uint8_t value) {
		shiftOut(DAT, CLK, MSBFIRST, address);
		shiftOut(DAT, CLK, MSBFIRST, value);
	}

	void sendCMD(uint8_t address, uint8_t value) {
		digitalWrite(CS, 0); // beginData();
		for (int i = 0; i < width * height; i++) sendData(address, value);
		digitalWrite(CS, 1); // endData();
	}
	
	const int _amount = width * height;
	int _row = 0, _count = 0;
	uint8_t _rot = 0, _bx = 0;
};

#endif // _TINYMAX7219_H_
