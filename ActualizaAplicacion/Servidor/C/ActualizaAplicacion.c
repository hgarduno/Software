#include <ActualizaAplicacion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int errno;

void OperacionesActualiza(SSiscomOperaciones **pSSiscomOp)
{

	(*pSSiscomOp)->intNumOperaciones=0;
	SiscomIniciaOperaciones(3,pSSiscomOp);

	SiscomAnexaOperacion("ActualizaModulo",
			     OP_ActualizaModulo,
			     pSSiscomOp);	

	SiscomAnexaOperacion("ActualizaConfiguracion",
			     OP_ActualizaConfiguracion,
			     pSSiscomOp);	
	SiscomAnexaOperacion("ActualizaServidor",
			     OP_ActualizaServidor,
			     pSSiscomOp);	
}

int CreaArchivoEscribir(const char *pchrPtrNmbArchivo,
			 const char *pchrPtrDirectorio,
			 int *pintPtrArchivo)
{

char lchrArrArchivo[1024];

	sprintf(lchrArrArchivo,
		"%s/%s",
		pchrPtrDirectorio,
		pchrPtrNmbArchivo);

	if((*pintPtrArchivo=open(lchrArrArchivo,
				 O_WRONLY|O_CREAT,
				 S_IRWXU|S_IROTH|S_IXOTH))<0)
	{
	  printf("CreaArchivoEscribir:{%s}{%s}\n",
		 lchrArrArchivo);
	  return 0;
	}
	else
	{
	printf("%s\n",strerror(errno));
	return 1;
	}
	



}
void LeeInformacionYCopia(int pintModulo,
			  int pintSocket)
{
char lchrArrNumBytes[5],
     *lchrPtrDatos;
int lintNumBytes;
char lchrCaracter;
char lchrArrBuffer[4196];
	   while((lintNumBytes=read(pintSocket,
		      &lchrArrBuffer,
		      1024)))
	      write(pintModulo,lchrArrBuffer,lintNumBytes);
}
void OP_ActualizaModulo(int pintSocket)
{
int lintContador;
int lintNCampos;
int lintModulo,
    lintNumBytesEscritos;
SCampoSiscomPro2 *lSCSiscomPro2Reg;
const char *lchrPtrModulo, 
	   *lchrPtrDirectorioIns;
char lchrArrNumBytes[10];
char *lchrArrEnvio;
int lintTamEnvio;
int lintRegreso;
SiscomLeeRegistroProtocolo2(pintSocket,
                                    &lSCSiscomPro2Reg);

        printf("El Registro ActualizaModulo\n");
        for(lintContador=0;lintContador<lSCSiscomPro2Reg->intNumCampos;lintContador++)
        printf("{%s,%s,%s}\n",
              (lSCSiscomPro2Reg+lintContador)->chrPtrNmbCampo,
              (lSCSiscomPro2Reg+lintContador)->chrPtrNoCampo,
              (lSCSiscomPro2Reg+lintContador)->chrPtrDato);
	lchrPtrModulo=SiscomObtenDatoDelRegistro(
				lSCSiscomPro2Reg,
				"Modulo",
				lintNCampos);
	lchrPtrDirectorioIns=SiscomObtenDatoDelRegistro(
				lSCSiscomPro2Reg,
				"DirectorioInstalacion",
				lintNCampos);
	if(lchrPtrModulo     &&
	   lchrPtrDirectorioIns &&
	CreaArchivoEscribir(lchrPtrModulo,
		     lchrPtrDirectorioIns,
		     &lintModulo))
	{
	  LeeInformacionYCopia(lintModulo,pintSocket); 	
	  close(lintModulo);
	  
	}

        close(pintSocket);

}
void OP_ActualizaConfiguracion(int pintSocket)
{
int lintContador;
int lintNCampos;
SCampoSiscomPro2 *lSCSiscomPro2Reg;
SiscomLeeRegistroProtocolo2(pintSocket,
                                    &lSCSiscomPro2Reg);

        printf("El Registro ActualizaConfiguracion\n");
        for(lintContador=0;lintContador<lintNCampos;lintContador++)
        printf("{%s,%s,%s}\n",
              (lSCSiscomPro2Reg+lintContador)->chrPtrNmbCampo,
              (lSCSiscomPro2Reg+lintContador)->chrPtrNoCampo,
              (lSCSiscomPro2Reg+lintContador)->chrPtrDato);

        close(pintSocket);

}
void OP_ActualizaServidor(int pintSocket)
{

int lintContador;
int lintNCampos;
int lintNRegistros;
SCampoSiscomPro2 *lSCSiscomPro2Reg;
char *lchrPtrOperacion;
/*
do
{
printf("OP_ActualizaServidor \n");
SiscomLeeRegistroProtocolo2(pintSocket,
                                    &lSCSiscomPro2Reg);

        printf("El Registro ActualizaServidor\n");
        for(lintContador=0;
	    lintContador<lSCSiscomPro2Reg->intNumCampos;
	    lintContador++)
        printf("{%s,%s,%s}\n",
              (lSCSiscomPro2Reg+lintContador)->chrPtrNmbCampo,
              (lSCSiscomPro2Reg+lintContador)->chrPtrNoCampo,
              (lSCSiscomPro2Reg+lintContador)->chrPtrDato);
  free(lSCSiscomPro2Reg);
}while(SiscomLeeOperacion(pintSocket,
			  &lchrPtrOperacion));
*/
LCamposSiscomPro2 *lLCSiscomPro2=0;
const char *lchrPtrNmbCampo;
		SiscomLeeInformacionProtocolo(pintSocket,
					      &lintNRegistros,
					      &lLCSiscomPro2);
	for(;
	    lLCSiscomPro2;
	    lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
	{
	  SiscomImprimeContenidoRegistro("",lLCSiscomPro2->SCSiscomPro2); 
	
	}
        close(pintSocket);
}

