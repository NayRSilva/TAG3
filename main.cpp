// Bruno Sanguinetti Regadas de Barros (18/0046063)
// Nayara Silva Nayara Rossi Brito da Silva ()
// Unb, Brasília, DF, 2019

#include <iostream>
#include <vector>
#include <list>
#include "construtor.h"

using namespace std;

void a(int v) {
	cout << v << " ";
}

int main(int argc, char** argv) {


	Professor professores;
	Escolas escolas;

	fstream arquivo1("entradaProj3TAG.txt");
	// fstream arquivo2("entradaProj3TAG.txt");
	// fstream arquivo3("entradaProj3TAG.txt");

	professores = vetorizaProfessores(arquivo1);
	//escolas = vetorizaEscolas(arquivo2);

	//Grafo fluxo = criarGrafo ("entradaproj3TAG.txt");

	return 0;

}