#include <RastreaProducto.h>
#include <SqlRastreaProducto.h>
#include <ComunElectronica2.h>

#include <stdlib.h>
SiscomOperaciones2 *OpRastreaProducto()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*350);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOpSubRegistros,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendio3,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosRastreaProducto,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlExistenciaProducto,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlExiProductoBodegas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlVentasProductoAnterior,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlComprasProductoAnterior,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlTransferenciasExpendioExpendio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlTransferenciasBodegasExpendio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlTotalVentasAnterior,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlTotalComprasAnterior,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlTotalTransBodExp,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlTotalTransExpExp,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlActualizoInventario,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(AgregaRegistrosVacios,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(FormaRegistroTotales,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RastreaProducto,lSOpOperaciones);
return lSOpOperaciones;
}


void RastreaProducto(SArgsSiscom *pSAgsSiscom)
{
SiscomContenidoSubRegistrosLog(pSAgsSiscom->LCSiscomPro2SREntrada);
/*
SiscomImprimeArgumento("SqlExistencia",pSAgsSiscom);
SiscomImprimeArgumento("SqlExBodegas",pSAgsSiscom);
SiscomImprimeArgumento("SqlVentas",pSAgsSiscom);
SiscomImprimeArgumento("SqlTransBodegaExpendio",pSAgsSiscom);
SiscomImprimeArgumento("SqlTransExpendioExpendio",pSAgsSiscom);
SiscomImprimeArgumento("SqlActualizoInventario",pSAgsSiscom);
*/

SiscomSumaListas(pSAgsSiscom->LCSiscomPro2Regreso,
		  SiscomArgumentoOperacionPrim("SqlExistencia",pSAgsSiscom));
SiscomSumaListas(pSAgsSiscom->LCSiscomPro2Regreso,
		  SiscomArgumentoOperacionPrim("SqlExBodegas",pSAgsSiscom));
SiscomSumaListas(pSAgsSiscom->LCSiscomPro2Regreso,
		  SiscomArgumentoOperacionPrim("SqlVentas",pSAgsSiscom));
SiscomSumaListas(pSAgsSiscom->LCSiscomPro2Regreso,
		  SiscomArgumentoOperacionPrim("SqlCompras",pSAgsSiscom));
SiscomSumaListas(pSAgsSiscom->LCSiscomPro2Regreso,
		  SiscomArgumentoOperacionPrim("SqlTransBodegaExpendio",pSAgsSiscom));
SiscomSumaListas(pSAgsSiscom->LCSiscomPro2Regreso,
		 SiscomArgumentoOperacionPrim("SqlTransExpendioExpendio",pSAgsSiscom));
SiscomSumaListas(pSAgsSiscom->LCSiscomPro2Regreso,
		 SiscomArgumentoOperacionPrim("SqlActualizoInventario",pSAgsSiscom));

pSAgsSiscom->intNumRegRegreso=
	SiscomArgumentosNumeroRegistros("SqlExistencia",pSAgsSiscom)		+
	SiscomArgumentosNumeroRegistros("SqlExBodegas",pSAgsSiscom)		+
	SiscomArgumentosNumeroRegistros("SqlVentas",pSAgsSiscom)		+
	SiscomArgumentosNumeroRegistros("SqlCompras",pSAgsSiscom)		+
	SiscomArgumentosNumeroRegistros("SqlTransBodegaExpendio",pSAgsSiscom)	+
	SiscomArgumentosNumeroRegistros("SqlTransExpendioExpendio",pSAgsSiscom)	+
	SiscomArgumentosNumeroRegistros("SqlActualizoInventario",pSAgsSiscom)	+
	2;
SiscomLog("Ahora se envia");
if(pSAgsSiscom->LCSiscomPro2Regreso)
{
SiscomEnviaRegreso(pSAgsSiscom);
/*SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Regreso);*/
}
else
SiscomLog("Noooooooooo, NULO");
}
void FormaRegistroTotales(SArgsSiscom *pSAgsSiscom)
{
pSAgsSiscom->LCSiscomPro2Regreso=0;
SiscomAnexaRegistroRegreso(
	pSAgsSiscom,
	"TotalVentas,		\
	TotalCompras,		\
	TotalTransBodExp,	\
	TotalTransExpExp",
	SiscomObtenCampoArgumento("SqlTotalVentas","totalventas",pSAgsSiscom),
	SiscomObtenCampoArgumento("SqlTotalCompras","totalcompras",pSAgsSiscom),
	SiscomObtenCampoArgumento("SqlTotalTransBodExp","tottransbodexp",pSAgsSiscom),
	SiscomObtenCampoArgumento("SqlTotalTransExpExp","tottransexpexp",pSAgsSiscom));

}
void ArgumentosRastreaProducto(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(12,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlExistencia",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SqlExBodegas",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"SqlVentas",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(3,"SqlCompras",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(4,"SqlTransBodegaExpendio",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(5,"SqlTransExpendioExpendio",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(6,"SqlTotalVentas",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(7,"SqlTotalCompras",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(8,"SqlTotalTransBodExp",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(9,"SqlTotalTransExpExp",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(10,"SqlActualizoInventario",pSAgsSiscom);
}
LCamposSiscomPro2 *ValidaConsultaVacia(const char *pchrPtrArgumento,
				       SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2RegPrim=0;
LCamposSiscomPro2 *lLCSiscomPro2RegAct=0;
int lintNRegRegreso=0;
  if(!(lLCSiscomPro2RegPrim=SiscomArgumentoOperacionPrim(pchrPtrArgumento,pSAgsSiscom)))
  {
     SiscomAnexaRegistroPro2(
     		&lLCSiscomPro2RegPrim,
		&lLCSiscomPro2RegAct,
		&lintNRegRegreso,
		pchrPtrArgumento,
		 "Vacio");
     SiscomAsignaArgumentoNumeroRegistros(pchrPtrArgumento,
     					  1,
					  pSAgsSiscom);
  }
  return lLCSiscomPro2RegPrim;
}

LCamposSiscomPro2 *TExpendioExpendio(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2RegPrim=0;
LCamposSiscomPro2 *lLCSiscomPro2RegAct=0;
int lintNRegRegreso=0;
  if(!(lLCSiscomPro2RegPrim=SiscomArgumentoOperacionPrim("SqlTransExpendioExpendio",pSAgsSiscom)))
  {
     /* 
      * Para enviar el regreso cuando no se obtuvo informacion 
      * de la consulta se debera considerar el hecho de 
      * enviar solo un campo vacio, para no tener que modificar 
      * para cada consulta, y en el cliente se preguntara por 
      * este nombre de campo, si va es que fue vacio sino 
      * si se encontro informacion en la base de datos
      *
      */
     SiscomAnexaRegistroPro2(
     		&lLCSiscomPro2RegPrim,
		&lLCSiscomPro2RegAct,
		&lintNRegRegreso,
		"EdoConsulta",
		 "Vacio");
     SiscomAsignaArgumentoNumeroRegistros("SqlTransExpendioExpendio",
     					  1,
					  pSAgsSiscom);
  }

  return lLCSiscomPro2RegPrim;
}


void AgregaRegistrosVacios(SArgsSiscom *pSAgsSiscom)
{
	ValidaExistenciaParaRastreo(pSAgsSiscom);
	ValidaExistenciaBodegas(pSAgsSiscom);
	ValidaVentas(pSAgsSiscom);
	ValidaCompras(pSAgsSiscom);
	ValidaTransferenciaBodegaExpendio(pSAgsSiscom);
	ValidaTransferenciaExpendioExpendio(pSAgsSiscom);
	ValidaTotalVentas(pSAgsSiscom);
	ValidaTotalCompras(pSAgsSiscom);
	ValidaTotalTransferenciaBodegaExpendio(pSAgsSiscom);
	ValidaTotalTransferenciaExpendioExpendio(pSAgsSiscom);
	ValidaActualizoInventario(pSAgsSiscom);
}
void ValidaExistenciaParaRastreo(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2RegPrim=0;
LCamposSiscomPro2 *lLCSiscomPro2RegAct=0;
int lintNRegRegreso=0;
if(!(SiscomArgumentoOperacionPrim("SqlExistencia",pSAgsSiscom)))
{
     SiscomAnexaRegistroPro2(
     		&lLCSiscomPro2RegPrim,
		&lLCSiscomPro2RegAct,
		&lintNRegRegreso,
		"cveproducto,	\
		 idexpendio,	\
		 existencia,	\
		 exbodegas",
		 "",
		 "",
		 "0",
		 "0");
    SiscomAsignaInformacionArgumento("SqlExistencia",
    				     pSAgsSiscom,
     				    lLCSiscomPro2RegPrim,
				    lLCSiscomPro2RegAct,
				    lintNRegRegreso);
				     
}

}
void ValidaExistenciaBodegas(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2RegPrim=0;
LCamposSiscomPro2 *lLCSiscomPro2RegAct=0;
int lintNRegRegreso=0;
if(!(SiscomArgumentoOperacionPrim("SqlExBodegas",pSAgsSiscom)))
{
     SiscomAnexaRegistroPro2(
     		&lLCSiscomPro2RegPrim,
		&lLCSiscomPro2RegAct,
		&lintNRegRegreso,
		"idbodega,	\
		 cveproducto,	\
		 existencia,	\
		 idcompra,	\
		 bodega",
		 "",
		 "",
		 "",
		 "",
		 "");
    SiscomAsignaInformacionArgumento("SqlExBodegas",
    				     pSAgsSiscom,
     				    lLCSiscomPro2RegPrim,
				    lLCSiscomPro2RegAct,
				    lintNRegRegreso);
				     
}

}

void ValidaVentas(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2RegPrim=0;
LCamposSiscomPro2 *lLCSiscomPro2RegAct=0;
int lintNRegRegreso=0;
if(!(SiscomArgumentoOperacionPrim("SqlVentas",pSAgsSiscom)))
{
     SiscomAnexaRegistroPro2(
     		&lLCSiscomPro2RegPrim,
		&lLCSiscomPro2RegAct,
		&lintNRegRegreso,
		"idexpendio,	\
		 idventa,	\
		 fechahora,	\
		 cveproducto,	\
		 cantidad,	\
		 importe,	\
		 precio,	\
		 vendedor,	\
		 cliente,	\
		 edoventa,	\
		 idproducto",
		 "",
		 "",
		 "",
		 "",
		 "",
		 "",
		 "",
		 "",
		 "",
		 "",
		 "");
    SiscomAsignaInformacionArgumento("SqlVentas",
    				     pSAgsSiscom,
     				    lLCSiscomPro2RegPrim,
				    lLCSiscomPro2RegAct,
				    lintNRegRegreso);
				     
}

}
void ValidaCompras(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2RegPrim=0;
LCamposSiscomPro2 *lLCSiscomPro2RegAct=0;
int lintNRegRegreso=0;
if(!(SiscomArgumentoOperacionPrim("SqlCompras",pSAgsSiscom)))
{
     SiscomAnexaRegistroPro2(
     		&lLCSiscomPro2RegPrim,
		&lLCSiscomPro2RegAct,
		&lintNRegRegreso,
		"fecha,	\
		 cveproducto,	\
		 cantidad,	\
		 importe,	\
		 proveedor,	\
		 conproveedor,	\
		 responsable,	\
		 idexpendio,	\
		 formapago,	\
		 numfactura,	\
		 precio,	\
		 preciosiniva,	\
		 idcompra",
		 "",
		 "",
		 "",
		 "",
		 "",
		 "",
		 "",
		 "",
		 "",
		 "",
		 "",
		 "",
		 "");
    SiscomAsignaInformacionArgumento("SqlCompras",
    				     pSAgsSiscom,
     				    lLCSiscomPro2RegPrim,
				    lLCSiscomPro2RegAct,
				    lintNRegRegreso);
				     
}

}

void ValidaTransferenciaBodegaExpendio(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2RegPrim=0;
LCamposSiscomPro2 *lLCSiscomPro2RegAct=0;
int lintNRegRegreso=0;
if(!(SiscomArgumentoOperacionPrim("SqlTransBodegaExpendio",pSAgsSiscom)))
{
     SiscomAnexaRegistroPro2(
     		&lLCSiscomPro2RegPrim,
		&lLCSiscomPro2RegAct,
		&lintNRegRegreso,
		"idbodega,	\
		 idexpendio,	\
		 fecha,	\
		 idempleado,	\
		 cantidad,	\
		 cveproducto",
		 "",
		 "",
		 "",
		 "",
		 "",
		 "");
    SiscomAsignaInformacionArgumento("SqlTransBodegaExpendio",
    				     pSAgsSiscom,
     				    lLCSiscomPro2RegPrim,
				    lLCSiscomPro2RegAct,
				    lintNRegRegreso);
				     
}




}
void ValidaTransferenciaExpendioExpendio(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2RegPrim=0;
LCamposSiscomPro2 *lLCSiscomPro2RegAct=0;
int lintNRegRegreso=0;
if(!(SiscomArgumentoOperacionPrim("SqlTransExpendioExpendio",pSAgsSiscom)))
{
     SiscomAnexaRegistroPro2(
     		&lLCSiscomPro2RegPrim,
		&lLCSiscomPro2RegAct,
		&lintNRegRegreso,
		"fechahora,	\
		 idempresaorigen,	\
		 idempresadestino,	\
		 cveproducto,	\
		 cantidad,	\
		 idempleado,	\
		 idtransferencia",
		 "",
		 "",
		 "",
		 "",
		 "",
		 "",
		 "");
    SiscomAsignaInformacionArgumento("SqlTransExpendioExpendio",
    				     pSAgsSiscom,
     				    lLCSiscomPro2RegPrim,
				    lLCSiscomPro2RegAct,
				    lintNRegRegreso);
				     
}


}

void ValidaTotalVentas(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2RegPrim=0;
LCamposSiscomPro2 *lLCSiscomPro2RegAct=0;
int lintNRegRegreso=0;
if(!(SiscomArgumentoOperacionPrim("SqlTotalVentas",pSAgsSiscom)))
{
     SiscomAnexaRegistroPro2(
     		&lLCSiscomPro2RegPrim,
		&lLCSiscomPro2RegAct,
		&lintNRegRegreso,
		"totalventas,"
		 "0.0");
    SiscomAsignaInformacionArgumento("SqlTotalVentas",
    				     pSAgsSiscom,
     				    lLCSiscomPro2RegPrim,
				    lLCSiscomPro2RegAct,
				    lintNRegRegreso);
				     
}

}
void ValidaTotalCompras(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2RegPrim=0;
LCamposSiscomPro2 *lLCSiscomPro2RegAct=0;
int lintNRegRegreso=0;
if(!(SiscomArgumentoOperacionPrim("SqlTotalCompras",pSAgsSiscom)))
{
     SiscomAnexaRegistroPro2(
     		&lLCSiscomPro2RegPrim,
		&lLCSiscomPro2RegAct,
		&lintNRegRegreso,
		"totalcompras,"
		 "0.0");
    SiscomAsignaInformacionArgumento("SqlTotalCompras",
    				     pSAgsSiscom,
     				    lLCSiscomPro2RegPrim,
				    lLCSiscomPro2RegAct,
				    lintNRegRegreso);
				     
}

}

void ValidaTotalTransferenciaBodegaExpendio(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2RegPrim=0;
LCamposSiscomPro2 *lLCSiscomPro2RegAct=0;
int lintNRegRegreso=0;
if(!(SiscomArgumentoOperacionPrim("SqlTotalTransBodExp",pSAgsSiscom)))
{
     SiscomAnexaRegistroPro2(
     		&lLCSiscomPro2RegPrim,
		&lLCSiscomPro2RegAct,
		&lintNRegRegreso,
		"bodegaaexpendio,"
		 "0.0");
    SiscomAsignaInformacionArgumento("SqlTotalTransBodExp",
    				     pSAgsSiscom,
     				    lLCSiscomPro2RegPrim,
				    lLCSiscomPro2RegAct,
				    lintNRegRegreso);
				     
}


}
void ValidaTotalTransferenciaExpendioExpendio(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2RegPrim=0;
LCamposSiscomPro2 *lLCSiscomPro2RegAct=0;
int lintNRegRegreso=0;
if(!(SiscomArgumentoOperacionPrim("SqlTotalTransExpExp",pSAgsSiscom)))
{
     SiscomAnexaRegistroPro2(
     		&lLCSiscomPro2RegPrim,
		&lLCSiscomPro2RegAct,
		&lintNRegRegreso,
		"tottransexpexp,"
		 "0");
    SiscomAsignaInformacionArgumento("SqlTotalTransExpExp",
    				     pSAgsSiscom,
     				    lLCSiscomPro2RegPrim,
				    lLCSiscomPro2RegAct,
				    lintNRegRegreso);
				     
}



}

void ValidaActualizoInventario(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2RegPrim=0;
LCamposSiscomPro2 *lLCSiscomPro2RegAct=0;
int lintNRegRegreso=0;
if(!(SiscomArgumentoOperacionPrim("SqlExistencia",pSAgsSiscom)))
{
     SiscomAnexaRegistroPro2(
     		&lLCSiscomPro2RegPrim,
		&lLCSiscomPro2RegAct,
		&lintNRegRegreso,
		"cveproducto,	\
		 cantidad,	\
		 idresponsable,	\
		 idexpendio,	\
		 fecharegistro,	\
		 hora,	\
		 idinventario",
		 "",
		 "",
		 "",
		 "",
		 "",
		 "",
		 "");
    SiscomAsignaInformacionArgumento("SqlExistencia",
    				     pSAgsSiscom,
     				    lLCSiscomPro2RegPrim,
				    lLCSiscomPro2RegAct,
				    lintNRegRegreso);
				     
}
}
