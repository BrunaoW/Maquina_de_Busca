#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <cctype>

#include "include/dirent.h"
#include "documento.h"
#include "palavra.h"
#include "indice_invertido.h"

using namespace std;

namespace LeituraArquivos {

	list<Documento> LerArquivosDaPasta(string caminhoDaPasta);

	void LerPalavrasDeDocumentos(list<Documento>& documentos, IndiceInvertido& indiceInvertido, string caminhoDaPasta);

	void NormalizarPalavra(string& palavra);
	
	void AdicionarPalavraAoIndiceInvertido(Documento& documento, IndiceInvertido& IndiceInvertido, Palavra& palavra);
	
	void AdicionarPalavraAoDocumento(Documento& documento, Palavra& palavra);
}


