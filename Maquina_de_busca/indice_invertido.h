#pragma once

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
	Coordenada coordenadaPadrao;

	public:
	IndiceInvertido();
	~IndiceInvertido();
};

