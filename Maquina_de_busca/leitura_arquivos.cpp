#include "leitura_arquivos.h"

using namespace std;

list<Documento> LeituraArquivos::LerArquivosDaPasta(string caminhoDaPasta) {
	list<Documento> documentos;

	DIR* diretorioAtual = NULL;

	// Abre a pasta onde se encontra todos os arquivos a serem lidos
	diretorioAtual = opendir(caminhoDaPasta.c_str());

	dirent* arquivo = NULL;

	// Verifica se a pasta foi aberta corretamente
	if (diretorioAtual == NULL) {
		cout << "Diretorio nao iniciado corretamente." << endl;
		exit(3);
	}

	// le todos os arquivos presentes na pasta de dataset
	while (arquivo = readdir(diretorioAtual)) {
		if (arquivo == NULL) {
			cout << "Arquivo nao iniciado corretamente." << endl;
			exit(3);
		}

		// filtra os arquivos com o nome "." e "..", que sao as pastas referentes a atual e a anterior
		if (strcmp(arquivo->d_name, ".") != 0 && strcmp(arquivo->d_name, "..") != 0)
			documentos.push_back(Documento(arquivo->d_name));
	}

	closedir(diretorioAtual);
	return documentos;
}

void LeituraArquivos::LerPalavrasDeDocumentos(list<Documento>& documentos, IndiceInvertido& indiceInvertido, string caminhoDaPasta) {
	for (Documento& documento : documentos) {
		ifstream arquivo;
		arquivo.open(caminhoDaPasta + documento.ObterNome());
		string palavra;

		while (arquivo >> palavra) {
			NormalizarPalavra(palavra);
			Palavra palavraAIncluir(palavra);
			AdicionarPalavraAoDocumento(documento, palavraAIncluir);
			AdicionarPalavraAoIndiceInvertido(documento, indiceInvertido, palavraAIncluir);
		}
	}

}

void LeituraArquivos::AdicionarPalavraAoIndiceInvertido(Documento& documento, IndiceInvertido& IndiceInvertido, Palavra& palavra) {
	// Ao mesmo tempo que busca os documentos associados, a palavra ja eh inclusa no indice invertido
	set<Documento>& documentosAssociados = IndiceInvertido.ObterRegistros()[palavra];
	
	// Verifica se o documento lido se apresenta na lista de documentos ja associados a palavra. Se nao, insere o documento no registro
	//    do indice invertido associado a palavra
	if (documentosAssociados.find(documento) == documentosAssociados.end()) {
		documentosAssociados.insert(documento);
	}
}

void LeituraArquivos::AdicionarPalavraAoDocumento(Documento& documento, Palavra& palavra) {
	map<Palavra, int>& palavras = documento.ObterPalavras();

	// Ao mesmo tempo que inclui a palavra na lista de palavras no documento, ja incrementa a contagem de quantas vezes ela apareceu
	palavras[palavra]++;
}

void LeituraArquivos::NormalizarPalavra(string& palavra) {
	string palavraNormalizada;

	for (auto& caracter : palavra) {
		// Verifica se existe alguma pontuacao separando a palavra, se nao, adiciona o caracter na palavra
		if (!ispunct((unsigned char)caracter))
		{
			palavraNormalizada += tolower((unsigned char)caracter);
		}
	}
	palavra = palavraNormalizada;
}