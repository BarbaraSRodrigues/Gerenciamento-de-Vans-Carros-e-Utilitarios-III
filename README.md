# Gerenciamento-de-Vans-Carros-e-Utilitarios-III
Terceiro trabalho feito em C++ para a matéria de Algoritmo e Estrutura de Dados II, onde a nota foi 100 de 100.

**Objetivo:**
adquirir conhecimentos de manipulação de dados numa aplicação que realiza buscas numa lista principal de carros, vans e utilitários e apresenta os resultados em árvore binária e árvore AVL.

**Descrição:**
o aplicativo desenvolvido no projeto deve criar uma lista ligada principal com os dados lidos de um arquivo de entrada. Os dados de cada linha do arquivo devem ser armazenados em um nó da lista, na ordem apresentada pelas linhas do arquivo (e não pela placa ou outro campo). Então o aplicativo deve construir uma árvore binária e uma árvore AVL a partir da lista principal, sem realocar ou duplicar os nós da lista principal, pelo campo placa dos veículos. Ao final devem ser informados o nível máximo das árvores.

**Arquivo de Dados:** contém um número ilimitado de linhas, onde cada linha possui os dados de um único veículo: modelo, marca, tipo, ano, quilometragem, potência do motor, combustível, câmbio, direção, cor, número de portas, placa e valor.

**Requisitos:**

o aplicativo deverá:

- apresentar um menu ao usuário com as opções de inclusão, exclusão, buscas, árvores, relatório das árvores e relatório da lista principal;
- construir as árvores binária e AVL a partir de buscas aplicadas sobre a lista principal, cada grupo deve implementar algum tipo de filtro para selecionar os veículos;
- apresentar o relatório das árvores percorrendo em pré-ordem;
- apresentar o relatório de todos os clientes na tela do computador;
- ao final da execução todas as estruturas devem ser desalocadas.
