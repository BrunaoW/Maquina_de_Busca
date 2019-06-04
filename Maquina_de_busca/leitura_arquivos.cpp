#include "leitura_arquivos.h"

using namespace std;

list<Documento> LeituraArquivos::LerArquivosDaPastaAtual() {
	list<Documento> documentos;

	int contador;
	DIR* diretorioAtual = NULL;
	diretorioAtual = opendir("dataset_teste");

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
		if (strcmp(arquivo->d_name, ".") != 0 && strcmp(arquivo->d_name, "..") != 0)
			documentos.push_back(Documento(arquivo->d_name));
	}

	closedir(diretorioAtual);
	return documentos;
}

void LeituraArquivos::LerPalavrasDeDocumentos(list<Documento>& documentos, IndiceInvertido& indiceInvertido) {
	for (Documento& documento : documentos) {
		
		ifstream arquivo;
		arquivo.open("dataset_teste/" + documento.ObterNome());
		string palavra;

		while (arquivo >> palavra) {
			NormalizarPalavra(palavra);
			AdicionarPalavraAoDocumento(documento, Palavra(palavra));
			AdicionarPalavraAoIndiceInvertido(documento, indiceInvertido, Palavra(palavra));
		}
	}

}

void LeituraArquivos::AdicionarPalavraAoIndiceInvertido(Documento& documento, IndiceInvertido& IndiceInvertido, Palavra palavra) {
	set<Documento>& documentosAssociados = IndiceInvertido.ObterRegistros()[palavra];
	if (documentosAssociados.find(documento) == documentosAssociados.end()) {
		documentosAssociados.insert(documento);
	}
}

void LeituraArquivos::AdicionarPalavraAoDocumento(Documento& documento, Palavra palavra) {
	map<Palavra, int>& palavras = documento.ObterPalavras();
	palavras[palavra]++;
}

void LeituraArquivos::NormalizarPalavra(string& palavra) {
	string palavraNormalizada;

	for (auto& caracter : palavra) {
		if (!ispunct((unsigned char)caracter))
		{
			palavraNormalizada += caracter;
		}
	}
	palavra = palavraNormalizada;
}