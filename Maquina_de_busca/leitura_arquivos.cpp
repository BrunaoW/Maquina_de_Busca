#include <iostream>
#include <list>
#include <dirent.h>

#include "leitura_arquivos.h"
#include "documento.h"

using namespace std;

list<Documento> LeituraArquivos::LerArquivosDaPastaAtual() {
	list<Documento> documentos;
	
	DIR* diretorioAtual = NULL;
	diretorioAtual = opendir("./dataset");

	dirent* arquivo = NULL;

	if (diretorioAtual == NULL) {
		cout << "Diretorio nao iniciado corretamente." << endl;
		exit(3);
	}

	while (arquivo = readdir(diretorioAtual)) {
		if (arquivo == NULL) {
			cout << "Arquivo nao iniciado corretamente." << endl;
			exit(3);
		}

		documentos.push_back(Documento(arquivo->d_name));
	}

	closedir(diretorioAtual);
	return documentos;
}