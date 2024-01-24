#include <SiscomVentanaPrincipal.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomArchivoIni.h>
#include <SiscomQAction.h>
#include <SiscomModulo.h>
#include <SiscomCpuInfo3.h>
#include <qmenubar.h>
#include <qapplication.h>
#include <qvbox.h>
#include <qworkspace.h>
#include <qmessagebox.h>

#include <stdlib.h>
#include <dlfcn.h>

class QWorkspaceChild;
SiscomVentanaPrincipal::SiscomVentanaPrincipal(QApplication *pQAppPrincipal,
					       QWidget *pQWParent,
					       const char *pchrPtrName,
					       WFlags pWFlags):
				QMainWindow(pQWParent,pchrPtrName,pWFlags),
				QAppPrincipal(pQAppPrincipal),
				QWParent(pQWParent),
				intIdsVentanas(100),
				QWSATrabajo(0)
{
}

SiscomVentanaPrincipal::SiscomVentanaPrincipal(QWidget *pQWParent,
					       const char *pchrPtrName,
					       WFlags pWFlags):
				QMainWindow(pQWParent,pchrPtrName,pWFlags),
				QWParent(pQWParent),
				intIdsVentanas(100),
				QWSATrabajo(0)
{
}
void SiscomVentanaPrincipal::ConectaSlots()
{
  connect(QPMVentanas,
  	  SIGNAL(activated(int)),
	  SLOT(SlotSeleccionaVentana(int)));
}
void SiscomVentanaPrincipal::FirmaAlSistema()
{
SiscomEscribeLog3Qt("");
}
void SiscomVentanaPrincipal::AccesoSiscomElectronica()
{
}
QApplication *SiscomVentanaPrincipal::PrincipalQt()
{
	return QAppPrincipal;
}
void SiscomVentanaPrincipal::AccesandoSistema()
{
const char *lchrPtrAccesoSistema=getenv("TipoAccesoSistema");
if(lchrPtrAccesoSistema &&
   !strcmp(lchrPtrAccesoSistema,"AccesoSistema"))
AccesoSiscomElectronica();
else
FirmaAlSistema();
}
void SiscomVentanaPrincipal::SiscomIniciaVentana()
{
/*
   SiscomValidaCpuInfo();

*/
   SiscomCargaBibliotecaIconos();
   SiscomPonAplicacion();

	/* Queretaro a 4 de diciembre del 2015 
	 * Integro en el acceso al sistema la 
	 * funcionalidad que permite agrupar 
	 * los expendios por tipo de expendio
	 */
   AccesandoSistema();
   ArchivoConfiguracionModulos();
   SisArchIni->Clases().ClasesPorNombre("MenuPrincipal",SisClassIniMenus);
   SisArchIni->Clases().ClasesPorNombre("Argumentos",SisClassIniArgs);
   SisClassIni=SisArchIni->Clases();
   CreaMenus();
   AreaTrabajo();
   SiscomIniciaMenuVentanas();
   ConectaSlots();
   SiscomIniciaSeguridad();
   SiscomIconoAplicacion();
   show();
   if(vidPtrIconos)
   dlclose(vidPtrIconos);
}

