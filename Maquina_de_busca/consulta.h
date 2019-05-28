#include <list>

#include "palavra.h"
#include "coordenada.h"

#pragma once
class Consulta
{
	list<Palavra> palavras_;
	Coordenada coordenada_;
public:
	Consulta();
	~Consulta();
};

