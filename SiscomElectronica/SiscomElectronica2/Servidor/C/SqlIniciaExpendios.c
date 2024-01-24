#include <SqlIniciaExpendios.h>
#include <string.h>


void SqlInsertaExpendioPublicoEnGeneral(SArgsSiscom *pSAgsSiscom)
{
 SiscomGeneraInsercionActualizacion(pSAgsSiscom,
 				    "SqlInsertando",
				    SqlGeneraInsertaExpendioPublicoEnGeneral); 
}
void SqlInsertaExpendioEmpresa(SArgsSiscom *pSAgsSiscom)
{
 SiscomGeneraInsercionActualizacion(pSAgsSiscom,
 				    "SqlInsertando",
				    SqlGeneraInsertaExpendioEmpresa); 
}


void SqlInsertaExpendioExpendio(SArgsSiscom *pSAgsSiscom)
{
 SiscomGeneraInsercionActualizacion(pSAgsSiscom,
 				    "SqlInsertando",
				    SqlGeneraInsertaExpendioExpendio); 
}


void SqlInsertaExpendioMatriz(SArgsSiscom *pSAgsSiscom)
{
 SiscomGeneraInsercionActualizacion2A(pSAgsSiscom,
 				    "SqlMatriz",
 				    "SqlInsertando",
				    SqlGeneraInsertaExpendioMatriz); 
}

void SqlInsertaExpendioFirmas(SArgsSiscom *pSAgsSiscom)
{
 SiscomGeneraInsercionActualizacion2A(pSAgsSiscom,
 				    "SqlFirmas",
 				    "SqlInsertando",
				    SqlGeneraInsertaExpendioFirmas); 
}
void SqlInsertaExpendioPersonas(SArgsSiscom *pSAgsSiscom)
{
 SiscomGeneraInsercionActualizacion2A(pSAgsSiscom,
 				    "SqlFirmas",
 				    "SqlInsertando",
				    SqlGeneraInsertaExpendioPersonas); 
}

void SqlInsertaExpendioTiposPersona(SArgsSiscom *pSAgsSiscom)
{
 SiscomGeneraInsercionActualizacion2A(pSAgsSiscom,
 				    "SqlTiposPersona",
 				    "SqlInsertando",
				    SqlGeneraInsertaExpendioTiposPersona); 
}
void SqlInsertaExpendioMatrizEmpresa(SArgsSiscom *pSAgsSiscom)
{
 SiscomGeneraInsercionActualizacion2A(pSAgsSiscom,
 				    "SqlMatriz",
 				    "SqlInsertando",
				    SqlGeneraInsertaExpendioEmpresa); 
}

void SqlInsertaExpendioMatrizExpendio(SArgsSiscom *pSAgsSiscom)
{
 SiscomGeneraInsercionActualizacion2A(pSAgsSiscom,
 				    "SqlMatriz",
 				    "SqlInsertando",
				    SqlGeneraInsertaExpendioExpendio); 
}

void SqlInsertaExpendioTipoPrecio(SArgsSiscom *pSAgsSiscom)
{
 SiscomGeneraInsercionActualizacion2A(pSAgsSiscom,
 				    "SqlTipoPrecio",
 				    "SqlInsertando",
				    SqlGeneraInsertaExpendioTipoPrecio); 
}

void SqlInsertaExpendioPrecios(SArgsSiscom *pSAgsSiscom)
{
 SiscomGeneraInsercionActualizacion2A(pSAgsSiscom,
 				    "SqlPrecios",
 				    "SqlInsertando",
				    SqlGeneraInsertaExpendioPrecios); 
}

void SqlInsertaExpendioControlesCaja(SArgsSiscom *pSAgsSiscom)
{
 SiscomGeneraInsercionActualizacion2A(pSAgsSiscom,
 				    "SqlControlesCaja",
 				    "SqlInsertando",
				    SqlGeneraInsertaExpendioControlesCaja); 
}
void SqlInsertaExpendioEdoControlesCaja(SArgsSiscom *pSAgsSiscom)
{
 SiscomGeneraInsercionActualizacion2A(pSAgsSiscom,
 				    "SqlEdoControlesCaja",
 				    "SqlInsertando",
				    SqlGeneraInsertaExpendioEdoControlesCaja); 
}
void SqlObtenMatriz(SArgsSiscom *pSAgsSiscom)
{

SiscomConsultaBaseAsignaArgumento(
                "SqlMatriz",
		"select b.*,"
		"	c.razonsocial,"
		"	c.rfc "
		"from matriz as a inner join "
		"     expendios as b using(idempresa) inner join "
		"      empresas as c using(idempresa) ",
		pSAgsSiscom);

}


