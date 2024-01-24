#include <SiscomOperaciones3.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomParametroConsulta3.h>
#include <SiscomRegistros4.h>
#include <SiscomDatCom.h>

#include <sys/socket.h>
#include <netdb.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
SiscomOperaciones3::SiscomOperaciones3()
{

}
SiscomOperaciones3::SiscomOperaciones3(SiscomDatCom *pSisDatCom):
			SisDatCom(pSisDatCom),
			chrPtrEdoConexion(0)
{
ConectaServidor();
}
SiscomOperaciones3::~SiscomOperaciones3()
{
	close(intSocket);
}
void SiscomOperaciones3::ConectaServidor() 
{
int lintSocketCliente; struct sockaddr_in lSocAddrInCon;

	if((intSocket=::socket(AF_INET,SOCK_STREAM,0))<0)
	{
	}
	else
	{
	  lSocAddrInCon.sin_family=AF_INET;
	  lSocAddrInCon.sin_port=htons(SisDatCom->SiscomObtenPuertoCom());
	  lSocAddrInCon.sin_addr.s_addr=::inet_addr(SisDatCom->SiscomObtenDireccionIp());
	  if((lintSocketCliente=::connect(intSocket,
					(struct sockaddr *)&lSocAddrInCon,
					sizeof(struct sockaddr_in)))<0)
	     chrPtrEdoConexion=(char *)strerror(errno); 
	}
if(chrPtrEdoConexion)
SiscomEscribeLog3Qt("%s",chrPtrEdoConexion);
}
void SiscomOperaciones3::NumeroRegistros(int pintNumRegistros,
					 char *pchrPtrNumeroRegistros)
{
sprintf(pchrPtrNumeroRegistros,
	"%06d",
	pintNumRegistros);
}
void SiscomOperaciones3::EnviaNumeroRegistros(int pintNumRegistros)
{
char lchrArrNumRegistros[12];
sprintf(lchrArrNumRegistros,
	"%06d",
	pintNumRegistros);
EnviaCadena(lchrArrNumRegistros);
}
void SiscomOperaciones3::InicioRegistro(const char *pchrPtrOperacion,
					     char **pchrPtrIniRegistro)
{
int lintTamano;
*pchrPtrIniRegistro=(char *)malloc((lintTamano=strlen(pchrPtrOperacion))+12);
sprintf(*pchrPtrIniRegistro,
	"%04d%s%04d",
	lintTamano,
	pchrPtrOperacion,
	0);
}
void SiscomOperaciones3::EnviaCadena(const char *pchrPtrCadena)
{
int lintTamEnvio=strlen(pchrPtrCadena);
   if(write(intSocket,pchrPtrCadena,lintTamEnvio)!=lintTamEnvio)
   {

   }
   /*
   SiscomEscribeLog3Qt("%s",pchrPtrCadena);

   */
}


void SiscomOperaciones3::AnexaDatoCampo(const char *pchrPtrDato,
		    char **pchrPtrSalida)
{
	*pchrPtrSalida=(char *)malloc(strlen(pchrPtrDato)+6);
	sprintf(*pchrPtrSalida,
		"%04d%s",
		strlen(pchrPtrDato),
		pchrPtrDato);	
}

void SiscomOperaciones3::AnexaCampoProtocolo2(const char *pchrPtrNmbCampo,
				int *pintPtrNoCampo,
				const char *pchrPtrCampo,
				char **pchrPtrCadena)
{
char lchrArrNoCampo[12];
char *lchrPtrNmbCampo,
     *lchrPtrNoCampo,
     *lchrPtrCampo;
int lintTamano,
	lintTamanoIni=0,
	lintNmbCampo,
	lintNoCampo,
	lintCampo;

	lintTamanoIni=strlen(*pchrPtrCadena);
	sprintf(lchrArrNoCampo,"%04d",*pintPtrNoCampo);
	AnexaDatoCampo(pchrPtrNmbCampo,&lchrPtrNmbCampo);
	AnexaDatoCampo(lchrArrNoCampo,&lchrPtrNoCampo);
	AnexaDatoCampo(pchrPtrCampo,&lchrPtrCampo);

	lintTamano=4                                      +
		   (lintNmbCampo=strlen(lchrPtrNmbCampo)) +
		   (lintNoCampo=strlen(lchrPtrNoCampo))   +
		   (lintCampo=strlen(lchrPtrCampo));

	*pchrPtrCadena=(char *)realloc(*pchrPtrCadena,lintTamano+lintTamanoIni);
	sprintf(*pchrPtrCadena+lintTamanoIni,
		"%s%s%s",
		lchrPtrNmbCampo,
		lchrPtrNoCampo,
		lchrPtrCampo);
	free(lchrPtrNmbCampo);
	free(lchrPtrNoCampo);
	free(lchrPtrCampo);
	(*pintPtrNoCampo)++;
}

