
insert into TipoCompetencia values(0,'Trampolin');
insert into TipoCompetencia values(1,'Artistica Varonil');
insert into TipoCompetencia values(2,'Artistica Femenil');

-- El -1, en esta tabla indicara que no hay una edad limite
--- Grupos para trampolin

insert into Grupos values(0,0,-1,-1,'Grupo A');
insert into Grupos values(1,0,9,11,'Grupo A');
insert into Grupos values(2,0,10,12,'Grupo A');
insert into Grupos values(3,0,13,15,'Grupo A');
insert into Grupos values(4,0,11,12,'Grupo A');
insert into Grupos values(5,0,16,18,'Grupo A');
insert into Grupos values(6,0,18,-1,'Grupo A');

insert into Grupos values(8,0,-1,-1,'Grupo B');
insert into Grupos values(9,0,12,14,'Grupo B');
insert into Grupos values(10,0,13,15,'Grupo B');
insert into Grupos values(11,0,16,17,'Grupo B');
insert into Grupos values(12,0,13,14,'Grupo B');
insert into Grupos values(13,0,19,-1,'Grupo B');
insert into Grupos values(14,0,17,-1,'Grupo B');

insert into Grupos values(15,0,-1,-1,'Grupo C');
insert into Grupos values(16,0,15,-1,'Grupo C');
insert into Grupos values(17,0,17,-1,'Grupo C');
insert into Grupos values(18,0,18,-1,'Grupo C');


---Grupos para Artistica Varonil 

insert into Grupos values(19,1,-1,-1,'Grupo A');
insert into Grupos values(20,1,5,7,'Grupo A');
insert into Grupos values(21,1,8,10,'Grupo A');
insert into Grupos values(22,1,11,12,'Grupo A');
insert into Grupos values(23,1,13,-1,'Grupo A');

insert into Grupos values(24,1,-1,-1,'Grupo B');
insert into Grupos values(25,1,5,7,'Grupo B');
insert into Grupos values(26,1,8,10,'Grupo B');
insert into Grupos values(27,1,11,12,'Grupo B');
insert into Grupos values(28,1,13,-1,'Grupo B');
insert into Grupos values(29,1,13,15,'Grupo B');
insert into Grupos values(30,1,16,-1,'Grupo B');


insert into Grupos values(31,1,-1,-1,'Grupo C');
insert into Grupos values(32,1,5,7,'Grupo C');
insert into Grupos values(33,1,8,10,'Grupo C');
insert into Grupos values(34,1,11,-1,'Grupo C');

insert into Grupos values(35,1,-1,-1,'Grupo D');
insert into Grupos values(36,1,5,7,'Grupo D');
insert into Grupos values(37,1,8,10,'Grupo D');
insert into Grupos values(38,1,11,12,'Grupo D');
insert into Grupos values(39,1,13,14,'Grupo D');
insert into Grupos values(40,1,14,15,'Grupo D');
insert into Grupos values(41,1,15,16,'Grupo D');

---Grupos para Artistica Femenil 

insert into Grupos values(42,2,-1,-1,'Grupo A');
insert into Grupos values(43,2,5,7,'Grupo A');
insert into Grupos values(44,2,8,10,'Grupo A');
insert into Grupos values(45,2,11,12,'Grupo A');
insert into Grupos values(46,2,13,-1,'Grupo A');

insert into Grupos values(47,2,-1,-1,'Grupo B');
insert into Grupos values(48,2,5,7,'Grupo B');
insert into Grupos values(49,2,8,10,'Grupo B');
insert into Grupos values(50,2,11,12,'Grupo B');
insert into Grupos values(51,2,13,-1,'Grupo B');
insert into Grupos values(52,2,13,15,'Grupo B');
insert into Grupos values(53,2,16,-1,'Grupo B');


insert into Grupos values(54,2,-1,-1,'Grupo C');
insert into Grupos values(55,2,5,7,'Grupo C');
insert into Grupos values(56,2,8,10,'Grupo C');
insert into Grupos values(57,2,11,-1,'Grupo C');

insert into Grupos values(58,2,-1,-1,'Grupo D');
insert into Grupos values(59,2,5,7,'Grupo D');
insert into Grupos values(60,2,8,10,'Grupo D');
insert into Grupos values(61,2,11,12,'Grupo D');
insert into Grupos values(62,2,13,14,'Grupo D');
insert into Grupos values(63,2,14,15,'Grupo D');
insert into Grupos values(64,2,15,16,'Grupo D');

