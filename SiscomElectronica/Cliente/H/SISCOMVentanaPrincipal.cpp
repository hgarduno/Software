#include <SISCOMVentanaPrincipal.h>
#include <CfrmFirmaUsuario2.h>
#include <CSISCOMComunicaciones.h>

#include <GeneralBibliotecaSeguridad3.h>
#include <qpopupmenu.h>
#include <qmenubar.h>
#include <qworkspace.h>
#include <qvbox.h>
#include <qwidget.h>
#include <qaction.h>
#include <qobjectlist.h>
#include <qdir.h>
#include <qapplication.h>



#include <dlfcn.h>
SISCOMVentanaPrincipal::SISCOMVentanaPrincipal(QWidget *pQWParent,
				       const char *pchrPtrNombre,
				       WFlags pWFlags):
		QMainWindow(pQWParent,pchrPtrNombre,pWFlags),
		intUltimoIdVentanaActiva(0),
		CSisDatCom(0)
{
	CargaFirmaUsuario();
	setName("CfrmPrincipalSistemaTiendas");
	ObtenNombreArchivoConfiguracion(getenv("ArchivoConfiguracionModulos"));
	CreaDatosComunicaciones();
	CreaMenus();
	CargaArchivosDeConfiguracion();
	CreaWS();
	CargaModulos(chrPtrAConfiguracionMod);
	CargaSistemaSeguridad();
	show();

}
/* Para el apartado de los archivos de configuracion
 * se deben colocar en el menu de ventanas los archivos 
 * de configuracion, para poder seleccionar cual se 
 * recargara, para activar esta opcion se debera 
 * crear un usuario con el perfil adecuado para 
 * realizar esta operacion
 */

