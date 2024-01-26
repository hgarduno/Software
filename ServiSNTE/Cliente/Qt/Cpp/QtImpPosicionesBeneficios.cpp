#include <QtImpPosicionesBeneficios.h>
#include <QtImpCapturaCantidad.h>
#include <zSiscomQt3.h>
#include <zSiscomDesarrollo4.h>
#include <qtable.h>
#include <qpushbutton.h>
QtImpPosicionesBeneficios::QtImpPosicionesBeneficios(Registro *pRegistro,
						     QWidget *pQWParent,
						     const char *pchrPtrName,
						     bool pbModal,
						     WFlags pWFlags):
						  PosicionesBeneficios(pQWParent,
						  		       pchrPtrName,
								       pbModal,
								       pWFlags),
						  RegPosiciones(pRegistro)
{
IniciaVariables();
ConectaSlots();
exec();
}
void QtImpPosicionesBeneficios::IniciaVariables()
{
QTPosiciones->setNumRows(55);
if(!TraeInformacionPosiciones())
{
LogSiscom("Se Inicia la primera corrida");
IniciaPosiciones();
}
else
AsignaPosiciones();
}
void QtImpPosicionesBeneficios::ConectaSlots()
{
connect(QPBIncrementaX,
	SIGNAL(clicked()),
	SLOT(SlotIncrementaX()));

connect(QPBIncrementaY,
	SIGNAL(clicked()),
	SLOT(SlotIncrementaY()));
connect(QPBAceptar,
	SIGNAL(clicked()),
	SLOT(SlotAceptar()));
}
void QtImpPosicionesBeneficios::SlotAceptar()
{
intAceptar=1;
done(1);
}
void QtImpPosicionesBeneficios::SlotIncrementaX()
{
   
}
void QtImpPosicionesBeneficios::SlotIncrementaY()
{
int lintIncremento;
 lintIncremento=CapturaCantidadIncremento();
 IncrementandoCamposY(lintIncremento);
 AsignaIncrementoY();
}
void QtImpPosicionesBeneficios::IniciaPosiciones()
{
PosicionCampo("Fecha",0,550,150);
PosicionCampo("APaterno",1,50,300);
PosicionCampo("AMaterno",2,00,300);
PosicionCampo("Nombre",3,300,300);
PosicionCampo("RFC",4,50,333);
PosicionCampo("CURP",5,300,333);
PosicionCampo("Entidad",6,550,333);
PosicionCampo("PaisNacimiento",7,50,370);
PosicionCampo("Masculino",8,300,370);
PosicionCampo("Femenino",9,330,370);
PosicionCampo("Casado",10,460,370);
PosicionCampo("Soltero",11,490,370);
PosicionCampo("Edad",12,525,370);
PosicionCampo("Fecha Nacimiento",13,590,370);
PosicionCampo("Identificacion",14,50,400);
PosicionCampo("No Identificacion",15,300,400);
PosicionCampo("Opcupacion",16,500,400);
PosicionCampo("Nacionalidad",17,630,400);
PosicionCampo("Calle",18,50,445);
PosicionCampo("NoExterior",19,305,445);
PosicionCampo("NoInterior",20,380,445);
PosicionCampo("Colonia",21,460,445);
PosicionCampo("Codigo Postal",22,660,445);
PosicionCampo("Delegacion",23,50,475);
PosicionCampo("Ciudad",24,380,475);
PosicionCampo("Estado",25,380,475);
PosicionCampo("Pais",26,630,475);
PosicionCampo("Tipo Vivienda Propia",27,150,500);
PosicionCampo("Tipo Vivienda Hipetecada",28,200,500);
PosicionCampo("Tipo Vivienda Otra",29,300,550);
PosicionCampo("Tipo Vivienda Rentada",30,150,600);
PosicionCampo("Tipo Vivienda Familiar",31,200,600);
PosicionCampo("Telefono Particular",32,560,515);
PosicionCampo("Tiempo Residir",33,50,560);
PosicionCampo("Telefono Celular",34,200,560);
PosicionCampo("Correo electronico",35,380,560);
PosicionCampo("Telefono Recado",36,590,560);
PosicionCampo("Nombre Empresa",37,50,615);
PosicionCampo("Antiguedad",38,360,615);
PosicionCampo("Puesto",39,500,615);
PosicionCampo("Giro",40,50,645);
PosicionCampo("Jefe",41,400,645);
PosicionCampo("Calle Empleo",42,50,695);
PosicionCampo("No Exterior Empleo",43,280,695);
PosicionCampo("No Interior Empleo",44,350,695);
PosicionCampo("Colonia Empleo",45,400,695);
PosicionCampo("CP Empleo",46,660,695);
PosicionCampo("Delegacion empleo",47,50,755);
PosicionCampo("Ciudad Empleo",48,305,725);
PosicionCampo("Estado empleo",49,560,725);
PosicionCampo("Pais Empleo",50,50,755);
PosicionCampo("Telefono Empleo",51,200,755);
PosicionCampo("Ext Telefono Empleo",52,380,755);
PosicionCampo("Correo Empelo",53,460,755);
PosicionesAImpresion(RegPosiciones);
}
void QtImpPosicionesBeneficios::PosicionCampo(const char *pchrPtrCampo,
					     int pintNCampo,
					     int pintX,
					     int pintY)
{
QTPosiciones->setText(pintNCampo,0,pchrPtrCampo);
QTPosiciones->setText(pintNCampo,1,QString().setNum(pintX));
QTPosiciones->setText(pintNCampo,2,QString().setNum(pintY));
}
void QtImpPosicionesBeneficios::PosicionesAImpresion(Registro *pRegistro)
{
int lintContador;
for(lintContador=0;
    lintContador<QTPosiciones->numRows();
    lintContador++,
    pRegistro++)
{
		
   pRegistro->x=QTPosiciones->text(lintContador,1).toInt(); 
   pRegistro->y=QTPosiciones->text(lintContador,2).toInt(); 
   pRegistro->valor="";
   LogSiscom("%d.- %s (%d,%d)",
   		lintContador,
		pRegistro->valor,
		pRegistro->x,
		pRegistro->y);
}
pRegistro->valor=0;
}


