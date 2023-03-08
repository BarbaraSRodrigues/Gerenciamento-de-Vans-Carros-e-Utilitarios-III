#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include "arvore.h"
using namespace std;

/*
 * Calcula o tamanho do no (influencia na hora de calcular o balanceamento)
 * @param: no a ser calculado o tamanho(altura)
 * @return: o tamanho do no
*/
int tamanho_no(noAVL *p)
{
  int te, td;
  te = p && p->esq?p->esq->tam:0;
  td = p && p->dir?p->dir->tam:0;

  return te>td?te+1:td+1;
}

/*
 * Calcula o valor de balanceamento
 * @param: no a ser calculado o fator de balanceamento
 * @return: o fator do no 
*/
int fatorB(noAVL *p)
{
  int te, td;
  te = p && p->esq?p->esq->tam:0;
  td = p && p->dir?p->dir->tam:0;

  return te-td;
}

/*
 * Calcula qual o maior no (de acordo com o parametro que voce passa)
*/
int max(int a, int b)
{
  return (a > b) ? a : b;
}
/*
 * Cria e aloca um novo no
 * @param: o veiculo a ser inserido na arvore
 * @return: o novo no
*/

noAVL *novoNo(Tveiculo *ins)
{
  noAVL *novo = new noAVL;
  novo->veiculo = ins;
  novo->esq = novo->dir = NULL;
  novo->tam = 1;
  return novo;
}

/*
 * Rotacao direita
 * @param: o no que ta com balanceamento errado
 * @return: o no que foi rotacionado
*/
noAVL *rotDir(noAVL *y)
{
  noAVL *x = y->esq;
  noAVL *T2 = x->dir;
  x->dir = y;
  y->esq = T2;
  y->tam = max(tamanho_no(y->esq), tamanho_no(y->dir)) + 1;
  x->tam = max(tamanho_no(x->esq), tamanho_no(x->dir)) + 1;
  return x;
}

/*
 * Rotacao esquerda
 * @param: o no que ta com balanceamento errado
 * @return: o no que foi rotacionado
*/
noAVL *rotEsq(noAVL *x)
{
  noAVL *y = x->dir;
  noAVL *T2 = y->esq;
  y->esq = x;
  x->dir = T2;
  x->tam = max(tamanho_no(x->esq), tamanho_no(x->dir)) + 1;
  y->tam = max(tamanho_no(y->esq), tamanho_no(y->dir)) + 1;
  return y;
}

/*
 * Insere o novo no na arvore AVL
 * @param: no raiz da arvore e o veiculo a ser inserido
 * @return: o no raiz da arvore
*/
noAVL *insereAVL(noAVL *raiz, Tveiculo *ins)
{
  // Insere recursivamente
  if (raiz == NULL) 
    return novoNo(ins);  
  if (ins->placa < raiz->veiculo->placa)
  {
    raiz->esq = insereAVL(raiz->esq, ins);
  } else if (ins->placa > raiz->veiculo->placa) {
    raiz->dir = insereAVL(raiz->dir, ins);
  } else {
    return raiz;
  }

  // Calcula e faz o balanceamento da arvore
  raiz->tam = 1 + max(tamanho_no(raiz->esq), tamanho_no(raiz->dir));
  int fb = fatorB(raiz);
  if (fb > 1 && ins->placa < raiz->esq->veiculo->placa)
    return rotDir(raiz);
  if (fb < -1 && ins->placa > raiz->dir->veiculo->placa)
    return rotEsq(raiz);
  if (fb > 1 && ins->placa > raiz->esq->veiculo->placa)
  {
    raiz->esq = rotEsq(raiz->esq);
    return rotDir(raiz);
  }
  if (fb < -1 && ins->placa < raiz->dir->veiculo->placa)
  {
    raiz->dir = rotDir(raiz->dir);
    return rotEsq(raiz);
  }

  return raiz;
}
/*
 * Imprime um no
 * @param: no a ser printado na tela
*/
void imprimenoAVL(noAVL *ptr)
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
 * Imprime a arvore em pre-ordem
 * @param: raiz da arvore AVL
*/
void imprimeAVL(noAVL *raiz)
{
  if(raiz == NULL)
  {
    cout << "Arvore vazia" << endl;
    return;
  } else {
    imprimenoAVL(raiz);
    if(raiz->esq != NULL)
    {
      imprimeAVL(raiz->esq);
    }
    if(raiz->dir != NULL)
    {
      imprimeAVL(raiz->dir);
    } 
  }
}

/*
 * Encerra a arvore
 * @param raiz da arvore AVL
 * @return NULL para a raiz
*/
noAVL *encerra_arvoreAVL(noAVL *raiz)
{
  if(raiz != NULL)
  {
    encerra_arvoreAVL(raiz->esq);
    encerra_arvoreAVL(raiz->dir);
    delete(raiz);
  }
  return NULL;
}