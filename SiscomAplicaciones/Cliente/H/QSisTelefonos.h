#ifndef __QSISTELEFONOS_H__
#define __QSISTELEFONOS_H__
#include <SISCOMComunicaciones++.h>
#include <SisMedioComunicacion.h>


class QGridLayout;
class QLabel;
class QPushButton;
class QTable;
class QSisHEspacio;
class SisLstMedCom;
/*!
 * Widget Qt 3 parte del control libControlSepomexComunicas.so <br>
 * que permite el manejo de los telefonos de una persona
 *
 */
class QSisTelefonos:public QWidget
{
Q_OBJECT
public:
	QSisTelefonos(QWidget *pQWParent=0,
		      const char *pchrPtrName=0,
		      WFlags pWFlags=0);
	void TelefonosRegistrados();
	void Telefonos(SisLstMedCom *);
	void SistemaConsulta(const char *);
	void IdPersona(const char *);
	void Servidor(SiscomDatCom *);
private:
	QGridLayout *QGLRegilla;
	QLabel *QLTelefonos;
	QLabel *QLTelefono;
	QLabel *QLDescripcion;
	QTable *QTTelefonos;
	QLineEdit *QLETelefono;
	QLineEdit *QLEDescripcion;
	QPushButton *QPBAnexar;
	QPushButton *QPBEliminar;
	QPushButton *QPBModificar;
	SisLstMedCom SLMCom;
	const char *chrPtrSistemaConsulta;
	const char *chrPtrIdPersona;
	SiscomDatCom *SisDatCom;
private:
	void IniciaVariables();
	void Etiqueta();
	void Tabla();
	QHBoxLayout *Botones();
	QSisHEspacio *CapturaDatos();
	QPushButton *Boton(const char *,const char *);
	void ConectaSlots();
	void Anexar();
	void ConsultaTelefonos();
	void MuestraTelefonos();
private slots:
	void SlotPasaFocoDescripcion();
	void SlotPasaFocoAnexar();
	void SlotAnexar();
};
#endif
