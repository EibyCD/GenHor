#include "Combinacion.hpp"

Combinar::Combinar(std::vector<std::vector<Datos>>& ls) : listas{ ls }, itrs(ls.size()), combi(ls.size())
{
	for (size_t i{ 0 }; i < listas.size(); i++)
	{
		itrs[i] = listas[i].begin();
	}
}

std::vector<Datos>& Combinar::Next()
{
	if (itrs[0] == listas[0].end())
	{
		combi.clear();
		return combi;
	}

	for (size_t i{ 0 }; i < itrs.size(); i++)
	{
		combi[i] = *itrs[i];
	}

	++itrs[itrs.size() - 1];

	for (size_t i{ itrs.size() - 1 }; i > 0; i--)
	{
		if (itrs[i] == listas[i].end())
		{
			itrs[i] = listas[i].begin();
			++itrs[i - 1];
		}

		if (itrs[i - 1] != listas[i - 1].end())
		{
			break;
		}
	}

	return combi;
}

std::vector<Datos>& Combinar::Get() { return combi; }

bool Combinar::empty() { return combi.empty(); }