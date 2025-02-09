#pragma once
enum class TipoDocumento : short {
    FacturaElectronica = 1,
    NotaDebito = 2,
    NotaCredito = 3,
    TiqueteElectronico = 4,
    ConfirmacionAceptacion = 5,
    ConfirmacionAceptacionParcial = 6,
    ConfirmacionRechazo = 7,
    FacuraElectronicaCompras = 8,
    FacuraElectronicaExportacion = 9,
    ReciboElectronicoPago = 10
};

enum class TipoDocumentoReferencia : short {
    FacturaElectronica = 1,
    NotaDebito = 2,
    NotaCredito = 3,
    TiqueteElectronico = 4,
    NotaDespacho = 5,
    Contrato = 6,
    Procedimiento = 7,
    ComprobanteEmitidoContingencia = 8,
    DevolucionMercaderia = 9,
    ComprobanteRechazo = 10,
    SustituyeFacturaRechazada = 11,
    SustituyeFacturaExportacion = 12,
    FacturacionMesVencido = 13,
    ComprobanteAportadoRegimenEspecial = 14,
    SustituyeFacturaCompra = 15,
    ComprobanteProveedorNoDomiciliado = 16,
    NotaCreditoFacturaElectronicaExportacion = 17,
    NotaDebitoFacturaElectronicaExportacion = 18,
    Otros = 99
};

enum class TipoDocumentoAutorizacionExoneracion : short {
    ComprasAutorizadasDGT = 1,
    VentasExentasDiplomatico = 2,
    AutorizadoLeyEspcial = 3,
    ExencionDGHLocalGenerica = 4,
    ExencionDGHTransitorioV = 5,
    ServiciosTuristicosICT = 6,
    TransitorioXVII = 7,
    ExoneracionZonaFranca = 8,
    ExnoneracionServiciosComplemetarios = 9,
    OrganoCorporacionesMunicipales = 10,
    ExencionesDGHImpuestoLocal = 11,
    Otros = 99
};

enum class TipoDocumentoOtrosCargos : short {
    ContribucionParafiscal = 1,
    TimbreCruzRoja = 2,
    TimbreBomberos = 3,
    CobroTercero = 4,
    CostosExportacion = 5,
    ImpuestoServicio = 6,
    TimbreColegioProfesional = 7,
    DepositoGarantia = 8,
    MultasPenalizaciones = 9,
    InteresMoratorios = 10,
    Otros = 99
};