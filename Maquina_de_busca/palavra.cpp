#include <iostream>

#include "palavra.h"

using namespace std;

Palavra::Palavra()
{
}

Palavra::Palavra(string nome)
{
	this->nome_ = nome;
}

bool operator<(const Palavra& palavra1, const Palavra& palavra2)
{
	return palavra1.nome_ < palavra2.nome_;
}

Palavra::~Palavra()
{
}
