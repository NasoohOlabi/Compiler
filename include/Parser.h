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
     INTEGER = 259,
     REAL = 260,
     BOOLEAN = 261,
     DD = 262,
     ASSIGN = 263,
     WHILE = 264,
     DO = 265,
     BEG = 266,
     END = 267,
     IF = 268,
     THEN = 269,
     ARRAY = 270,
     OF = 271,
     TRUE = 272,
     FALSE = 273,
     IDENT = 274,
     INT_NUM = 275,
     REAL_NUM = 276,
     BINARY_OPERATOR = 277,
     EXPRLST_PREC = 278,
     ELSE = 279,
     IF_PREC = 280,
     NOSUBDECS_PREC = 281,
     FUNCTION = 282,
     PROCEDURE = 283,
     SUBPROGRAMDEC_PREC = 284,
     SUBDECS_PREC = 285,
     NODECS_PREC = 286,
     VAR = 287,
     UNARY_PREC = 288,
     NOT = 289,
     EXPR_PREC = 290
   };
#endif
/* Tokens.  */
#define PROGRAM 258
#define INTEGER 259
#define REAL 260
#define BOOLEAN 261
#define DD 262
#define ASSIGN 263
#define WHILE 264
#define DO 265
#define BEG 266
#define END 267
#define IF 268
#define THEN 269
#define ARRAY 270
#define OF 271
#define TRUE 272
#define FALSE 273
#define IDENT 274
#define INT_NUM 275
#define REAL_NUM 276
#define BINARY_OPERATOR 277
#define EXPRLST_PREC 278
#define ELSE 279
#define IF_PREC 280
#define NOSUBDECS_PREC 281
#define FUNCTION 282
#define PROCEDURE 283
#define SUBPROGRAMDEC_PREC 284
#define SUBDECS_PREC 285
#define NODECS_PREC 286
#define VAR 287
#define UNARY_PREC 288
#define NOT 289
#define EXPR_PREC 290




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 16 "../Parser.y"
typedef union YYSTYPE {
	Ident *tIdent;
	Ident_List *tIdent_List;
	Int_Num *tInt_Num;
	Real_Num *tReal_Num;
	Standard_Type *tStandard_Type;
	Type *tType;
	Parameter *tParameter;
	Parameter_List *tParameter_List;
	Declaration *tDeclaration;
	Declarations *tDeclarations;
	Arguments *tArguments;
	Expression *tExpression;
	Int_Expression *tInt_Expression;
	Real_Expression *tReal_Expression;
	Boolean_Expression *tBoolean_Expression;
	Ident_Expression *tIdent_Expression;
	Expression_Expression *tExpression_Expression;
	Not_Expression *tNot_Expression;
	Expression_List *tExpression_List;
	Procedure_Statement *tProcedure_Statement;
	Statement *tStatement;
	Statement_List *tStatement_List;
	Optional_Statements *tOptional_Statements;
	Compound_Statement *tCompound_Statement;
	Variable *tVariable;
	Subprogram_Head *tSubprogram_Head;
	Subprogram_Declaration *tSubprogram_Declaration;
	Subprogram_Declarations *tSubprogram_Declarations;
	Program *tProgram;
	Add_expression *tAdd_expression;
	Minus_expression *tMinus_expression;
	Mul_expression *tMul_expression;
	Divide_expression *tDivide_expression;
	Binary_expression *tBinary_expression;
	Binary_opreator *tBinary_Opreator;
 } YYSTYPE;
/* Line 1447 of yacc.c.  */
#line 146 "../include/Parser.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



