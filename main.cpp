/* Esse trabalho apresenta o gerenciamento (usando listas encadeadas) de carros, vans e utilitarios. E possivel fazer operacoes de insercao, busca e remocao
 * Os nos podem ser colocados em uma arvore binaria e em uma arvore AVL e sao impressos em pre-ordem
 * 
 * Nome: Barbara Silveira Rodrigues
 * RA: 2021.1.08.042
 * Curso: Ciência da Computação         Instituição: UNIFAL-MG 
 * Matéria: Algoritmo e Estrutura de Dados II (AEDsII)
 */

#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "arvore.h"
using namespace std;

tLista *BD;

int main()
{
  // Inicializacao e alocacao da arvore binaria
  noArvB *raizAB = NULL;
  
  // Inicializacao e alocacao da arvore AVL
  noAVL *raizAVL = NULL;

  // Inicializacao do cabecalho e da lista principal
  BD = inicia_lista();
  no *p = new (no);
  BD->lista = p;

  no *ant;
  
  // Leitura do arquivo
  ifstream myfile("BD_veiculos.txt");
  if(myfile.is_open())
  {
    while(!myfile.eof())
    {
      ant = p;
      p->veiculo = new Tveiculo;
      myfile >> p->veiculo->modelo;
      myfile >> p->veiculo->marca;
      myfile >> p->veiculo->tipo;
      myfile >> p->veiculo->ano;
      myfile >> p->veiculo->km;
      myfile >> p->veiculo->potencia;
      myfile >> p->veiculo->combustivel;
      myfile >> p->veiculo->cambio;
      myfile >> p->veiculo->direcao;
      myfile >> p->veiculo->cor;
      myfile >> p->veiculo->portas;
      myfile >> p->veiculo->placa;
      myfile >> p->veiculo->valor;
      BD->tam++;
      p->prox = new(no);
      p = p->prox;
    }
    delete(p);
    ant->prox->prox = NULL;
    ant->prox = NULL;// com isso o ultimo nao aparece mas a busca funciona
    myfile.close();
  } else {
    cout << "Nao foi possivel abrir o arquivo." << endl;
    return EXIT_SUCCESS;
  }
    
  cout << "-----------------------------------------" << endl;
  cout << "Gerenciador de Carros, Vans e Utilitarios" << endl;
  cout << "-----------------------------------------" << endl; 
    
  int opc;
    
  do
  {
    cout << "Escolha a funcionalidade que deseja: " << endl;
    cout << "(1) Busca" << endl;
    cout << "(2) Inserir" << endl;
    cout << "(3) Relatorio" << endl;
    cout << "(4) Relatorio AVL" << endl;
    cout << "(5) Relatorio Arvore Binaria" << endl;
    cout << "(0) Sair" << endl;
    cin >> opc;
        
    switch (opc)
    {
      case 1: // Busca
      {
        string placaBus;
        no *retornoB;
        char opcB;
                
        cout << "Digite a placa do veiculo buscado: " << endl;
        cin >> placaBus;
                
        retornoB = busca(BD, placaBus);
                
        if(retornoB == NULL)
        {
          cout << "Veiculo não encontrado." << endl;
        } else {
          cout << "Veiculo encontrado. Deseja excluir?(s/n)" << endl;
          cin >> opcB;
          if(opcB == 's')
          {
            remove(BD, retornoB);
            cout << "Veiculo excluido." << endl;
          } else if(opcB == 'n')
          {
            cout << "Veiculo nao sera apagado." << endl;
          } else {
            cout << "Digito invalido." << endl;
          }
        }
    }
    break;
            
    case 2: // Inserir
    {
      string placaIns;
                
      cout << "Digite a placa do veiculo que deseja inserir: " << endl;
      cin >> placaIns;
                
      if(busca(BD, placaIns) == NULL) // Nao e uma placa repetida
      {
        insere(BD, placaIns);
        cout << "Veiculo inserido." << endl;
      } else {
        cout << "Veiculo nao foi inserido. Placa duplicada." << endl;
      }  
    }
    break;
            
    case 3: // Relatorio
    {
      imprime(BD);
    }
    break;
            
    case 4: // Relatorio AVL
    {
      cout << "Essa arvore AVL foi criada com um filtro para veiculos com o ano menor ou igual a 2016 estarem incluidos." << endl;
      cout << endl;

      no *percorre = BD->lista;
      while(percorre != NULL)
      {
        if(percorre->veiculo->ano <= 2016)
          raizAVL = insereAVL(raizAVL, percorre->veiculo);
        percorre = percorre->prox;
      }
      imprimeAVL(raizAVL);
      cout << endl;
      cout << "O nivel maximo dessa arvore e: " << tamanho_no(raizAVL) << endl;
      raizAVL = encerra_arvoreAVL(raizAVL);

    }
    break;
            
    case 5: // Relatorio Arvore Binaria
    {
      cout << "Essa arvore binaria foi criada com um filtro para veiculos com o ano maior ou igual a 2016 estarem incluidos." << endl;
      cout << endl;

      no *percorre2 = BD->lista;
      while(percorre2 != NULL)
      {
        if(percorre2->veiculo->ano >= 2016)
          raizAB = insere_ABinario(raizAB, percorre2->veiculo);
        percorre2 = percorre2->prox;
      }
      imprimeAB(raizAB);
      cout << endl;
      cout << "O nivel maximo dessa arvore e: " << tamanho_noArvB(raizAB) << endl; 
      raizAB = encerra_arvore(raizAB);
    }
    break;
            
    case 0: // Sair
    {
      cout << "Obrigada por usar!" << endl;
    }
    break;
            
    default: // Usuario digita errado/invalido
    {
      cout << "Digito invalido. Digite novamente." << endl;
    }
    break;
    }
  } while(opc != 0);

  rename("BD_veiculos.txt", "BD_Backup.txt"); // O antigo arquivo agora sera o backup
            
  ofstream arquivo;
  arquivo.open("BD_veiculos.txt", ios::out);
    
  if(arquivo.is_open())
  {
    no *fim = BD->lista;
    while(fim != NULL)
    {
      arquivo << fim->veiculo->modelo << " ";
      arquivo << fim->veiculo->marca << " ";
      arquivo << fim->veiculo->tipo << " ";
      arquivo << fim->veiculo->ano << " ";
      arquivo << fim->veiculo->km << " ";
      arquivo << fim->veiculo->potencia << " ";
      arquivo << fim->veiculo->combustivel << " ";
      arquivo << fim->veiculo->cambio << " ";
      arquivo << fim->veiculo->direcao << " ";
      arquivo << fim->veiculo->cor << " ";
      arquivo << fim->veiculo->portas << " ";
      arquivo << fim->veiculo->placa << " ";
      arquivo << fim->veiculo->valor << endl;
      fim = fim->prox;
    }
  }
  arquivo.close();
    
  encerra_lista(BD);
         
  return (EXIT_SUCCESS);
}
 