void SiscomVentanaPrincipal::ArchivoConfiguracionModulos()
{
const char *lchrPtrArchivoIni=getenv("ArchivoConfiguracionModulos");
char lchrArrArchivoIni[1024];
sprintf(lchrArrArchivoIni,"%s",lchrPtrArchivoIni);

if(lchrPtrArchivoIni)
{
SiscomEscribeLog3Qt("Se Cargaran los modulos:%s",
		     lchrArrArchivoIni);
SisArchIni=new SiscomArchivoIni(lchrArrArchivoIni);

}
else
SiscomEscribeLog3Qt("No se ha definido la variable ArchivoConfiguracionModulos o DirSistema");

}
void SiscomVentanaPrincipal::CreaMenus()
{
QPopupMenu *lQPMOpciones;
SiscomClaseIni *lSisClasIni;
char lchrArrNmbMenu[256];
char lchrArrNmbPrincipal[256];
char lchrArrTexto[256];
SiscomVariableIni *lSisVarIni;
int lintNMenu;
for(lSisClasIni=SisClassIniMenus.first(),
lintNMenu=0;
    lSisClasIni;
    lSisClasIni=SisClassIniMenus.next(),
    lintNMenu++)
{
   DatosMenu(lSisClasIni,lchrArrNmbMenu,lchrArrTexto);
  lQPMOpciones=CreaMenu(lchrArrNmbMenu,lchrArrTexto);
  menuBar()->insertItem(lchrArrTexto,lQPMOpciones);
}
}
void SiscomVentanaPrincipal::DatosMenu(SiscomClaseIni *pSisClasIni,
				       char *pchrPtrNmbMenu,
				       char *pchrPtrTexto)
{
char lchrArrClase[256];
char lchrArrPrincipal[256];
	pSisClasIni->Clase(lchrArrClase);
	SiscomDesarrollo3Qt::CadenasPorSeparador(lchrArrClase,
						 '.',
						 lchrArrPrincipal,
						 pchrPtrNmbMenu);
  pSisClasIni->Propiedad("Texto")->Valor(pchrPtrTexto);
}
SiscomQAction *SiscomVentanaPrincipal::CreaOpcion(
				SiscomClaseIni *pSisClasIni)
{
char lchrArrNmbPopupMenu[256];
char lchrArrNmbAction[256];
char lchrArrNmbClase[256];
char lchrArrTexto[256];
SiscomQAction *lSisQAOpcion;
SiscomVariableIni *lSisVarIni;
pSisClasIni->Clase(lchrArrNmbClase);
SiscomDesarrollo3Qt::CadenasPorSeparador(lchrArrNmbClase,
					 '.',
					 lchrArrNmbPopupMenu,
					 lchrArrNmbAction);
lSisQAOpcion=new SiscomQAction(this,lchrArrNmbAction,vidPtrIconos);
AsignaTexto(lSisQAOpcion,pSisClasIni);
AsignaIcono(lSisQAOpcion,pSisClasIni);
AsignaModulo(lSisQAOpcion,pSisClasIni);
AsignaFuncion(lSisQAOpcion,pSisClasIni);
lSisQAOpcion->SiscomMuestraIcono();
return lSisQAOpcion;
}

