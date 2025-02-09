#pragma once
#include <iostream>
#include "../common/codigos/TipoDocumento.h"

// Clave numérica del comprobante

class NumeracionComprobante {
private:
    char casaMatriz;                // d{0,3}
    char puntoVenta;                // d{4,8}
    TipoDocumento tipoComprobante;  // d{9,10}
    char numeracion;                // d{11, 20}
public:
    std::string getValue();
};