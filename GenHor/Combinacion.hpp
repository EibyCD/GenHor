#pragma once

#include <vector>

#include "Datos.hpp"

class Combinar {

private:

	std::vector<std::vector<Datos>> listas{};
	std::vector<std::vector<Datos>::iterator> itrs{};
	std::vector<Datos> combi{};

public:

	Combinar(std::vector<std::vector<Datos>>& ls);

	std::vector<Datos>& Next();
	std::vector<Datos>& Get();
	bool empty();

	~Combinar() {}
};