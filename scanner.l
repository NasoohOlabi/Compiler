
%{
	#include "stdio.h"
	
	#include <iostream>
	#include "Parser.h"
	using std::cout;	
	using std::endl;
	using std::left;
	
	// #include "ast.h"
	
	#define YY_INPUT(buf,result,max_size) \
    { \
    int c = getchar(); \
    result = (c == EOF) ? YY_NULL : (buf[0] = c, 1); \
    }\

	
	
	int lin = 1, col = 1, errorno = 0;
%}
%option noyywrap
%option caseless

%x comment
REAL1	(0|[1-9][0-9]*)"."[0-9]*([eE][-+]?(0|[1-9][0-9]*))?
REAL2	"."[0-9]+([eE][-+]?(0|[1-9][0-9]*))?
REAL3	(0|[1-9][0-9]*)([eE][-+]?(0|[1-9][0-9]*))
%%
"/*"					BEGIN(comment); col += yyleng;
<comment>[^*\n]*		col += yyleng;
<comment>"*"+[^*/\n]*	col += yyleng;
<comment>\n				lin++; col = 1;
<comment>"*"+"/"		BEGIN(0); col += yyleng;

"//".*\n				lin++; col = 1;

"program"				{
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
"do" {
	col += yyleng;
	return DO;
}
"begin" {
	col += yyleng;
	return BEG;
}
"end" {
	col += yyleng;
	return END;
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
"and" {
	col += yyleng;
	return AND;
}
"or" {
	col += yyleng;
	return OR;
}
"boolean"			{						
						col += yyleng;
						return BOOLEAN;
					}
"double"			{
						col += yyleng;
						return DOUBLE;
					}
"if"				{
						col += yyleng;
						return IF;
					}
"else"				{
						col += yyleng;
						return ELSE;
					}
"while"				{
						col += yyleng;
						return WHILE;
					}
"for"				{
						col += yyleng;
						return FOR;
					}
"false"				{
						col += yyleng;
						return FALSE;
					}
"true"				{
						col += yyleng;
						return TRUE;
					}
"null"				{
						col += yyleng;
						return NUL;
					}
"return"			{
						col += yyleng;
						return RETURN;
					}
"++"				{
						col += yyleng;
						return INCREMENT;
					}
"--"				{
						col += yyleng;
						return DECREMENT;
					}
">="				{
						col += yyleng;
						return LE;
					}
"<="				{						
						col += yyleng;
						return SE;
					}
"=="				{
						col += yyleng;
						return EQ;
					}
"!="				{
						col += yyleng;
						return NE;
					}
"&&"				{
						col += yyleng;
						return AND;
					}
"||"				{
						col += yyleng;
						return OR;
					}
			
									
0|[1-9][0-9]*		{
						col += yyleng;
						
						return INTEGER;
					}
					
(0|[1-9][0-9]*)"."[0-9]*([eE][-+]?(0|[1-9][0-9]*))? |
"."[0-9]+([eE][-+]?(0|[1-9][0-9]*))?				|
(0|[1-9][0-9]*)([eE][-+]?(0|[1-9][0-9]*))			{
														col += yyleng;
														
														return REAL;
													}
([a-zA-Z]|_)([a-zA-Z]|[0-9]|_)*	{
									col += yyleng;
									
									return IDENT;
								}
[\t]*				col += 4 * yyleng;
[ ]*				col += yyleng;
\n					lin++; col = 1;
[+*/%<>={}().;,-<>]		return *yytext;
.					{
						col += yyleng;
						errorno++;
					}
%%

  