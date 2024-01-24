alter table definiciontiposproducto alter column cantidad type numeric(10,2);
alter table importeorden add constraint   idventa_Unico unique (idventa);
alter table importeorden add column edoventa integer;
