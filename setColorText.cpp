#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string>

using namespace std;
void setColor(int);
void gotoxy(int, int);

#define N rand()%14+1

enum ConsoleColors
{
    BLACK = 0, BLUE = 1, GREEN = 2,
    AQUA = 3, RED = 4, PURPLE = 5,
    YELLOW = 6, WHITE = 7, GRAY = 8, 
    LIGHT_BLUE = 9, LIGHT_GREEN = 10,
    LIGHT_AQUA = 11, LIGHT_RED = 12, 
    LIGHT_PURPLE = 13, LIGHT_YELLOW = 14,
    LIGHT_WHITE = 15
}*color;


typedef HANDLE Handle;
typedef CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
typedef WORD Word;

short setTextColor( ConsoleColors foreground)
{
    Handle consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    BufferInfo bufferInfo;
    if(!GetConsoleScreenBufferInfo(consoleHandle, &bufferInfo))
        return 0;
    Word color = (bufferInfo.wAttributes & 0xF0) + (foreground & 0x0F);
    SetConsoleTextAttribute(consoleHandle, color);
    return 1;
}


int main()
{
	int i=1 ,  j=1;
	
	char name[27] ="" ;

	
	string n;
    
	gotoxy(i,j);
	cin.get(name,27);
	
	for(int i=0 ; name[i]!=NULL; i++)
	  n+=name[i];
	
	while(1){
	 
	 gotoxy(i,j);
	for(int i=0 ; i<n.size() ; i++)
	{
		setColor(N);
		cout << n[i];
	}
	  Sleep(500);
         }


}

void setColor(int n)
{
	if(n==0)
	setTextColor(BLACK);
	
	else if(n==1)
	 setTextColor(BLUE);
	 
	 else if(n==2)
	   setTextColor(GREEN);
	   
	   else if(n==3)
	     setTextColor(AQUA);
	     
	     else if(n==4)
	       setTextColor(RED);
	       
	       else if(n==5)
	        setTextColor(PURPLE);
	        
	        else if(n==6)
	        setTextColor(YELLOW);
	        
	        else if(n==7)
	        setTextColor(WHITE);
	        
	        else if(n==8)
	        setTextColor(GRAY);
	        
	         else if(n==9)
	         setTextColor(LIGHT_BLUE);
	         
	         else if(n==10)
	         setTextColor(LIGHT_GREEN);
	         
	         else if(n==11)
	         setTextColor(LIGHT_AQUA);
	         
	         else if(n==12)
	         setTextColor(LIGHT_RED);
	         
	         else if(n==13)
	         setTextColor(LIGHT_PURPLE);
	         
	         else if(n==14)
	         setTextColor(LIGHT_YELLOW);
	         
	         else setTextColor(LIGHT_WHITE);
}


void gotoxy(int x, int y)
{


	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
