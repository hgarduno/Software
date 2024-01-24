#include <CQSisPreciosTabla3Qt.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomRegistros3.h>
#include <qtable.h>

CQSisPreciosTabla3Qt::CQSisPreciosTabla3Qt(SiscomRegistro3Lst *pSReg3PreciosLst,
					   SiscomRegistro3 *pSReg3Producto,
					   QWidget *pQWParent,
					   int pintFila,
					   int pintColumna):
			QComboBox(pQWParent,0,0),
			SReg3PreciosLst(pSReg3PreciosLst),
			intFila(pintFila),
			intColumna(pintColumna),
			SReg3Producto(pSReg3Producto)
{
MuestraPrecios();
setEditable(false);
setInsertionPolicy(QComboBox::NoInsertion);
connect(this,
        SIGNAL(activated(int)),
        SLOT(SlotPrecio(int)));
}
CQSisPreciosTabla3Qt::~CQSisPreciosTabla3Qt()
{

}
int CQSisPreciosTabla3Qt::Fila()
{
return intFila;
}
int CQSisPreciosTabla3Qt::Columna()
{
return intColumna;
}
void CQSisPreciosTabla3Qt::MuestraPrecios()
{
SiscomDesarrollo3Qt::RegistrosAlCombo("nombre",
				    this,
				    SReg3PreciosLst);
}
void CQSisPreciosTabla3Qt::SlotPrecio(int pintNPrecio)
{
SiscomRegistro3 *lSReg3TipoPrecio=(*SReg3PreciosLst)[pintNPrecio];
SReg3Producto->SiscomActualizaCampo("IdPrecio",(*lSReg3TipoPrecio)["idprecio"]);
SReg3Producto->SiscomActualizaCampo("TipoPrecio",(*lSReg3TipoPrecio)["nombre"]);
emit SignalCambioTipoPrecio((*SReg3PreciosLst)[pintNPrecio],intFila,intColumna);
}

