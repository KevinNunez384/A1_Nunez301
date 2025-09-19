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
* File name: Compilers.c
* Compiler: MS Visual Studio 2022
* Course: CST 8152 – Compilers, Lab Section: [011, 012]
* Assignment: A1, A2, A3.
* Date: Sep 01 2025
* Professor: Paulo Sousa
* Purpose: This file is the main program of Compilers Project
* Function list: main().
************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

#ifndef COMPILERS_H_
#include "Compilers.h"
#endif

/*
***********************************************************
* Function name: main
* Purpose: Main function
* Author: Paulo Sousa
* History/Versions: Ver F25
* Called functions: main1Coder(), mainReader(), mainScanner(), mainParser()
* Parameters: Command line arguments - argc, argv
* Return value: Status
*************************************************************
*/

echo_intg main(int argc, char** argv) {

    echo_intg i;
    printLogo();
    if (DEBUG) {
        for (i = 0; i < argc; ++i)
            printf("argv[%d] = %s\n", i, argv[i]);
    }
    if (argc < 2) {
        printf("%s%c%s%c%s%c%s%c%s%c%s", "OPTIONS:\n* [",
            PGM_CDR, "] - Coder\n* [",
            PGM_RDR, "] - Reader\n* [",
            PGM_SCN, "] - Scanner\n* [",
            PGM_PSR, "] - Parser\n* [",
            PGM_WRT, "] - Writer\n");
        return EXIT_FAILURE;
    }
    echo_char option = argv[1][0];
    switch (option) {
    case PGM_CDR:
        printf("%s%c%s", "\n[Option '", PGM_CDR, "': Starting CODER .....]\n\n");
        main1Coder(argc, argv);
        break;
    default:
        printf("%s%c%s%c%s%c%s%c%s%c%s", "OPTIONS:\n* [",
            PGM_CDR, "] - Coder\n* [",
            PGM_RDR, "] - Reader\n* [",
            PGM_SCN, "] - Scanner\n* [",
            PGM_PSR, "] - Parser\n* [",
            PGM_WRT, "] - Writer\n");
        break;
    }
    return EXIT_SUCCESS;
}

/*
***********************************************************
* Function name: printLogo
* Purpose: Print Logo
* Author: Paulo Sousa
* History/Versions: Ver F25
* Called functions: -
* Parameters: -
* Return value: (Null)
*************************************************************
*/

echo_void printLogo() {
    printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
        "\t=---------------------------------------=\n",
        "\t|  COMPILERS - ALGONQUIN COLLEGE (S25)  |\n",
        "\t=---------------------------------------=\n",
        "\t    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    \n",
        "\t    @@                             @@    \n",
        "\t    @@           %&@@@@@@@@@@@     @@    \n",
        "\t    @@       @%% (@@@@@@@@@  @     @@    \n",
        "\t    @@      @& @   @ @       @     @@    \n",
        "\t    @@     @ @ %  / /   @@@@@@     @@    \n",
        "\t    @@      & @ @  @@              @@    \n",
        "\t    @@       @/ @*@ @ @   @        @@    \n",
        "\t    @@           @@@@  @@ @ @      @@    \n",
        "\t    @@            /@@    @@@ @     @@    \n",
        "\t    @@     @      / /     @@ @     @@    \n",
        "\t    @@     @ @@   /@/   @@@ @      @@    \n",
        "\t    @@     @@@@@@@@@@@@@@@         @@    \n",
        "\t    @@                             @@    \n",
        "\t    @@          E C H O            @@    \n",
        "\t    @@                             @@    \n",
        "\t    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    \n",
        "\t                                         \n",
        "\t[COMPILER SCRIPT .......................]\n",
        "\t                                         \n"
    );
}

/*
************************************************************
* Error printing function with variable number of arguments
* Params: Variable arguments, using formats from C language.
************************************************************
*/

echo_void errorPrint(echo_strg fmt, ...) {
    va_list ap;
    va_start(ap, fmt);

    (echo_void)vfprintf(stderr, fmt, ap);
    va_end(ap);

    if (strchr(fmt, '\n') == NULL)
        fprintf(stderr, "\n");
}
