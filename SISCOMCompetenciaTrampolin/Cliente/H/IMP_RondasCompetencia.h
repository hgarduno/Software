
#ifndef __IMP_RONDASCOMPETENCIA_H__
#define __IMP_RONDASCOMPETENCIA_H__
#include <UIC_H_RondasCompetencia.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class QRondasCompetencia:public RondasCompetencia
{
 Q_OBJECT
public:
	QRondasCompetencia(SiscomDatCom *,
	    const char *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QRondasCompetencia();
	const char *IdRonda();
private:
	SiscomDatCom *SisDatCom;
	const char *chrPtrIdCompetencia;
	SiscomRegistro3Lst SRegistros3Lst;
	const char *chrPtrIdRonda;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultandoRondas();
	void ConsultaRondas();
	void MuestraRondas();
private slots:
	void SlotRonda(int);
};
#endif