void SqlObtenTipoPrecio(SArgsSiscom *pSAgsSiscom)
{

SiscomConsultaBaseAsignaArgumento(
                "SqlTipoPrecio",
		"select * from tipoprecio",
		pSAgsSiscom);

}

void SqlObtenPrecios(SArgsSiscom *pSAgsSiscom)
{

SiscomConsultaBaseAsignaArgumento(
                "SqlPrecios",
		"select * from precios",
		pSAgsSiscom);

}

void SqlObtenTiposPersonaMatriz(SArgsSiscom *pSAgsSiscom)
{

SiscomConsultaBaseAsignaArgumento(
                "SqlTiposPersona",
		"select * from tipospersona",
		pSAgsSiscom);

}
void SqlObtenControlesCaja(SArgsSiscom *pSAgsSiscom)
{

SiscomConsultaBaseAsignaArgumento(
                "SqlControlesCaja",
		"select * from controlesventa",
		pSAgsSiscom);

}
void SqlObtenEdoControlesCaja(SArgsSiscom *pSAgsSiscom)
{

SiscomConsultaBaseAsignaArgumento(
                "SqlEdoControlesCaja",
		"select * from estadocontrolescaja",
		pSAgsSiscom);

}
void SqlObtenFirmasMatriz(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
		"select idpersona,   		"
		"	firma,       		"
		"	%s as idexpendio,	"
		"	nombre,      		"
		"	apaterno,    		"
		"	amaterno,    		"
		"	rfc,	     		"
		"	tipopersona, 		"
		"	departamento 		"
		"from firmas inner join 	"
		"     personas using(idpersona) ",
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"idempresa"));
SiscomConsultaBaseAsignaArgumento("SqlFirmas",lchrArrSql,pSAgsSiscom);
}

void SqlFamiliasMatriz(SArgsSiscom *pSAgsSiscom)
{
EjecutandoConsultaMatriz("select * from familias",
			 "SqlFamilias",
			 pSAgsSiscom);

}
void SqlProductosMatriz(SArgsSiscom *pSAgsSiscom)
{ 
char lchrArrSql[256];
EjecutandoConsultaMatriz("select * from productos",
		      "SqlProductos",
		      pSAgsSiscom);
}

void SqlUnidadesMatriz(SArgsSiscom *pSAgsSiscom)
{
EjecutandoConsultaMatriz("select * from unidades",
		      "SqlUnidades",
		      pSAgsSiscom);
}
/*
 *
 * Se encapsula para poder manejar el error de conexion con lo matriz
 *
 */
void EjecutandoConsultaMatriz(const char *pchrPtrSql,
			      const char *pchrPtrArgumento,
			      SArgsSiscom *pSAgsSiscom)
{
int lintSocket;
char *lchrPtrEdoConexion=0;
int lintNRegRespuesta;
char *lchrPtrOperacion=0;
char lchrArrDirIp[25];
int lintPuerto;
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
ObtenDatosComunicacionMatriz(pSAgsSiscom,
			     lchrArrDirIp,
			     &lintPuerto);
SiscomConsultaBaseDeDatos(pchrPtrSql,
			  lchrArrDirIp,
			  lintPuerto,
			  &lchrPtrEdoConexion,
			  &lintSocket,
			  &lintNRegRespuesta,
			  &lchrPtrOperacion,
			  &lLCSiscomPro2Reg);
/*
 * Generar el mensaje de error para la interfaz 
 *
 */
if(lchrPtrEdoConexion)
SiscomLog("%s",lchrPtrEdoConexion);
else
{
SiscomLog("Conexion exitosa con la Matriz");
SiscomAsignaArgumentoOperacionPrim(pchrPtrArgumento,lLCSiscomPro2Reg,pSAgsSiscom);
}

}
void ObtenDatosComunicacionMatriz(SArgsSiscom *pSAgsSiscom,
				  char *pchrPtrDirIp,
				  int *pintPtrPuerto)
{

strcpy(pchrPtrDirIp,
       SiscomObtenDato(SiscomArgumentoOperacionPrim("SqlMatriz",pSAgsSiscom),
                       "diripsvrad"));

*pintPtrPuerto=atoi(SiscomObtenDato(SiscomArgumentoOperacionPrim("SqlMatriz",pSAgsSiscom),
				    "ptocomad"));
}
/*
 *
 * Queretaro  Jueves 14 Octubre 2010
 * 
 * En la base de datos se debe almacenar el IdEmpresa de la matriz
 * para poder establecer el filtro en el servidor matriz
 *
 * La otra es eliminar todos los registros y dejar solo los de la matriz,
 * por el momento en el servidor siscom estan los productos de todos los
 * 2 expendios, si hasta antes de esto ...
 *
 */
 
