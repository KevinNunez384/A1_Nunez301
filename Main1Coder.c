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
# ECHO "[CODER SCRIPT ..........................]"
# ECHO "                                         "
*/

/*
************************************************************
* File name: Main1Coder.c
* Compiler: MS Visual Studio 2022
* Course: CST 8152 – Compilers, Lab Section: [011, 012]
* Assignment: A1.
* Date: Sep 01 2025
* Professor: Paulo Sousa
* Purpose: This file is the main code for the Coder (A1)
************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef COMPILERS_H_
#include "Compilers.h"
#endif

#ifndef CODER_H_
#include "Step1Coder.h"
#endif

/* Check for ANSI C compliancy */
#define ANSI_C 0
#if defined(__STDC__)
#undef ANSI_C
#define ANSI_C 1
#endif

/*
************************************************************
* Coder starting method
* Params:
*   - Mode: Cypher/decypher
*   - Input: Filename
*   - Key: Encrypt word (default = STR_LANGNAME)
*   - Output: Filename
************************************************************
*/

echo_intg main1Coder(echo_intg argc, echo_strg* argv) {
    if (argc < 5) {
        printf("Usage: %s [1=cypher | 0=decypher] <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    echo_strg operation = argv[2];
    echo_strg inputFileName = argv[3];
    echo_strg outputFileName = argv[4];
    echo_strg key = STR_LANGNAME; /* default key is your language name */

    int op = atoi(operation);
    if (op == CYPHER) {
        cypher(inputFileName, outputFileName, key);
    }
    else if (op == DECYPHER) {
        decypher(inputFileName, outputFileName, key);
    }
    else {
        errorPrint("Error: Unknown operation %s. Use 1 for cypher or 0 for decypher.\n", operation);
        return EXIT_FAILURE;
    }

    printf("Operation '%s' completed successfully.\n", operation);

    /* Demonstrate in-memory reverse operation */
    echo_strg output = NULL;
    if (op == CYPHER) {
        output = vigenereMem(outputFileName, key, DECYPHER);
    }
    else {
        output = vigenereMem(outputFileName, key, CYPHER);
    }

    if (output) {
        printf("OUTPUT:\n%s\n", output);
        free(output); /* free memory allocated by vigenereMem */
    }

    return EXIT_SUCCESS;
}
