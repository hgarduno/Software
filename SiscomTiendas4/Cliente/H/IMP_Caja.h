#ifndef __IMP_CAJA_H__
#define __IMP_CAJA_H__
#include <UIC_H_Caja.h>
#include <CQSisProdCotiza.h>
#include <Seguridad3Protocolo2.h>
class SiscomDatCom;
class CQSisOrden;
class QVentas;
class QCaja:public Caja /*,private Seguridad3Protocolo2 */
{
 Q_OBJECT
public:
	QCaja(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QCaja();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	QWidget *QWParent;
	CQSisOrden *CQSOrden;
	CQSisLstProdCotiza CQSLPCotiza;
	QVentas *QVOrden;
	CQSisEmpleado *CQSEmpleado;
	int intSePuedeMOrden;

private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultaOrden();
	void MuestraOrden();
	void ConsultandoOrden();
	void RegistraVenta();
	void HabilitaBotones();
	void IniciaSistemaSeguridad3();
	void closeEvent(QCloseEvent *);

private slots:
	void SlotOrdenes();
	void SlotOrden(CQSisOrden *);
	void SlotMOrden();
	void SlotRealizoOperacion(QVentas *);
	void SlotRegistraVenta();

	void SlotPasaFocoFechaFin();
	void SlotPasaFocoOrdenes();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QCaja *InstanciaCaja(void *,char **,void *,const char *,int);
#endif
