#include "consulta.h"



Consulta::Consulta()
{
}

map<Palavra, double> Consulta::ObterCoordenada()
{
	return coordenada_.ObterPosicao();
}


Consulta::~Consulta()
{
}

void Consulta::AtribuirCoordenada(Coordenada coordenada)
{
	this->coordenada_ = coordenada;
}
