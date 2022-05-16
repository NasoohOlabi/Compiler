/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM = 258,
     VAR = 259,
     INTEGER = 260,
     REAL = 261,
     BOOLEAN = 262,
     FUNCTION = 263,
     PROCEDURE = 264,
     DD = 265,
     WHILE = 266,
     DO = 267,
     BEG = 268,
     END = 269,
     IF = 270,
     THEN = 271,
     ELSE = 272,
     ARRAY = 273,
     OF = 274,
     IDENT = 275,
     INT_NUM = 276,
     REAL_NUM = 277,
     UNARY_OPERATOR = 278
   };
#endif
/* Tokens.  */
#define PROGRAM 258
#define VAR 259
#define INTEGER 260
#define REAL 261
#define BOOLEAN 262
#define FUNCTION 263
#define PROCEDURE 264
#define DD 265
#define WHILE 266
#define DO 267
#define BEG 268
#define END 269
#define IF 270
#define THEN 271
#define ELSE 272
#define ARRAY 273
#define OF 274
#define IDENT 275
#define INT_NUM 276
#define REAL_NUM 277
#define UNARY_OPERATOR 278




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 18 "../Parser.y"
typedef union YYSTYPE {
	Ident *tIdent;
	Ident_List *tIdent_List;
	Int_Num *tInt_Num;
	Real_Num *tReal_Num;
	Unary_Operator *tUnary_Operator;
	Standard_Type *tStandard_Type;
	Type *tType;
	Parameter *tParameter;
	Parameter_List *tParameter_List;
	Declaration *tDeclaration;
	Declarations *tDeclarations;
	Arguments *tArguments;
} YYSTYPE;
/* Line 1447 of yacc.c.  */
#line 99 "../include/Parser.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



