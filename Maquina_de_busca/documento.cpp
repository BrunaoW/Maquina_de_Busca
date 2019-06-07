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

map<Palavra, double> Documento::ObterCoordenada()
{
	return coordenada_.ObterPosicao();
}

void Documento::AtribuirProximidade(double proximidade_)
{
	this->proximidade_ = proximidade_;
}

bool operator<(const Documento& documento1, const Documento& documento2)
{
	return documento1.nome_ < documento2.nome_;
}

map<Palavra, int>& Documento::ObterPalavras()
{
	return this ->palavras_;
}

double Documento::ObterProximidade() const
{
	return this->proximidade_;
}

void Documento::AtribuirCoordenada(Coordenada coordenada) {
	this->coordenada_ = coordenada;
}

int Documento::BuscarVezesQuePalavraAparece(Palavra palavra)
{
	return this->palavras_[palavra];
}

vector<string> Documento::ObterNomesDeDocumentos(list<Documento> documentos)
{
	vector<string> listaDeNomes;

	for (Documento& documento : documentos) {
		listaDeNomes.push_back(documento.nome_);
	}

	return listaDeNomes;
}

Documento::~Documento()
{
}