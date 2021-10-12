class enemigo {

    int x, y;

  public:

    enemigo(int X, int Y);

    void colision(struct jugador &N);

    bool limite();
    void pintar();
    void borrar();
    void mover();  
    void explotar(); 

    int X() {
      return x;
    }
    int Y() {
      return y;
    }
};