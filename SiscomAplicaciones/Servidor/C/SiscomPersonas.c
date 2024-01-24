#include <SiscomPersonas.h>
#include <SiscomPersonasSQL.h>




void SiscomNormalizaPersona(SArgsSiscom *pSAgsSiscom)
{
unsigned char *lchrPtrCambia=SiscomCaracteresCambiados();
LCamposSiscomPro2 *lLCSiscomPro2ContactoN=0;
SiscomNormalizaNombre(lchrPtrCambia,
		      pSAgsSiscom->LCSiscomPro2Dat,
		      &lLCSiscomPro2ContactoN);
SiscomAsignaArgumentoOperacionPrim("SisNormalizado",
				    lLCSiscomPro2ContactoN,
				    pSAgsSiscom); 
}
void SiscomArgumentosPersona(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(4,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SisNormalizado",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SisSQLPersona",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"SisRegistrosEnNormalizados",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(3,"SisRegistrosSimilares",pSAgsSiscom);
}

void SiscomArgumentosPersonaMoral(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SisSQLPersona",pSAgsSiscom);
}
void SiscomValidaNombreVacio(SArgsSiscom *pSAgsSiscom)
{
const char *lchrPtrNombre,
           *lchrPtrAPaterno;

lchrPtrNombre=SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Nombre");
lchrPtrAPaterno=SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"APaterno");

if(!(lchrPtrNombre[0] &&
   lchrPtrAPaterno[0] ))
{
SiscomMensajesLog2("SiscomValidaNombreVacio: Nombre={%s} APaterno={%s}",
		    lchrPtrNombre,
		    lchrPtrAPaterno);
pSAgsSiscom->intCodigoRetorno=1;
}
}
void SiscomPersonaEnNormalizados(SArgsSiscom *pSAgsSiscom)
{
char lchrArrCadena[256];
char *lchrPtrEdoConexion;
char *lchrPtrOperacionRespuesta;
int lintSocket;
int lintNRegRespuesta=0;
LCamposSiscomPro2 *lLCSiscomPro2Base=0;
LCamposSiscomPro2 *lLCSiscomPro2Nor;
lLCSiscomPro2Nor=SiscomArgumentoOperacionPrim("SisNormalizado",
					       pSAgsSiscom);
	sprintf(lchrArrCadena,
		"select * 			\n\
		 from personanormalizada	\n\
		 where nombre='%s' 	and	\n\
		 	apaterno='%s'	and	\n\
			amaterno='%s'",
		  SiscomObtenDato(lLCSiscomPro2Nor,"Nombre"),
		  SiscomObtenDato(lLCSiscomPro2Nor,"APaterno"),
		  SiscomObtenDato(lLCSiscomPro2Nor,"AMaterno"));
	SiscomConsultaBaseDeDatos(
			lchrArrCadena,
			pSAgsSiscom->chrArrDirIpAD,
			pSAgsSiscom->intPtoComAD,
			&lchrPtrEdoConexion,
			&lintSocket,
			&lintNRegRespuesta,
			&lchrPtrOperacionRespuesta,
			&lLCSiscomPro2Base);
	if(lLCSiscomPro2Base)
	{
	SiscomAsignaDatoCampo2(
		"IdPersona",
		SiscomObtenDato(lLCSiscomPro2Base,"idpersona"),
		pSAgsSiscom->LCSiscomPro2Dat);
	 SiscomAsignaArgumentoOperacionPrim("SisRegistrosEnNormalizados",
	 				    lLCSiscomPro2Base,
					    pSAgsSiscom);
	  
	 }
	pSAgsSiscom->intCodigoRetorno=lLCSiscomPro2Base ? 2:0;

}

