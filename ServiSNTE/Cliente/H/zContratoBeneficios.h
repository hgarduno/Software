#ifndef __ZCONTRATOBENEFICIOS_H__
#define __ZCONTRATOBENEFICIOS_H__
#include <zSiscomRegistro.h>

class zProductos;
class zDireccion;
class zTelefonos;
class zEmpleo;
class zCargoPublico;
class zAportacionTercero;
class zBeneficioTercero;
class zDatosGenerales;
class zDatosComunicacion;
class zGeneralesBeneficios;
class zReferenciasPersonales;
class zCentroTrabajo;
class zContratoBeneficios:public zSiscomRegistro
{
 public:
    zContratoBeneficios(zSiscomRegistro *pzSisRegCliente);
    void Productos(zProductos *pzProdsContratoBeneficios);
    void Comunicacion(zDatosComunicacion *pzDatComunicacion);
    void Credito(zSiscomRegistro *pzSisRegCredito);
    void DireccionParticular(zDireccion *pzDireccion);
    void TiempoResidir(const char *pchrPtrTiempoResidir);
    void TipoVivienda(zSiscomRegistro *pzSisRegTipoVivienda);
    void Empleo(zEmpleo *pzEmpleo);
    void CargoPublico(zCargoPublico *pzCargoPublico);
    void BeneficioTercero(zBeneficioTercero *pzBeneficioTercero);
    void AportacionTercero(zAportacionTercero *pzAportacionTercero);
    void Generales(zDatosGenerales *pzDatGenerales);
    void GeneralesContrato(zGeneralesBeneficios *pzGenBeneficios);
    void Lugar(const char *pchrPtrLugar);
    void Fecha(const char *pchrPtrFecha);
    void ReferenciasPersonales(zReferenciasPersonales *pzRefsPersonales);
    void CentroTrabajo(zCentroTrabajo *pzCentroTrabajo);

    const char *NombreReferencia(int pintNReferencia);
    const char *DomicilioReferencia(int pintNReferencia);
    const char *TelefonoReferencia(int pintNReferencia);
    const char *ParentescoReferencia(int pintNReferencia);

    zCentroTrabajo *CentroTrabajo();
    const char *CentroTrabajo2();
    const char *ClavePresupuestal();

    
    const char *IdVenta();
    
    const char *Importe();
    const char *ImporteLetra();
    const char *Fecha();
    const char *FechaConMesLetra();
    
    const char *DiaFecha();
    const char *MesFecha();
    const char *AnioFecha();
    const char *MesFechaLetra();


    const char *Lugar();
    const char *CURP();
    const char *EstadoNacimiento();
    const char *PaisNacimiento();
    const char *Genero();
    const char *EsMasculino();
    const char *EsFemenino();
    const char *EstadoCivil();
    const char *EsSoltero();
    const char *EsCasado();
    const char *Edad();
    const char *FechaNacimiento();
    const char *Identificacion();
    const char *NoIdentificacion();
    const char *Ocupacion();
    const char *Nacionalidad();
    
  
    const char *Antiguedad();
    const char *Puesto();
    const char *Sueldo();
    const char *OtrosIngresosMonto();
    const char *OtrosIngresosDescripcion();
    const char *TotalIngresos();

    const char *FrecuenciaPago();
    const char *EsFrecuenciaPagoSemanal();
    const char *EsFrecuenciaPagoCatorcenal();
    const char *EsFrecuenciaPagoQuincenal();
    const char *EsFrecuenciaPagoMensual();

    const char *Empresa();
    const char *Giro();
    const char *Jefe();
    const char *NombreJefe();
    const char *APaternoJefe();
    const char *AMaternoJefe();
    const char *TelefonoEmpleo();
    const char *ExtensionEmpleo();
    const char *CorreoEmpleo();

    const char *CalleEmpleo();
    const char *NumExteriorEmpleo();
    const char *NumInteriorEmpleo();
    const char *ColoniaEmpleo();
    const char *CodigoPostalEmpleo();
    const char *DelegacionEmpleo();
    const char *CiudadEmpleo();
    const char *EstadoEmpleo();



    zDireccion *DireccionParticular();
    const char *TiempoResidir();
    const char *CorreoElectronico();

    const char *TipoViviendaPropia();
    const char *TipoViviendaHipotecada();
    const char *TipoViviendaFamiliar();
    const char *TipoViviendaRentada();

    const char *EsTipoViviendaPropia();
    const char *EsTipoViviendaHipotecada();
    const char *EsTipoViviendaFamiliar();
    const char *EsTipoViviendaRentada();



    const char *IdCliente();
    const char *Nombre();
    const char *APaterno();
    const char *AMaterno();
    const char *NombreCompleto();
    const char *RFC();
    const char *PagoQuincenal();
    const char *PagoTotal();
    const char *PagoTotalLetra();
    const char *PagoQuincenalLetra();
    const char *Plazo();
    const char *Tasa();
    const char *PorcentajeTasa();
    const char *PorcentajeTasaLetra();
    const char *NumeroPagos();

    const char *Calle();
    const char *NumExterior();
    const char *NumInterior();
    const char *Colonia();
    const char *CodigoPostal();
    const char *Delegacion();
    const char *Ciudad();
    const char *Estado();

    const char *TelefonoParticular();
    const char *TelefonoCelular();
    const char *TelefonoRecados();
    zDatosComunicacion *Comunicacion();
    zEmpleo *Empleo();
    zProductos *Productos();
private:
	const char *Cadena(const unsigned char *pchrPtrCadena);
	zTelefonos *Telefonos();
	char chrArrMes[3];
	char chrArrAnio[5];
};

#endif
