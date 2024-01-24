#include <IMP_FirmaTiendas.h>
#include <IMP_SelExpendios.h>
#include <IMP_FirmateExpendio.h>

#include <EmpresasN.h>
#include <Personas.h>
#include <SISCOMComunicaciones++.h>
#include <SiscomDesarrollo3Qt++.h>

#include <qvariant.h>
#include <qiconview.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qpushbutton.h>
#include <qfontdialog.h>
#include <qapplication.h>
extern FILE *gPtrFleArchivoLog;
extern FILE *gPtrFleArchivoLog3Qt;

QFirmaTiendas::QFirmaTiendas(QApplication *pQAPrincipal,
			     QWidget* parent,
			     const char* name, bool modal, WFlags fl )
    : FirmaTiendas( parent, name, modal, fl ),
    QAPrincipal(pQAPrincipal),
    QWParent(parent),
    	Expendio((EmpresaN *)0),
	intModificoPerfil(0)
{

	if((intArchivoServidores=CargaArchivo()))
	{
	ConectaSlots();
	MuestraServidores();
	exec();
	}
	else
	{
	const char *lchrPtrPtoCom=getenv("PtoComSvr"),
		   *lchrPtrDirIpSvr=getenv("DirIpSvr"),
		   *lchrPtrIdExpendio=getenv("IdExpendio");

		
	if(lchrPtrPtoCom 	&&
	   lchrPtrDirIpSvr	&&
	   lchrPtrIdExpendio )
	{
	SisDatCom=  new SiscomDatCom(atoi(lchrPtrPtoCom),lchrPtrDirIpSvr);
	Expendio=new EmpresaN("",lchrPtrIdExpendio,""); 
	ConsultaEmpleadosExpendio();
	exec();
	}
	else
	{
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "No Se puede realizar la conexion al expendio\n");
	exit(0);
	}
	}
}

