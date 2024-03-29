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
	map<Palavra, set<Documento>>& ObterRegistros();
	
	// Calcula coordenadas para cada um dos documentos, a partir do indice invertido
	void CalcularCoordenadasParaMapaDePalavras(Documento& documento, int numeroDeDocumentos);

	// Retorna a quantidade de documentos associados a uma palavra
	double BuscarQuantidadeDeDocumentosAssociadosAUmaPalavra(Palavra palavra);

	// Destrutor do Indice Invertido
	~IndiceInvertido();
};

#endif // INDICE_INVERTIDO_H


