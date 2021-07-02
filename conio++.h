#include<termios.h>
#include<stdio.h>


#ifndef _COLORS_

#define _COLORS_


/* FOREGROUND */

#define RST  "\x1B[0m"

#define KRED  "\x1B[31m"

#define KGRN  "\x1B[32m"

#define KYEL  "\x1B[33m"

#define KBLU  "\x1B[34m"

#define KMAG  "\x1B[35m"

#define KCYN  "\x1B[36m"

#define KWHT  "\x1B[37m"

#define CLS  "\033[2J\033[1;1H"

#define LOC  "\033[%d;%dH"


#define FRED(x) KRED x RST

#define FGRN(x) KGRN x RST

#define FYEL(x) KYEL x RST

#define FBLU(x) KBLU x RST

#define FMAG(x) KMAG x RST

#define FCYN(x) KCYN x RST

#define FWHT(x) KWHT x RST


#define BOLD(x) "\x1B[1m" x RST

#define UNDL(x) "\x1B[4m" x RST


#endif  /* _COLORS_ */

 static struct termios old, neww;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); //grab old terminal i/o settings
  neww = old; //make neww settings same as old settings
  neww.c_lflag &= ~ICANON; //disable buffered i/o
  neww.c_lflag &= echo ? ECHO : ~ECHO; //set echo mode
  tcsetattr(0, TCSANOW, &neww); //apply terminal io settings
}
 
/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}
 
/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}
 
/* 
Read 1 character without echo 
getch() function definition.
*/
char getch(void) 
{
  return getch_(0);
}
 
/* 
Read 1 character with echo 
getche() function definition.
*/
char getche(void) 
{
  return getch_(1);
}
 

void LOCATION(int _x, int y__)
{
	printf(LOC,_x,y__);
	/*  LOC(x_coordinate, y_coordinate) 
		It shifts the cursor the
		given coordinate.*/
}

void Clear_Screen()
{
	printf("\033[2J\033[1;1H");
	/* CLS - clears the console screen */
}

