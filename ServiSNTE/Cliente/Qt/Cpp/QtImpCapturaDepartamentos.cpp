#include <QtImpCapturaDepartamentos.h>

#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>

#include <zOperacionesServiSNTE.h>

#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <zDepartamento.h> 
#include <qlineedit.h> 
#include <qcheckbox.h> 
#include <qpushbutton.h>
QtImpCapturaDepartamentos::QtImpCapturaDepartamentos(QWidget *pQWParent,
				     const char *pchrPtrName):
				     CapturaDepartamentos(pQWParent,pchrPtrName),
				     zDatDepartamento(0)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 ConectaSlots();

}

void QtImpCapturaDepartamentos::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpCapturaDepartamentos::ConectaSlots()
{
	connect(QPBCrear,
		SIGNAL(clicked()),
		SLOT(SlotCrear()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QLEDepartamento,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAAbreviatura()));
	connect(QLEAbreviatura,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoANombreDepartamento()));
	connect(QLENombreDepartamento,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoACrear()));
}

void QtImpCapturaDepartamentos::SlotFocoAAbreviatura()
{
	zSiscomQt3::Foco(QLEAbreviatura);
}
void QtImpCapturaDepartamentos::SlotFocoANombreDepartamento()
{
	zSiscomQt3::Foco(QLENombreDepartamento);
}
void QtImpCapturaDepartamentos::SlotFocoACrear()
{
	zSiscomQt3::Foco(QPBCrear);
}
void QtImpCapturaDepartamentos::reject()
{
}
void QtImpCapturaDepartamentos::SlotCrear()
{
	zDatDepartamento=FormaDepartamento();
	
	zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"RegistraDepartamento");
	lzOpServiSNTE.RegistraDepartamento(zDatDepartamento);
}
void QtImpCapturaDepartamentos::SlotCancelar()
{
}
zDepartamento *QtImpCapturaDepartamentos::FormaDepartamento()
{
	return new zDepartamento(0,
		      zSiscomQt3::Texto(QLEAbreviatura),
		      zSiscomQt3::Texto(QLENombreDepartamento));
}
zDepartamento *QtImpCapturaDepartamentos::Departamento()
{
	return zDatDepartamento;
}
