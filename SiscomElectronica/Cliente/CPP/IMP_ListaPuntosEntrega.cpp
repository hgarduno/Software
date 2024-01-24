#include <IMP_ListaPuntosEntrega.h>


#include <zOpsPuntosEntrega.h>
#include <zPuntosEntrega.h>


#include <zSiscomDesarrollo4.h>
QListaPuntosEntrega::QListaPuntosEntrega(zSiscomConexion *pzSisConexion,
					QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				QtListaPuntosEntrega(pQWParent,
						     pchrPtrName,
						     pbModal,
						     pWFlags),
				 zSisConexion(pzSisConexion)
{
IniciaVariables();
Ejecutando();
}

QListaPuntosEntrega::~QListaPuntosEntrega()
{

}

void QListaPuntosEntrega::Ejecutando()
{
Consultando();
exec();
}
void QListaPuntosEntrega::Consultando()
{
	Consulta();
	QtListaPuntosEntrega::PuntosEntrega(zPsEntrega);
	QtListaPuntosEntrega::Muestra();
}

void QListaPuntosEntrega::Consulta()
{
zOpsPuntosEntrega lzOpsPEntrega("Consultando",zSisConexion,0,"PuntosEntrega");
zPsEntrega=lzOpsPEntrega.ObtenPuntosEntrega();
}

