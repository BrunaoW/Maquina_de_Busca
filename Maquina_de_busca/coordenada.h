#ifndef COORDENADA_H_
#define COORDENADA_H_

#include <iostream>
#include <map>

#include "palavra.h"

using namespace std;

class Coordenada
{
	map<Palavra, double> posicao_;
	public:
	// Inicializar coordenada
	Coordenada();
	
	~Coordenada();

	// Incluir um novo eixo, i.e., uma nova palavra, e seu respectivo valor
	void IncluirPosicao(Palavra palavra, double valor = 0);

	// Atualiza valor da palavra
	void AtualizarValorDaPalavra(Palavra palavra, double valor = 0);
};

#endif // !COORDENADA_H_
