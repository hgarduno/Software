#ifndef __IMP_MODIFICAGENERALES_H__
#define __IMP_MODIFICAGENERALES_H__

#include <UIC_H_ModificaGenerales.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QComboBox;
class QTextEdit;
class QPushButton;
class CSISCOMDatComunicaciones;
class CQ_Persona;
class CQ_Direccion;

class QModificaGenerales : public ModificaGenerales
{
    Q_OBJECT

public:
    QModificaGenerales(CSISCOMDatComunicaciones *,
		       CQ_Persona *,
		    	QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QModificaGenerales();
private:
    CSISCOMDatComunicaciones *CSisDatCom;
    CQ_Persona *CQPersona;
    CQ_Direccion *CQDireccion;
private:
    void MuestraEncabezado();
    void MuestraDatos();
    void MuestraApodo();
    void MuestraDireccion();
    void ObtenDireccion(int);
    void ConectaSlots();
private slots:
    void S_ActualizaGenerales();	
    void S_AnexaDireccion();
    void S_AnexaTelefono();
};

#endif 
