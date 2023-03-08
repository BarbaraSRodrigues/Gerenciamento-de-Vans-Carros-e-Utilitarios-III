#ifndef ARVORE_H
#define ARVORE_H
using namespace std;


typedef struct
{
  string modelo;
  string marca;
  string tipo;
  int ano;
  int km;
  float potencia;
  string combustivel;
  string cambio;
  string direcao;
  string cor;
  int portas;
  string placa;
  float valor;  
}Tveiculo;

typedef struct no_
{
  Tveiculo *veiculo;
  struct no_ *prox;
}no;

typedef struct cabecalho
{
  struct no_ *lista;
  int tam;
}tLista;

typedef struct noAB
{
  struct noAB *esq;
  Tveiculo *veiculo;
  struct noAB *dir;
}noArvB;

typedef struct node
{
  struct node *esq;
  Tveiculo *veiculo;
  struct node *dir;
  int tam;
}noAVL;


tLista* inicia_lista();
no * busca(tLista * ptlista, string placa);
no *noIns(string placa);
no *insere(tLista *ptlista, string placa);
void imprime(tLista * ptlista);
void remove(tLista *ptlista, no *rem);
tLista * encerra_lista(tLista * ptlista);

noAVL *insereAVL(noAVL *raiz, Tveiculo *ins);
void imprimeAVL(noAVL *raiz);
int tamanho_no(noAVL *p);
noAVL *encerra_arvoreAVL(noAVL *raiz);

noArvB *insere_ABinario(noArvB *raiz, Tveiculo *insLis);
void imprimeAB(noArvB *raiz);
int tamanho_noArvB(noArvB *raiz);
noArvB *encerra_arvore(noAB *raiz);


#endif /* ARVORE_H */