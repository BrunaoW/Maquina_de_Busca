#include <map>
#include <list>
#include <vector>
#include <iostream>
#include <cmath>

#include "palavra.h"
#include "coordenada.h"

#ifndef DOCUMENTO_H
#define DOCUMENTO_H

using namespace std;

class Documento
{
	string nome_;
	map<Palavra, int> palavras_;
	Coordenada coordenada_;
	double proximidade_;

	public:
	
	// Inicializar documento
	Documento();
	
	// Inicializar o documento com o nome do arquivo
	Documento(string nome);
	
	// Obter nome string
	string ObterNome();

	// Obter coordenada do documento
	map<Palavra, double> ObterCoordenada();

	// Atribui proximidade ao realizar uma consulta
	void AtribuirProximidade(double proximidade_);

	// Definido um comparador para acessar um map de documentos
	friend bool operator<(const Documento& documento1, const Documento& documento2);

	// Obtem as palavras do documento
	map<Palavra, int>& ObterPalavras();

	// Obtem a proximidade dos documentos
	double ObterProximidade() const;

	// Atribuir coordenada a documento
	void AtribuirCoordenada(Coordenada coordenada);

	// Buscar palavra que existe no documento e retornar a quantidade de vezes que ela aparece
	int BuscarVezesQuePalavraAparece(Palavra palavra);

	// Obter lista de nomes dos documentos
	static vector<string> ObterNomesDeDocumentos(vector<Documento> documentos);

	// Indice Invertido declarado como classe amiga para ela ter acesso as propriedades do documento
	friend class IndiceInvertido;

	~Documento();
};

#endif // DOCUMENTO_H

