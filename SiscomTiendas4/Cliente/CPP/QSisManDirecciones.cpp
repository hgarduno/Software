#include <QSisManDirecciones.h>
#include <SiscomDesarrollo3Qt++.h>
#include <IMP_AnexaDireccion.h>
QSisManDirecciones::QSisManDirecciones(const QPoint &pQPPosicion,
				       const char *pchrPtrIdPersona,
				       SiscomDatCom *pSisDatCom,
				       char **pchrPtrArgumentos,
				       QWidget *pQWParent,
				       const char *pchrPtrNombre):
			QPopupMenu(pQWParent,pchrPtrNombre),
			chrPtrArgumentos(pchrPtrArgumentos),
			SisDatCom(pSisDatCom),
			chrPtrIdPersona(pchrPtrIdPersona),
			intEdoOperacion(0)
{
Opciones();
ConectaSlots();
exec(pQPPosicion);

}
void QSisManDirecciones::ConectaSlots()
{
   connect(this,
   	   SIGNAL(activated(int)),
	   SLOT(SlotSelecciona(int)));
}
void QSisManDirecciones::Opciones()
{
    insertItem("Mantenimiento De Direcciones");
    insertSeparator();
    insertItem("Agregar",0);
    insertItem("Modificar",1);
    insertItem("Elimina",2);

}
void QSisManDirecciones::SlotSelecciona(int pintOpcion)
{
   SiscomEscribeLog3Qt("La Opcion:%d",pintOpcion);
   switch(pintOpcion)
   {
   	case 0:
		AnexarDireccion();
	break;
	case 1:
	break;
	case 2:
	break;
   }
}
void QSisManDirecciones::AnexarDireccion()
{

QAnexaDireccion lQADireccion(chrPtrIdPersona,SisDatCom,chrPtrArgumentos);
intEdoOperacion=lQADireccion.Opcion();
}
int QSisManDirecciones::EdoOperacion()
{
 return intEdoOperacion;
}
