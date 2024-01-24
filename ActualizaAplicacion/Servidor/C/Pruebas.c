#include <SiscomProtocolo2.h>
#include <stdio.h>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
typedef struct Pruebas 
{
	const char *chrPtrOpcion;
	void (*Operacion)(int,char **);
}StcPruebas;

void CadenaProtocolo(int,char **);
void EnvioModulo(int,char **);
void PruebaRegistros(int,char **);

void PruebaRegistros2(int,char **);


StcPruebas gSPruebas[]={
				{ "-a", CadenaProtocolo },
				{ "-b", EnvioModulo     },
				{ "-c", PruebaRegistros },
				{ "-d", PruebaRegistros2 }
			       };

int ObtenOpcion(int pintArgc,char **pzCArgv)
{
int lintContador,
    lintContadorJ;
	for(lintContador=1;
	    lintContador<pintArgc;
	    lintContador++)
	{
	    for(lintContadorJ=0;
	        lintContadorJ<4;
		lintContadorJ++)
	      if(!strcmp(gSPruebas[lintContadorJ].chrPtrOpcion,
			 pzCArgv[lintContador])) 
		 return lintContadorJ;
	}

	return -1;
}


int main(int pintArgc,
	 char **pchrPtrArgv)
{
int lintOpcion;
	if((lintOpcion=ObtenOpcion(pintArgc,pchrPtrArgv))!=-1)
	{
	    gSPruebas[lintOpcion].Operacion(pintArgc,
					    pchrPtrArgv);
	}

}
void CadenaProtocolo(int pintArgc,
		     char **pchrPtrArgv)
{
char *lchrPtrProtocolo=0;
int lintNoCampo=0;
	SiscomFormaRegistroIniEnvio("ActualizaServidor",
				    &lchrPtrProtocolo);
	SiscomAnexaCampoProtocolo2("ModuloCliente",
				   &lintNoCampo,
				   "/home/hgarduno/.Clinicas/Cliente/SO/libCitas.so",
				  &lchrPtrProtocolo);
	SiscomAnexaCampoProtocolo2("DireccionIpEstacion",
				   &lintNoCampo,
				   "127.0.0.1",
				  &lchrPtrProtocolo);
	SiscomAnexaCampoProtocolo2("PuertoComunicaciones",
				   &lintNoCampo,
				   "4545",
				  &lchrPtrProtocolo);
	SiscomNumeroCamposAlProtocolo(lintNoCampo,
				      lchrPtrProtocolo);
	printf("%s\n",lchrPtrProtocolo);
}
void EnvioModulo(int pintArgc,
		 char **pchrPtrArgv)
{
SCampoSiscomPro2 lSCSiscomPro2[5];
int lintNCampos,
    lintContador,
    lintSocket;
char *lchrPtrEdoConexion;

LCamposSiscomPro2 *lLCSiscomPro2P=0,
		  *lLCSiscomPro2A=0;
SiscomIniciaRegistro(lSCSiscomPro2,
		     &lintNCampos,
		     "%s%s%s%s",
		     "Modulo",
		     "DireccionIpEstacion",
		     "PuertoComunicaciones",
		     "DirectorioInstalacion");

	SiscomAsignaDatoCampo("Modulo",
			      lintNCampos,
			      "libCitas.so",
			      lSCSiscomPro2);
	SiscomAsignaDatoCampo("DireccionIpEstacion",
			      lintNCampos,
			      "127.0.0.1",
			      lSCSiscomPro2);
	SiscomAsignaDatoCampo("PuertoComunicaciones",
			      lintNCampos,
			      "4545",
			      lSCSiscomPro2);
	SiscomAsignaDatoCampo("DirectorioInstalacion",
			      lintNCampos,
			      "/home/hgarduno/SISCOMClinicas2Cliente",
			      lSCSiscomPro2);
   SiscomCreaListaCamposPro2(lSCSiscomPro2,
			     &lLCSiscomPro2P,
			     &lLCSiscomPro2A);

	if((lintSocket=SiscomConectateServidor(4545,
					       "127.0.0.1",
						&lchrPtrEdoConexion))>0)
	{
	printf("Si Se Conecto \n");
	SiscomEnviaAlServidor(lintSocket,
			      "ActualizaModulo",
			      lLCSiscomPro2P);
	 {
	   int lintModulo,
               lintNBytes=4196;
	   char lchrArrBuffer[4196],
		lchrArrEnvio[1050];
	   char lchrCaracter;
		
	     if((lintModulo=open("/home/hgarduno/.Clinicas2/Cliente/SO/libCitas.so",
			     O_RDONLY,
			     0))<0)
		{

		}
		else
		{
		  while((lintNBytes=read(lintModulo,
			lchrArrBuffer,
			4196)))
		       write(lintSocket	,
			     lchrArrBuffer,
			     lintNBytes);
		}
	  
	  }
	}
	else
	printf("No Se Pudo Conectar {%s}\n",lchrPtrEdoConexion);
	close(lintSocket); 

}

