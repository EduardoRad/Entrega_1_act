#pragma once
#include <string>

#include "Botiga.h"
#include "Comanda.h"
#include "Magatzem.h"
#include "Proveidor.h"

/**
 *
* La clase empresa aglutina la inforamcion para gestionar la comunicacion del almacen con el proveedor, asi como las tiendas.
* La empresa se define por un conjunto de tiendas, un almacen y un proveedor.
* La empresa realizar� pedidos al provedor y recibira una notificacion indicando si el pedido ha llegado correctamente a almacen.
* 
**/

class Empresa
{
public:
	Empresa(string name, int numBotigues, Magatzem& magatzemPrincipal, Proveidor& p);
	string getName() const { return m_name; }
	Magatzem& getMagatzem() { return m_magatzem; }
	vector<Botiga*>& getBotigues() { return m_botigues; }
	void setProveidor(Proveidor& proveidor) { this->m_proveidor = proveidor; }
	Proveidor& getProveidor() { return m_proveidor; }
	void afegeixBotiga(Botiga* b) { this->m_botigues.emplace_back(b); }
	static int getSeguentCodiRus();

	bool realitzaComanda(Comanda& c, Proveidor& p);
	string static generaCodiRus(const string& model);

private:
	string m_name;
	Magatzem m_magatzem;
	vector<Botiga*> m_botigues;
	Proveidor m_proveidor;
	int m_nBotigues;
};