void SiscomOperaciones3::NumeroCamposAlProtocolo(int pintNoCampos,
				   char *pchrPtrCadenaEnvio)
{
int lintTamIni;
char lchrArrNoCampos[5],
	lchrArrTamOperacion[5];
	strncpy(lchrArrTamOperacion,pchrPtrCadenaEnvio,4);	
	lchrArrTamOperacion[4]=0;
	lintTamIni=atoi(lchrArrTamOperacion);
	sprintf(lchrArrNoCampos,
		"%04d",
		pintNoCampos);
	strncpy(pchrPtrCadenaEnvio+lintTamIni+4,
		lchrArrNoCampos,
		4);
}
void SiscomOperaciones3::EnviaVersionProtocolo()
{
char lchrArrVersionProtocolo[16];
sprintf(lchrArrVersionProtocolo,"%05d%05d%05d",2,0,0);
EnviaCadena(lchrArrVersionProtocolo);
}
void SiscomOperaciones3::SiscomEnvia(const char *pchrPtrOperacion,
				     SiscomRegistro3 *pSisReg3Envio,
				     SiscomRegistro4 *pSisReg4Info,
				     SiscomRegistro4 *pSisReg4Reg)
{
SiscomRegistro3Lst lSisReg3LstConf;
SiscomRegistro3LstLst *lSisReg3LstLstEnvio;
SiscomRegistro3Lst *lSisReg3LstEnvio;
SiscomRegistro4 *lSisReg4Envio;
/*
 * Faltara resolver el envio con el registro de configuracion
 * para el numero de registros total 
 * Luunes 22 De Agosto 2011 
 * No es necesario el registro de configuracion
 * se enviara para el caso de los expendios 
 * en el primer registro esta informacion
 *
lSisReg3LstConf << pSisReg3Envio;
	EnviaRegistros(pchrPtrOperacion,&lSisReg3LstConf);
*/
//SiscomEscribeLog3Qt("El Numero Reg:%d",pSisReg4Info->Registros());
EnviaVersionProtocolo();
EnviaNumeroRegistros(pSisReg4Info->Registros());
  for(lSisReg3LstLstEnvio=pSisReg4Info->first();
      lSisReg3LstLstEnvio;
      lSisReg3LstLstEnvio=pSisReg4Info->next())
  {
     for(lSisReg3LstEnvio=lSisReg3LstLstEnvio->first();
         lSisReg3LstEnvio;
	 lSisReg3LstEnvio=lSisReg3LstLstEnvio->next())
	 EnviaRegistros(0,pchrPtrOperacion,lSisReg3LstEnvio);
  }
/*
 * Falta Leer la Respuesta 
 *
 */
ObtenRespuesta(pSisReg4Reg);
}
void SiscomOperaciones3::SiscomEnvia(const char *pchrPtrOperacion,
				     SiscomRegistro3 *pSisReg3Envio,
				     SiscomRegistro3Lst *pSisReg3LstRespuesta)
{
SiscomRegistro3Lst lSisReg3LstEnvio;

lSisReg3LstEnvio << pSisReg3Envio;
EnviaVersionProtocolo();
EnviaRegistros(pchrPtrOperacion,&lSisReg3LstEnvio);
if(pSisReg3LstRespuesta)
ObtenRespuesta(pSisReg3LstRespuesta);
}


void SiscomOperaciones3::SiscomEnvia(const char *pchrPtrOperacion,
				     SiscomRegistro3 *pSisReg3Envio,
				     SiscomRegistro3LstLst *pSisReg3LstLstRespuesta)
{
SiscomRegistro3Lst lSisReg3LstEnvio;
lSisReg3LstEnvio << pSisReg3Envio;
EnviaVersionProtocolo();
EnviaRegistros(pchrPtrOperacion,&lSisReg3LstEnvio);
if(pSisReg3LstLstRespuesta)
ObtenRespuesta(pSisReg3LstLstRespuesta);
}

