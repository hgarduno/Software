create table GeneralesContratoBeneficios(IdVenta integer references ventas(idventa) primary key,
					 Lugar varchar(128),
					 Fecha	date);
