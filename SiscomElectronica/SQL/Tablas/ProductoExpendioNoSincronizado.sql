alter table expendios add constraint idempresa_key primary key(idempresa);
create table ProductoExpendioNoSincronizado(
		idEmpresa integer references Expendios(idempresa),
		CveProducto varchar(25),
		primary key(IdEmpresa,CveProducto));
