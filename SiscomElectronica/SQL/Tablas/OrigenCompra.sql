create table OrigenCompra(IdRfcOrigen	integer unique,
			   RFC		varchar(25));

create table FacturaVentas(IdVenta	integer);

create table RegistroCompra(IdCompra integer unique,
			    IdOrigenCompra integer references OrigenCompra(IdRfcOrigen),
			    Fecha timestamp without time zone,
			    Importe float);
alter table compras add column IdCompra integer references RegistroCompra(IdCompra);
