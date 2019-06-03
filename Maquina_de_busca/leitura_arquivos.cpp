#include <iostream>
#include <list>
#include <sstream>
#include "dirent.h"
#include "leitura_arquivos.h"
#include "documento.h"
#include <fstream>

using namespace std;

list<Documento> LeituraArquivos::LerArquivosDaPastaAtual() {
	list<Documento> documentos;
	
	int contador;
	DIR* diretorioAtual = NULL;
	diretorioAtual = opendir("dataset");

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
void LeituraArquivos::LeituraFinal(list <Documento> documentos, IndiceInvertido IndiceInvertido) {
	for (Documento& documento : documentos){
		ifstream arquivo;
		arquivo.open(documento.ObterNome());
		while (!arquivo.eof()) {
			string palavra;
			arquivo >> palavra;
			NormalizarPalavras(Palavra palavra);
			AdicionarPalavraDoc(Documento documento, Palavra palavra);
			AdicionaIndice(Documento documento, string palavra, IndiceInvertido IndiceInvertido);
		}
	}

}//Fim da função de Normalização de Palavras

void LeituraArquivos::AdicionaIndice(Documento documento, string palavra, IndiceInvertido IndiceInvertido) {
	set<Documento>& documentosAssociados = IndiceInvertido.ObterRegistros()[Palavra(palavra)];
	if (documentosAssociados.find(documento)==documentosAssociados.end()) {
		documentosAssociados.insert(documento);
	}
}

void LeituraArquivos::AdicionarPalavraDoc(Documento documento, Palavra palavra) {
	map<Palavra, int>palavras = documento.ObterPalavras();
	palavras[palavra]++;
}

string LeituraArquivos::NormalizarPalavras(Palavra palavra) {
	ostringstream chave;
	for (int i = 0; i < palavra.lenght(); i++) {
		if (palavra[i] >= 'a' && palavra[i] <= 'z') || (palavra[i] >= 'A' && palavra[i] <= 'Z') || (palavra[i] >= '0' && palavra[i] <= '9')) {
		chave << tolower(palavra[i], locale());
		}
	}
	return chave.str();
}//Fim da função de normalizar as palavras