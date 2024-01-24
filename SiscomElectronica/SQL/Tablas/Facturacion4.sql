
-- Viernes 21 de Octubre del 2016
-- Se agrega la tablas, que afectan los datos de las facturas.

create table NumeroExterior(IdPersona integer,
			    IdEmpresa integer,
			    NumeroInt varchar(6));
create table Facturado(IdPersona integer,
		       IdEmpresa integer,
		       IdFactura integer unique,
		       IdEstado integer,
		       Fecha timestamp without time zone);

create table OrdenesFacturadas(IdFactura integer references Facturado(IdFactura),
			       IdVenta integer);

