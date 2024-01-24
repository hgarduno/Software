#include <SqlCambiaEliminaClave.h>


void SqlFormaInsertaCveNueva(SArgsSiscom *pSAgsSiscom)
{

SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlInsertandoCveNueva);

}


void SqlFormaActualizaPrecios(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlActualizandoPrecios);

}
void SqlFormaActualizaTransfiereMaterial(SArgsSiscom *pSAgsSiscom)
{

SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlActualizandoTransfiereMaterial);
}
void SqlFormaActualizaBodegaAExpendio(SArgsSiscom *pSAgsSiscom)
{

SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlActualizandoBodegaAExpendio);
}
void SqlFormaActualizaCompras(SArgsSiscom *pSAgsSiscom)
{

SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlActualizandoCompras);
}
void SqlFormaActualizaDetallePedido(SArgsSiscom *pSAgsSiscom)
{

SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlActualizandoDetallePedido);
}
void SqlFormaActualizaDetallePractica(SArgsSiscom *pSAgsSiscom)
{

SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlActualizandoDetallePractica);
}
void SqlFormaActualizaInventario(SArgsSiscom *pSAgsSiscom)
{

SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlActualizandoInventario);
}

void SqlFormaActualizaInventarioBodega(SArgsSiscom *pSAgsSiscom)
{

SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlActualizandoInventarioBodega);
}
void SqlFormaActualizaMaterialBodega(SArgsSiscom *pSAgsSiscom)
{

SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlActualizandoMaterialBodega);
}
void SqlFormaActualizaTicketImpresoHistorial(SArgsSiscom *pSAgsSiscom)
{

SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlActualizandoTicketImpresoHistorial);
}
void SqlFormaActualizaExistencias(SArgsSiscom *pSAgsSiscom)
{

SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlActualizandoExistencias);
}
void SqlFormaActualizaVentas(SArgsSiscom *pSAgsSiscom)
{

SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlActualizandoVentas);
}
void SqlFormaEliminaProductos(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlEliminandoProductos);
}

void SqlFormaEliminaClaveSat(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlEliminandoClaveSat);
}
void SqlFormaEliminaTransfiereMaterial(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlEliminandoTransfiereMaterial);
}
void SqlFormaEliminaBodegaAExpendio(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlEliminandoBodegaAExpendio);
}
void SqlFormaEliminaDesajusteInventario(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlEliminandoDesajusteInventario);
}