void SiscomPersonasSimilares(SArgsSiscom *pSAgsSiscom)
{
char lchrArrCadena[256];
char *lchrPtrEdoConexion;
char *lchrPtrOperacionRespuesta;
int lintSocket;
int lintNRegRespuesta;
LCamposSiscomPro2 *lLCSiscomPro2Base=0;
LCamposSiscomPro2 *lLCSiscomPro2Nor;
lLCSiscomPro2Nor=SiscomArgumentoOperacionPrim("SisNormalizado",
					       pSAgsSiscom);
pSAgsSiscom->intCodigoRetorno=0;
	sprintf(lchrArrCadena,
		"select * 					\n\
		 from personanormalizada			\n\
		 where	apaterno 	like '%%%s%%'	or	\n\
			amaterno 	like '%%%s%%'		\n\
		  order by apaterno,amaterno,nombre",
		  SiscomObtenDato(lLCSiscomPro2Nor,"APaterno"),
		  SiscomObtenDato(lLCSiscomPro2Nor,"AMaterno"));
	SiscomConsultaBaseDeDatos(
			lchrArrCadena,
			pSAgsSiscom->chrArrDirIpAD,
			pSAgsSiscom->intPtoComAD,
			&lchrPtrEdoConexion,
			&lintSocket,
			&lintNRegRespuesta,
			&lchrPtrOperacionRespuesta,
			&lLCSiscomPro2Base);
	/*
	 * Martes 30 De Agosto 2011
	 * Con la revision del proceso de normalizacion 
	 * y busqueda de las personas para el registro
	 * se identifico que este codigo no seria util
	 * aqui
	if(lLCSiscomPro2Base)
	{
	pSAgsSiscom->LCSiscomPro2Dat=lLCSiscomPro2Base;
	pSAgsSiscom->intNumRegRegreso=lintNRegRespuesta;
	pSAgsSiscom->intCodigoRetorno=6;
	}
	*/
	SiscomAsignaArgumentoOperacionPrim("SisRegistrosSimilares",
					    lLCSiscomPro2Base,
					    pSAgsSiscom);
}
void SiscomGeneraIdPersona(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Dat;
char lchrArrIdPersona[12];
  SiscomObtenNumeroUnicoChar(lchrArrIdPersona);
  SiscomAsignaDatoCampo2("IdPersona",	
  			 lchrArrIdPersona,
			 lLCSiscomPro2Dat);
}

void SiscomBusquedaPersonas(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Nor=0;
lLCSiscomPro2Nor=SiscomArgumentoOperacionPrim("SisNormalizado",
					       pSAgsSiscom);
SiscomObtenTipoBusquedaPersona(pSAgsSiscom)(pSAgsSiscom);
}

SiscomOperaciones2 SiscomObtenTipoBusquedaPersona(SArgsSiscom *pSAgsSiscom)
{

if(SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Nombre")[0]	&&
   SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"APaterno")[0] 	&&
   SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"AMaterno")[0])
 return SQLSiscomBuscaNombreCompleto;
if(SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Nombre")[0]	&&
   SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"APaterno")[0] )
 return SQLSiscomBuscaTodosNombreAPaterno;

if(SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"APaterno")[0] )
 return SQLSiscomBuscaTodosAPaterno;
}


int ComparaDatoSimilarPosibleRegistro(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				      LCamposSiscomPro2 *pLCSiscomPro2RegN,
				      const char *pchrPtrDato)
{
return !strcmp(SiscomObtenDato(pLCSiscomPro2Dat,pchrPtrDato),
	       SiscomObtenDato(pLCSiscomPro2RegN,pchrPtrDato));
}
int ComparaNombreSimilarPosibleRegistro(LCamposSiscomPro2 *pLCSiscomPro2Dat,
					 LCamposSiscomPro2 *pLCSiscomPro2RegN)
{
return ComparaDatoSimilarPosibleRegistro(pLCSiscomPro2Dat,
					 pLCSiscomPro2RegN,
					 "nombre");
}
int ComparaAPaternoSimilarPosibleRegistro(LCamposSiscomPro2 *pLCSiscomPro2Dat,
					 LCamposSiscomPro2 *pLCSiscomPro2RegN)
{
return ComparaDatoSimilarPosibleRegistro(pLCSiscomPro2Dat,
					 pLCSiscomPro2RegN,
					 "APaterno");
}

