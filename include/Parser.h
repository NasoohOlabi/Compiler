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
     WHILE = 265,
     DO = 266,
     BEG = 267,
     END = 268,
     IF = 269,
     THEN = 270,
     ELSE = 271,
     ARRAY = 272,
     OF = 273,
     DIV = 274,
     NOT = 275,
     OR = 276,
     AND = 277,
     IDENT = 278,
     INT_NUM = 279,
     REAL_NUM = 280
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
#define WHILE 265
#define DO 266
#define BEG 267
#define END 268
#define IF 269
#define THEN 270
#define ELSE 271
#define ARRAY 272
#define OF 273
#define DIV 274
#define NOT 275
#define OR 276
#define AND 277
#define IDENT 278
#define INT_NUM 279
#define REAL_NUM 280




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 17 "../Parser.y"
typedef union YYSTYPE {
	Ident *tIdent;
	Ident_List *tIdent_List;
	Int_Num *tInt_Num;
	Real_Num *tReal_Num;
} YYSTYPE;
/* Line 1447 of yacc.c.  */
#line 95 "../include/Parser.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