void SiscomVentanaPrincipal::CreaOpcion(SiscomClaseIni *pSisClasIni,
					QPopupMenu *pQPMenu)
{
char lchrArrNmbPopupMenu[256];
char lchrArrNmbAction[256];
char lchrArrNmbClase[256];
char lchrArrTexto[256];
SiscomVariableIni *lSisVarIni;
pSisClasIni->Clase(lchrArrNmbClase);
SiscomDesarrollo3Qt::CadenasPorSeparador(lchrArrNmbClase,
					 '.',
					 lchrArrNmbPopupMenu,
					 lchrArrNmbAction);

}
QPopupMenu *SiscomVentanaPrincipal::CreaMenu(const char *pchrPtrNmbMenu,
					     const char *pchrPtrTexto)
{
char lchrArrClase[256];
char lchrArrNombrePrincipal[256];
QPopupMenu *lQPMenu;
SiscomQAction *lSisQAOpcion;
SiscomClasesIni lSisClassIniMenu;
SiscomClaseIni *lSisClasIni;
    SisClassIni.ClasesPorNombre(pchrPtrNmbMenu,0,lSisClassIniMenu); 
    lQPMenu=new QPopupMenu(QWParent);
for(lSisClasIni=lSisClassIniMenu.first();
    lSisClasIni;
    lSisClasIni=lSisClassIniMenu.next())
{
  lSisQAOpcion=CreaOpcion(lSisClasIni);  
  connect(lSisQAOpcion,
  	  SIGNAL(SignalSelecciono(SiscomQAction *)),
	  SLOT(SlotSelecciono(SiscomQAction *)));
  lSisQAOpcion->addTo(lQPMenu);
}
return lQPMenu; 
}
void SiscomVentanaPrincipal::SlotSeleccionaVentana(int pintNVentana)
{
SiscomEscribeLog3Qt("La ventana:%d",pintNVentana);
if(pintNVentana==10)
{
 //AreaTrabajoSiscom()->cascade();
}
else
{
QWidget *lQWVentana=QWSATrabajo->windowList().at(pintNVentana-100);
lQWVentana->showNormal();
lQWVentana->setFocus();
}
}
void SiscomVentanaPrincipal::SlotTerminar(QWidget *pQWVentana)
{
   delete pQWVentana;
   VentanasCargadas();
}
void SiscomVentanaPrincipal::SlotActualizaMenu(const QString &pQStrTextoMenu)
{
   VentanasCargadas();
}
void  SiscomVentanaPrincipal::SlotSelecciono(SiscomQAction *pSisQASelecciono)
{
char lchrArrModulo[256];
char lchrArrFuncion[256];
SiscomModulo *lSisModulo;
QWidget *lQWOpcion;
int lintEstado=0;
QWidget *(*SiscomOpcion)(SiscomDatCom *pSisDatCom,
			 char **pchrPtrArgumentos,
			 QWidget *pQWParent,
			 const char *pchrPtrName,
			 int pintWFlags);
QWidget *lQWVentana;			 
pSisQASelecciono->ObtenModulo(lchrArrModulo);
pSisQASelecciono->ObtenFuncion(lchrArrFuncion);
SiscomEscribeLog3Qt("%s %s %s",
		    pSisQASelecciono->name(),
		    lchrArrModulo,
		    lchrArrFuncion);
SiscomArgumentosPantalla(pSisQASelecciono->name());
if(SisModulos==lchrArrModulo)
{
 lSisModulo=SisModulos.Modulo(lchrArrModulo);
 if(lSisModulo->EstadoCarga())
 {
 lSisModulo->Funcion(lchrArrFuncion,(void **)&SiscomOpcion);
 if(SiscomOpcion)
 	lQWVentana=SiscomOpcion(SisDatCom,chrPtrArgumentos,QWSATrabajo,pSisQASelecciono->name(),0);
 else
 {
 QMessageBox::information(this,
 			  "Mensaje del Sistema",
			  QString().sprintf("No se ha podido encontra %s en %s",
			  lchrArrFuncion,
			  lchrArrModulo));
 lintEstado=1;
 }
 }
 else
 {
 QMessageBox::information(this,
 			  "Mensaje del Sistema",
			  QString().sprintf("No se ha podido cargar:%s",
			  lchrArrModulo));
 lintEstado=1;
 }

}
else
{
  lSisModulo=new SiscomModulo(lchrArrModulo);
  if(lSisModulo->EstadoCarga())
  {
  lSisModulo->Funcion(lchrArrFuncion,(void **)&SiscomOpcion);
  if(SiscomOpcion)
 	lQWVentana=SiscomOpcion(SisDatCom,chrPtrArgumentos,QWSATrabajo,pSisQASelecciono->name(),0);
  else
  {
 QMessageBox::information(this,
 			  "Mensaje del Sistema",
			  QString().sprintf("No se ha podido encontra %s en %s",
			  lchrArrFuncion,
			  lchrArrModulo));
  lintEstado=1;
  }

  SisModulos << lSisModulo;
  }
  else
  {
 QMessageBox::information(this,
 			  "Mensaje del Sistema",
			  QString().sprintf("No se ha podido cargar:%s",
			  lchrArrModulo));
 lintEstado=1;
 }

}
 if(!lintEstado)
 {
 connect(lQWVentana,
 	 SIGNAL(SignalTerminar(QWidget *)),
	 SLOT(SlotTerminar(QWidget *)));

 /* Tepotzotlan Mexico 
  * Sabado 4 Julio 2020 
  * En medio del covid 
  */
 connect(lQWVentana,
 	 SIGNAL(SignalActualizaMenu(const QString &)),
	 SLOT(SlotActualizaMenu(const QString &)));


 lQWVentana->show();
 intIdsVentanas++;
 VentanasCargadas();
 }
OrganizaVentanas();
}

