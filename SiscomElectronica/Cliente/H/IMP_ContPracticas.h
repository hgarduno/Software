#ifndef __IMP_CONTPRACTICAS_H__
#define __IMP_CONTPRACTICAS_H__

#include <UIC_H_ContPracticas.h>
#include <Escuelas.h>
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class SiscomDatCom;
class Escuela;
class Materia;
class Practica;

class QContPracticas : public ContPracticas
{
    Q_OBJECT

public:
    QContPracticas(SiscomDatCom *,
    		   char **,
		   QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QContPracticas();

    Escuela *ObtenEscuela();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	Escuela *EEscuela;
	Materia *MMateria;
	Practica *PPractica;
private:
	void ConectaSlots();
	void closeEvent(QCloseEvent *);
private slots:
	void S_ContEscuelas();
	void S_ContMaterias();
	void S_SelLasPracticas();
	void S_MaterialPracticas();
signals:
	void SignalTerminar(QWidget *);
};

extern "C" QContPracticas *InstanciaContPracticas(void *,
						  char **,
						  void *,
						  const char *,
						  int );
#endif 
