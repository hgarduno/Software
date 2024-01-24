#include <IMP_NoAlcanzaProducto.h>
#include <zSiscomRegistros.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>

#include <qtable.h>
#include <qpushbutton.h>

QNoAlcanzaProducto::QNoAlcanzaProducto(zSiscomRegistros *pzSisRegDefProducto,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				NoAlcanzaProducto(pQWParent,pchrPtrName,pbModal,pWFlags),
				zSisRegsDefProducto(pzSisRegDefProducto)
{
IniciaVariables();
ConectaSlots();
exec();
}

QNoAlcanzaProducto::~QNoAlcanzaProducto()
{

}

void QNoAlcanzaProducto::ConectaSlots()
{
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
}
void QNoAlcanzaProducto::SlotAceptar()
{
  done(1);
}
void QNoAlcanzaProducto::IniciaVariables()
{
 MuestraInformacionProducto();
}
void QNoAlcanzaProducto::MuestraInformacionProducto()
{
const char *lchrPtrCampos[]={"cveproducto","cantidad","existencia","exbodegas",0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,
		       zSisRegsDefProducto,
		       QTDatos);
ColoreaNoAlcanza();
}
void QNoAlcanzaProducto::reject()
{

}
void QNoAlcanzaProducto::CualesNoAlcanzan(int *pintPtrNoAlcanzan)
{
zSiscomRegistro *lzSisRegProducto;
SiscomRegistrosLog(zSisRegsDefProducto);
for(lzSisRegProducto=zSisRegsDefProducto->Primer();
    lzSisRegProducto;
    lzSisRegProducto=zSisRegsDefProducto->Siguiente(),
    pintPtrNoAlcanzan++)
     *pintPtrNoAlcanzan=!lzSisRegProducto->CampoInt("sepuedevender");
*pintPtrNoAlcanzan=-1;
}
void QNoAlcanzaProducto::ColoreaNoAlcanza()
{
int lintArrNoAlcanzan[100];
CualesNoAlcanzan(lintArrNoAlcanzan);
zSiscomQt3::ColoreaFilas(QTDatos,Qt::red,lintArrNoAlcanzan);
}
