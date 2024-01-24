alter table expendios add constraint unique_idempresa unique(idempresa);
create table BodegaExpendio(IdEmpresa integer references expendios(idEmpresa),
			    IdBodega integer references bodegas(idBodega));
