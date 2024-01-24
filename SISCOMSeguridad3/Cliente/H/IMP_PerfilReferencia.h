#ifndef __CQSISPERFILREFERENCIA_H__
#define __CQSISPERFILREFERENCIA_H__

#include <UIC_H_PerfilReferencia.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;
class QTable;
class CSISCOMDatComunicaciones;
class CQPerfiles;

class CQSisPerfilReferencia : public PerfilReferencia
{
    Q_OBJECT

public:
    CQSisPerfilReferencia(CSISCOMDatComunicaciones *, const char *,const char *,QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CQSisPerfilReferencia();
     const char *ObtenPerfilReferencia();
private:
	const char *chrPtrNmbPerfil;
	const char *chrPtrIdAplicacion;
	int intNumPerfil;
	CSISCOMDatComunicaciones *CSisDatCom;
	CQPerfiles *CQPerfilesDat;
	
private:
	void MuestraPerfiles();
	void ConectaSlots();
	void ConsultaPerfilesValidos();
private slots:
	void SlotSeleccionaPerfil(int,int,int ,const QPoint &);
	void SlotAceptar();
};

#endif 
