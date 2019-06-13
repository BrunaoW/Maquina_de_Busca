#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "include/doctest.h"

#include "leitura_arquivos.h"

TEST_SUITE("Leitura de palavras e arquivos") {
	TEST_CASE("Normalizar Palavra") {
		string palavra1 = "guarda-chuva",
			   palavra2 = "^teste^de^separacao^de^caracteres^",
			   palavra3 = "/*-+.?,;'\"";

		LeituraArquivos::NormalizarPalavra(palavra1);
		LeituraArquivos::NormalizarPalavra(palavra2);
		LeituraArquivos::NormalizarPalavra(palavra3);

		CHECK(palavra1 == "guardachuva");
		CHECK(palavra2 == "testedeseparacaodecaracteres");
		CHECK(palavra1 == "");
	}
	TEST_CASE("Normalizar palavra Caixa Alta") {
		string palavra5 = "TESTANDO";
		string palavra6 = "nOrMaLiZaNdO PaLaVrA";

		LeituraArquivos::NormalizarPalavra(palavra5);
		LeituraArquivos::NormalizarPalavra(palavra6);

		CHECK(palavra5 = "testando");
		CHECK(palavra6 = "normalizando palavra");
	}
}
TEST_SUITE("Coordenadas") {
	TEST_CASE("Atribuir coordenada") {
		double coordenada = 5;
		Consulta::AtribuirCoordenada(coordenada);
		CHECK(coordenada_ = "5");
	}
	TEST_CASE("Atualizar valor da palavra") {
		double valor = 12;
		Coordenada::AtualizarValorDaPalavra(palavra, valor);
		CHECK(posicao_[palavra] = "12");
	}
}
