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
     NUMBER = 258,
     IDENT = 259,
     IF = 260,
     PROCEDURE = 261,
     PROGRAM = 262,
     VAR = 263,
     INTEGER = 264,
     REAL = 265,
     TRUE = 266,
     FALSE = 267,
     LE = 268,
     SE = 269,
     EQ = 270,
     NQ = 271,
     NE = 272,
     BOOLEAN = 273,
     RETURN = 274,
     DECREMENT = 275,
     INCREMENT = 276,
     NUL = 277,
     FOR = 278,
     WHILE = 279,
     DOUBLE = 280,
     FUNCTION = 281,
     DO = 282,
     BEG = 283,
     END = 284,
     ARRAY = 285,
     DIV = 286,
     OF = 287,
     OR = 288,
     AND = 289,
     NOT = 290,
     ELSE = 291,
     IFPREC = 292,
     MINUS = 293
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define IDENT 259
#define IF 260
#define PROCEDURE 261
#define PROGRAM 262
#define VAR 263
#define INTEGER 264
#define REAL 265
#define TRUE 266
#define FALSE 267
#define LE 268
#define SE 269
#define EQ 270
#define NQ 271
#define NE 272
#define BOOLEAN 273
#define RETURN 274
#define DECREMENT 275
#define INCREMENT 276
#define NUL 277
#define FOR 278
#define WHILE 279
#define DOUBLE 280
#define FUNCTION 281
#define DO 282
#define BEG 283
#define END 284
#define ARRAY 285
#define DIV 286
#define OF 287
#define OR 288
#define AND 289
#define NOT 290
#define ELSE 291
#define IFPREC 292
#define MINUS 293




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



