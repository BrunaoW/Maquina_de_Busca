#include <iostream>
#include <map>

#include "palavra.h"

#ifndef COORDENADA_H
#define COORDENADA_H

using namespace std;

class Coordenada
{
	map<Palavra, double> posicao_;
	public:

	// Construtor da coordenada
	Coordenada();

	// Obtem as coordenadas
	map<Palavra, double> ObterPosicao();
	
	// Destrutor de coordenada
	~Coordenada();

	// Incluir um novo eixo, i.e., uma nova palavra, e seu respectivo valor
	void IncluirPosicao(Palavra palavra, double valor);

	// Atualiza valor da palavra
	void AtualizarValorDaPalavra(Palavra palavra, double valor);
};

#endif // COORDENADA_H
