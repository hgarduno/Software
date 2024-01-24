#ifndef __IMP_MATERIALPRACTICA_H__
#define __IMP_MATERIALPRACTICA_H__

#include <UIC_H_MaterialPractica.h>
#include <ProductosE.h>
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QLabel;
class QLineEdit;
class QPushButton;
class QLCDNumber;
class Escuela;
class Practica;
class Materia;
class SiscomDatCom;

class QMaterialPractica : public MaterialPractica
{
    Q_OBJECT

public:
    QMaterialPractica(Escuela *,
    		      Materia *,
		      Practica *,
		      SiscomDatCom *,
		      char **,
		      QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QMaterialPractica();

private:
	Escuela *EEscuela;
	Materia *MMateria;
	Practica *PPractica;
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	ProductosE PProductos;
	ProductosE PProductosPractica;
private:
	void MuestraDatos();
	void MuestraMaterial();
	void ConectaSlots();
	void AnexaProducto(ProductoE *);
	void CotizaPractica();
private slots:
	void S_Anexar();
	void S_MaterialPractica();
	void S_EliminarProductos();
};

#endif 
