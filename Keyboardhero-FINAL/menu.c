#include <stdint.h>   
#include <pic32mx.h>  
#include "header.h" 
void display_title_screen(void)
{
    /* draw borders */
    draw_line(0,0);
    draw_line(0,31);
    draw_column(0,0);
    draw_column(127,0);
	
}

void title_screen(void)
{
    int i;
	int borderTrue = 0;

	
    while(1)
    {
        /* border around play icon */
		if(borderTrue)
		{
			for(i=0; i < 30; i++)
			{
				enable_pixel(48+i,16);
				enable_pixel(48+i,27);
			}
			for(i = 0; i < 12; i++)
			{
				enable_pixel(48,16+i);
				enable_pixel(77,16+i);
			}
			print_letters(90,20,3,"5W1");
		}
		else
			display_clear();
	
		cursor_construct(cursx,cursy);
		print_letters(24,4,13,"KEYBOARDHERO");
        print_letters(50,18,4,"PLAY");
        display_title_screen();
		display_update();
		cursor_move();

		if((cursx >= 48) && (cursx <= 77) && (cursy <= 28) && (cursy >= 15))
		{
			if(getswitch(1))
				break;
			borderTrue = 1;
		}
		else
		{
			borderTrue = 0;
		}
    }
}

void display_menu(void)
{
	/* draw borders */
    draw_line(0,0);
    draw_line(0,31);
    draw_column(0,0);
    draw_column(127,0);
	draw_column(30,0);
	draw_column(97,0);
	int i;
	int j;
	for(i = 0; i < 32; i++)
	{
		draw_line(97,i);
	}
	for(i = 0; i < 32; i++)
	{
		for(j = 0; j < 31; j++)
		{
			enable_pixel(i,j);
		}
	}
}

void menu(void)
{
	int borderTrue = 0;
	int i;
	cursx = 88;
	cursy = 25;
	while(1)
	{
		if(borderTrue == 1)
		{
			for(i=0; i < 30; i++)
			{
				enable_pixel(48+i,0);
				enable_pixel(48+i,10);
			}
			for(i = 0; i < 11; i++)
			{
				enable_pixel(48,0+i);
				enable_pixel(77,0+i);
			}
			print_letters(79,22,3,"5W1");
		}
		else if (borderTrue == 2)
		{
			for(i=0; i < 43; i++)
			{
				enable_pixel(41+i,11);
				enable_pixel(41+i,21);
			}
			for(i = 0; i < 11; i++)
			{
				enable_pixel(41,11+i);
				enable_pixel(84,11+i);
			}
			print_letters(79,22,3,"5W1");
		}
		else if (borderTrue == 3)
		{
			for(i=0; i < 30; i++)
			{
				enable_pixel(48+i,21);
				enable_pixel(48+i,30);
			}
			for(i = 0; i < 11; i++)
			{
				enable_pixel(48,21+i);
				enable_pixel(77,21+i);
			}
			print_letters(79,22,3,"5W1");
		}
		
		else
		{
			display_clear();
		}
		
		cursor_construct(cursx,cursy);
		display_menu();
		print_letters(50,2,4,"HARD");
		print_letters(43,12,6,"MEDIUM");
		print_letters(50,22,4,"EA5Y");
		display_update();
		quicksleep(10000);
		cursor_move();
		/* hard */
		if((cursx > 48) && (cursx < 77) && (cursy < 12) && (cursy > 0))
		{
			if(getswitch(1))
			{
				hitZone = 10;
				break;
			}
			borderTrue = 1;
		}
		/* medium */
		else if((cursx > 41) && (cursx < 82) && (cursy < 22) && (cursy > 12))
		{
			if(getswitch(1))
			{
				hitZone = 5;
				break;
			}
			borderTrue = 2;
		}
		/* easy */
		else if((cursx > 48) && (cursx < 77) && (cursy < 31) && (cursy > 22))
		{
			if(getswitch(1))
			{
				hitZone = 0;
				break;
			}
			borderTrue = 3;
		}
		else
		{
			borderTrue = 0;
		}
		
		
		display_update();
	}
}

void display_leaderboard(void)
{
    draw_line(0,0);
    draw_line(0,31);
    draw_column(0,0);
    draw_column(127,0);
    draw_column(6,0);
    draw_column(121,0);
}

void leaderboard(void)
{
	cursx = 120;
	cursy = 15;
	int borderTrue = 0;
	int i;
	
	while(1)
	{
		if(borderTrue)
		{
			for(i=0; i < 30; i++)
			{
				enable_pixel(88+i,19);
				enable_pixel(88+i,29);
			}
			for(i = 0; i < 11; i++)
			{
				enable_pixel(88,19+i);
				enable_pixel(117,19+i);
			}
			print_letters(101,10,3,"5W1");
		}
		else
		{
			display_clear();
		}
		
		display_leaderboard();
		cursor_construct(cursx,cursy);
		print_letters(10,3,9,"HIGH5CORE");
		if(hitZone == 10)
        	print_letters(80,3, 3,itoaconv(highscore_hard));
		else if(hitZone == 5)
			print_letters(80,3, 3,itoaconv(highscore_medium));
		else
			print_letters(80,3, 3,itoaconv(highscore_easy));
        print_letters(10,20,5,"5CORE");
        print_letters(50,20, 3,itoaconv(score));
        print_letters(90,20,4,"BACK");
		
        
		display_update();
		cursor_move();
		if((cursx > 87) && (cursx <= 120) && (cursy < 29) && (cursy > 18))
		{
			borderTrue = 1;
			if(getswitch(1))
				break;
		}
		else
		{
			borderTrue = 0;
		}
		
		display_update();
	}
}
