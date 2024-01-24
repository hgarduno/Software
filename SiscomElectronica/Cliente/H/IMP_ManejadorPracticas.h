
#ifndef __IMP_MANEJADORPRACTICAS_H__
#define __IMP_MANEJADORPRACTICAS_H__
#include <UIC_H_ManejadorPracticas.h>
#include <zPractica.h>
class SiscomDatCom;
class zSiscomConexion;
class zSiscomRegistro;
class zPractica;
class QManejadorPracticas:public ManejadorPracticas
{
 Q_OBJECT
public:
	QManejadorPracticas(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QManejadorPracticas();
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProducto;
	zSiscomRegistro *zSisRegEscuela;
	zPractica zPraPractica;
private:
	void ConectaSlots();
	void IniciaVariables();
	void SeleccionandoPractica();
	void MuestraPractica(zSiscomRegistro *);	
	void RegistrandoPractica();
	void RegistraPractica();
	zPractica *Practica();
	int EstaPracticaRegistrada();
	void MostrandoPractica();
	void MuestraProductos();
	void DatosPractica();
	void DatosProfesor();
	void HabilitaDesHabilita(bool );
	void HabilitaDesHabilitaDatosPractica(bool );
	void HabilitaDesHabilitaDatosProfesor(bool);
private slots:
	void SlotRegistraPractica();
	void SlotSeleccionaPractica();
	void SlotFocoAMateria();
	void SlotFocoAEscuelas();
	void SlotEscuela(zSiscomRegistro *);
};
extern "C" QManejadorPracticas *InstanciaManejadorPracticas(void *,char **,void *,const char *,int);
#endif
