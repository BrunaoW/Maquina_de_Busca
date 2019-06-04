#include "documento.h"

Documento::Documento()
{
}

Documento::Documento(string nome)
{
	this->nome_ = nome;
}

string Documento::ObterNome()
{
	return this->nome_;
}

bool operator<(const Documento& documento1, const Documento& documento2)
{
	return documento1.nome_ < documento2.nome_;
}

map<Palavra, int>& Documento::ObterPalavras()
{
	return this ->palavras_;
}

void Documento::AtribuirCoordenada(Coordenada coordenada) {
	this->coordenada_ = coordenada;
}

int Documento::BuscarVezesQuePalavraAparece(Palavra palavra)
{
	return this->palavras_[palavra];
}

Documento::~Documento()
{
}