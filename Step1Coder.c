/*
***********************************************************
* File name: Step1Coder.c
* Compiler: MS Visual Studio 2022
* Course: CST 8152 – Compilers, Lab Section: [011, 012, 013]
* Assignment: A1.
* Date: Sep 01 2025
* Professor: Paulo Sousa
* Purpose: This file is the main code for the Coder (A1)
************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef COMPILERS_H_
#include "Compilers.h"
#endif

#ifndef CODER_H_
#include "Step1Coder.h"
#endif

// Helper: transform a single character using Vigenère
static char transformChar(char c, char k, echo_intg encode) {
    if (c < ASCII_START || c > ASCII_END) return c; // leave unchanged
    int shift = (k - ASCII_START) % ASCII_RANGE;
    int offset = c - ASCII_START;
    int result;
    if (encode == CYPHER)
        result = (offset + shift) % ASCII_RANGE;
    else
        result = (offset - shift + ASCII_RANGE) % ASCII_RANGE;
    return (char)(result + ASCII_START);
}

// Function to perform the Vigenère cipher (encoding or decoding) on files
void vigenereFile(const echo_strg inputFileName,
    const echo_strg outputFileName,
    const echo_strg key,
    echo_intg encode) {
    if (!inputFileName || !outputFileName || !key) return;
    if (!(encode == CYPHER || encode == DECYPHER)) return;

    FILE* in = fopen(inputFileName, "rb");
    FILE* out = fopen(outputFileName, "wb");
    if (!in || !out) {
        if (in) fclose(in);
        if (out) fclose(out);
        return;
    }

    size_t keyLen = strlen(key);
    if (keyLen == 0) { fclose(in); fclose(out); return; }

    int ch, i = 0;
    while ((ch = fgetc(in)) != EOF) {
        char k = key[i % keyLen];
        char outCh = transformChar((char)ch, k, encode);
        fputc(outCh, out);
        if (ch >= ASCII_START && ch <= ASCII_END) i++;
    }

    fclose(in);
    fclose(out);
}

// Function to perform the Vigenère cipher (encoding or decoding) in memory
echo_strg vigenereMem(const echo_strg inputFileName,
    const echo_strg key,
    echo_intg encode) {
    if (!inputFileName || !key) return NULL;
    if (!(encode == CYPHER || encode == DECYPHER)) return NULL;

    int size = getSizeOfFile(inputFileName);
    if (size <= 0) return NULL;

    FILE* in = fopen(inputFileName, "rb");
    if (!in) return NULL;

    echo_strg output = (echo_strg)malloc(size + 1);
    if (!output) { fclose(in); return NULL; }

    size_t keyLen = strlen(key);
    if (keyLen == 0) { fclose(in); free(output); return NULL; }

    int ch, i = 0, pos = 0;
    while ((ch = fgetc(in)) != EOF) {
        char k = key[i % keyLen];
        output[pos++] = transformChar((char)ch, k, encode);
        if (ch >= ASCII_START && ch <= ASCII_END) i++;
    }
    output[pos] = '\0';

    fclose(in);
    return output;
}

// Function to encode (cypher)
void cypher(const echo_strg inputFileName,
    const echo_strg outputFileName,
    const echo_strg key) {
    vigenereFile(inputFileName, outputFileName, key, CYPHER);
}

// Function to decode (decypher)
void decypher(const echo_strg inputFileName,
    const echo_strg outputFileName,
    const echo_strg key) {
    vigenereFile(inputFileName, outputFileName, key, DECYPHER);
}

// Get file size (utility method)
echo_intg getSizeOfFile(const echo_strg filename) {
    if (!filename) return -1;
    FILE* fp = fopen(filename, "rb");
    if (!fp) return -1;
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fclose(fp);
    return (echo_intg)size;
}
