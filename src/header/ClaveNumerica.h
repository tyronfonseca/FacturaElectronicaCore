#pragma once
#include "../common/codigos/Codigos.h"
#include "../common/Identificador.h"
#include "./NumeracionComprobante.h"


// Clave numérica del comprobante

class ClaveNumerica {
private:
    char codigoPais;                       // d{0,3}
    char dia;                               // d{4,5}
    char mes;                             // d{6,7}
    char anno;                              // d{8,9}
    Identificador identificador;                         // d{10,21}
    NumeracionComprobante numeroConsecutivo;    // d{22,41}
    Estatus estatus;                        // d{42}
    std::string codigoSeguridad;                         // d{43,50}
public:
    void setCodigoPais(short codigo);
    std::string getCodigoPais();

};