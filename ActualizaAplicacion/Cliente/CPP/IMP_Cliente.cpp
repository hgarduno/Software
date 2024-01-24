#include  <IMP_Cliente.h>
#include  <IMP_CapturaInformacion.h>
#include  <IMP_CapEstacion.h>
#include  <IMP_NotTransmision.h>
#include  <CreaDirectorio.h>
#include  <TransfiereArchivos.h>
#include  <Estaciones.h>
#include  <TransfiereAEstaciones.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qfiledialog.h>
#include <qtoolbox.h>
#include <qtextedit.h>
#include <qhbox.h>
FILE *gPtrFleArchivoLog=stdout;

QCliente::QCliente( QWidget* parent, const char* name, WFlags fl )
    : Cliente( parent, name, fl )
{
	ConectaSlots();
	IniciaComunicaciones();	
	IniciaVariables();
}

QCliente::~QCliente()
{
}
void QCliente::IniciaVariables()
{
  QTBEscripts->removeItem(QTBEscripts->currentItem());
  // CargaEstaciones();
	QNTransmision=new QNotTransmision;	

}
void QCliente::IniciaComunicaciones()
{
	SDatCom=new SiscomDatCom(QLEPto->text().toInt(),
				 (const char *)QLEDirIpSvr->text());
}
void QCliente::ConectaSlots()
{
	connect(QPCDirectorio,
		SIGNAL(clicked()),
		SLOT(S_CreaDirectorios()));
	connect(QPBAMCliente,
		SIGNAL(clicked()),
		SLOT(S_AnexaModulos()));
	connect(QPBTServidor,
		SIGNAL(clicked()),
		SLOT(S_TransfiereClienteAlServidor()));
	connect(QPBAAplicacion,
		SIGNAL(clicked()),
		SLOT(S_AnexaAplicacionCliente()));
	connect(QPBConfiguracion,
		SIGNAL(clicked()),
		SLOT(S_AnexaConfiguracionCliente()));

	connect(QPBAEscript,
		SIGNAL(clicked()),
		SLOT(S_AnexaEscript()));
	connect(QPBAnexaEstacion,
		SIGNAL(clicked()),
		SLOT(S_AnexaEstacion()));
	connect(QPBAEstaciones,
		SIGNAL(clicked()),
		SLOT(S_ActualizaEstaciones()));
	connect(QPBTAEstaciones,
		SIGNAL(clicked()),
		SLOT(S_TransfiereAEstaciones()));


}
void QCliente::S_TransfiereAEstaciones()
{
	TAEstaciones=new TransfiereAEstaciones(this,
				     SDatCom,
				    "TransfiereAEstaciones",
				     0);
	QNTransmision->exec();

}
void QCliente::S_ActualizaEstaciones()
{
	CargaEstaciones();
}
void QCliente::S_AnexaEstacion()
{
QCapEstacion lQCEstacion;
			
	if(lQCEstacion.ObtenBoton())
	{
	ListaEstaciones lLstEstaciones;
	lLstEstaciones.append(lQCEstacion.ObtenEstacion());
	Estaciones lEstaciones(SDatCom,
		      	        "InsertaEstacion",
				&lLstEstaciones);
	}

}
void QCliente::S_AnexaEscript()
{
	AnexaEscript();

}
void QCliente::S_AnexaConfiguracionCliente()
{
	SeleccionaYAnexaArchivos("*.xml",
				QSLConCliente,
				QTConfiguracion);
}
void QCliente::S_AnexaAplicacionCliente()
{

	SeleccionaYAnexaArchivos("*",
				 QSLACliente,
				 QTAplicaciones);

}
void QCliente::TransfiereArchivos(QStringList pQSLArchivos,
				  const char *pchrPtrDirTrabajo,
				  const char *pchrPtrHome,
				  const char *pchrPtrComentario)
{
int lintContador;
char lchrArrNmbDestino[256];
	for(lintContador=0;
	    lintContador<(int )pQSLArchivos.size();
	    lintContador++)
	 {
	  ObtenDatosArchivo(pQSLArchivos[lintContador],
			    lchrArrNmbDestino); 
	  TransfiereArchivo lTArchivo(SDatCom,
				      pQSLArchivos[lintContador],
				      lchrArrNmbDestino,
				      pchrPtrDirTrabajo,
				      pchrPtrHome,
				      pchrPtrComentario);

	 }



}
void QCliente::S_TransfiereClienteAlServidor()
{
	TransfiereArchivos(QSLModulos,
			   (const char *)QLEDTrabajo->text(),
			   "/home/hgarduno",
			   "ModuloCliente");
	TransfiereArchivos(QSLACliente,
			   (const char *)QLEDTrabajo->text(),
			   "/home/hgarduno",
			   "AplicacionCliente");
	TransfiereArchivos(QSLConCliente,
			   (const char *)QLEDTrabajo->text(),
			   "/home/hgarduno",
			   "ConfiguracionCliente");
	TransfiereEscripts();
}
void QCliente::SeleccionaYAnexaArchivos(const char *pchrPtrExtension,
				        QStringList &pQSLArchivos,
					QTable *pQTDatos)
{
int lintContador;
QStringList lQSLModulos;
	lQSLModulos=QFileDialog::getOpenFileNames(pchrPtrExtension);	
	for(lintContador=0;
	    lintContador<(int )lQSLModulos.size();
	    lintContador++)
	 pQSLArchivos.append(lQSLModulos[lintContador]);
	MuestraDatosTabla(lQSLModulos,pQTDatos);
}
void QCliente::S_AnexaModulos()
{
	SeleccionaYAnexaArchivos("*.so",
				 QSLModulos,
				 QTMCliente);
}
void QCliente::S_CreaDirectorios()
{
char *lchrPtrEdoCDInstalacion,
     *lchrPtrEdoCDConfiguracion;
CreaDirectorio lCDirectorio(SDatCom,
			    (const char *)QLEDTrabajo->text(),
			    (const char *)QLEServidor->text());	
	if(!lCDirectorio.ObtenEdoConexion())
	{
	   lCDirectorio.EnviaOrden();
	   lCDirectorio.ObtenEdoCreacion(&lchrPtrEdoCDInstalacion,
					 &lchrPtrEdoCDConfiguracion);
	   
	}
	
}
void QCliente::MuestraDatosTabla(QStringList pQSLModulos,
				 QTable *pQTDatos)
{
int lintContador;
int lintNumFilas=pQTDatos->numRows();
int lintNumModulos=pQSLModulos.size();
	
	 pQTDatos->setNumRows(lintNumFilas+lintNumModulos);
	 for(lintContador=0;
	     lintContador<lintNumModulos;
	     lintContador++,
	     lintNumFilas++)
	 pQTDatos->setText(lintNumFilas,
			     0,
			     pQSLModulos[lintContador]);
}
void QCliente::ObtenDatosArchivo(QString pQSArchivo,
				 char *pchrPtrDestino)
{
QString lQSArchivo=pQSArchivo.section('/',-1);

	strcpy(pchrPtrDestino,
	       (const char *)lQSArchivo);
}

