#include <stdint.h>   
#include <pic32mx.h>  
#include "header.h" 

void display_field(void)
{
    draw_line(0,0);
    draw_line(0,31);
    
    draw_line(30,8);
    draw_line(30,16);
    draw_line(30,24);
    /* hit field */
    draw_column(50-hitZone,0);
    draw_column(30,0);
}

/* spawns a note that moves down one of the 4 rows */
void spawn_note(int row)
{
    int i = 8;
    for(i; i>=0;i--)
        fill_column(119 + i,row*8);
}

/* prevloc = previous x coordinate location, row = what row intended note is in */
void move_note(uint8_t prevloc, int row)
{
    empty_column(prevloc+8,row*8);
    fill_column(prevloc-1,row*8);
}

/* removes note from given location and row */
void remove_note(int loc, int row)
{
    int i = 0;
    for(i; i<9; i++)
        empty_column(loc + i,row*8);
}

/* returns random value between 0 and 4 for usage when spawning random note */
int randomNoteRow(int rand)
{
    int random = 0;

    random = (rand * 819 + 1972)%4;
}

/* main game loop */
void keyboardHero(void)
{
    int gamespeed = 80000;
	int difficulty = 1000;
	int difficultyControl = 5000;
    int combo = 0;
    int tutorial = 1;
    lives = 3;
    score = 0;
	PORTE = 0;
    
    /* track x coordinate of all notes */
    uint8_t ntX0 = 119;
	uint8_t ntX1 = 119;
	uint8_t ntX2 = 119;
	uint8_t ntX3 = 119;
    
    int row = randomNoteRow(rand);
    /* used in various for loops */
    int i;
    int j;
    display_field();
	display_update();
    while(1)
    {
        /* create random numbers continously */
        if(getbtn(1) || getbtn(2) || getbtn(3) || getbtn(4))
            rand += 7;
        
        /* check if combo should be applied */
        if(PORTE == 255)
            combo = 1;
        else
            combo = 0;
        
        /* display quick tutorial before the game starts */
        if(tutorial)
        {
            for(i = 0; i<128; i++)
                disable_pixel(i,0);
            for(i = 0; i<128; i++)
                disable_pixel(i,31);
            print_letters(2,0,4,"BTN4");
            print_letters(2,8,4,"BTN3");
            print_letters(2,16,4,"BTN2");
            print_letters(2,24,4,"BTN1");
            
            display_update();
            quicksleep(10000000);
            quicksleep(500000);
            tutorial--;
            display_clear();
            display_field();
            spawn_note(row);
        }
        
        /* all code for row 0 */
        if(row == 0)
        {
            move_note(ntX0,0);
            ntX0--;
            if(getbtn(4) && (ntX0 > 30) && ((ntX0 + 8) < (50-hitZone)))
            {
                remove_note(ntX0,0);
                score += 1 + combo;
                ntX0 = 0;
                difficulty += difficultyControl;
                difficultyControl *= 0.95;
                remove_note(0,0);
                ntX0 = 119;
                row = randomNoteRow(rand);
                spawn_note(row);
                if((PORTE != 0) && (PORTE != 255))
                    PORTE = (PORTE << 1) + 1;
                else if(PORTE != 255)
                    PORTE++;
                continue;
            }
            if(ntX0 == 0)
            {
                remove_note(0,0);
                ntX0 = 119;
                row = randomNoteRow(rand);
                spawn_note(row);
                lives--;
                PORTE = 0;
            }
        }

        /* all code for row 1 */
        if(row == 1)
        {
            move_note(ntX1,1);
            ntX1--;
            if(getbtn(3) && (ntX1 > 30) && ((ntX1 + 8) < (50-hitZone)))
            {
                remove_note(ntX1,1);
                score += 1 + combo;
                ntX1 = 0;
                difficulty += difficultyControl;
                difficultyControl *= 0.95;
                remove_note(0,1);
                ntX1 = 119;
                row = randomNoteRow(rand);
                spawn_note(row);
                if((PORTE != 0) && (PORTE != 255))
                    PORTE = (PORTE << 1) + 1;
                else if(PORTE != 255)
                    PORTE++;
                continue;
            }
            if(ntX1 == 0)
            {
                remove_note(0,1);
                ntX1 = 119;
                row = randomNoteRow(rand);
                spawn_note(row);
                lives--;
                PORTE = 0;
            }
        }

        /* all code for row 2 */
        if(row == 2)
        {
            move_note(ntX2,2);
            ntX2--;
            if(getbtn(2) && (ntX2 > 30) && ((ntX2 + 8) <  (50-hitZone)))
            {
                remove_note(ntX2,2);
                score += 1 + combo;
                ntX2 = 0;
                difficulty += difficultyControl;
                difficultyControl *= 0.95;
                remove_note(0,2);
                ntX2 = 119;
                row = randomNoteRow(rand);
                spawn_note(row);
                if((PORTE != 0) && (PORTE != 255))
                    PORTE = (PORTE << 1) + 1;
                else if(PORTE != 255)
                    PORTE++;
                continue;
            }
            if(ntX2 == 0)
            {
                remove_note(0,2);
                ntX2 = 119;
                row = randomNoteRow(rand);
                spawn_note(row);
                lives--;
                PORTE = 0;
            }
        }

        /* all code for row 3 */
        if(row == 3)
        {
            move_note(ntX3,3);
            ntX3--;
            if(getbtn(1) && (ntX3 > 30) && ((ntX3 + 8) <  (50-hitZone)))
            {
                remove_note(ntX3,3);
                score += 1 + combo;
                ntX3 = 0;
                difficulty += difficultyControl;
                difficultyControl *= 0.95;
                remove_note(0,3);
                ntX3 = 119;
                row = randomNoteRow(rand);
                spawn_note(row);
                if((PORTE != 0) && (PORTE != 255))
                    PORTE = (PORTE << 1) + 1;
                else if(PORTE != 255)
                    PORTE++;
                continue;
            }
            if(ntX3 == 0)
            {
                remove_note(0,3);
                ntX3 = 119;
                row = randomNoteRow(rand);
                spawn_note(row);
                lives--;
                PORTE = 0;
            }
        }

        /* calculate if highscore and break out of game */
        if(lives == 0)
        {
            if(hitZone == 10)
            {
                if(score > highscore_hard)
                    highscore_hard = score;
            }
            else if(hitZone == 5)
            {
                if(score > highscore_medium)
                    highscore_medium = score;
            }
            else
            {
                if(score > highscore_easy)
                    highscore_easy = score;
            }
            break;  
        }
        /* clear previous score display */
        for(i = 0; i < 25; i++)
        {
            for(j = 0; j < 9; j++)
                disable_pixel(i + 5,j + 15);
            
            j = 0;
        }
        /* display score */
        print_letters(5,15,3,itoaconv(score));

        rand++;
        display_field();
        display_update();

        /* difficulty control */
        if(gamespeed > difficulty + 20000)
            quicksleep(gamespeed - difficulty);
        else
            quicksleep(gamespeed - 60000);
        

    }
}

