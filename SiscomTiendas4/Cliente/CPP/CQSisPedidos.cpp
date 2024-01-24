#include <CQSisPedidos.h>
#include <CQSisProdCotiza.h>
#include <CQSisClientes.h>
#include <SisPersonas.h>
#include <CQSisObjetosTiendas4.h>
CQSisPedido::CQSisPedido(const char *pchrPtrIdPedido,
			 const char *pchrPtrIdEmpleado,
			 const char *pchrPtrIdCliente,
			 const char *pchrPtrObservaciones,
			 const char *pchrPtrFecha,
			 const char *pchrPtrImporte)
{
SRegistroPro2	<<
"IdPedido"	<<
"IdEmpleado"	<<
"IdCliente"	<<
"Observaciones"	<<
"Fecha"		<<
"Importe";

SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2						<<
SiscomCampoPro2("IdPedido",pchrPtrIdPedido)		<<
SiscomCampoPro2("IdEmpleado",pchrPtrIdEmpleado)		<<
SiscomCampoPro2("IdCliente",pchrPtrIdCliente)		<<
SiscomCampoPro2("Observaciones",pchrPtrObservaciones)	<<
SiscomCampoPro2("Fecha",pchrPtrFecha)	<<
SiscomCampoPro2("Importe",pchrPtrImporte);
SRegistrosPro2.SiscomAnexaRegistro();
}
CQSisLstPedido::CQSisLstPedido()
{

}

CQSisLstPedido &CQSisLstPedido::operator<<(CQSisPedido *pCQSPedido)
{
	append(pCQSPedido);
	return *this;
}

CQSisOpPedido::CQSisOpPedido(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{

}
void CQSisOpPedido::Registra(CQSisPedido *pCQSPedido)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisLstPedido lCQSLPedido;
lCQSLPedido << pCQSPedido;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLPedido);
SiscomActualiza2SubRegistros("RegistraPedido",&lSRegistrosPro2);
}

void CQSisOpPedido::Pedidos(CQSisCliente *pCQSCliente,
			    CQSisLstPedido *pCQSLPedidos)
{
SisPersona *lSPCliente=pCQSCliente->Persona();
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s",
			 "PedidosCliente",
			 (*lSPCliente)["IdPersona"]);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
/*
 *
 * Esta parte se toma como provisional solo para avanzar,
 * se tendra que integrar en el Archivo de Objetos 
 * la forma de generar la lista de Pedidos
 *
 * Martes 30 de septiembre 2008 Queretaro
 *
 * Se realizo el cambio
 *
 */
SiscomConsulta("ConsultaTiendas4",&lSRegistrosPro2);

ObjetosTiendas4::Pedidos(lSRegistrosPro2,pCQSLPedidos);

}

void CQSisOpPedido::PedidoEntregado(CQSisPedido *pCQSPedido)
{
CQSisLstPedido lCQSLPedido;
SiscomRegistrosPro2 *lSRegistrosPro2;
lCQSLPedido << pCQSPedido;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLPedido);
SiscomActualiza2SubRegistros("PedidoEntregado",&lSRegistrosPro2);
}
