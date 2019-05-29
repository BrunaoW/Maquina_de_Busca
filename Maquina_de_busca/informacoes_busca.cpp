#include "informacoes_busca.h"

InformacoesBusca::InformacoesBusca()
{
}


InformacoesBusca::~InformacoesBusca()
{
}


void InformacoesBusca::InicializarCoordenadaPadrao()
{
	Coordenada coordenadaACriar;
	map<Palavra, set<Documento>>& registros = this->indiceInvertido_.ObterRegistros();

	for (auto const& registro : registros) {
		coordenadaACriar.IncluirPosicao(registro.first);
	}

	this->coordenadaPadrao_ = coordenadaACriar;

	for (Documento& documento : documentos_) {
		documento.AtribuirCoordenada(this->coordenadaPadrao_);
	}
}