#pragma once
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <fstream>
#include "Comanda.h"


/**
* La clase Magatzem gestiona el estoc de la empresa antes de ser enviado a tiendas.
* En el almacen se pasan controles de calidad para notificar a la empresa del estado en el que llega el pedido.
* El almacen tambien genera la factura final en funcion del estado con el que llega el pedido.
* 
**/

class Magatzem
{
public:
	Magatzem() { this->m_stock = map<string, priority_queue<Bicicleta*>>(); };
	Magatzem(string nom, string codi);
	void enmagatzemarComanda(vector<Bicicleta*>& paquet, Data dataEntrada);
	float procesQA(Comanda& c, vector<Bicicleta*>& paquet, Data dataActual);
	bool rebreComanda(Comanda& c, vector<Bicicleta*>& paquet, Data dataRecepcioPaquet);
	void generaFactura(bool paquetComplet, float costCorregit, Comanda& c);
	Bicicleta* agafaBicicletaAntiga(const string& model);
	void mostraCataleg();

	string getNom() const { return m_nom; }
	void setNom(string nom) { m_nom = nom; }
	string getCodi() const { return m_codi; }
	void setCodi(string codi) { m_codi = codi; }
	map<string, priority_queue<Bicicleta*>> getStock() const { return m_stock; }
	
private:
	float m_taxaEndarreriment = 1.1f;
	map<string, priority_queue<Bicicleta*>> m_stock;
	map<TipusBicicleta, vector<string>> m_relacioModelTipus;
	Data data;
	string m_nom;
	string m_codi;
};
