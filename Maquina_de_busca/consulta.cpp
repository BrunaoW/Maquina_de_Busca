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

void Consulta::CalcularCoordenadasParaPalavras(IndiceInvertido& indiceInvertido, int numeroDeDocumentos)
{
	for (auto& palavra : palavras_) {
		double tf = palavra.second;
		double idf = log10(numeroDeDocumentos / indiceInvertido.BuscarQuantidadeDeDocumentosAssociadosAUmaPalavra(palavra.first));
	
		this->coordenada_.AtualizarValorDaPalavra(palavra.first, tf * idf);
	}
}

void Consulta::AtribuirPalavras(string frase)
{
	char* fraseASeparar = &frase[0u];
	char* tokenSeparador = new char(' ');

	strtok(fraseASeparar, tokenSeparador);

	while (fraseASeparar != NULL) {
		string fraseAAdicionar(fraseASeparar);

		LeituraArquivos::NormalizarPalavra(fraseAAdicionar);
		this->palavras_[Palavra(fraseAAdicionar)]++;
		fraseASeparar = strtok(NULL, tokenSeparador);
	}
}


