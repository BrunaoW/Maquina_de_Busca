#include <list>

#include "palavra.h"
#include "coordenada.h"

#ifndef CONSULTA_H
#define CONSULTA_H

class Consulta
{
	list<Palavra> palavras_;
	Coordenada coordenada_;
	public:
	// Construtor da Consulta
	Consulta();

	~Consulta();

	// Atribuir coordenada padrao a consulta
	void AtribuirCoordenada(Coordenada coordenada);
};

#endif // CONSULTA_H
