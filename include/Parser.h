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
     NUM = 259,
     INT = 260,
     PROGRAM = 261,
     VAR = 262,
     INTEGER = 263,
     REAL = 264,
     FUNCTION = 265,
     PROCEDURE = 266,
     WHILE = 267,
     DO = 268,
     KBEGIN = 269,
     END = 270,
     IF = 271,
     THEN = 272,
     ELSE = 273,
     ARRAY = 274,
     OF = 275,
     DIV = 276,
     NOT = 277,
     OR = 278,
     AND = 279
   };
#endif
/* Tokens.  */
#define IDENT 258
#define NUM 259
#define INT 260
#define PROGRAM 261
#define VAR 262
#define INTEGER 263
#define REAL 264
#define FUNCTION 265
#define PROCEDURE 266
#define WHILE 267
#define DO 268
#define KBEGIN 269
#define END 270
#define IF 271
#define THEN 272
#define ELSE 273
#define ARRAY 274
#define OF 275
#define DIV 276
#define NOT 277
#define OR 278
#define AND 279




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 17 "../Parser.y"
typedef union YYSTYPE {
		Func *tFunc;
		Args *tArgs;
		Arg *tArg;
		int tInt;
		Expr *tExpr;
		Stmts *tStmts;
		Stmt *tStmt;
		Num *tNum;
		Ident *tIdent;
		Program *tProgram;
		Var *tVar;
		Integer *tInteger;
		Real *tReal;
		Function *tFunction;
		Procedure *tProcedure;
		While *tWhile;
		Do *tDo;
		KBegin *tBegin;
		End *tEnd;
		If *tIf;
		Then *tThen;
		Else *tElse;
		Array *tArray;
		Of *tOf;
		Div *tDiv;
		Not *tNot;
		Or *tOr;
		And *tAnd;
} YYSTYPE;
/* Line 1447 of yacc.c.  */
#line 117 "../include/Parser.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



