#include <IMP_ConExpendiosVenta.h>
#include <IMP_AccesoSiscomElectronica.h>

#include <zSiscomQt3.h>

#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zExpendio.h>
#include <zConexionExpendio.h>

#include <SiscomRegistros3.h>

#include <SiscomDatCom.h>

#include <qlineedit.h>
#include <qpushbutton.h>
#include <qtable.h>
QConExpendiosVenta::QConExpendiosVenta(zSiscomConexion *pzSiscomConexion,
				       char **pchrPtrArgumentos,
				      QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				ConExpendiosVenta(pQWParent,pchrPtrName,pbModal,pWFlags),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion(pzSiscomConexion),
				intDejaPrecios(0)
{
IniciaVariables();
ConectaSlots();
Muestra();
}

QConExpendiosVenta::~QConExpendiosVenta()
{

}
void QConExpendiosVenta::MuestraExpendios()
{
const char *lchrPtrCampos[]={"RazonSocial",0};
 zSiscomQt3::LlenaTabla(lchrPtrCampos,&zExpsSiscom,QTExpendios);
}
void QConExpendiosVenta::Muestra()
{
QLEPrincipal->setText(zExpsSiscom.RazonSocialPrincipal());
}
void QConExpendiosVenta::ConectaSlots()
{
connect(QPBOExpendio,SIGNAL(clicked()),SLOT(SlotOExpendio()));
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
connect(QPBDejaPrecios,SIGNAL(clicked()),SLOT(SlotDejaPrecios()));
connect(QTExpendios,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotExpendio(int,int,int,const QPoint &)));
}
void QConExpendiosVenta::SlotDejaPrecios()
{
intDejaPrecios=1;    
}
void QConExpendiosVenta::SlotAceptar()
{
     done(1);
}
void QConExpendiosVenta::SlotExpendio(int pintNExpendio,
				      int,
				      int,
				      const QPoint &)
{
  if(pintNExpendio!=-1)
  {
   zExActual=(zExpendio *)zExpsSiscom[pintNExpendio];
   QTExpendios->selectRow(pintNExpendio);  
   QPBAceptar->setEnabled(true);
   FocoAAceptar();
  }
}
void QConExpendiosVenta::FocoAAceptar()
{
   QPBAceptar->setText(QString("Aceptar") +
   		       " "		  +
		       zExActual->RazonSocial());

  zSiscomQt3::Foco(QPBAceptar);
}
void QConExpendiosVenta::SlotOExpendio()
{
  Seleccionando();
  done(1);
}
void QConExpendiosVenta::IniciaVariables()
{
  ExpendioPrincipal();
  zExActual=zExpsSiscom.Principal();
}
int QConExpendiosVenta::Corriendo()
{
  intDejaPrecios=0;
  
   if(!SeCambioExpendio())
   Seleccionando();
   else
   {
   MuestraExpendios();
   /*
   exec();
   */
   }


}
int QConExpendiosVenta::SeCambioExpendio()
{
   return zExpsSiscom.NNodos()>1;
}
void QConExpendiosVenta::ExpendioPrincipal()
{
zExpendio *lzExpendio=new zExpendio;
 lzExpendio->DirIp(zSisConexion->DireccionIp());
 lzExpendio->Puerto(zSisConexion->Puerto());
 lzExpendio->RazonSocial(Expendio());
 lzExpendio->IdExpendio(IdExpendio());
 zExpsSiscom.Principal(new zConexionExpendio(lzExpendio));
}
int QConExpendiosVenta::Seleccionando()
{
EmpresaN *lEExpendio;
QAccesoSiscomElectronica lQAccSisEle(0,this);
if(!lQAccSisEle.Cancelo())
{
lEExpendio=lQAccSisEle.ExpendioSeleccionado();
OtroExpendio(lQAccSisEle.ExpendioRegistro3(),lQAccSisEle.Servidor());
return 0;
}
return 1;
}
const char *QConExpendiosVenta::IdExpendio()
{
SiscomRegistro3 *lSisRegEmpresa=(SiscomRegistro3 *)(*(chrPtrArgumentos+5));
return (*lSisRegEmpresa)["IdExpendio"];
}
const char *QConExpendiosVenta::Expendio()
{
SiscomRegistro3 *lSisRegEmpresa=(SiscomRegistro3 *)(*(chrPtrArgumentos+5));
return (*lSisRegEmpresa)["RazonSocial"];
}
void QConExpendiosVenta::OtroExpendio(SiscomRegistro3 *pSisReg3Expendio,
				   SiscomDatCom *pSisDatCom)
{
  zExActual=new zExpendio;
  zExActual->RazonSocial((*pSisReg3Expendio)["RazonSocial"]);
  zExActual->DirIp(pSisDatCom->SiscomObtenDireccionIp());
  zExActual->Puerto(pSisDatCom->SiscomObtenPuertoCom());
  zExActual->IdExpendio((*pSisReg3Expendio)["IdExpendio"]);
  zExpsSiscom.Agrega(new zConexionExpendio(zExActual));
  /*
  LogSiscom("Expendio %s : %s ", 
  	    (*pSisReg3Expendio)["RazonSocial"],
  	    (*pSisReg3Expendio)["IdExpendio"]);
*/
}
const char *QConExpendiosVenta::DireccionIp()
{
   return zExActual->DirIp();    
}
int QConExpendiosVenta::Puerto()
{
   return zExActual->PuertoInt();
}
const char *QConExpendiosVenta::IdExpendioActual()
{
   return zExActual->IdExpendio();
}
int QConExpendiosVenta::EsPrincipal()
{
  return zExActual==zExpsSiscom[0] ;
}


int QConExpendiosVenta::DejaPrecios()
{
   return intDejaPrecios;
}
zConexionExpendio *QConExpendiosVenta::Expendio(int pintNExpendio)
{
     zExActual=zExpsSiscom.Expendio(pintNExpendio);
	return (zConexionExpendio *)zExActual;
}
zConexionExpendio *QConExpendiosVenta::Actual()
{
   return (zConexionExpendio *)zExpsSiscom.Actual();
}
