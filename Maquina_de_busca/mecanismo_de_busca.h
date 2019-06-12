#include <list>
#include <algorithm>
#include <cmath>
#include <string>

#include "indice_invertido.h"
#include "documento.h"
#include "coordenada.h"
#include "consulta.h"
#include "leitura_arquivos.h"
#include "comandos_console.h"


#ifndef MECANISMO_DE_BUSCA_H
#define MECANISMO_DE_BUSCA_H

using namespace std;

class MecanismoDeBusca
{
	IndiceInvertido indiceInvertido_;
	list<Documento> documentos_;
	Consulta consulta_;

public:
	// Construtor para Informacoes da busca
	MecanismoDeBusca();

	// Rotina para o mecanismo de busca
	void RotinaMecanismoDeBusca();

	// Calcula as coordenadas para cada documento
	void CalcularCoordenadasParaOsDocumentos();

	//Método para calcular a proximidade
	void CalcularProximidadeDeDocumentos();

	//Método para retornar a lista ordenada das proximidades
	void OrdenarDocumentosPorProximidade();

	~MecanismoDeBusca();
};
#endif // MECANISMO_DE_BUSCA_H


