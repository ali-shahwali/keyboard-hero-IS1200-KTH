#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "header.h"  /* Declatations for these labs */


int getswitches( void )
{
    return (PORTD >> 8) & 0x000F; // maskera med 1111 (4 switches)
}

int getbtns( void )
{
    return ((PORTD >> 4) & 0x000e) | ((PORTF >> 1) & 0x0001); // maskera PORTD med 1110 (knapp 2,3,4) och PORTF med 0001 (knapp 1)
}

int getbtn(int btn)
{
    switch (btn)
    {
    case 1:
        if ( (getbtns() & 0x0001) != 0x0001 )
            return 0;
        return 1;
        break;
    case 2:
        if ( (getbtns() & 0x0002) != 0x0002 )
            return 0;
        return 1;
        break;
    case 3:
        if ( (getbtns() & 0x0004) != 0x0004 )
            return 0;
        return 1;
        break;
    case 4:
        if ( (getbtns() & 0x0008) != 0x0008 )
            return 0;
        return 1;
        break;
    default:
        return -1;
        break;
    }
    
}

int getswitch(int sw)
{
    switch (sw)
    {
    case 1:
        if ((getswitches() & 0x0001) != 0x0001)
            return 0;
        return 1;
        break;
    case 2:
        if ((getswitches() & 0x0002) != 0x0002)
            return 0;
        return 1;
        break;
    case 3:
        if ((getswitches() & 0x0004) != 0x0004)
            return 0;
        return 1;
        break;
    case 4:
        if ((getswitches() & 0x0008) != 0x0008)
            return 0;
        return 1;
        break;
    default:
        return -1;
        break;
    }
}
/* x och y koordinat för vilken letter du vill skriva på skärmen */
void print_letter(uint8_t x, uint8_t y, char letter)
{
    if (letter == 'M')
    {
        fill_column(x,y);
        enable_pixel(x+1,y+1);
        enable_pixel(x+2,y+2);
        enable_pixel(x+3,y+1);
        fill_column(x+4,y);
    }
    if (letter == 'N')
    {
        fill_column(x,y);
        enable_pixel(x+1,y+1);
        enable_pixel(x+1,y+2);
        enable_pixel(x+2,y+3);
        enable_pixel(x+2,y+4);
        enable_pixel(x+3,y+5);
        enable_pixel(x+3,y+6);
        fill_column(x+4,y);

    }
    if (letter == 'F')
    {
        fill_column(x,y);
        enable_pixel(x+1,y);
        enable_pixel(x+1,y+4);
        enable_pixel(x+2,y);
        enable_pixel(x+2,y+4);
        enable_pixel(x+3,y);
        enable_pixel(x+4,y);

    }
    if (letter == 'T')
    {
        enable_pixel(x,y);
        enable_pixel(x+1,y);
        fill_column(x+2,y);
        enable_pixel(x+3,y);
        enable_pixel(x+4,y);
    }
    if (letter == 'U')
    {
        fill_column(x,y);
        enable_pixel(x+1,y+7);
        enable_pixel(x+2,y+7);
        enable_pixel(x+3,y+7);
        fill_column(x+4,y);
    }
    if (letter == '!')
    {
        fill_column(x,y);
        disable_pixel(x,y+6);
        disable_pixel(x,y+5);
    }
    if (letter == 'A')
    {

        enable_pixel(x,y+3);
        enable_pixel(x,y+4);
        enable_pixel(x,y+5);
        enable_pixel(x,y+6);
        enable_pixel(x,y+7);
        enable_pixel(x+1,y);
        enable_pixel(x+1,y+1);
        enable_pixel(x+1,y+2);
        enable_pixel(x+1,y+3);
        enable_pixel(x+1,y+4);
        enable_pixel(x+2,y);
        enable_pixel(x+2,y+3);
        enable_pixel(x+3,y);
        enable_pixel(x+3,y+1);
        enable_pixel(x+3,y+2);
        enable_pixel(x+3,y+3);
        enable_pixel(x+3,y+4);
        enable_pixel(x+4,y+3);
        enable_pixel(x+4,y+4);
        enable_pixel(x+4,y+5);
        enable_pixel(x+4,y+6);
        enable_pixel(x+4,y+7);
    }
    if (letter == 'R')
    {
        fill_column(x,y);
        enable_pixel(x+1,y);
        enable_pixel(x+1,y+4);
        enable_pixel(x+1,y+5);
        enable_pixel(x+2,y);
        enable_pixel(x+2,y+4);
        enable_pixel(x+2,y+5);
        enable_pixel(x+2,y+6);
        enable_pixel(x+3,y);
        enable_pixel(x+3,y+4);
        enable_pixel(x+3,y+6);
        enable_pixel(x+3,y+7);
        fill_column(x+4,y);
        disable_pixel(x+4,y+5);
        disable_pixel(x+1,y+6);
    }
    if (letter == 'D')
    {
        fill_column(x,y);
        enable_pixel(x+1,y);
        enable_pixel(x+1,y+7);
        enable_pixel(x+2,y);
        enable_pixel(x+2,y+7);
        enable_pixel(x+3,y);
        enable_pixel(x+3,y+7);
        fill_column(x+4,y);
        disable_pixel(x+4,y);
        disable_pixel(x+4,y+7);
    }
    if (letter == 'H')
    {
        fill_column(x,y);
        enable_pixel(x+1,y+3);
        enable_pixel(x+2,y+3);
        enable_pixel(x+3,y+3);
        fill_column(x+4,y);
    }
    
    if (letter == 'B')
    {
        fill_column(x,y);
        enable_pixel(x+1,y);
        enable_pixel(x+1,y+3);
        enable_pixel(x+1,y+4);
        enable_pixel(x+1,y+7);
        enable_pixel(x+2,y);
        enable_pixel(x+2,y+3);
        enable_pixel(x+2,y+4);
        enable_pixel(x+2,y+7);
        fill_column(x+3,y);
        enable_pixel(x+4,y+1);
        enable_pixel(x+4,y+2);
        enable_pixel(x+4,y+5);
        enable_pixel(x+4,y+6);
    }
    if (letter == 'E')
    {
        fill_column(x,y);
        enable_pixel(x+1,y);
        enable_pixel(x+1,y+4);
        enable_pixel(x+1,y+7);
        enable_pixel(x+2,y);
        enable_pixel(x+2,y+4);
        enable_pixel(x+2,y+7);
        enable_pixel(x+3,y);
        enable_pixel(x+3,y+4);
        enable_pixel(x+3,y+7);
        enable_pixel(x+4,y);
        enable_pixel(x+4,y+7);
    }
    if(letter == 'K')
    {
        fill_column(x,y);
        enable_pixel(x+1,y+2);
        enable_pixel(x+1,y+3);
        enable_pixel(x+1,y+4);
        enable_pixel(x+1,y+5);
        enable_pixel(x+1,y+6);
        enable_pixel(x+2,y+1);
        enable_pixel(x+2,y+2);
        enable_pixel(x+2,y+6);
        enable_pixel(x+2,y+7);
        enable_pixel(x+3,y);
        enable_pixel(x+3,y+1);
        enable_pixel(x+3,y+6);
        enable_pixel(x+3,y+7);
        enable_pixel(x+4,y);
        enable_pixel(x+4,y+7);
    }
    if (letter == 'O')
    {
        fill_column(x,y);
        disable_pixel(x,y);
        disable_pixel(x,y+7);
        enable_pixel(x+1,y);
        enable_pixel(x+1,y+1);
        enable_pixel(x+1,y+6);
        enable_pixel(x+1,y+7);
        enable_pixel(x+2,y);
        enable_pixel(x+2,y+7);
        enable_pixel(x+3,y);
        enable_pixel(x+3,y+1);
        enable_pixel(x+3,y+6);
        enable_pixel(x+3,y+7);
        fill_column(x+4,y);
        disable_pixel(x+4,y);
        disable_pixel(x+4,y+7);
    }
    
    if (letter == 'Y')
    {
        enable_pixel(x,y);
        enable_pixel(x,y+1);
        enable_pixel(x+1,y+1);
        enable_pixel(x+1,y+2);
        enable_pixel(x+2,y+2);
        enable_pixel(x+2,y+3);
        enable_pixel(x+2,y+4);
        enable_pixel(x+2,y+5);
        enable_pixel(x+2,y+6);
        enable_pixel(x+2,y+7);
        enable_pixel(x+3,y+2);
        enable_pixel(x+3,y+1);
        enable_pixel(x+4,y+1);
        enable_pixel(x+4,y);
    }
    if (letter == 'P')
    {
        fill_column(x,y);
        enable_pixel(x+1,y);
        enable_pixel(x+1,y+3);
        enable_pixel(x+2,y);
        enable_pixel(x+2,y+3);
        enable_pixel(x+3,y);
        enable_pixel(x+3,y+3);
        enable_pixel(x+4,y);
        enable_pixel(x+4,y+1);
        enable_pixel(x+4,y+2);
        enable_pixel(x+4,y+3);
    }
    
    if (letter == 'L')
    {
        fill_column(x,y);
        enable_pixel(x+1,y+7);
        enable_pixel(x+2,y+7);
        enable_pixel(x+3,y+7);
        enable_pixel(x+4,y+7);
    }
    
    if (letter == 'C')
    {
        fill_column(x,y);
        disable_pixel(x,y);
        disable_pixel(x,y+7);
        enable_pixel(x+1,y);
        enable_pixel(x+1,y+1);
        enable_pixel(x+1,y+6);
        enable_pixel(x+1,y+7);
        enable_pixel(x+2,y);
        enable_pixel(x+2,y+7);
        enable_pixel(x+3,y);
        enable_pixel(x+3,y+7);
        enable_pixel(x+4,y);
        enable_pixel(x+4,y+7);
    }
    
    if (letter == 'G')
    {
        fill_column(x,y);
        disable_pixel(x,y);
        disable_pixel(x,y+7);
        enable_pixel(x+1,y);
        enable_pixel(x+1,y+1);
        enable_pixel(x+1,y+6);
        enable_pixel(x+1,y+7);
        enable_pixel(x+2,y);
        enable_pixel(x+2,y+7);
        enable_pixel(x+3,y);
        enable_pixel(x+3,y+4);
        enable_pixel(x+3,y+7);
        fill_column(x+4,y);
        disable_pixel(x+4,y+1);
        disable_pixel(x+4,y+2);
        disable_pixel(x+4,y+3);
    }

    if (letter == 'I')
    {
        enable_pixel(x,y);
        enable_pixel(x,y+7);
        enable_pixel(x+1,y);
        enable_pixel(x+1,y+7);
        fill_column(x+2,y);
        enable_pixel(x+3,y);
        enable_pixel(x+3,y+7);
        enable_pixel(x+4,y);
        enable_pixel(x+4,y+7);
    }

    if (letter == '0')
    {
        fill_column(x,y);
        disable_pixel(x,y);
        disable_pixel(x,y+7);
        enable_pixel(x+1,y);
        enable_pixel(x+1,y+1);
        enable_pixel(x+1,y+6);
        enable_pixel(x+1,y+7);
        enable_pixel(x+2,y);
        enable_pixel(x+2,y+7);
        enable_pixel(x+3,y);
        enable_pixel(x+3,y+1);
        enable_pixel(x+3,y+6);
        enable_pixel(x+3,y+7);
        fill_column(x+4,y);
        disable_pixel(x+4,y);
        disable_pixel(x+4,y+7);
    }

    if (letter == '1')
    {
        enable_pixel(x,y+1);
        enable_pixel(x,y+2);
        enable_pixel(x,y+7);
        enable_pixel(x+1,y+1);
        enable_pixel(x+1,y+7);
        fill_column(x+2,y);
        enable_pixel(x+3,y+7);
        enable_pixel(x+4,y+7);
    }

        if (letter == '2')
    {
        fill_column(x,y);
        disable_pixel(x,y+1);
        disable_pixel(x,y+2);
        enable_pixel(x+1,y);
        enable_pixel(x+1,y+3);
        enable_pixel(x+1,y+7);
        enable_pixel(x+2,y);
        enable_pixel(x+2,y+3);
        enable_pixel(x+2,y+7);
        enable_pixel(x+3,y);
        enable_pixel(x+3,y+3);
        enable_pixel(x+3,y+7);
        fill_column(x+4,y);
        disable_pixel(x+4,y+4);
        disable_pixel(x+4,y+5);
        disable_pixel(x+4,y+6);
    }
    if (letter == '3')
    {
        enable_pixel(x,y);
        enable_pixel(x,y+7);
        enable_pixel(x+1,y);
        enable_pixel(x+1,y+7);
        enable_pixel(x+2,y);
        enable_pixel(x+2,y+4);
        enable_pixel(x+2,y+7);
        enable_pixel(x+3,y);
        enable_pixel(x+3,y+4);
        enable_pixel(x+3,y+7);
        fill_column(x+4,y);
    }
    if (letter == '4')
    {
        fill_column(x,y);
        disable_pixel(x,y+4);
        disable_pixel(x,y+5);
        disable_pixel(x,y+6);
        disable_pixel(x,y+7);
        enable_pixel(x+1,y+3);
        enable_pixel(x+2,y+3);
        enable_pixel(x+3,y+3);
        fill_column(x+4,y);
    }
    
    if (letter == '5')
    {
        fill_column(x,y);
        disable_pixel(x,y+5);
        disable_pixel(x,y+6);
        enable_pixel(x+1,y);
        enable_pixel(x+1,y+4);
        enable_pixel(x+1,y+7);
        enable_pixel(x+2,y);
        enable_pixel(x+2,y+4);
        enable_pixel(x+2,y+7);
        enable_pixel(x+3,y);
        enable_pixel(x+3,y+4);
        enable_pixel(x+3,y+7);
        fill_column(x+4,y);
        disable_pixel(x+4,y+1);
        disable_pixel(x+4,y+2);
        disable_pixel(x+4,y+3);
    }
    if (letter == '6')
    {
        fill_column(x,y);
        enable_pixel(x+1,y);
        enable_pixel(x+1,y+4);
        enable_pixel(x+1,y+7);
        enable_pixel(x+2,y);
        enable_pixel(x+2,y+4);
        enable_pixel(x+2,y+7);
        enable_pixel(x+3,y);
        enable_pixel(x+3,y+4);
        enable_pixel(x+3,y+7);
        fill_column(x+4,y);
        disable_pixel(x+4,y+1);
        disable_pixel(x+4,y+2);
        disable_pixel(x+4,y+3);
    }
    if (letter == '7')
    {
        enable_pixel(x,y);
        enable_pixel(x+1,y);
        enable_pixel(x+2,y);
        enable_pixel(x+3,y);
        fill_column(x+4,y);
    }
    if (letter == '8')
    {
        fill_column(x,y);
        enable_pixel(x+1,y);
        enable_pixel(x+1,y+4);
        enable_pixel(x+1,y+7);
        enable_pixel(x+2,y);
        enable_pixel(x+2,y+4);
        enable_pixel(x+2,y+7);
        enable_pixel(x+3,y);
        enable_pixel(x+3,y+4);
        enable_pixel(x+3,y+7);
        fill_column(x+4,y);
    }
    if (letter == '9')
    {
        enable_pixel(x,y);
        enable_pixel(x,y+1);
        enable_pixel(x,y+2);
        enable_pixel(x,y+3);
        enable_pixel(x,y+4);
        enable_pixel(x+1,y);
        enable_pixel(x+1,y+4);
        enable_pixel(x+2,y);
        enable_pixel(x+2,y+4);
        enable_pixel(x+3,y);
        enable_pixel(x+3,y+4);
        fill_column(x+4,y);

    }

    if (letter == 's')
    {
        enable_pixel(x+2,y+1);
        enable_pixel(x+2,y+5);
        enable_pixel(x+3,y+2);
        enable_pixel(x+3,y+3);
        enable_pixel(x+3,y+4);
        enable_pixel(x+4,y+2);
        enable_pixel(x+4,y+3);
        enable_pixel(x+4,y+4);
        enable_pixel(x+5,y+2);
        enable_pixel(x+5,y+3);
        enable_pixel(x+5,y+4);
        enable_pixel(x+6,y+1);
        enable_pixel(x+6,y+5);
    }
        if (letter == 't')
    {
        enable_pixel(x+1,y+3);
        enable_pixel(x+2,y+1);
        enable_pixel(x+2,y+5);
        enable_pixel(x+3,y+2);
        enable_pixel(x+3,y+3);
        enable_pixel(x+3,y+4);
        enable_pixel(x+4,y+2);
        enable_pixel(x+4,y+3);
        enable_pixel(x+4,y+4);
        enable_pixel(x+5,y+2);
        enable_pixel(x+5,y+3);
        enable_pixel(x+5,y+4);
        enable_pixel(x+6,y+1);
        enable_pixel(x+6,y+5);
        enable_pixel(x+7,y+3);
    }
    if (letter == 'a')
    {
        enable_pixel(x,y+3);
        enable_pixel(x+1,y+3);
        enable_pixel(x+2,y+1);
        enable_pixel(x+2,y+5);
        enable_pixel(x+3,y+2);
        enable_pixel(x+3,y+3);
        enable_pixel(x+3,y+4);
        enable_pixel(x+4,y+2);
        enable_pixel(x+4,y+3);
        enable_pixel(x+4,y+4);
        enable_pixel(x+5,y+2);
        enable_pixel(x+5,y+3);
        enable_pixel(x+5,y+4);
        enable_pixel(x+6,y+1);
        enable_pixel(x+6,y+5);
        enable_pixel(x+7,y+3);
        enable_pixel(x+8,y+3);
    }
    if (letter == 'r')
    {
        enable_pixel(x+2,y+1);
        enable_pixel(x+2,y+5);
        enable_pixel(x+3,y+2);
        enable_pixel(x+3,y+3);
        enable_pixel(x+3,y+4);
        enable_pixel(x+4,y+1);
        enable_pixel(x+4,y+2);
        enable_pixel(x+4,y+3);
        enable_pixel(x+4,y+4);
        enable_pixel(x+4,y+5);
        enable_pixel(x+5,y+2);
        enable_pixel(x+5,y+3);
        enable_pixel(x+5,y+4);
        enable_pixel(x+6,y+1);
        enable_pixel(x+6,y+5);
    }
    if (letter == 'y')
    {
        enable_pixel(x+2,y+1);
        enable_pixel(x+2,y+5);
        enable_pixel(x+3,y+2);
        enable_pixel(x+3,y+3);
        enable_pixel(x+3,y+4);
        fill_column(x+4,y);
        enable_pixel(x+5,y+2);
        enable_pixel(x+5,y+3);
        enable_pixel(x+5,y+4);
        enable_pixel(x+6,y+1);
        enable_pixel(x+6,y+5);
    }
    if (letter == 'W')
    {
        fill_column(x,y);
        enable_pixel(x+1,y+6);
        enable_pixel(x+2,y+5);
        enable_pixel(x+3,y+6);
        fill_column(x+4,y);
    }
}


