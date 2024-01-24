#ifndef __QOPERACIONESGENERALES_H__
#define __QOPERACIONESGENERALES_H__
#include <qwidget.h>
class QToolBox;
class QRotaciones;
class SISCOMVentanaPrincipal;
class SiscomDatCom;
class CQSisCompetencia;
class QOperacionesGenerales:public QWidget
{
Q_OBJECT
public:
	QOperacionesGenerales(SiscomDatCom *,
			      char **,
			      QWidget *pQWParent=0,
			      const char *pchrPtrName=0,
			      WFlags pWFlags=0);
	void Competencia(CQSisCompetencia *);
private:
	QToolBox *QTBOperaciones;
	QRotaciones *QORotaciones;
	SISCOMVentanaPrincipal *QSisVentanaP;
	char **chrPtrArgumentos;
	SiscomDatCom *SisDatCom;
private:
	void IniciaInterfaz();
	void IniciaVariables();
	void CreaAreaVentana();
};
extern "C" QOperacionesGenerales *InstanciaOperacionesGenerales(void *,
								char **,
								void *,
								const char *,
								int );
#endif
