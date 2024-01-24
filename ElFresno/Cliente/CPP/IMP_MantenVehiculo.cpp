#include <IMP_MantenVehiculo.h>

#include <Vehiculos.h>
#include <VehiculosProt2.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QMantenVehiculo::QMantenVehiculo(SiscomDatCom *pSDatCom,
			         Vehiculo *pVehiculo,
				 QWidget* parent,
				  const char* name,
				  bool modal, WFlags fl )
    : MantenVehiculo( parent, name, modal, fl ),
      SDatCom(pSDatCom),
      VVehiculo(pVehiculo)
{
	ConectaSlots();
	MuestraDatos();
	exec();
	
}

QMantenVehiculo::~QMantenVehiculo()
{
}
void QMantenVehiculo::MuestraDatos()
{
	QLEPlacas->setText(VVehiculo->ObtenPlacas());
	QLEDescripcion->setText(VVehiculo->ObtenDescripcion());

}
void QMantenVehiculo::ConectaSlots()
{
	connect(QPBModifica,
		SIGNAL(clicked()),
		SLOT(S_Modificar()));
	connect(QPBEliminar,
		SIGNAL(clicked()),
		SLOT(S_Eliminar()));
}
void QMantenVehiculo::S_Modificar()
{
QPtrList <VehiculoProt2> lQPtrLVehiculo;

	    lQPtrLVehiculo.append(new VehiculoProt2(
	    				VVehiculo->ObtenIdVehiculo(),
	    				(const char *)QLEPlacas->text(),
					(const char *)QLEDescripcion->text()));
SiscomGeneralOperacionesSrv lSGenOperaciones(SDatCom,
					     (QPtrList<SiscomInformacion > *)&lQPtrLVehiculo);

			lSGenOperaciones.SiscomEjecutaEnvio("ModificaVehiculo");
	done(1);
}
void QMantenVehiculo::S_Eliminar()
{
QPtrList <VehiculoProt2> lQPtrLVehiculo;

	    lQPtrLVehiculo.append(new VehiculoProt2(
	    				VVehiculo->ObtenIdVehiculo(),
	    				"",
					""));
SiscomGeneralOperacionesSrv lSGenOperaciones(SDatCom,
					     (QPtrList<SiscomInformacion > *)&lQPtrLVehiculo);

			lSGenOperaciones.SiscomEjecutaEnvio("EliminaVehiculo");
	done(1);

}
void QMantenVehiculo::S_Cancelar()
{

}