void SiscomOperaciones3::SiscomEnvia(const char *pchrPtrOperacion,
				     SiscomRegistro3Lst *pSRegistro3LstRes,
				     const char *pchrPtrFormato,
				     ...)
{
va_list lzArgumentos;
const char *lzCadenaFormato=pchrPtrFormato;
char  lzMen[1024];
        char *lzParametroChar;
        int liParametroInt;
        float lfParametroFloat;
        int liPos=0;
SiscomRegistro3Lst lSReg3LstConsulta;
        va_start(lzArgumentos,pchrPtrFormato);
        do
        {
                if(*lzCadenaFormato=='%')
                {
                        *lzCadenaFormato++;
                        switch(*lzCadenaFormato)
                        {
                          case 's':
                                lzMen[liPos]=0;
                                lzParametroChar=va_arg(lzArgumentos,
                                                       char *);
				lSReg3LstConsulta  << 
				   new SiscomParametroConsulta3(lzParametroChar);
                                liPos=0;

                          break;
                          case 'f':
                                lzMen[liPos]=0;
                                lfParametroFloat=(float )va_arg(lzArgumentos,
                                                                double);
                                liPos=0;
                          break;
                          case 'd':
                                lzMen[liPos]=0;
                                liParametroInt=(int )va_arg(lzArgumentos,
                                                            int);
                                liPos=0;
                          break;
			  case 'x':
                                lzMen[liPos]=0;
                                lzParametroChar=(char *)va_arg(lzArgumentos,
                                                                char *);
                                liPos=0;
                          break;
                        }
                     lzMen[0]=0;
                 }
            else
                {
                        lzMen[liPos]=*lzCadenaFormato;
                        liPos++;
                }
         }while(*lzCadenaFormato++);
        lzMen[liPos]=0;
        va_end(lzArgumentos);
EnviaVersionProtocolo();
EnviaRegistros(pchrPtrOperacion,
		&lSReg3LstConsulta);	
ObtenRespuesta(pSRegistro3LstRes);
lSReg3LstConsulta.SiscomElimina();
}

void SiscomOperaciones3::SiscomEnvia(const char *pchrPtrOperacion,
				     SiscomRegistro4 *pSisReg4Respuesta,
				     const char *pchrPtrFormato,
				     ...)
{
va_list lzArgumentos;
const char *lzCadenaFormato=pchrPtrFormato;
char  lzMen[1024];
        char *lzParametroChar;
        int liParametroInt;
        float lfParametroFloat;
        int liPos=0;
SiscomRegistro3Lst lSReg3LstConsulta;
        va_start(lzArgumentos,pchrPtrFormato);
        do
        {
                if(*lzCadenaFormato=='%')
                {
                        *lzCadenaFormato++;
                        switch(*lzCadenaFormato)
                        {
                          case 's':
                                lzMen[liPos]=0;
                                lzParametroChar=va_arg(lzArgumentos,
                                                       char *);
				lSReg3LstConsulta  << 
				   new SiscomParametroConsulta3(lzParametroChar);
                                liPos=0;

                          break;
                          case 'f':
                                lzMen[liPos]=0;
                                lfParametroFloat=(float )va_arg(lzArgumentos,
                                                                double);
                                liPos=0;
                          break;
                          case 'd':
                                lzMen[liPos]=0;
                                liParametroInt=(int )va_arg(lzArgumentos,
                                                            int);
                                liPos=0;
                          break;
			  case 'x':
                                lzMen[liPos]=0;
                                lzParametroChar=(char *)va_arg(lzArgumentos,
                                                                char *);
                                liPos=0;
                          break;
                        }
                     lzMen[0]=0;
                 }
            else
                {
                        lzMen[liPos]=*lzCadenaFormato;
                        liPos++;
                }
         }while(*lzCadenaFormato++);
        lzMen[liPos]=0;
        va_end(lzArgumentos);
EnviaVersionProtocolo();
EnviaRegistros(pchrPtrOperacion,
		&lSReg3LstConsulta);	
ObtenRespuesta(pSisReg4Respuesta);
lSReg3LstConsulta.SiscomElimina();
}
/* Viernes 6 de Septiembre del 2013 
 * Se agrega la funcion que permite desde la cadena de formato
 * formar un registro definido y pasarle sus valores correspondientes
 * para los casos en los que sea necesario mas que enviar un registro
 * y no se haya definido una clase.
 * "%s[FechaIni]%s[FechaFin]%s[IdServidor]"
 */
