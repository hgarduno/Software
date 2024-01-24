
#ifndef __IMP_FACTURANDO_H__
#define __IMP_FACTURANDO_H__
#include <qwidget.h>
#include <qdialog.h>
#include <ProductosE.h>
class QTable;
class SiscomDatCom;
class QImprimeFactura;
class QVBoxLayout;
class QGridLayout;
class QLineEdit;
class QScrollView;
class QVBox;
class QSpacerItem;
class QFacturando:public QDialog
{
 Q_OBJECT
public:
	QFacturando(const char *,
		    const char *,
		    const ProductosE &,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pBModal=false,
	    WFlags pWFlags=0);
	~QFacturando();
private:
	const char *chrPtrCliente;
	const char *chrPtrRFC;
	ProductosE PProductos;
	QImprimeFactura *QIFactura;
	QGridLayout *QHBRegilla;
	QPushButton *QPBImprime;
	QSpacerItem *QSSeparador;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
#endif
