typedef struct{
  int peso;
  int altura;
} PesoAltura; // ATRIBUI UM NOME PARA UMA ESTRUTURA

typedef int CHAVE; // TROCA O NOME DE INT PARA CHAVE

#define alturuaMaxima 225 // CRIA UMA CONSTANTE

int main() {
  PesoAltura* pessoa1 = (PesoAltura*) malloc(sizeof(PesoAltura));
  pessoa1->altura = 220; // QUANDO A VARIÁVEL FOR PONTEIRO, USAMOS UMA SETA
  pessoa1->peso = 123;
}