class bala {

    int x, y;

  public:

    bala(int X, int Y);

    void mover();
    void pintar();
    void borrar();
    bool fuera();

    int X() {
      return x;
    }
    int Y() {
      return y;
    }

};