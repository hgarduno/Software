#ifndef __QSISMANDIRECCIONES_H__
#define __QSISMANDIRECCIONES_H__
#include <qpopupmenu.h>
class SiscomDatCom;
class QSisManDirecciones:public QPopupMenu
{
Q_OBJECT
public:
	QSisManDirecciones(const QPoint &pQPPosicion,
			   const char *pchrPtrIdPersona,
			   SiscomDatCom *pSisDatCom,
			   char **pchrPtrArgumentos,
			   QWidget *pQWParent=0,
			   const char *pchrPtrNombre=0);

	int EdoOperacion();
private:
	char **chrPtrArgumentos;
	SiscomDatCom *SisDatCom;
	const char *chrPtrIdPersona;
	int intEdoOperacion;
private:
	void Opciones();
	void ConectaSlots();
	void AnexarDireccion();
private slots:
	void SlotSelecciona(int);
};

#endif
