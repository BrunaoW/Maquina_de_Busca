#ifndef INDICE_INVERTIDO_H_
#define INDICE_INVERTIDO_H_

#include <iostream>
#include <map>
#include <string>
#include <set>

#include "documento.h"
#include "palavra.h"

using namespace std;

class IndiceInvertido
{
	map<Palavra, set<Documento>> registros_;

	public:
	// Inicializa indice invertido
	IndiceInvertido();

	// Retornar os registros do indice invertido
	map<Palavra, set<Documento>>& ObterRegistros();
	
	// Retorna a quantidade de documentos associados a uma palavra
	friend int BuscarQuantidadeDeDocumentosAssociadosAUmaPalavra(IndiceInvertido indiceInvertido, Palavra palavra);

	~IndiceInvertido();
};

#endif // !INDICE_INVERTIDO_H_


