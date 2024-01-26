
#include <Principal.h>
#include <GeneraInserciones.h>
#include <SiscomFuncionesComunes.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomErrores.h>
#include <SiscomArchivosIni.h>

#include <EjecutaSql.h>
#include <InsercionesArchivoSql.h>


#include <string.h>
FILE *gPtrFleArchivoLog;
SiscomError gSiscomErrorSistema;
int gintSocketProtocoloLog;
SiscomDatosIni gSiscomDatIni;
SiscomRegistroProL *gSiscomRegProLPtrMemoria;
PostgresSql gzPostgresSql;

zErroresInsercion gzErroresInsercion[]={
       {"ERROR:  duplicate key value violates unique constraint \"personas_pkey\"",
        ErrorClienteDuplicado
	},
	{"",0}
};
			
int main(int pintArgc,
	 char **pchrPtrArgv)
{
char lchrArrDirServiSNTE[128],
     lchrArrDirTablasSql[128],
     lchrArrDirScriptsSql[128],
     lchrArrBuffer[512];
SiscomRegistroProL *lSiscomRegProLPtrRegreso=0,
		   *lSiscomRegProLPtrActual=0,
		   *lSiscomRegProLPtrSqlPrim=0,
		   *lSiscomRegProLPtrSqlAct=0;
int lintNOperaciones,
    lintContador,
    lintContadorSentencias,
    lintEjecuta;
zOperacionesMigracion lzOpMigracion[20],
		      *lzOpMigracionPaso;;
SiscomAnalizaArchivoIni(*(pchrPtrArgv+2),&gSiscomDatIni);
SiscomVariableIniAChar2("DirServiSNTE",&gSiscomDatIni,lchrArrDirServiSNTE);
SiscomVariableIniAChar2("DirSqlTablas",&gSiscomDatIni,lchrArrDirTablasSql);
SiscomVariableIniAChar2("DirSqlScripts",&gSiscomDatIni,lchrArrDirScriptsSql);
lintEjecuta=SiscomVariableIniAInt("Ejecuta",&gSiscomDatIni);

gPtrFleArchivoLog=stdout;
lzOpMigracionPaso=LlenaProcesoMigracion(lzOpMigracion,
					lchrArrDirServiSNTE,
					lchrArrDirTablasSql,
					lchrArrDirScriptsSql,
					&lintNOperaciones);
AsignaEjecucionOperaciones(lintNOperaciones,lzOpMigracionPaso);
ConectateBaseDatos(pchrPtrArgv);  
for(lintContador=0;
    lintContador<lintNOperaciones;
    lzOpMigracionPaso++,
    lintContador++)
{
  if(lzOpMigracionPaso->chrPtrDatos && lzOpMigracionPaso->ProcesaTablas)
  {
   lzOpMigracionPaso->ProcesaTablas(lzOpMigracionPaso->chrPtrDirServiSNTE,
   				    lzOpMigracionPaso->chrPtrDirSqls,
				    lzOpMigracionPaso->chrPtrVariableArreglo,
					  &lSiscomRegProLPtrSqlPrim,
					  &lSiscomRegProLPtrSqlAct);
   }
   if(lzOpMigracionPaso->chrPtrDatos 	&& 
       lzOpMigracionPaso->chrPtrSql  	&&
      !lzOpMigracionPaso->chrPtrDirTalones	&&
       lzOpMigracionPaso->InsercionesSql)
   {
	EjecutaSql(*(pchrPtrArgv+1),
		   lzOpMigracionPaso->chrPtrSql,
		   &lSiscomRegProLPtrRegreso,
		   &lSiscomRegProLPtrActual);
	/* Sabado 21 de Mayo
	 * Se agrega el IdTienda en el el Inidice 3 de los argumentos 
	 * de entrada, al dia de hoy aqui no se usa,
	 */
	lzOpMigracionPaso->InsercionesSql(IdTienda(pchrPtrArgv),
					  lSiscomRegProLPtrRegreso,
					  &lSiscomRegProLPtrSqlPrim,
					  &lSiscomRegProLPtrSqlAct);
	lSiscomRegProLPtrRegreso=0; 
   }
   if(lzOpMigracionPaso->chrPtrDatos 		&&
      !lzOpMigracionPaso->chrPtrSql		&&
      !lzOpMigracionPaso->chrPtrDirTalones	&&
      lzOpMigracionPaso->InsercionesSql)
   {
	  DatosDesdeArchivo(lzOpMigracionPaso->chrPtrArchivoDatos,
	  		    &lSiscomRegProLPtrRegreso,
			    &lSiscomRegProLPtrActual);
	/* Sabado 21 de Mayo
	 * Se agrega el IdTienda en el el Inidice 3 de los argumentos 
	 * de entrada
	 */
	    lzOpMigracionPaso->InsercionesSql(IdTienda(pchrPtrArgv),
	    				      lSiscomRegProLPtrRegreso,
					      &lSiscomRegProLPtrSqlPrim,
					      &lSiscomRegProLPtrSqlAct);
	lSiscomRegProLPtrRegreso=0; 
   }
   if(lzOpMigracionPaso->chrPtrDatos      &&
      lzOpMigracionPaso->chrPtrDirTalones &&
      lzOpMigracionPaso->InsercionesSql)
   {
	ArchivosDirectorio(lzOpMigracionPaso->chrPtrDirTalones,	
			   &lSiscomRegProLPtrRegreso,
			   &lSiscomRegProLPtrActual);
	lzOpMigracionPaso->InsercionesSql(0,
					  lSiscomRegProLPtrRegreso,
					  &lSiscomRegProLPtrSqlPrim,
					  &lSiscomRegProLPtrSqlAct);
	lSiscomRegProLPtrRegreso=0; 
   }
}
LanzaSentenciasSql(lintEjecuta,lSiscomRegProLPtrSqlPrim);
}
int MuestraEstadoEjecuciones(int pintContador,
			      int pintCadaCuanto)
{
int lintResto;

   lintResto=pintContador%pintCadaCuanto;
   if(!lintResto)
   LogSiscom("%d Instrucciones Ejecutadas",pintContador);
}
void LanzaSentenciasSql(int pintSoloMuestra,
			SiscomRegistroProL *pSiscomRegProLPtrSqlPrim)
{
const char *lchrPtrSentenciaSql,*lchrPtrRegreso;
int lintContador=0,lintContadorSentencias;
SiscomRegistroProL *lSiscomRegProLPtrSqlActual;
PGresult *lPGResult;
LogSiscom("Se ejecutaran %d Nodos",
	 pSiscomRegProLPtrSqlPrim->intNRegistros);
lintContadorSentencias=SiscomVariableIniAInt("ContadorSentencias",&gSiscomDatIni);
for(lSiscomRegProLPtrSqlActual=pSiscomRegProLPtrSqlPrim,
    lintContador=0;
    lSiscomRegProLPtrSqlActual;
    lSiscomRegProLPtrSqlActual=SiscomSiguienteNodoRegistroProL(lSiscomRegProLPtrSqlActual),
    lintContador++)
{
MuestraEstadoEjecuciones(lintContador,lintContadorSentencias);
if((lchrPtrSentenciaSql=SiscomObtenCampoRegistroProLChar("SentenciaSql",lSiscomRegProLPtrSqlActual)))
{
 if(!SiscomObtenCampoRegistroProLChar("EstadoRegistro",lSiscomRegProLPtrSqlActual))
 {
 if(pintSoloMuestra)
 {
 if((lchrPtrRegreso=PostgresEjecutaComando(gzPostgresSql.PGConPtrConexion,
 			lchrPtrSentenciaSql,
			0,
			&lPGResult)))
 AnalizaErrorInsercion(lchrPtrRegreso,pSiscomRegProLPtrSqlPrim,lSiscomRegProLPtrSqlActual);
 }
 else
	printf("%s\n",lchrPtrSentenciaSql);  
 
 }

}

}

}
zOperacionesMigracion *LlenaProcesoMigracion(zOperacionesMigracion *pzOpMigracion,
					     const char *pchrPtrDirServiSNTE,
					     const char *pchrPtrDirTablasSql,
					     const char *pchrPtrDirScriptsSql,
					     int *pintPtrNOperaciones)
{
/* Martes 21 abril del 2015 
 * Las entradas a esta estructura son posicionales 
 * con respecto a la variable Operaciones
 */
 zOperacionesMigracion lzOperacionesMigracion[]={
{
	0,
	0,
	"Tablas",
	pchrPtrDirServiSNTE,
	pchrPtrDirTablasSql,
	0,
	0,
	ProcesaArchivos,
	0
},
{
	0,
	0,
	"Scripts00",
	pchrPtrDirServiSNTE,
	pchrPtrDirScriptsSql,
	0,
	0,
	ProcesaArchivos,
	0
},

{  0,
   "select * from  TGCDep ",
   0,
   0,
   0,
   0,
   0,
   0,
   InsertandoDepartamentos,
},
{  0,
   "select * from tectdc",
   0,
   0,
   0,
   0,
   0,
   0,
   InsertandoTiposDocumentos,
},

{  0,
   "select * from teccon",
   0,
   0,
   0,
   0,
   0,
   0,
   InsertandoConceptosExistencias,
},

{  0,
   "select * "
   "from tbmprv",
   0,
   0,
   0,
   0,
   0,
   0,
   InsertandoEmpresas,
},

{  0,
   "select * from TbrPrdDep",
   0,
   0,
   0,
   0,
   0,
   0,
   AsignandoProductosDepartamentos,
},

{  0,
   "select prv_cve,"
   "	   prd_cve,"
   "	   prd_modelo,"
   "	   prd_nombre,"
   "	   prd_sts,"
   "	   prd_costob,"
   "	   prd_coston,"
   "	   prd_preciof,"
   "	   prd_preciom "
   "from TBMPrd",
   0,
   0,
   0,
   0,
   0,
   0,
   InsertandoProductos,
},

{  0,
   "select tda_cve,tda_nombre,tda_nomabr,tda_siglas from TGCTda ",
   0,
   0,
   0,
   0,
   0,
   0,
   InsertandoTiendas,
},

{  0,
   "select * from  TGCVen ",
   0,
   0,
   0,
   0,
   0,
   0,
   InsertandoVendedores,
},



{
	0,
	0,
	"Scripts",
	pchrPtrDirServiSNTE,
	pchrPtrDirScriptsSql,
	0,
	0,
	ProcesaArchivos,
	0
},
{
	0,
	0,
	0,
	0,
	0,
	"Scripts/ExistenciasTiendas.csv",
	0,
	0,
	ActualizandoExistenciasTienda
},
{
	0,
	0,
	0,
	0,
	0,
	"Scripts/VentasCreditoMaestros2016.csv",
	0,
	0,
 	InsertandoCreditosMaestros
},

{
	0,
	0,
	0,
	0,
	0,
	0,
	"Talones/q21",
	0,
 	InsertandoRFCsCreditos
}
};


memcpy(pzOpMigracion,lzOperacionesMigracion,sizeof(lzOperacionesMigracion));
*pintPtrNOperaciones=sizeof(lzOperacionesMigracion)/sizeof(zOperacionesMigracion);
return pzOpMigracion;
}

