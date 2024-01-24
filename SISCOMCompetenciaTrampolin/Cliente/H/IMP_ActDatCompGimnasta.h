#ifndef __IMP_ACTDATCOMPGIMNASTA_H__
#define __IMP_ACTDATCOMPGIMNASTA_H__
#include <UIC_H_ActDatCompGimnasta.h>
class SiscomDatCom;
class CQSisCompitiendo;
class CQSisEntrenador;
class CQSisGimnasio;
class CQSisClase;
class CQSisNivel;
class CQSisGrupo;
class QLineEdit;
class QActDatCompGimnasta:public ActDatCompGimnasta
{
 Q_OBJECT
public:
	QActDatCompGimnasta(SiscomDatCom *,
	    CQSisCompitiendo *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=true,
	    WFlags pWFlags=0);
	~QActDatCompGimnasta();
private:
	SiscomDatCom *SisDatCom;
	CQSisCompitiendo *CQSCompitiendo;
	CQSisGimnasio *CQSGimnasio;
	CQSisEntrenador *CQSEntrenador;
	CQSisClase *CQSClase;
	CQSisGrupo *CQSGrupo;
	CQSisNivel *CQSNivel;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraDatosCompetencia();
	void MuestraPersona(CQSisEntrenador *,QLineEdit *);
	void ConsultaNivelesClase();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotGimnasio(CQSisGimnasio *);
	void SlotClase(CQSisClase *);
	void SlotNivel(CQSisNivel *);
	void SlotGrupo(CQSisGrupo *);
	void SlotBusEntrenador();
	void SlotCancelar();
	void SlotRegistrar();
};
#endif
