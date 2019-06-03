#include "leitura_arquivos.h"

using namespace std;

list<Documento> LeituraArquivos::LerArquivosDaPastaAtual() {
	list<Documento> documentos;
	
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

void LeituraArquivos::NormalizacaoPalavras(list<Documento> documentos, IndiceInvertido IndiceInvertido) {
	for (Documento& documento : documentos){
		ifstream arquivo;
		arquivo.open(documento.ObterNome());
		while (!arquivo.eof()) {
			string palavra;
			arquivo >> palavra;
		// CHAMAR MÉTODO NORMALIZAR, CHAMAR MÉTODOS ABAIXO
		}
	}

}

void LeituraArquivos::AdicionaIndice(Documento documento, string palavra, IndiceInvertido IndiceInvertido) {
	set<Documento>& documentosAssociados = IndiceInvertido.ObterRegistros()[Palavra(palavra)];
	
	if (documentosAssociados.find(documento) == documentosAssociados.end()) {
		documentosAssociados.insert(documento);
	}
}

void LeituraArquivos::AdicionarPalavraDoc(Documento documento, Palavra palavra) {
	map<Palavra, int>palavras = documento.ObterPalavras();
	palavras[palavra]++;
}
