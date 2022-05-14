%{
	#include "ast.h"
	#include "parser.h"
	extern int lin, col;
%}


/* Options */

%option noyywrap
%option caseless


/* Definitions */

int_num 0|[1-9][0-9]*


%%

int_num {
    return (NUM);
}


%%