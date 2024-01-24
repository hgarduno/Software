#include <IMP_SeleccionaInventario.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSis3QtComunes.h>

#include <qtable.h>
QSeleccionaInventario::QSeleccionaInventario(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				SeleccionaInventario(pQWParent,
						     pchrPtrName,
						     pbModal,
						     pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				SisReg3Inventario(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QSeleccionaInventario::~QSeleccionaInventario()
{

}
void QSeleccionaInventario::SlotSeleccionaInventario(int pintFila,
						     int,
						     int,
						     const QPoint &)
{
	SisReg3Inventario=SisReg3InventariosProg[pintFila];
	done(1);
}
void QSeleccionaInventario::ConectaSlots()
{
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionaInventario(int ,int,int,const QPoint &)));
}
void QSeleccionaInventario::IniciaVariables()
{
Consultando();
}

void QSeleccionaInventario::Consulta()
{
CQSis3QtComunes lCQS3QtConsulta(SisDatCom);

lCQS3QtConsulta.InventariosProgramados(chrPtrArgumentos[0],
					&SisReg3InventariosProg);
SiscomRegistro3LstContenido(&SisReg3InventariosProg);
}

void QSeleccionaInventario::Consultando()
{
Consulta();
Muestra();
}
void QSeleccionaInventario::Muestra()
{
const char *lchrArrColumnas[]={"descripcion",	
			 "fechainicio",
			 "fechafin",
			 0
			 };
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrArrColumnas,
					QTDatos,
					&SisReg3InventariosProg);

}

SiscomRegistro3 *QSeleccionaInventario::Inventario()
{
return SisReg3Inventario;
}
