#include <iostream>
#include <map>
#include <string>
#include <set>

#include "palavra.h"
#include "documento.h"

#ifndef INDICE_INVERTIDO_H
#define INDICE_INVERTIDO_H

using namespace std;

class IndiceInvertido
{
	map<Palavra, set<Documento>> registros_;

	public:
	// Inicializa indice invertido
	IndiceInvertido();

	// Retornar os registros do indice invertido
	map<Palavra, set<Documento>> ObterRegistros();
	
	void CalcularCoordenadasParaMapaDePalavras(Documento documento, int numeroDeDocumentos);

	// Retorna a quantidade de documentos associados a uma palavra
	int BuscarQuantidadeDeDocumentosAssociadosAUmaPalavra(Palavra palavra);

	~IndiceInvertido();
};

#endif // INDICE_INVERTIDO_H


