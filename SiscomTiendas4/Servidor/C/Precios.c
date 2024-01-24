#include <Precios.h>
#include <SQLPrecios.h>
#include <ComunSiscomTiendas4.h>
#include <stdlib.h>
#include <string.h>
SiscomOperaciones2 *OPPreciosRegistrados()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SQLPreciosRegistrados,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OPAnexaPrecio()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosPrecios,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(CambiaMayusculasPrecio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(GeneraIdPrecio,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SQLRegistraPrecios,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraPrecio,lSOpOperaciones); 
return lSOpOperaciones;
}
SiscomOperaciones2 *OPIniciaPrecios()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ArgumentosIniciaPrecios,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SQLObtenPrecios,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SQLObtenProductos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SQLIniciaPreciosProductos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(IniciaPreciosProductos,lSOpOperaciones);
return lSOpOperaciones;

}
SiscomOperaciones2 *OPPreciosProducto()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SQLPreciosProducto,lSOpOperaciones); 
return lSOpOperaciones;

}
SiscomOperaciones2 *OPActualizaPrecioProducto()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(ArgumentosPrecios,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SQLActualizaPrecioProducto,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(RegistraPrecio,lSOpOperaciones); 
return lSOpOperaciones;

}
void ArgumentosPrecios(SArgsSiscom *pSAgsSiscom)
{
SiscomMensajesLog2("ArgumentosPrecios"); 
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"Precios",pSAgsSiscom);
}
void CambiaMayusculasPrecio(SArgsSiscom *pSAgsSiscom)
{
CambiaCampoProtocoloMayusculas(pSAgsSiscom->LCSiscomPro2Dat,"Nombre");
}
void GeneraIdPrecio(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Contador;
char lchrArrIdPrecio[12];

for(lLCSiscomPro2Contador=pSAgsSiscom->LCSiscomPro2Dat;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{
	SiscomObtenNumeroUnicoChar(lchrArrIdPrecio);
	SiscomAsignaDatoCampo2("IdPrecio",lchrArrIdPrecio,lLCSiscomPro2Contador);
}

}
void RegistraPrecio(SArgsSiscom *pSAgsSiscom)
{
EjecutaRegistroInformacion(pSAgsSiscom,"Precios"); 
}

void ArgumentosIniciaPrecios(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(3,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"Precios",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"Productos",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"Registrar",pSAgsSiscom);
}
void IniciaPreciosProductos(SArgsSiscom *pSAgsSiscom)
{
EjecutaRegistroInformacion(pSAgsSiscom,"Registrar"); 

}
