#include "indice_invertido.h"

IndiceInvertido::IndiceInvertido()
{
}


IndiceInvertido::~IndiceInvertido()
{
}

map<Palavra, set<Documento>>& IndiceInvertido::ObterRegistros() {
	return this->registros_;
}

void IndiceInvertido::CalcularCoordenadasParaMapaDePalavras(Documento& documento, int numeroDeDocumentos)
{
	for (auto& palavra : documento.palavras_) {
		int tf = documento.BuscarVezesQuePalavraAparece(palavra.first);
		double idf = log10((double)numeroDeDocumentos / BuscarQuantidadeDeDocumentosAssociadosAUmaPalavra(palavra.first));
		documento.coordenada_.AtualizarValorDaPalavra(palavra.first, tf * idf);
	}
}

double IndiceInvertido::BuscarQuantidadeDeDocumentosAssociadosAUmaPalavra(Palavra palavra)
{
	set<Documento> documentos = this->registros_[palavra];
	return (double)documentos.size();
}