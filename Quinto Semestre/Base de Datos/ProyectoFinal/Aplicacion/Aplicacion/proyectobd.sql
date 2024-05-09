-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 02-12-2023 a las 00:19:56
-- Versión del servidor: 10.4.25-MariaDB
-- Versión de PHP: 8.1.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `proyectobd`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `album`
--

CREATE TABLE `album` (
  `ID` int(11) NOT NULL,
  `Portada` varchar(300) COLLATE utf8mb4_spanish_ci NOT NULL DEFAULT '../Source/Portadas/default.png',
  `Nombre` varchar(120) COLLATE utf8mb4_spanish_ci NOT NULL,
  `Anio` int(11) NOT NULL,
  `Descripcion` varchar(160) COLLATE utf8mb4_spanish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_spanish_ci;

--
-- Volcado de datos para la tabla `album`
--

INSERT INTO `album` (`ID`, `Portada`, `Nombre`, `Anio`, `Descripcion`) VALUES
(5, '../Source/Portadas/bocanada.jpg', 'Bocanada', 1999, 'Segundo disco solista del cantatutor argentino Gustavo Cerati'),
(8, '../Source/Portadas/pddc.jpg', 'Primer Dia de Clases', 2021, 'El primer disco de Mora lanzado en 2020'),
(11, '../Source/Portadas/mornoletemasalaoscuridad.jpg', 'Mor, no le temas a la oscuridad', 2023, 'Acabo de dejarte en casa'),
(14, '../Source/Portadas/Amor_amarillo.jpg', 'Amor Amarillo', 1993, 'El primer disco solista de Cerati');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `artistas`
--

CREATE TABLE `artistas` (
  `ID` int(11) NOT NULL,
  `Foto` varchar(300) COLLATE utf8mb4_spanish_ci NOT NULL DEFAULT '../Source\\Artistas\\default.png',
  `Nombre` varchar(50) COLLATE utf8mb4_spanish_ci NOT NULL,
  `NacAno` int(11) NOT NULL,
  `NacMes` int(11) NOT NULL,
  `NacDia` int(11) NOT NULL,
  `FKIDPais` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_spanish_ci;

--
-- Volcado de datos para la tabla `artistas`
--

INSERT INTO `artistas` (`ID`, `Foto`, `Nombre`, `NacAno`, `NacMes`, `NacDia`, `FKIDPais`) VALUES
(2, '../Source/Artistas/feid.jpg', 'Feid', 1992, 8, 19, 49),
(4, '../Source/Artistas/mora.jpg', 'Mora', 1996, 4, 18, 181),
(5, '../Source/Artistas/gustavo_cerati.jpeg', 'Gustavo Cerati', 1959, 8, 11, 11);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `artistasxcancion`
--

CREATE TABLE `artistasxcancion` (
  `ID` int(11) NOT NULL,
  `FKIDArtista` int(11) NOT NULL,
  `FKIDCancion` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_spanish_ci;

--
-- Volcado de datos para la tabla `artistasxcancion`
--

INSERT INTO `artistasxcancion` (`ID`, `FKIDArtista`, `FKIDCancion`) VALUES
(2, 1, 4),
(3, 1, 4),
(16, 4, 1),
(20, 2, 3),
(21, 5, 2),
(22, 5, 4);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `canciones`
--

CREATE TABLE `canciones` (
  `ID` int(11) NOT NULL,
  `Nombre` varchar(50) COLLATE utf8mb4_spanish_ci NOT NULL,
  `DuracionMin` int(11) NOT NULL,
  `DuracionSeg` int(11) NOT NULL,
  `Letra` varchar(2000) COLLATE utf8mb4_spanish_ci NOT NULL,
  `Disponibilidad` int(11) NOT NULL DEFAULT 1
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_spanish_ci;

--
-- Volcado de datos para la tabla `canciones`
--

INSERT INTO `canciones` (`ID`, `Nombre`, `DuracionMin`, `DuracionSeg`, `Letra`, `Disponibilidad`) VALUES
(1, 'Buenos Aires', 1, 58, 'Uoh\r\nSe cansó de que estuvieron controlándola\r\nPeleándole por to, siempre llamándola\r\nY ella otra ve revolcándose\r\nEn mi cama viendo el amanecer\r\nEso ojito color café\r\nMe derrito si me ven\r\nQue se joda si nos ven\r\nY se hace tarde, así que no te tarde\r\nEl reloj e nuestro enemigo\r\nSabes dónde resido\r\nTú solo cáele\r\nPa hacerte el truquito ese que te quita el aire\r\nVámonos first class pa Buenos Aires\r\nDijo, Nos van a ver y yo le dije, ¿Y qué?\r\n¿Qué esto iba a pasar? Lo pronostiqué\r\nYo me la acerqué y ni le expliqué\r\nEso fue un jueve y se quedó el weekend entero\r\nPidiéndolo entero, yo bien caballero\r\nPor cortesía pa entrar me quité el sombrero\r\nMami, lero, lero, si te soy sincero\r\nMe importa un carajo lo que piensen los tercero\r\nSe hace tarde, así que no te tarde\r\nEl reloj e nuestro enemigo\r\nSabes dónde resido\r\nTú solo cáele\r\nPa hacerte el truquito ese que te quita el aire\r\nVámonos first class pa Buenos Aires\r\nPidiéndolo entero, yo bien caballero\r\nPor cortesía pa entrar, me quité el sombrero, mami\r\nZion, baby', 1),
(2, 'Puente', 4, 33, 'Hoy te busqué\r\nEn la rima que duerme\r\nCon todas las palabras\r\nSi algo callé\r\nEs porque entendí todo\r\nMenos la distancia\r\nDesordené\r\nÁtomos tuyos para hacerte\r\nAparecer\r\nUn día más\r\nUn día más\r\nArriba el sol\r\nAbajo el reflejo\r\nVe cómo estalla mi alma\r\nYa estás aquí\r\nY el paso que dimos\r\nEs causa y es efecto\r\nCruza el amor\r\nYo cruzaré los dedos\r\nY gracias por venir\r\nGracias por venir\r\nAdorable puente\r\nSe ha creado entre los dos\r\nCruza el amor\r\nYo cruzaré los dedos\r\nY gracias por venir\r\nGracias por venir\r\nGracias por venir\r\nGracias por venir\r\nAdorable puente\r\nCruza el amor\r\nCruza el amor\r\nPor el puente\r\nUsa el amor\r\nUsa el amor\r\nComo un puente', 1),
(3, 'Perro Negro', 2, 42, 'Al menos dame un perreíto, mor\r\nWow\r\nYo no sabía que tú era así\r\nTe juro que ahora me cae mejor\r\nMe contaron muchas cosas de ti\r\nPero eres más hijueputa que yo\r\nEs de hacer, no es de hablar\r\nSuelta el cel pa perrear\r\nPa Twitter y pa entonar, yeah\r\nSalió de roce al Poblao, ey, ey\r\nTaba perdida y ahora anda en to lao, ey, ey\r\nUno prendío y el otro está enrolao, ey, ey\r\nHoy es el día, por si no me has probao (yeah-yeah-yeah-yeah, ey)\r\nVi que te dejaste de tu novio, baby, me alegro\r\nVamo a celebrarlo en Perro Negro\r\nDile a ese cabrón que tú no quiere arreglo\r\nDile a tu pai que quiero que sea mi suegro\r\nMami, tiene el party prendío\r\nSaco 2CB, toy sorprendío\r\nMe dijo que la amiguita está pal trío, je\r\nLa loquita es un lío\r\nSi le ponen reggaetón, marihuana\r\nHoy se parcha hasta las seis de la mañana\r\nQuiero que salga de mi mente y te meta en mi cama, porque, je\r\nTú tiene cara que tiene la pussy linda\r\nQue los dejas loco, enchulao como Belinda\r\nMenéame las chapa hasta que me rinda\r\nUn hijo en la disco, vo a dejarte encinta\r\nEh-eh-eh-eh-eh\r\nNo me importa cuál es la hora ni cuál es tu signo\r\nEh-eh-eh-eh-eh\r\nSi el DJ fuera pastor, nos casábamo aquí mismo\r\nEh-eh-eh-eh-eh\r\nBaby, perrear con otro y conmigo no es lo mismo\r\nEh-eh-eh-eh-eh\r\nFERXXO\r\nBad Bunny, baby, bebé\r\nSalió de roce al Pobla o, ey, ey\r\nTaba perdida y ahora anda en to lao, ey, ey\r\nUno prendío y el otro está enrolao, ey, ey\r\nHoy es el día por si no me has probao\r\nEy, ey (wow)\r\nMami, bronceaíta, solita\r\nLo de hoy no lo tiene que postear\r\nNo andas solita, andas con un par\r\nUna paisita, she looks so fine\r\nTiene un culo chimba y cara mejor\r\nNegro el bolso, negro los Halls\r\nEstabas triste, pero no hoy\r\nTiene rosita sin ODEROI\r\nBebé, está encendía, prendía\r\nSale de noche y llega de día\r\nExótica, bandida\r\nUna bebé, Real G e por vida', 1),
(4, 'A Merced', 6, 28, 'Hey, hey, hey, a merced\r\nMi amor es real\r\nMe vuelvo a quedar a merced\r\nHey, hey, hey, a merced\r\nHistorias de sal\r\nMe vuelven a dejar a merced\r\nTomar la dosis\r\nY levitar\r\nAtado a tu belleza inconsciente\r\nQue mece mi espíritu y cuelga\r\nHey, hey, hey, a merced\r\nTe escucho soñar\r\nMe vuelvo a quedar a merced\r\nCasi quiero que te despiertes\r\nY es porque\r\nPodrías sonreír de verme flotar\r\nHey, hey, hey, a merced\r\nMi amor es real\r\nMe vuelvo a quedar a merced\r\nHey, hey, hey, a merced\r\nMi amor es real\r\nMe vuelvo a quedar a merced\r\nHey, hey, hey, a merced\r\nMi amor es real\r\nMe vuelvo a quedar\r\nCeci\r\nTomar una dosis\r\nY levitar\r\nAtado a tu belleza inconsciente\r\nAdentro tuyo\r\nMe caigo del sol\r\nAdentro tuyo es único\r\nEs único\r\nCuerpos de luz\r\nCorriendo en pleno cielo\r\nCristales de amor amarillo\r\nMe hundo en el mar\r\nDe la fertilidad\r\nCristales de amor amarillo\r\nAmarillo\r\nAmarillo\r\nTe amo\r\nTe amo\r\nTe amo\r\nTe amo', 1);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `cancionesxalbum`
--

CREATE TABLE `cancionesxalbum` (
  `ID` int(11) NOT NULL,
  `FKIDAlbum` int(11) NOT NULL,
  `NombreAlbum` varchar(120) COLLATE utf8mb4_spanish_ci NOT NULL,
  `FKIDCancion` int(11) NOT NULL,
  `NombreCancion` varchar(120) COLLATE utf8mb4_spanish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_spanish_ci;

--
-- Volcado de datos para la tabla `cancionesxalbum`
--

INSERT INTO `cancionesxalbum` (`ID`, `FKIDAlbum`, `NombreAlbum`, `FKIDCancion`, `NombreCancion`) VALUES
(27, 11, 'Mor, no le temas a la oscuridad', 3, 'Perro Negro'),
(28, 5, 'Bocanada', 2, 'Puente'),
(29, 8, 'Primer Dia de Clases', 1, 'Buenos Aires'),
(30, 14, 'Amor Amarillo', 4, 'A Merced');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `cancionesxplaylist`
--

CREATE TABLE `cancionesxplaylist` (
  `ID` int(11) NOT NULL,
  `FKIDPlaylist` int(11) NOT NULL,
  `FKIDCancion` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_spanish_ci;

--
-- Volcado de datos para la tabla `cancionesxplaylist`
--

INSERT INTO `cancionesxplaylist` (`ID`, `FKIDPlaylist`, `FKIDCancion`) VALUES
(1, 2, 3),
(4, 2, 1);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `pais`
--

CREATE TABLE `pais` (
  `ID` int(11) NOT NULL,
  `Nombre` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `pais`
--

INSERT INTO `pais` (`ID`, `Nombre`) VALUES
(1, 'Afghanistan'),
(2, 'Aland Islands'),
(3, 'Albania'),
(4, 'Algeria'),
(5, 'American Samoa'),
(6, 'Andorra'),
(7, 'Angola'),
(8, 'Anguilla'),
(9, 'Antarctica'),
(10, 'Antigua and Barbuda'),
(11, 'Argentina'),
(12, 'Armenia'),
(13, 'Aruba'),
(14, 'Australia'),
(15, 'Austria'),
(16, 'Azerbaijan'),
(17, 'Bahamas'),
(18, 'Bahrain'),
(19, 'Bangladesh'),
(20, 'Barbados'),
(21, 'Belarus'),
(22, 'Belgium'),
(23, 'Belize'),
(24, 'Benin'),
(25, 'Bermuda'),
(26, 'Bhutan'),
(27, 'Bolivia'),
(28, 'Bonaire, Sint Eustatius and Saba'),
(29, 'Bosnia and Herzegovina'),
(30, 'Botswana'),
(31, 'Bouvet Island'),
(32, 'Brazil'),
(33, 'British Indian Ocean Territory'),
(34, 'Brunei Darussalam'),
(35, 'Bulgaria'),
(36, 'Burkina Faso'),
(37, 'Burundi'),
(38, 'Cambodia'),
(39, 'Cameroon'),
(40, 'Canada'),
(41, 'Cape Verde'),
(42, 'Cayman Islands'),
(43, 'Central African Republic'),
(44, 'Chad'),
(45, 'Chile'),
(46, 'China'),
(47, 'Christmas Island'),
(48, 'Cocos (Keeling) Islands'),
(49, 'Colombia'),
(50, 'Comoros'),
(51, 'Congo'),
(52, 'Congo, Democratic Republic of the Congo'),
(53, 'Cook Islands'),
(54, 'Costa Rica'),
(55, 'Cote D\'Ivoire'),
(56, 'Croatia'),
(57, 'Cuba'),
(58, 'Curacao'),
(59, 'Cyprus'),
(60, 'Czech Republic'),
(61, 'Denmark'),
(62, 'Djibouti'),
(63, 'Dominica'),
(64, 'Dominican Republic'),
(65, 'Ecuador'),
(66, 'Egypt'),
(67, 'El Salvador'),
(68, 'Equatorial Guinea'),
(69, 'Eritrea'),
(70, 'Estonia'),
(71, 'Ethiopia'),
(72, 'Falkland Islands (Malvinas)'),
(73, 'Faroe Islands'),
(74, 'Fiji'),
(75, 'Finland'),
(76, 'France'),
(77, 'French Guiana'),
(78, 'French Polynesia'),
(79, 'French Southern Territories'),
(80, 'Gabon'),
(81, 'Gambia'),
(82, 'Georgia'),
(83, 'Germany'),
(84, 'Ghana'),
(85, 'Gibraltar'),
(86, 'Greece'),
(87, 'Greenland'),
(88, 'Grenada'),
(89, 'Guadeloupe'),
(90, 'Guam'),
(91, 'Guatemala'),
(92, 'Guernsey'),
(93, 'Guinea'),
(94, 'Guinea-Bissau'),
(95, 'Guyana'),
(96, 'Haiti'),
(97, 'Heard Island and Mcdonald Islands'),
(98, 'Holy See (Vatican City State)'),
(99, 'Honduras'),
(100, 'Hong Kong'),
(101, 'Hungary'),
(102, 'Iceland'),
(103, 'India'),
(104, 'Indonesia'),
(105, 'Iran, Islamic Republic of'),
(106, 'Iraq'),
(107, 'Ireland'),
(108, 'Isle of Man'),
(109, 'Israel'),
(110, 'Italy'),
(111, 'Jamaica'),
(112, 'Japan'),
(113, 'Jersey'),
(114, 'Jordan'),
(115, 'Kazakhstan'),
(116, 'Kenya'),
(117, 'Kiribati'),
(118, 'Korea, Democratic People\'s Republic of'),
(119, 'Korea, Republic of'),
(120, 'Kosovo'),
(121, 'Kuwait'),
(122, 'Kyrgyzstan'),
(123, 'Lao People\'s Democratic Republic'),
(124, 'Latvia'),
(125, 'Lebanon'),
(126, 'Lesotho'),
(127, 'Liberia'),
(128, 'Libyan Arab Jamahiriya'),
(129, 'Liechtenstein'),
(130, 'Lithuania'),
(131, 'Luxembourg'),
(132, 'Macao'),
(133, 'Macedonia, the Former Yugoslav Republic of'),
(134, 'Madagascar'),
(135, 'Malawi'),
(136, 'Malaysia'),
(137, 'Maldives'),
(138, 'Mali'),
(139, 'Malta'),
(140, 'Marshall Islands'),
(141, 'Martinique'),
(142, 'Mauritania'),
(143, 'Mauritius'),
(144, 'Mayotte'),
(145, 'Mexico'),
(146, 'Micronesia, Federated States of'),
(147, 'Moldova, Republic of'),
(148, 'Monaco'),
(149, 'Mongolia'),
(150, 'Montenegro'),
(151, 'Montserrat'),
(152, 'Morocco'),
(153, 'Mozambique'),
(154, 'Myanmar'),
(155, 'Namibia'),
(156, 'Nauru'),
(157, 'Nepal'),
(158, 'Netherlands'),
(159, 'Netherlands Antilles'),
(160, 'New Caledonia'),
(161, 'New Zealand'),
(162, 'Nicaragua'),
(163, 'Niger'),
(164, 'Nigeria'),
(165, 'Niue'),
(166, 'Norfolk Island'),
(167, 'Northern Mariana Islands'),
(168, 'Norway'),
(169, 'Oman'),
(170, 'Pakistan'),
(171, 'Palau'),
(172, 'Palestinian Territory, Occupied'),
(173, 'Panama'),
(174, 'Papua New Guinea'),
(175, 'Paraguay'),
(176, 'Peru'),
(177, 'Philippines'),
(178, 'Pitcairn'),
(179, 'Poland'),
(180, 'Portugal'),
(181, 'Puerto Rico'),
(182, 'Qatar'),
(183, 'Reunion'),
(184, 'Romania'),
(185, 'Russian Federation'),
(186, 'Rwanda'),
(187, 'Saint Barthelemy'),
(188, 'Saint Helena'),
(189, 'Saint Kitts and Nevis'),
(190, 'Saint Lucia'),
(191, 'Saint Martin'),
(192, 'Saint Pierre and Miquelon'),
(193, 'Saint Vincent and the Grenadines'),
(194, 'Samoa'),
(195, 'San Marino'),
(196, 'Sao Tome and Principe'),
(197, 'Saudi Arabia'),
(198, 'Senegal'),
(199, 'Serbia'),
(200, 'Serbia and Montenegro'),
(201, 'Seychelles'),
(202, 'Sierra Leone'),
(203, 'Singapore'),
(204, 'Sint Maarten'),
(205, 'Slovakia'),
(206, 'Slovenia'),
(207, 'Solomon Islands'),
(208, 'Somalia'),
(209, 'South Africa'),
(210, 'South Georgia and the South Sandwich Islands'),
(211, 'South Sudan'),
(212, 'Spain'),
(213, 'Sri Lanka'),
(214, 'Sudan'),
(215, 'Suriname'),
(216, 'Svalbard and Jan Mayen'),
(217, 'Swaziland'),
(218, 'Sweden'),
(219, 'Switzerland'),
(220, 'Syrian Arab Republic'),
(221, 'Taiwan, Province of China'),
(222, 'Tajikistan'),
(223, 'Tanzania, United Republic of'),
(224, 'Thailand'),
(225, 'Timor-Leste'),
(226, 'Togo'),
(227, 'Tokelau'),
(228, 'Tonga'),
(229, 'Trinidad and Tobago'),
(230, 'Tunisia'),
(231, 'Turkey'),
(232, 'Turkmenistan'),
(233, 'Turks and Caicos Islands'),
(234, 'Tuvalu'),
(235, 'Uganda'),
(236, 'Ukraine'),
(237, 'United Arab Emirates'),
(238, 'United Kingdom'),
(239, 'United States'),
(240, 'United States Minor Outlying Islands'),
(241, 'Uruguay'),
(242, 'Uzbekistan'),
(243, 'Vanuatu'),
(244, 'Venezuela'),
(245, 'Viet Nam'),
(246, 'Virgin Islands, British'),
(247, 'Virgin Islands, U.s.'),
(248, 'Wallis and Futuna'),
(249, 'Western Sahara'),
(250, 'Yemen'),
(251, 'Zambia'),
(252, 'Zimbabwe'),
(253, 'Desconocido');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `playlist`
--

CREATE TABLE `playlist` (
  `ID` int(11) NOT NULL,
  `Nombre` varchar(50) COLLATE utf8mb4_spanish_ci NOT NULL,
  `Descripcion` varchar(120) COLLATE utf8mb4_spanish_ci NOT NULL,
  `FKIDUsuario` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_spanish_ci;

--
-- Volcado de datos para la tabla `playlist`
--

INSERT INTO `playlist` (`ID`, `Nombre`, `Descripcion`, `FKIDUsuario`) VALUES
(1, 'Futbol pele', '', 9),
(2, 'BRASIL 2014', 'Uma lista para jogar a fuchibol', 9),
(3, 'mondongo', 'Ai se eu te pego (Assim voce me mata)', 9);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `usuarios`
--

CREATE TABLE `usuarios` (
  `ID` int(11) NOT NULL,
  `Correo` varchar(50) COLLATE utf8mb4_spanish_ci NOT NULL,
  `Contrasena` varchar(32) COLLATE utf8mb4_spanish_ci NOT NULL,
  `Nombre` varchar(50) COLLATE utf8mb4_spanish_ci NOT NULL,
  `Telefono` varchar(10) COLLATE utf8mb4_spanish_ci NOT NULL,
  `Administrador` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_spanish_ci;

--
-- Volcado de datos para la tabla `usuarios`
--

INSERT INTO `usuarios` (`ID`, `Correo`, `Contrasena`, `Nombre`, `Telefono`, `Administrador`) VALUES
(3, 'taytay@gmail.com', '1989', 'tay13', '123-123-12', 0),
(4, 'soyguapo@hotmail.com', 'feliz', 'cyberpunk', '104-104-10', 0),
(5, 'messi@argentina.com', 'perdon', 'rubius', '101-010-10', 0),
(6, 'admin@gmail.com', 'primero12', 'admin', '4494608373', 1),
(7, 'jose@gmail.com', 'nelson3', 'jose19', '4491881942', 1),
(8, 'dany@gmail.com', 'ronaldo7', 'dannytm', '4493465595', 1),
(9, 'reydopele@hotmail.com', 'peledos', 'pele', '123-123-12', 0);

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `album`
--
ALTER TABLE `album`
  ADD PRIMARY KEY (`ID`);

--
-- Indices de la tabla `artistas`
--
ALTER TABLE `artistas`
  ADD PRIMARY KEY (`ID`);

--
-- Indices de la tabla `artistasxcancion`
--
ALTER TABLE `artistasxcancion`
  ADD PRIMARY KEY (`ID`);

--
-- Indices de la tabla `canciones`
--
ALTER TABLE `canciones`
  ADD PRIMARY KEY (`ID`);

--
-- Indices de la tabla `cancionesxalbum`
--
ALTER TABLE `cancionesxalbum`
  ADD PRIMARY KEY (`ID`);

--
-- Indices de la tabla `cancionesxplaylist`
--
ALTER TABLE `cancionesxplaylist`
  ADD PRIMARY KEY (`ID`);

--
-- Indices de la tabla `pais`
--
ALTER TABLE `pais`
  ADD PRIMARY KEY (`ID`);

--
-- Indices de la tabla `playlist`
--
ALTER TABLE `playlist`
  ADD PRIMARY KEY (`ID`);

--
-- Indices de la tabla `usuarios`
--
ALTER TABLE `usuarios`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `album`
--
ALTER TABLE `album`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;

--
-- AUTO_INCREMENT de la tabla `artistas`
--
ALTER TABLE `artistas`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT de la tabla `artistasxcancion`
--
ALTER TABLE `artistasxcancion`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=23;

--
-- AUTO_INCREMENT de la tabla `canciones`
--
ALTER TABLE `canciones`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT de la tabla `cancionesxalbum`
--
ALTER TABLE `cancionesxalbum`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=31;

--
-- AUTO_INCREMENT de la tabla `cancionesxplaylist`
--
ALTER TABLE `cancionesxplaylist`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT de la tabla `pais`
--
ALTER TABLE `pais`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=254;

--
-- AUTO_INCREMENT de la tabla `playlist`
--
ALTER TABLE `playlist`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT de la tabla `usuarios`
--
ALTER TABLE `usuarios`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
