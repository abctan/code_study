#ifndef __KEN_RES_H__
#define __KEN_RES_H__

typedef volatile unsigned int 	U32;
typedef volatile unsigned short U16;
typedef volatile unsigned char 	U8;

//led register address
#define GPJ2CON *(U32 *)0xE0200280
#define GPJ2DAT *(U8 *)0xE0200284

//buzzer register address
#define GPD0CON *(U32 *)0xE02000A0
#define GPD0DAT *(U8 *)0xE02000A4


#endif //RES_H