void SiscomOperaciones3::SiscomEnvia2(const char *pchrPtrOperacion,
				      SiscomRegistro4 *pSisReg4Respuesta,
				      const char *pchrPtrFormato,
				      ...)
{
char lchrArrNmbCampo[512];
va_list lzArgumentos;
const char *lzCadenaFormato=pchrPtrFormato;
char  lzMen[1024];
        char *lzParametroChar;
        int liParametroInt;
        float lfParametroFloat;
        int liPos=0;
SiscomRegistro3Lst lSReg3LstConsulta;
SiscomRegistro3 *lSisReg3Registro;
lSisReg3Registro=new SiscomRegistro3;
        va_start(lzArgumentos,pchrPtrFormato);
        do
        {
                if(*lzCadenaFormato=='%')
                {
                        *lzCadenaFormato++;
                        switch(*lzCadenaFormato)
                        {
                          case 's':
                                lzMen[liPos]=0;
                                lzParametroChar=va_arg(lzArgumentos,char *);
				 lzCadenaFormato++;
				 lzCadenaFormato=(char *)SiscomDesarrollo3Qt::CadenaEntreSeparadores(lzCadenaFormato,'[',']',lchrArrNmbCampo);
				  (*lSisReg3Registro) << new SiscomCampo3(lchrArrNmbCampo,lzParametroChar);
                                liPos=0;

                          break;
                          case 'f':
                                lzMen[liPos]=0;
                                lfParametroFloat=(float )va_arg(lzArgumentos,
                                                                double);
                                liPos=0;
                          break;
                          case 'd':
                                lzMen[liPos]=0;
                                liParametroInt=(int )va_arg(lzArgumentos,
                                                            int);
                                liPos=0;
                          break;
			  case 'x':
                                lzMen[liPos]=0;
                                lzParametroChar=(char *)va_arg(lzArgumentos,
                                                                char *);
                                liPos=0;
                          break;
                        }
                     lzMen[0]=0;
                 }
            else
                {
                        lzMen[liPos]=*lzCadenaFormato;
                        liPos++;
                }
         }while(*lzCadenaFormato++);
        lzMen[liPos]=0;
        va_end(lzArgumentos);
lSReg3LstConsulta << lSisReg3Registro;
EnviaVersionProtocolo();
EnviaRegistros(pchrPtrOperacion,
		&lSReg3LstConsulta);	
ObtenRespuesta(pSisReg4Respuesta);
lSReg3LstConsulta.SiscomElimina();
}

void SiscomOperaciones3::SiscomEnvia2(const char *pchrPtrOperacion,
				      SiscomRegistro3Lst *pSisReg3LstRespuesta,
				      const char *pchrPtrFormato,
				      ...)
{
char lchrArrNmbCampo[512];
va_list lzArgumentos;
const char *lzCadenaFormato=pchrPtrFormato;
char  lzMen[1024];
        char *lzParametroChar;
        int liParametroInt;
        float lfParametroFloat;
        int liPos=0;
SiscomRegistro3Lst lSReg3LstConsulta;
SiscomRegistro3 *lSisReg3Registro;
lSisReg3Registro=new SiscomRegistro3;
        va_start(lzArgumentos,pchrPtrFormato);
        do
        {
                if(*lzCadenaFormato=='%')
                {
                        *lzCadenaFormato++;
                        switch(*lzCadenaFormato)
                        {
                          case 's':
                                lzMen[liPos]=0;
                                lzParametroChar=va_arg(lzArgumentos,char *);
				 lzCadenaFormato++;
				 lzCadenaFormato=(char *)SiscomDesarrollo3Qt::CadenaEntreSeparadores(lzCadenaFormato,'[',']',lchrArrNmbCampo);
				  (*lSisReg3Registro) << new SiscomCampo3(lchrArrNmbCampo,lzParametroChar);
                                liPos=0;

                          break;
                          case 'f':
                                lzMen[liPos]=0;
                                lfParametroFloat=(float )va_arg(lzArgumentos,
                                                                double);
                                liPos=0;
                          break;
                          case 'd':
                                lzMen[liPos]=0;
                                liParametroInt=(int )va_arg(lzArgumentos,
                                                            int);
                                liPos=0;
                          break;
			  case 'x':
                                lzMen[liPos]=0;
                                lzParametroChar=(char *)va_arg(lzArgumentos,
                                                                char *);
                                liPos=0;
                          break;
                        }
                     lzMen[0]=0;
                 }
            else
                {
                        lzMen[liPos]=*lzCadenaFormato;
                        liPos++;
                }
         }while(*lzCadenaFormato++);
        lzMen[liPos]=0;
        va_end(lzArgumentos);
lSReg3LstConsulta << lSisReg3Registro;
EnviaVersionProtocolo();
EnviaRegistros(pchrPtrOperacion,
		&lSReg3LstConsulta);	
ObtenRespuesta(pSisReg3LstRespuesta);
lSReg3LstConsulta.SiscomElimina();
}

