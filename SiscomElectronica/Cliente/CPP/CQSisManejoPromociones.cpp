#include <CQSisManejoPromociones.h>

CQSisManejoPromociones::CQSisManejoPromociones():
			intContador(0)
{


}
void CQSisManejoPromociones::FilasMaximas(int pintFilas)
{
   QMAFilas.resize(pintFilas);
   QMAFilas.fill(-1);
}
void CQSisManejoPromociones::Agrega(SiscomRegistro3 *pSisReg3Promocion,
				    int pintNFila)
{
  SisReg3LstPromociones<<pSisReg3Promocion;
  QMAFilas[intContador]=pintNFila;
  intContador++;
}
const SiscomRegistro3Lst &CQSisManejoPromociones::Promociones()
{
 return SisReg3LstPromociones;
}
const QMemArray<int> &CQSisManejoPromociones::Filas()
{
return QMAFilas;
}
void CQSisManejoPromociones::ReInicia()
{
   QMAFilas.fill(-1);
   SisReg3LstPromociones.clear();
   intContador=0;
}
void CQSisManejoPromociones::Elimina(SiscomRegistro3 *pSisReg3Promocion,
				     int pintFila)
{

SisReg3LstPromociones.remove(pSisReg3Promocion);
QMAFilas[pintFila]=-1;


}
