#include "comandos_console.h"

void ComandosConsole::ImprimirContainerDeMensagem(const string& titulo, const string& subtitulo)
{
	int i = 0;

	for (i = 0; i < larguraMensagens; i++) cout << "#";
	cout << endl << "#";

	for (i = 0; i < larguraMensagens - 2; i++) cout << " ";
	cout << "#" << endl;

	cout << "# " << titulo;
	for (i = 0; i < larguraMensagens - (int)titulo.size() - 4; i++) cout << " ";
	cout << " #" << endl << "#";

	for (i = 0; i < larguraMensagens - 2; i++) cout << " ";
	cout << "#" << endl;

	cout << "# " << subtitulo;
	for (i = 0; i < larguraMensagens - (int)subtitulo.size() - 4; i++) cout << " ";
	cout << " #" << endl << "#";

	for (i = 0; i < larguraMensagens - 2; i++) cout << " ";
	cout << "#" << endl;

	for (i = 0; i < larguraMensagens; i++) cout << "#";
	cout << endl;
}

string ComandosConsole::ImprimirMensagemComInput(const string& mensagem)
{
	string retornoInput;
	int i = 0;

	for (i = 0; i < larguraMensagens; i++) cout << "#";
	cout << endl << "#";

	for (i = 0; i < larguraMensagens - 2; i++) cout << " ";
	cout << "#" << endl;

	cout << "# " << mensagem;
	for (i = 0; i < larguraMensagens - ((int)mensagem.size()) - 4; i++) cout << " ";
	cout << " #" << endl << "#";

	for (i = 0; i < larguraMensagens - 2; i++) cout << " ";
	cout << "#" << endl;

	cout << "# ";
	cin.ignore();
	getline(cin, retornoInput);
	
	cout << "# ";
	for (i = 0; i < larguraMensagens - 4; i++) cout << " ";
	cout << " #" << endl;

	for (i = 0; i < larguraMensagens; i++) cout << "#";
	cout << endl;

	return retornoInput;
}

void ComandosConsole::ImprimirListaDeItens(string titulo, vector<string> itens)
{
	int i, j;

	for (i = 0; i < larguraMensagens; i++) cout << "#";
	cout << endl << "#";

	for (i = 0; i < larguraMensagens - 2; i++) cout << " ";
	cout << "#" << endl;

	cout << "# " << titulo;
	for (i = 0; i < larguraMensagens - 4 - ((int)titulo.size()); i++) cout << " ";
	cout << " #" << endl << "#";

	for (i = 0; i < larguraMensagens - 2; i++) cout << " ";
	cout << "#" << endl;

	for (j = 0; j < (int)itens.size(); j++) {
		cout << "# " << j + 1 << ". " << itens[j];
		for (i = 0; i < larguraMensagens - ((int)itens[j].size()) - 6; i++) cout << " ";
		cout << "#" << endl;

		cout << "#";
		for (i = 0; i < larguraMensagens - 2; i++) cout << " ";
		cout << "#" << endl;
	}

	for (i = 0; i < larguraMensagens; i++) cout << "#";
	cout << endl;
}

bool ComandosConsole::MenuContinuarNoPrograma(string mensagem, string opcaoAfirmativa)
{
	int i;
	for (i = 0; i < larguraMensagens; i++) cout << "#";
	cout << endl << "#";

	for (i = 0; i < larguraMensagens - 2; i++) cout << " ";
	cout << "#" << endl;

	cout << "# " << mensagem;
	for (i = 0; i < larguraMensagens - ((int)mensagem.size()) - 4; i++) cout << " ";
	cout << " #" << endl;

	cout << "#";
	for (i = 0; i < larguraMensagens - 2; i++) cout << " ";
	cout << "#" << endl;

	cout << "# [1] " << opcaoAfirmativa;
	for (i = 0; i < larguraMensagens - ((int)opcaoAfirmativa.size()) - 8; i++) cout << " ";
	cout << " #" << endl;

	cout << "#";
	for (i = 0; i < larguraMensagens - 2; i++) cout << " ";
	cout << "#" << endl;

	cout << "# [0] Sair";
	for (i = 0; i < larguraMensagens - 12; i++) cout << " ";
	cout << " #" << endl;

	cout << "#";
	for (i = 0; i < larguraMensagens - 2; i++) cout << " ";
	cout << "#" << endl;

	for (i = 0; i < larguraMensagens; i++) cout << "#";
	cout << endl;

	char c;
	cin.clear();
	cin >> c;

	return c == '1';
}

void ComandosConsole::LimparTela()
{
	for (int i = 0; i < 200; i++) cout << endl;
}
