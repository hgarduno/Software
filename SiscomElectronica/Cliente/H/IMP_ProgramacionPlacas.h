
#ifndef __IMP_PROGRAMACIONPLACAS_H__
#define __IMP_PROGRAMACIONPLACAS_H__
#include <UIC_H_ProgramacionPlacas.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class QProgramacionPlacas:public ProgramacionPlacas
{
 Q_OBJECT
public:
	QProgramacionPlacas(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QProgramacionPlacas();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3Lst SisRegPlacasProgramadas;
	SiscomRegistro3 *SisRegPlaca;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	void Consulta();
	void Muestra();
	void EntregandoPlaca();
private slots:
	void SlotPlacasPendientes();
	void SlotSeleccionaPlaca(int,int,int,const QPoint &);
	void SlotEntrega();
};
extern "C" QProgramacionPlacas *InstanciaProgramacionPlacas(void *,char **,void *,const char *,int);
#endif
