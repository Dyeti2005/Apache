#include "utils.h"

#include "jugador.h"
#include "enemigo.h"

#include <list>

using namespace std;

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
  
  if(kbhit){
  char tecla = getch();
  borrar();
  if(tecla == UP) y-=1;
  if(tecla == Down) y+=1;
  if(tecla == left) x-=1;
  if(tecla == right) x+=1;  
  pintar();
  }
}

bala::bala(int X,int Y){
x = X;
y = Y;
}

void bala::mover(){
gotoxy(x,y);
printf(" ");
gotoxy(x,y);
printf("*");
}

int main() {
  jugador N(10, 10);
  
  N.pintar();
  
  list<bala*> B;
  
  while (true) {
    if(kbhit){
    char tecla = getch();
    if(tecla == 'a'){
    B.push_back(new bala(N.X() + 15, N.Y()));
    }
    }
    N.mover();
  }
}