void SiscomOperaciones3::SiscomEnvia(const char *pchrPtrOperacion,
				     SiscomRegistro3Lst *pSRegistro3Lst,
				     SiscomRegistro3Lst *pSRegistro3LstRes)
{
	EnviaVersionProtocolo();
	EnviaRegistros(pchrPtrOperacion,pSRegistro3Lst);
	ObtenRespuesta(pSRegistro3LstRes);
			
}

void SiscomOperaciones3::SiscomEnvia(const char *pchrPtrOperacion,
				     SiscomRegistro3Lst *pSRegistro3Lst,
				     SiscomRegistro4 *pSisReg4Resp)
{
	EnviaVersionProtocolo();
	EnviaRegistros(pchrPtrOperacion,pSRegistro3Lst);
	ObtenRespuesta(pSisReg4Resp);
}
void SiscomOperaciones3::SiscomEnvia(const char *pchrPtrOperacion,
				     SiscomRegistro3Lst *pSRegistro3LstRes)
{
	EnviaVersionProtocolo();
	EnviaRegistros(pchrPtrOperacion,pSRegistro3LstRes);
	pSRegistro3LstRes->SiscomElimina();
	ObtenRespuesta(pSRegistro3LstRes);
}
void SiscomOperaciones3::EnviaRegistros(const char *pchrPtrOperacion,
				     SiscomRegistro3Lst *pSRegistro3Lst)
{
SiscomRegistro3 *lSRegistro3;
SiscomCampo3 *lSCampo3;
char *lchrPtrEnvio;
int lintNumCampo=0;
int lintContador;
EnviaNumeroRegistros(pSRegistro3Lst->count());
for(lSRegistro3=pSRegistro3Lst->first();
    lSRegistro3;
    lSRegistro3=pSRegistro3Lst->next())
{
  InicioRegistro(pchrPtrOperacion,&lchrPtrEnvio);
  for(lSCampo3=lSRegistro3->SiscomColocaPrimerCampo(),
      lintContador=0;
      lSCampo3;
      lSCampo3=lSRegistro3->SiscomSiguienteCampo(),
      lintContador++)
      AnexaCampoProtocolo2(
      		lSCampo3->SiscomNmbCampo(),
		&lintNumCampo,
		lSCampo3->SiscomDato(),
		&lchrPtrEnvio);
  NumeroCamposAlProtocolo(lintContador,lchrPtrEnvio);
  EnviaCadena(lchrPtrEnvio);
  free(lchrPtrEnvio);
}
}

void SiscomOperaciones3::EnviaRegistros(int,
				     const char *pchrPtrOperacion,
				     SiscomRegistro3Lst *pSRegistro3Lst)
{
SiscomRegistro3 *lSRegistro3;
SiscomCampo3 *lSCampo3;
char *lchrPtrEnvio;
int lintNumCampo=0;
int lintContador;
for(lSRegistro3=pSRegistro3Lst->first();
    lSRegistro3;
    lSRegistro3=pSRegistro3Lst->next())
{
  InicioRegistro(pchrPtrOperacion,&lchrPtrEnvio);
  for(lSCampo3=lSRegistro3->SiscomColocaPrimerCampo(),
      lintContador=0;
      lSCampo3;
      lSCampo3=lSRegistro3->SiscomSiguienteCampo(),
      lintContador++)
      AnexaCampoProtocolo2(
      		lSCampo3->SiscomNmbCampo(),
		&lintNumCampo,
		lSCampo3->SiscomDato(),
		&lchrPtrEnvio);
  NumeroCamposAlProtocolo(lintContador,lchrPtrEnvio);
  EnviaCadena(lchrPtrEnvio);
  free(lchrPtrEnvio);
}
}

void SiscomOperaciones3::SiscomCopiaProtocoloCadena(const char *pchrPtrOperacion,
				     		    SiscomRegistro3Lst *pSRegistro3Lst,
						    char *pchrPtrProtocolo)
{
SiscomRegistro3 *lSRegistro3;
SiscomCampo3 *lSCampo3;
char *lchrPtrEnvio;
char lchrArrNumRegistros[12];
int lintNumCampo=0;
int lintContador;

NumeroRegistros(pSRegistro3Lst->count(),lchrArrNumRegistros);
strcpy(pchrPtrProtocolo,lchrArrNumRegistros);
for(lSRegistro3=pSRegistro3Lst->first();
    lSRegistro3;
    lSRegistro3=pSRegistro3Lst->next())
{
  InicioRegistro(pchrPtrOperacion,&lchrPtrEnvio);
  for(lSCampo3=lSRegistro3->SiscomColocaPrimerCampo(),
      lintContador=0;
      lSCampo3;
      lSCampo3=lSRegistro3->SiscomSiguienteCampo(),
      lintContador++)
      AnexaCampoProtocolo2(
      		lSCampo3->SiscomNmbCampo(),
		&lintNumCampo,
		lSCampo3->SiscomDato(),
		&lchrPtrEnvio);
  NumeroCamposAlProtocolo(lintContador,lchrPtrEnvio);
  SiscomEscribeLog3Qt("%s",lchrPtrEnvio);
  strcat(pchrPtrProtocolo,lchrPtrEnvio);
  free(lchrPtrEnvio);
}
}


