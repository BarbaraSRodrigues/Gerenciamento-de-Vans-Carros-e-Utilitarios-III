#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include "arvore.h"
using namespace std;

/**
 * Realiza a alocacao do espaco para que a lista possa comecar
 * a receber nos.
 * @return a lista vazia.
 */
tLista* inicia_lista()
{
  tLista* tmp = new (tLista);
	tmp->tam = 0;
	tmp->lista = NULL;

	return tmp;
}

/**
 * Desaloca o espaco previamente alocado para a lista encadeada.
 * @param ptlista ponteiro para a lista.
 * @return NULL para atualizar o ponteiro da lista.
 */
tLista * encerra_lista(tLista * ptlista)
{
	no * ant = ptlista->lista;
	no * pont = ptlista->lista;
	
	while(ant != NULL)
  {
		pont = ant->prox;
    delete(ant->veiculo);		
    delete(ant);
		ant = pont;
	}
	delete(ptlista);
	
  return NULL;
}

/**
 * Busca pela placa da chave passada dentro da lista encadeada.
 * @param banco de dados utilizado.
 * @param placa a ser buscada.
 * @return verdareiro se o elemento foi encontrado.
*/

no * busca(tLista * ptlista, string placa)
{
  no *p = ptlista->lista;

  while(p != NULL)
  {
    if(placa == p->veiculo->placa)
      return p;
    p = p->prox;
  }
  return NULL;
}
 

/**
 * Realiza a insercao do no no início da lista ligada.
 * @param banco de dados utilizado.
 * @param no a ser inserido.
 */
void insere_inicio(tLista * ptlista, no *ins)
{
	no* p;
  p = new(no);
  p->veiculo = ins->veiculo;
  p->prox = ptlista->lista;
  ptlista->lista = p;
  ptlista->tam++;
}

/**
 * Pega o input do usuario para a insercao
 * @param placa digitada no main que veio da funcao void insere()
 * @return o no a ser inserido
 */

no *noIns(string placa)
{
  no *ins = new (no);
  ins->veiculo = new (Tveiculo);
  
  cout << "Digite o modelo: " << endl;
  cin >> ins->veiculo->modelo;
  cout << "Digite a marca: " << endl;
  cin >> ins->veiculo->marca;
  cout << "Digite o tipo: " << endl;
  cin >> ins->veiculo->tipo;
  cout << "Digite o ano: " << endl;
  cin >> ins->veiculo->ano;
  cout << "Digite a km: " << endl;
  cin >> ins->veiculo->km;
  cout << "Digite a potencia: " << endl;
  cin >> ins->veiculo->potencia;
  cout << "Digite o combustivel: " << endl;
  cin >> ins->veiculo->combustivel;
  cout << "Digite o cambio: " << endl;
  cin >> ins->veiculo->cambio;
  cout << "Digite a direcao: " << endl;
  cin >> ins->veiculo->direcao;
  cout << "Digite a cor: " << endl;
  cin >> ins->veiculo->cor;
  cout << "Digite as portas: " << endl;
  cin >> ins->veiculo->portas;
  cout << "Digite o valor: " << endl;
  cin >> ins->veiculo->valor;
  cout << "A placa recebida será a digitada anteriormente" << endl;
  ins->veiculo->placa = placa;
  return ins;
}

/**
 * Insere o no no fim da lista
 * @param banco de dados onde sera inserido
 * @param placa digitada no main(nao sera duplicada)
 * @return o no inserido
 */
no *insere(tLista *ptlista, string placa)
{
  no *atual = ptlista->lista;
  no *ins = noIns(placa);
    
  if(atual == NULL) // Lista vazia
  {
    insere_inicio(ptlista, ins);
  } else {
    while (atual->prox != NULL)
      atual = atual->prox;
    atual->prox = new(no);
    atual->prox->veiculo = ins->veiculo;
    atual->prox->prox = NULL;
    ptlista->tam++;
  }
  return ins;
}

/**
 * Vai remover o no retornado da funcao busca()
 * @param banco de dados que vai ser utilizado
 * @param no a ser removido que vem da funcao busca()
 */

void remove(tLista *ptlista, no *rem)
{
  no *ant = ptlista->lista;
  if(ant == NULL)
  {
    cout << "Lista vazia." << endl;
  } else {
    while(ant != NULL && ant->prox != rem)
    {
      ant = ant->prox;
    }    
    ant->prox = ant->prox->prox;

    free(rem->veiculo);
    free(rem);
    ptlista->tam--;
  }
}

/**
 * Imprime a lista encadeada.
 * @param banco de dados que vai ser utilizado
 */
void imprime(tLista * ptlista)
{
	no * ptr = ptlista->lista;

  if(ptr == NULL)
  {
    cout << "Lista vazia." << endl;
    return;
  }
	while(ptr != NULL)
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
    ptr = ptr->prox;
	}
}
