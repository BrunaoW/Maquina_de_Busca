#include <iostream>
#include <map>

#include "palavra.h"

using namespace std;

#pragma once
class Coordenada
{
	map<Palavra, double> posicao_;
public:
	// Inicializar coordenada
	Coordenada();
	
	~Coordenada();

	// Incluir um novo eixo, i.e., uma nova palavra, e seu respectivo valor
	void IncluirPosicao(Palavra palavra, double valor = 0);
};

