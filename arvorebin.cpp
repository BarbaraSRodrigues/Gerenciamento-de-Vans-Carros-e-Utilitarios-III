#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include "arvore.h"
using namespace std;

/**
 * Insere o no da lista principal dentro da arvore binaria
 * @param no da raiz
 * @param tveiculo do no que vai ser inserido
 * @return o no inserido na arvore binaria 
 */
noArvB *insere_ABinario(noArvB *raiz, Tveiculo *insLis)
{
  if(raiz == NULL) 
  {  
    noArvB *ins = new noArvB;
    ins->veiculo = insLis;
    ins->dir = ins->esq = NULL;
    raiz = ins;
    return ins;
  }

  // Acha onde o novo no vai ser inserido
  if(raiz->veiculo->placa > insLis->placa) // escreve na subarvore esquerda
  {
    raiz->esq = insere_ABinario(raiz->esq, insLis);
  } else { // na subarvore direita
    raiz->dir = insere_ABinario(raiz->dir, insLis);
  }
  return raiz;
}

/**
 * Imprime um no
 * @param no da raiz da arvore binaria
 */
void imprimeno(noArvB *ptr)
{
  cout << ptr->veiculo->modelo << " ";
  cout << ptr->veiculo->marca << " ";
  cout << ptr->veiculo->tipo << " ";
  cout << ptr->veiculo->ano << " ";
  cout << ptr->veiculo->km << " ";
  cout << ptr->veiculo->potencia << " ";
  cout << ptr->veiculo->combustivel << " ";
  cout << ptr->veiculo->cambio << " ";
  cout << ptr->veiculo->direcao << " ";
  cout << ptr->veiculo->cor << " ";
  cout << ptr->veiculo->portas << " ";
  cout << ptr->veiculo->placa << " ";
  cout << ptr->veiculo->valor << ".00" << endl;
}

/*
 * Imprime em pre ordem a arvore binaria
 * @param no da raiz da arvore binaria
*/
void imprimeAB(noArvB *raiz)
{
  if(raiz == NULL)
  {
    cout << "Arvore vazia" << endl;
    return;
  } else {
    imprimeno(raiz);
    if(raiz->esq != NULL)
    {
      imprimeAB(raiz->esq);
    }
    if(raiz->dir != NULL)
    {
      imprimeAB(raiz->dir);
    } 
  }
}

/*
 * Calcula o tamanho do no
 * @param no da raiz da arvore binaria
*/
int tamanho_noArvB(noArvB *raiz)
{
  if(raiz == NULL)
  {
    return -1;
  } else {
    int esq = tamanho_noArvB(raiz->esq);
    int dir = tamanho_noArvB(raiz->dir);
    if(esq > dir)
      return esq + 1;
    else
      return dir + 1;
  }
}

/*
 * Encerra a arvore
 * @param raiz da arvore binaria
 * @return retorna NULL para a raiz da arvore binaria
*/
noArvB *encerra_arvore(noArvB *raiz)
{
  if(raiz != NULL)
  {
    encerra_arvore(raiz->esq);
    encerra_arvore(raiz->dir);
    delete(raiz);
  }

  return NULL;
}