create table ComunicacionMatriz(IdMatriz integer unique  references Empresas(idEmpresa),
				DirIp	varchar(25),
				Puerto	integer,
				primary key(DirIp,Puerto));
