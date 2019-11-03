// Bruno Sanguinetti Regadas de Barros (18/0046063)
// Nayara Silva Nayara Rossi Brito da Silva ()
// Unb, Brasília, DF, 2019

#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include "construtor.h"
using namespace std;

vector<string> split(string s, char delim)
{
	vector<string> flds;
	if (!flds.empty())
	{
		flds.clear();
	}
	string work = s;
	string buf = "";
	int i = 0;
	while (i < work.length())
	{
		if (work[i] != delim)
		{
			buf += work[i];
		}
		else if (buf.length() > 0)
		{
			flds.push_back(buf);
			buf = "";
		}
		i++;
	}
	if (!buf.empty())
	{
		flds.push_back(buf);
	}
	return flds;
}

string replaceChar(string str, char ch1, char ch2)
{
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == ch1)
			str[i] = ch2;
	}

	return str;
}
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
vector<vector<int>> vetorizaProfessores(fstream &fileStream)
{

	if (!fileStream.is_open())
	{
		printf("ERROR: Leitura do Arquivo - vetorizaProfessores()");
		exit(EXIT_FAILURE);
	}
	Professor n;
	string buffer;
	string teste;

	int i = 0;
	int j = 0;

	for (int h = 0; h < 3; h++)//pulando linha
	{ 
		getline(fileStream, buffer);
	}
	while (getline(fileStream, buffer))
	{
		if (buffer[0] == '/')
		{ //para de ler o arquivo quando acaba a parte dos professores
			printf("xau");
			break;
		}
		//imprime o buffer p conferir
		//	cout<< buffer;
		//getchar();
		teste = replaceChar(buffer, '(', ' '); //funçao pra fazer replace do char pq a pocaria da funçao replace do c++ nao ta funcionando comigo, maldita linguagem infernal
		teste = replaceChar(teste, ')', ' ');
		teste = replaceChar(teste, ',', ' ');
		teste = replaceChar(teste, 'E', ' ');
		teste = replaceChar(teste, 'P', ' ');
		teste = replaceChar(teste, ':', ' ');
		cout << "ou" << teste;
		//agora devo ter algo no sentido 1 3 10 20 1 3(string)
		//da o cout p testar
		//cout<<"ou"<<teste;
		//vou dividir isso em vetore 1 3 10 30 1
		vector<string> palavras;
		vector<int> numero;
		palavras = split(teste, ' ');//separa minha string em array de string
		int aux;//aux p conversao de string em int
		const char *a;//nao sei como foi so sei que
		for (int h = 0; h < palavras.size(); h++)
		{
			a = palavras[i].c_str();
			sscanf(a, "%d", &aux);
			numero.push_back(aux);
		}
		//Funçao p imprimir o vetor e verificar bunitinho
		// for(i= 0; i<numero.size(); i++){
		// 	cout<<"\n"<<"ola os numero"<< numero[i]<<"\n";
		// }

		//estrutura do vetor numero: [P, habilitaçao, Escolas...]
		vector<int> habilitacao;
		for (int h = 1; h < numero.size(); h++)
		{
			if (h == 1)
			{
				habilitacao.push_back(numero[h]); //como temos um vetor de vetor, nao posso so mandar uma int, tenho que mandar um vetor de int contendo apenas uma posição
				n.push_back(habilitacao);		  //logo apos esse passo eu tenho
												  //vetor n:[[1] ]
			}
			else
			{
			}
		}

		// 	getchar();
		// 	cout<<"ou"<<teste;
		// 	getchar();
		// 	//if (buffer.find("P") != string::npos) {			// Procura pela string nome
		// 	printf("enteir");
		// 	getchar();

		// 		n[i][j] = c_habilitacao;
		// 		i++;						// Insere no vetor
		// //	}
		// 	if (buffer.find('\n')) {
		// 		j++;
		// 		printf("f %d", j);
		// 	getchar();
		//}
	}
	printf("cabo while");
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