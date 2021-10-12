#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include <Winuser.h>

#define UP 0x26
#define Down 0x28
#define left 0x25
#define right 0x27

#define limite_x 64
#define limite_y 32

int timer = 0;

bool randbool(int value){
  return ((rand()%value) == 1);
}

void gotoxy(int x, int y) {
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y = y;
  SetConsoleCursorPosition(hcon, dwPos);
}