int QtImpPosicionesBeneficios::TraeInformacionPosiciones()
{
int lintContador=0;
Registro *lRegPosiciones=RegPosiciones;
while(lRegPosiciones->valor)
{
	lintContador++;
	lRegPosiciones++;
}
return lintContador;
}
void QtImpPosicionesBeneficios::AsignaPosiciones()
{
int lintContador=0;
Registro *lRegPosiciones;
while(lRegPosiciones->valor)
{
   PosicionCampo(lRegPosiciones->valor,
   		 lintContador,
		 lRegPosiciones->x,
		 lRegPosiciones->y);
   lRegPosiciones++;
   lintContador++;
}
}
int QtImpPosicionesBeneficios::CapturaCantidadIncremento()
{
QString lQStrCantidad;
QtImpCapturaCantidad lQtImpCapCantidad;
if(lQtImpCapCantidad.Aceptar())
{
 lQtImpCapCantidad.Cantidad(&lQStrCantidad);
 return lQStrCantidad.toInt();
}
else
return 0;
}
void QtImpPosicionesBeneficios::IncrementandoCamposY(int pintIncremento)
{
int lintContador; 
for(lintContador=0;
    lintContador<QTPosiciones->numRows();
    lintContador++)
{
  if(QTPosiciones->isRowSelected(lintContador))
	(RegPosiciones+lintContador)->y+=pintIncremento;
}
}
void QtImpPosicionesBeneficios::AsignaIncrementoY()
{
int lintContador;
Registro *lRegPosiciones=RegPosiciones;
for(lintContador=0;
    lintContador<QTPosiciones->numRows();
    lintContador++,
    lRegPosiciones++)
 QTPosiciones->setText(lintContador,
 		       2,
		       QString().setNum(lRegPosiciones->y));
}
int QtImpPosicionesBeneficios::Aceptar()
{
  return intAceptar;
}