char *SiscomOperaciones3::LeeDato(const char *pchrPtrCadena,
				 int pintNCaracteres,
				 int *pintPtrDato)
{
char lchrArrDato[128];
char *lchrPtrRegreso;
	lchrPtrRegreso=LeeDato(pchrPtrCadena,pintNCaracteres,lchrArrDato);
	*pintPtrDato=atoi(lchrArrDato);

	return lchrPtrRegreso;
}

char *SiscomOperaciones3::LeeDato(const char *pchrPtrCadena,
				 int pintNCaracteres,
				 char *pchrPtrDato)
{

	strncpy(pchrPtrDato,pchrPtrCadena,pintNCaracteres);
	pchrPtrDato[pintNCaracteres]=0;
	return (char *)pchrPtrCadena+pintNCaracteres;

}



void SiscomOperaciones3::LeeDato(int pintNCaracteres,
				 char *pchrPtrDato)
{
int lintContador;

	for(lintContador=0;
	    lintContador<pintNCaracteres;
	    lintContador++)
	 read(intSocket,pchrPtrDato+lintContador,1);
 pchrPtrDato[lintContador]=0;
}
void SiscomOperaciones3::LeeDato(int pintNCaracteres,
				 int *pintPtrDato)
{
char lchrArrDato[12];
	LeeDato(pintNCaracteres,lchrArrDato);
	*pintPtrDato=atoi(lchrArrDato);
}
char *SiscomOperaciones3::LeeDato(const char *pchrPtrCadena,
				  int pintNCaracteres,
				  char **pchrPtrDato)
{

	*pchrPtrDato=(char *)malloc(pintNCaracteres+1);
	pchrPtrCadena=LeeDato(pchrPtrCadena,pintNCaracteres,*pchrPtrDato);	
	return (char *)pchrPtrCadena;
}
void SiscomOperaciones3::LeeDato(int pintNCaracteres,
				 char **pchrPtrDato)
{
	*pchrPtrDato=(char *)malloc(pintNCaracteres+1);
	LeeDato(pintNCaracteres,*pchrPtrDato);
}

void SiscomOperaciones3::ObtenRespuesta(SiscomRegistro3Lst *pSRegistro3Lst)
{
int lintNRegRes;
int lintContador;
int lintNumCampos;
int lintCampos;

int lintNumCampo;
char *lchrPtrNmbCampo;
char *lchrPtrCampo;
char *lchrPtrRespuesta;
SiscomRegistro3 *lSRegistro3;
LeeDato(6,&lintNRegRes);
for(lintContador=0;
    lintContador<lintNRegRes;
    lintContador++)
{
    ObtenNombreRespuesta(&lchrPtrRespuesta);
    LeeDato(4,&lintNumCampos);
    lSRegistro3=new SiscomRegistro3;
    for(lintCampos=0;
        lintCampos<lintNumCampos;
	lintCampos++)
    {
	 ObtenCampoProtocolo(&lintNumCampo,
	 	    &lchrPtrNmbCampo,
		    &lchrPtrCampo);
	(*lSRegistro3) << new SiscomCampo3(lchrPtrNmbCampo,lchrPtrCampo);
    }
    (*pSRegistro3Lst) << lSRegistro3;
    free(lchrPtrRespuesta); 
}
}

