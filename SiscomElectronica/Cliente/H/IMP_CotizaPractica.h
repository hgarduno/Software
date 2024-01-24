#ifndef __IMP_COTIZAPRACTICA_H__
#define __IMP_COTIZAPRACTICA_H__

#include <UIC_H_CotizaPractica.h>
#include <Escuelas.h>
#include <Materias.h>
#include <Practicas.h>
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QTable;
class QPushButton;
class QLCDNumber;
class SiscomDatCom;

class QCotizaPractica : public CotizaPractica
{
    Q_OBJECT

public:
    QCotizaPractica(SiscomDatCom *,
    		    const char *,
		    const char *,
    		    QWidget* parent = 0,
		    const char* name = 0,
		    bool modal = FALSE,
		    WFlags fl = 0 );
    ~QCotizaPractica();
    ProductosE &ObtenProductos();
    int ObtenSeleccion();
private:
    	int intSeleccion;
	SiscomDatCom *SisDatCom;
	const char *chrPtrIdExpendio;
	const char *chrPtrNmbTipoPrecio;
	Escuelas EEscuelas;
	Escuela *EEscuela;
	Materias MMaterias;
	Materia *MMateria;
	Practica *PPractica;
	Practicas PPracticas;
	ProductosE PProductos;
	ProductosE PProdLoQueHay;
	
	QLineEdit *QLEEscuelas;
	QLineEdit *QLEMaterias;
	QLineEdit *QLEPracticas;
private:
	void ConsultaLasEscuelas();
	void ConsultaMateriasDeLaEscuela();
	void ConsultaPracticasDeLaMateria();
	void ConectaSlots();
	void IniciaVariables();
	void ColocaExtension();
private slots:
	void S_SeleccionoEscuela();
	void S_SeleccionoMateria();
	void S_SeleccionoPractica();
	void S_AnexarALaOrden();
	void S_VendeLoQueHay();
	
};

#endif 
