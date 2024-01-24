#ifndef __CQSISPRECIOSTABLA_H__
#define __CQSISPRECIOSTABLA_H__
#include <qcombobox.h>
class CQSisLstPrecio;
class CQSisPrecio;
class CQSisPreciosTabla:public QComboBox
{
Q_OBJECT
public:
	CQSisPreciosTabla(CQSisLstPrecio *,
			  QWidget *,
			  int,
			  int);
	~CQSisPreciosTabla();
	int Fila();
	int Columna();
private:
	CQSisLstPrecio *CQSLPrecios;
	int intFila;
	int intColumna;
private:
	void MuestraPrecios();
	QStringList QSLPrecios;
private slots:
	void SlotPrecio(int);
signals:
	void SignalPrecio(CQSisPrecio *,int,int);
};

#endif
