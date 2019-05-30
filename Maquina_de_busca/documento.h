#ifndef DOCUMENTO_H_
#define DOCUMENTO_H_

#include <iostream>
#include <map>

#include "palavra.h"
#include "coordenada.h"

using namespace std;

class Documento
{
	string nome_;
	map<Palavra, int> palavras_;
	Coordenada coordenada_;

public:
	// Inicializar documento
	Documento();

	// Inicializar o documento com o nome do arquivo
	Documento(string nome);

	// Atribuir coordenada a documento
	void AtribuirCoordenada(Coordenada coordenada);

	~Documento();
};

#endif // DOCUMENTO_H_