void SiscomOperaciones3::ObtenRespuesta(SiscomRegistro4 *pSisReg4Respuesta)
{
int lintNRegRes;
int lintContador;
int lintNumCampos;
int lintCampos;

int lintNumCampo;
char *lchrPtrNmbCampo;
char *lchrPtrCampo;
char *lchrPtrRespuesta;
SiscomRegistro3 *lSRegistro3;
LeeDato(6,&lintNRegRes);
for(lintContador=0;
    lintContador<lintNRegRes;
    lintContador++)
{
    ObtenNombreRespuesta(&lchrPtrRespuesta);
    LeeDato(4,&lintNumCampos);
    lSRegistro3=new SiscomRegistro3;
    for(lintCampos=0;
        lintCampos<lintNumCampos;
	lintCampos++)
    {
	 ObtenCampoProtocolo(&lintNumCampo,
	 	    &lchrPtrNmbCampo,
		    &lchrPtrCampo);
	(*lSRegistro3) << new SiscomCampo3(lchrPtrNmbCampo,lchrPtrCampo);
    }
    (*pSisReg4Respuesta) << lSRegistro3;
    free(lchrPtrRespuesta);
}
}
void SiscomOperaciones3::SiscomObtenNombreRespuesta(char **pchrPtrRespuesta,
					int *pintPtrNRegistros)
{
int lintNRegRes;
int lintContador;
int lintNumCampos;
int lintCampos;

int lintNumCampo;
char *lchrPtrNmbCampo;
char *lchrPtrCampo;
char *lchrPtrRespuesta;
SiscomRegistro3 *lSRegistro3;
LeeDato(6,pintPtrNRegistros);
ObtenNombreRespuesta(pchrPtrRespuesta);
}
void SiscomOperaciones3::SiscomObtenRespuesta(int pintNRegistros,
					SiscomRegistro4 *pSisReg4Respuesta)
{
int lintNRegRes;
int lintContador;
int lintNumCampos;
int lintCampos;

int lintNumCampo;
char *lchrPtrNmbCampo;
char *lchrPtrCampo;
char *lchrPtrRespuesta;
SiscomRegistro3 *lSRegistro3;
pSisReg4Respuesta->SiscomAgregaRegistro();
for(lintContador=0;
    lintContador<pintNRegistros;
    lintContador++)
{
    LeeDato(4,&lintNumCampos);
    lSRegistro3=new SiscomRegistro3;
    for(lintCampos=0;
        lintCampos<lintNumCampos;
	lintCampos++)
    {
	 ObtenCampoProtocolo(&lintNumCampo,
	 	    &lchrPtrNmbCampo,
		    &lchrPtrCampo);
	(*lSRegistro3) << new SiscomCampo3(lchrPtrNmbCampo,lchrPtrCampo);
    }
    ObtenNombreRespuesta(&lchrPtrRespuesta);
    pSisReg4Respuesta->AgregaDato(lSRegistro3);
    free(lchrPtrRespuesta);
}
}
void SiscomOperaciones3::SiscomObtenRespuesta(int pintNRegistros,
					SiscomRegistro3Lst *pSRegistro3Lst)
{
int lintContador;
int lintNumCampos;
int lintCampos;

int lintNumCampo;
char *lchrPtrNmbCampo;
char *lchrPtrCampo;
char *lchrPtrRespuesta;
SiscomRegistro3 *lSRegistro3;
for(lintContador=0;
    lintContador<pintNRegistros;
    lintContador++)
{
    ObtenNombreRespuesta(&lchrPtrRespuesta);
    LeeDato(4,&lintNumCampos);
    lSRegistro3=new SiscomRegistro3;
    for(lintCampos=0;
        lintCampos<lintNumCampos;
	lintCampos++)
    {
	 ObtenCampoProtocolo(&lintNumCampo,
	 	    &lchrPtrNmbCampo,
		    &lchrPtrCampo);
	(*lSRegistro3) << new SiscomCampo3(lchrPtrNmbCampo,lchrPtrCampo);
    }
    (*pSRegistro3Lst) << lSRegistro3;
    free(lchrPtrRespuesta);
}

}
void SiscomOperaciones3::ObtenRespuesta(SiscomRegistro3LstLst *pSRegistro3LstLst)
{
int lintNRegRes;
int lintContador;
int lintNumCampos;
int lintCampos;

int lintNumCampo;
char *lchrPtrNmbCampo;
char *lchrPtrCampo;
char *lchrPtrRespuesta;
char lchrArrRegistro[256];
SiscomRegistro3 *lSRegistro3;
LeeDato(6,&lintNRegRes);
SiscomRegistro3Lst lSisReg3LstReg;

lchrArrRegistro[0]=0;
for(lintContador=0;
    lintContador<lintNRegRes;
    lintContador++)
{
    ObtenNombreRespuesta(&lchrPtrRespuesta);
    LeeDato(4,&lintNumCampos);
    lSRegistro3=new SiscomRegistro3;
    for(lintCampos=0;
        lintCampos<lintNumCampos;
	lintCampos++)
    {
	 ObtenCampoProtocolo(&lintNumCampo,
	 	    &lchrPtrNmbCampo,
		    &lchrPtrCampo);
	(*lSRegistro3) << new SiscomCampo3(lchrPtrNmbCampo,lchrPtrCampo);
	strcat(lchrArrRegistro,lchrPtrNmbCampo);
    }
    pSRegistro3LstLst->AgregaRegistro(lchrArrRegistro,lSRegistro3);
    lchrArrRegistro[0]=0;
    free(lchrPtrRespuesta);
}
}

