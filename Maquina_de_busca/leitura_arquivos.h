#include <iostream>
#include <list>
#include <sstream>
#include <fstream>

#include "dirent.h"
#include "documento.h"
#include "palavra.h"
#include "indice_invertido.h"

using namespace std;

namespace LeituraArquivos {
	list<Documento> LerArquivosDaPastaAtual();

	void LerPalavrasDeDocumentos(list<Documento>& documentos, IndiceInvertido& indiceInvertido);

	string NormalizarPalavra(string palavra);
	
	void AdicionarPalavraAoIndiceInvertido(Documento& documento, IndiceInvertido& IndiceInvertido, Palavra palavra);
	
	void AdicionarPalavraAoDocumento(Documento& documento, Palavra palavra);
}