void SqlInsertandoCveNueva(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{
char lchrArrSql[2048];
  sprintf(lchrArrSql,
  	  "insert into Productos values('%s','%s',%s,%s);",
	  SiscomObtenDato(pLCSiscomPro2Dat,"CveNueva"),
	  SiscomObtenDato(pLCSiscomPro2Dat,"dscproducto"),
	  SiscomObtenDato(pLCSiscomPro2Dat,"unidad"),
	  SiscomObtenDato(pLCSiscomPro2Dat,"idfamilia"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SqlActualizandoCveTabla(const char *pchrPtrTabla,
			    LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{
char lchrArrSql[2048];
 sprintf(lchrArrSql,
 	 "update %s set cveproducto ='%s' where cveproducto='%s';",
	 pchrPtrTabla,
	  SiscomObtenDato(pLCSiscomPro2Dat,"CveNueva"),
	  SiscomObtenDato(pLCSiscomPro2Dat,"cveproducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}


void SqlActualizandoPrecios(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{
SqlActualizandoCveTabla("Precios",
			 pLCSiscomPro2Dat,
			 pLCSiscomPro2DatPrim,
			 pLCSiscomPro2DatAct,
			 pintPtrNRegistros);
}
void SqlActualizandoTransfiereMaterial(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

SqlActualizandoCveTabla("TransfiereMaterial",
			 pLCSiscomPro2Dat,
			 pLCSiscomPro2DatPrim,
			 pLCSiscomPro2DatAct,
			 pintPtrNRegistros);
}
void SqlActualizandoBodegaAExpendio(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

SqlActualizandoCveTabla("BodegaAExpendio",
			 pLCSiscomPro2Dat,
			 pLCSiscomPro2DatPrim,
			 pLCSiscomPro2DatAct,
			 pintPtrNRegistros);
}
void SqlActualizandoCompras(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

SqlActualizandoCveTabla("Compras",
			 pLCSiscomPro2Dat,
			 pLCSiscomPro2DatPrim,
			 pLCSiscomPro2DatAct,
			 pintPtrNRegistros);
}
void SqlActualizandoDetallePedido(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

SqlActualizandoCveTabla("DetallePedido",
			 pLCSiscomPro2Dat,
			 pLCSiscomPro2DatPrim,
			 pLCSiscomPro2DatAct,
			 pintPtrNRegistros);
}
void SqlActualizandoDetallePractica(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

SqlActualizandoCveTabla("DetallePractica",
			 pLCSiscomPro2Dat,
			 pLCSiscomPro2DatPrim,
			 pLCSiscomPro2DatAct,
			 pintPtrNRegistros);
}

void SqlActualizandoInventario(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

SqlActualizandoCveTabla("Inventario",
			 pLCSiscomPro2Dat,
			 pLCSiscomPro2DatPrim,
			 pLCSiscomPro2DatAct,
			 pintPtrNRegistros);

}

void SqlActualizandoInventarioBodega(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

SqlActualizandoCveTabla("InventarioBodega",
			 pLCSiscomPro2Dat,
			 pLCSiscomPro2DatPrim,
			 pLCSiscomPro2DatAct,
			 pintPtrNRegistros);

}
void SqlActualizandoMaterialBodega(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

SqlActualizandoCveTabla("MaterialBodega",
			 pLCSiscomPro2Dat,
			 pLCSiscomPro2DatPrim,
			 pLCSiscomPro2DatAct,
			 pintPtrNRegistros);
}
void SqlActualizandoTicketImpresoHistorial(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

SqlActualizandoCveTabla("TicketImpresoHistorial",
			 pLCSiscomPro2Dat,
			 pLCSiscomPro2DatPrim,
			 pLCSiscomPro2DatAct,
			 pintPtrNRegistros);
}
void SqlActualizandoExistencias(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

SqlActualizandoCveTabla("Existencias",
			 pLCSiscomPro2Dat,
			 pLCSiscomPro2DatPrim,
			 pLCSiscomPro2DatAct,
			 pintPtrNRegistros);
}
void SqlActualizandoVentas(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

SqlActualizandoCveTabla("Ventas",
			 pLCSiscomPro2Dat,
			 pLCSiscomPro2DatPrim,
			 pLCSiscomPro2DatAct,
			 pintPtrNRegistros);
}
void SqlEliminandoProductos(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{
char lchrArrSql[2048];
 sprintf(lchrArrSql,
 	"delete from productos where cveproducto='%s';",
	  SiscomObtenDato(pLCSiscomPro2Dat,"cveproducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SqlEliminandoClaveSat(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{
char lchrArrSql[2048];
 sprintf(lchrArrSql,
 	"delete from clavesatsiscom where clave='%s';",
	  SiscomObtenDato(pLCSiscomPro2Dat,"cveproducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SqlEliminandoTransfiereMaterial(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{
char lchrArrSql[2048];
 sprintf(lchrArrSql,
 	"delete from transfierematerial where cveproducto='%s';",
	  SiscomObtenDato(pLCSiscomPro2Dat,"cveproducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
void SqlEliminandoBodegaAExpendio(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{
char lchrArrSql[2048];
 sprintf(lchrArrSql,
 	"delete from bodegaaexpendio where cveproducto='%s';",
	  SiscomObtenDato(pLCSiscomPro2Dat,"cveproducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
void SqlEliminandoDesajusteInventario(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{
char lchrArrSql[2048];
 sprintf(lchrArrSql,
 	"delete from desajusteinventario where cveproducto='%s';",
	  SiscomObtenDato(pLCSiscomPro2Dat,"cveproducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SqlEliminandoProductosTabla(const char *pchrPtrTabla,
			    LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{
char lchrArrSql[2048];
 sprintf(lchrArrSql,
 	 "delete from %s where cveproducto='%s';",
	 pchrPtrTabla,
	  SiscomObtenDato(pLCSiscomPro2Dat,"cveproducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}


void SqlFormaEliminaPrecios(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlEliminandoPrecios);
}
void SqlEliminandoPrecios(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{
  SqlEliminandoProductosTabla("Precios",
  			      pLCSiscomPro2Dat,
			      pLCSiscomPro2DatPrim,
			      pLCSiscomPro2DatAct,
			      pintPtrNRegistros);
}


void SqlFormaEliminaMaterialBodega(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlEliminandoMaterialBodega);
}
void SqlEliminandoMaterialBodega(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{
  SqlEliminandoProductosTabla("MaterialBodega",
  			      pLCSiscomPro2Dat,
			      pLCSiscomPro2DatPrim,
			      pLCSiscomPro2DatAct,
			      pintPtrNRegistros);
}

void SqlFormaEliminaCompras(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlEliminandoCompras);
}
void SqlEliminandoCompras(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{
  SqlEliminandoProductosTabla("Compras",
  			      pLCSiscomPro2Dat,
			      pLCSiscomPro2DatPrim,
			      pLCSiscomPro2DatAct,
			      pintPtrNRegistros);
}



void SqlFormaEliminaInventario(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlEliminandoInventario);
}
void SqlEliminandoInventario(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{
  SqlEliminandoProductosTabla("Inventario",
  			      pLCSiscomPro2Dat,
			      pLCSiscomPro2DatPrim,
			      pLCSiscomPro2DatAct,
			      pintPtrNRegistros);
}


void SqlFormaEliminaTicketImpresoHistorial(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlEliminandoTicketImpresoHistorial);
}
void SqlEliminandoTicketImpresoHistorial(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{
  SqlEliminandoProductosTabla("TicketImpresoHistorial",
  			      pLCSiscomPro2Dat,
			      pLCSiscomPro2DatPrim,
			      pLCSiscomPro2DatAct,
			      pintPtrNRegistros);
}


void SqlFormaEliminaDetallePractica(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlEliminandoDetallePractica);
}
void SqlEliminandoDetallePractica(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{
  SqlEliminandoProductosTabla("DetallePractica",
  			      pLCSiscomPro2Dat,
			      pLCSiscomPro2DatPrim,
			      pLCSiscomPro2DatAct,
			      pintPtrNRegistros);
}


void SqlFormaEliminaInventarioBodega(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlCambiaClave",
				   SqlEliminandoInventarioBodega);
}
void SqlEliminandoInventarioBodega(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{
  SqlEliminandoProductosTabla("InventarioBodega",
  			      pLCSiscomPro2Dat,
			      pLCSiscomPro2DatPrim,
			      pLCSiscomPro2DatAct,
			      pintPtrNRegistros);
}


