-- phpMyAdmin SQL Dump
-- version 4.0.10deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Czas wygenerowania: 14 Cze 2016, 17:27
-- Wersja serwera: 5.5.49-0ubuntu0.14.04.1
-- Wersja PHP: 5.5.9-1ubuntu4.16

SET FOREIGN_KEY_CHECKS=0;
SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Baza danych: `Serwis`
--
CREATE DATABASE IF NOT EXISTS `Serwis` DEFAULT CHARACTER SET utf8 COLLATE utf8_polish_ci;
USE `Serwis`;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `AuthorsOfCourses`
--
-- Data utworzenia: 13 Cze 2016, 21:10
--

DROP TABLE IF EXISTS `AuthorsOfCourses`;
CREATE TABLE IF NOT EXISTS `AuthorsOfCourses` (
  `AuthorID` int(11) NOT NULL,
  `CourseID` int(11) NOT NULL,
  KEY `AuthorID` (`AuthorID`),
  KEY `CourseID` (`CourseID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELACJE TABELI `AuthorsOfCourses`:
--   `CourseID`
--       `Courses` -> `ID`
--   `AuthorID`
--       `Users` -> `ID`
--

--
-- Zrzut danych tabeli `AuthorsOfCourses`
--

INSERT INTO `AuthorsOfCourses` (`AuthorID`, `CourseID`) VALUES
(4, 1),
(4, 2),
(4, 3),
(5, 4);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `AvailableCourses`
--
-- Data utworzenia: 13 Cze 2016, 21:10
--

DROP TABLE IF EXISTS `AvailableCourses`;
CREATE TABLE IF NOT EXISTS `AvailableCourses` (
  `UserID` int(11) NOT NULL,
  `CourseID` int(11) NOT NULL,
  KEY `UserID` (`UserID`),
  KEY `CourseID` (`CourseID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELACJE TABELI `AvailableCourses`:
--   `CourseID`
--       `Courses` -> `ID`
--   `UserID`
--       `Users` -> `ID`
--

--
-- Zrzut danych tabeli `AvailableCourses`
--

INSERT INTO `AvailableCourses` (`UserID`, `CourseID`) VALUES
(1, 1),
(1, 2),
(1, 3),
(1, 4),
(2, 1),
(2, 2),
(2, 3),
(2, 4),
(3, 1),
(3, 2),
(4, 1),
(4, 2),
(4, 3),
(5, 4);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `Courses`
--
-- Data utworzenia: 13 Cze 2016, 21:10
--

DROP TABLE IF EXISTS `Courses`;
CREATE TABLE IF NOT EXISTS `Courses` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `Name` varchar(50) NOT NULL,
  `Level` int(11) NOT NULL,
  `IsFree` tinyint(1) NOT NULL,
  `Price` float NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=5 ;

--
-- Zrzut danych tabeli `Courses`
--

INSERT INTO `Courses` (`ID`, `Name`, `Level`, `IsFree`, `Price`) VALUES
(1, 'Techniki Programowania', 3, 0, 20.99),
(2, 'Jak nie umrzec na studiach', 999, 1, 0),
(3, 'Modelowanie biznesowe', 20, 0, 30.99),
(4, 'Hurr lol', 20, 1, 0);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `Users`
--
-- Data utworzenia: 13 Cze 2016, 21:10
--

DROP TABLE IF EXISTS `Users`;
CREATE TABLE IF NOT EXISTS `Users` (
  `ID` int(10) NOT NULL AUTO_INCREMENT,
  `Login` varchar(50) NOT NULL,
  `Password` varchar(50) NOT NULL,
  `Name` varchar(50) NOT NULL,
  `Surname` varchar(50) NOT NULL,
  `Type` int(10) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=7 ;

--
-- Zrzut danych tabeli `Users`
--

INSERT INTO `Users` (`ID`, `Login`, `Password`, `Name`, `Surname`, `Type`) VALUES
(1, 'Jerzy', '*B66A10847C429C9070E5B7176C20E5D8DBA65A35', 'Jerzy', 'Watrobka', 0),
(2, 'Jarek', '*BAC37AC9A1554858B175D08335BD66CE44104CC4', 'Jarek', 'Urbaniuk', 0),
(3, 'Janusz', '*83F00B4831C75BCC854940287F8954C42FC57DFF', 'Darek', 'Trymboniuk', 2),
(4, 'Student', '*73CF1E1EACB66A606AB2F492A1F406825A17EB2A', 'Jan', 'Kowalski', 1),
(5, 'hurr', '*74CB7E314342BF90F1A3DB285DB35531797C5463', 'Janusz', 'Zbigniewski', 1);

--
-- Ograniczenia dla zrzutów tabel
--

--
-- Ograniczenia dla tabeli `AuthorsOfCourses`
--
ALTER TABLE `AuthorsOfCourses`
  ADD CONSTRAINT `AuthorsOfCourses_ibfk_2` FOREIGN KEY (`CourseID`) REFERENCES `Courses` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `AuthorsOfCourses_ibfk_1` FOREIGN KEY (`AuthorID`) REFERENCES `Users` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Ograniczenia dla tabeli `AvailableCourses`
--
ALTER TABLE `AvailableCourses`
  ADD CONSTRAINT `AvailableCourses_ibfk_2` FOREIGN KEY (`CourseID`) REFERENCES `Courses` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `AvailableCourses_ibfk_1` FOREIGN KEY (`UserID`) REFERENCES `Users` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;
SET FOREIGN_KEY_CHECKS=1;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
