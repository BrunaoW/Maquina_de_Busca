#include "leitura_arquivos.h"

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

void LeituraArquivos::LerPalavrasDeDocumentos(list<Documento>& documentos, IndiceInvertido& indiceInvertido) {
	for (Documento& documento : documentos) {
		ifstream arquivo;
		arquivo.open(documento.ObterNome());
		while (!arquivo.eof()) {
			string palavra;
			arquivo >> palavra;
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
	map<Palavra, int>palavras = documento.ObterPalavras();
	palavras[palavra]++;
}

string LeituraArquivos::NormalizarPalavra(string palavra) {
	ostringstream palavraNormalizada;
	for (int i = 0; i < palavra.size(); i++) {
		if ((palavra[i] >= 'a' && palavra[i] <= 'z') || (palavra[i] >= 'A' && palavra[i] <= 'Z') || (palavra[i] >= '0' && palavra[i] <= '9')) {
			palavraNormalizada << tolower(palavra[i]);
		}
	}
	return palavraNormalizada.str();
}