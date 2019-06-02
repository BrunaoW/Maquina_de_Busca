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

bool Documento::operator<(const Documento& documento)
{
	return this ->nome_<documento.nome_;
}

map<Palavra, int> Documento::ObterPalavras()
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