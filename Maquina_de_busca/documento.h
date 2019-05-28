#include <iostream>
#include <map>

#include "Palavra.h"
#include "Coordenada.h"

using namespace std;

#pragma once
class Documento
{
	string nome_;
	map<Palavra, int> palavras_;
	Coordenada coordenada_;

public:
	Documento();
	~Documento();
};

