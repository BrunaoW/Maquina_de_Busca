#include <map>
#include <cmath>

#include "palavra.h"
#include "coordenada.h"
#include "indice_invertido.h"
#include "leitura_arquivos.h"

#ifndef CONSULTA_H
#define CONSULTA_H

class Consulta
{
	map<Palavra, int> palavras_;
	Coordenada coordenada_;

	public:
	// Construtor da Consulta
	Consulta();

	map<Palavra, double>ObterCoordenada();

	~Consulta();

	// Atribuir coordenada padrao a consulta
	void AtribuirCoordenada(Coordenada coordenada);

	// Calcular coordenadas para cada palavra
	void CalcularCoordenadasParaPalavras(IndiceInvertido& indiceInvertido, int numeroDeDocumentos);

	void AtribuirPalavras(string frase);
};

#endif // CONSULTA_H
