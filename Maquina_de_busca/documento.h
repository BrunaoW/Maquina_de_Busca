#include <map>
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

	public:
	// Inicializar documento
	Documento();
	// Inicializar o documento com o nome do arquivo
	Documento(string nome);
	//obter nome string
	string ObterNome();

	bool operator<(const Documento& documento);
	map<Palavra, int> ObterPalavras();

	// Atribuir coordenada a documento
	void AtribuirCoordenada(Coordenada coordenada);

	// Buscar palavra que existe no documento e retornar a quantidade de vezes que ela aparece
	int BuscarVezesQuePalavraAparece(Palavra palavra);

	friend class IndiceInvertido;

	~Documento();
};

#endif // DOCUMENTO_H

