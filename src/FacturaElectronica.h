#pragma once
#include <iostream>
#include "./header/ClaveNumerica.h"
#include "./header/Emisor.h"
#include "./header/Receptor.h"
#include "./common/codigos/Codigos.h"

class FacturaElectronica
{
private:
	ClaveNumerica clave;
	std::string proveedorSistemas;
	std::string codigoActivadadEmisor;
	std::string codigoActivadadReceptor;
	std::string fechaEmision;
	Emisor emisor;
	Receptor receptor;
	CondicionDeVenta condicionVenta;
	std::string condicionVentaOtros;
	short plazoCredito;
};

