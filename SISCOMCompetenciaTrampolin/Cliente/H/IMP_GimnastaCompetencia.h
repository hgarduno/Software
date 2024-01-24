
#ifndef __IMP_GIMNASTACOMPETENCIA_H__
#define __IMP_GIMNASTACOMPETENCIA_H__
#include <UIC_H_GimnastaCompetencia.h>
class SiscomDatCom;
class CQSisClase;
class CQSisNivel;
class CQSisGrupo;
class CQSisCompetencia;
class CQSisEntrenador;
class CQSisGimnasio;
class QCtrlBuscaPersonas2;
class QGimnastaCompetencia:public GimnastaCompetencia
{
 Q_OBJECT
public:
	QGimnastaCompetencia(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QGimnastaCompetencia();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisClase *CQSClase;
	CQSisNivel *CQSNivel;
	CQSisGrupo *CQSGrupo;
	CQSisCompetencia *CQSCompetencia;
	CQSisEntrenador *CQSPersona;
	CQSisEntrenador *CQSEntrenador;
	CQSisGimnasio *CQSGimnasio;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultaNivelesClase();
	void EstanTodosLosDatos();
	void MuestraGimnasta();
	void MuestraEntrenador();
private slots:
	void SlotClase(CQSisClase *);
	void SlotNivel(CQSisNivel *);
	void SlotGrupo(CQSisGrupo *);
	void SlotCompetencia(CQSisCompetencia *);
	void SlotGimnasio(CQSisGimnasio *);
	void SlotRegistra();
	void SlotActualizaPantalla();
	void SlotPersona(CQSisEntrenador *,const char *);
	void SlotEntrenador(CQSisEntrenador *,const char *);
};
extern "C" QGimnastaCompetencia *InstanciaGimnastaCompetencia(void *,char **,void *,const char *,int);
#endif