void SiscomVentanaPrincipal::AreaTrabajo()
{
QVBox* vb = new QVBox( this );
vb->setFrameStyle( QFrame::StyledPanel | QFrame::Sunken );
QWSATrabajo = new QWorkspace( vb ,"QWSAreaTrabajo"); 
QWSATrabajo->setScrollBarsEnabled( TRUE ); setCentralWidget( vb );
}
void SiscomVentanaPrincipal::ValorPropiedad(SiscomClaseIni *pSisClasIni,
					    const char *pchrPtrPropiedad,
					    char *pchrPtrValor)
{
SiscomVariableIni *lSisVarIni;

if((lSisVarIni=pSisClasIni->Propiedad(pchrPtrPropiedad)))
  lSisVarIni->Valor(pchrPtrValor);
else
{
 SiscomEscribeLog3Qt("No se encontrol la propiedad:%s",pchrPtrPropiedad);
}




}
void SiscomVentanaPrincipal::AsignaTexto(SiscomQAction *pSisQAOpcion,
					 SiscomClaseIni *pSisClasIni)
{
char lchrArrTexto[256];
	ValorPropiedad(pSisClasIni,"Texto",lchrArrTexto);
	pSisQAOpcion->Texto(lchrArrTexto);
}
void SiscomVentanaPrincipal::AsignaIcono(SiscomQAction *pSisQAOpcion,
					 SiscomClaseIni *pSisClasIni)
{
char lchrArrIcono[256];
	ValorPropiedad(pSisClasIni,"Icono",lchrArrIcono);
	pSisQAOpcion->Icono(lchrArrIcono);
}
void SiscomVentanaPrincipal::AsignaModulo(SiscomQAction *pSisQAOpcion,
					  SiscomClaseIni *pSisClasIni)
{
char lchrArrModulo[256];
	ValorPropiedad(pSisClasIni,"Modulo",lchrArrModulo);
	pSisQAOpcion->Modulo(lchrArrModulo);
}
void SiscomVentanaPrincipal::AsignaFuncion(SiscomQAction *pSisQAOpcion,
					   SiscomClaseIni *pSisClasIni)
{
char lchrArrFuncion[256];
	ValorPropiedad(pSisClasIni,"Funcion",lchrArrFuncion);
	pSisQAOpcion->Funcion(lchrArrFuncion);
}
void SiscomVentanaPrincipal::SiscomComunicaciones(SiscomDatCom *pSisDatCom)
{
   SisDatCom=pSisDatCom;
}
void SiscomVentanaPrincipal::SiscomArgumentos(char **pchrPtrArgumentos)
{
   chrPtrArgumentos=pchrPtrArgumentos;
}

void SiscomVentanaPrincipal::SiscomIniciaSeguridad()
{

}
SiscomDatCom *SiscomVentanaPrincipal::SiscomComunicaciones()
{
return SisDatCom;
}
void SiscomVentanaPrincipal::SiscomIniciaMenuVentanas()
{
/*
 QPMVentanas=new QPopupMenu(this);
 QPMVentanas->insertSeparator();
 menuBar()->insertItem("Ventanas",QPMVentanas);
 */
}
void SiscomVentanaPrincipal::VentanasCargadas()
{
QWidgetList lQWListVentanas=QWSATrabajo->windowList();
QWidget *lQWVentana;
int lintContador;

for(lintContador=100;
    lintContador<intIdsVentanas;
    lintContador++)
   QPMVentanas->removeItem(lintContador); 
for(lQWVentana=lQWListVentanas.first(),
    lintContador=100;
    lQWVentana;
    lQWVentana=lQWListVentanas.next(),
    lintContador++)
   QPMVentanas->insertItem(lQWVentana->caption(),lintContador); 
}

void SiscomVentanaPrincipal::UsuarioSeguridad3(SisUsuarioSeg3 *pSUSeg3Firmado)
{
   SUSeg3Firmado=pSUSeg3Firmado;
}
QWidget *SiscomVentanaPrincipal::SiscomParent()
{
	return QWParent;
}
void SiscomVentanaPrincipal::SiscomMenuVentanas(QPopupMenu *pQPMenuVentanas)
{
	QPMVentanas=pQPMenuVentanas;
	menuBar()->insertItem("Ventanas",QPMVentanas);
}
void SiscomVentanaPrincipal::SiscomArgumentosPantalla(const char *pchrPtrQAction)
{
char lchrArrNmbClase[256];
char lchrArrValor[256];
SiscomClasesIni lSisClassIni;
SiscomClaseIni *lSisClasArg;
SiscomVariableIni *lSisVarIni;
int lintPosicion;

sprintf(lchrArrNmbClase,"Argumentos.%s",pchrPtrQAction);
SisClassIniArgs.ClasesPorNombre(lchrArrNmbClase,lSisClassIni);
lSisClasArg=lSisClassIni.first();
if(lSisClasArg)
{
lSisClasArg->Muestra();
for(lSisVarIni=lSisClasArg->first();
    lSisVarIni;
    lSisVarIni=lSisClasArg->next())
{
 ObtenPosicionArgumentoValor(lSisVarIni,lchrArrValor,&lintPosicion);
 strcpy(chrPtrArgumentos[lintPosicion],lchrArrValor); 
}


}
}

void SiscomVentanaPrincipal::ObtenPosicionArgumentoValor(SiscomVariableIni *pSisVarIni,
							 char *pchrPtrValor,
							 int *pintPtrPosicion)
{
char lchrArrPosicion[10];

pSisVarIni->Nombre(lchrArrPosicion);
*pintPtrPosicion=atoi(lchrArrPosicion);
pSisVarIni->Valor(pchrPtrValor);
}

