#include <TransfiereArchivos.h>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
#include <unistd.h>
#include <string.h>
TransfiereArchivo::TransfiereArchivo(SiscomDatCom *pSDatCom,
				    const char *pchrPtrOrigen,
				    const char *pchrPtrDestino,
				    const char *pchrPtrDirTrabajo,
				    const char *pchrPtrHome,
				    const char *pchrPtrComentario):
			SDatCom(pSDatCom),
			chrPtrOrigen(pchrPtrOrigen),
			chrPtrDestino(pchrPtrDestino),
			chrPtrDirTrabajo(pchrPtrDirTrabajo),
			chrPtrHome(pchrPtrHome),
		        chrPtrComentario(pchrPtrComentario)
{
	CreaRegistroComunicaciones();
	Transfiere();

}
TransfiereArchivo::TransfiereArchivo(SiscomDatCom *pSDatCom,
				    const char *pchrPtrOrigen,
				    const char *pchrPtrDestino,
				    const char *pchrPtrDirTrabajo,
				    const char *pchrPtrHome,
				    const char *pchrPtrComentario,
				    const char *pchrPtrArchivoEnBuffer):
			SDatCom(pSDatCom),
			chrPtrOrigen(pchrPtrOrigen),
			chrPtrDestino(pchrPtrDestino),
			chrPtrDirTrabajo(pchrPtrDirTrabajo),
			chrPtrHome(pchrPtrHome),
			chrPtrComentario(pchrPtrComentario),
			chrPtrArchivoEnBuffer(pchrPtrArchivoEnBuffer)
{
	CreaRegistroComunicaciones();
	TransfiereDelBuffer();

}			    
TransfiereArchivo::~TransfiereArchivo()
{
	delete SComunicaSrv;
}
void TransfiereArchivo::CreaRegistroComunicaciones()
{
	SRegistroPro2 <<
	"Origen"      <<
	"Destino"     <<
	"DirTrabajo"  <<
	"Home"        <<
	"Comentario";

}
void TransfiereArchivo::TransfiereDelBuffer()
{
SiscomRegistrosPro2 lSRegistrosPro2(&SRegistroPro2);

	lSRegistrosPro2 				<<
	SiscomCampoPro2("Origen",chrPtrOrigen)		<<	
	SiscomCampoPro2("Destino",chrPtrDestino)	<<
	SiscomCampoPro2("DirTrabajo",chrPtrDirTrabajo)  <<
	SiscomCampoPro2("Home",chrPtrHome)              <<
	SiscomCampoPro2("Comentario",chrPtrComentario) ;
	lSRegistrosPro2.SiscomAnexaRegistro();

	SComunicaSrv=new SiscomComunicaSrv(SDatCom);
	if(!SComunicaSrv->SiscomObtenEdoConexion())
	{
	 SComunicaSrv->SiscomEnvia(&lSRegistrosPro2,"CopiaModulo");
	 EnviaArchivoDelBuffer(SComunicaSrv->SiscomObtenSocket());
	}
}
void TransfiereArchivo::Transfiere()
{
SiscomRegistrosPro2 lSRegistrosPro2(&SRegistroPro2);

	lSRegistrosPro2 				<<
	SiscomCampoPro2("Origen",chrPtrOrigen)		<<	
	SiscomCampoPro2("Destino",chrPtrDestino)	<<
	SiscomCampoPro2("DirTrabajo",chrPtrDirTrabajo)  <<
	SiscomCampoPro2("Home",chrPtrHome)              <<
	SiscomCampoPro2("Comentario",chrPtrComentario);
	lSRegistrosPro2.SiscomAnexaRegistro();

	SComunicaSrv=new SiscomComunicaSrv(SDatCom);
	if(!SComunicaSrv->SiscomObtenEdoConexion())
	{
	 SComunicaSrv->SiscomEnvia(&lSRegistrosPro2,"CopiaModulo");
	 EnviaArchivo(SComunicaSrv->SiscomObtenSocket());
	}
}
void TransfiereArchivo::EnviaArchivo(int pintSocket)
{
int lintArchivo;
int lintNBytes;
char lchrArrBuffer[4198];
	if((lintArchivo=open(chrPtrOrigen, O_RDONLY,0))<0)
	{

	}
	else
	{
	    while((lintNBytes=read(lintArchivo,
				   lchrArrBuffer,
				   4196)))
	       write(pintSocket,
		     lchrArrBuffer,
		     lintNBytes);
		close(lintArchivo);
	}

}
void TransfiereArchivo::EnviaArchivoDelBuffer(int pintSocket)
{
	       write(pintSocket,
		     chrPtrArchivoEnBuffer,
		     strlen(chrPtrArchivoEnBuffer));

}
