#include <CQSisClientes.h>
CQSisCliente::CQSisCliente(const char *pchrPtrNombre,
			  const char *pchrPtrAPaterno,
			  const char *pchrPtrAMaterno,
			  const char *pchrPtrRFC,
			  const char *pchrPtrIdExpendio,
			  const char *pchrPtrIdPersona)
{
(*this)						<<
new SiscomCampo3("Nombre",pchrPtrNombre)	<<
new SiscomCampo3("APaterno",pchrPtrAPaterno)	<<
new SiscomCampo3("AMaterno",pchrPtrAMaterno)	<<
new SiscomCampo3("RFC",pchrPtrRFC)		<<
new SiscomCampo3("IdExpendio",pchrPtrIdExpendio)	<<
new SiscomCampo3("IdPersona",pchrPtrIdPersona);

}

CQSisCliente::CQSisCliente(const char *pchrPtrRazonSocial,
			   const char *pchrPtrRFC,
			   const char *pchrPtrIdPersona,
			   const char *pchrPtrIdExpendio)
{
(*this)							<<
new SiscomCampo3("RazonSocial",pchrPtrRazonSocial)	<<
new SiscomCampo3("RFC",pchrPtrRFC)			<<
new SiscomCampo3("IdExpendio",pchrPtrIdExpendio)	<<
new SiscomCampo3("IdPersona",pchrPtrIdPersona);
}
void CQSisCliente::Direccion(
			const char *pchrPtrCalle,
			const char *pchrPtrNumero,
			const char *pchrPtrColonia,
			const char *pchrPtrCP,
			const char *pchrPtrDelMunicipio,
			const char *pchrPtrEstado)
{
(*this)							<<
new SiscomCampo3("Calle",pchrPtrCalle)			<<
new SiscomCampo3("Numero",pchrPtrNumero)		<<
new SiscomCampo3("Colonia",pchrPtrColonia)		<<
new SiscomCampo3("CP",pchrPtrCP)			<<
new SiscomCampo3("Municipio",pchrPtrDelMunicipio)	<<
new SiscomCampo3("Estado",pchrPtrEstado);
}
void CQSisCliente::Telefono(const char *pchrPtrTelefono)
{
(*this)					<<
new SiscomCampo3("Telefono",pchrPtrTelefono);
}


void CQSisCliente::Correo(const char *pchrPtrCorreo)
{
(*this)					<<
new SiscomCampo3("Correo",pchrPtrCorreo);
}
