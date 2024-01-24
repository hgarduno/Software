#include <Estaciones.h>
#include <stdio.h>
Estaciones::Estaciones(SiscomDatCom *pSDatCom,
		       const char *pchrPtrDirTrabajo,
			const char *pchrPtrHome):
		SDatCom(pSDatCom),
		chrPtrHome(pchrPtrHome),
		chrPtrDirTrabajo(pchrPtrDirTrabajo)
{
	CreaRegistroComunicaciones();
	ObtenEstaciones();

}

Estaciones::Estaciones(SiscomDatCom *pSDatCom,
		       const char *pchrPtrOperacion,
		       ListaEstaciones *pLstEstaciones):
		      SDatCom(pSDatCom),
		      chrPtrOperacion(pchrPtrOperacion),
		      LstEstaciones2(pLstEstaciones)
{
	IniciaRegistroComunicacion();
	EnviaInformacionServidor();

}
void Estaciones::IniciaRegistroComunicacion()
{
	SRegistroPro2 <<
	"DirIp"       <<
	"PtoCom"      <<
	"DirTrabajo"  <<
	"Home"        <<
	"Parametro"   <<
	"EdoRegistro";

}
void Estaciones::CreaRegistroComunicaciones()
{

}
void Estaciones::EnviaInformacionServidor()
{
SiscomRegistrosPro2 lSRegistrosPro2(&SRegistroPro2);
Estacion *lEstacion;

	for(lEstacion=LstEstaciones2->first();
	    lEstacion;
	    lEstacion=LstEstaciones2->next())
	{
	  
	    lSRegistrosPro2                       		<<
	    SiscomCampoPro2("DirIp",lEstacion->ObtenDirIp())	<<
	    SiscomCampoPro2("PtoCom",lEstacion->ObtenPtoCom())	<<
	    SiscomCampoPro2("DirTrabajo",lEstacion->ObtenDirTrabajo()) <<
	    SiscomCampoPro2("Home",lEstacion->ObtenHome())             <<	
	    SiscomCampoPro2("Parametro",lEstacion->ObtenParametro())   <<
	    SiscomCampoPro2("EdoRegistro",lEstacion->ObtenEdoRegistro());
	    lSRegistrosPro2.SiscomAnexaRegistro(); 
	}

	SComunicaSrv=new SiscomComunicaSrv(SDatCom);
	if(!SComunicaSrv->SiscomObtenEdoConexion())
	{
	
	    SComunicaSrv->SiscomEnvia(&lSRegistrosPro2,chrPtrOperacion);
	    SComunicaSrv->SiscomObtenRespuesta();
	    SiscomRegistrosPro2 lSRegistrosPro2(SComunicaSrv);
	    LstEstaciones2->clear();
	    for(;
		!lSRegistrosPro2.SiscomEsElUltimoRegistro();
		++lSRegistrosPro2)
		LstEstaciones2->append(new Estacion(
					     lSRegistrosPro2["dirip"],
					     lSRegistrosPro2["ptocom"],
					     lSRegistrosPro2["dirtrabajo"],
					     lSRegistrosPro2["home"],
					     "",
					     ""));
	 
	
	}		
	
	
}
void Estaciones::ObtenEstaciones()
{
}
const ListaEstaciones &Estaciones::ObtenEstacionesTrabajo()
{

	LstEstaciones.CreaListaEstacionesServidor(SComunicaSrv);	

	return LstEstaciones;

}
Estacion::Estacion(const char *pchrPtrDirIp,
		   const char *pchrPtrPtoCom,
		   const char *pchrPtrDirTrabajo,
		   const char *pchrPtrHome,
		   const char *pchrPtrParametro,
		   const char *pchrPtrEdoRegistro):
		chrPtrDirIp(pchrPtrDirIp),
		chrPtrPtoCom(pchrPtrPtoCom),
		chrPtrDirTrabajo(pchrPtrDirTrabajo),
		chrPtrHome(pchrPtrHome),
		chrPtrParametro(pchrPtrParametro),
		chrPtrEdoRegistro(pchrPtrEdoRegistro)
{

}
const char *Estacion::ObtenDirIp()
{
	return chrPtrDirIp;
}
const char *Estacion::ObtenPtoCom()
{
	return chrPtrPtoCom;
}

const char *Estacion::ObtenDirTrabajo()
{
	return chrPtrDirTrabajo;
}

const char *Estacion::ObtenHome()
{
	return chrPtrHome;
}
const char *Estacion::ObtenParametro()
{
	return chrPtrParametro;

}

const char *Estacion::ObtenEdoRegistro()
{
	return chrPtrEdoRegistro;
}
ListaEstaciones::ListaEstaciones()
{

}
void ListaEstaciones::CreaListaEstacionesServidor(SiscomComunicaSrv *pSComunicaSrv)
{
pSComunicaSrv->SiscomObtenRespuesta();
SiscomRegistrosPro2 lSRegistrosPro2(pSComunicaSrv);
	for(;
	    !lSRegistrosPro2.SiscomEsElUltimoRegistro();
	    ++lSRegistrosPro2)
	{
	    append(new Estacion(lSRegistrosPro2["DirIp"],
				lSRegistrosPro2["PtoCom"],
				lSRegistrosPro2["DirTrabajo"],
				lSRegistrosPro2["Home"],
				"",
				""));
	}
}
