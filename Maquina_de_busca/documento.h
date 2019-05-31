#include <iostream>
#include <map>

#include "palavra.h"
#include "coordenada.h"

using namespace std;

#pragma once
class Documento
{
	string nome_;
	map<Palavra, int> palavras_;
	Coordenada coordenada_;

public:
	Documento(string nome);
	// Inicializar documento
	Documento();

	~Documento();

	// Atribuir coordenada a documento
	void AtribuirCoordenada(Coordenada coordenada);
};

