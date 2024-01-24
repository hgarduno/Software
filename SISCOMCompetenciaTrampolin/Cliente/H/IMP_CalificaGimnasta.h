
#ifndef __IMP_CALIFICAGIMNASTA_H__
#define __IMP_CALIFICAGIMNASTA_H__
#include <UIC_H_CalificaGimnasta.h>
class SiscomDatCom;
class CQSisCompitiendo;
class CQSisCalificacion;
class CQSisAparato;
class QCalificaGimnasta:public CalificaGimnasta
{
 Q_OBJECT
public:
	enum Juez
	{
		Ejecucion=0,
		Dificultad,
		NotaFinal
	};

public:
	QCalificaGimnasta(Juez,
			  SiscomDatCom *,
	    		  CQSisCompitiendo *,
			  CQSisAparato *,
	                  QWidget *pQWParent=0,
	                  const char *pchrPtrName=0,
	                  bool pbModal=true,
	                  WFlags pWFlags=0);
	QCalificaGimnasta(SiscomDatCom *,
	    		  CQSisCompitiendo *,
			  CQSisAparato *,
	                  QWidget *pQWParent=0,
	                  const char *pchrPtrName=0,
	                  bool pbModal=true,
	                  WFlags pWFlags=0);
	~QCalificaGimnasta();

private:
	SiscomDatCom *SisDatCom;
	CQSisCompitiendo *CQSCompitiendo;
	CQSisCalificacion *CQSCalificacion;
	CQSisAparato *CQSAparato;
	Juez JEvalua;

	void (QCalificaGimnasta::*PerfilJuez[10])();
	void (QCalificaGimnasta::*ActualizaCalificacion[10])();

private:
	void ConectaSlots();
	void IniciaVariables();
	void IniciaVariablesFueraCompetencia();
	void MuestraDatosGimnasta();

	void PerfilEjecucion();
	void PerfilDificultad();
	void PerfilNotaFinal();

	void ActualizaEjecucion();
	void ActualizaDificultad();
	void ObtenNotaFinal();

	void IniciaCalificacion();
	void ConsultaNotaFinal();
	void closeEvent(QCloseEvent *);
private slots:

	void SlotRegistrar();
	void SlotCancelar();
	void SlotPasaFocoRegistrar();
};


#endif
