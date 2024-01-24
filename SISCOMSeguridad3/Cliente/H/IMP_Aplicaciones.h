#ifndef __CQSISAPLICACIONES_H__
#define __CQSISAPLICACIONES_H__

#include <UIC_H_Aplicaciones.h>
#include <GeneralBibliotecaSeguridad3.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class CSISCOMDatComunicaciones;
class CQPerfiles;
class CQSisAplicaciones : public Aplicaciones ,
			  public QSiscomSeguridad3 
{
    Q_OBJECT

public:
    CQSisAplicaciones(CSISCOMDatComunicaciones *, QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CQSisAplicaciones();
	QString ObtenIdAplicacion();
        QString ObtenDirectorioArchivosQt();	
	QString ObtenNombreAplicacion();
	int EstanLasPantallas();

private:
	CSISCOMDatComunicaciones *CSisDatCom;
	int intEstanLasPantallas;
	QSiscomListaPantallasBD QSLPantallasBD;
	QSiscomConsultaAplicacion *QSCAplicacionBD;
	//QSiscomListaContXForma QSLContXForma;
	CQPerfiles *CQPAplicacion;

	
private:
	void ConectaSlots();
	void ConsultaRegistroDeLaAplicacion(const char *);
private slots:
	void SlotVerificaIdentificador();
	void SlotSeleccionaDirectorio();
	void SlotRegistraAplicacion();
signals:
	void SignalEstanRegLasPantallas(int );
	void SignalLasPantallas(const QSiscomListaPantallasBD &);
	void SignalPantallasYControles(const QSiscomListaContXForma &);
	void SignalConsultaAplicacion(int ,
				      const QSiscomListaPantallasBD &,
				      CQPerfiles *);
};

#endif 
