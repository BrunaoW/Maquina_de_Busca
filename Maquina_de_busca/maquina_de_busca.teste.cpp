#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "include/doctest.h"

#include "leitura_arquivos.h"
#include "coordenada.h"
#include "documento.h"
#include "consulta.h"

TEST_SUITE("Leitura de palavras e arquivos") {
	TEST_CASE("Normalizar Palavra") {
		string palavra1 = "guarda-chuva",
			   palavra2 = "^teste^de^separacao^de^caracteres^",
			   palavra3 = "/*-+.?,;'";

		LeituraArquivos::NormalizarPalavra(palavra1);
		LeituraArquivos::NormalizarPalavra(palavra2);
		LeituraArquivos::NormalizarPalavra(palavra3);

		CHECK(palavra1 == "guardachuva");
		CHECK(palavra2 == "testedeseparacaodecaracteres");
		CHECK(palavra3 == "");
	}
}

TEST_SUITE("Coordenadas") {	
	TEST_CASE("Obter Posicao") {
		Coordenada c1;
		Palavra p1("A"), p2("B");

		c1.IncluirPosicao(p1, 100);
		c1.IncluirPosicao(p2, 200);

		map<Palavra, double> coordenada;
		coordenada[p1] = 100;
		coordenada[p2] = 200;

		CHECK(c1.ObterPosicao()[p1] == coordenada[p1]);
		CHECK(c1.ObterPosicao()[p2] == coordenada[p2]);
	}

	TEST_CASE("Atribuir coordenada") {
		Coordenada c1, c2, c3;
		Palavra p1("A"), p2("B"), p3("C");

		c1.IncluirPosicao(p1, 5);
		c2.IncluirPosicao(p2, 10);
		c3.IncluirPosicao(p3, 15);

		CHECK(c1.ObterPosicao()[p1] == 5);
		CHECK(c2.ObterPosicao()[p2] == 10);
		CHECK(c3.ObterPosicao()[p3] == 15);
	}

	TEST_CASE("Atualizar valor da palavra") {
		Coordenada c1, c2;
		Palavra p1("A"), p2("B");
		
		c1.IncluirPosicao(p1, 5);
		c2.IncluirPosicao(p2, 10);

		REQUIRE(c1.ObterPosicao()[p1] == 5);
		REQUIRE(c2.ObterPosicao()[p2] == 10);

		c1.AtualizarValorDaPalavra(p1, 100);
		c2.AtualizarValorDaPalavra(p2, 400);

		CHECK(c1.ObterPosicao()[p1] == 100);
		CHECK(c2.ObterPosicao()[p2] == 400);
	}
}

TEST_SUITE("Documento") {
	TEST_CASE("Obter Nome") {
		Documento d1("D1"), d2("D2");

		CHECK(d1.ObterNome() == "D1");
		CHECK(d2.ObterNome() == "D2");
	}

	TEST_CASE("Obter e atribuir coordenada") {
		Documento d1("D1");
		Coordenada c1;
		Palavra p1("A"), p2("B");

		c1.IncluirPosicao(p1, 5);
		c1.IncluirPosicao(p2, 10);

		d1.AtribuirCoordenada(c1);

		CHECK(d1.ObterCoordenada()[p1] == c1.ObterPosicao()[p1]);
		CHECK(d1.ObterCoordenada()[p2] == c1.ObterPosicao()[p2]);
	}

	TEST_CASE("Obter Nomes de documentos") {
		vector<Documento> listaDocumentos = {
			Documento("d1"),
			Documento("d2"),
			Documento("d3")
		};

		vector<string> nomes = { "d1", "d2", "d3" };


		CHECK(Documento::ObterNomesDeDocumentos(listaDocumentos) == nomes);
	}
}

TEST_SUITE("Consulta") {
	TEST_CASE("Obter e atribuir coordenada") {
		Consulta con1;
		Coordenada c1;
		Palavra p1("A"), p2("B");

		c1.IncluirPosicao(p1, 5);
		c1.IncluirPosicao(p2, 10);

		con1.AtribuirCoordenada(c1);

		CHECK(con1.ObterCoordenada()[p1] == c1.ObterPosicao()[p1]);
		CHECK(con1.ObterCoordenada()[p2] == c1.ObterPosicao()[p2]);
	}

	TEST_CASE("Obter e atribuir palavras") {
		Consulta con1;
		string palavras = "Este eh um teste unitario";

		con1.AtribuirPalavras(palavras);

		CHECK(con1.ObterPalavras()[Palavra("este")] == 1);
		CHECK(con1.ObterPalavras()[Palavra("um")] == 1);
		CHECK(con1.ObterPalavras()[Palavra("teste")] == 1);
		CHECK(con1.ObterPalavras()[Palavra("unitario")] == 1);
	}
}