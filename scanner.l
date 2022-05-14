%{
	#include "ast.h"
	#include "parser.h"
	extern int lin, col;
%}


/* Options */

%option noyywrap
%option caseless


/* Definitions */

digit 		[0-9]
alpha 		[a-z]
id      	[{alpha}_][{alpha}{digit}_]*
int_num 	0|([1-9]{digit}*)
real_num	(0|[1-9][0-9]*)"."[0-9]*([eE][-+]?(0|[1-9][0-9]*))?|"."[0-9]+([eE][-+]?(0|[1-9][0-9]*))?|(0|[1-9][0-9]*)([eE][-+]?(0|[1-9][0-9]*))
white_space [ /t/n]
opreators	[\[\]:;]


%%

\n {
	col = 1;
	lin += 1;
}

"program" {
	col += yyleng;
	return PROGRAM;
}


"var" {
	col += yyleng;
	return VAR;
}


"integer" {
	col += yyleng;
	return INTEGER;
}


"real" {
	col += yyleng;
	return REAL;
}


"boolean" {
	col += yyleng;
	return BOOLEAN;
}


"function" {
	col += yyleng;
	return FUNCTION;
}


"procedure" {
	col += yyleng;
	return PROCEDURE;
}


"while" {
	col += yyleng;
	return WHILE;
}


"do" {
	col += yyleng;
	return DO;
}


"begin" {
	col += yyleng;
	return BEG; // BEGIN IS A LEX RESERVED KEYWORD
}


"end" {
	col += yyleng;
	return END;
}


"if" {
	col += yyleng;
	return IF;
}


"then" {
	col += yyleng;
	return THEN;
}


"else" {
	col += yyleng;
	return ELSE;
}


"array" {
	col += yyleng;
	return ARRAY;
}


"of" {
	col += yyleng;
	return OF;
}


"div" {
	col += yyleng;
	return DIV;
}


"not" {
	col += yyleng;
	return NOT;
}


"or" {
	col += yyleng;
	return OR;
}


"and" {
	col += yyleng;
	return AND;
}

".." {
	col += yyleng;
	return DD;
}

{opreators} {
	col += yyleng;
	return *yytext;
}


{id} {
	col += yyleng;
	yylval.tIdent = new Ident(strdup(yytext), lin, col);
    return IDENT;
}

{int_num} {
	col += yyleng;
	yylval.tInt_Num = new Int_Num(atoi(yytext), lin, col);
    return INT_NUM;
}

{real_num} {
	col += yyleng;
	yylval.tReal_Num = new Real_Num(atof(yytext), lin, col);
    return REAL_NUM;
}


{white_space} {
	/* IGNORE */
}

. {}

%%