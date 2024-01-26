create table Departamentos(IdDepartamento 	integer unique,
			   NombreDepto		varchar(30),
			   AbrevDepto		varchar(20));

create table EstatusDepartamento(IdDepartamento integer references Departamentos(IdDepartamento),
				 IdEstatus	integer references Estatus(IdEstatus));

