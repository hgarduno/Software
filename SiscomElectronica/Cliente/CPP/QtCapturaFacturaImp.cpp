#include <QtCapturaFacturaImp.h>

#include <QCtrlProveedoresSE.h>

QtCapturaFacturaImp::QtCapturaFacturaImp(SiscomDatCom *pSisDatCom,
					 char **pchrPtrArgumentos,
					 QWidget *pQWParent,
					 const char *pchrPtrName,
					 WFlags pWFlags):
			QComprasImportaciones(pSisDatCom,
					      pchrPtrArgumentos,
					      pQWParent,
					      pchrPtrName,
					      pWFlags)
{
Inicia();

}

void QtCapturaFacturaImp::Inicia()
{
DesHabilitaControles();
}
void QtCapturaFacturaImp::DesHabilitaControles()
{
QCtrProveedores->setEnabled(false);


}