void SISCOMVentanaPrincipal::ObtenNombreArchivoConfiguracion(const char *pchrPtrNmbArchivo)
{
const char *lchrPtrDirectorio;

	if((lchrPtrDirectorio=getenv("DirectorioConfiguracion")) &&
	    pchrPtrNmbArchivo)
	sprintf(chrPtrAConfiguracionMod,
		"%s/%s",
		lchrPtrDirectorio,
		pchrPtrNmbArchivo);
	printf("El Nombre Del Archivo %s \n",chrPtrAConfiguracionMod);
}
void SISCOMVentanaPrincipal::CargaArchivosDeConfiguracion()
{
const char *lchrPtrDirConfiguracion=getenv("DirectorioConfiguracion") ? getenv("DirectorioConfiguracion") :".";
QDir lQDArchivos(lchrPtrDirConfiguracion);
QStringList lQSLArchivos=lQDArchivos.entryList("*.xml");
int lintContador;
	QPMVentanas->insertItem("Firmarse Al Sistema",1);
	QPMVentanas->insertSeparator();
	for(lintContador=0;lintContador<lQSLArchivos.size();lintContador++)
	 QPMVentanas->insertItem(lQSLArchivos[lintContador],20+lintContador);
	intUltimoIdMenuArchivo=20+lintContador;
	QPMVentanas->insertSeparator();
	connect(QPMVentanas,SIGNAL(activated(int)),SLOT(SlotOperacionVentanas(int)));
}
void SISCOMVentanaPrincipal::CargaFirmaUsuario()
{
/*
if(CSisDatCom)
delete CSisDatCom; 
*/
CfrmFirmaUsuario2 *lCFRMFUsuario2=new CfrmFirmaUsuario2(getenv("Aplicacion"));
CSisDatCom=lCFRMFUsuario2->ObtenDatosDeComunicaciones();
//gQFTipoLetra.fromString("Bitstream Vera Sans,14,-1,5,50,0,0,0,0,0");

}
void SISCOMVentanaPrincipal::SlotOperacionVentanas(int pintNoArchivo)
{
		if(pintNoArchivo>=20 &&
		   pintNoArchivo<=intUltimoIdMenuArchivo)
		 ReCargaConfiguracion((const char *)QPMVentanas->text(pintNoArchivo));
		if(pintNoArchivo>=60 &&
		   pintNoArchivo<=intUltimoIdVentanaActiva)
		 ActivaVentana(pintNoArchivo);
		if(pintNoArchivo==1)
		{
		 ws->closeAllWindows();
		 CargaFirmaUsuario();
		 CargaSistemaSeguridad();
		}
		
}
void SISCOMVentanaPrincipal::ActivaVentana(int pintNoIdArchivo)
{
QWidget *lQWVentana=ws->windowList().at(pintNoIdArchivo-60);

	if(lQWVentana)
	{
	   lQWVentana->showNormal();
	   lQWVentana->setFocus();
	}
}
void SISCOMVentanaPrincipal::EliminaMenuVentanasActivas()
{
int lintContador;
	for(lintContador=60;lintContador<intUltimoIdVentanaActiva;lintContador++)
	{
	 printf("SISCOMVentanaPrincipal::EliminaMenuVentanasActivas{%d}\n",lintContador);
	 QPMVentanas->removeItem(lintContador);
	}
}
void SISCOMVentanaPrincipal::MuestraVentanasActivas()
{
QWidgetList lQWVentanas=ws->windowList();
QWidget *lQWVentana;
int lintContador;
static int lintPVez=1;
	EliminaMenuVentanasActivas();	
	if(lintPVez)
	{
	QPMVentanas->insertSeparator();
	lintPVez=0;
	}
	for(lintContador=0;lintContador<lQWVentanas.count();lintContador++)
	{
		printf("SISCOMVentanaPrincipal::MuestraVentanasActivas:%d\n",
			lintContador);
		lQWVentana=lQWVentanas.at(lintContador);
		QPMVentanas->insertItem(lQWVentana->caption(),
					60+lintContador);
	}
	intUltimoIdVentanaActiva=lintContador+60;
}
void SISCOMVentanaPrincipal::SlotMuestraVentana(int pintIdVentana)
{
	printf("La Ventana Activa es %d \n",pintIdVentana);
}
void SISCOMVentanaPrincipal::EliminaModulosCargados()
{
int lintContador;
	for(lintContador=0;lintContador<QPLModulos.count();lintContador++)
	  delete QPLModulos.at(lintContador);
	QPLModulos.clear();


}
void SISCOMVentanaPrincipal::ReCargaConfiguracion(const char *pchrPtrArchivo)
{
	ObtenNombreArchivoConfiguracion(pchrPtrArchivo);	
	EliminaModulosCargados();
	CargaModulos(chrPtrAConfiguracionMod);
	CargaSistemaSeguridad();


}
void SISCOMVentanaPrincipal::CreaMenus()
{

	QPMAplicacion=new QPopupMenu(this);
	QPMEstadisticas=new QPopupMenu(this);
	QPMVentanas=new QPopupMenu(this);
	connect(QPMVentanas,
		SIGNAL(aboutToShow()),
		SLOT(SlotMuestraVentanas())); 
	menuBar()->insertItem("Manejo Clinica",QPMAplicacion);
	menuBar()->insertItem("Administracion Clinica",QPMEstadisticas);
	menuBar()->insertItem("Ventanas",QPMVentanas);
}
void SISCOMVentanaPrincipal::SlotMuestraVentanas()
{
	MuestraVentanasActivas();
}
void SISCOMVentanaPrincipal::CargaSistemaSeguridad()
{
QSiscomSeguridad3 lQSSeguridad3(this,
				CSisDatCom,
				getenv("Aplicacion"),
				CSisDatCom->ObtenUsuario(),
				"");

}
void SISCOMVentanaPrincipal::CargaModulos(const char *pchrPtrArchivo)
{
CQSiscomConfiguracionModulos lCQSConModulos(pchrPtrArchivo);
CQSiscomInfoModulosLista lCQSIMLista;
 int lintContador;
	lCQSIMLista=lCQSConModulos.ObtenListaModulos();
 for(lintContador=0;lintContador<lCQSIMLista.NumModulos();lintContador++)
 {
   CQSiscomModuloTiendas *lCQSModuloTiendas=new CQSiscomModuloTiendas(ws,0,0);
   	lCQSModuloTiendas->PonDatosModulo(lCQSIMLista[lintContador]->ObtenNombreBiblioteca(),
					  lCQSIMLista[lintContador]->ObtenNombreFuncion());
	lCQSModuloTiendas->PonMenuAlQueVa(ObtenMenuDestino(lCQSIMLista[lintContador]->ObtenNombreMenuAplicacion()));
	lCQSModuloTiendas->PonDatosComunicaciones(CSisDatCom);
	lCQSModuloTiendas->CargaModuloTiendas();
	lCQSModuloTiendas->IniciaOpcion(lCQSIMLista[lintContador]->ObtenNombreMenu(),
					lCQSIMLista[lintContador]->ObtenTextoMenu()); 
	QPLModulos.append(lCQSModuloTiendas);
 }
}
QPopupMenu *SISCOMVentanaPrincipal::ObtenMenuDestino(const char *pchrPtrNombre)
{
		if(!strcmp(pchrPtrNombre,"QPMAplicacion")) 
		 return QPMAplicacion;
		if(!strcmp(pchrPtrNombre,"QPMEstadisticas"))
		 return QPMEstadisticas;
}

