#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include <Winuser.h>

#define UP 0x26
#define Down 0x28
#define left 0x25
#define right 0x27

void gotoxy(int x, int y) {
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y = y;
  SetConsoleCursorPosition(hcon, dwPos);
}

/*
void ocultar_cursor(){
HANDLE hcon;
hCon = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR
}
*/