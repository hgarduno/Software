
#ifndef __IMP_BUSCAPERSONAS_H__
#define __IMP_BUSCAPERSONAS_H__
#include <UIC_H_BuscaPersonas.h>
#include <CQSisBuscaPersonas.h>
class SiscomDatCom;
class CQSisBuscaPersona;
class QBuscaPersonas:public BuscaPersonas
{
 Q_OBJECT
public:
	QBuscaPersonas(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pBoolModal=false,
	    WFlags pWFlags=0);
	~QBuscaPersonas();
	CQSisBuscaPersona *PersonaSeleccionada();
	int SeSeleccionaronPersonas();
	void PersonasSeleccionadas(CQSisLstBuscaPersona *);
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisLstBuscaPersona CQSLBPersona;
	CQSisBuscaPersona *CQSPersona;
private:
	void ConectaSlots();
	void IniciaVariables();
	CQSisBuscaPersona *Persona();
	void ConsultandoPersonas();
	void ConsultaPersonas();
	void MuestraPersonas();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotPasaFocoAPaterno();
	void SlotPasaFocoAMaterno();
	void SlotPasaFocoIdPersona();
	void SlotPasaFocoConsulta();
	void SlotConsulta();
	void SlotSeleccionandoPersona(int,int,int,const QPoint &);
	void SlotSeleccionaPersona();
	void SlotCancelar();
};
#endif
