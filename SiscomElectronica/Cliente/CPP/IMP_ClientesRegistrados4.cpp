#include <IMP_ClientesRegistrados4.h>

#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <zSiscomDesarrollo4.h>
#include <zClienteSiscom.h>
#include <zClientesSiscom.h>
#include <zTelefono.h>
#include <zTelefonos.h>
#include <qpushbutton.h>
#include <qtable.h>
QClientesRegistrados4::QClientesRegistrados4(
				    zClientesSiscom *pzClisSiscom,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				ClientesRegistrados4(pQWParent,pchrPtrName,pbModal,pWFlags),
				zClisSiscom(pzClisSiscom),
				intAceptar(1)
{
IniciaVariables();
ConectaSlots();
exec();
}

QClientesRegistrados4::~QClientesRegistrados4()
{

}

void QClientesRegistrados4::ConectaSlots()
{
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
connect(QPBCancelar,SIGNAL(clicked()),SLOT(SlotCancelar()));
connect(QTClientes,
	SIGNAL(doubleClicked(int,int,int,const QPoint &)),
	SLOT(SlotCliente(int,int,int,const QPoint &)));
connect(QTClientes,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionoCliente(int,int,int,const QPoint &)));

}
void QClientesRegistrados4::SlotSeleccionoCliente(int pintNCliente,
						  int,
						  int,
						  const QPoint &)
{
   if(pintNCliente!=-1)
   {
   QTClientes->selectRow(pintNCliente);
   zCliSiscom=(zClienteSiscom *)(*zClisSiscom)[pintNCliente];
   QPBAceptar->setEnabled(true);
   zSiscomQt3::Foco(QPBAceptar);
   }
}
void QClientesRegistrados4::SlotCliente(int pintNCliente,
					int,
					int,
					const QPoint &)
{
   zCliSiscom=(zClienteSiscom *)(*zClisSiscom)[pintNCliente];
   SlotAceptar();
}
void QClientesRegistrados4::SlotAceptar()
{
	intAceptar=1;
	done(1);
}
void QClientesRegistrados4::SlotCancelar()
{
	intAceptar=0;
	done(1);
}
void QClientesRegistrados4::IniciaVariables()
{
Muestra();
}
QString QClientesRegistrados4::NombreCompleto(zClienteSiscom *pzCliSiscom)
{
QString lQSCompleto(pzCliSiscom->Nombre());
lQSCompleto+=" ";
lQSCompleto+=pzCliSiscom->APaterno() ? pzCliSiscom->APaterno() : "";
lQSCompleto+=" ";
lQSCompleto+=pzCliSiscom->AMaterno() ? pzCliSiscom->AMaterno() : "";
return lQSCompleto;
}
void QClientesRegistrados4::MuestraTelefonos(int pintNCliente,
					     zClienteSiscom *pzCliSiscom)
{
zTelefono *lzTelefono;
QString lQStrCadena;
if(pzCliSiscom->Telefonos())
{
for(lzTelefono=(zTelefono *)pzCliSiscom->Telefonos()->Primer();
    lzTelefono;
    lzTelefono=(zTelefono *)pzCliSiscom->Telefonos()->Siguiente())
{
    if(lzTelefono->Telefono())
    {
    lQStrCadena+=lzTelefono->Telefono();
    lQStrCadena+="\n" ;
    }
}
QTClientes->setText(pintNCliente,1,lQStrCadena);
}

}
void QClientesRegistrados4::Muestra()
{
zClienteSiscom *lzCliSiscom;
int lintContador=0;
QTClientes->setNumRows(zClisSiscom->NNodos());
for(lzCliSiscom=(zClienteSiscom *)zClisSiscom->Primer();
    lzCliSiscom;
    lzCliSiscom=(zClienteSiscom *)zClisSiscom->Siguiente(),
    lintContador++)
{
    QTClientes->setText(lintContador,0,NombreCompleto(lzCliSiscom));
    MuestraTelefonos(lintContador,lzCliSiscom);
    QTClientes->setText(lintContador,3,lzCliSiscom->Escuela());
}
zSiscomQt3::AjustaColumnasTabla(QTClientes);
}
void QClientesRegistrados4::reject()
{

}
zClienteSiscom *QClientesRegistrados4::Cliente()
{
	return zCliSiscom;
}
int QClientesRegistrados4::Aceptar()
{
   return intAceptar;
}