void QCliente::AnexaEscript()
{
QCapturaInformacion lQCInformacion("Captura Nombre Del Escrip",
				   "Nombre Del Escript");
static int lintContador=0;
   if(lQCInformacion.ObtenCualBoton())
   {
	const char *lchrPtrDato;
	lchrPtrDato=lQCInformacion.ObtenDato();
	QTBEscripts->insertItem(lintContador++,
				new QItemToolBoxEscrip(
					lchrPtrDato,
					this,
					lchrPtrDato),
				lchrPtrDato);
 }
}

void QCliente::CargaEstaciones()
{
Estacion *lEstacion=new Estacion("",
				 "",
				 "",
				 "",
				 "Todas",
				 "");

ListaEstaciones lLstEstaciones;
lLstEstaciones.append(lEstacion);
Estaciones lEstaciones(SDatCom,
		       "ConsultaEstaciones",
		       &lLstEstaciones);
int lintContador;
	
	QTEstaciones->setNumRows(lLstEstaciones.count());
	for(lintContador=0,
	    lEstacion=lLstEstaciones.first();
	    lEstacion;
	    lEstacion=lLstEstaciones.next(),
	    lintContador++)
	{
	 QTEstaciones->setText(lintContador,
			       0,
			       lEstacion->ObtenDirIp());
	 QTEstaciones->setText(lintContador,
			       1,
			       lEstacion->ObtenPtoCom());

	 QTEstaciones->setText(lintContador,
			       2,
			       lEstacion->ObtenDirTrabajo());
	 QTEstaciones->setText(lintContador,
			       3,
			       lEstacion->ObtenHome());
		
	}
}
void QCliente::TransfiereEscripts()
{
int lintContador;
int lintNEscripts=QTBEscripts->count();
QItemToolBoxEscrip *lQITBEscrip;
	for(lintContador=0;
	    lintContador<lintNEscripts;
	    lintContador++)
	{
	   lQITBEscrip=(QItemToolBoxEscrip *)QTBEscripts->item(lintContador);
	   TransfiereArchivo lTArchivo(SDatCom,
					"",
					lQITBEscrip->ObtenNmbEscript(),
					(const char *)QLEDTrabajo->text(),
					"/home/hgarduno",
					"EscriptCliente",
					lQITBEscrip->ObtenEscript());	
	}
}
void QCliente::customEvent(QCustomEvent *pQCEvento)
{
	if(pQCEvento->type()==QEvent::User+100)
	EstadoTransmision((QEEdoTransmision *)pQCEvento);

}
void QCliente::EstadoTransmision(QEEdoTransmision *pQEEdoTransmision)
{
	QNTransmision->PonDatos(pQEEdoTransmision->ObtenEdoTransmision(),
				pQEEdoTransmision->ObtenArchivo(),
				pQEEdoTransmision->ObtenDirIpEstacion(),
				pQEEdoTransmision->ObtenPtoComEstacion());

}
QItemToolBoxEscrip::QItemToolBoxEscrip(const char *pchrPtrNmbEscrip,
				       QWidget *pQWParent,
				       const char *pchrPtrName):
		QWidget(pQWParent,pchrPtrName)
{

		chrPtrNmbEscrip=strdup(pchrPtrNmbEscrip);
QHBoxLayout *lQHBox=new QHBoxLayout(this);
	QTEscript=new QTextEdit(this);
	lQHBox->addWidget(QTEscript);

}
const char *QItemToolBoxEscrip::ObtenEscript()
{
	return  strdup(QTEscript->text());
}
const char *QItemToolBoxEscrip::ObtenNmbEscript()
{
	return chrPtrNmbEscrip;
}

