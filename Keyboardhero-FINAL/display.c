/* mipslabdata.c
   This file compiled 2015 by F Lundevall
   from original code written by Axel Isaksson

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "header.h"  /* Declatations for these labs */

static void num32asc(char * s, int); 

#define DISPLAY_CHANGE_TO_COMMAND_MODE (PORTFCLR = 0x10)
#define DISPLAY_CHANGE_TO_DATA_MODE (PORTFSET = 0x10)

#define DISPLAY_ACTIVATE_RESET (PORTGCLR = 0x200)
#define DISPLAY_DO_NOT_RESET (PORTGSET = 0x200)

#define DISPLAY_ACTIVATE_VDD (PORTFCLR = 0x40)
#define DISPLAY_ACTIVATE_VBAT (PORTFCLR = 0x20)

#define DISPLAY_TURN_OFF_VDD (PORTFSET = 0x40)
#define DISPLAY_TURN_OFF_VBAT (PORTFSET = 0x20)
// artificial delay
void quicksleep(int cyc) 
{
	int i;
	for(i = cyc; i > 0; i--);
}

uint8_t  display[512];


static void num32asc(char * s, int n) 
{
  int i;
  for( i = 28; i >= 0; i -= 4 )
    *s++ = "0123456789ABCDEF"[ (n >> i) & 15 ];
}

uint8_t spi_send_recv(uint8_t data) 
{
	while(!(SPI2STAT & 0x08));
	SPI2BUF = data;
	while(!(SPI2STAT & 1));
	return SPI2BUF;
}

void display_init(void) 
{
        DISPLAY_CHANGE_TO_COMMAND_MODE;
	quicksleep(10);
	DISPLAY_ACTIVATE_VDD;
	quicksleep(1000000);
	
	spi_send_recv(0xAE);
	DISPLAY_ACTIVATE_RESET;
	quicksleep(10);
	DISPLAY_DO_NOT_RESET;
	quicksleep(10);
	
	spi_send_recv(0x8D);
	spi_send_recv(0x14);
	
	spi_send_recv(0xD9);
	spi_send_recv(0xF1);
	
	DISPLAY_ACTIVATE_VBAT;
	quicksleep(10000000);
	
	spi_send_recv(0xA1);
	spi_send_recv(0xC8);
	
	spi_send_recv(0xDA);
	spi_send_recv(0x20);
	
	spi_send_recv(0xAF);
}

void enable_pixel(uint8_t x, uint8_t y)
{
	display[(x % 128) + 128 * (((y - (y % 8))/8)%4)] |= (0x1 << (y % 8));
}

void disable_pixel(uint8_t x, uint8_t y)
{
	display[(x % 128) + 128 * (((y - (y % 8))/8)%4)] &= ~(0x1 << (y % 8));
}
/* moves the cursor */
void move_cursor(char dir)
{
	switch(dir)
	{
		case 'u':
			enable_pixel(cursx,cursy - 1);
			enable_pixel(cursx+1,cursy-1);
			disable_pixel(cursx,cursy+1);
			disable_pixel(cursx+1,cursy+1);
			break;

		case 'd':
			enable_pixel(cursx+1,cursy+2);
			enable_pixel(cursx,cursy+2);
			disable_pixel(cursx,cursy);
			disable_pixel(cursx+1,cursy);
			break;
		case 'l':
			enable_pixel(cursx-1,cursy);
			enable_pixel(cursx-1,cursy+1);
			disable_pixel(cursx+1,cursy);
			disable_pixel(cursx+1,cursy+1);
			break;
		case 'r':
			enable_pixel(cursx+2,cursy);
			enable_pixel(cursx+2,cursy+1);
			disable_pixel(cursx,cursy);
			disable_pixel(cursx,cursy+1);
			break;
	}
}

void display_clear(void)
{
	int i = 0;
	for(i; i<512; i++)
	{
		display[i] = 0;
	}
}

void display_update(void) 
{
	int i, j;
	for(i = 0; i < 4; i++) 
    {
		DISPLAY_CHANGE_TO_COMMAND_MODE;
		spi_send_recv(0x22);
		spi_send_recv(i);
		
		spi_send_recv(0x0);
		spi_send_recv(0x10);
		
		DISPLAY_CHANGE_TO_DATA_MODE;
		
		for(j = 0; j < 128; j++) 
			spi_send_recv(display[i*128 + j]);
	}
}


#define ITOA_BUFSIZ (24)
char * itoaconv(int num)
{
  register int i, sign;
  static char itoa_buffer[ ITOA_BUFSIZ ];
  static const char maxneg[] = "-2147483648";
  
  itoa_buffer[ ITOA_BUFSIZ - 1 ] = 0;   /* Insert the end-of-string marker. */
  sign = num;                           /* Save sign. */
  if( num < 0 && num - 1 > 0 )          /* Check for most negative integer */
  {
    for( i = 0; i < sizeof( maxneg ); i += 1 )
    itoa_buffer[ i + 1 ] = maxneg[ i ];
    i = 0;
  }
  else
  {
    if( num < 0 ) num = -num;           /* Make number positive. */
    i = ITOA_BUFSIZ - 2;                /* Location for first ASCII digit. */
    do {
      itoa_buffer[ i ] = num % 10 + '0';/* Insert next digit. */
      num = num / 10;                   /* Remove digit from number. */
      i -= 1;                           /* Move index to next empty position. */
    } while( num > 0 );
    if( sign < 0 )
    {
      itoa_buffer[ i ] = '-';
      i -= 1;
    }
  }
  /* Since the loop always sets the index i to the next empty position,
   * we must add 1 in order to return a pointer to the first occupied position. */
  return( &itoa_buffer[ i + 1 ] );
}
