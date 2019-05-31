#include <iostream>
#include <cmath>

#include "documento.h"
#include "indice_invertido.h"

Documento::Documento()
{
}

Documento::Documento(string nome)
{
	this->nome_ = nome;
}


int Documento::BuscarVezesQuePalavraAparece(Palavra palavra)
{
	return this->palavras_[palavra];
}

void Documento::CalcularCoordenadaParaCadaPalavra(const IndiceInvertido& indiceInvertido, int numeroTotalDeDocumentos)
{
	for (auto& palavra : this->palavras_) {
		int tf = BuscarVezesQuePalavraAparece(palavra.first);
		double idf = log10(numeroTotalDeDocumentos / BuscarQuantidadeDeDocumentosAssociadosAUmaPalavra(indiceInvertido, palavra.first));
		this->coordenada_.AtualizarValorDaPalavra(palavra.first, tf * idf);
	}
}

void Documento::AtribuirCoordenada(Coordenada coordenada) {
	this->coordenada_ = coordenada;
}

Documento::~Documento()
{
}