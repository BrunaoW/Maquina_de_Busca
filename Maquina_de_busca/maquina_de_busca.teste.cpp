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
}