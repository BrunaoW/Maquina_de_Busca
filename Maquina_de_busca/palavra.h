#include <iostream>

#ifndef PALAVRA_H
#define PALAVRA_H

using namespace std;

class Palavra
{
	string nome_;
	public:
	// Construtor da palavra
	Palavra();

	// Construtor da palavra inicializando com uma string
	Palavra(string nome);

	// Operador de comparacao criado para acessar o map a partir da palavra
	friend bool operator<(const Palavra& palavra1, const Palavra& palavra2);

	~Palavra();
};

#endif // PALAVRA_H
