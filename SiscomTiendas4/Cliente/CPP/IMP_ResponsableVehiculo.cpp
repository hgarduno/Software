#include <IMP_ResponsableVehiculo.h>
#include <IMP_QControlNombres.h>
#include<SISCOMComunicaciones++.h>
#include <CQSisResponsableVehiculo.h>
#include <SiscomDesarrollo3Qt++.h>

QResponsableVehiculo::QResponsableVehiculo(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				ResponsableVehiculo(pQWParent,
						    pchrPtrName,
						    pbModal,
						    pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
exec();
}

QResponsableVehiculo::~QResponsableVehiculo()
{

}

void QResponsableVehiculo::ConectaSlots()
{

connect(QCtrNombre,
	SIGNAL(SignalEnterAMaterno()),
	SLOT(SlotPasaFocoCargo()));
connect(QLECargo,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoAceptar()));
connect(QPBAceptar,
	SIGNAL(clicked()),
	SLOT(SlotAceptar()));

}
void QResponsableVehiculo::SlotAceptar()
{
RegistraResponsable();
	done(1);
}
void QResponsableVehiculo::SlotPasaFocoAceptar()
{
	QPBAceptar->setFocus();
}
void QResponsableVehiculo::SlotPasaFocoCargo()
{
		
	QLECargo->setFocus();
}
void QResponsableVehiculo::IniciaVariables()
{
QCtrNombre->setFocus();
}

void QResponsableVehiculo::NombreCompleto(char *pchrPtrNombre)
{

sprintf(pchrPtrNombre,
	"%s %s %s",
	QCtrNombre->ObtenNombre(),
	QCtrNombre->ObtenAPaterno(),
	QCtrNombre->ObtenAMaterno());
}
void QResponsableVehiculo::Cargo(char *pchrPtrCargo)
{
  strcpy(pchrPtrCargo,
  	 (const char *)QLECargo->text());
}
CQSisResponsableVehiculo *QResponsableVehiculo::Responsable()
{
return new CQSisResponsableVehiculo("",
			   QCtrNombre->ObtenNombre(),
			   QCtrNombre->ObtenAPaterno(),
			   QCtrNombre->ObtenAMaterno(),
			   (const char *)QLECargo->text());
}
/*
 *
 * El registro del responsbla del vehiculo se debera realizar
 * en dos fase, primero se registra el responsable, para validad
 * si esta en la base de datos, si es asi, el sistema regresa 
 * persona ya registrada, y se debera realizar la consulta del
 * cargo.
 *
 * Si se registra la persona, y no se encontro en la base de 
 * datos entonces con el idPersona que se regresa en el proceso
 * de insercion de la persona, se debera registrar en una segunda
 * operacion el cargo del responsable del vehiculo
 *
 */
int QResponsableVehiculo::RegistraResponsable()
{
CQSisClienteOp3Qt lCQSOpCliente(SisDatCom);
CQSC3QtResponsable=Responsable();
if(lCQSOpCliente.RegistraResponsableVehiculo(CQSC3QtResponsable))
{
SiscomEscribeLog3Qt("Ya esta el reponsable Se Consulta su cargo");
return 1;
}
else 
return 0;

}
