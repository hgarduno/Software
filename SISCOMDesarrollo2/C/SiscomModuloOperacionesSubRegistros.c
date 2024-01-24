#include <SiscomModuloOperacionesSubRegistros.h>
/*
 * Domingo 21 De Agosto 2011 
 * Con la integracion del manejo de los subregistros 
 * se anexaran las funciones para generar las sentencias
 * sql apartir de esta nueva forma de almacenar la
 * informacion que se envia al servidor
 *
 */
/*
 * Jueves 22 De Septiembre 2011 
 * Funcion que recorre cada uno de los nodos en el formato
 * de SubRegistros, e invoca SiscomOperacionesSql, al final
 * asigna a pchrPtrArgSal el resultado
 *
 */

/* 
 * Domingo 14 de Octubre del 2012
 * Con la integracion del manejo de los subregistros, se debera 
 * desarrollar en el modulo de acceso a datos la funcionalidad 
 * para enviar Via los subregistros un bloque de sentencias sql
 * que por ejemplo podria representar algo como:
 *
 * En los campos del registro principal, la sentencia para los 
 * datos generale nombre, apellidos etc, insert into nombre ...
 * en el primer subregistro podrian ir las direcciones de la 
 * persona 
 *
 * insert into direccion (1
 * insert into direccion (2
 *
 * En el Sub registro 2 los telefonos 
 *
 * En el Sub Registro 3 otras cosas 
 *
 * Como podemos observar es muy importante poder hacer las 
 * funciones de insercion con subregistros
 *
 */


/* Lunes 21 de enero del 2013
 * Funcion que recorre todos los nodos de pSAgsSiscom->LCSiscomPro2SREntrada
 * tomando los subregistros de pintNSubRegistro, recorriendo toda esta lista
 * ejecutando SiscomSql el Resultado se almacena agrega al aumento
 * pchrPtrArgSalida
 *
 */
