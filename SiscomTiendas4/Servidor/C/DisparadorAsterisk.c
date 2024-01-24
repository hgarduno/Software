#include <DisparadorAsterisk.h>
#include <SiscomDesarrollo2.h>
void EnviaNumero(int pintPuerto,
		 const char *pchrPtrDireccion,
		 const char *pchrPtrNumero)
{
int lintNRegistros;
LCamposSiscomPro2 *lLCSiscomPro2Dat=0;
char *lchrPtrEdoConexion;
int lintSocket;
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRespuesta=0;
FormaRegistro(pchrPtrNumero,&lintNRegistros,&lLCSiscomPro2Dat);
SiscomInformacionServidorConRespuesta(
		pintPuerto,
		pchrPtrDireccion,
		"AsignaAsesor",
		lintNRegistros,
		lLCSiscomPro2Dat,
		&lchrPtrEdoConexion,
		&lintSocket,
		&lLCSiscomPro2Reg,
		&lintNRegRespuesta);

}


void FormaRegistro(const char *pchrPtrTelefono,
		   int *pintPtrNRegistros,
		   LCamposSiscomPro2 **pLCSiscomPro2)
{
LCamposSiscomPro2 *lLCSiscomPro2Act=0;

	*pLCSiscomPro2=0;
	*pintPtrNRegistros=0;

SiscomAnexaRegistroPro2(
		pLCSiscomPro2,
		&lLCSiscomPro2Act,
		pintPtrNRegistros,
		"Numero,Algo,Algo1",
		pchrPtrTelefono,
		"Prueba",
		"Prueba1");

}
