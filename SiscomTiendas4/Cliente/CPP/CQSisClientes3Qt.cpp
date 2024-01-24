#include <CQSisClientes3Qt.h>
#include <CQSisResponsableVehiculo.h>
#include <CQSisComunesTiendas3Qt.h>
#include <SiscomDesarrollo3Qt++.h>
#include <string.h>
#include <stdio.h>

CQSisCliente3Qt::CQSisCliente3Qt(const char *pchrPtrIdPersona,
				 const char *pchrPtrNombre,
				 const char *pchrPtrAPaterno,
				 const char *pchrPtrAMaterno)
{
	(*this)			<<
	new SiscomCampo3("IdPersona",pchrPtrIdPersona)		<<
	new SiscomCampo3("Nombre",pchrPtrNombre)		<<
	new SiscomCampo3("APaterno",pchrPtrAPaterno)		<<
	new SiscomCampo3("AMaterno",pchrPtrAMaterno);
}


CQSisCliente3QtLst::CQSisCliente3QtLst()
{

}
SiscomRegistro3 *CQSisCliente3QtLst::Cliente(const char *pchrPtrCliente)
{
SiscomRegistro3 *lSReg3Cliente;
char lchrArrCliente[120];
int lintContador;
for(lSReg3Cliente=first(),
    lintContador=0;
    lSReg3Cliente;
    lSReg3Cliente=next(),
    lintContador++)
{
CQSisComunesTiendas3Qt::NombreCompleto(lSReg3Cliente,lchrArrCliente);
SiscomEscribeLog3Qt("[%s] ? [%s]",pchrPtrCliente,lchrArrCliente);
if(!strcmp(lchrArrCliente,pchrPtrCliente))
{
SiscomEscribeLog3Qt("");
intNCliente=lintContador;
return lSReg3Cliente;
}
}
return 0;
}
int CQSisCliente3QtLst::Cliente()
{
	return intNCliente;
}
CQSisClienteOp3Qt::CQSisClienteOp3Qt(SiscomDatCom *pSisDatCom):
			SiscomOperaciones3(pSisDatCom)
{

}
int CQSisClienteOp3Qt::RegistraPropietario(CQSisCliente3Qt *pCQSisCliente3Qt)
{
int lintRegreso=0;
SiscomRegistro3Lst lSReg3LstEnvio;
SiscomRegistro3Lst lSReg3LstRegreso;

lSReg3LstEnvio << pCQSisCliente3Qt;
SiscomEnvia("RegistraPropietarioVehiculo",
	    &lSReg3LstEnvio,
	    &lSReg3LstRegreso);
if(!strcmp(lSReg3LstRegreso["Error"],"Persona Ya Registrada"))
lintRegreso=1;

	  
pCQSisCliente3Qt->SiscomActualizaCampo("IdPersona",lSReg3LstRegreso["IdPersona"]);

return lintRegreso;
}
int CQSisClienteOp3Qt::RegistraResponsableVehiculo(CQSisResponsableVehiculo *pCQSisCliente3Qt)
{
int lintRegreso=0;
SiscomRegistro3Lst lSReg3LstEnvio;
SiscomRegistro3Lst lSReg3LstRegreso;

lSReg3LstEnvio << pCQSisCliente3Qt;
SiscomEnvia("RegistraResponsableVehiculo",
	    &lSReg3LstEnvio,
	    &lSReg3LstRegreso);
if(!strcmp(lSReg3LstRegreso["Error"],"Persona Ya Registrada"))
lintRegreso=1;

pCQSisCliente3Qt->SiscomActualizaCampo("IdPersona",lSReg3LstRegreso["IdPersona"]);

}
