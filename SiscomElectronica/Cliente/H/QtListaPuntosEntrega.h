#ifndef __QTLISTAPUNTOSENTREGA_H__
#define __QTLISTAPUNTOSENTREGA_H__
#include <UIC_H_ListaPuntosEntrega.h>


class zPuntosEntrega;
class zPuntoEntrega;

class QtListaPuntosEntrega:public ListaPuntosEntrega
{
Q_OBJECT
public:
	QtListaPuntosEntrega(QWidget *pQWParent,
			     const char *pchrPtrNombre,
			     bool pbModal,
			     WFlags pWFlags);
	void ConectaSlots();
	void IniciaVariables();
	void Muestra();
	void PuntosEntrega(zPuntosEntrega *pzPsEntrega);
	void reject();
	zPuntoEntrega *PuntoEntrega();
	int Aceptar();
private:
	zPuntosEntrega *zPsEntrega;
	zPuntoEntrega *zPEntrega;
	int intAceptar;
private:
	void Descripcion(zPuntoEntrega *,char *pchrPtrDescripcion);
	void Referencias(int );
private slots:
	void SlotPuntoEntrega(int,int,int,const QPoint &);
	void SlotAceptar();
	void SlotCancelar();
};

#endif
