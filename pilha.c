/*
Autor: Tomás de Carvalho Coelho, Eng comp, 418391
*/

// pilha só pra numeros positivos;
// pq eu nao confio no usuario pra freear a memoria.

#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
  struct NO* prox;
  int chave;
} no;

typedef no* stack_t;

stack_t* criar_pilha() {
  stack_t* pilha = malloc(sizeof(stack_t));
  *pilha = NULL;
  return pilha;
}

void push(stack_t* pilha, int chave) {
  no* nvo_elem = malloc(sizeof(no));
  nvo_elem->chave = chave;
  if (*pilha != NULL) {
    nvo_elem->prox = *pilha;
  }
  else {
    nvo_elem->prox = NULL;
  }
  *pilha = nvo_elem;
}

int pop(stack_t* pilha) {
  no* x = (*pilha);
  if (x != NULL) {
    int chave = x->chave;
    *pilha = (*pilha)->prox;
    free(x);
    return chave;
  }
  else {
    return -1;
  }
}

int main() {
  stack_t* pilha = criar_pilha();
  for (int i = 0; i < 30; i++) {
    push(pilha, i);
  }
  for (no* elem_atual = *pilha; elem_atual != NULL; elem_atual = elem_atual->prox) {
    printf("%d\n", elem_atual->chave);
  }


  return 0;
}
