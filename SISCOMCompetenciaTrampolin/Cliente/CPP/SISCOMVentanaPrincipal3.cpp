#include <SISCOMVentanaPrincipal3.h>
#include <SISCOMComunicaciones++.h>
#include <Seguridad3Protocolo2.h>

#include <qpopupmenu.h>
#include <qmenubar.h>
#include <qworkspace.h>
#include <qvbox.h>
#include <qwidget.h>
#include <qaction.h>
#include <qobjectlist.h>
#include <qdir.h>
#include <qapplication.h>
#include <qmessagebox.h>


#include <dlfcn.h>
SISCOMVentanaPrincipal::SISCOMVentanaPrincipal(QWidget *pQWParent,
				       const char *pchrPtrNombre,
				       WFlags pWFlags):
		QMainWindow(pQWParent,pchrPtrNombre,pWFlags),
		intUltimoIdVentanaActiva(0),
		SisDatCom(0)
{
/*
*/
}
void SISCOMVentanaPrincipal::SiscomIniciaVentana()
{
	CargaFirmaUsuario();
	setName("SISCOMVentanaPrincipal");
	ObtenNombreArchivoConfiguracion(getenv("ArchivoConfiguracionModulos"));
	CreaMenus();
	CargaArchivosDeConfiguracion();
	CreaWS();
	CargaModulos(chrPtrAConfiguracionMod);
	CargaModulosSinMenu();
	CargaSistemaSeguridad();
	show();


}
void SISCOMVentanaPrincipal::CargaModulosSinMenu()
{
CQSiscomModuloTiendas *lCQSMTiendas;

for(lCQSMTiendas=QPLModulosSinMenu.first();
    lCQSMTiendas;
    lCQSMTiendas=QPLModulosSinMenu.next())
  lCQSMTiendas->SlotCargaOpcion();

}
void SISCOMVentanaPrincipal::PonDatosComunicaciones(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void SISCOMVentanaPrincipal::PonDatosComunicaciones(int pintPtoCom,
						    const char *pchrPtrDirIp)
{
	
	SisDatCom=new SiscomDatCom(pintPtoCom,pchrPtrDirIp);
}
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
void SISCOMVentanaPrincipal::MuestraDatosExpendio()
{


}
void SISCOMVentanaPrincipal::CargaFirmaUsuario()
{
	printf("CargaFirmaUsuario:\n");	
}
void SISCOMVentanaPrincipal::CambiaEstadoFirma(const char *pchrPtrEdo)
{

}
void SISCOMVentanaPrincipal::closeEvent(QCloseEvent *pQClose)
{
	CambiaEstadoFirma("0");
	pQClose->accept();


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
		 CambiaEstadoFirma("0");
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
	 QPMVentanas->removeItem(lintContador);
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
		lQWVentana=lQWVentanas.at(lintContador);
		QPMVentanas->insertItem(lQWVentana->caption(),
					60+lintContador);
	}
	intUltimoIdVentanaActiva=lintContador+60;
}
void SISCOMVentanaPrincipal::SlotMuestraVentana(int pintIdVentana)
{
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
	menuBar()->insertItem("Operaciones",QPMAplicacion);
	menuBar()->insertItem("Administracion",QPMEstadisticas);
	menuBar()->insertItem("Ventanas",QPMVentanas);
}
void SISCOMVentanaPrincipal::SlotMuestraVentanas()
{
	MuestraVentanasActivas();
}
void SISCOMVentanaPrincipal::CargaSistemaSeguridad()
{
/*
SiscomTiendasSeguridad3Envio lSisTienSeg3Envio;

		lSisTienSeg3Envio << 
		new SiscomTiendasSeguridad3(
				getenv("Aplicacion"),
				Empleado->SRegistrosPro2["TipoPersona"],
				this->name(),
				Expendio->SRegistrosPro2["IdEmpresa"],
				"ConsultaSeguridad3");
Seguridad3Protocolo2 lSeguridad3Prot2(getenv("Aplicacion"),
				      Empleado->SRegistrosPro2["TipoPersona"],
				      SisDatCom,
				      this);
*/
}
void SISCOMVentanaPrincipal::CargaModulos(const char *pchrPtrArchivo)
{
CQSiscomConfiguracionModulos lCQSConModulos(pchrPtrArchivo);
CQSiscomInfoModulosLista lCQSIMLista;
char **lchrPtrArgumentos;
 int lintContador;
	lCQSIMLista=lCQSConModulos.ObtenListaModulos();
 for(lintContador=0;lintContador<lCQSIMLista.NumModulos();lintContador++)
 {
   lchrPtrArgumentos=(char **)lCQSIMLista[lintContador]->ObtenArgumentos();
   lchrPtrArgumentos[25]=(char *)this;
   CQSiscomModuloTiendas *lCQSModuloTiendas=new CQSiscomModuloTiendas(lchrPtrArgumentos,ws,0,0);
   	lCQSModuloTiendas->PonDatosModulo(lCQSIMLista[lintContador]->ObtenNombreBiblioteca(),
					  lCQSIMLista[lintContador]->ObtenNombreFuncion());
	lCQSModuloTiendas->PonMenuAlQueVa(ObtenMenuDestino(lCQSIMLista[lintContador]->ObtenNombreMenuAplicacion()));
	lCQSModuloTiendas->PonDatosComunicaciones(SisDatCom);
	lCQSModuloTiendas->CargaModuloTiendas();
	if(!strcmp(lchrPtrArgumentos[98],"IniciaMenu"))
	lCQSModuloTiendas->IniciaOpcion(lCQSIMLista[lintContador]->ObtenNombreMenu(),
					lCQSIMLista[lintContador]->ObtenTextoMenu()); 
	else
	QPLModulosSinMenu.append(lCQSModuloTiendas);
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
ws = new QWorkspace( vb ,"AreaTrabajo");
ws->setScrollBarsEnabled( TRUE );
setCentralWidget( vb );
}
QWorkspace *SISCOMVentanaPrincipal::ObtenAreaTrabajo()
{
	return ws;
}
void SISCOMVentanaPrincipal::CreaDatosComunicaciones()
{
	SisDatCom=new SiscomDatCom(5640,"127.0.0.1");
}

void SISCOMVentanaPrincipal::ObtenVentanasActivas(QWidgetList &pQWLVentanas)
{
	pQWLVentanas=ws->windowList(QWorkspace::CreationOrder);
}
void SISCOMVentanaPrincipal::ActualizaParametro(char *pchrPtrDato,int pintNParametro)
{
CQSiscomModuloTiendas *lCQSMTiendas;

for(lCQSMTiendas=QPLModulos.first();
    lCQSMTiendas;
    lCQSMTiendas=QPLModulos.next())
 lCQSMTiendas->ActualizaParametro(pchrPtrDato,pintNParametro);

}
CQSiscomModuloTiendas::CQSiscomModuloTiendas(char **pchrPtrArgumentos,
					   QWidget *pQWParent,
					     const char *pchrPtrNombre,
				     WFlags pWFlags):
			 QWSATrabajo(pQWParent),
			 QMWModulo(0),
			 CreaModuloTiendas(0),
			 vidAncla(0),
			 chrPtrArgumentos(pchrPtrArgumentos)
{

}
CQSiscomModuloTiendas::~CQSiscomModuloTiendas()
{
	if(QAOpcion)
	delete QAOpcion;
	if(QMWModulo)
	delete QMWModulo; 
	/*
	if(vidAncla);	
	dlclose(vidAncla);

	*/
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
	}
	else
	  if(!(CreaModuloTiendas=(QMainWindow *(*)(SiscomDatCom *,char **,QWidget *,const char *,WFlags ))dlsym(vidAncla,
					  chrPtrNmbFuncion)))
	  {
	    SiscomMensajesLog(gPtrFleArchivoLog,"CQSiscomModuloTiendas::CargaModuloTiendas:dlsym:%s [%s]",
		    (chrPtrErrorDll=dlerror()),
		    chrPtrNmbFuncion);

	  }

}
void CQSiscomModuloTiendas::PonDatosComunicaciones(SiscomDatCom *pCSisDatCom)
{
	SisDatCom=pCSisDatCom;
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
	(QMWModulo=CreaModuloTiendas(SisDatCom,chrPtrArgumentos,QWSATrabajo,0,0))->show();
	else
	{
	  printf("Error al Cargar El Modulo %s\n",chrPtrErrorDll);
	}
}
void CQSiscomModuloTiendas::ActualizaParametro(char *pchrPtrDato,int pintNParametro)
{
    chrPtrArgumentos[pintNParametro]=pchrPtrDato;
}
CQSiscomInfoModulos::CQSiscomInfoModulos(const char *pchrPtrNmbBiblioteca,
					 const char *pchrPtrNmbFuncion,
					 const char *pchrPtrNmbMenu,
					 const char *pchrPtrTextoMenu,
					 const char *pchrPtrNmbMenuAplicacion,
					 const char **pchrPtrArgumentos):
			chrPtrNmbBiblioteca(pchrPtrNmbBiblioteca),
			chrPtrNmbFuncion(pchrPtrNmbFuncion),
			chrPtrNmbMenu(pchrPtrNmbMenu),
			chrPtrTextoMenu(pchrPtrTextoMenu),
			chrPtrNmbMenuAplicacion(pchrPtrNmbMenuAplicacion),
			chrPtrArgumentos(pchrPtrArgumentos)
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
const char **CQSiscomInfoModulos::ObtenArgumentos()
{
	return chrPtrArgumentos;
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
		AsignaMemoriaArgumentos();
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
	  if(pQSNmbConf=="Argumento")
	  {
	    intNumArgumento=pQXAttributes.value(0).toInt();
	    chrPtrArgumentos[intNumArgumento]=strdup((const char *)pQXAttributes.value(1));
	    chrPtrArgumentos[intNumArgumento+1]=0;
	  }
	  
		return true;
}
bool CQSiscomAnalizaXMLModulos::endElement(const QString &,
					   const QString &,
					   const QString &pQSNmbConf)
{
	if(pQSNmbConf=="MenuGeneral")
	{
		CQSInfModLista.AnexaModulo(new CQSiscomInfoModulos(chrPtrNmbModulo,
								   chrPtrNmbFuncion,
								   chrPtrMenu,
								   chrPtrTextoMenu,
								   chrPtrNmbMenuAplicacion,
								   chrPtrArgumentos));
		LiberaArgumentos();
		AsignaMemoriaArgumentos();

	}
	return true;
}
CQSiscomInfoModulosLista CQSiscomAnalizaXMLModulos::ObtenListaModulos()
{
	return CQSInfModLista;
}
void CQSiscomAnalizaXMLModulos::AsignaMemoriaArgumentos()
{
		chrPtrArgumentos=(const char **)malloc(sizeof(const char *)*100);
}
void CQSiscomAnalizaXMLModulos::LiberaArgumentos()
{
/*
int lintContador;
	for(lintContador=0;
	    lintContador<99;
	    lintContador++)
	   if(chrPtrArgumentos[lintContador])
	  free((void *)chrPtrArgumentos[lintContador]);
	free((void *)chrPtrArgumentos);
*/
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