void AsignaEjecucionOperaciones(int pintNOperaciones,
			        zOperacionesMigracion *pzOpMigracion)
{
char **lchrPtrOperaciones;
int lintContador;
SiscomObtenVariableArregloACharChar(&gSiscomDatIni,
				    "Operaciones",
				    &lchrPtrOperaciones);
for(lintContador=0;
    lintContador<pintNOperaciones;
    lintContador++,
    pzOpMigracion++,
    lchrPtrOperaciones++)
{
   if(!strcmp(*lchrPtrOperaciones,"No"))
    pzOpMigracion->chrPtrDatos=0;
    else
     pzOpMigracion->chrPtrDatos=*lchrPtrOperaciones;
}

}

void ConectateBaseDatos(char **pchrPtrArgv)
{
char lchrArrBaseDatos[128];
const char *lchrPtrRegreso;
if(*(pchrPtrArgv+3))
sprintf(lchrArrBaseDatos,"ServiSNTE.%s",*(pchrPtrArgv+3));
else
sprintf(lchrArrBaseDatos,"ServiSNTE");
  memset(&gzPostgresSql,0,sizeof(PostgresSql));
  lchrPtrRegreso=SiscomConectateBD(&gzPostgresSql,"5432",lchrArrBaseDatos);
}
void ObtenNombreApellidoPaternoDescripcionError(const char *pchrPtrDescripcionError,
						char *pchrPtrNombre,
						char *pchrPtrAPaterno)
{
const char *lchrPtrRegreso=strstr(pchrPtrDescripcionError,")=("),
	   *lchrPtrPaso;
int lintRegreso;
lchrPtrRegreso+=3;
while(*lchrPtrRegreso!=',')
{
   *pchrPtrNombre=*lchrPtrRegreso;
   pchrPtrNombre++;
   lchrPtrRegreso++;
}
pchrPtrNombre=0;
lchrPtrRegreso+=2;
lchrPtrPaso=strstr(lchrPtrRegreso,")");
lintRegreso=lchrPtrPaso-lchrPtrRegreso;
strncpy(pchrPtrAPaterno,lchrPtrRegreso,lintRegreso);
*(pchrPtrAPaterno+lintRegreso)=0;
}
void ObtenIdPersonaCliente(const char *pchrPtrSentenciaSql,
			   char *pchrPtrIdPersona)
{
const char *lchrPtrCadenaInsert="insert into Personas values(",
	   *lchrPtrBuscando;

int lintTamanoInsert;

lintTamanoInsert=strlen(lchrPtrCadenaInsert);


if((lchrPtrBuscando=strstr(pchrPtrSentenciaSql,lchrPtrCadenaInsert)))
{
   strncpy(pchrPtrIdPersona,lchrPtrBuscando+lintTamanoInsert,10);
   *(pchrPtrIdPersona+10)=0;
}

}
void BuscaRegistroAnteriorCliente(const char *pchrPtrNombre,
				  const char *pchrPtrAPaterno,
				  SiscomRegistroProL *pSiscomRegProLPtrSentenciasPrim,
				  char *pchrPtrIdPrimerRegistro)
{
const char *lchrPtrSentencia;
char lchrArrBuscandoEnSql[256];
sprintf(lchrArrBuscandoEnSql,
	",'%s','%s',",
	pchrPtrNombre,
	pchrPtrAPaterno);
    for(;
        pSiscomRegProLPtrSentenciasPrim;
        pSiscomRegProLPtrSentenciasPrim=pSiscomRegProLPtrSentenciasPrim->SiscomRegProLPtrSig)
    {
        if((lchrPtrSentencia=SiscomObtenCampoRegistroProLChar("SentenciaSql",pSiscomRegProLPtrSentenciasPrim)))
	{
	   if(strstr(lchrPtrSentencia,lchrArrBuscandoEnSql))
	   {
	   if(!ModoSilencioActivado())
	   LogSiscom("%s",lchrPtrSentencia);
	   ObtenIdPersonaCliente(lchrPtrSentencia,pchrPtrIdPrimerRegistro);
	   break;
	   }
	}

    }

}
void AsignaIdClienteNuevoCredito(const char *pchrPtrIdPersonaPrimerRegistro,
				 SiscomRegistroProL *pSiscomRegProLPtrSentencia)
{
char *lchrPtrSentenciaSql=(char *)SiscomObtenCampoRegistroProLChar("SentenciaSql",pSiscomRegProLPtrSentencia);

while(*lchrPtrSentenciaSql!=',')
lchrPtrSentenciaSql++;
lchrPtrSentenciaSql++;
while(*pchrPtrIdPersonaPrimerRegistro)
{
   *lchrPtrSentenciaSql=*pchrPtrIdPersonaPrimerRegistro;
   lchrPtrSentenciaSql++;
   pchrPtrIdPersonaPrimerRegistro++;
}
}
void DatosNuevoCredito(const char *pchrPtrIdPersonaPrimerRegistro,
		       SiscomRegistroProL * pSiscomRegProLPtrSentencias)
{
int lintContador;
if(!ModoSilencioActivado())
LogSiscom("Primer Registro Cliente:%s",pchrPtrIdPersonaPrimerRegistro);
for(lintContador=0; 
    lintContador<4;
    lintContador++,
    pSiscomRegProLPtrSentencias=SiscomSiguienteNodoRegistroProL(pSiscomRegProLPtrSentencias))
{
if(!ModoSilencioActivado())
LogSiscom("%s",SiscomObtenCampoRegistroProLChar("SentenciaSql",pSiscomRegProLPtrSentencias));
SiscomActualizaCampoAsignaMemoria2("EstadoRegistro","0",pSiscomRegProLPtrSentencias);
}
if(!ModoSilencioActivado())
LogSiscom("Ahora los datos del nuevo Credito");
for(lintContador=0; 
    lintContador<3;
    lintContador++,
    pSiscomRegProLPtrSentencias=SiscomSiguienteNodoRegistroProL(pSiscomRegProLPtrSentencias))
{
if(!lintContador)
AsignaIdClienteNuevoCredito(pchrPtrIdPersonaPrimerRegistro,pSiscomRegProLPtrSentencias);
if(!ModoSilencioActivado())
LogSiscom("%s",SiscomObtenCampoRegistroProLChar("SentenciaSql",pSiscomRegProLPtrSentencias));
}
}
void ErrorClienteDuplicado(const char *pchrPtrError,
		           const char *pchrPtrDescripcionError,
			   SiscomRegistroProL *pSiscomRegProLPtrSentenciasPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrSentenciasAct)
{
char lchrArrNombre[25],
     lchrArrAPaterno[25],
     lchrArrIdPersona[11];
memset(lchrArrNombre,0,25);
memset(lchrArrAPaterno,0,25);
ObtenNombreApellidoPaternoDescripcionError(pchrPtrDescripcionError,lchrArrNombre,lchrArrAPaterno);
if(!ModoSilencioActivado())
LogSiscom("*%s*  *%s*",lchrArrNombre,lchrArrAPaterno);
BuscaRegistroAnteriorCliente(lchrArrNombre,
			     lchrArrAPaterno,
			     pSiscomRegProLPtrSentenciasPrim,
			     lchrArrIdPersona);
DatosNuevoCredito(lchrArrIdPersona,pSiscomRegProLPtrSentenciasAct);
}
void ObtenErrorDetalleError(const char *pchrPtrError,
			    char *pchrPtrDescripcionError,
			    char *pchrPtrDetalleError)
{
    while(*pchrPtrError!='\n')
    {
         *pchrPtrDescripcionError=*pchrPtrError;
	 pchrPtrDescripcionError++;
	 pchrPtrError++;
    }
    pchrPtrError++;
    *pchrPtrDescripcionError=0; 
    strcpy(pchrPtrDetalleError,pchrPtrError);
    *(pchrPtrDetalleError+strlen(pchrPtrDetalleError)-1)=0;
}
void AnalizaErrorInsercion(const char *pchrPtrError,
			   SiscomRegistroProL *pSiscomRegProLPtrSentenciaPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrSentenciaActual)
{
char lchrArrError[256],
     lchrArrDetalleError[256];
zErroresInsercion *lzErroresInsercion=gzErroresInsercion;
ObtenErrorDetalleError(pchrPtrError,lchrArrError,lchrArrDetalleError);
if(!ModoSilencioActivado())
{
LogSiscom("%s",lchrArrError);
LogSiscom("%s",lchrArrDetalleError);
}
while(lzErroresInsercion->ErrorInsercion)
{ 
   if(!strcmp(lzErroresInsercion->chrArrError,lchrArrError))
   {
	gzErroresInsercion->ErrorInsercion(lchrArrError,
					   lchrArrDetalleError,
					   pSiscomRegProLPtrSentenciaPrim,
					   pSiscomRegProLPtrSentenciaActual);
	break;
   }
  lzErroresInsercion++; 
}
}

int ModoSilencioActivado()
{
  return SiscomVariableIniAInt("EjecucionSilencio",&gSiscomDatIni);
}
const char *IdTienda(char **pchrPtrArgv)
{
  if(*(pchrPtrArgv+3))
  return *(pchrPtrArgv+3);
  else
  return "5";
}