/*

	SiscomAnexaRegistro(LCamposSiscomPro **, 
			    LCamposSiscomPro **,
			    const char *,
			    const char *,
			    ...);


	SiscomAnexaRegistroPro2(pLCSiscomPro2P,
			    pLCSiscomPro2A,
			    "ActualizaServidor",	
			    "Modulo,  			\
			     DireccionIpEstacion,	\
			     PuertoComunicaciones,	\
			     DirectorioInstalacion",
			    "libCentroDelMedico",
			    "192.168.1.45",
			    "4545",
			    "/home/hgarduno/SISCOMClinicas2Cliente");
			    
		
	


*/
void PruebaRegistros2(int pintArgc,
		     char **pchrPtrArgv)
{
int lintSocket;
LCamposSiscomPro2 *lLCSiscomPro2P=0,
		  *lLCSiscomPro2A=0;
char *lchrPtrEdoConexion;
/*
SiscomAnexaRegistroPro2(&lLCSiscomPro2P,
			    &lLCSiscomPro2A,
			    "Modulo,			\
			     DireccionIpEstacion,	\
			     PuertoComunicaciones,	\
			     DirectorioInstalacion",
			    "libCentroDelMedico.so",
			    "192.168.1.45",
			    "4545",
			    "/home/hgarduno/SISCOMClinicas2Cliente");

SiscomAnexaRegistroPro2(&lLCSiscomPro2P,
			    &lLCSiscomPro2A,
			    "Modulo,  			\
			     DireccionIpEstacion,	\
			     PuertoComunicaciones,	\
			     DirectorioInstalacion",
			    "libCentroDelMedico.so",
			    "192.168.1.52",
			    "4545",
			    "/home/hgarduno/SISCOMClinicas2Cliente");
*/
SiscomAnexaRegistroPro2(&lLCSiscomPro2P,
			    &lLCSiscomPro2A,
			    "Nombre",
			    "Heli" );
if((lintSocket=SiscomConectateServidor(4545,
				       "127.0.0.1",
					&lchrPtrEdoConexion))>0)
{
	SiscomEnviaAlServidor(lintSocket,
			      "ActualizaServidor",
			      lLCSiscomPro2P);
}
else
printf("No Se Puedo Conectar :%s\n",lchrPtrEdoConexion);
}
void PruebaRegistros(int pintArgc,
		     char **pchrPtrArgv)
{
SCampoSiscomPro2 lSCSiscomPro2[5];
int lintNCampos,
    lintContador,
    lintSocket;

LCamposSiscomPro2 *lLCSiscomPro2P=0,
		  *lLCSiscomPro2A=0;
SiscomIniciaRegistro(lSCSiscomPro2,
		     &lintNCampos,
		     "%s%s%s%s",
		     "Modulo",
		     "DireccionIpEstacion",
		     "PuertoComunicaciones",
		     "DirectorioInstalacion");

	SiscomAsignaDatoCampo("Modulo",
			      lintNCampos,
			      "libCitas.so",
			      lSCSiscomPro2);
	SiscomAsignaDatoCampo("DireccionIpEstacion",
			      lintNCampos,
			      "127.0.0.1",
			      lSCSiscomPro2);
	SiscomAsignaDatoCampo("PuertoComunicaciones",
			      lintNCampos,
			      "4545",
			      lSCSiscomPro2);
	SiscomAsignaDatoCampo("DirectorioInstalacion",
			      lintNCampos,
			      "/home/hgarduno/SISCOMClinicas2Cliente",
			      lSCSiscomPro2);
   SiscomCreaListaCamposPro2(lSCSiscomPro2,
			     &lLCSiscomPro2P,
			     &lLCSiscomPro2A);

   SiscomCreaListaCamposPro2(lSCSiscomPro2,
			     &lLCSiscomPro2P,
			     &lLCSiscomPro2A);

   SiscomCreaListaCamposPro2(lSCSiscomPro2,
			     &lLCSiscomPro2P,
			     &lLCSiscomPro2A);
   SiscomCreaListaCamposPro2(lSCSiscomPro2,
			     &lLCSiscomPro2P,
			     &lLCSiscomPro2A);
   SiscomCreaListaCamposPro2(lSCSiscomPro2,
			     &lLCSiscomPro2P,
			     &lLCSiscomPro2A);
   SiscomCreaListaCamposPro2(lSCSiscomPro2,
			     &lLCSiscomPro2P,
			     &lLCSiscomPro2A);
	if((lintSocket=SiscomConectateServidor(4545,
					       "127.0.0.1"))>0)
	{
	SiscomEnviaAlServidor(lintSocket,
			      "ActualizaServidor",
			      lLCSiscomPro2P);
	}

}