void SiscomOperaciones3::SiscomFormaRegistrosCadena(const char *pchrPtrCadena,
						    SiscomRegistro3Lst *pSRegistro3Lst)
{
int lintNRegRes;
int lintContador;
int lintNumCampos;
int lintCampos;

int lintNumCampo;
char *lchrPtrNmbCampo;
char *lchrPtrCampo;
char *lchrPtrRespuesta;

SiscomRegistro3 *lSRegistro3;
/*
LeeDato(6,&lintNRegRes);

*/
pchrPtrCadena=LeeDato(pchrPtrCadena,
	6,
	&lintNRegRes);
for(lintContador=0;
    lintContador<lintNRegRes;
    lintContador++)
{
    /*
    ObtenNombreRespuesta(&lchrPtrRespuesta);
    */
    pchrPtrCadena=ObtenNombreRespuesta(pchrPtrCadena,&lchrPtrRespuesta);
    /*
    LeeDato(4,&lintNumCampos);

    */
    pchrPtrCadena=LeeDato(pchrPtrCadena,4,&lintNumCampos);
    lSRegistro3=new SiscomRegistro3;
    for(lintCampos=0;
        lintCampos<lintNumCampos;
	lintCampos++)
    {
	 pchrPtrCadena=ObtenCampoProtocolo(pchrPtrCadena,
	 	    &lintNumCampo,
	 	    &lchrPtrNmbCampo,
		    &lchrPtrCampo);
	(*lSRegistro3) << new SiscomCampo3(lchrPtrNmbCampo,lchrPtrCampo);
    }
    (*pSRegistro3Lst) << lSRegistro3;
    free(lchrPtrRespuesta);
}
}
char *SiscomOperaciones3::ObtenCampoProtocolo(const char *pchrPtrCadena,
					     int *pintPtrNumCampo,
					     char **pchrPtrNmbCampo,
					     char **pchrPtrCampo)
{
int lintTamCampo;
char *lchrPtrPaso=(char *)pchrPtrCadena;

	lchrPtrPaso=LeeDato(lchrPtrPaso,4,&lintTamCampo);
	lchrPtrPaso=LeeDato(lchrPtrPaso,lintTamCampo,pchrPtrNmbCampo);
	lchrPtrPaso=LeeDato(lchrPtrPaso,4,&lintTamCampo);
	lchrPtrPaso=LeeDato(lchrPtrPaso,lintTamCampo,pintPtrNumCampo);
	lchrPtrPaso=LeeDato(lchrPtrPaso,4,&lintTamCampo);
	lchrPtrPaso=LeeDato(lchrPtrPaso,lintTamCampo,pchrPtrCampo);
	return lchrPtrPaso;
}
void SiscomOperaciones3::ObtenCampoProtocolo(int *pintPtrNumCampo,
					     char **pchrPtrNmbCampo,
					     char **pchrPtrCampo)
{
int lintTamCampo;
	LeeDato(4,&lintTamCampo);
	LeeDato(lintTamCampo,pchrPtrNmbCampo);
	LeeDato(4,&lintTamCampo);
	LeeDato(lintTamCampo,pintPtrNumCampo);
	LeeDato(4,&lintTamCampo);
	LeeDato(lintTamCampo,pchrPtrCampo);
}
char *SiscomOperaciones3::ObtenNombreRespuesta(const char *pchrPtrCadena,
					      char **pchrPtrNmbRespuesta)
{
int lintTamRes;
LeeDato(pchrPtrCadena,4,&lintTamRes);
	*pchrPtrNmbRespuesta=(char *)malloc(lintTamRes+1);
	LeeDato(pchrPtrCadena+4,lintTamRes,*pchrPtrNmbRespuesta);
}
void SiscomOperaciones3::ObtenNombreRespuesta(char **pchrPtrNmbRespuesta)
{
int lintTamRes;
	LeeDato(4,&lintTamRes);
	*pchrPtrNmbRespuesta=(char *)malloc(lintTamRes+5);
	LeeDato(lintTamRes,*pchrPtrNmbRespuesta);
}
