#include <iostream>
#include <map>

#include "Palavra.h"

using namespace std;

#pragma once
class Coordenada
{
	map<Palavra, double> posicao_;
public:
	Coordenada();
	~Coordenada();
};

