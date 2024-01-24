#ifndef __CQSISCONTROLADORSEGURIDAD_H__
#define __CQSISCONTROLADORSEGURIDAD_H__

#include <UIC_H_ControladorSeguridad.h>
#include <GeneralBibliotecaSeguridad3.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;

class CQSisAplicaciones;
class CQSisControlFormas;
class CSISCOMDatComunicaciones;
class CQPerfiles;
class CQManejadorControlFormas
{

	public:
		CQManejadorControlFormas();
		void AnexaPerfil(CQSisControlFormas *,QSiscomPerfilBD *);
		CQSisControlFormas *operator[](const char *);
	private:
		QSiscomListaPerfilesBD QSLPerfilesBD;
		QPtrList<CQSisControlFormas> QSCFormas;	

};
class CQSisControladorSeguridad : public ControladorSeguridad 
{
    Q_OBJECT

public:
    CQSisControladorSeguridad( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CQSisControladorSeguridad();

private:
	void ConectaSlots();	
	void CargaArchivos();
	void MuestraPantallas();
	void LlenaComboPerfiles(CQPerfiles *);
	int ObtenIdPerfil();
	const char *ObtenIdPerfilChar();
	
	void ConsultaControlesXPerfil(QSiscomListaContXForma &);
	QSiscomPerfilBD *ObtenPerfil();
	void MuestraUsuariosXPerfil();
private :
	CQSisAplicaciones *CQSisCapApli;
	CQSisControlFormas *CQSisConFormas;
	CQSisControlFormas *CQSisConActualiza;
	CQSisControlFormas *CQSisActualiza;
	CQManejadorControlFormas CQMCFormas;	
	CSISCOMDatComunicaciones *CSisDatCom;
	QStringList QSLArchivosUI;
	QSiscomListaPantallasBD QSLPantallasBD;
	QSiscomListaContXForma QSLContXForma;
	CQPerfiles *CQPerfilesDat;
private slots:
	void SlotManejadorUsuarios();
	void SlotCapturaAplicacion();
	void SlotRegistraAplicacion();
	void SlotCargaAplicacion();
	void SlotIniciaComunicaciones();
	void SlotEstanRegLasPantallas(int );
	void SlotLasPantallas(const QSiscomListaPantallasBD &);
	void SlotMuestraDatosPantalla(int );
	void SlotConsultaAplicacion(int ,
				    const QSiscomListaPantallasBD &,
				    CQPerfiles *);
	void SlotCargaPerfiles();
	void SlotMuestraDscPerfil(int );
	void SlotRegistroPerfiles(CQPerfiles *);
	void SlotMuestraUsuariosXPerfil(int );
	void SlotCapturaFirmas();

	void S_ActualizaPantalla();
	void S_ActualizaAplicacion();

};

#endif 
