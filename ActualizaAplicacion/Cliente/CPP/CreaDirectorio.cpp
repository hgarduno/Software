#include <CreaDirectorio.h>
#include <unistd.h>
#include <stdio.h>

CreaDirectorio::CreaDirectorio(SiscomDatCom *pSDatCom,
			       const char *pchrPtrNmbDirectorio,
			       const char *pchrPtrDirServidor):

			chrPtrEdoConexion(0),
			SDatCom(pSDatCom),
			chrPtrNmbDirectorio(pchrPtrNmbDirectorio),
			chrPtrNmbDirectorioServidor(pchrPtrDirServidor)
{
}
CreaDirectorio::~CreaDirectorio()
{
}
const char *CreaDirectorio::ObtenEdoConexion()
{
	return chrPtrEdoConexion;
}
void CreaDirectorio::EnviaOrden()
{

SiscomRegistroPro2 lSiscomRegPro2;
	lSiscomRegPro2 		   << 
	"DirHome"     		   <<
	"DirectorioInstalacion"    <<
	"DirectorioServidor" ;
SiscomRegistrosPro2 lSRegistrosPro2(&lSiscomRegPro2);

	lSRegistrosPro2          <<
	SiscomCampoPro2("DirHome","/home/hgarduno") <<
	SiscomCampoPro2("DirectorioInstalacion",chrPtrNmbDirectorio) <<
	SiscomCampoPro2("DirectorioServidor",chrPtrNmbDirectorioServidor);	

	lSRegistrosPro2.SiscomAnexaRegistro();

	SComunicaSrv=new SiscomComunicaSrv(SDatCom);

		if(!SComunicaSrv->SiscomObtenEdoConexion())
		   SComunicaSrv->SiscomEnvia(&lSRegistrosPro2,"CreaDirectorioTrabajo");
		

	

}
void CreaDirectorio::ObtenEdoCreacion(char **pchrPtrEdoInstalacion,	
				  char **pchrPtrEdoConfiguracion)
{

	SComunicaSrv->SiscomObtenRespuesta();
	SiscomRegistrosPro2 lSRegistrosPro2(SComunicaSrv);
	*pchrPtrEdoInstalacion=(char *)lSRegistrosPro2["EdoCreacionInstalacion"];
	*pchrPtrEdoConfiguracion=(char *)lSRegistrosPro2["EdoCreacionConfiguracion"];
	printf("%s\t%s\n",
		*pchrPtrEdoInstalacion,
		*pchrPtrEdoConfiguracion);

}
