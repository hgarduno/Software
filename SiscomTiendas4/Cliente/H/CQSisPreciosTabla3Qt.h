#ifndef __CQSISPRECIOSTABLA3QT_H__
#define __CQSISPRECIOSTABLA3QT_H__
#include <qcombobox.h>
class SiscomRegistro3Lst;
class SiscomRegistro3;

class CQSisPreciosTabla3Qt:public QComboBox
{
Q_OBJECT
public:
	CQSisPreciosTabla3Qt(SiscomRegistro3Lst *pSReg3PreciosLst,
			     SiscomRegistro3 *pSReg3Producto,
			     QWidget *pQWParent,
			     int pintFila,
			     int pintNColumna);
	~CQSisPreciosTabla3Qt();
	int Fila();
	int Columna();
private:
	SiscomRegistro3Lst *SReg3PreciosLst;
	SiscomRegistro3 *SReg3Producto;
	int intFila;
	int intColumna;
private:
	void MuestraPrecios();
private slots:
	void SlotPrecio(int );
signals:
	void SignalCambioTipoPrecio(SiscomRegistro3 *,int,int);
};
#endif
