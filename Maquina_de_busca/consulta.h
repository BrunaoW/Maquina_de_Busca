#ifndef CONSULTA_H_
#define CONSULTA_H_

#include <list>

#include "palavra.h"
#include "coordenada.h"

class Consulta
{
	list<Palavra> palavras_;
	Coordenada coordenada_;
public:
	// Construtor da Consulta
	Consulta();

	~Consulta();
};

#endif // !CONSULTA_H_