void SISCOMVentanaPrincipal::CreaWS()
{
QVBox* vb = new QVBox( this );
vb->setFrameStyle( QFrame::StyledPanel | QFrame::Sunken );
ws = new QWorkspace( vb );
ws->setScrollBarsEnabled( TRUE );
setCentralWidget( vb );
}

void SISCOMVentanaPrincipal::CreaDatosComunicaciones()
{
}
CQSiscomModuloTiendas::CQSiscomModuloTiendas(QWidget *pQWParent,
					     const char *pchrPtrNombre,
				     WFlags pWFlags):
			 QWSATrabajo(pQWParent),
			 QMWModulo(0),
			 CreaModuloTiendas(0),
			 vidAncla(0)
{

}
CQSiscomModuloTiendas::~CQSiscomModuloTiendas()
{
	//dlclose(vidAncla);
	delete QAOpcion;
	if(QMWModulo)
	delete QMWModulo; 
	
}
void CQSiscomModuloTiendas::PonDatosModulo(const char *pchrPtrNmbBiblioteca,
					   const char *pchrPtrNmbFuncion)
{
	chrPtrNmbBiblioteca=pchrPtrNmbBiblioteca;
	chrPtrNmbFuncion=pchrPtrNmbFuncion;
}
void CQSiscomModuloTiendas::PonMenuAlQueVa(QPopupMenu *pQPMDatos)
{
	QPMModulo=pQPMDatos;
}
void CQSiscomModuloTiendas::CargaModuloTiendas()
{
	if(!(vidAncla=dlopen(chrPtrNmbBiblioteca,RTLD_LAZY)))
	{
	    printf("CQSiscomModuloTiendas::CargaModuloTiendas:dlopen:%s\n",
		    (chrPtrErrorDll=dlerror()));
	    return ;
	}
	else
	  if(!(CreaModuloTiendas=(QMainWindow *(*)(CSISCOMDatComunicaciones *,QWidget *,const char *,WFlags ))dlsym(vidAncla,
					  chrPtrNmbFuncion)))
	  {
	    printf("CQSiscomModuloTiendas::CargaModuloTiendas:dlsym:%s [%s]\n",
		    (chrPtrErrorDll=dlerror()),
		    chrPtrNmbFuncion);

	  }

}
void CQSiscomModuloTiendas::PonDatosComunicaciones(CSISCOMDatComunicaciones *pCSisDatCom)
{
	CSisDatCom=pCSisDatCom;
}
void CQSiscomModuloTiendas::IniciaOpcion(const char *pchrPtrNmbOpcion,
					 const char *pchrPtrTexto)
{
         QAOpcion=new QAction(QPMModulo,pchrPtrNmbOpcion);
  	  QAOpcion->setText(pchrPtrTexto);
  	  connect(QAOpcion,
		  SIGNAL(activated()),
		  SLOT(SlotCargaOpcion()));
	   QAOpcion->addTo(QPMModulo);
		  
}
void CQSiscomModuloTiendas::SlotCargaOpcion()
{
	if(CreaModuloTiendas)
	(QMWModulo=CreaModuloTiendas(CSisDatCom,QWSATrabajo,0,0))->show();
	else
	{
	  printf("Error al Cargar El Modulo %s\n",chrPtrErrorDll);
	}
}

