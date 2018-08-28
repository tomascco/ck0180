/*
Autor: Tomás de Carvalho Coelho, Eng comp, 418391
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
  struct NO* ant;
  int chave;
  struct NO* prox;
} no;

typedef struct HEADER {
  no* head;
} header;

header* criar_lista() {
  header* lista = malloc(sizeof(header));
  lista->head = NULL;
  return lista;
}

void adicionar_elemento(header* lista, int chave) {
  no* nvo_elemento = malloc(sizeof(no));
  if (lista->head == NULL) {
    nvo_elemento->ant = NULL;
    nvo_elemento->prox = NULL;
  }
  else {
    nvo_elemento->prox = lista->head;
    (lista->head)->ant = nvo_elemento;
  }
  nvo_elemento->ant = NULL;
  lista->head = nvo_elemento;
  nvo_elemento->chave = chave;
}

void remover_elemento(header* lista, no* removendo) {
  if (removendo->ant == NULL) {
    (removendo->prox)->ant = NULL;
    lista->head = removendo->prox;
  }
  else if (removendo->prox == NULL) {
    (removendo->ant)->prox = NULL;
  }
  else {
    (removendo->ant)->prox = removendo->prox;
    (removendo->prox)->ant = removendo->ant;
  }
  free(removendo);
}

int main() {
  header* lista = criar_lista();
  for (int i = 0; i < 30; i++) {
    adicionar_elemento(lista, i);
  }
  no* elemento_atual = (lista->head);
  while (elemento_atual != NULL) {
    printf("elemento: %d\n", elemento_atual->chave);
    elemento_atual = elemento_atual->prox;
  }
}
