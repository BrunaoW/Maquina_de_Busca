
#ifndef PALAVRA_H_
#define PALAVRA_H_

#include <iostream>

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
	bool operator<(const Palavra& palavra) const;

	~Palavra();
};

#endif // !PALAVRA_H_
