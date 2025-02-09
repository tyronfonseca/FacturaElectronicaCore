#pragma once
enum class Estatus : short {
    Normal = 1,
    Contingencia = 2,
    NoInternet = 3
};

enum class TipoIdentificacion : short {
    CedulaFisica = 1,
    CedulaJuridica = 2,
    DIMEX = 3,
    NITE  = 4,
    ExtranjeroNoDomiciliado = 5,
    NoContribuyente = 6
};

enum class CondicionDeVenta : short {
    Contado = 1,
    Credito = 2,
    Consignacion = 3,
    Apartado = 4,
    ArrendamientoOpcionCompra = 5,
    ArrendamientoFuncionFinaciera = 6,
    CobroFavorTercero = 7,
    ServiciosEstado = 8,
    PagoServiciosEstado = 9,
    VentaCreditoIVA = 10,
    PagoVentaCreditoIVA = 11,
    VentaMercanciaNoNacionalizada = 12,
    VentaBienUsadoNoContribuyente = 13,
    ArrendamientoOperativo = 14,
    ArrendamientoFinanciero = 15,
    Otros = 99
};

enum class MedioPago : short {
    Efectivo = 1,
    Tarjeta  = 2,
    Cheque   = 3,
    Transferencia = 4,
    RecaudadoTerceros = 5,
    SINPEMovil = 6,
    PlataformaDigital = 7,
    Otros    = 99
};

enum class CodigoReferenciaOtro : short {
    AnulaDocumentoReferencia = 1,
    CorrigeMonto = 2,
    ReferenciaOtroDocumento = 4,
    SustituyeComprobanteProvicional = 5,
    DevolucionMercancia = 6,
    SustituyeComprobanteElectronico = 7,
    FacutoraEndosada = 8,
    NotaCredito = 9,
    NotaDebito = 10,
    ProveedorNoDomiciliado = 11,
    CreditoExoneracionPosterior = 12,
    Otros = 99
};

enum class DescripcionMensaje : short {
    Aceptado = 1,
    AceptadoParcial = 2,
    Rechazado = 3
};

enum class CodigoProductoServicio : short {
    CodigoProductorVendedor = 1,
    CodigoProductorComprador = 2,
    CodigoProductorFabricante = 3,
    UsoInterno = 4,
    Otros = 99,
};

enum class TipoTransaccion : short {
    VentaNormalBienesServicios = 1,
    MercanciaAutoconsumoExento = 2,
    MercanciaAutoconsumoGravado = 3,
    ServicioAutoconsumoExento = 4,
    ServicioAutoconsumoGravado = 5,
    CuotaAfiliacion = 6,
    CuotaAfiliacionExenta = 7,
    BienesCapitalEmisor = 8,
    BienesCapitalReceptor = 9,
    BienesCapitalEmisorReceptor = 10,
    BienesCapitalAutoconsumoExentoEmisor = 11,
    BienesCapitalContraprestacionAutoconsumoExentoEmisor = 12,
    SinContraprestacionTerceros = 13
};

enum class Institucion : short {
    MinisterioHacienda = 1,
    MinisterioRelacionesExteriores = 2,
    MinisterioAgriculturaGanaderia = 3,
    MinisterioEconomiaIndustriaComercio = 4,
    CruzRojaCostarricense = 5,
    BomberosCostaRica = 6,
    AsociacionObrasEspirituSanto = 7,
    Fecrunapa = 8,
    EARTH = 9,
    INCAE = 10,
    JPS = 11,
    Aresep = 12,
    Otros = 99
};

enum class CodigoDescuento : short {
    Regalia = 1,
    RegaliaIVACobradoCliente = 2,
    Bonificacion = 3,
    Volumen = 4,
    TemporadaEstacional = 5,
    Promocional = 6,
    Comercial = 7,
    Frecuencia = 8,
    Sostenido = 9,
    Otros = 99
};