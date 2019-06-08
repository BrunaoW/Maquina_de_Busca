#include <iostream>
#include <string>
#include <vector>

#ifndef COMANDOS_CONSOLE_H
#define COMANDOS_CONSOLE_H

using namespace std;

const int larguraMensagens = 80;

class ComandosConsole
{
	public:

	static void ImprimirContainerDeMensagem(const string& titulo, const string& subtitulo);
	
	static string ImprimirMensagemComInput(const string& mensagem);
	
	static void ImprimirListaDeItens(string titulo, vector<string> itens);
	
	static bool MenuContinuarNoPrograma(string mensagem, string opcaoAfirmativa);
	
	static void LimparTela();
};

#endif // !COMANDOS_CONSOLE_H
