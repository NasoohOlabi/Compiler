%{
	#include "ast.h"
	#include "parser.h"
	#include<iostream>
	#include<string>
	using std::cout;
	using std::endl;
	int line=1;
	int col=1;
	int no_error=1;
	extern int yylex();
	extern int yyerror(const char *);
%}

%option caseless
%option noyywrap
%x comment

%}


/* Options */

%option noyywrap
%option caseless


/* Definitions */


Digit 		[0-9]
Alpha 		[a-z]
Id      	[{Alpha}_][{Alpha}{Digit}_]*
Int_Num 	0|([1-9]{Digit}*)
Real_Num	(0|[1-9][0-9]*)"."[0-9]*([eE][-+]?(0|[1-9][0-9]*))?|"."[0-9]+([eE][-+]?(0|[1-9][0-9]*))?|(0|[1-9][0-9]*)([eE][-+]?(0|[1-9][0-9]*))

%%

\n 					{
						col = 1;
						lin++;
					}

Id 					{
						cout << "Id:\n" << yytext;
					}	

Int_Num 					{
						cout << "Int_Num:\n" << yytext;
}

Real_Num 					{
						cout << "Real_Num:\n" << yytext;
}

"int"      return INT;



ordinary [-+=<>@\*\/;%~^:&,\|\[\]\(\)\{\}]
white_space [ /t/n]

alpha [a-z]|[A-Z]

int_num 0|[1-9][0-9]*


%%
"/*"					BEGIN(comment); col += yyleng;
<comment>[^*\n]*		col += yyleng;
<comment>"*"+[^*/\n]*	col += yyleng;
<comment>\n				lin++; col = 1;
<comment>"*"+"/"		BEGIN(0); col += yyleng;

"//".*\n				lin++; col = 1;

									
0|[1-9][0-9]*		{
						col += yyleng;
					}
					
(0|[1-9][0-9]*)"."[0-9]*([eE][-+]?(0|[1-9][0-9]*))?|"."[0-9]+([eE][-+]?(0|[1-9][0-9]*))?|(0|[1-9][0-9]*)([eE][-+]?(0|[1-9][0-9]*))
													{
														col += yyleng;
													}


"program" {
            col += yyleng;
            // cout<<yytext<<" PROGRAM "<<line<<" "<<col<<endl;
			return PROGRAM;
            }


"var" {
            col += yyleng;
            // cout<<yytext<<" VAR "<<line<<" "<<col<<endl;
			return VAR;
            }


"integer" {
            col += yyleng;
            // cout<<yytext<<" INTEGER "<<line<<" "<<col<<endl;
			return INTEGER;
            }


"real" {
            col += yyleng;
            // cout<<yytext<<" REAL "<<line<<" "<<col<<endl;
			return REAL;
            }


"function" {
            col += yyleng;
            // cout<<yytext<<" FUNCTION "<<line<<" "<<col<<endl;
			return FUNCTION;
            }


"procedure" {
            col += yyleng;
            // cout<<yytext<<" PROCEDURE "<<line<<" "<<col<<endl;
			return PROCEDURE;
            }


"while" {
            col += yyleng;
            // cout<<yytext<<" WHILE "<<line<<" "<<col<<endl;
			return WHILE;
            }


"do" {
            col += yyleng;
            // cout<<yytext<<" DO "<<line<<" "<<col<<endl;
			return DO;
            }


"begin" {
            col += yyleng;
            // cout<<yytext<<" BEGIN "<<line<<" "<<col<<endl;
			return BEGIN;
            }


"end" {
            col += yyleng;
            // cout<<yytext<<" END "<<line<<" "<<col<<endl;
			return END;
            }


"if" {
            col += yyleng;
            // cout<<yytext<<" IF "<<line<<" "<<col<<endl;
			return IF;
            }


"then" {
            col += yyleng;
            // cout<<yytext<<" THEN "<<line<<" "<<col<<endl;
			return THEN;
            }


"else" {
            col += yyleng;
            // cout<<yytext<<" ELSE "<<line<<" "<<col<<endl;
			return ELSE;
            }


"array" {
            col += yyleng;
            // cout<<yytext<<" ARRAY "<<line<<" "<<col<<endl;
			return ARRAY;
            }


"of" {
            col += yyleng;
            // cout<<yytext<<" OF "<<line<<" "<<col<<endl;
			return OF;
            }


"div" {
            col += yyleng;
            // cout<<yytext<<" DIV "<<line<<" "<<col<<endl;
			return DIV;
            }


"not" {
            col += yyleng;
            // cout<<yytext<<" NOT "<<line<<" "<<col<<endl;
			return NOT;
            }


"or" {
            col += yyleng;
            // cout<<yytext<<" OR "<<line<<" "<<col<<endl;
			return OR;
            }


"and" {
            col += yyleng;
            // cout<<yytext<<" AND "<<line<<" "<<col<<endl;
			return AND;
            }

white_space       /* IGNORE */
%%

