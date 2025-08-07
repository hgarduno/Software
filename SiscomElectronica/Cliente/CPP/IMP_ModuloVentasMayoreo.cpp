#include <IMP_ModuloVentasMayoreo.h>

#include <qpushbutton.h>

QModuloVentasMayoreo *InstanciaModuloVentasMayoreo(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QModuloVentasMayoreo((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}

QModuloVentasMayoreo::QModuloVentasMayoreo(SiscomDatCom *pSisDatCom,
			     char **pchrPtrArgumentos,
			     QWidget *pQWParent,
			     const char *pchrPtrName,
			     WFlags pWFlags):
			     QManejadorOrden(pSisDatCom,
			     		     pchrPtrArgumentos,
					     pQWParent,
					     pchrPtrName,
					     pWFlags)
{
IniciaVariables();
}
void QModuloVentasMayoreo::IniciaVariables()
{

LogSiscom("Iniciando ....");
TextoBotonRegistro("Vende Pedido Mayo&reo");
TextoBotonNuevaOrden("Nueva Orden");

}
void QModuloVentasMayoreo::NuevaOrden()
{
LogSiscom("Modulo mayoreo");

}

void QModuloVentasMayoreo::TextoBotonRegistro(const char *pchrPtrTexto)
{
   QPBRegistrar->setText(pchrPtrTexto);
}
