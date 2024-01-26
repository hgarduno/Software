#ifndef __QTIMPRIMIENDOREPORTE_H__
#define __QTIMPRIMIENDOREPORTE_H__
#include <qdialog.h>

class QVBoxLayout;
class QPushButton;
class QtImprimeReporte;
class zSiscomRegistros;
class zSiscomConexion;
class QtImprimiendoReporte:public QDialog
{
Q_OBJECT
public:
	QtImprimiendoReporte(zSiscomConexion *pzSisConexion,
						   zSiscomRegistros *pzSisRegsInformacion,
						   QWidget *pQWParent=0,
						   const char *pchrPtrName=0,
						   bool pbModal=false,
						   WFlags pWFlags=false);
	void Iniciando();
	
virtual	QtImprimeReporte *ControlReporte();
private:
	QVBoxLayout *QVBLayout;
	QPushButton *QPBImprimir;
	QtImprimeReporte *QtImpReporte;
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsInformacion;
private:
	void ColocaControles();
	void ConectaSlots();
	int ImprimeAArchivo();
	void ImprimeVentanaConfiguracion();
	void ImprimeArchivo();
	void ImprimeImpresoraDefault();
private slots:
	void SlotImprimir();

};
#endif
