#ifndef __IMP_CONTMATERIAS_H__
#define __IMP_CONTMATERIAS_H__

#include <UIC_H_ContMaterias.h>
#include <Materias.h>
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class QTable;
class SiscomDatCom;
class Escuela;
class Materia;

class QContMaterias : public ContMaterias
{
    Q_OBJECT

public:
    QContMaterias(Escuela *,SiscomDatCom *,char **, QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QContMaterias();
    Materia *ObtenMateria();
private:
	Escuela *EEscuela;	
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	Materias MMaterias;
	Materia *MMateria;
private:
	void ConsultaLasMaterias();
	void ConectaSlots();
private slots:
	void S_SelMateria();
	void S_Anexar();
	void S_Registrar();
};

#endif 
