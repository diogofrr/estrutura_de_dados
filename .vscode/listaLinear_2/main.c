// #2 - OTIMIZAÇÃO DO CONTEÚDO APRENDIDO NA AULA 1 DE LISTA LINEAR

#include <stdio.h>

// TAMANHO PRÉ DEFINIDO DE ELEMENTOS DA ESTRUTURA
#define MAX 50

// RENOMEIA O TIPO INT PARA "TIPOCHAVE"
typedef int TIPOCHAVE;

// CRIA O VALOR BOOLEANO
typedef int bool;
enum { false, true };

// TIPO DO REGISTRO
typedef struct {
  TIPOCHAVE chave;
} REGISTRO;

// ARRANJO DOS REGISTROS COM TAMANHO MAX E O NÚMERO DE ELEMENTOS
typedef struct {
  REGISTRO A[MAX+1];
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

// BUSCA POR ELEMENTO DE FORMA SEQUENCIAL OTIMIZADA (SENTINELA)
int buscaSentinela(LISTA* lista, TIPOCHAVE chave) {
  int i = 0;
  lista->A[lista->nroElem].chave = chave;

  while(lista->A[i].chave != chave) i++;
  if (i == lista->nroElem) return -1;
  else return i;
}

//BUSCA POR ELEMENTO DE FORMA BINÁRIA
int buscaBinaria(LISTA* lista, TIPOCHAVE chave) {
  int esq, dir, meio;
  esq = 0;
  dir = lista->nroElem - 1;

  while (esq <= dir) {
    meio = ((esq + dir) / 2);
    if (chave == lista->A[meio].chave) return meio;
    else {
      if (lista->A[meio].chave < chave) esq = meio + 1;
      else dir = meio - 1;
    }
  }
  return -1;
}


// INSERE UM ELEMENTO EM UMA POSIÇÃO ESPECÍFICA E JOGA OS OUTROS ELEMENTOS UMA POSIÇÃO A FRENTE
bool inserirElemLista(LISTA* lista, REGISTRO registro, int indice) {
  int indiceIt;
  if ((lista->nroElem == MAX) || (indice < 0) || (indice > lista->nroElem))
    return false;

  for (indiceIt = lista->nroElem; indiceIt > indice; indiceIt--) {
    lista->A[indiceIt] = lista->A[indiceIt - 1];
  }

  lista->A[indice] = registro;
  lista->nroElem++;
  return true;
}

// INSERÇÃO DE ELEMENTOS DE FORMA ORDENADA
bool inserirElemListaOrd(LISTA* lista, REGISTRO registro) {
  if (lista->nroElem >= MAX) return false;

  int pos = lista->nroElem;

  while(pos > 0 && lista->A[pos-1].chave > registro.chave) {
    lista->A[pos] = lista->A[pos-1];
    pos--;
  }

  lista->A[pos] = registro;
  lista->nroElem++;
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

int main() {
  LISTA lista; 

  int num = 0;
  REGISTRO pos;
  
  bool elemExcluido = false;
  int chaveLocalizada;

  pos.chave = 2;

  // INICIALIZANDO A LISTA
  inicializarLista(&lista);
  printf("Lista inicializada!");
  printf("\n----------------------------\n");
  printf("Elemento adicionado na posicao: %i", pos);
  inserirElemLista(&lista, pos, num);
  printf("\n----------------------------\n");
  printf("Tamanho da lista: %i", lista.nroElem);
  printf("\n----------------------------\n");
  exibirLista(&lista);
  printf("\n----------------------------\n");
  chaveLocalizada = buscaSequencialLista(&lista, pos.chave);
  printf("Posicao do elemento especifico: %i", chaveLocalizada);
  printf("\n----------------------------\n");
  elemExcluido = excluirElemento(2, &lista);
  printf("Elemento excluido: ");
  printf(elemExcluido == true ? "Sim - (%i)" : "Nao - (%i)", lista.nroElem);
  printf("\n============================\n");

  return 0;
}