insert into Grupos values(65,2,-1,-1,'Grupo E');
insert into Grupos values(66,2,5,7,'Grupo E');
insert into Grupos values(67,2,8,10,'Grupo E');
insert into Grupos values(68,2,11,12,'Grupo E');
insert into Grupos values(69,2,13,14,'Grupo E');
insert into Grupos values(70,2,14,15,'Grupo E');
insert into Grupos values(71,2,15,16,'Grupo E');


---- Clases para trampolin


insert into CatClase values(1,0,'VIII');
insert into CatClase values(2,0,'VII');
insert into CatClase values(3,0,'VI');
insert into CatClase values(4,0,'V');
insert into CatClase values(5,0,'IV');
insert into CatClase values(6,0,'III');
insert into CatClase values(7,0,'II');
insert into CatClase values(8,0,'I');

insert into CatNivel values(1,1,1,'Nivel 1');
insert into CatNivel values(1,2,2,'Nivel 2');
insert into CatNivel values(2,3,3,'Nivel 3');
insert into CatNivel values(2,4,4,'Nivel 4');
insert into CatNivel values(3,5,5,'Nivel 5');
insert into CatNivel values(3,6,6,'Nivel 6');
insert into CatNivel values(4,7,7,'Nivel 7');
insert into CatNivel values(4,8,8,'Nivel 8');
insert into CatNivel values(5,9,9,'Nivel 9');
insert into CatNivel values(6,10,10,'Nivel 10');
insert into CatNivel values(6,11,11,'Nivel 11');
insert into CatNivel values(7,12,12,'Nivel 12');
insert into CatNivel values(8,13,13,'Nivel 13');

--- Clases Para artistica varonil

insert into CatClase values(9,1,'Unica');

--- Clases para artistica femenil

insert into CatClase values(10,2,'VIII');
insert into CatClase values(11,2,'VII');
insert into CatClase values(12,2,'VI');
insert into CatClase values(13,2,'V');
insert into CatClase values(14,2,'IV');
insert into CatClase values(15,2,'III');
insert into CatClase values(16,2,'II');
insert into CatClase values(17,2,'I');

--- Niveles artistica Varonil

insert into CatNivel values(9,14,1,'Nivel 1');
insert into CatNivel values(9,15,2,'Nivel 2');
insert into CatNivel values(9,16,3,'Nivel 3');
insert into CatNivel values(9,17,4,'Nivel 4');
insert into CatNivel values(9,18,5,'Nivel 5');
insert into CatNivel values(9,19,6,'Nivel 6');
insert into CatNivel values(9,20,7,'Nivel 7');
insert into CatNivel values(9,21,8,'Nivel 8');

-- Niveles artistica Femenil

insert into CatNivel values(10,22,1,'Nivel 1');
insert into CatNivel values(10,23,2,'Nivel 2');
insert into CatNivel values(10,24,3,'Nivel 3');
insert into CatNivel values(10,25,4,'Nivel 4');

insert into CatNivel values(11,26,7,'Nivel 7');
insert into CatNivel values(12,27,6,'Nivel 6');
insert into CatNivel values(13,28,4,'Nivel 5');
insert into CatNivel values(14,29,5,'Nivel 4');
insert into CatNivel values(15,30,3,'Nivel 3');
insert into CatNivel values(16,31,2,'Nivel 2');
insert into CatNivel values(17,32,1,'Nivel 1');

insert into Aparatos values(0,'Trampolin');
insert into Aparatos values(1,'Piso');
insert into Aparatos values(2,'Salto De Caballo');
insert into Aparatos values(3,'Barras Asimetricas');
insert into Aparatos values(4,'Viga De Equilibrio');
insert into Aparatos values(5,'Anillos');
insert into Aparatos values(6,'Caballo con arzones');
insert into Aparatos values(7,'Barra Fija');
insert into Aparatos values(8,'Barras Paralelas');

--Trampolin

insert into AparatosCompetencia values(0,0);

--- Artistica Varonil

insert into AparatosCompetencia values(1,1);
insert into AparatosCompetencia values(1,2);
insert into AparatosCompetencia values(1,5);
insert into AparatosCompetencia values(1,6);
insert into AparatosCompetencia values(1,7);
insert into AparatosCompetencia values(1,8);

--- Artistica Femenil

insert into AparatosCompetencia values(2,1);
insert into AparatosCompetencia values(2,2);
insert into AparatosCompetencia values(2,3);
insert into AparatosCompetencia values(2,4);
			
