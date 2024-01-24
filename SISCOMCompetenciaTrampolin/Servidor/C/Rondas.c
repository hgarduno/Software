#include <Rondas.h>
#include <RegistraRondas.h>
#include <ResultadosCompetencia.h>
#include <stdlib.h>
#include <string.h>
#include <ServidorGeneral.h>
void InsertaRondas(SArgsSiscom *pSAgsSiscom)
{
char *lchrPtrEdoConexion;
int lintSocket;
SiscomLog("Insertando....(%d) Registros",
	  SiscomArgumentosNumeroRegistros("Rondas",pSAgsSiscom));

SiscomImprimeContenidoProtocolo("",
				gPtrFleArchivoLog,
				SiscomArgumentoOperacionPrim("Rondas",pSAgsSiscom));
SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
			  gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
			  "Inserciones",
			  SiscomArgumentosNumeroRegistros("Rondas",pSAgsSiscom),
			  SiscomArgumentoOperacionPrim("Rondas",pSAgsSiscom),
			  &lchrPtrEdoConexion,
			  &lintSocket);
}
void EnviaRondasCliente(SArgsSiscom *pSAgsSiscom)
{

SiscomMensajesLog2("Las Rondas generadas");
SiscomImprimeContenidoProtocolo2("",SiscomArgumentoOperacionPrim("ResRondas",pSAgsSiscom));

SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
		      SiscomArgumentosNumeroRegistros("ResRondas",pSAgsSiscom),
		      "Respuesta",
		      SiscomArgumentoOperacionPrim("ResRondas",pSAgsSiscom));

}
void ArgumentosRonda(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(4,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"Rondas",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"GimAparatos",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"DatRondas",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(3,"ResRondas",pSAgsSiscom);
}

void SQLCalificaRonda(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Regreso=0;
int lintNRegRespuesta;
char lchrArrSQL[2048];
sprintf(lchrArrSQL,"									\
select	a.idCompetencia,								\
	a.idGimnasta,									\
	b.Nombre	as NmbGimnasta,							\
       	b.APaterno	as APatGimnasta,						\
       	''		as AMatGimnasta,						\
       	c.Nombre	as NmbEntrenador,						\
       	c.APaterno	as APatEntrenador,						\
       	''		as AMatEntrenador,						\
       	d.idClase,									\
       	d.Clase,									\
       	e.idNivel,									\
       	e.nivel,									\
       	idgimnasio,									\
       	f.nombre	as gimnasio,							\
	g.idgrupo,									\
       	g.edadinf,									\
       	g.edadsup,									\
       	g.grupo,									\
	''		as rangoedad,							\
	h.ejecucion,									\
	h.dificultad,									\
	h.ejecucion-h.dificultad as notafinal,						\
	'' as idtipocompetencia,							\
	i.idaparato,									\
	i.aparato,									\
	j.idronda,									\
	k.nmbronda									\
from	compitiendo		as a							\
	inner join personas	as b on (idgimnasta=b.idpersona)			\
	inner join personas	as c on (identrenador=c.idpersona)			\
	inner join catclase	as d using(idclase) 					\
	inner join catnivel	as e on (a.idclase=e.idclase and 			\
	                                 a.idnivel=e.idnivel   )			\
	inner join gimnasio 	as f on (idgimnasiopqc=idgimnasio)			\
	inner join grupos	as g using(idgrupo)					\
	inner join calificaciones as h on (a.idgimnasta=h.idgimnasta and		\
	                                   a.idcompetencia=h.idcompetencia)		\
	inner join aparatos	as i using(idAparato)					\
	inner join detalleronda as j on a.idgimnasta=j.idgimnasta and			\
					i.idaparato=j.idaparato				\
	inner join rondas	as k on j.idronda=k.idronda				\
where 	a.idCompetencia=%s								\
order by k.idronda,									\
	d.clase,									\
	 e.nivel,									\
	 g.idgrupo,									\
	 i.idaparato,									\
	 b.APaterno,									\
	 b.AMaterno,									\
	 b.Nombre",
pSAgsSiscom->chrPtrArgConsulta[1]);

SiscomConsultaBaseDatosSinDatosConexion(
        lchrArrSQL,
	gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
	gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	&lLCSiscomPro2Regreso,
	&lintNRegRespuesta);
SiscomAsignaArgumentoOperacionPrim("Rondas",lLCSiscomPro2Regreso,pSAgsSiscom);
}
void GeneraAparatoGimnasta(int pintNAparatos,
			   LCamposSiscomPro2ConSubReg *pLCSiscomPro2CSRDat,
			   LCamposSiscomPro2 **pLCSiscomPro2Prim)
{
int lintContador;
int lintNRegistros=0;
LCamposSiscomPro2 *lLCSiscomPro2C;
LCamposSiscomPro2 *lLCSiscomPro2Act=0;
SCampoSiscomPro2 *lSCSiscomPro2Dat; 
const char *lchrPtrIdRonda,
	   *lchrPtrRonda;
	*pLCSiscomPro2Prim=0;
	for(lintContador=0;
	    lintContador<pintNAparatos;
	    lintContador++)
	{
	lLCSiscomPro2C=pLCSiscomPro2CSRDat->LCSiscomSubReg[lintContador].LCSiscomPro2Prim;
	lSCSiscomPro2Dat=lLCSiscomPro2C->SCSiscomPro2;
	AnexaRegistroInicioAparato(
		SiscomObtenDato(lLCSiscomPro2C,"idaparato"),
		SiscomObtenDato(lLCSiscomPro2C,"aparato"),
		(lchrPtrIdRonda=SiscomObtenDato(lLCSiscomPro2C,"idronda")),
		(lchrPtrRonda=SiscomObtenDato(lLCSiscomPro2C,"nmbronda")),
		lLCSiscomPro2C->SCSiscomPro2,
		pLCSiscomPro2Prim,
		&lLCSiscomPro2Act,
		&lintNRegistros);
	for(;
		lLCSiscomPro2C;
	    lLCSiscomPro2C=lLCSiscomPro2C->SCP2PtrSig)
	{
	   SiscomCreaListaCamposPro2(lLCSiscomPro2C->SCSiscomPro2,
	   			    pLCSiscomPro2Prim,
				    &lLCSiscomPro2Act);
	   lintNRegistros++;

	}
	AnexaRegistroInicioAparato(
		"",
		"",
		lchrPtrIdRonda,
		lchrPtrRonda,
		lSCSiscomPro2Dat,
		pLCSiscomPro2Prim,
		&lLCSiscomPro2Act,
		&lintNRegistros);
	}
}
void FormaEstructuraRondas(LCamposSiscomPro2 *pLCSiscomPro2DatRondas,
			   StcSisFormaRegistro *pSSFormaReg)
{
int lintContador;

	memset(pSSFormaReg,0,sizeof(StcSisFormaRegistro));
	pSSFormaReg->chrPtrCampo=strdup("nmbronda");
	for(lintContador=0;
	    pLCSiscomPro2DatRondas;
	    lintContador++,
	    pLCSiscomPro2DatRondas=pLCSiscomPro2DatRondas->SCP2PtrSig)
	{
	  pSSFormaReg->SSRegistro[lintContador].chrPtrCampo=strdup("nmbronda");
	  pSSFormaReg->SSRegistro[lintContador].chrPtrValor=
	  		SiscomObtenDato(pLCSiscomPro2DatRondas,"nmbronda");
			
	}
}
void RondaGimnastaAparato01(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Rondas;
LCamposSiscomPro2 *lLCSiscomPro2Datos;
LCamposSiscomPro2 *lLCSiscomPro2Aparatos;
LCamposSiscomPro2 *lLCSiscomPro2RondasCont;
LCamposSiscomPro2 *lLCSiscomPro2DatosCont;
LCamposSiscomPro2 *lLCSiscomPro2AparatosCont;
const char *lchrPtrIdRonda,
           *lchrPtrRonda;
const char *lchrPtrIdAparato,
           *lchrPtrAparato;
LCamposSiscomPro2 *lLCSiscomPro2RegPrim=0;
LCamposSiscomPro2 *lLCSiscomPro2RegAct=0;
int lintNRegReg=0;
lLCSiscomPro2Rondas=SiscomArgumentoOperacionPrim("DatRondas",pSAgsSiscom);
lLCSiscomPro2Datos=SiscomArgumentoOperacionPrim("Rondas",pSAgsSiscom);
lLCSiscomPro2Aparatos=SiscomArgumentoOperacionPrim("GimAparatos",pSAgsSiscom);

SiscomImprimeContenidoProtocolo2("Rondas",lLCSiscomPro2Rondas);
SiscomImprimeContenidoProtocolo2("Datos",lLCSiscomPro2Datos);
SiscomImprimeContenidoProtocolo2("Aparatos",lLCSiscomPro2Aparatos);
for(lLCSiscomPro2RondasCont=lLCSiscomPro2Rondas;
    lLCSiscomPro2RondasCont;
    lLCSiscomPro2RondasCont=lLCSiscomPro2RondasCont->SCP2PtrSig)
{
lchrPtrRonda=SiscomObtenDato(lLCSiscomPro2RondasCont,"nmbronda");
lchrPtrIdRonda=SiscomObtenDato(lLCSiscomPro2RondasCont,"idronda");
AnexaRegistroInicioRonda(lchrPtrIdRonda,
			  lchrPtrRonda,
			  lLCSiscomPro2Datos->SCSiscomPro2,
			  &lLCSiscomPro2RegPrim,
			  &lLCSiscomPro2RegAct,
			  &lintNRegReg);
for(lLCSiscomPro2AparatosCont=lLCSiscomPro2Aparatos;
    lLCSiscomPro2AparatosCont;
    lLCSiscomPro2AparatosCont=lLCSiscomPro2AparatosCont->SCP2PtrSig)
{
lchrPtrIdAparato=SiscomObtenDato(lLCSiscomPro2AparatosCont,"idaparato");
lchrPtrAparato=SiscomObtenDato(lLCSiscomPro2AparatosCont,"aparato");
AnexaRegistroInicioAparato(lchrPtrIdAparato,
			   lchrPtrAparato,
			   lchrPtrIdRonda,
			   lchrPtrRonda,
			   lLCSiscomPro2Datos->SCSiscomPro2,
			  &lLCSiscomPro2RegPrim,
			  &lLCSiscomPro2RegAct,
			  &lintNRegReg);



for(lLCSiscomPro2DatosCont=lLCSiscomPro2Datos;
    lLCSiscomPro2DatosCont;
    lLCSiscomPro2DatosCont=lLCSiscomPro2DatosCont->SCP2PtrSig)
{
if(!strcmp(lchrPtrIdRonda,
	   SiscomObtenDato(lLCSiscomPro2DatosCont,"idronda")) &&
   !strcmp(lchrPtrIdAparato,
   	   SiscomObtenDato(lLCSiscomPro2DatosCont,"idaparato")))
{
SiscomLog("\t\t%s %s %s",
	  SiscomObtenDato(lLCSiscomPro2DatosCont,"nmbgimnasta"),
	  SiscomObtenDato(lLCSiscomPro2DatosCont,"apatgimnasta"),
	  SiscomObtenDato(lLCSiscomPro2DatosCont,"amatgimnasta"));
SiscomCreaListaCamposPro2(lLCSiscomPro2DatosCont->SCSiscomPro2,
			  &lLCSiscomPro2RegPrim,
			  &lLCSiscomPro2RegAct);
lintNRegReg++;
}
}

AnexaRegistroInicioAparato("",
			   "",
			   "",
			   "",
			   lLCSiscomPro2Datos->SCSiscomPro2,
			  &lLCSiscomPro2RegPrim,
			  &lLCSiscomPro2RegAct,
			  &lintNRegReg);

}
AnexaRegistroInicioRonda("",
			  "",
			  lLCSiscomPro2Datos->SCSiscomPro2,
			  &lLCSiscomPro2RegPrim,
			  &lLCSiscomPro2RegAct,
			  &lintNRegReg);

}
SiscomImprimeContenidoProtocolo2("Resultado",lLCSiscomPro2RegPrim);

SiscomAsignaArgumentoOperacionPrim("ResRondas",lLCSiscomPro2RegPrim,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("ResRondas",lintNRegReg,pSAgsSiscom);

}
void RondaGimnastaAparato(SArgsSiscom *pSAgsSiscom)
{
StcSisFormaRegistro lSSFormaReg;
StcSisFormaRegistro lSSFormaRegRondas;
int lintContador;
int lintNumAparatos;
int lintNRegRondas;
LCamposSiscomPro2ConSubReg lLCSiscomPro2CSRDat;
LCamposSiscomPro2ConSubReg lLCSiscomPro2CSRRondas;
LCamposSiscomPro2 *lLCSiscomPro2Rondas;
LCamposSiscomPro2 *lLCSiscomPro2AparatoGimnasta;
	FormaEstructuraSubAparatos(
		SiscomArgumentoOperacionPrim("GimAparatos",pSAgsSiscom),
		&lSSFormaReg);
SiscomLeeConSubRegistros(SiscomArgumentoOperacionPrim("Rondas",pSAgsSiscom),
			 &lSSFormaReg,
			 &lLCSiscomPro2CSRDat);
lintNumAparatos=SiscomArgumentosNumeroRegistros("GimAparatos",pSAgsSiscom);
GeneraAparatoGimnasta(lintNumAparatos,
		      &lLCSiscomPro2CSRDat,
		      &lLCSiscomPro2AparatoGimnasta);
GeneraRondas(SiscomArgumentosNumeroRegistros("DatRondas",pSAgsSiscom),
	     SiscomArgumentoOperacionPrim("DatRondas",pSAgsSiscom),
	     lLCSiscomPro2AparatoGimnasta, 
	     &lLCSiscomPro2CSRRondas);
RondaAparatoGimnasta(SiscomArgumentosNumeroRegistros("DatRondas",pSAgsSiscom),
		     &lLCSiscomPro2CSRRondas,
		     pSAgsSiscom);
}
void RondaAparatoGimnasta(int pintNRondas,
			  LCamposSiscomPro2ConSubReg *pLCSiscomPro2CSRDat,
			  SArgsSiscom *pSAgsSiscom)
{
int lintContador;
int lintNRegistros=0;
LCamposSiscomPro2 *lLCSiscomPro2C;
LCamposSiscomPro2 *lLCSiscomPro2Act=0;
LCamposSiscomPro2 *lLCSiscomPro2Prim=0;
SCampoSiscomPro2 *lSCSiscomPro2Dat; 

	for(lintContador=0;
	    lintContador<pintNRondas;
	    lintContador++)
	 {
	   lLCSiscomPro2C=pLCSiscomPro2CSRDat->LCSiscomSubReg[lintContador].LCSiscomPro2Prim;
	   lSCSiscomPro2Dat=lLCSiscomPro2C->SCSiscomPro2;
	   AnexaRegistroInicioRonda(
	   	SiscomObtenDato(lLCSiscomPro2C,"idronda"),
		SiscomObtenDato(lLCSiscomPro2C,"nmbronda"),
		lSCSiscomPro2Dat,
		&lLCSiscomPro2Prim,
		&lLCSiscomPro2Act,
		&lintNRegistros);
	   for(;
	       lLCSiscomPro2C;
	       lLCSiscomPro2C=lLCSiscomPro2C->SCP2PtrSig)
	   {
		SiscomCreaListaCamposPro2(lLCSiscomPro2C->SCSiscomPro2,
					  &lLCSiscomPro2Prim,
					  &lLCSiscomPro2Act);
		lintNRegistros++;
	   }
	   AnexaRegistroInicioRonda(
	   	"",
		"",
		lSCSiscomPro2Dat,
		&lLCSiscomPro2Prim,
		&lLCSiscomPro2Act,
		&lintNRegistros);
	 }
SiscomAsignaArgumentoOperacionPrim("ResRondas",lLCSiscomPro2Prim,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("ResRondas",lintNRegistros,pSAgsSiscom);
}
void GeneraRondas(int pintNRondas,
		  LCamposSiscomPro2 *pLCSiscomPro2DatRondas,
		  LCamposSiscomPro2 *pLCSiscomPro2AparatoGimnasta,
		  LCamposSiscomPro2ConSubReg *pLCSiscomPro2CSRRondas)
{
StcSisFormaRegistro lSSFormaReg;
FormaEstructuraRondas(pLCSiscomPro2DatRondas,&lSSFormaReg);
SiscomLeeConSubRegistros(
		pLCSiscomPro2AparatoGimnasta,
		&lSSFormaReg,
		pLCSiscomPro2CSRRondas);
}
void GeneraIdRonda(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2=pSAgsSiscom->LCSiscomPro2Dat;
char lchrArrIdRonda[15];
const char *lchrPtrRonda;

lchrPtrRonda=SiscomObtenDato(lLCSiscomPro2,"Ronda");

SiscomObtenNumeroUnicoChar(lchrArrIdRonda);
SiscomContenidoProtocolo(lLCSiscomPro2); 

if(!SiscomObtenDato(lLCSiscomPro2,"IdRonda")[0])
while(lLCSiscomPro2)
{
SiscomObtenNumeroUnicoChar(lchrArrIdRonda);
lchrPtrRonda=SiscomObtenDato(lLCSiscomPro2,"Ronda");
SiscomLog("Ronda%s[%s]",lchrPtrRonda,lchrArrIdRonda);
for(;
    lLCSiscomPro2 &&
    !strcmp(lchrPtrRonda,
    	    SiscomObtenDato(lLCSiscomPro2,"Ronda"));
    lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
{
SiscomAsignaDatoCampo2("IdRonda",
		       lchrArrIdRonda,
		       lLCSiscomPro2);

}
}
else
SiscomLog("No Se Genera El IdRonda"); 
}
void ObtenRondasCompetencia(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Regreso=0;
int lintNRegRespuesta;
char lchrArrSQL[2048];
sprintf(lchrArrSQL,
	"select distinct * 					\
	 from rondas						\
	 where idcompetencia=%s",
	 pSAgsSiscom->chrPtrArgConsulta[1]);

SiscomConsultaBaseDatosSinDatosConexion(
        lchrArrSQL,
	gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
	gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	&lLCSiscomPro2Regreso,
	&lintNRegRespuesta);
SiscomAsignaArgumentoOperacionPrim("DatRondas",lLCSiscomPro2Regreso,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("DatRondas",lintNRegRespuesta,pSAgsSiscom);


}
SiscomOperaciones2 *RegistraRondas()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ArgumentosRonda,lSOpPtrGimnasio); 
SiscomAnexaOperacionAlArreglo2(GeneraIdRonda,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(SqlEliminaDetalleRonda,lSOpPtrGimnasio); 
SiscomAnexaOperacionAlArreglo2(SqlEliminaRonda,lSOpPtrGimnasio); 
SiscomAnexaOperacionAlArreglo2(SQLRonda,lSOpPtrGimnasio); 
SiscomAnexaOperacionAlArreglo2(SQLDetalleRonda,lSOpPtrGimnasio); 
SiscomAnexaOperacionAlArreglo2(InsertaRondas,lSOpPtrGimnasio); 
return lSOpPtrGimnasio;

}
SiscomOperaciones2 *CalificaRonda()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(ArgumentosRonda,lSOpPtrGimnasio); 
SiscomAnexaOperacionAlArreglo2(ObtenAparatos,lSOpPtrGimnasio); 
SiscomAnexaOperacionAlArreglo2(ObtenRondasCompetencia,lSOpPtrGimnasio); 
SiscomAnexaOperacionAlArreglo2(SQLCalificaRonda,lSOpPtrGimnasio); 
SiscomAnexaOperacionAlArreglo2(RondaGimnastaAparato01,lSOpPtrGimnasio); 
SiscomAnexaOperacionAlArreglo2(EnviaRondasCliente,lSOpPtrGimnasio);
return lSOpPtrGimnasio;
}
void AnexaRegistroInicioAparato(const char *pchrPtrIdAparato,
				const char *pchrPtrAparato,
				const char *pchrPtrIdRonda,
				const char *pchrPtrRonda,
				SCampoSiscomPro2 *pSCSiscomPro2,
				LCamposSiscomPro2 **pLCSiscomPro2Prim,
				LCamposSiscomPro2 **pLCSiscomPro2Act,
				int *pintPtrNRegistros)
{
SCampoSiscomPro2 *lSCSiscomPro2;
	SiscomCopiaCampos(pSCSiscomPro2,&lSCSiscomPro2);
	SiscomAsignaDatoCampo2A("aparato",pchrPtrAparato,lSCSiscomPro2);
	SiscomAsignaDatoCampo2A("idaparato",pchrPtrIdAparato,lSCSiscomPro2);
	SiscomAsignaDatoCampo2A("idronda",pchrPtrIdRonda,lSCSiscomPro2);
	SiscomAsignaDatoCampo2A("nmbronda",pchrPtrRonda,lSCSiscomPro2);
	SiscomCreaListaCamposPro2(lSCSiscomPro2,
				  pLCSiscomPro2Prim,
				  pLCSiscomPro2Act);
	(*pintPtrNRegistros)++;
}
void AnexaRegistroInicioRonda(const char *pchrPtrIdRonda,
			      const char *pchrPtrRonda,
			      SCampoSiscomPro2 *pSCSiscomPro2,
			      LCamposSiscomPro2 **pLCSiscomPro2Prim,
			      LCamposSiscomPro2 **pLCSiscomPro2Act,
			      int *pintPtrNRegistros)
{
SCampoSiscomPro2 *lSCSiscomPro2;
SiscomCopiaCampos(pSCSiscomPro2,&lSCSiscomPro2);
SiscomAsignaDatoCampo2A("idronda",pchrPtrIdRonda,lSCSiscomPro2);
SiscomAsignaDatoCampo2A("nmbronda",pchrPtrRonda,lSCSiscomPro2);
SiscomCreaListaCamposPro2(lSCSiscomPro2,
			  pLCSiscomPro2Prim,
			  pLCSiscomPro2Act);
(*pintPtrNRegistros)++;
}
