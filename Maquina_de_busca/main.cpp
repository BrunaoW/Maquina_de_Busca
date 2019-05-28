#include <iostream>
#include <list>

#include "leitura_arquivos.h"
#include "documento.h"

using namespace std;

int main() {
	list<Documento> documentos = LeituraArquivos::LerArquivosDaPastaAtual();

	return 0;
}
