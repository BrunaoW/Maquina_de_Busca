#pragma once

#include <iostream>
#include <map>
#include <string>
#include <set>

#include "Documento.h"

using namespace std;

class IndiceInvertido
{
	map<string, set<Documento>> Indices_;

	public:
	IndiceInvertido();
	~IndiceInvertido();
};