QFirmaTiendas::~QFirmaTiendas()
{
}
void QFirmaTiendas::MuestraServidores()
{
if(intArchivoServidores)
{
char **lchrPtrServidores;
char *lchrPtrBuffer=(char *)malloc(strlen(chrArrArchivo));
int lintContador;
	SiscomAnalizaCadenas(chrArrArchivo,
			     '\n',
			     lchrPtrBuffer,
			     &lchrPtrServidores);
	for(lintContador=0;
	    lchrPtrServidores[lintContador];
	    lintContador++)
	 AnexaServidor(lchrPtrServidores[lintContador]);
}
else
SiscomEscribeLog3Qt("No Se Cargan los servidores \n");
}
void QFirmaTiendas::AnexaServidor(const char *pchrPtrServidor)
{
char **lchrPtrServidor;
char lchrArrBuffer[125];
	SiscomAnalizaCadenas(pchrPtrServidor,
			     '@',
			      lchrArrBuffer,
			      &lchrPtrServidor);
	SiscomEscribeLog3Qt("Se Anexara:%s",pchrPtrServidor);	
	QIVInforma->insertItem(new QServidoresIconView(new SiscomDatCom(
								atoi(lchrPtrServidor[1]),
								lchrPtrServidor[0],
								lchrPtrServidor[2]),
								QIVInforma,
								0));
}
void QFirmaTiendas::ConsultaExpendios()
{
EmpresasN lExpendios;
ConsultaEmpresasN lCnsExpendios(SisDatCom,
                                "Expendios",
				lExpendios);
EmpresaN *lEmpresa;
		for(lEmpresa=lExpendios.first(); lEmpresa; lEmpresa=lExpendios.next())
		QIVInforma->insertItem(new QIconVExpendio(lEmpresa,QIVInforma));

}
void QFirmaTiendas::ConectaSlots()
{

	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_AnexarServidor()));
	connect(QPBEliminar,
		SIGNAL(clicked()),
		SLOT(S_EliminarServidor()));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(S_Aceptar())); 
	connect(QIVInforma,
		SIGNAL(doubleClicked(QIconViewItem *)),
		SLOT(S_SeleccionoServidor(QIconViewItem *)));

	connect(QIVInforma,
		SIGNAL(returnPressed(QIconViewItem *)),
		SLOT(S_SeleccionoServidor(QIconViewItem *)));
	connect(QPBSLetra,
		SIGNAL(clicked()),
		SLOT(S_SeleccionarLetra()));

}
void QFirmaTiendas::S_SeleccionarLetra()
{
bool lbRegreso;
QFLetra=QFontDialog::getFont(&lbRegreso,
				    QFont( "Times", 12 ), 
				    this );
setFont(QFLetra);
QAPrincipal->setFont(QFLetra);
QWParent->setFont(QFLetra);
intModificoPerfil=1;
}
void QFirmaTiendas::S_SeleccionoServidor(QIconViewItem *pQIVItem)
{
       if(pQIVItem)
       {
	SisDatCom=((QServidoresIconView *)pQIVItem)->ObtenServidor();
	disconnect(QIVInforma,0,0,0);
	QIVInforma->clear();
	connect(QIVInforma,
		SIGNAL(doubleClicked(QIconViewItem *)),
		SLOT(S_SeleccionoExpendio(QIconViewItem *)));
	connect(QIVInforma,
		SIGNAL(returnPressed(QIconViewItem *)),
		SLOT(S_SeleccionoExpendio(QIconViewItem *)));
	ConsultaExpendios();
	}
}
void QFirmaTiendas::S_SeleccionoExpendio(QIconViewItem *pQIVItem)
{
	if(pQIVItem)
	{
	Expendio=((QIconVExpendio *)pQIVItem)->ObtenExpendio();
	disconnect(QIVInforma,0,0,0);
	QIVInforma->clear();
	ConsultaEmpleadosExpendio();
	}
	else
	{
	if((intArchivoServidores=CargaArchivo()))
	{
	MuestraServidores();
	disconnect(QIVInforma,0,0,0);
	connect(QIVInforma,
		SIGNAL(doubleClicked(QIconViewItem *)),
		SLOT(S_SeleccionoServidor(QIconViewItem *)));
	connect(QIVInforma,
		SIGNAL(returnPressed(QIconViewItem *)),
		SLOT(S_SeleccionoServidor(QIconViewItem *)));
	}

	}

}
void QFirmaTiendas::S_SeleccionaEmpleado(QIconViewItem *pQIVItem)
{
Persona *lPersona=((QEmpleadosExpendioIconView *)pQIVItem)->ObtenEmpleado();
const char *lchrPtrAplicacion;
if((lchrPtrAplicacion=getenv("Aplicacion")))
{
QFirmateExpendio lQFirmate(SisDatCom,
			   lchrPtrAplicacion,
			   Expendio->SRegistrosPro2["IdEmpresa"],
			   lPersona);
 if(!lQFirmate.ObtenEdoValidacionUsuario())
  exit(0);
  else
  {
  Empleado=lPersona;
  if(intModificoPerfil)
  {
  AlmacenaPerfil();
  }
  else
  {
   SiscomEscribeLog3Qt("Se carga el perfil del usuario:%s",
   	     (*Empleado)["Firma"]);
   CargaPerfil();
  }
  done(1);
  }
}
else
{
SiscomEscribeLog3Qt("QFIrmaTiendas::No se definio la variable de ambiente Aplicacion\n");
exit(0);
}			   
}
void QFirmaTiendas::S_AnexarServidor()
{

}
void QFirmaTiendas::S_EliminarServidor()
{

}
void QFirmaTiendas::S_Aceptar()
{


}
int QFirmaTiendas::CargaArchivo()
{
FILE *lFlePtrArchivo;
char lchrArrNmbArchivo[1024];
int lintContador=0;
const char *lchrPtrArchivoServidores=getenv("ArchivoServidores");
unsigned char lchrCaracter;
SiscomEscribeLog3Qt("");
	if(!lchrPtrArchivoServidores)
	{
	SiscomEscribeLog3Qt("No Se encontro La variable de ambiente:\"ArchivoServidores\"\n");
	return 0;
	}
	else
	{
	sprintf(lchrArrNmbArchivo,
		"%s",getenv("ArchivoServidores"));
	SiscomEscribeLog3Qt("( %s )",lchrArrNmbArchivo);
	if(!(lFlePtrArchivo=fopen(lchrArrNmbArchivo,"r")))
	{
	  SiscomEscribeLog3Qt("No Se pudo abrir el archivo:%s\n",
	          lchrArrNmbArchivo);
	   exit(0);

	}
	else
	while((lchrCaracter=getc(lFlePtrArchivo))!=(unsigned char )EOF)
	{
	    chrArrArchivo[lintContador]=lchrCaracter; 
	   lintContador++;
	}
	chrArrArchivo[lintContador-2]=0;
	return 1;
	}
SiscomEscribeLog3Qt("Termino");
} 
SiscomDatCom *QFirmaTiendas::ObtenServidor()
{
	return SisDatCom;
}
void QFirmaTiendas::ConsultaEmpleadosExpendio()
{
ConsultaPersonas lCnsEmpleados;
SiscomLog("COnsultando los empleados");
Personas lEmpleados;
	lCnsEmpleados.EmpleadosExpendio(SisDatCom,
				 	Expendio->SRegistrosPro2["IdEmpresa"],
					lEmpleados);
	
Persona *lEmpleado;
	for(lEmpleado=lEmpleados.first();
	    lEmpleado;
	    lEmpleado=lEmpleados.next())
	  QIVInforma->insertItem(new QEmpleadosExpendioIconView(
	  				lEmpleado,
					QIVInforma,
					0));

connect(QIVInforma,
		SIGNAL(doubleClicked(QIconViewItem *)),
		SLOT(S_SeleccionaEmpleado(QIconViewItem *)));
connect(QIVInforma,
		SIGNAL(returnPressed(QIconViewItem *)),
		SLOT(S_SeleccionaEmpleado(QIconViewItem *)));

}
EmpresaN *QFirmaTiendas::ObtenExpendio()
{
	return Expendio;
}
Persona *QFirmaTiendas::ObtenEmpleado()
{
	return Empleado;
}
void QFirmaTiendas::CargaPerfil()
{
FILE *lFleArchivo;
char lchrArrNmbAPerfil[1024];
sprintf(lchrArrNmbAPerfil,
	"%s/%s.PerfilSiscomElectronica",
	getenv("HOME"),
	(*Empleado)["Firma"]);
SiscomEscribeLog3Qt("---------------------------------------------------------------");
SiscomDesarrollo3Qt::TipoLetraPerfil(lchrArrNmbAPerfil,&QFLetra);
setFont(QFLetra);
QAPrincipal->setFont(QFLetra);
QWParent->setFont(QFLetra);
}
void QFirmaTiendas::AlmacenaPerfil()
{
FILE *lFleArchivo;
char lchrArrNmbAPerfil[1024];
sprintf(lchrArrNmbAPerfil,
	"%s/%s.PerfilSiscomElectronica",
	getenv("HOME"),
	(*Empleado)["Firma"]);
if((lFleArchivo=fopen(lchrArrNmbAPerfil,"w")))
{
fprintf(lFleArchivo,
	"%s\t%d",
	(const char *)QFLetra.family(),
	QFLetra.pointSize());
fclose(lFleArchivo);
}
else
{
}
}
QServidoresIconView::QServidoresIconView(SiscomDatCom *pSisDatCom,
					 QIconView *pQIconView,
					 const char *pchrPtrNombre):
			QIconViewItem(pQIconView,pchrPtrNombre),
			SisDatCom(pSisDatCom)
{
/*
	setText(QString(pSisDatCom->SiscomObtenDireccionIp()) +
		"\n\n"					      +
		QString().sprintf("%d",pSisDatCom->SiscomObtenPuertoCom()));
*/
	setText(QString(pSisDatCom->SiscomDescripcionServidor()));
}
SiscomDatCom *QServidoresIconView::ObtenServidor()
{
	return SisDatCom;
}
QEmpleadosExpendioIconView::QEmpleadosExpendioIconView(Persona *pPersona,
						       QIconView *pQIView,
						       const char *pchrPtrName):
			QIconViewItem(pQIView,pchrPtrName),
			Empleado(pPersona)
{

	setText(QString(pPersona->SRegistrosPro2["Firma"]));
}
Persona *QEmpleadosExpendioIconView::ObtenEmpleado()
{
	return Empleado;
}



