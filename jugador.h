class jugador {

    int x, y;

  public:

    jugador(int X, int Y);

    int puntaje = 0;
    int vida = 3;

    int X() {
      return x;
    }
    int Y() {
      return y;
    }
    void cor();
    void pintarGui();
    void pintar();
    void borrar();
    void mover();
    void explotar();
};