void SiscomInsercionActualizacionSubRegistros(int pintNSubRegistro,
					      SArgsSiscom *pSAgsSiscom,
					      const char *pchrPtrArgSalida,
					      char *pchrPtrBufferSql,
					      void (*SiscomSql)(LCamposSiscomPro2 *,
					      		        SArgsSiscom *,
								char *))
{
LCamposSiscomPro2 *lLCSiscomPro2;
LCamposSiscomPro2 *lLCSiscomPro2SqlPrim,
		  *lLCSiscomPro2SqlAct;
int lintNRegSql;
LCamposSiscomPro2ConSubReg *lLCSiscomPro2SRDat=0;
SiscomObtenInformacionArgumento(pchrPtrArgSalida,
				pSAgsSiscom,
				&lLCSiscomPro2SqlPrim,
				&lLCSiscomPro2SqlAct,
				&lintNRegSql);

for(lLCSiscomPro2SRDat=pSAgsSiscom->LCSiscomPro2SREntrada;
    lLCSiscomPro2SRDat;
    lLCSiscomPro2SRDat=lLCSiscomPro2SRDat->LCSiscomPro2SRSig)
for(lLCSiscomPro2=SiscomSubRegistroPrim(pintNSubRegistro,lLCSiscomPro2SRDat);
    lLCSiscomPro2;
    lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
{
SiscomSql(lLCSiscomPro2,pSAgsSiscom,pchrPtrBufferSql);
SiscomAnexaRegistroPro2(&lLCSiscomPro2SqlPrim,
			&lLCSiscomPro2SqlAct,
			&lintNRegSql,
			"ComandoSQL,EdoRegistro",
			pchrPtrBufferSql,
			"");
}
SiscomAsignaInformacionArgumento(pchrPtrArgSalida,
				pSAgsSiscom,
				lLCSiscomPro2SqlPrim,
				lLCSiscomPro2SqlAct,
				lintNRegSql);
}

void SiscomInsercionActualizacionRegistroPrincipal(
		SArgsSiscom *pSAgsSiscom,
		const char *pchrPtrArgSalida,
		char *pchrPtrBufferSql,
		void (*SiscomSql)(LCamposSiscomPro2ConSubReg *,
				 SArgsSiscom *,
				char *))
{
LCamposSiscomPro2 *lLCSiscomPro2;
LCamposSiscomPro2 *lLCSiscomPro2SqlPrim,
		  *lLCSiscomPro2SqlAct;
int lintNRegSql;
LCamposSiscomPro2ConSubReg *lLCSiscomPro2SRDat=0;
SiscomObtenInformacionArgumento(pchrPtrArgSalida,
				pSAgsSiscom,
				&lLCSiscomPro2SqlPrim,
				&lLCSiscomPro2SqlAct,
				&lintNRegSql);

for(lLCSiscomPro2SRDat=pSAgsSiscom->LCSiscomPro2SREntrada;
    lLCSiscomPro2SRDat;
    lLCSiscomPro2SRDat=lLCSiscomPro2SRDat->LCSiscomPro2SRSig)
{
SiscomSql(lLCSiscomPro2SRDat,pSAgsSiscom,pchrPtrBufferSql);
SiscomAnexaRegistroPro2(&lLCSiscomPro2SqlPrim,
			&lLCSiscomPro2SqlAct,
			&lintNRegSql,
			"ComandoSQL,EdoRegistro",
			pchrPtrBufferSql,
			"");
}
SiscomAsignaInformacionArgumento(pchrPtrArgSalida,
				pSAgsSiscom,
				lLCSiscomPro2SqlPrim,
				lLCSiscomPro2SqlAct,
				lintNRegSql);
}

void SiscomInsercionActualizacionEntradaSubRegistroAArgumento2(
		SArgsSiscom *pSAgsSiscom,
		const char *pchrPtrArgSalida,
		char *pchrPtrBufferSql,
		int pintNSubRegistro,
		void (*SiscomSql)(LCamposSiscomPro2 *,
				  char *pchrPtrSql))
{
const LCamposSiscomPro2ConSubReg *lLCSiscomPro2SRDat;
LCamposSiscomPro2 *lLCSiscomPro2SqlPrim;
LCamposSiscomPro2 *lLCSiscomPro2SqlAct;
LCamposSiscomPro2 *lLCSiscomPro2Reg;
int lintNRegSql;
SiscomObtenInformacionArgumento(pchrPtrArgSalida,
				pSAgsSiscom,
				&lLCSiscomPro2SqlPrim,
				&lLCSiscomPro2SqlAct,
				&lintNRegSql);
for(lLCSiscomPro2SRDat=pSAgsSiscom->LCSiscomPro2SREntrada;
    lLCSiscomPro2SRDat;
    lLCSiscomPro2SRDat=lLCSiscomPro2SRDat->LCSiscomPro2SRSig)
{
for(lLCSiscomPro2Reg=SiscomSubRegistroPrim(pintNSubRegistro,lLCSiscomPro2SRDat);
    lLCSiscomPro2Reg;
    lLCSiscomPro2Reg=lLCSiscomPro2Reg->SCP2PtrSig)
{
SiscomSql(lLCSiscomPro2Reg,pchrPtrBufferSql);
SiscomAnexaRegistroPro2(
	  &lLCSiscomPro2SqlPrim,
	  &lLCSiscomPro2SqlAct,
	  &lintNRegSql,
	  "ComandoSQL,EdoRegistro",
	  pchrPtrBufferSql,
	  "");

}
SiscomAsignaInformacionArgumento(pchrPtrArgSalida,
                              pSAgsSiscom,
                              lLCSiscomPro2SqlPrim,
                              lLCSiscomPro2SqlAct,
                              lintNRegSql);


}


}
void SiscomInsercionActualizacionEntradaSubRegistroAArgumento(
		SArgsSiscom *pSAgsSiscom,
		const char *pchrPtrArgSal,
		void (*SiscomOperacionSql)(
				const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
				SArgsSiscom *,
				LCamposSiscomPro2 **,
				LCamposSiscomPro2 **,
				int *))
{
const LCamposSiscomPro2ConSubReg *lLCSiscomPro2SRDat;
LCamposSiscomPro2 *lLCSiscomPro2SqlPrim;
LCamposSiscomPro2 *lLCSiscomPro2SqlAct;
int lintNRegSql;
SiscomObtenInformacionArgumento(pchrPtrArgSal,
				pSAgsSiscom,
				&lLCSiscomPro2SqlPrim,
				&lLCSiscomPro2SqlAct,
				&lintNRegSql);
for(lLCSiscomPro2SRDat=pSAgsSiscom->LCSiscomPro2SREntrada;
    lLCSiscomPro2SRDat;
    lLCSiscomPro2SRDat=lLCSiscomPro2SRDat->LCSiscomPro2SRSig)
SiscomOperacionSql(lLCSiscomPro2SRDat,
		   pSAgsSiscom,
		   &lLCSiscomPro2SqlPrim,
		   &lLCSiscomPro2SqlAct,
		   &lintNRegSql);
SiscomAsignaInformacionArgumento(pchrPtrArgSal,
				 pSAgsSiscom,
				 lLCSiscomPro2SqlPrim,
				 lLCSiscomPro2SqlAct,
				 lintNRegSql);
}


void SiscomInsercionActualizacionSql2(SArgsSiscom *pSAgsSiscom,	
				     int pintNSubRegistro,
				     void (*SiscomSql)(SArgsSiscom *,LCamposSiscomPro2 *))
{
const LCamposSiscomPro2ConSubReg *lLCSiscomPro2SRDat;
for(lLCSiscomPro2SRDat=pSAgsSiscom->LCSiscomPro2SREntrada;
    lLCSiscomPro2SRDat;
    lLCSiscomPro2SRDat=lLCSiscomPro2SRDat->LCSiscomPro2SRSig)
SiscomOperacionGeneralSql2(pintNSubRegistro,
			   SiscomSql,
			   pSAgsSiscom);
}
void SiscomInsercionActualizacionSql(SArgsSiscom *pSAgsSiscom,
				     const char *pchrPtrArgSal,
				     int pintNSubRegistro,
				     void (*SiscomSql)(LCamposSiscomPro2 *,
				     		       LCamposSiscomPro2 **,
						       LCamposSiscomPro2 **,
						       int *))
{
const LCamposSiscomPro2ConSubReg *lLCSiscomPro2SRDat;
LCamposSiscomPro2 *lLCSiscomPro2SqlPrim;
LCamposSiscomPro2 *lLCSiscomPro2SqlAct;
int lintNRegSql;
SiscomObtenInformacionArgumento(pchrPtrArgSal,
				pSAgsSiscom,
				&lLCSiscomPro2SqlPrim,
				&lLCSiscomPro2SqlAct,
				&lintNRegSql);
for(lLCSiscomPro2SRDat=pSAgsSiscom->LCSiscomPro2SREntrada;
    lLCSiscomPro2SRDat;
    lLCSiscomPro2SRDat=lLCSiscomPro2SRDat->LCSiscomPro2SRSig)
SiscomOperacionGeneralSql(SiscomSubRegistroPrim(pintNSubRegistro,lLCSiscomPro2SRDat),
			  SiscomSql,
			  &lLCSiscomPro2SqlPrim,
			  &lLCSiscomPro2SqlAct,
			  &lintNRegSql);
SiscomAsignaInformacionArgumento(pchrPtrArgSal,
				 pSAgsSiscom,
				 lLCSiscomPro2SqlPrim,
				 lLCSiscomPro2SqlAct,
				 lintNRegSql);
}
/* Domingo 21 De Agosto 2011 
 * Toma el SubRegistro pintNSubRegistro y lo recorre
 * invocando a SiscomSql(SArgsSiscom *) durante el 
 * recorrido de la lista 
 */
void SiscomOperacionGeneralSql2(int pintNSubRegistro,
				void (*SiscomOperacionSql)(SArgsSiscom *,
							   LCamposSiscomPro2 *),
				SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
lLCSiscomPro2Dat=SiscomSubRegistroPrim(pintNSubRegistro,
				       pSAgsSiscom->LCSiscomPro2SREntrada);
for(;
     lLCSiscomPro2Dat;
     lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
SiscomOperacionSql(pSAgsSiscom,lLCSiscomPro2Dat);

}
void SiscomOperacionGeneralSql(LCamposSiscomPro2 *pLCSiscomPro2Dat,
					 void (*SiscomOperacion)(LCamposSiscomPro2 *,
					 			 LCamposSiscomPro2 **,
								 LCamposSiscomPro2 **,
								 int *),
					 LCamposSiscomPro2 **pLCSiscomPro2Prim,
					 LCamposSiscomPro2 **pLCSiscomPro2Act,
					 int *pintPtrNRegistros)
{

for(;
    pLCSiscomPro2Dat;
    pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
SiscomOperacion(pLCSiscomPro2Dat,
		pLCSiscomPro2Prim,
		pLCSiscomPro2Act,
		pintPtrNRegistros);
}


/*Domingo 21 de Agosto 2011 
 * Faltara integrar las funciones, para regresar int, float etc
 *
 *
 */
const char *SiscomCampoSubRegistroArgs(int pintNSubRegistro,
				       const char *pchrPtrCampo,
				       SArgsSiscom *pSAgsSiscom)
{
return SiscomCampoSubRegistro(pintNSubRegistro,
			      pchrPtrCampo,
			      pSAgsSiscom->LCSiscomPro2SREntrada);
}


void SiscomAsignaCampoRegistroPrincipalArgs(SArgsSiscom *pSAgsSiscom,
					    const char *pchrPtrCampo,
					    const char *pchrPtrDato)
{
SiscomAsignaCampoRegistroPrincipal(pSAgsSiscom->LCSiscomPro2SREntrada,
				   pchrPtrCampo,
				   pchrPtrDato);
}
/*
 * Domingo 14 de Octubre del 2012
 * Toma del argumento pSAgsSiscom los subregistros LCSiscomPro2SREntrada
 * recorre cada uno de los nodos del registro principal, ejecuta SiscomSql
 * que debera ser una funcion que genere la sentencia insert /update 
 * la cadena de salida pchrPtrBuffer, se asigna al registro actual del
 * argumento pchrPtrArgumentoSal
 *
 * Al terminar de recorrer la informacion por los campos del registro
 * principal se almacenara en el argumento pchrPtrArgumentoSalida 
 * las sentencias insert / update que se deberan enviar al manejador
 * de base de datos
 *
 */
void SiscomInsercionActualizacionRegPrincipal(
		SArgsSiscom *pSAgsSiscom,
		const char *pchrPtrArgumentoSal,
		char *pchrPtrBufferSql,
		void (*SiscomSql)(LCamposSiscomPro2ConSubReg *,char *))
{
LCamposSiscomPro2 *lLCSiscomPro2SQLPrim=0,
		  *lLCSiscomPro2SQLAct;
int lintNRegistros;
LCamposSiscomPro2ConSubReg *lLCSiscomPro2SRDat;

SiscomObtenInformacionArgumento(pchrPtrArgumentoSal,
				pSAgsSiscom,
				&lLCSiscomPro2SQLPrim,
				&lLCSiscomPro2SQLAct,
				&lintNRegistros);
for(lLCSiscomPro2SRDat=pSAgsSiscom->LCSiscomPro2SREntrada;
    lLCSiscomPro2SRDat;
    lLCSiscomPro2SRDat=lLCSiscomPro2SRDat->LCSiscomPro2SRSig)
{
SiscomSql(lLCSiscomPro2SRDat,pchrPtrBufferSql);
SiscomAnexaRegistroPro2(
	  &lLCSiscomPro2SQLPrim,
	  &lLCSiscomPro2SQLAct,
	  &lintNRegistros,
	  "ComandoSQL,EdoRegistro",
	  pchrPtrBufferSql,
	  "");
}
SiscomAsignaInformacionArgumento(pchrPtrArgumentoSal,
                              pSAgsSiscom,
                              lLCSiscomPro2SQLPrim,
                              lLCSiscomPro2SQLAct,
                              lintNRegistros);


}


const char *SiscomCampoSubRegistroPrincipalArgs(const char *pchrPtrCampo,SArgsSiscom *pSAgsSiscom)
{
return SiscomCampoRegistroPrincipal(pSAgsSiscom->LCSiscomPro2SREntrada,pchrPtrCampo);
}
float SiscomCampoSubRegistroPrincipalArgsFloat(const char *pchrPtrCampo,SArgsSiscom *pSAgsSiscom)
{
return SiscomCampoRegistroPrincipalFloat(pSAgsSiscom->LCSiscomPro2SREntrada,pchrPtrCampo);
}
int SiscomCampoSubRegistroPrincipalArgsInt(const char *pchrPtrCampo,SArgsSiscom *pSAgsSiscom)
{
return SiscomCampoRegistroPrincipalInt(pSAgsSiscom->LCSiscomPro2SREntrada,pchrPtrCampo);
}


void SiscomAsignaCampoSubRegistroArgs(int pintSubRegistro,
				  const char *pchrPtrCampo,
				  const char *pchrPtrDato,
				  SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaCampoSubRegistro(pSAgsSiscom->LCSiscomPro2SREntrada,
			     pintSubRegistro,
			     pchrPtrCampo,
			     pchrPtrDato);
}
