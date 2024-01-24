#include <IMP_RegistraCostoCurso.h>
#include <QCtrlExplicacionPromocion.h>
#include <CQSisCostoCurso.h>
#include <CQSis3QtOperaciones.h>
#include <SiscomRegistros.h>


#include <SiscomDesarrollo3Qt++.h>

#include <qlineedit.h>
#include <qpushbutton.h>
#include <qtable.h>
QRegistraCostoCurso::QRegistraCostoCurso(const char *pchrPtrIdProgramacion,
					 const char *pchrPtrIdCurso,
					 const char *pchrPtrCurso,
					SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool   pbModal,
				    WFlags pWFlags):	      
				RegistraCostoCurso(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				chrPtrIdProgramacion(pchrPtrIdProgramacion),
				chrPtrIdCurso(pchrPtrIdCurso),
				chrPtrCurso(pchrPtrCurso),
				SisReg3ExPromocion(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QRegistraCostoCurso::~QRegistraCostoCurso()
{

}

void QRegistraCostoCurso::ConectaSlots()
{
connect(QCtrExPromocion,
	SIGNAL(SignalExplicacionPromocion(SiscomRegistro3 *)),
	SLOT(SlotExplicacionPromocion(SiscomRegistro3 *)));
connect(QLECosto,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoAAnexar()));
connect(QPBAnexar,
	SIGNAL(clicked()),
	SLOT(SlotAnexarPrecio()));
connect(QPBRegPrecios,
	SIGNAL(clicked()),
	SLOT(SlotRegistraPrecios()));
connect(QPBTerminar,
	SIGNAL(clicked()),
	SLOT(SlotTerminar()));
}
void QRegistraCostoCurso::SlotRegistraPrecios()
{
CQSis3QtOperaciones lCQS3QtRegPrecios(SisDatCom);
lCQS3QtRegPrecios.CostosCurso(CQSCostoCurso);
SiscomDesarrollo3Qt::FocoAControl(QPBTerminar);
}
void QRegistraCostoCurso::SlotTerminar()
{
  done(1);
}
void QRegistraCostoCurso::SlotAnexarPrecio()
{
    CQSCostoCurso->CostoAlCurso((*SisReg3ExPromocion)["idestatus"],
    				(*SisReg3ExPromocion)["explicacion"],
    				(const char *)QLECosto->text());
    CostosCurso();
    FocoAPromocion();
}
void QRegistraCostoCurso::SlotFocoAAnexar()
{
  HabilitaAnexar();
  SiscomDesarrollo3Qt::FocoAControl(QPBAnexar);
}
void QRegistraCostoCurso::SlotExplicacionPromocion(SiscomRegistro3 *pSisReg3ExPromocion)
{
  SisReg3ExPromocion=pSisReg3ExPromocion;
  SiscomDesarrollo3Qt::FocoAControl(QLECosto);
  HabilitaAnexar();
}
void QRegistraCostoCurso::IniciaVariables()
{
QCtrExPromocion->Servidor(SisDatCom);
QCtrExPromocion->IniciaControl();
QLECurso->setText(chrPtrCurso);
SiscomDesarrollo3Qt::FocoAControl(QCtrExPromocion);
CQSCostoCurso=new CQSisCostoCurso(chrPtrIdProgramacion,
				  chrPtrIdCurso);
}

void QRegistraCostoCurso::CostosCurso()
{
const char *lchrPtrCostos[]={"Promocion",
			     "Costo",
			     0};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCostos,
					QTCCurso,
					CQSCostoCurso);
				       
SiscomDesarrollo3Qt::AjustaColumnas(QTCCurso);
}

void QRegistraCostoCurso::HabilitaAnexar()
{
 QPBAnexar->setEnabled(SisReg3ExPromocion &&
       		       !QLECosto->text().isEmpty());
}
void QRegistraCostoCurso::FocoAPromocion()
{
    SisReg3ExPromocion=0;
    SiscomDesarrollo3Qt::FocoAControl(QCtrExPromocion);
    QPBAnexar->setEnabled(false);
}
