#ifndef INFORMACOES_BUSCA_H_
#define INFORMACOES_BUSCA_H_

#include <list>

#include "indice_invertido.h"
#include "documento.h"
#include "coordenada.h"
#include "consulta.h"

class InformacoesBusca
{
	IndiceInvertido indiceInvertido_;
	list<Documento> documentos_;
	Coordenada coordenadaPadrao_;
	Consulta consulta_;

public:
	// Inicializa Informacoes da busca
	InformacoesBusca();

	~InformacoesBusca();

	// Inicializa coordenada padrao, a partir das palavras carregadas
	void InicializarCoordenadaPadrao();
};
#endif // !INFORMACOES_BUSCA_H_


