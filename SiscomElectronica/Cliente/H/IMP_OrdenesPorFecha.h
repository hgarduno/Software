#ifndef __IMP_ORDENESPORFECHA_H__
#define __IMP_ORDENESPORFECHA_H__
#include <UIC_H_OrdenesPorFecha.h>
#include <ControladorOrdenes.h>
class SiscomDatCom;
class QOrdenesPorFecha:public OrdenesPorFecha
{
 Q_OBJECT
public:
	QOrdenesPorFecha(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QOrdenesPorFecha();
	 void ObtenOrdenesSeleccionadas(GeneralesOrden &);
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	GeneralesOrden GOrden;
	GeneralesOrden GOrdenSel;

private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultaPorRangoFechas(const char *,
				    const char *,
				    GeneralesOrden *);
	void MuestraInformacion(GeneralesOrden );
private slots:
	void S_SeleccionaOrdenes();
};
#endif
