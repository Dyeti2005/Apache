class jugador {
    int x, y;
  public:
    jugador(int X, int Y);
    void pintarGui();
    int X(){return x;}
    int Y(){return y;}
    void pintar();
    void borrar();
    void mover();
};