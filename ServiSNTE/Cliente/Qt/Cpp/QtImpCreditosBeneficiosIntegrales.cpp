#include <QtImpCreditosBeneficiosIntegrales.h>

#include <zOperacionesServiSNTE.h>
#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>
#include <qpushbutton.h>
#include <qtable.h>
QtImpCreditosBeneficiosIntegrales::QtImpCreditosBeneficiosIntegrales(
					QWidget *pQWParent,
					const char *pchrPtrName,
					bool pbModal,
					WFlags pWFlags):
					CreditosBeneficiosIntegrales(pQWParent,
								     pchrPtrName,
								     pbModal,
								     pWFlags),
								     intAceptar(0)
{

Conexion((zSiscomConexion *)gzSiscomConexion);
ConectaSlots();
IniciaVariables();
exec();
}
void QtImpCreditosBeneficiosIntegrales::IniciaVariables()
{
	Consultando();

}
void QtImpCreditosBeneficiosIntegrales::Conexion(zSiscomConexion *pzSiscomConexion)
{
   zSisConexion=pzSiscomConexion;
}
void QtImpCreditosBeneficiosIntegrales::reject()
{

}
void QtImpCreditosBeneficiosIntegrales::ConectaSlots()
{
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QTCreditos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionaCredito(int,int,int,const QPoint &)));
}
void QtImpCreditosBeneficiosIntegrales::SlotAceptar()
{
	if(intCreditoSeleccionado!=-1)
	{
		zSisCredito=(*zSisRegsCreditos)[intCreditoSeleccionado];
		done(1);
	}
}
void QtImpCreditosBeneficiosIntegrales::SlotSeleccionaCredito(int pintNCredito,
							      int,
							      int,
							      const QPoint &)
{
	QTCreditos->selectRow(pintNCredito);
	zSiscomQt3::Foco(QPBAceptar);
	intCreditoSeleccionado=pintNCredito;

}
void QtImpCreditosBeneficiosIntegrales::SlotCancelar()
{
   intAceptar=0;
   done(0);
}
int QtImpCreditosBeneficiosIntegrales::Consultando()
{
	if(Consulta())
	{
	Muestra();
	return 1;
	}
	else
	{
	return 0;
	}
}

int QtImpCreditosBeneficiosIntegrales::Consulta()
{
 zOperacionesServiSNTE lzSisOpeServiSNTE(zSisConexion,"CreditosBeneficiosIntegrales");
 if((zSisRegCredsBeneficios=lzSisOpeServiSNTE.CreditosBeneficiosIntegrales()))
 return 1;
 else
 return 0;
}
void QtImpCreditosBeneficiosIntegrales::Muestra()
{
const char *lchrPtrCampos[]={"total",
		 	"pagototal",
			"pagoquincenal",
			"plazo",
			"porcentajetasa",
			"completo",
			"rfc",
			0};
zSisRegsCreditos=zSisRegCredsBeneficios->AsociadosDelCampo("CreditosBeneficios");
zSiscomQt3::LlenaTabla(lchrPtrCampos,
			zSisRegsCreditos,	
			QTCreditos);
}
zSiscomRegistro *QtImpCreditosBeneficiosIntegrales::Credito()
{
	return zSisCredito;
}
int QtImpCreditosBeneficiosIntegrales::Aceptar()
{
	return intAceptar;
}
