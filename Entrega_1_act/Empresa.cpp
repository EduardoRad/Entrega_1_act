#include "Empresa.h"

Empresa::Empresa(string name, int numBotigues, Magatzem& magatzemPrincipal, Proveidor& p)
{
	m_name = name;
	m_nBotigues = numBotigues;
	m_magatzem = magatzemPrincipal;
	m_proveidor = p;
}

int Empresa::getSeguentCodiRus()
{
	return 0;
}

bool Empresa::realitzaComanda(Comanda& c, Proveidor& p)
{

	return false;
}

string Empresa::generaCodiRus(const string& model)
{
	return string();
}
