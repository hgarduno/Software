
#ifndef __IMP_RECETAS_H__
#define __IMP_RECETAS_H__
#include <UIC_H_Recetas.h>
#include <CQSisRecetas.h>
class SiscomDatCom;
class CQSisPersona;
class QRecetas:public Recetas
{
 Q_OBJECT
public:
	QRecetas(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRecetas();
	void Paciente(CQSisPersona *);
	void Informacion();
	
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisPersona *CQSPaciente;
	CQSisLstReceta CQSLReceta;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraPaciente();
	void ConsultandoRecetas();
	void ConsultaRecetas();
	void MuestraRecetas();
	void CadenaColor(const char *,const char *,char *);
	void closeEvent(QCloseEvent *);
private slots:
};
#endif