void SiscomVentanaPrincipal::SiscomValidaCpuInfo()
{
const char *lchrPtrUtilizacion=getenv("UtilizacionVentas");
const char *lchrPtrCpuInfo=getenv("CpuInfo");
SiscomCpuInfo *(*CpuInfo)();
if(lchrPtrUtilizacion &&
   lchrPtrCpuInfo)
{
SiscomEscribeLog3Qt("");
 CpuInfo=(SiscomCpuInfo *(*)())CargaFuncionBiblioteca(lchrPtrUtilizacion,
 						      lchrPtrCpuInfo);
SiscomCpuInfo lSisCpuInfoSistema("/proc/cpuinfo");
SiscomCpuInfo *lSisCpuInfo;
if(CpuInfo)
{
   lSisCpuInfo=CpuInfo();
   if(lSisCpuInfoSistema==lSisCpuInfo)
   SiscomEscribeLog3Qt("El Cpu Es Valido, ejecutando....");
   else
   {
   SiscomEscribeLog3Qt("El Cpu No es valido");
   exit(0);
   }
}
else
exit(0);
}
else
{
SiscomEscribeLog3Qt("No se definieron las variables para la validacion del Cpu");
exit(0);
}

}
void *SiscomVentanaPrincipal::CargaFuncionBiblioteca(const char *pchrPtrBiblioteca,	
						     const char *pchrPtrFuncion)
{
void *lvidPtrFuncion;
	if((vidPtrBiblioteca=dlopen(pchrPtrBiblioteca,RTLD_LAZY)))
	{
	   if((lvidPtrFuncion=dlsym(vidPtrBiblioteca,pchrPtrFuncion)))
	    return lvidPtrFuncion;
	   else
	   SiscomEscribeLog3Qt("(dlsym:%s)",dlerror());
	}
	else
	SiscomEscribeLog3Qt("(dlopen:%s)",dlerror());

return 0;
}
void SiscomVentanaPrincipal::SiscomCargaBibliotecaIconos()
{
const char *lchrPtrIconos=getenv("BibliotecaIconos");
if(lchrPtrIconos)
{
	if((vidPtrIconos=dlopen(lchrPtrIconos,RTLD_LAZY)))
	   SiscomEscribeLog3Qt("Se Carga la biblioteca con los Iconos");
	else
	SiscomEscribeLog3Qt("(dlopen:%s)",dlerror());
}
else
{
SiscomEscribeLog3Qt("NO se ha definido la variable \"BibliotecaIconos\"");
vidPtrIconos=0;
}
}

void SiscomVentanaPrincipal::SiscomIconoAplicacion()
{
const char *lchrPtrIconoAp=SisClassIni.ValorPropiedad("IconoAplicacion","Icono");
const char **(*IconoAplicacion)();
if(lchrPtrIconoAp)
{
SiscomEscribeLog3Qt("El Icono de la aplicacion:%s",lchrPtrIconoAp);
if((IconoAplicacion=(const char **(*)())dlsym(vidPtrIconos,lchrPtrIconoAp)))
   {
     SiscomEscribeLog3Qt("Se carga la funcion...");
     setIcon(QPixmap(IconoAplicacion()));
   }
}
}
void SiscomVentanaPrincipal::SiscomPonAplicacion()
{

	chrPtrAplicacion=getenv("Aplicacion");
	if(chrPtrAplicacion)
	   SiscomEscribeLog3Qt("La Aplicacion:%s",chrPtrAplicacion);
	else
	SiscomEscribeLog3Qt("No Se ha definido la variable \"Aplicacion\"");
}
const char *SiscomVentanaPrincipal::SiscomAplicacion()
{
   return chrPtrAplicacion ? chrPtrAplicacion : "Aplicacion NO Definida";

}
QWorkspace *SiscomVentanaPrincipal::AreaTrabajoSiscom()
{
  return QWSATrabajo;

}
void SiscomVentanaPrincipal::OrganizaVentanas()
{
/*
QWidgetList lQWListVentanas=QWSATrabajo->windowList();
QWidget *lQWVentana;

int lintX=10,lintY=10;
SiscomEscribeLog3Qt("Iniciando la Organizacion de ventanas");
// 800x500
for(lQWVentana=lQWListVentanas.first();
    lQWVentana;
    lQWVentana=lQWListVentanas.next())
{
    SiscomEscribeLog3Qt("%s",(const char *)lQWVentana->name());
    lQWVentana->parentWidget()->setGeometry(lintX,lintY,300,500); 
}
*/
}
