#include "utils.h"

#include "jugador.h"
//#include "enemigo.h"

#include "bala.h"

#include <list>

using namespace std;


void dibujar_limites();

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
  borrar();
  if(GetAsyncKeyState(UP)) y-=1;
  if(GetAsyncKeyState(Down)) y+=1;
  if(GetAsyncKeyState(left)) x-=1;
  if(GetAsyncKeyState(right)) x+=1;  
  pintar();
}

bala::bala(int X,int Y){
x = X;
y = Y;
}

void bala::mover(){
gotoxy(x,y);
printf("  ");
x += 1;
gotoxy(x,y);
printf("->");
}

int bala::X(){return x;}
int bala::Y(){return y;}

bool bala::fuera(){
  if(x == 64) return true;
  return false;
}

void dibujar_limites(){
  for(int x = 0; x != 64; x++){
    gotoxy(x,2);
    printf("*");
    gotoxy(x,32);
    printf("*");
  }
  for(int y = 0; y != 64; y++){
    gotoxy(0,y);
    printf("*");
    gotoxy(64,y);
    printf("*");
  }
}


int main() {

  //dibujar_limites();

  jugador N(10, 10);

  N.mover();
  
  N.pintar();
  
  list<bala*> B;

  list<bala*>::iterator it;
  
  while (true) {

    N.mover();
    
    if(kbhit){

    //char tecla = getch();

    if(GetAsyncKeyState(0X20)){

    B.push_back(new bala(N.X() + 15, N.Y() + 1));

    }

    }

    for(it = B.begin(); it != B.end(); it++){

    (*it)->mover();
    
    if((*it)->fuera()){
     gotoxy((*it)->X(),(*it)->Y());printf("  ");
     delete(*it);
     it = B.erase(it);
    }

    }
   Sleep(100);
  }
}