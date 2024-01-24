
#ifndef __IMP_PRECIOPRODUCTO_H__
#define __IMP_PRECIOPRODUCTO_H__
#include <UIC_H_PrecioProducto.h>
#include <CQSisDatoPrecio.h>
class SiscomDatCom;
class CQSisPrecio;
class CQSisProducto;
class QPrecioProducto:public PrecioProducto
{
 Q_OBJECT
public:
	QPrecioProducto(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QPrecioProducto();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisPrecio *CQSPrecio;
	CQSisProducto *CQSProducto;
	CQSisLstDatoPrecio CQSLDPrecio;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraDescripcion();
	void MuestraDescripcionPrecio();
	void ConsultandoPreciosProducto();
	void ConsultaPreciosProducto();
	void MuestraPreciosProducto();
	void ActualizaPrecio();
	void closeEvent(QCloseEvent *);
	
private slots:
	void SlotPrecio(CQSisPrecio *);
	void SlotProducto(CQSisProducto *);
	void SlotIniciaPrecios();
	void SlotPasaFocoActualiza();
	void SlotActualiza();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QPrecioProducto *InstanciaPrecioProducto(void *,char **,void *,const char *,int);
#endif
