#include <CQSisComunesTiendas3Qt.h>
#include <SiscomRegistros3.h>
#include <stdio.h>
#include <string.h>
CQSisComunesTiendas3Qt::CQSisComunesTiendas3Qt()
{

}
void CQSisComunesTiendas3Qt::NombreCompleto(SiscomRegistro3 *pSisReg3Persona,
					    char *pchrPtrNmbCompleto)
{
const char *lchrPtrNombre,
           *lchrPtrAPaterno,
	   *lchrPtrAMaterno;
lchrPtrNombre=(*pSisReg3Persona)["nombre"];
lchrPtrAPaterno=(*pSisReg3Persona)["apaterno"];
lchrPtrAMaterno=(*pSisReg3Persona)["amaterno"];
if(lchrPtrNombre[0])
strcpy(pchrPtrNmbCompleto,lchrPtrNombre);
if(lchrPtrAPaterno[0])
{
strcat(pchrPtrNmbCompleto," ");
strcat(pchrPtrNmbCompleto,lchrPtrAPaterno);
}
if(lchrPtrAMaterno[0])
{
strcat(pchrPtrNmbCompleto," ");
strcat(pchrPtrNmbCompleto,lchrPtrAMaterno);
}
}
