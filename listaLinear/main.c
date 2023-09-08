// TAMANHO PRÉ DEFINIDO DE ELEMENTOS DA ESTRUTURA
#define MAX 50

// RENOMEIA O TIPO INT PARA "TIPOCHAVE"
typedef int TIPOCHAVE;
typedef int bool;
enum { false, true };

// TIPO DO REGISTRO
typedef struct {
  TIPOCHAVE chave;
} REGISTRO;

// ARRANJO DOS REGISTROS COM TAMANHO MAX E O NÚMERO DE ELEMENTOS
typedef struct {
  REGISTRO A[MAX];
  int nroElem;
} LISTA;

// DEFINE QUE O NÚMERO DE ELEMENTOS VÁLIDOS NA LISTA É 0
void inicializarLista(LISTA* lista) {
  lista->nroElem = 0;
}

// RETORNA A QUANTIDADE DE ELEMENTOS VÁLIDOS
int tamanhoLista(LISTA* lista) {
  return lista->nroElem;
}

// EXIBE TODA A LISTA
void exibirLista(LISTA* lista) {
  int i;
  printf("Lista: \" ");
  for (i = 0; i < lista->nroElem; i++) {
    printf("%i ", lista->A[i].chave);
  }
  printf("\"n");
}

// BUSCA UM ELEMENTO NA LISTA DE FORMA SEQUENCIAL
int buscaSequencialLista(LISTA* lista, TIPOCHAVE chave) {
  int i = 0;

  while (i < lista->nroElem) {
    if (chave == lista->A[i].chave) return i;
    else i++;
  }

  return -1;
}

// INSERE UM ELEMENTO EM UMA POSIÇÃO ESPECÍFICA E JOGA OS OUTROS ELEMENTOS UMA POSIÇÃO A FRENTE
bool inserirElemLista(LISTA* lista, REGISTRO registro, int indice) {
  int indiceIt;
  if ((lista->nroElem == 50) || (indice < 0) || (indice > lista->nroElem))
    return false;

  for (indiceIt = lista->nroElem; indiceIt > indice; indiceIt--) {
    lista->A[indiceIt] = lista->A[indiceIt - 1];
  }

  lista->A[indice] = registro;
  lista->nroElem++;
  return true;
}

// EXCLUI UM ELEMENTO ESPECÍFICO DA LISTA
bool excluirElemento(TIPOCHAVE chave, LISTA* lista) {
  int posicao, indiceIt;
  posicao = buscaSequencialLista(lista, chave);

  if (posicao == -1) return false;

  for (indiceIt = posicao; indiceIt < lista->nroElem - 1; indiceIt++) {
    lista->A[indiceIt] = lista->A[indiceIt + 1];
  }

  lista->nroElem--;
  return true;
}

// DEFINE QUE O NÚMERO DE ELEMENTOS VÁLIDOS NA LISTA É 0 PARA FALSAMENTE REINICIALIZAR A LISTA
void reinicializarLista(LISTA* lista) {
  lista->nroElem = 0;
}