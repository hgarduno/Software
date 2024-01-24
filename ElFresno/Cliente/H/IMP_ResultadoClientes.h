#ifndef __IMP_RESULTADOCLIENTES_H__
#define __IMP_RESULTADOCLIENTES_H__

#include <UIC_H_ResultadoClientes.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QPushButton;
class CQ_Personas;

class QResultadoClientes : public ResultadoClientes
{
    Q_OBJECT

public:
	enum BTN_Botones
	{
	  SeleccionarTodo,
	  Cancelar
	};
    QResultadoClientes(CQ_Personas *, QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QResultadoClientes();
     BTN_Botones ObtenSeleccion();
private:

	CQ_Personas *CQPersonas;
	BTN_Botones BTN_Seleccion;
private:
	void MuestraClientes();
	void ConectaSlots();
private slots:
	void S_SeleccionarTodos();
	void S_Cancelar();
};

#endif 
