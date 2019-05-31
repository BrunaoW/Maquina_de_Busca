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

int BuscarQuantidadeDeDocumentosAssociadosAUmaPalavra(IndiceInvertido indiceInvertido, Palavra palavra)
{
	set<Documento> documentos = indiceInvertido.registros_[palavra];
	return documentos.size;
}
