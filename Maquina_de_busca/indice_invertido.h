#pragma once

#include <iostream>
#include <map>
#include <string>
#include <set>

#include "Documento.h"
#include "Coordenada.h"

using namespace std;

class IndiceInvertido
{
	map<string, set<Documento>> registros_;
	Coordenada coordenadaPadrao;

	public:
	IndiceInvertido();
	~IndiceInvertido();
};

