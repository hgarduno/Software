---

create table ArquitecturaMaquinas(IdMaquina 	integer unique references Maquinas(idmaquina),
				  Maquina	varchar(20),
				  Kernel	varchar(10),
				  Nombre	varchar(128),
				  Procesador	varchar(252));
-- Los campos de esta tabla se obtendran de la siguiente forma
-- Maquina: uname -m
-- Kernel: uname -r
-- Nombre: uname -n
-- Procesador: uname -p
-- Esta 
