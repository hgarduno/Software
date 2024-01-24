#ifndef __IMP_CONTDELASPRACTICASS_H__
#define __IMP_CONTDELASPRACTICASS_H__

#include <UIC_H_ContDeLasPracticas.h>
#include <Practicas.h>
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTable;
class QPushButton;
class SiscomDatCom;
class Materia;
class Escuela;

class QContDeLasPracticas : public ContDeLasPracticas
{
    Q_OBJECT

public:
    QContDeLasPracticas(Escuela *,
    			 Materia *,
    			 SiscomDatCom *,
    			 char **,
			 QWidget* parent = 0, 
			 const char* name = 0,
			 bool modal = FALSE, 
			 WFlags fl = 0 );
    ~QContDeLasPracticas();
    Practica *ObtenPractica();

private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	Escuela *EEscuela;
	Materia *MMateria;
	Practicas PPracticas;
	Practica *PPractica;
private:
	void ConsultaLasPracticas();
	void ConectaSlots();
private slots:
	void S_SelPractica();
	void S_Anexar();
	void S_Registrar();
};

#endif 
