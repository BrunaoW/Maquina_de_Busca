#include <iostream>
#include <map>

#include "palavra.h"
#include "coordenada.h"

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

