#ifndef __QTIMPACTIVASERVIDOR_H__
#define __QTIMPACTIVASERVIDOR_H__
#include <ActivaServidor.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class QtImpActivaServidor:public ActivaServidor
{
Q_OBJECT
public:
	QtImpActivaServidor(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegTienda;
	zSiscomRegistros *zSisRegsServidores;
private:
	void Consultando();
	void Consulta();
	void Muestra();
	void CambiaConexionA();
private slots:
	void SlotTienda(zSiscomRegistro *pzSisRegTienda);	
	void SlotSeleccionaMaquina(int pintMaquina,int,int,const QPoint &);
	void SlotCambiarConexionA();
};

#endif