void ObtenIdEmpresaMatriz(SArgsSiscom *pSAgsSiscom,
			  char *pchrPtrIdEmpresa)
{

strcpy(pchrPtrIdEmpresa,
       SiscomObtenDato(SiscomArgumentoOperacionPrim("SqlMatriz",pSAgsSiscom),
                       "idempresa"));

}

void SqlFormaInsertaProductos(SArgsSiscom *pSAgsSiscom)
{
  SiscomGeneraInsercionActualizacion2A(pSAgsSiscom,
  				       "SqlProductos",
				       "SqlInsertando",
				       SqlInsertandoProductos);
}
void SqlFormaInsertaFamilias(SArgsSiscom *pSAgsSiscom)
{

  SiscomGeneraInsercionActualizacion2A(pSAgsSiscom,
  				       "SqlFamilias",
				       "SqlInsertando",
				       SqlInsertandoFamilias);
}
void SqlFormaInsertaUnidades(SArgsSiscom *pSAgsSiscom)
{
  SiscomGeneraInsercionActualizacion2A(pSAgsSiscom,
  				       "SqlUnidades",
				       "SqlInsertando",
				       SqlInsertandoUnidades);
}
void SqlFormaInsertaExistencias(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Prods;
LCamposSiscomPro2 *lLCSiscomPro2InsertandoPrim,
		  *lLCSiscomPro2InsertandoAct;
int lintNRegInsertando;
char lchrArrSql[256];

lLCSiscomPro2Prods=SiscomArgumentoOperacionPrim("SqlProductos",pSAgsSiscom);
lLCSiscomPro2InsertandoPrim=SiscomArgumentoOperacionPrim("SqlInsertando",pSAgsSiscom);
lLCSiscomPro2InsertandoAct=SiscomArgumentoOperacionAct("SqlInsertando",pSAgsSiscom);
lintNRegInsertando=SiscomArgumentosNumeroRegistros("SqlInsertando",pSAgsSiscom);
for(;
    lLCSiscomPro2Prods;
    lLCSiscomPro2Prods=lLCSiscomPro2Prods->SCP2PtrSig)
{
sprintf(lchrArrSql,
	"insert into Existencias values('%s',0,%s,10);",
	SiscomObtenDato(lLCSiscomPro2Prods,"cveproducto"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"idempresa"));
SiscomAnexaRegistroPro2(&lLCSiscomPro2InsertandoPrim,
			&lLCSiscomPro2InsertandoAct,
			&lintNRegInsertando,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
SiscomAsignaInformacionArgumento("SqlInsertando",
				 pSAgsSiscom,
				 lLCSiscomPro2InsertandoPrim,
				 lLCSiscomPro2InsertandoAct,
				 lintNRegInsertando);
}
void SqlInsertandoProductos(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

char lchrArrSql[2048];
for( ;
     pLCSiscomPro2Dat;
     pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
{
  sprintf(lchrArrSql,
  	  "insert into Productos values('%s','%s',%s,%s);",
	  SiscomObtenDato(pLCSiscomPro2Dat,"cveproducto"),
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
}


void SqlInsertandoUnidades(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

char lchrArrSql[256];
for( ;
     pLCSiscomPro2Dat;
     pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
{
  sprintf(lchrArrSql,
  	  "insert into Unidades values(%s,'%s','%s');",
	  SiscomObtenDato(pLCSiscomPro2Dat,"unidad"),
	  SiscomObtenDato(pLCSiscomPro2Dat,"nmbunidad"),
	  SiscomObtenDato(pLCSiscomPro2Dat,"abreviatura"));

SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
}


void SqlInsertandoFamilias(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

char lchrArrSql[256];
for( ;
     pLCSiscomPro2Dat;
     pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
{
  sprintf(lchrArrSql,
  	  "insert into Familias values(%s,'%s','%s');",
	  SiscomObtenDato(pLCSiscomPro2Dat,"idfamilia"),
	  SiscomObtenDato(pLCSiscomPro2Dat,"nmbfamilia"),
	  SiscomObtenDato(pLCSiscomPro2Dat,"dscfamilia"));

SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
}

void SqlGeneraInsertaExpendioEmpresa(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

char lchrArrSql[256];
sprintf(lchrArrSql,
	"insert into Empresas values('%s',%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2Dat,"razonsocial"),
	SiscomObtenDato(pLCSiscomPro2Dat,"idempresa"),
	SiscomObtenDato(pLCSiscomPro2Dat,"rfc"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SqlGeneraInsertaExpendioExpendio(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

char lchrArrSql[256];
sprintf(lchrArrSql,
	"insert into Expendios values(%s,%s,'%s','%s');",
	SiscomObtenDato(pLCSiscomPro2Dat,"idempresa"),
	SiscomObtenDato(pLCSiscomPro2Dat,"ptocomad"),
	SiscomObtenDato(pLCSiscomPro2Dat,"diripsvrad"),
	SiscomObtenDato(pLCSiscomPro2Dat,"rfc"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SqlGeneraInsertaExpendioMatriz(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

char lchrArrSql[256];
sprintf(lchrArrSql,
	"insert into Matriz values(%s);",
	SiscomObtenDato(pLCSiscomPro2Dat,"idempresa"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}


void SqlGeneraInsertaExpendioFirmas(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

char lchrArrSql[256];

for(;
     pLCSiscomPro2Dat;
     pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
{
sprintf(lchrArrSql,
	"insert into Firmas values('%s',%s,%s);",
	SiscomObtenDato(pLCSiscomPro2Dat,"firma"),
	SiscomObtenDato(pLCSiscomPro2Dat,"idpersona"),
	SiscomObtenDato(pLCSiscomPro2Dat,"idexpendio"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
}
void SqlGeneraInsertaExpendioPersonas(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

char lchrArrSql[256];
for(;
     pLCSiscomPro2Dat;
     pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
{
sprintf(lchrArrSql,
	"insert into Personas values('%s','%s','%s','%s',%s,%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2Dat,"nombre"),
	SiscomObtenDato(pLCSiscomPro2Dat,"apaterno"),
	SiscomObtenDato(pLCSiscomPro2Dat,"amaterno"),
	SiscomObtenDato(pLCSiscomPro2Dat,"rfc"),
	SiscomObtenDato(pLCSiscomPro2Dat,"idpersona"),
	SiscomObtenDato(pLCSiscomPro2Dat,"tipopersona"),
	SiscomObtenDato(pLCSiscomPro2Dat,"departamento"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
}

void SqlGeneraInsertaExpendioTiposPersona(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

char lchrArrSql[256];
for(;
     pLCSiscomPro2Dat;
     pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
{
sprintf(lchrArrSql,
	"insert into TiposPersona values(%s,'%s','%s');",
	SiscomObtenDato(pLCSiscomPro2Dat,"tipopersona"),
	SiscomObtenDato(pLCSiscomPro2Dat,"nmbtipopersona"),
	SiscomObtenDato(pLCSiscomPro2Dat,"dsctipopersona"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
}

void SqlGeneraInsertaExpendioTipoPrecio(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

char lchrArrSql[256];
for(;
     pLCSiscomPro2Dat;
     pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
{
sprintf(lchrArrSql,
	"insert into TipoPrecio values('%s','%s','%s');",
	SiscomObtenDato(pLCSiscomPro2Dat,"nmbtipoprecio"),
	SiscomObtenDato(pLCSiscomPro2Dat,"descripcion"),
	SiscomObtenDato(pLCSiscomPro2Dat,"tipo"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
}

void SqlGeneraInsertaExpendioPrecios(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

char lchrArrSql[256];
for(;
     pLCSiscomPro2Dat;
     pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
{
sprintf(lchrArrSql,
	"insert into Precios values('%s',1,0,%s,%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2Dat,"cveproducto"),
	SiscomObtenDato(pLCSiscomPro2Dat,"idprecio"),
	SiscomObtenDato(pLCSiscomPro2Dat,"precio"),
	SiscomObtenDato(pLCSiscomPro2Dat,"nmbtipoprecio"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
}

void SqlGeneraInsertaExpendioControlesCaja(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

char lchrArrSql[256];
for(;
     pLCSiscomPro2Dat;
     pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
{
sprintf(lchrArrSql,
	"insert into ControlesVenta values(%s,'%s','%s');",
	SiscomObtenDato(pLCSiscomPro2Dat,"idcontrol"),
	SiscomObtenDato(pLCSiscomPro2Dat,"nombreqt"),
	SiscomObtenDato(pLCSiscomPro2Dat,"nombre"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
}
void SqlGeneraInsertaExpendioEdoControlesCaja(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

char lchrArrSql[256];
for(;
     pLCSiscomPro2Dat;
     pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
{
sprintf(lchrArrSql,
	"insert into EstadoControlesCaja values(%s,%s,%s);",
	SiscomObtenDato(pLCSiscomPro2Dat,"idcaja"),
	SiscomObtenDato(pLCSiscomPro2Dat,"idcontrol"),
	SiscomObtenDato(pLCSiscomPro2Dat,"estado"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
}

void SqlGeneraInsertaExpendioPublicoEnGeneral(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros)
{

char lchrArrSql[256];
sprintf(lchrArrSql,
	"insert into Personas values('%s','%s','%s','%s',%s,1,'');",
	"Publico En General",
	"GENERAL",
	"",
	"GENERAL",
	"1");
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

