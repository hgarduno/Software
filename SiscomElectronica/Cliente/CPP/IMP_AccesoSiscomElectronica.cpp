#include <IMP_AccesoSiscomElectronica.h>
#include <IMP_SelExpendios.h>
#include <IMP_FirmaTiendas.h>
#include <IMP_FirmateExpendio.h>
#include<SiscomDesarrollo3Qt++.h>
#include <qmessagebox.h>
#include <qapplication.h>
#include <qfontdialog.h>
#include <EmpresasN.h>
#include <Personas.h>
extern FILE *gPtrFleArchivoLog;
extern FILE *gPtrFleArchivoLog3Qt;

QAccesoSiscomElectronica::QAccesoSiscomElectronica(QApplication *pQAPrincipal,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				AccesoSiscomElectronica(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(0),
				QAPrincipal(pQAPrincipal),
				QWParent(pQWParent),
				intModificoPerfil(0),
				intCancelo(0)
{
setFont(QWParent->font());
if(!gPtrFleArchivoLog)
gPtrFleArchivoLog=stdout;
if(!gPtrFleArchivoLog3Qt)
gPtrFleArchivoLog3Qt=stdout;
IniciaVariables();
ConectaSlots();
exec();
}

QAccesoSiscomElectronica::~QAccesoSiscomElectronica()
{

}
void QAccesoSiscomElectronica::ConectandoIconView(const char *pchrPtrSlot)
{
connect(QIconViewInforma,SIGNAL(clicked(QIconViewItem *)),pchrPtrSlot);
connect(QIconViewInforma,SIGNAL(returnPressed(QIconViewItem *)),pchrPtrSlot);
}
void QAccesoSiscomElectronica::ConectaSlots()
{
	ConectandoIconView(SLOT(SlotTipoExpendio(QIconViewItem *)));
	connect(QPBSLetra,SIGNAL(clicked()),SLOT(SlotTipoLetra()));
	 
}
void QAccesoSiscomElectronica::SlotTipoLetra()
{
bool lbRegreso;
QFLetra=QFontDialog::getFont(&lbRegreso,QFont( "Times", 12 ),this );
setFont(QFLetra);
if(QAPrincipal)
QAPrincipal->setFont(QFLetra);
QWParent->setFont(QFLetra);
intModificoPerfil=1;
}
void QAccesoSiscomElectronica::SlotTipoExpendio(QIconViewItem *pQIconViewItemDato)
{
   disconnect(QIconViewInforma,0,0,0);
   MuestraServidores(((QSisTipoExpendioIconViewItem *)pQIconViewItemDato)->Consecutivo());
}
void QAccesoSiscomElectronica::SlotExpendio(QIconViewItem *pQIconViewItemExpendio)
{
   MuestraExpendiosServidor(((QSisExpendioIconViewItem *)pQIconViewItemExpendio)->Expendio());
}
void QAccesoSiscomElectronica::SlotExpendioServidor(QIconViewItem *pQIconViewItemExpendioServidor)
{
   	disconnect(QIconViewInforma,0,0,0);
 	MuestraEmpleadosExpendio(((QIconVExpendio *)pQIconViewItemExpendioServidor)->ObtenExpendio());
}
void QAccesoSiscomElectronica::SlotSeleccionaEmpleado(QIconViewItem *pQIconViewItemEmpleado)
{
Persona *lPersona=((QEmpleadosExpendioIconView *)pQIconViewItemEmpleado)->ObtenEmpleado();
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
        AlmacenaPerfil();
       else
       CargaPerfil();
     }
done(1);
}
else
{
SiscomEscribeLog3Qt("QFIrmaTiendas::No se definio la variable de ambiente Aplicacion\n");
exit(0);
}
}
void QAccesoSiscomElectronica::MuestraEmpleadosExpendio(EmpresaN *pEmpresaN)
{
ConsultaPersonas lCnsEmpleados;
Personas lEmpleados;
	lCnsEmpleados.EmpleadosExpendio(SisDatCom,
				 	(*pEmpresaN)["IdEmpresa"],
					lEmpleados);
Persona *lEmpleado;
Expendio=pEmpresaN;
QIconViewInforma->clear();
	for(lEmpleado=lEmpleados.first();
	    lEmpleado;
	    lEmpleado=lEmpleados.next())
	  QIconViewInforma->insertItem(new QEmpleadosExpendioIconView(
	  				lEmpleado,
					QIconViewInforma,
					0));
	ConectandoIconView(SLOT(SlotSeleccionaEmpleado(QIconViewItem *)));
}
void QAccesoSiscomElectronica::MuestraExpendiosServidor(SiscomRegistro3 *pSisReg3Expendio)
{
EmpresasN lExpendios;
SisDatCom=new SiscomDatCom(pSisReg3Expendio->CampoAInt("Puerto"),
			   (*pSisReg3Expendio)["DirIp"],
			   (*pSisReg3Expendio)["Expendio"]);
EmpresaN *lEmpresaN;
QIconVExpendio *lQIconVExpendio;
ConsultaEmpresasN lCnsExpendios(SisDatCom,"Expendios",lExpendios);
if(!lCnsExpendios.EstadoConexion())
{
disconnect(QIconViewInforma,0,0,0);
QIconViewInforma->clear();
for(lEmpresaN=lExpendios.first();lEmpresaN;lEmpresaN=lExpendios.next())
{
lQIconVExpendio=new QIconVExpendio(lEmpresaN,QIconViewInforma);
QIconViewInforma->insertItem(lQIconVExpendio);
}
	ConectandoIconView(SLOT(SlotExpendioServidor(QIconViewItem *)));
}
else
{
QMessageBox::information(this,"Aviso Sistema","NO Se pudo conectar al expendio");
}

}
void QAccesoSiscomElectronica::MuestraServidores(int pintCuales)
{
SiscomRegistro3Lst *lSisReg3LstExpendios=CQSExpendios.Expendios(pintCuales);
SiscomRegistro3 *lSisReg3Expendio;
QSisExpendioIconViewItem *lQSisIconViewItemExpendio;
QIconViewInforma->clear();

for(lSisReg3Expendio=lSisReg3LstExpendios->first();
    lSisReg3Expendio;
    lSisReg3Expendio=lSisReg3LstExpendios->next())
{
   lQSisIconViewItemExpendio=new QSisExpendioIconViewItem(lSisReg3Expendio,QIconViewInforma);
   QIconViewInforma->insertItem(lQSisIconViewItemExpendio); 
}

	ConectandoIconView(SLOT(SlotExpendio(QIconViewItem *)));
}
void QAccesoSiscomElectronica::IniciaVariables()
{
char lchrArrArchivo[256];
 ArchivoServidores(lchrArrArchivo);
 CQSExpendios.LeeArchivo(lchrArrArchivo);
 MuestraTiposExpendios();

}
void QAccesoSiscomElectronica::ArchivoServidores(char *pchrPtrArchivo)
{
const char *lchrPtrArchivo=getenv("ServidoresAccesoSistema");
if(lchrPtrArchivo)
 strcpy(pchrPtrArchivo,lchrPtrArchivo);
else
{
  QMessageBox::information(this,"Aviso Sistema","NO Se encontro la variable ServidoresAccesoSistema");
  exit(0);
}

}
void QAccesoSiscomElectronica::MuestraTiposExpendios()
{
int lintContador;
SiscomRegistro3 *lSisReg3TipoExpendio;
QSisTipoExpendioIconViewItem *lQSIconViewItemTipo;
for(CQSExpendios.first(),
    lintContador=0;
    CQSExpendios.current();
    CQSExpendios.next(),
    lintContador++)
{
   lQSIconViewItemTipo=new QSisTipoExpendioIconViewItem(CQSExpendios.RegistroPrincipal(),
   						 	lintContador,
							QIconViewInforma);
    QIconViewInforma->insertItem(lQSIconViewItemTipo);
}
QIconViewInforma->setFocus();
}
SiscomDatCom *QAccesoSiscomElectronica::Servidor()
{
	return SisDatCom;
}
EmpresaN *QAccesoSiscomElectronica::ExpendioSeleccionado()
{
     return Expendio;
}
SiscomRegistro3 *QAccesoSiscomElectronica::ExpendioRegistro3()
{
SiscomRegistro3 *lSisReg3Expendio=new SiscomRegistro3;
(*lSisReg3Expendio) << 
new SiscomCampo3("IdExpendio",(*Expendio)["IdEmpresa"]) <<
new SiscomCampo3("RazonSocial",(*Expendio)["RazonSocial"]);
return lSisReg3Expendio;
}
Persona *QAccesoSiscomElectronica::EmpleadoFirmado()
{
	return Empleado;
}

