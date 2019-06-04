#include "mecanismo_de_busca.h"

MecanismoDeBusca::MecanismoDeBusca()
{
}

void MecanismoDeBusca::RotinaMecanismoDeBusca()
{
	cout << "Bem-vindo a rotina de busca de palavras" << endl;

	this->documentos_ = LeituraArquivos::LerArquivosDaPastaAtual();
	LeituraArquivos::LerPalavrasDeDocumentos(this->documentos_, this->indiceInvertido_);

	InicializarCoordenadaPadrao();
	CalcularCoordenadasParaOsDocumentos();
}

void MecanismoDeBusca::InicializarCoordenadaPadrao()
{
	Coordenada coordenadaACriar;
	map<Palavra, set<Documento>>& registros = indiceInvertido_.ObterRegistros();

	for (const auto& registro : registros) {
		coordenadaACriar.IncluirPosicao(registro.first, 0);
	}

	this->coordenadaPadrao_ = coordenadaACriar;

	for (Documento& documento : documentos_) {
		documento.AtribuirCoordenada(this->coordenadaPadrao_);
	}

	this->consulta_.AtribuirCoordenada(this->coordenadaPadrao_);
}

void MecanismoDeBusca::CalcularCoordenadasParaOsDocumentos()
{
	for (Documento& documento : this->documentos_) {
		indiceInvertido_.CalcularCoordenadasParaMapaDePalavras(documento, (int)documentos_.size());
	}
}

MecanismoDeBusca::~MecanismoDeBusca()
{
}