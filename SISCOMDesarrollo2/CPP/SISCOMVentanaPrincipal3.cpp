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
		SisDatCom(0),
		SUSeg3Firmado(0)

{
/*
*/
}
void SISCOMVentanaPrincipal::SiscomLeeCPUInfo()
{
FILE *lFlePtrArchivo;
int lintContador;
chrPtrCPUInfo=(char *)malloc(2048);

if((lFlePtrArchivo=fopen("/proc/cpuinfo","r")))
{
for(lintContador=0;
    (lintContador<2048 &&
     !feof(lFlePtrArchivo));
    lintContador++)
 chrPtrCPUInfo[lintContador]=getc(lFlePtrArchivo);
 chrPtrCPUInfo[lintContador-1]=0;
 fclose(lFlePtrArchivo);
}
}
/*
 *
 * Codigo obtenido de la ayuda de la funcion crypt
 * En el manual GNU
 *
 */
void SISCOMVentanaPrincipal::SiscomClaveAcceso()
{
/*
 *
 * Por alguna razon no funciono la fase de 
 * de encriptar la informacion.
 * Lo que se observo es que al llamar dos
 * veces seguidas la funcion crypt no regresa
 * de forma correcta, el valor que regresa
 * siempre es igual
 *
 */
/*
unsigned long seed[2];
char salt[] = "$1$........";
const char *const seedchars =
"./0123456789ABCDEFGHIJKLMNOPQRST"
"UVWXYZabcdefghijklmnopqrstuvwxyz";
char *password;
int i;
seed[0] = time(NULL);
seed[1] = getpid() ^ (seed[0] >> 14 & 0x30000); 
for (i = 0; i < 8; i++)
salt[3+i] = seedchars[(seed[i/5] >> (i%5)*6) & 0x3f]; 
chrPtrClaveAcceso= crypt(chrPtrCPUInfo, salt);
printf("La Clave:%s\n",chrPtrClaveAcceso);

*/
}
void SISCOMVentanaPrincipal::SiscomValidaAutenticidad()
{
	SiscomLeeCPUInfo();
	SiscomClaveAcceso();
}
char *SISCOMVentanaPrincipal::SiscomCPUInfo()
{
return chrPtrCPUInfo;
}
char *SISCOMVentanaPrincipal::SiscomObtenClaveAcceso()
{
	return chrPtrClaveAcceso;
}
const char *SISCOMVentanaPrincipal::SiscomMacAddress()
{
FILE *lFlePtrArchivo;
char lchrArrDato[20];
int lintContador;
if((lFlePtrArchivo=fopen("/sys/class/net/eth0/address","r")))
{
  for(lintContador=0;
      !feof(lFlePtrArchivo);
      lintContador++)
   lchrArrDato[lintContador]=getc(lFlePtrArchivo);
   /*
    * Se elimina el salto de linea
    */
   lchrArrDato[lintContador-2]=0;
   fclose(lFlePtrArchivo);
   return strdup(lchrArrDato);
}
else
return 0;
}
void SISCOMVentanaPrincipal::SiscomIniciaVentana()
{
	CargaFirmaUsuario();
//	setName("SISCOMVentanaPrincipal");
	ObtenNombreArchivoConfiguracion(getenv("ArchivoConfiguracionModulos"));
	CreaMenus();
	CargaArchivosDeConfiguracion();
	CreaWS();
	CargaModulos(chrPtrAConfiguracionMod);
	CargaSistemaSeguridad();
	CargaArgumentos();
	SiscomValidaAutenticidad();
	MuestraUsuarioFirmado();
	show();


}
void SISCOMVentanaPrincipal::MuestraUsuarioFirmado()
{
QString lQSCaption=caption();
	if(SUSeg3Firmado)
	{
	lQSCaption+=QString(" ") 			+ 
	SUSeg3Firmado->SRegistrosPro2["Nombre"] +
	" "					+
	SUSeg3Firmado->SRegistrosPro2["APaterno"];
	setCaption(lQSCaption);
	}
	else
	  printf("No se han pasado los datos del usuario\n");
}
void SISCOMVentanaPrincipal::UsuarioSeguridad3(SisUsuarioSeg3 *pSUSeg3)
{
	SUSeg3Firmado=pSUSeg3;
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
SiscomDatCom *SISCOMVentanaPrincipal::ObtenDatosComunicacion()
{
	return SisDatCom;
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
	for(lintContador=0;lintContador<(int )lQSLArchivos.size();lintContador++)
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
void SISCOMVentanaPrincipal::CargaArgumentos()
{
	
}
CQSisLstParametrosModulo &SISCOMVentanaPrincipal::SiscomArgumentos()
{
	return CQSLPModulo;
}
CQSisLstMenu &SISCOMVentanaPrincipal::OpcionesMenu()
{
	return CQSLMenus;
}
void SISCOMVentanaPrincipal::CambiaEstadoFirma(const char *)
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
	for(lintContador=0;lintContador<(int )lQWVentanas.count();lintContador++)
	{
		lQWVentana=lQWVentanas.at(lintContador);
		QPMVentanas->insertItem(lQWVentana->caption(),
					60+lintContador);
	}
	intUltimoIdVentanaActiva=lintContador+60;
}
void SISCOMVentanaPrincipal::SlotMuestraVentana(int )
{
}
void SISCOMVentanaPrincipal::EliminaModulosCargados()
{
int lintContador;

	for(lintContador=0;lintContador<(int )QPLModulos.count();lintContador++)
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
 int lintContador;
char **lchrPtrArgumentos;
	lCQSIMLista=lCQSConModulos.ObtenListaModulos();

/* Se debe crear un objeto que contenga la lista de los parametros
 * por nombre de modulo para poder identificarlo
 * ya que hacerlo por la referencia de chrPtrArgumentos
 * es erroneo, esto es debido a que cada modulo contiene una 
 * un espacio de memoria diferente para sus argumentos
 * Por lo que para hacer referencia en conjunto o individualmente
 * fuera de esta clase a los argumentos no es posible 
 *
 */
 for(lintContador=0;lintContador<lCQSIMLista.NumModulos();lintContador++)
 {
 lchrPtrArgumentos=(char **)lCQSIMLista[lintContador]->ObtenArgumentos();
 lchrPtrArgumentos[0]=(char *)SUSeg3Firmado;
CQSiscomModuloTiendas *lCQSModuloTiendas=new CQSiscomModuloTiendas(lchrPtrArgumentos ,ws,0,0);
lCQSModuloTiendas->PonDatosModulo(lCQSIMLista[lintContador]->ObtenNombreBiblioteca(),
					  lCQSIMLista[lintContador]->ObtenNombreFuncion());
lCQSModuloTiendas->PonMenuAlQueVa(ObtenMenuDestino(lCQSIMLista[lintContador]->ObtenNombreMenuAplicacion()));
lCQSModuloTiendas->PonDatosComunicaciones(SisDatCom);
lCQSModuloTiendas->CargaModuloTiendas();
CQSLMenus << lCQSModuloTiendas->IniciaOpcion(lCQSIMLista[lintContador]->ObtenNombreMenu(),
					lCQSIMLista[lintContador]->ObtenTextoMenu()); 
CQSLPModulo << new CQSisParametrosModulo(lCQSIMLista[lintContador]->ObtenNombreMenu(),(const char **)lchrPtrArgumentos);
QPLModulos.append(lCQSModuloTiendas);
 }
}
QPopupMenu *SISCOMVentanaPrincipal::ObtenMenuDestino(const char *pchrPtrNombre)
{
		if(!strcmp(pchrPtrNombre,"QPMAplicacion")) 
		 return QPMAplicacion;
		if(!strcmp(pchrPtrNombre,"QPMEstadisticas"))
		 return QPMEstadisticas;
		 else
		 return 0;
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
CQSiscomModuloTiendas::CQSiscomModuloTiendas(char **pchrPtrArgumentos,
					   QWidget *pQWParent,
					     const char *,
				     WFlags ):
			 chrPtrArgumentos(pchrPtrArgumentos),
			 QWSATrabajo(pQWParent),
			 QMWModulo(0),
			 CreaModuloTiendas(0),
			 vidAncla(0)
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
QAction *CQSiscomModuloTiendas::IniciaOpcion(const char *pchrPtrNmbOpcion,
					 const char *pchrPtrTexto)
{
         QAOpcion=new QAction(QPMModulo,pchrPtrNmbOpcion);
  	  QAOpcion->setText(pchrPtrTexto);
  	  connect(QAOpcion,
		  SIGNAL(activated()),
		  SLOT(SlotCargaOpcion()));
	   QAOpcion->addTo(QPMModulo);

	return QAOpcion;		  
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
		/*
		LiberaArgumentos();
		*/
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
		memset(chrPtrArgumentos,
		       0,
		       sizeof(const char *)*100);
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



CQSisParametrosModulo::CQSisParametrosModulo(const char *pchrPtrModulo,
					     const char **pchrPtrArgumentos):
					  chrPtrModulo(pchrPtrModulo),
					  chrPtrArgumentos(pchrPtrArgumentos)
{
}
const char **CQSisParametrosModulo::Parametros()
{
	return chrPtrArgumentos;
}
const char *CQSisParametrosModulo::Modulo()
{
	return chrPtrModulo;
}
void CQSisParametrosModulo::SiscomDatoParametro(int pintNArgumento,
						 const char *pchrPtrDato)
{
chrPtrArgumentos[pintNArgumento]=strdup(pchrPtrDato);
}
CQSisLstParametrosModulo::CQSisLstParametrosModulo()
{

}
CQSisLstParametrosModulo &CQSisLstParametrosModulo::operator<<(
				CQSisParametrosModulo *pCQSPModulo)
{
	append(pCQSPModulo);
	return *this;
}
CQSisParametrosModulo *CQSisLstParametrosModulo::operator[](const char *pchrPtrModulo)
{
CQSisParametrosModulo *lCQSPModulo;
for(lCQSPModulo=first();
    lCQSPModulo;
    lCQSPModulo=next())
 if(!strcmp(lCQSPModulo->Modulo(),pchrPtrModulo))
 return lCQSPModulo;
 return 0;
}
void CQSisLstParametrosModulo::SiscomAsignaDatoArgumento(int pintNArgumento,
							 const char *pchrPtrValor)
{
CQSisParametrosModulo *lCQSPModulo;
for(lCQSPModulo=first();
    lCQSPModulo;
    lCQSPModulo=next())
    lCQSPModulo->SiscomDatoParametro(pintNArgumento,pchrPtrValor);
}
