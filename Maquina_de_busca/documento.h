#ifndef DOCUMENTO_H_
#define DOCUMENTO_H_

#include <iostream>
#include <map>

#include "palavra.h"
#include "coordenada.h"
#include "indice_invertido.h"

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

	// Calcula a coordenada para cada palavra presente no documento
	void CalcularCoordenadaParaCadaPalavra(const IndiceInvertido& indiceInvertido, int numeroTotalDeDocumentos);

	~Documento();
};

#endif // DOCUMENTO_H_

