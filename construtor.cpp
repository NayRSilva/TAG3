// Bruno Sanguinetti Regadas de Barros (18/0046063)
// Nayara Silva Nayara Rossi Brito da Silva ()
// Unb, Brasília, DF, 2019

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "construtor.h"

using namespace std;

/*
vector<vector<int> > criarGrafo (const string& fileName) {
    fstream arquivo(fileName);

    int tamanho = tamanhoGrafo(arquivo); 

    Grafo g;
    
    for (size_t i = 0; i < tamanho; i++) {
		g.push_back(vector<int>());
	}

    montaArestas(arquivo, g);
    return g;
}
*/

/*
size_t tamanhoGrafo (fstream& fileStream) {

	string buffer;
	size_t tamanho = 0;

	if (!fileStream.is_open()) {
		throw "ERROR: Leitura do Arquivo - tamanhoGrafo()";
	}
	else {
		while (getline (fileStream, buffer)) {
		if (buffer.find("node") != string::npos) 	// incrementa o tamanho para cada string "node" encontrada
			tamanho++;
		else if (buffer.find("aresta") != string::npos) // termina ao chegar a primeira aresta
			break;
		}
	}
	return tamanho;
}
*/

/*
void montaArestas (fstream& fileStream, vector<vector<int> >& grafo) {

	if (!fileStream.is_open())
		throw "ERROR: Leitura do Arquivo - montaArestas()";

	string buffer;
	while (getline(fileStream, buffer)) {
		if (buffer.find("origem") != string::npos) {
			int x,y = 0;

            sscanf(buffer.c_str(), "    origem %d", &x);
            getline(fileStream, buffer);
            sscanf(buffer.c_str(), "    destino %d", &y);

			if ((unsigned int) (x-1) >= grafo.size() || (unsigned int) (y-1) >= grafo.size())
				throw "aresta inexistente"; 	
			grafo[x-1].push_back(y-1);
		}
	}
}*/

// retorna um vetor com os nomes das materias, a partir do arquivo lido
vector<vector<int> > vetorizaProfessores (fstream& fileStream) {

	if (!fileStream.is_open()){
		printf("ERROR: Leitura do Arquivo - vetorizaProfessores()");
		exit(EXIT_FAILURE);
	}
	Professor  n;
	string buffer;

	int i = 0;
	int j = 0;
	while (getline(fileStream, buffer)) {
		if (buffer.find(",") != string::npos) {			// Procura pela string nome
			char* habilitacao;

			sscanf(buffer.c_str(), " %s", habilitacao);	// Salva o valor										

			int c_habilitacao = atoi(habilitacao);


			n[i][j] = c_habilitacao;
			i++;						// Insere no vetor
		}

		if (buffer.find('\n')) {
			j++;
    }
	}
	return n;
}

// retorna um vetor com os créditos da materia, a partir do arquivo lido
/*vector<vector<int>> vetorizaCreditos (fstream& fileStream) {
	if (!fileStream.is_open()){
		throw "ERROR: Leitura do Arquivo - vetorizaCreditos()";
	}

	string buffer;
	Escolas c;
	while (getline(fileStream, buffer)) {
		if (buffer.find("creditos") != string::npos) {				// Procura pela string creditos
			int credit = 0;

			sscanf(buffer.c_str(), "    creditos %d", &credit);		// Salva o valor

			c.push_back(credit);									//Insere no vetor
		}

		if (buffer.find("aresta") != string::npos) {
			return c;
    	}
	}

	return c;
}*/