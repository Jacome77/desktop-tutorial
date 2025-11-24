typedef struct nodo {
  char Pan [19+1];
  double Monto ;
  char Expirations_Date [5+1];
  int CVV ;
  char franquicia[30];
  int estado ;
  int referncia;
  struct nodo *next;
  struct nodo *back;

}ttransaccion;

int Validar_pan(const char *pan);
void Flow_Buy();
int validar_numero(const char *val);
int  Validar_monto(const char *monto);
int  vacio ();