create table DatosCasa(IdDireccion integer unique references Direcciones(IdDireccion) unique,
		       IdTipoVivienda integer references TipoViviendas(IdTipoVivienda),
		       TiempoResidir	integer);

