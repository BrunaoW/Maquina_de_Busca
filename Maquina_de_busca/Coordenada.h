#include <iostream>
#include <map>

#include "palavra.h"

using namespace std;

#pragma once
class Coordenada
{
	map<Palavra, double> posicao_;
public:
	Coordenada();
	~Coordenada();
};

