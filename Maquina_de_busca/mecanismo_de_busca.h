#include <list>

#include "indice_invertido.h"
#include "documento.h"
#include "coordenada.h"
#include "consulta.h"
#include "leitura_arquivos.h"
#include "cmath"


#ifndef MECANISMO_DE_BUSCA_H
#define MECANISMO_DE_BUSCA_H

using namespace std;

class MecanismoDeBusca
{
	IndiceInvertido indiceInvertido_;
	list<Documento> documentos_;
	Coordenada coordenadaPadrao_;
	Consulta consulta_;


public:
	// Construtor para Informacoes da busca
	MecanismoDeBusca();

	// Rotina para o mecanismo de busca
	void RotinaMecanismoDeBusca();

	// Inicializa coordenada padrao, a partir das palavras carregadas
	void InicializarCoordenadaPadrao();

	// Calcula as coordenadas para cada documento
	void CalcularCoordenadasParaOsDocumentos();

	//M�todo para calcular a proximidade
	void Proximidade();

	//M�todo para retornar a lista ordenada das proximidades
	list<Documento> OrdenaProximidade();

	~MecanismoDeBusca();
};
#endif // MECANISMO_DE_BUSCA_H


