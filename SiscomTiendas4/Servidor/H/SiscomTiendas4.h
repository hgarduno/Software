#ifndef __SISCOMTIENDAS4_H__
#define __SISCOMTIENDAS4_H__
#include <SiscomDesarrollo2.h>
#include <Sepomex.h>
#include <Familias.h>
#include <Productos.h>
#include <ConsultasTiendas4.h>
#include <Empresas.h>
#include <Precios.h>
#include <Compras.h>
#include <Cotiza.h>
#include <Devoluciones.h>
#include <Ventas.h>
#include <Empleados.h>
#include <Paquetes.h>


void OperacionesSistemaGeneral(SSiscomOperaciones **);
void AsignaOperacionesVersion2(int ,
				int,
				SSiscomOperaciones2 **,
				SArgsSiscom *);
void SiscomErrorOperacion2(SArgsSiscom *pSAgsSisPtr);


#endif
