#include "coordenada.h"

Coordenada::Coordenada()
{
}

map<Palavra, double> Coordenada::ObterPosicao()
{
	return posicao_;
}


Coordenada::~Coordenada()
{
}

void Coordenada::IncluirPosicao(Palavra palavra, double valor) {
	this->posicao_.insert({ palavra, valor });
}

void Coordenada::AtualizarValorDaPalavra(Palavra palavra, double valor)
{
	this->posicao_[palavra] = valor;
}
