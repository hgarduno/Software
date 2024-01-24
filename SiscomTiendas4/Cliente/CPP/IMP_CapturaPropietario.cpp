#include <IMP_CapturaPropietario.h>
#include <IMP_QControlNombres.h>
#include<SISCOMComunicaciones++.h>
#include <QSisDirecciones.h>
#include <QSisTelefonos.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSisClientes3Qt.h>
#include <CQSisDirecciones.h>
#include <SisMedioComunicacion.h>
QCapturaPropietario::QCapturaPropietario(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CapturaPropietario(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCapturaPropietario::~QCapturaPropietario()
{

}

void QCapturaPropietario::ConectaSlots()
{
connect(QCtrPropietario,
	SIGNAL(SignalEnterAMaterno()),
	SLOT(SlotPasaFocoRegistrarPropietario()));
connect(QPBRegistrarP,
	SIGNAL(clicked()),
	SLOT(SlotRegistrarP()));
connect(QPBAceptar,
	SIGNAL(clicked()),
	SLOT(SlotAceptar()));
}
void QCapturaPropietario::SlotAceptar()
{
done(1);
}
void QCapturaPropietario::SlotRegistrarP()
{
RegistraPropietario();
SiscomDesarrollo3Qt::PasaFocoControl(QCtrDirecciones);

}
void QCapturaPropietario::SlotPasaFocoRegistrarPropietario()
{
SiscomDesarrollo3Qt::PasaFocoControl(QPBRegistrarP);
}
void QCapturaPropietario::SlotPasaFocoDirecciones()
{
QCtrDirecciones->setFocus();
}
void QCapturaPropietario::IniciaVariables()
{
QCtrPropietario->setFocus();
QCtrDirecciones->Servidor(SisDatCom);
QCtrDirecciones->Argumentos(chrPtrArgumentos);
QCtrDirecciones->SistemaConsulta("ConsultaTiendas4");
QCtrDirecciones->IniciaControl();
QCtrTelefonos->Servidor(SisDatCom);
QCtrTelefonos->SistemaConsulta("ConsultaTiendas4");
}
CQSisCliente3Qt *QCapturaPropietario::Propietario()
{
return new CQSisCliente3Qt("",
			   QCtrPropietario->ObtenNombre(),
			   QCtrPropietario->ObtenAPaterno(),
			   QCtrPropietario->ObtenAMaterno());
}
void QCapturaPropietario::RegistraPropietario()
{
int lintRegistraPropietario;
CQSisClienteOp3Qt lCQSOpCliente(SisDatCom);
CQSC3QtPropietario=Propietario();
lintRegistraPropietario=lCQSOpCliente.RegistraPropietario(CQSC3QtPropietario);
QCtrDirecciones->IdPersona((*CQSC3QtPropietario)["IdPersona"]);
QCtrTelefonos->IdPersona((*CQSC3QtPropietario)["IdPersona"]);
if(lintRegistraPropietario)
{
QCtrDirecciones->DireccionesPersona();
QCtrTelefonos->TelefonosRegistrados();
}

SiscomEscribeLog3Qt("El Propietario:%s",(*CQSC3QtPropietario)["IdPersona"]);

}

void QCapturaPropietario::Propietario(char *pchrPtrPropietario)
{
sprintf(pchrPtrPropietario,
	"%s %s %s",
	QCtrPropietario->ObtenNombre(),
	QCtrPropietario->ObtenAPaterno(),
	QCtrPropietario->ObtenAMaterno());
}
void QCapturaPropietario::Direcciones(CQSisLstDireccion *pCQSLDirecciones)
{
  QCtrDirecciones->Direcciones(pCQSLDirecciones);
}
void QCapturaPropietario::Telefonos(SisLstMedCom *pSLMCom)
{
	QCtrTelefonos->Telefonos(pSLMCom);
}
