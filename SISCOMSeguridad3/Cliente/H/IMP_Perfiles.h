#ifndef __CQSISPERFILES_H__
#define __CQSISPERFILES_H__

#include <UIC_H_Perfiles.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTable;
class QPushButton;
class CSISCOMDatComunicaciones;
class CQPerfiles;

class CQSisPerfiles : public Perfiles
{
    Q_OBJECT

public:
    CQSisPerfiles(const char *,
		  const char *,
		   CSISCOMDatComunicaciones *,
		   QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CQSisPerfiles();


private:
	CSISCOMDatComunicaciones *CSisDatCom;
	const char *chrPtrIdAplicacion;
	const char *chrPtrNmbAplicacion;
	CQPerfiles *CQPConsulta;
private:
	void MuestraCabecera();
	void ConectaSlots();
	void ConsultaPerfiles();
	void MuestraPerfiles();
	void ReConsultaPerfiles();
	const char *CapturaPerfilReferencia();
private slots:
	void SlotRegistraPerfil();
signals:
	void SignalRegistroPerfil(CQPerfiles *);
};

#endif 
