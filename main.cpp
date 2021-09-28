#include<stdio.h>
#include<windows.h>

void gotoxy(int x, int y) {
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y = y;
  SetConsoleCursorPosition(hcon, dwPos);
}

class jugador {
    int x, y;
  public:
    jugador(int X, int Y);
    void pintarGui();
    void pintar();
    void borrar();
    void mover();
};

jugador::jugador(int X, int Y) {
  x = X;
  y = Y;
}

void jugador::pintar() {
  gotoxy(x, y);
  printf("   -----|-----\n");
  gotoxy(x, y + 1);
  printf(" >=====[_]L)  \n");
  gotoxy(x, y + 2);
  printf("      -'-`-   \n");
}

void jugador::borrar() {
  gotoxy(x, y);
  printf("              \n");
  gotoxy(x, y + 1);
  printf("              \n");
  gotoxy(x, y + 2);
  printf("              \n");
}

void jugador::mover() {
  for (int i = 1; i != 25; i++) {
    borrar();
    Sleep(100);
    x += 1;
    pintar();
    Sleep(100);
  }
}

int main() {
  jugador N(0, 10);
  while (true) {
    N.mover();
  }
}