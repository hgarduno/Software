
#ifndef __IMP_EXISTENCIASISCOM_H__
#define __IMP_EXISTENCIASISCOM_H__
#include <QtExistenciaSiscom.h>
class SiscomDatCom;

class zExistenciaVenta;
class QExistenciaSiscom:public QtExistenciaSiscom
{
 Q_OBJECT
public:
	QExistenciaSiscom(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QExistenciaSiscom();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zExistenciaVenta *zExistenciaV;	

private:
	void ProductosSiscom();
	void ConsultaProductos();
	void ConsultandoProductos();
	void IniciaVariables();
	void IniciaExistenciaVenta();
	zExistenciaVenta *ExistenciaVenta();
	void ConsultaTodo();
	void GuardaArchivo();
private slots:
};
extern "C" QExistenciaSiscom *InstanciaExistenciaSiscom(void *,char **,void *,const char *,int);
#endif
