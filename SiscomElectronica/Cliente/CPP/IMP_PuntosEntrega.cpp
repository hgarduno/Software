#include <IMP_PuntosEntrega.h>
#include <QtPuntosEntrega.h>


#include <zSiscomElectronica.h>
#include <zProductoCotizar.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <zOpsPuntosEntrega.h>
#include <zDireccion.h>
#include <zPuntoEntrega.h>

QPuntosEntrega *InstanciaPuntosEntrega(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QPuntosEntrega((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QPuntosEntrega::QPuntosEntrega(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				QtPuntosEntrega(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)

{
IniciaVariables();
ConectaSlots();
}

QPuntosEntrega::~QPuntosEntrega()
{

}
void QPuntosEntrega::SlotRegistrar()
{
    Registrar();
}
void QPuntosEntrega::Registrar()
{
zOpsPuntosEntrega lzOpsPEntrega(zSisConexion,PuntoEntrega(),"RegistraPuntoEntrega");
}

zPuntoEntrega *QPuntosEntrega::PuntoEntrega()
{

zPuntoEntrega *lzPEntrega;

lzPEntrega=new zPuntoEntrega("",
			     zSiscomQt3::Texto(QLEPuntoEntrega),
			     DireccionPEntrega());
return lzPEntrega;

}
zDireccion *QPuntosEntrega::DireccionPEntrega()
{
zDireccion *lzDirPEntrega;

lzDirPEntrega=new zDireccion("",
			      zSiscomQt3::Texto(QLECalle),
			      zSiscomQt3::Texto(QLENumExterior),
			      zSiscomQt3::Texto(QLENumInterior),
			      zSiscomQt3::Texto(QLEMunicipio),
			      zSiscomQt3::Texto(QLEColonia),
			      zSiscomQt3::Texto(QLEEstado),
			      zSiscomQt3::Texto(QLECP));
lzDirPEntrega->Referencias(zSiscomQt3::Texto(QTEReferencias));
return lzDirPEntrega;

}
