create table CajaMaterial(IdCaja integer unique,
		  Caja varchar(25) primary key,
		  Descripcion text);
create table Estante(IdEstante integer unique,
		     Estante varchar(25) primary key,
		     Descripcion text);
create table UbicacionProducto(cveproducto varchar(25) references Productos(CveProducto) primary key,
			       IdEstante integer references Estante(IdEstante),
			       IdCaja integer references CajaMaterial(IdCaja));
