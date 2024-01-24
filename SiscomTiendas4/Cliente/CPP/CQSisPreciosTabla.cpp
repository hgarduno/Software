#include <CQSisPreciosTabla.h>
#include <CQSisPrecios.h>

#include <qtable.h>
CQSisPreciosTabla::CQSisPreciosTabla(CQSisLstPrecio *pCQSLPrecio,
				     QWidget *pQWParent,
				     int pintFila,
				     int pintColumna):
			QComboBox(pQWParent,0,0),
			CQSLPrecios(pCQSLPrecio),
			intFila(pintFila),
			intColumna(pintColumna)
{

	MuestraPrecios();
	setEditable(false);
	setInsertionPolicy(QComboBox::NoInsertion);
	connect(this,
		SIGNAL(activated(int)),
		SLOT(SlotPrecio(int)));

}
CQSisPreciosTabla::~CQSisPreciosTabla()
{
printf("CQSisPreciosTabla::~CQSisPreciosTabla\n");
}
int CQSisPreciosTabla::Fila()
{
	return intFila;
}
int CQSisPreciosTabla::Columna()
{
	return intColumna;
}
void CQSisPreciosTabla::MuestraPrecios()
{
CQSisPrecio *lCQSPrecio;

for(lCQSPrecio=CQSLPrecios->first();
    lCQSPrecio;
    lCQSPrecio=CQSLPrecios->next())
 QSLPrecios << lCQSPrecio->SRegistrosPro2["Nombre"];

 insertStringList(QSLPrecios);
}

void CQSisPreciosTabla::SlotPrecio(int pintNPrecio)
{
	emit SignalPrecio(CQSLPrecios->at(pintNPrecio),intFila,intColumna);	
}
