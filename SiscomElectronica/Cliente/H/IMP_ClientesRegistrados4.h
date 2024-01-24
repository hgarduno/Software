
#ifndef __IMP_CLIENTESREGISTRADOS4_H__
#define __IMP_CLIENTESREGISTRADOS4_H__
#include <UIC_H_ClientesRegistrados4.h>

class zSiscomRegistros;
class zSiscomRegistro;
class zClienteSiscom;

class zClientesSiscom;
class QClientesRegistrados4:public ClientesRegistrados4
{
 Q_OBJECT
public:
	QClientesRegistrados4(
	   zClientesSiscom *pzClisSiscom,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QClientesRegistrados4();
	zClienteSiscom *Cliente();
	int Aceptar();
private:
	zClientesSiscom *zClisSiscom;
	/* 21 de diciembre del 2023 
	 * Siscom Ecatepec
	 * zSiscomRegistro *zSisRegCliente;
         *
	 */
	zClienteSiscom *zCliSiscom;
	int intAceptar;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Muestra();
	void reject();
	QString NombreCompleto(zClienteSiscom *);
	void MuestraTelefonos(int,zClienteSiscom *);
private slots:
	void SlotAceptar();
	void SlotCliente(int,int,int,const QPoint &);
	void SlotSeleccionoCliente(int,int,int,const QPoint &);
	void SlotCancelar();
};
#endif
