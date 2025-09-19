/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Fall, 2025
* Author: TO_DO
* Professors: Paulo Sousa
************************************************************
#
# ECHO "=---------------------------------------="
# ECHO "|  COMPILERS - ALGONQUIN COLLEGE (F25)  |"
# ECHO "=---------------------------------------="
# ECHO "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    ”
# ECHO "    @@                             @@    ”
# ECHO "    @@           %&@@@@@@@@@@@     @@    ”
# ECHO "    @@       @%% (@@@@@@@@@  @     @@    ”
# ECHO "    @@      @& @   @ @       @     @@    ”
# ECHO "    @@     @ @ %  / /   @@@@@@     @@    ”
# ECHO "    @@      & @ @  @@              @@    ”
# ECHO "    @@       @/ @*@ @ @   @        @@    ”
# ECHO "    @@           @@@@  @@ @ @      @@    ”
# ECHO "    @@            /@@    @@@ @     @@    ”
# ECHO "    @@     @      / /     @@ @     @@    ”
# ECHO "    @@     @ @@   /@/   @@@ @      @@    ”
# ECHO "    @@     @@@@@@@@@@@@@@@         @@    ”
# ECHO "    @@                             @@    ”
# ECHO "    @@          E C H O            @@    ”
# ECHO "    @@                             @@    ”
# ECHO "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    ”
# ECHO "                                         "
# ECHO "[COMPILER SCRIPT .......................]"
# ECHO "                                         "
*/

/*
************************************************************
* File name: Compilers.h
* Compiler: MS Visual Studio 2022
* Course: CST 8152 – Compilers, Lab Section: [011, 012]
* Assignment: A1-A5.
* Date: Sep 01 2025
* Professor: Paulo Sousa
* Purpose: This file defines the functions called by main function.
* Function list: mainReader(), mainScanner(), mainParser().
*************************************************************/

#ifndef COMPILERS_H_
#define COMPILERS_H_

#define DEBUG 0

/* Language name */
#define STR_LANGNAME    "Echo"

/* Logical constants - adapt for your language */
#define ECHO_TRUE   1
#define ECHO_FALSE  0

#define INVALID NULL
#define EOF_CHAR '\0'

/*
------------------------------------------------------------
Data types definitions
------------------------------------------------------------
*/
typedef char            echo_char;
typedef char* echo_strg;
typedef int             echo_intg;
typedef float           echo_real;
typedef void            echo_void;

typedef unsigned char   echo_boln;
typedef unsigned char   echo_byte;

typedef long            echo_long;
typedef double          echo_doub;

/*
------------------------------------------------------------
Programs:
------------------------------------------------------------
*/
enum PROGRAMS {
    PGM_CDR = '1', // Coder:    05pt
    PGM_RDR = '2', // Reader:   05pt
    PGM_SCN = '3', // Scanner:  15pt
    PGM_PSR = '4', // Parser:   15pt
    PGM_WRT = '5', // Writer:   10pt
};

/*
------------------------------------------------------------
Main functions signatures
------------------------------------------------------------
*/
echo_intg main1Coder(echo_intg argc, echo_strg* argv);

echo_void printLogo();
echo_void errorPrint(echo_strg fmt, ...);

#endif

/*
      "args": [
        1,
        1,
        "README.txt",
        "CODED.txt"
      ]
      "args": [
        4,
        "CODED.txt"
      ]
*/
