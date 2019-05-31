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

bool Palavra::operator<(const Palavra& palavra) const
{
	return this->nome_ < palavra.nome_;
}

Palavra::~Palavra()
{
}
