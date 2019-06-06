#include "consulta.h"

Consulta::Consulta()
{
}

Consulta::~Consulta()
{
}

void Consulta::AtribuirCoordenada(Coordenada coordenada)
{
	this->coordenada_ = coordenada;
}

void Consulta::AtribuirPalavras(string frase)
{
	char* fraseASeparar = &frase[0u];
	char* tokenSeparador = new char(' ');

	strtok(fraseASeparar, tokenSeparador);

	while (fraseASeparar != NULL) {
		this->palavras_.push_back(string(fraseASeparar));
		fraseASeparar = strtok(NULL, tokenSeparador);
	}
}


