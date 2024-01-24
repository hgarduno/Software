create table Facturas(IdFactura integer unique,
		      Folio	integer, -- Se incrementa por cada factura
		      Fecha	date,
		      Importe	float,
		      Iva	float,
		      Total	float);

create table EstadosFactura(IdEstado integer unique ,
			    Descripcion varchar(128));

create table EstadoFactura(IdFactura integer references Facturas(IdFactura),
			   IdEstado integer references EstadosFactura(IdEstado),
			   Fecha timestamp without time zone,
			   primary key(IdFactura,IdEstado));



create table FacturasFisicas(IdFactura integer references Facturas(IdFactura),
			     IdCliente  integer );

create table FacturasMorales(IdFactura integer references Facturas(IdFactura),
			     IdEmpresa integer);
				   
create table DetalleFactura(IdFactura integer references Facturas(IdFactura),
			    CveProducto varchar(50),
			    Cantidad	numeric(10,2),
			    Precio	numeric(10,2),
			    Importe	numeric(10,2));

insert into EstadosFactura values(0,'Registrada');
insert into EstadosFactura values(1,'Enviada Cliente');


-- Viernes 21 de Octubre del 2016
-- Se agrega la tablas, que afectan los datos de las facturas.

