#include "coordenada.h"



Coordenada::Coordenada()
{
}


Coordenada::~Coordenada()
{
}

void Coordenada::IncluirPosicao(Palavra palavra, double valor = 0) {
	this->posicao_.insert({palavra, valor})
}