void QAccesoSiscomElectronica::CargaPerfil()
{
FILE *lFleArchivo;
char lchrArrNmbAPerfil[1024];
sprintf(lchrArrNmbAPerfil,
	"%s/%s.PerfilSiscomElectronica",
	getenv("HOME"),
	(*Empleado)["Firma"]);
SiscomDesarrollo3Qt::TipoLetraPerfil(lchrArrNmbAPerfil,&QFLetra);
setFont(QFLetra);
if(QAPrincipal)
QAPrincipal->setFont(QFLetra);
QWParent->setFont(QFLetra);
}
void QAccesoSiscomElectronica::AlmacenaPerfil()
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
void QAccesoSiscomElectronica::reject()
{
 intCancelo=1;
 done(intCancelo);
}
int QAccesoSiscomElectronica::Cancelo()
{
SiscomEscribeLog3Qt("Estado de Cancelar %d",intCancelo);
    return intCancelo;
}
CQSisExpendiosPorTipo::CQSisExpendiosPorTipo()
{
}
FILE *CQSisExpendiosPorTipo::AbreArchivo(const char *pchrPtrArchivo)
{
FILE *lFlePtrArchivo;
if((lFlePtrArchivo=fopen(pchrPtrArchivo,"r")))
 return lFlePtrArchivo;
else
return 0;
}
void CQSisExpendiosPorTipo::AgregaTipoExpendio(const char *pchrPtrTipoExpendio)
{
SiscomRegistro3 *lSisReg3TipoExpendio=new SiscomRegistro3;
SiscomAgregaRegistro();
(*lSisReg3TipoExpendio) << new SiscomCampo3("TipoExpendio",pchrPtrTipoExpendio);
AgregaDato(lSisReg3TipoExpendio);
}
void CQSisExpendiosPorTipo::LeeArchivo(const char *pchrPtrArchivo)
{
FILE *lFlePtrArchivo;
char lchrArrLinea[256],
	lchrArrTipoExpendio[128],
	*lchrPtrPaso;
if((lFlePtrArchivo=AbreArchivo(pchrPtrArchivo)))
{
   while(!SiscomDesarrollo3Qt::LeeLinea(lFlePtrArchivo,lchrArrLinea))
   {
	lchrPtrPaso=lchrArrLinea;
	if(*lchrPtrPaso=='[')
	{
	SiscomDesarrollo3Qt::CadenaEntreSeparadores(lchrArrLinea,'[',']',lchrArrTipoExpendio);
	AgregaTipoExpendio(lchrArrTipoExpendio);
	}
	else
	{
	AgregaExpendio(lchrArrLinea);
	}
   }
}
}
SiscomRegistro3 *CQSisExpendiosPorTipo::DatosExpendio(const char *pchrPtrLinea)
{
int lintContadorCampo=0;
char lchrArrCampo[128],
	*lchrPtrCampo=lchrArrCampo;
SiscomAgregaSubRegistro();
SiscomRegistro3 *lSisReg3Expendio=new SiscomRegistro3;
		while(*pchrPtrLinea)
		{
		 *lchrPtrCampo=*pchrPtrLinea; 
		  if(*pchrPtrLinea=='@')
		  {
		   *lchrPtrCampo=0;
		   lchrPtrCampo=lchrArrCampo;
		   if(lintContadorCampo==0)
		   (*lSisReg3Expendio) << new SiscomCampo3("DirIp",lchrArrCampo);
		    if(lintContadorCampo==1)
		   (*lSisReg3Expendio) << new SiscomCampo3("Puerto",lchrArrCampo);
		    lintContadorCampo++;
		 	pchrPtrLinea++;
		  }
		  else
		  {
		 pchrPtrLinea++;
		 lchrPtrCampo++;
		 }
		}
		   *lchrPtrCampo=0;
		    if(lintContadorCampo==2)
		    (*lSisReg3Expendio) << new SiscomCampo3("Expendio",lchrArrCampo);
 return lSisReg3Expendio;
}
void CQSisExpendiosPorTipo::AgregaExpendio(const char *pchrPtrLinea)
{
SiscomRegistro3 *lSisReg3Expendio;
		lSisReg3Expendio=DatosExpendio(pchrPtrLinea);
 
 SiscomAgregaRegistro(1,lSisReg3Expendio);
}
SiscomRegistro3Lst *CQSisExpendiosPorTipo::Expendios(int pintTipoExpendio)
{
  return RegistrosSubGrupo(pintTipoExpendio,1);
}

QSisTipoExpendioIconViewItem::QSisTipoExpendioIconViewItem(
					SiscomRegistro3 *pSisRegTipoExpendio,
					int pintConsecutivo,
					QIconView *pQIconViewDatos):
					intConsecutivo(pintConsecutivo),
					QIconViewItem(pQIconViewDatos)
{
	setText((*pSisRegTipoExpendio)["TipoExpendio"]);
}
int QSisTipoExpendioIconViewItem::Consecutivo()
{
return intConsecutivo;
}

QSisExpendioIconViewItem::QSisExpendioIconViewItem(SiscomRegistro3 *pSisReg3Expendio,
						   QIconView *pQIconViewDatos):
				SisReg3Expendio(pSisReg3Expendio),
				QIconViewItem(pQIconViewDatos)
{
	setText((*SisReg3Expendio)["Expendio"]);
}
SiscomRegistro3 *QSisExpendioIconViewItem::Expendio()
{
	return SisReg3Expendio;
}



