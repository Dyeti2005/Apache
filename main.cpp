#include "jugador.h"
#include "enemigo.h"
#include "utils.h"
#include "bala.h"
#include <list>

using namespace std;

void dibujar_limites();

jugador::jugador(int X, int Y) {
  x = X;
  y = Y;
}

void jugador::pintarGui() {
  gotoxy(0, 0); printf("vida: %i",vida);
  gotoxy(8, 0); printf("puntaje: %i", puntaje);
}

void jugador::pintar() {
  gotoxy(x,y);printf("]>");
}

void jugador::borrar() {
  gotoxy(x,y);printf("  ");
}

void jugador::cor(){
   borrar();
   explotar();
   x = 10,y = 10;
   vida--;
}

void jugador::explotar(){
    gotoxy(x,y);  printf("   **   ");
    gotoxy(x,y+1);printf("  ****  ");
    gotoxy(x,y+2);printf("   **   ");

    Sleep(100);  

    gotoxy(x,y);  printf(" * ** *");
    gotoxy(x,y+1);printf("  **** ");
    gotoxy(x,y+2);printf(" * ** *"); 

    Sleep(100);
    
    gotoxy(x,y);  printf("       ");
    gotoxy(x,y+1);printf("       ");
    gotoxy(x,y+2);printf("       "); 
}

void jugador::mover() {
  borrar();
  
  if (GetAsyncKeyState(UP) && !(y-1 <= 2)) y -= 1;
  if (GetAsyncKeyState(Down) && !(y+1 >= limite_y)) y += 1;

  if (GetAsyncKeyState(left) && !(x-2 <= 0)) x-= 1;
  if (GetAsyncKeyState(right) && !(x+2 >= limite_x)) x+= 1;
  
  pintar();
}

bala::bala(int X, int Y) {
  x = X;
  y = Y;
}

void bala::pintar() {
  gotoxy(x, y);
  printf("-");
}
void bala::borrar() {
  gotoxy(x, y);
  printf("  ");
}

void bala::mover() {
  borrar();
  x += 1;
  pintar();
}

bool bala::fuera() {
  return x+2 >= limite_x;
}

enemigo::enemigo(int X, int Y) {
  x = X;
  y = Y;
}

void enemigo::colision(struct jugador &N){
  if(x == N.X() && y == N.Y()){
    N.cor();
    N.pintar();
    N.pintarGui();
  }
}


void enemigo::pintar() {
  gotoxy(x,y);printf("<[");
}

void enemigo::borrar() {
  gotoxy(x,y);printf("  ");
}

void enemigo::explotar(){
    gotoxy(x,y);  printf("   **   ");
    gotoxy(x,y+1);printf("  ****  ");
    gotoxy(x,y+2);printf("   **   ");

    Sleep(100);  

    gotoxy(x,y);  printf(" * ** *");
    gotoxy(x,y+1);printf("  **** ");
    gotoxy(x,y+2);printf(" * ** *"); 

    Sleep(100);
    
    gotoxy(x,y);  printf("       ");
    gotoxy(x,y+1);printf("       ");
    gotoxy(x,y+2);printf("       ");     
}

void enemigo::mover() {
  borrar();
  x -= 1;
  pintar();
}

bool enemigo::limite() {
  if (x <= 2) return true;
  return false;
}

void dibujar_limites() {
  for (int x = 0; x != limite_x; x++) {
    gotoxy(x, 2);
    printf("*");
    gotoxy(x, limite_y);
    printf("*");
  }
  for (int y = 2; y != limite_y; y++) {
    gotoxy(0, y);
    printf("*");
    gotoxy(limite_x, y);
    printf("*");
  }
}

void GameOver(struct jugador &N){
  system("cls");
  gotoxy(0,0);printf("***** fin del juego ******\n");
  gotoxy(0,5);printf("******* Puntaje: %i ******\n",N.puntaje);
  system("pause");  
}

int main() {
  dibujar_limites();

  jugador N(10, 10);

  N.pintar();

  list<bala*> B;
  list<enemigo*> e;

  list<bala*>::iterator it;
  list<enemigo*>::iterator it2;

  e.push_back(new enemigo(rand()%limite_x - 1, rand()%limite_y));
  e.push_back(new enemigo(rand()%limite_x - 1, rand()%limite_y));
  e.push_back(new enemigo(rand()%limite_x - 1, rand()%limite_y));
  e.push_back(new enemigo(rand()%limite_x - 1, rand()%limite_y));

  bool fin_del_juego = false;

  while (!fin_del_juego) {

    if(N.vida < 1){
      fin_del_juego = true;
    }

    if (GetAsyncKeyState(0X20) && timer >= 5) {
      B.push_back(new bala(N.X(), N.Y()));
      Beep(600,100);
      timer = 0;
    }

    if (timer >= 2)
    {
      dibujar_limites();
    }   
    for (it2 = e.begin(); it2 != e.end(); it2++) {

      (*it2)->mover();
      (*it2)->colision(N);

      if ((*it2)->limite()) {
        (*it2)->borrar();
        delete(*it2);
        it2 = e.erase(it2);
        e.push_back(new enemigo(limite_x - 1, rand() % limite_y));
      }

    }

    for (it = B.begin(); it != B.end(); it++) {
      
      (*it)->mover();
      
      if ((*it)->fuera()) {
        (*it)->borrar();
        delete(*it);
        it = B.erase(it);
      }
    }

      for(it2 = e.begin(); it2 != e.end(); it2++){
        
        for(it = B.begin(); it != B.end(); it++){

          if(((*it)->X() == (*it2)->X()) && ((*it)->Y() == (*it2)->Y())){

            (*it2)->explotar();
            delete(*it2);
            it2 = e.erase(it2);
            
            e.push_back(new enemigo(limite_x - 1, rand() % limite_y - 3));

            (*it)->borrar();
            delete(*it);
            it = B.erase(it);

            N.puntaje += 5;

            if(randbool(25)) N.vida += 1;
          }
        }
      }

    N.mover();
    N.pintarGui();
    timer += 1;    
    Sleep(70);
  }
  GameOver(N);
}