int ComparaAMaternoSimilarPosibleRegistro(LCamposSiscomPro2 *pLCSiscomPro2Dat,
					 LCamposSiscomPro2 *pLCSiscomPro2RegN)
{
return ComparaDatoSimilarPosibleRegistro(pLCSiscomPro2Dat,
					 pLCSiscomPro2RegN,
					 "AMaterno");
}

/*
 * Lunes 22 De Agosto 2011 
 * Se debe colocar en la ventana de registro rapido
 * una validacion para no dejar registrar al alumno 
 * si no se han capturado todos  los datos del nombre
 * Nombre, APaterno y AMaterno, ya que la validacion
 * para concluir si la persona ya esta registrada 
 * se complica si esta el APaterno vacio, ya sea
 * para el dato de entrada o alguno con el que se
 * compara en la base de datos que sin AMaterno
 * 
 * Se debera modificar la funcion SiscomPersonaEnNormalizados
 * para que no se genere ahi el error de validacion, esta
 * funcion unicamente consultara los registros que 
 * pueden considerarse similares para la validacion
 * donde debera enviarse el error sera en esta funcion
 *
 *
 */
void SiscomDescartaRegistrosSimilares(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
const char *lchrPtrAMaterno;
int lintEsAMaternoVacio=-1;
LCamposSiscomPro2 *lLCSiscomPro2Normalizados=SiscomArgumentoOperacionPrim("SisNormalizado",pSAgsSiscom);
for(lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim("SisRegistrosSimilares",
						  pSAgsSiscom);
    lLCSiscomPro2Dat;
    lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
{
/*
SiscomLog("Entrada (%s %s %s) %s  ? Base De Datos (%s %s %s) %s",
	SiscomObtenDato(lLCSiscomPro2Normalizados,"nombre"),
	SiscomObtenDato(lLCSiscomPro2Normalizados,"APaterno"),
	SiscomObtenDato(lLCSiscomPro2Normalizados,"AMaterno"),
	SiscomObtenDato(lLCSiscomPro2Normalizados,"IdPersona"),
	SiscomObtenDato(lLCSiscomPro2Dat,"nombre"),
	SiscomObtenDato(lLCSiscomPro2Dat,"APaterno"),
	SiscomObtenDato(lLCSiscomPro2Dat,"AMaterno"),
	SiscomObtenDato(lLCSiscomPro2Dat,"IdPersona"));
*/
   if(ComparaNombreSimilarPosibleRegistro(lLCSiscomPro2Normalizados,
   					  lLCSiscomPro2Dat))
   {
     if(ComparaAPaternoSimilarPosibleRegistro(lLCSiscomPro2Normalizados,
     					      lLCSiscomPro2Dat))
     {
	if(ComparaAMaternoSimilarPosibleRegistro(lLCSiscomPro2Normalizados,
	   					 lLCSiscomPro2Dat))
	{
	   pSAgsSiscom->intCodigoRetorno=2;
	   return ;
	}
     }
   }
}


}

void SiscomNormalizaRazonSocial(SArgsSiscom *pSAgsSiscom)
{
unsigned char *lchrPtrCambia=SiscomCaracteresCambiados();
LCamposSiscomPro2 *lLCSiscomPro2ContactoN=0;
SiscomNormalizaEmpresa(lchrPtrCambia,
		      pSAgsSiscom->LCSiscomPro2Dat,
		      &lLCSiscomPro2ContactoN);
SiscomAsignaArgumentoOperacionPrim("SisEmpresaNormalizada",
				    lLCSiscomPro2ContactoN,
				    pSAgsSiscom); 
}
