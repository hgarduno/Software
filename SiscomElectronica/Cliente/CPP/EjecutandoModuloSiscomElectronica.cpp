#include <stdio.h>
#include <dlfcn.h>
#include <qapplication.h>
#include <qfontdialog.h>

#include <SiscomRegistros3.h>
#include <zSiscomConexion.h>
#include <EmpresasN.h>

#include <EjecutandoModuloSiscomElectronica.h>
#include <zLineaComandosEjecutaModuloSe.h>

typedef void *(*InstanciaModulo)(void *,char **,void *,const char *,int);

QFont gQFTipoLetra;
FILE *gPtrFleArchivoLog;
FILE *gPtrFleArchivoLog3Qt;
void *gzSiscomConexion;

int main(int pintArgc,char **pchrPtrArgv)
{
SiscomDatCom *lSisDatCom;
bool lbReg;
zLineaComandosEjecutaModuloSe lzLCmnEjModSe(pintArgc,pchrPtrArgv);
QApplication a(pintArgc,pchrPtrArgv);
QWidget *lQWModulo;
gPtrFleArchivoLog=gPtrFleArchivoLog3Qt=stdout;
gzSiscomConexion=Conectate("127.0.0.1",5645);
CambiaLetra(&lzLCmnEjModSe,&a);
EjecutandoModulo(&lzLCmnEjModSe);
a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
return a.exec();
}
void CambiaLetra(zLineaComandosEjecutaModuloSe *pzLCmnEjModSe,QApplication *pQAppPrograma)
{
bool lbResultado;
  if(pzLCmnEjModSe->TipoLetra())
    pQAppPrograma->setFont(QFontDialog::getFont(&lbResultado));
  else
  if(pzLCmnEjModSe->SePuedeCambiarLetra())
   pQAppPrograma->setFont(QFont(pzLCmnEjModSe->Letra(),pzLCmnEjModSe->TamanoLetra()));

}
void EjecutandoModulo(zLineaComandosEjecutaModuloSe *pzLnCmnEjModSe)
{
   if(pzLnCmnEjModSe->SeCargaModulo())
    CargaModulo(pzLnCmnEjModSe->Biblioteca(),pzLnCmnEjModSe->Modulo())->show();
}
QWidget *CargaModulo(const char *pchrPtrBiblioteca,
		     const char *pchrPtrModulo)
{
void *lvidBiblioteca;
InstanciaModulo lInsModulo;
if((lvidBiblioteca=dlopen(pchrPtrBiblioteca,RTLD_LAZY)))
{
  if((lInsModulo=(InstanciaModulo )dlsym(lvidBiblioteca,pchrPtrModulo)))
  {
   SiscomDatCom *lSisDatCom;
    lSisDatCom=SiscomDatComConexion("127.0.0.1",5645);
	return (QWidget *)lInsModulo(lSisDatCom,Argumentos(),0,0,0);
  }
  else
   printf("NO Se cargo la funcion %s\n",dlerror());
}
else
{
printf("NO Se cargo la biblioteca %s \n",dlerror());
}
return 0;
}
zSiscomConexion *Conectate(const char *pchrPtrDirIp,
			   int pintPuerto)
{

return new zSiscomConexion(pchrPtrDirIp,pintPuerto);
}
char **Argumentos()
{
char **lchrPtrArgumentos;
lchrPtrArgumentos=(char **)malloc(sizeof(char *)*10);
*(lchrPtrArgumentos+0)=(char *)strdup("-1165857915");
*(lchrPtrArgumentos+1)=(char *)strdup("1180535225");
*(lchrPtrArgumentos+2)=(char *)Expendio();
*(lchrPtrArgumentos+3)=(char *)malloc(10);
*(lchrPtrArgumentos+4)=(char *)malloc(10);
*(lchrPtrArgumentos+5)=(char *)ExpendioRegistro3();
return lchrPtrArgumentos;
}
EmpresaN *Expendio()
{

return new EmpresaN("SISCOM IPN",
		    " -1165857915",
		    "IPN",
		    "5645",
		    "127.0.0.1",
		    "SiscomElectronica");
}
SiscomRegistro3 *ExpendioRegistro3()
{
SiscomRegistro3 *lSisReg3Expendio=new SiscomRegistro3;
(*lSisReg3Expendio) 						<<
new SiscomCampo3("IdExpendio",(*Expendio())["IdEmpresa"]) 	<<
new SiscomCampo3("RazonSocial",(*Expendio())["RazonSocial"]);
return lSisReg3Expendio;
}
SiscomDatCom *SiscomDatComConexion(const char *pchrPtrDirIp,int pintPuerto)
{
return new SiscomDatCom(pintPuerto,pchrPtrDirIp);
}
