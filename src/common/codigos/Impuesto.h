#pragma once
enum IVACobradoFabrica {
    VentaBienes = 1,
    VentasExentas = 2
};

enum IVATarifa {
    Cero = 1,
    ReducidaUno = 2,
    ReducidaDos = 3,
    ReducidaCuatro = 4,
    TransitoriaCero = 5,
    TransitoriaCuatro = 6,
    TransitoriaOcho = 7,
    GeneralTrece = 8,
    ReducidaCeroPuntoCinco = 9,
    Exenta = 10,
    CeroSinDerechoCredito = 11
};

enum CodigoImpuesto {
    ValorAgregadp = 1,
    SelectivoConsumo = 2,
    UnicoCombustibles = 3,
    BebidasAlcoholicas = 4,
    BebidasJabones = 5,
    ProductosTabaco = 6,
    IVACalculoEspecial = 7,
    IVARegimenBienesUsados = 8,
    Cemento = 9,
    Otros = 99
};

enum CondicionImpuesto {
    GeneralCreditoIVA = 1,
    GeneralCreditoParcialIVA = 2,
    BienesCapital = 3,
    GastoCorrienteNoCredito = 4,
    Proporcionalidad = 5
};
