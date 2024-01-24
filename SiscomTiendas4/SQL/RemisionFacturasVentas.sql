ALTER TABLE ventas add constraint venta_primary_key primary key(idventa);
create table RemisionFactura(
		 idventa integer references ventas,
		 tipo varchar(28),
		 numero varchar(10) primary key);
