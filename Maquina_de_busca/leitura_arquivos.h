#include <iostream>
#include <list>
#include <sstream>
#include <fstream>

#include "dirent.h"
#include "documento.h"
#include "indice_invertido.h"

using namespace std;

namespace LeituraArquivos {
	list<Documento> LerArquivosDaPastaAtual();

	void NormalizacaoPalavras(list <Documento> documentos, IndiceInvertido IndiceInvertido);
	
	void AdicionaIndice(Documento documento, string palavra, IndiceInvertido IndiceInvertido);
	
	void AdicionarPalavraDoc(Documento documento, Palavra palavra);
}


