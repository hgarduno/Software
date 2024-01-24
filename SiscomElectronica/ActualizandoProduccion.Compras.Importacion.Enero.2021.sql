--
-- PostgreSQL database dump
--

-- Dumped from database version 12.1
-- Dumped by pg_dump version 12.1

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'SQL_ASCII';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Data for Name: compraimportacion; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY public.compraimportacion (idcompraimportacion, idempresa, fecha, numerofactura, importefactura, costoenviodolares, costodolar, costoadministrativo, ponderacioncostoadministrativo, numeropartidas, pesocompra) FROM stdin;
1612086666	1488846911	2021-01-22	20202001	38497.000	170.000	21.000	200.000	11.765	17	4971.000
\.


--
-- PostgreSQL database dump complete
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.1
-- Dumped by pg_dump version 12.1

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'SQL_ASCII';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Data for Name: detallecompraimportacion; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY public.detallecompraimportacion (idcompraimportacion, idconsecutivo, cveproducto, cantidad, costounitario) FROM stdin;
1612086666	0	PIC18F4550	100	4.45000
1612086666	1	PIC16F887	100	1.73000
1612086666	2	74LS83	100	1.42000
1612086666	3	IRF540	100	0.21000
1612086666	4	TIP41	100	0.14000
1612086666	5	74LS112	100	0.27000
1612086666	6	74LS283	100	0.70000
1612086666	7	74LS175	50	0.27000
1612086666	8	74LS48	150	0.65000
1612086666	9	LM317T	100	0.25000
1612086666	10	LM35	100	0.78000
1612086666	11	74LS164	100	0.40000
1612086666	12	4N26	100	0.16000
1612086666	13	74LS244	200	0.35000
1612086666	14	ULN2803	100	0.45000
1612086666	15	74LS139	100	0.38000
1612086666	16	L293D	100	0.87000
\.


--
-- Name: detallecompraimportacion_idconsecutivo_seq; Type: SEQUENCE SET; Schema: public; Owner: hgarduno
--

SELECT pg_catalog.setval('public.detallecompraimportacion_idconsecutivo_seq', 300, true);


--
-- PostgreSQL database dump complete
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.1
-- Dumped by pg_dump version 12.1

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'SQL_ASCII';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: descripcioncompraimportacion; Type: TABLE; Schema: public; Owner: hgarduno
--

CREATE TABLE public.descripcioncompraimportacion (
    idcompraimportacion integer,
    descripcion text
);


ALTER TABLE public.descripcioncompraimportacion OWNER TO hgarduno;

--
-- Data for Name: descripcioncompraimportacion; Type: TABLE DATA; Schema: public; Owner: hgarduno
--

COPY public.descripcioncompraimportacion (idcompraimportacion, descripcion) FROM stdin;
2	Algo de displays
2	Compuertas y Resistores
1606144303	Displays y Barras de leds
1604507437	Compuertas , Resistencias y un proto
1605597057	Manuelote I
1606010750	Manuelote II
1612086666	Cotizacion Enero 2021
\.


--
-- Name: descripcioncompraimportacion descripcioncompraimportacion_idcompraimportacion_fkey; Type: FK CONSTRAINT; Schema: public; Owner: hgarduno
--

ALTER TABLE ONLY public.descripcioncompraimportacion
    ADD CONSTRAINT descripcioncompraimportacion_idcompraimportacion_fkey FOREIGN KEY (idcompraimportacion) REFERENCES public.compraimportacion(idcompraimportacion);


--
-- PostgreSQL database dump complete
--

