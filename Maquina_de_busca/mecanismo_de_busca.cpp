#include "mecanismo_de_busca.h"

MecanismoDeBusca::MecanismoDeBusca()
{
}

void MecanismoDeBusca::RotinaMecanismoDeBusca()
{
	ComandosConsole::ImprimirContainerDeMensagem("Bem-vindo a rotina de busca de palavras", "Processando informacoes da pasta. Aguarde...");

	this->documentos_ = LeituraArquivos::LerArquivosDaPastaAtual();
	LeituraArquivos::LerPalavrasDeDocumentos(this->documentos_, this->indiceInvertido_);

	InicializarCoordenadaPadrao();
	CalcularCoordenadasParaOsDocumentos();

	string fraseConsulta = ComandosConsole::ImprimirMensagemComInput("Digite a palavra que deseja buscar: ");
	
	this->consulta_.AtribuirPalavras(fraseConsulta);
	this->consulta_.CalcularCoordenadasParaPalavras(this->indiceInvertido_, (int)this->documentos_.size());

	CalcularProximidadeDeDocumentos();
	OrdenarDocumentosPorProximidade();

	ComandosConsole::ImprimirListaDeItens("Os documentos mais proximos a sua consulta sao: ", Documento::ObterNomesDeDocumentos(this->documentos_));
	system("pause");
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

void MecanismoDeBusca::CalcularProximidadeDeDocumentos()
{
	//iterando sobre cada documento
	for (Documento& documento : documentos_) {
		double numerador = 0, denominador = 0, somatorioPosicaoDocumento = 0, somatorioPosicaoConsulta = 0;
		
		//iterando sobre as palavras de um documento
		for (auto& posicaoPalavra : documento.ObterCoordenada()) {
			//Conta para o numerador
			numerador += consulta_.ObterCoordenada()[posicaoPalavra.first] * posicaoPalavra.second;
			somatorioPosicaoDocumento += pow(posicaoPalavra.second, 2);
			somatorioPosicaoConsulta += pow(consulta_.ObterCoordenada()[posicaoPalavra.first], 2);
		}
		denominador += sqrt(somatorioPosicaoDocumento) * sqrt(somatorioPosicaoConsulta);
		documento.AtribuirProximidade(numerador/denominador);
	}
}

void MecanismoDeBusca::OrdenarDocumentosPorProximidade()
{
	this->documentos_.sort([](const Documento& d1, const Documento& d2) { return d1.ObterProximidade() > d2.ObterProximidade(); });
}

MecanismoDeBusca::~MecanismoDeBusca()
{
}