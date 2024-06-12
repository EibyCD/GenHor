#include <unordered_set>

#include "Compatibilidad.hpp"

bool compatible(std::vector<Datos>& propuesta)
{
	if (propuesta.empty()) { return false; }

	std::vector<int> H_LM{}, H_MV{};

	for (const auto& clase : propuesta)
	{
		switch (clase.Dias)
		{
		case 0:
			H_LM.push_back(clase.Hora);
			break;
		case 1:
			H_MV.push_back(clase.Hora);
			break;
		default:
			break;
		}
	}

	std::unordered_set<int> horas{};

	for (const auto& hora : H_LM)
	{
		if (!horas.insert(hora).second)
		{
			return false;
		}
	}

	horas.clear();
	for (const auto& hora : H_MV)
	{
		if (!horas.insert(hora).second)
		{
			return false;
		}
	}
	return true;
}