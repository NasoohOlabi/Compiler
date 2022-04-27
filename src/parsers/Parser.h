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
     IDENT = 258,
     IF = 259,
     PROCEDURE = 260,
     PROGRAM = 261,
     VAR = 262,
     INTEGER = 263,
     REAL = 264,
     TRUE = 265,
     FALSE = 266,
     LE = 267,
     SE = 268,
     EQ = 269,
     NQ = 270,
     NE = 271,
     BOOLEAN = 272,
     RETURN = 273,
     DECREMENT = 274,
     INCREMENT = 275,
     NUL = 276,
     FOR = 277,
     WHILE = 278,
     DOUBLE = 279,
     FUNCTION = 280,
     DO = 281,
     BEG = 282,
     END = 283,
     ARRAY = 284,
     DIV = 285,
     OF = 286,
     OR = 287,
     AND = 288,
     NOT = 289,
     INTEGER_LITERAL = 290,
     REAL_LITERAL = 291,
     ELSE = 292,
     IFPREC = 293,
     MINUS = 294
   };
#endif
/* Tokens.  */
#define IDENT 258
#define IF 259
#define PROCEDURE 260
#define PROGRAM 261
#define VAR 262
#define INTEGER 263
#define REAL 264
#define TRUE 265
#define FALSE 266
#define LE 267
#define SE 268
#define EQ 269
#define NQ 270
#define NE 271
#define BOOLEAN 272
#define RETURN 273
#define DECREMENT 274
#define INCREMENT 275
#define NUL 276
#define FOR 277
#define WHILE 278
#define DOUBLE 279
#define FUNCTION 280
#define DO 281
#define BEG 282
#define END 283
#define ARRAY 284
#define DIV 285
#define OF 286
#define OR 287
#define AND 288
#define NOT 289
#define INTEGER_LITERAL 290
#define REAL_LITERAL 291
#define ELSE 292
#define IFPREC 293
#define MINUS 294




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



