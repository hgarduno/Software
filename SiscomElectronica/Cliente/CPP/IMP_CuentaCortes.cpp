#include <IMP_CuentaCortes.h>
#include <IMP_QControlFecha.h>
#include <IMP_SelExpendios.h>

QCuentaCortes *InstanciaCuentaCortes(void *pSisDatCom,
				     char **pchrPtrArgumentos,
				     void *pQWParent,
				     const char *pchrPtrName,
				     int pintWFlags)
{

  return new QCuentaCortes((SiscomDatCom *)pSisDatCom,
  			pchrPtrArgumentos,
			(QWidget *)pQWParent,
			pchrPtrName,
			pintWFlags);
}

QCuentaCortes::QCuentaCortes(SiscomDatCom *pSisDatCom,
			     char **pchrPtrArgumentos,
			     QWidget *pQWParent,
			     const char *pchrPtrNombre,
			     WFlags pWFlags):
			     QtCuentaCortesS(pQWParent,pchrPtrNombre,pWFlags),
			     SisDatCom(pSisDatCom)
{


}
QCuentaCortes::~QCuentaCortes()
{

}
void QCuentaCortes::SeleccionaExpendio()
{
QSelExpendios lQSExpendios(SisDatCom);

}
