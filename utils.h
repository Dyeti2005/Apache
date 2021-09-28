#include<stdio.h>
#include<windows.h>
#include<conio.h>

#define UP 72
#define Down 80
#define left 75
#define right 77

void gotoxy(int x, int y) {
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y = y;
  SetConsoleCursorPosition(hcon, dwPos);
}