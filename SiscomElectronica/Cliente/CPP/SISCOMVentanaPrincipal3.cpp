#include <SISCOMVentanaPrincipal3.h>
#include <SISCOMComunicaciones++.h>
#include <SiscomDesarrollo3Qt++.h>
#include <Seguridad3Protocolo2.h>

#include <IMP_FirmaTiendas.h>
#include <EmpresasN.h>
#include <Personas.h>
#include <SiscomRegistros3.h>

#include <qpopupmenu.h>
#include <qmenubar.h>
#include <qworkspace.h>
#include <qvbox.h>
#include <qwidget.h>
#include <qaction.h>
#include <qobjectlist.h>
#include <qdir.h>
#include <qapplication.h>

#include <zSiscomConexion.h>

#include <dlfcn.h>

void *gzSiscomConexion;

SISCOMVentanaPrincipal::SISCOMVentanaPrincipal(QApplication *pQAPrincipal,
					      QWidget *pQWParent,
				       const char *pchrPtrNombre,
				       WFlags pWFlags):
		QMainWindow(pQWParent,pchrPtrNombre,pWFlags),
		QAPrincipal(pQAPrincipal),
		intUltimoIdVentanaActiva(0),
		SisDatCom(0)
{
SiscomEscribeLog3Qt("");
	CargaFirmaUsuario();
	setName("SISCOMVentanaPrincipal");
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
void SISCOMVentanaPrincipal::MuestraDatosExpendio()
{
setCaption(QString("Expendio:")				+
	   Expendio->SRegistrosPro2["RazonSocial"]	+
	   "    "					+
	   "<<Atendiendo:"			   	+
	   Empleado->SRegistrosPro2["Nombre"]		+
	   " "						+
	   Empleado->SRegistrosPro2["APaterno"]		+
	   ">>"); 

}
SiscomRegistro3 *SISCOMVentanaPrincipal::ExpendioRegistro3()
{
SiscomRegistro3 *lSisReg3Expendio=new SiscomRegistro3;

(*lSisReg3Expendio) << new SiscomCampo3("IdExpendio",(*Expendio)["IdEmpresa"]);
SiscomContenidoRegistro3(lSisReg3Expendio);

return lSisReg3Expendio;
}
void SISCOMVentanaPrincipal::CargaFirmaUsuario()
{
QFirmaTiendas lQFirmaT(QAPrincipal,this);
	if((Empleado=lQFirmaT.ObtenEmpleado()))
	{
	SiscomEscribeLog3Qt("------------------------------");	
	SisDatCom=lQFirmaT.ObtenServidor();
	Expendio=lQFirmaT.ObtenExpendio();
	chrPtrArgumentos=(char **)malloc(sizeof(char *)*10);
	chrPtrArgumentos[0]=(char *)Expendio->SRegistrosPro2["IdEmpresa"];
	chrPtrArgumentos[1]=(char *)Empleado->SRegistrosPro2["IdPersona"];
	chrPtrArgumentos[2]=(char *)Expendio;
	chrPtrArgumentos[3]=(char *)this;
	chrPtrArgumentos[4]=(char *)Empleado->SRegistrosPro2["TipoPersona"];
	chrPtrArgumentos[5]=(char *)ExpendioRegistro3();
	chrPtrArgumentos[6]=0;
	MuestraDatosExpendio();
	}
	else
	exit(0);

}
void SISCOMVentanaPrincipal::CambiaEstadoFirma(const char *pchrPtrEdo)
{
OpPersonas lOpPersonas(SisDatCom);
	lOpPersonas.CambiaEstatusFirma(chrPtrArgumentos[0],
				       chrPtrArgumentos[1],
				       pchrPtrEdo);


}
void SISCOMVentanaPrincipal::closeEvent(QCloseEvent *pQClose)
{
/*
 * Jueves 31 de enero 2008
 * El cambio del estado de la firma, trae mas problemas
 * que lo que arregla, en el contexto actual de las 
 * aplicaciones no es necesario verificar si el usuario
 * ya esta firmado o 
 * no
 *
 */
//	CambiaEstadoFirma("0");
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
/*
 * Jueves 31 de enero 2008
 * El cambio del estado de la firma, trae mas problemas
 * que lo que arregla, en el contexto actual de las 
 * aplicaciones no es necesario verificar si el usuario
 * ya esta firmado o 
 * no
 *
 */
//		 CambiaEstadoFirma("0");
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
	menuBar()->insertItem("Siscom Electronica",QPMAplicacion);
	menuBar()->insertItem("Administracion",QPMEstadisticas);
	menuBar()->insertItem("Ventanas",QPMVentanas);
}
void SISCOMVentanaPrincipal::SlotMuestraVentanas()
{
	MuestraVentanasActivas();
}
void SISCOMVentanaPrincipal::CargaSistemaSeguridad()
{
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
/*
Seguridad3Protocolo2 lSeguridad3Prot2(
				SisDatCom,
				(QPtrList<SiscomInformacion> *)&lSisTienSeg3Envio,
				this);
*/
}
void SISCOMVentanaPrincipal::CargaModulos(const char *pchrPtrArchivo)
{
CQSiscomConfiguracionModulos lCQSConModulos(pchrPtrArchivo);
CQSiscomInfoModulosLista lCQSIMLista;
 int lintContador;
	lCQSIMLista=lCQSConModulos.ObtenListaModulos();
 for(lintContador=0;lintContador<lCQSIMLista.NumModulos();lintContador++)
 {
   CQSiscomModuloTiendas *lCQSModuloTiendas=new CQSiscomModuloTiendas(chrPtrArgumentos,ws,0,0);
   	lCQSModuloTiendas->PonDatosModulo(lCQSIMLista[lintContador]->ObtenNombreBiblioteca(),
					  lCQSIMLista[lintContador]->ObtenNombreFuncion());
	lCQSModuloTiendas->PonMenuAlQueVa(ObtenMenuDestino(lCQSIMLista[lintContador]->ObtenNombreMenuAplicacion()));
	lCQSModuloTiendas->PonDatosComunicaciones(SisDatCom);
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
Persona *SISCOMVentanaPrincipal::ObtenEmpleado()
{
	return Empleado;
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
}
void SISCOMVentanaPrincipal::ActualizaExpendio(EmpresaN *pExpendio)
{
	Expendio=pExpendio;
	MuestraDatosExpendio();
}
void SISCOMVentanaPrincipal::ObtenVentanasActivas(QWidgetList &pQWLVentanas)
{
	pQWLVentanas=ws->windowList(QWorkspace::CreationOrder);
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

SiscomTiendasSeguridad3::SiscomTiendasSeguridad3(
		const char *pchrPtrAplicacion,
		const char *pchrPtrIdPerfil,
		const char *pchrPtrNmbPantalla,
		const char *pchrPtrIdExpendio,
		const char *pchrPtrConsulta)
{

	SRegistroPro2 			<<
	"Aplicacion"			<<
	"IdPerfil"			<<
	"NmbPantalla"			<<
	"IdExpendio"			<<
	"Consulta";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

	SRegistrosPro2						<<
	SiscomCampoPro2("Aplicacion",pchrPtrAplicacion)		<<
	SiscomCampoPro2("IdPerfil",pchrPtrIdPerfil)		<<
	SiscomCampoPro2("NmbPantalla",pchrPtrNmbPantalla)	<<
	SiscomCampoPro2("IdExpendio",pchrPtrIdExpendio)		<<
	SiscomCampoPro2("Consulta",pchrPtrConsulta);
	SRegistrosPro2.SiscomAnexaRegistro();
}
					

SiscomTiendasSeguridad3Envio::SiscomTiendasSeguridad3Envio()
{

}
SiscomTiendasSeguridad3Envio &SiscomTiendasSeguridad3Envio::operator<<(
		SiscomTiendasSeguridad3 *pSisTienSeg3)
{

		append(pSisTienSeg3);
		return *this;
}