void print_letters(uint8_t x, uint8_t y, int size, char * letters)
{
    int i;
    for (i = 0; i < size; i++)
    {
        print_letter(x, y, letters[i]);
        x += 7;
    }
    
}
/* enables 8 pixels below start coordinate */

void fill_column(int x, int y)
{
    uint8_t i = 0;
    for(i; i<8; i++)
        enable_pixel(x,i+y);
}
/* empties/disables 8 pixels below start coordinate */
void empty_column(int x, int y)
{
    uint8_t i = 0;
    for(i; i<8; i++)
        disable_pixel(x,i+y);
}

/* draw a horizontal line from start coordinate to edge of screen*/
void draw_line(int x, int y)
{
    int i = 0;
    for(i; i < 128; i++)
    {
        if(x > 127)
            return;
        else
        {
            enable_pixel(x,y);
            x++;
        }
    }
}
/* draw a vertical line from start coordinate to bottom of screen */
void draw_column(int x, int y)
{
    int i = 0;
    for(i; i < 32; i++)
    {
        if(y > 31)
        {
            return;
        }
        else 
        {
            enable_pixel(x,y);
            y++;
        }
    }
}

void cursor_construct(uint8_t x, uint8_t y)
{
    enable_pixel(x,y);
	enable_pixel(x+1,y);
	enable_pixel(x,y+1);
	enable_pixel(x+1,y+1);
}




void cursor_move(void)
{
    if((cursx > 1) && (cursx < 125) && (cursy > 1) && (cursy < 29))
    {
        if(getbtn(1))
        {
            move_cursor('r');
            cursx++;
            rand++;
        }
        if(getbtn(2))
        {
            move_cursor('d');
            cursy++;

            rand++;
        }
        if(getbtn(3))
        {
            move_cursor('u');
            cursy--;
            rand++;
        }
        if(getbtn(4))
        {
            move_cursor('l');
            cursx--;
            rand++;
        }
        quicksleep(40000);
    }
    else
    {
        if(cursx == 1)
        {
            move_cursor('r');
            cursx++;
            rand++;
        }
        if(cursx == 125)
        {
            move_cursor('l');
            cursx--;
            rand++;
        }
        if(cursy == 1)
        {
            move_cursor('d');
            cursy++;
            rand++;
        }
        if(cursy == 29)
        {
            move_cursor('u');
            cursy--;
            rand++;
        }
        quicksleep(40000);

    }
}
