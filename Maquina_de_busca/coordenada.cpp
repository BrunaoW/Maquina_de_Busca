#include "coordenada.h"



Coordenada::Coordenada()
{
}


Coordenada::~Coordenada()
{
}

void Coordenada::IncluirPosicao(Palavra palavra, double valor) {
	this->posicao_.insert({ palavra, valor });
}

void Coordenada::AtualizarValorDaPalavra(Palavra palavra, double valor)
{
	posicao_[palavra] = valor;
}