CQSiscomInfoModulos::CQSiscomInfoModulos(const char *pchrPtrNmbBiblioteca,
					 const char *pchrPtrNmbFuncion,
					 const char *pchrPtrNmbMenu,
					 const char *pchrPtrTextoMenu,
					 const char *pchrPtrNmbMenuAplicacion):
			chrPtrNmbBiblioteca(pchrPtrNmbBiblioteca),
			chrPtrNmbFuncion(pchrPtrNmbFuncion),
			chrPtrNmbMenu(pchrPtrNmbMenu),
			chrPtrTextoMenu(pchrPtrTextoMenu),
			chrPtrNmbMenuAplicacion(pchrPtrNmbMenuAplicacion)
{

}
const char *CQSiscomInfoModulos::ObtenNombreBiblioteca()
{
	return chrPtrNmbBiblioteca;
}
const char *CQSiscomInfoModulos::ObtenNombreFuncion()
{
	return chrPtrNmbFuncion;
}
const char *CQSiscomInfoModulos::ObtenNombreMenu()
{
	return chrPtrNmbMenu;
}
const char *CQSiscomInfoModulos::ObtenTextoMenu()
{
	return chrPtrTextoMenu;
}
const char *CQSiscomInfoModulos::ObtenNombreMenuAplicacion()
{
	return chrPtrNmbMenuAplicacion;
}
CQSiscomInfoModulosLista::CQSiscomInfoModulosLista()
{

}
void CQSiscomInfoModulosLista::AnexaModulo(CQSiscomInfoModulos *pCQSIModulos)
{
	QPLInfoModulos.append(pCQSIModulos);
}
int CQSiscomInfoModulosLista::NumModulos()
{
	return QPLInfoModulos.count();
}
CQSiscomInfoModulos *CQSiscomInfoModulosLista::operator[](int pintNumReg)
{
	return QPLInfoModulos.at(pintNumReg);
}
bool CQSiscomAnalizaXMLModulos::startDocument()
{
		return true;
}
bool CQSiscomAnalizaXMLModulos::startElement(const QString &,
					     const QString &,
					     const QString &pQSNmbConf,
					     const QXmlAttributes &pQXAttributes)
{
	 if(pQSNmbConf=="MenuGeneral")
  	 chrPtrNmbMenuAplicacion=strdup((const char *)pQXAttributes.value(0));
	 if(pQSNmbConf=="Modulo")
	  chrPtrNmbModulo=strdup((const char *)pQXAttributes.value(0));
	 if(pQSNmbConf=="Funcion")
	  chrPtrNmbFuncion=strdup((const char *)pQXAttributes.value(0));
	 if(pQSNmbConf=="Menu")
	  chrPtrMenu=strdup((const char *)pQXAttributes.value(0));
	 if(pQSNmbConf=="TextoMenu")
	  chrPtrTextoMenu=strdup((const char *)pQXAttributes.value(0));
	  
		return true;
}
bool CQSiscomAnalizaXMLModulos::endElement(const QString &,
					   const QString &,
					   const QString &pQSNmbConf)
{
	if(pQSNmbConf=="MenuGeneral")
	{
/*	
		printf("AnexaModulo:%s\t%s\t%s\t%s\n",
			chrPtrNmbModulo,
			chrPtrNmbFuncion,
			chrPtrMenu,
			chrPtrTextoMenu); */
		CQSInfModLista.AnexaModulo(new CQSiscomInfoModulos(chrPtrNmbModulo,
								   chrPtrNmbFuncion,
								   chrPtrMenu,
								   chrPtrTextoMenu,
								   chrPtrNmbMenuAplicacion));
	}
	return true;
}
CQSiscomInfoModulosLista CQSiscomAnalizaXMLModulos::ObtenListaModulos()
{
	return CQSInfModLista;
}
CQSiscomConfiguracionModulos::CQSiscomConfiguracionModulos(const char *pchrPtrArchivo)
{
QFile lQArchivo(pchrPtrArchivo);
QXmlInputSource lQXISource(&lQArchivo);
QXmlSimpleReader lQXSReader;
	lQXSReader.setContentHandler(&CQSAXMLModulos);
	lQXSReader.parse(lQXISource);
}
CQSiscomInfoModulosLista CQSiscomConfiguracionModulos::ObtenListaModulos()
{
	return CQSAXMLModulos.ObtenListaModulos();
}
