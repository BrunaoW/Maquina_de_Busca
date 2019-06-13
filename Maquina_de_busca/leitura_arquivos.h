#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>
#include <dirent.h>

#include "documento.h"
#include "palavra.h"
#include "indice_invertido.h"

using namespace std;

namespace LeituraArquivos {

	vector<Documento> LerArquivosDaPasta(string caminhoDaPasta);

	void LerPalavrasDeDocumentos(vector<Documento>& documentos, IndiceInvertido& indiceInvertido, string caminhoDaPasta);

	void NormalizarPalavra(string& palavra);
	
	void AdicionarPalavraAoIndiceInvertido(Documento& documento, IndiceInvertido& IndiceInvertido, Palavra& palavra);
	
	void AdicionarPalavraAoDocumento(Documento& documento, Palavra& palavra);
}


