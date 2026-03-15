///////////////////////////////////////////////////////////////////////////
// Workfile : parser.h
// Author : Leander Kieweg
// Date : 07.03.2026
// Description : parser for Arithmetic Expression Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef PARSER_H
#define PARSER_H

#include "scanner.h"

// Parse an arithmetic expression from the scanner and return the calculated result
int ScanExpression(pfc::scanner& scan);

#endif
