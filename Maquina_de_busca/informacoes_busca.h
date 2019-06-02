#include <list>

#include "indice_invertido.h"
#include "documento.h"
#include "coordenada.h"
#include "consulta.h"

#ifndef INFORMACOES_BUSCA_H
#define INFORMACOES_BUSCA_H

class InformacoesBusca
{
	IndiceInvertido indiceInvertido_;
	list<Documento> documentos_;
	Coordenada coordenadaPadrao_;
	Consulta consulta_;

	public:
	// Inicializa Informacoes da busca
	InformacoesBusca();

	// Inicializa coordenada padrao, a partir das palavras carregadas
	void InicializarCoordenadaPadrao();
	
	// Calcula as coordenadas para cada documento
	void CalcularCoordenadasParaOsDocumentos();

	~InformacoesBusca();
};
#endif // INFORMACOES_BUSCA_H


