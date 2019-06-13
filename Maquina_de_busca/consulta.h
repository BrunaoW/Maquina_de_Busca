#include <map>
#include <cmath>
#include <cstring>

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

	// Obter coordenadas da consulta
	map<Palavra, double>ObterCoordenada();

	// Destrutor de consulta
	~Consulta();

	// Atribuir coordenada padrao a consulta
	void AtribuirCoordenada(Coordenada coordenada);

	// Calcular coordenadas para cada palavra
	void CalcularCoordenadasParaPalavras(IndiceInvertido& indiceInvertido, int numeroDeDocumentos);

	// Atribui palavras quando o usuario realiza a consulta
	void AtribuirPalavras(string frase);

	// Obtem palavras inseridas na consulta
	map<Palavra, int> ObterPalavras();
};

#endif // CONSULTA_H
