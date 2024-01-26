#ifndef __ZVENTA_H__
#define __ZVENTA_H__
#include <zSiscomRegistro.h>

class zOrden;
class zCredito;
class zVenta:public zSiscomRegistro
{
  public:
  	zVenta();
	void IdVenta(const unsigned char *pchrPtrIdVenta);
	void IdTipoVenta(const unsigned char *pchrPtrIdTipoVenta);
	void IdConcepto(const unsigned char *pchrPtrIdConcepto);
	void IdTiendaEntrega(const unsigned char *pchrPtrIdTiendaEntrega);
	void NombreTiendaEntrega(const unsigned char *pchrPtrNombreTiendaEntrega);
	void IdVendedor(const unsigned char *pchrPtrIdVendedor);
	void NombreVendedor(const unsigned char *pchrPtrNombreVendedor);
	void Folio(const unsigned char *pchrPtrFolio);
	void Fecha(const unsigned char *pchrPtrFecha);
	void Anio(const unsigned char *pchrPtrAnio);
	void Mes(const unsigned char *pchrPtrMes);
	void Dia(const unsigned char *pchrPtrDia);
	void IdCliente(const unsigned char *pchrPtrIdCliente);
	void Nombre(const unsigned char *pchrPtrNombre);
	void APaterno(const unsigned char *pchrPtrAPaterno);
	void AMaterno(const unsigned char *pchrPtrAMaterno);
	void RFC(const unsigned char *pchrPtrRFC);
	void IdDireccion(const unsigned char *pchrPtrIdDireccion);
	void Calle(const unsigned char *pchrPtrCalle);
	void NumExterior(const unsigned char *pchrPtrNumExterior);
	void NumInterior(const unsigned char *pchrPtrNumInterior);
	void Colonia(const unsigned char *pchrPtrColonia);
	void DelegMunic(const unsigned char *pchrPtrDelegMunic);
	void CodigoPostal(const unsigned char *pchrPtrCodigoPostal);
	void Referencias(const unsigned char *pchrPtrReferencias);
	void FormaEntrega(zSiscomRegistro *pzSisRegFormaEntrega);
	void InstruccionesEntrega(const char *pchrPtrIntsEntrega);
	void TiendaVenta(zSiscomRegistro *pzSisRegTienda);
	void Telefono(const char *pchrPtrTelefono);
	void IdTelefono(const char *pchrPtrIdTelefono);
	
	void Orden(zOrden *pzOrden);
	void Credito(zCredito *pzCredito);
	const char *SiglasTienda();
	zOrden *Orden();

	const char *Folio();
	const char *Id();
};

#endif


