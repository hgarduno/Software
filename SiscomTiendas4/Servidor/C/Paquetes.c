#include <Paquetes.h>
#include <ComunSiscomTiendas4.h>
#include <SqlPaquetes.h>

SiscomOperaciones2 *OEliminaPaquete()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(100,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosPaquetes,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlEliminaPaquete,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraPaquete,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OAnexarProductoPaquete()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(100,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosPaquetes,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlAnexarProductoPaquete,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraPaquete,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OEliminaProductoPaquete()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(100,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosPaquetes,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlEliminaProductoPaquete,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraPaquete,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OPaquetesDisponibles()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(100,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlPaquetesDisponibles,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OProductosDelPaquete()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(100,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlProductosPaquete,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *ORegistraPaquete()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(100,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosPaquetes,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(GeneraIdPaquete,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraPaquete,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraPaquete,lSOpOperaciones);
return lSOpOperaciones;
}


SiscomOperaciones2 *OProductosPaquete()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(100,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosPaquetes,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraProductosPaquete,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraPaquete,lSOpOperaciones);
return lSOpOperaciones;
}
void RegistraPaquete(SArgsSiscom *pSAgsSiscom)
{
SiscomEnviaServidorArgumento(pSAgsSiscom,"SQLPaquetes");
}
void ArgumentosPaquetes(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SQLPaquetes",pSAgsSiscom);
}
void GeneraIdPaquete(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraIdRegistro(pSAgsSiscom,"IdPaquete");
}

