#include <list>
#include <string>

#include "indice_invertido.h"
#include "documento.h"
#include "coordenada.h"
#include "consulta.h"
#include "leitura_arquivos.h"

#ifndef MECANISMO_DE_BUSCA_H
#define MECANISMO_DE_BUSCA_H

using std::cout;
using std::cin;

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

	~MecanismoDeBusca();
};
#endif // MECANISMO_DE_BUSCA_H


