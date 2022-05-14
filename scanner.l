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


{id} {
	col += yyleng;
    //TODO: MAKE NODE ID
}

{int_num} {
	col += yyleng;
    return INT_NUM;
}

{real_num} {
	col += yyleng;
    return REAL_NUM;
}


{white_space} {
	/* IGNORE */
}

. {}

%%