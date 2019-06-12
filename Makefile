CXX := g++
CXX_Flags := -Wall -Wextra -std=c++14

all: criarPastaBin clean MaquinaDeBusca MaquinaDeBuscaTeste

MaquinaDeBusca: bin/main.o bin/mecanismo_de_busca.o bin/comandos_console.o bin/consulta.o bin/coordenada.o bin/documento.o bin/indice_invertido.o bin/leitura_arquivos.o bin/palavra.o
	${CXX} ${CXX_Flags} $^ -o $@

MaquinaDeBuscaTeste: bin/mecanismo_de_busca.o bin/comandos_console.o bin/consulta.o bin/coordenada.o bin/documento.o bin/indice_invertido.o bin/leitura_arquivos.o bin/palavra.o Maquina_de_Busca/maquina_de_busca.teste.cpp
	${CXX} ${CXX_Flags} -I Maquina_de_Busca/include/ $^ -o $@

bin/main.o: Maquina_de_Busca/main.cpp
	${CXX} ${CXX_Flags} -c $^ -o $@

bin/mecanismo_de_busca.o: Maquina_de_Busca/mecanismo_de_busca.cpp
	${CXX} ${CXX_Flags} -c $^ -o $@ 

bin/comandos_console.o: Maquina_de_Busca/comandos_console.cpp
	${CXX} ${CXX_Flags} -c $^ -o $@

bin/consulta.o: Maquina_de_Busca/consulta.cpp
	${CXX} ${CXX_Flags} -c $^ -o $@

bin/coordenada.o: Maquina_de_Busca/coordenada.cpp
	${CXX} ${CXX_Flags} -c $^ -o $@

bin/documento.o: Maquina_de_Busca/documento.cpp
	${CXX} ${CXX_Flags} -c $^ -o $@

bin/indice_invertido.o: Maquina_de_Busca/indice_invertido.cpp
	${CXX} ${CXX_Flags} -c $^ -o $@

bin/leitura_arquivos.o: Maquina_de_Busca/leitura_arquivos.cpp
	${CXX} ${CXX_Flags} -c $^ -o $@

bin/palavra.o: Maquina_de_Busca/palavra.cpp
	${CXX} ${CXX_Flags} -c $^ -o $@

clean:
	rm -f *.o MaquinaDeBusca

criarPastaBin:
	mkdir -p bin