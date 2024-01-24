#ifndef _CQSISFIRMAS_H__
#define _CQSISFIRMAS_H__

#include <UIC_H_Firmas.h>
#include <SoporteAplicacionSeguridad.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QLabel;
class QLineEdit;
class QPushButton;
class CSISCOMDatComunicaciones;
class CQSisFirmas : public Firmas
{
    Q_OBJECT

public:
    CQSisFirmas(long ,
		long ,
		CSISCOMDatComunicaciones *,
		QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CQSisFirmas();
private:
	CSISCOMDatComunicaciones *CSisDatCom;
	long lngIdAplicacion;
	long lngIdPerfil;
	CQUsuarios CQUsuariosA;
	int intNumUsuario;
private:
	void MuestraUsuariosXPerfil();
	void ObtenUsuarios();
	void ConectaSlots();
private slots:
	void SlotSeleccionaUsuario(int ,int ,int ,const QPoint &);
	void SlotRegistraFirma();
};

#endif 
