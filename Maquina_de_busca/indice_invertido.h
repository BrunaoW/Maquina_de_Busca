#ifndef INDICE_INVERTIDO_H_
#define INDICE_INVERTIDO_H_

#include <iostream>
#include <map>
#include <string>
#include <set>

#include "documento.h"
#include "coordenada.h"

using namespace std;

class IndiceInvertido
{
	map<string, set<Documento>> registros_;

	public:
	// Inicializa indice invertido
	IndiceInvertido();
	
	~IndiceInvertido();

	map<Palavra, set<Documento>>& ObterRegistros();
};

#endif // !INDICE_INVERTIDO_H_


