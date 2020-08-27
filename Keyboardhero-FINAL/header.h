
/* Declare display-related functions */

void display_init(void);
void display_update(void);
uint8_t spi_send_recv(uint8_t data);
void enable_pixel(uint8_t x, uint8_t y);
void disable_pixel(uint8_t x, uint8_t y);
void move_cursor(char dir);
void cursor_construct(uint8_t x, uint8_t y);
char * itoaconv(int num);

/* different types of delay */
void quicksleep(int cyc);
void delay(int);

/* Setup functions */
void setupOS ( void );
void setupPorts ( void );
void setupSPI ( void );
void display_debug( volatile int * const addr );

/* describes the screen */
extern uint8_t display[512];


/* all global variables */
extern int rand;
extern int score;
extern int highscore_easy;
extern int highscore_hard;
extern int highscore_medium;
extern int hitZone;
extern int lives;

/* cursor */
extern uint8_t cursx;
extern uint8_t cursy;

/* all functions needed to display different stages of the program */
void display_clear(void);
void title_screen(void);
void menu(void);
void keyboardHero(void);
void leaderboard(void);


/* access buttons and switches */
int getbtn (int btn);
int getswitch(int sw);

/* draw different objects */
void fill_line(int x, int y);
void fill_column(int x, int y);
void empty_column(int x, int y);
void draw_line(int x, int y);
void draw_column(int x, int y);


void print_letters(uint8_t x, uint8_t y, int size, char * letters);
void print_letter(uint8_t x, uint8_t y, char letter);
void cursor_move(void);



/* everything delay related */
void enable_interrupt(void);
void delay(int);
