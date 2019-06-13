#include "mecanismo_de_busca.h"

MecanismoDeBusca::MecanismoDeBusca()
{
}

void MecanismoDeBusca::RotinaMecanismoDeBusca()
{
	ComandosConsole::ImprimirContainerDeMensagem("Bem-vindo a rotina de busca de palavras", "Insira o caminho da pasta que deseja buscar...");

	string caminho;
	cin >> caminho;

	if (caminho.back() != '/' || caminho.back() != '\\')
		caminho += '/';

	this->documentos_ = LeituraArquivos::LerArquivosDaPasta(caminho);
	LeituraArquivos::LerPalavrasDeDocumentos(this->documentos_, this->indiceInvertido_, caminho);

	CalcularCoordenadasParaOsDocumentos();

	do {
		string fraseConsulta = ComandosConsole::ImprimirMensagemComInput("Digite os termos que deseja buscar: ");
		
		this->consulta_ = Consulta();
		this->consulta_.AtribuirPalavras(fraseConsulta);
		this->consulta_.CalcularCoordenadasParaPalavras(this->indiceInvertido_, (int)this->documentos_.size());

		CalcularProximidadeDeDocumentos();
		OrdenarDocumentosPorProximidade();

		ComandosConsole::ImprimirListaDeItens("Os documentos mais proximos a sua consulta sao: ", Documento::ObterNomesDeDocumentos(this->documentos_));
	
		if (ComandosConsole::MenuContinuarNoPrograma("Deseja fazer outra consulta?", "Sim")) 
			ComandosConsole::LimparTela();
		else 
			break;

	} while (true);
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
		
		//iterando sobre as palavras das consulta
		for (auto& palavraDaCoordenada : consulta_.ObterCoordenada()) {
			// Conta para o numerador
			numerador += documento.ObterCoordenada()[palavraDaCoordenada.first] * palavraDaCoordenada.second;
			somatorioPosicaoDocumento += pow(documento.ObterCoordenada()[palavraDaCoordenada.first], 2);
			somatorioPosicaoConsulta += pow(palavraDaCoordenada.second, 2);
		}

		denominador += sqrt(somatorioPosicaoDocumento) * sqrt(somatorioPosicaoConsulta);
		documento.AtribuirProximidade(denominador == 0 ? 0 : numerador/denominador);
	}
}

void MecanismoDeBusca::OrdenarDocumentosPorProximidade()
{
	sort(documentos_.begin(), documentos_.end(), [](const Documento& d1, const Documento& d2) { return d1.ObterProximidade() > d2.ObterProximidade(); });
}

MecanismoDeBusca::~MecanismoDeBusca()
{
}