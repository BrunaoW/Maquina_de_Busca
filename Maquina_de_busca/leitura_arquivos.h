#include <iostream>
#include <list>
#include "dirent.h"

#include "documento.h"

using namespace std;

namespace LeituraArquivos {
	list<Documento> LerArquivosDaPastaAtual();
	void LeituraFinal(list <Documento> documentos, IndiceInvertido IndiceInvertido);
	void AdicionaIndice(Documento documento, string palavra, IndiceInvertido IndiceInvertido);
	void AdicionarPalavraDoc(Documento documento, Palavra palavra);
	string NormalizarPalavras(Palavra palavra);
}


