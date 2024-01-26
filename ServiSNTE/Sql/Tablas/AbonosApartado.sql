create table AbonosApartado(IdVenta integer references ventas(idVenta),
			    Fecha timestamp without time zone,
			    Monto	numeric(10,2),
                IdEstado integer);

create table TotalAbonado(IdVenta integer references ventas(idVenta) primary key,
			  Total numeric(10,2));
