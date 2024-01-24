#ifndef __QSISDIRECCIONES_H__
#define __QSISDIRECCIONES_H__
#include <SISCOMComunicaciones++.h>
#include <CQSisDirecciones.h>
#include <qwidget.h>
class SiscomDatCom;
class QSisSepomex;
class QHBoxLayout;
class SisDireccion;
class SiscomRegistro3;
/*!
 * Widget Qt 3 parte del control libControlSepomexComunicas.so <br>
 * que permite el manejo de las direcciones de una persona
 *
 *
 */
class QSisDirecciones:public QWidget
{
Q_OBJECT
public:
	QSisDirecciones(QWidget *pQWParent=0,
			const char *pchrPtrName=0,
			WFlags pWFlags=0);
	void Servidor(SiscomDatCom *);
	void Argumentos(char **);
	void IdPersona(const char *);

	void DatosServidor(const char *pchrPtrOperacionesConsulta,
			   const char *pchrPtrConsulta);
	QSisSepomex *Sepomex();
	void SistemaConsulta(const char *);
	void IniciaControl();
	void DireccionesPersona();
	void Direcciones(CQSisLstDireccion *);

	void setFocus();
private:
	char **chrPtrArgumentos;
	SiscomDatCom *SisDatCom;
	const char *chrPtrIdPersona;
	const char *chrPtrSistemaConsulta;
	QSisSepomex *QSSepomex;
	QGridLayout *QGLRegilla;
	QTable *QTDirecciones;
	QLabel *QLDirecciones;
	QPushButton *QPBAnexar;
	QPushButton *QPBEliminar;
	QPushButton *QPBModificar;
	CQSisLstDireccion CQSLDirecciones;
	SisDireccion *SDireccion;
	SiscomRegistro3 *SisReg3Direccion;

	const char *chrPtrOperacionesConsulta;
	const char *chrPtrConsulta;
private:
	void IniciaVariables();
	void Etiqueta();
	void Tabla();
	QPushButton *Boton(const char *,const char *);
	QHBoxLayout *Botones();
	void ConectaSlots();
	void IniciaSepomex();
	void RegistraDireccion();
	void ConsultaDirecciones();
	void MuestraDirecciones();
private slots:
	void SlotAnexar();
	void SlotDireccion(SiscomRegistro3 *);
};
#endif
