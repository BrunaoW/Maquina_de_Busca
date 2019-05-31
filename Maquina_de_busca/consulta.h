#include <list>

#include "palavra.h"
#include "coordenada.h"

class Consulta
{
	list<Palavra> palavras_;
	Coordenada coordenada_;
public:
	Consulta();
	~Consulta();
};

