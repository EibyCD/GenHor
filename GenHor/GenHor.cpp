#include <iostream>
#include <vector>

#include "Combinacion.hpp"
#include "Datos.hpp"
#include "Compatibilidad.hpp"
#include "Imprimir.hpp"

int main()
{
	std::vector<Datos> Calculo{ {17724, 0, 4}, {17732, 0, 4}, {17735, 1, 4}, {17739, 0, 2}, {17742, 1, 2}, {17745, 0, 0} }, Geometria{ {18083, 0, 3} },
		Lineal{ {17709, 0, 0} }, Probabilidad{ {12604, 1, 2}, {12614, 1, 1}, {12625, 0, 1} };

	std::vector<std::vector<Datos>> Cursos{ Calculo, Geometria, Lineal, Probabilidad };

	Combinar Combi_Cursos{ Cursos };

	while (!Combi_Cursos.empty())
	{
		if (compatible(Combi_Cursos.Next()))
		{
			imprimir(Combi_Cursos.Get());
		}
	}

	system("pause");

	return 0;
}