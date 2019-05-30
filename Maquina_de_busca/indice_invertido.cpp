#include "indice_invertido.h"

IndiceInvertido::IndiceInvertido()
{
}


IndiceInvertido::~IndiceInvertido()
{
}

map<Palavra, set<Documento>>& IndiceInvertido::ObterRegistros() {
	return this->registros_;
}
