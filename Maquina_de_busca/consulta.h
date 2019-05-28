#include <list>

#include "Palavra.h"
#include "Coordenada.h"

#pragma once
class Consulta
{
	list<Palavra> palavras_;
	Coordenada coordenada_;
public:
	Consulta();
	~Consulta();
};

