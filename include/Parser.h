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
     RET = 264,
     ENDWHILE = 265,
     WHILE = 266,
     DO = 267,
     BEG = 268,
     END = 269,
     IF = 270,
     THEN = 271,
     ARRAY = 272,
     OF = 273,
     TRUE = 274,
     FALSE = 275,
     ENDIF = 276,
     IDENT = 277,
     INT_NUM = 278,
     REAL_NUM = 279,
     LOGICAL_OPERATOR = 280,
     BINARY_OPERATOR = 281,
     EXPRLST_PREC = 282,
     IF_PREC = 283,
     ELSE = 284,
     WHILE_PREC = 285,
     NOSUBDECS_PREC = 286,
     FUNCTION = 287,
     PROCEDURE = 288,
     SUBPROGRAMDEC_PREC = 289,
     SUBDECS_PREC = 290,
     NODECS_PREC = 291,
     VAR = 292,
     UNARY_PREC = 293,
     NOT = 294,
     EXPR_PREC = 295
   };
#endif
/* Tokens.  */
#define PROGRAM 258
#define INTEGER 259
#define REAL 260
#define BOOLEAN 261
#define DD 262
#define ASSIGN 263
#define RET 264
#define ENDWHILE 265
#define WHILE 266
#define DO 267
#define BEG 268
#define END 269
#define IF 270
#define THEN 271
#define ARRAY 272
#define OF 273
#define TRUE 274
#define FALSE 275
#define ENDIF 276
#define IDENT 277
#define INT_NUM 278
#define REAL_NUM 279
#define LOGICAL_OPERATOR 280
#define BINARY_OPERATOR 281
#define EXPRLST_PREC 282
#define IF_PREC 283
#define ELSE 284
#define WHILE_PREC 285
#define NOSUBDECS_PREC 286
#define FUNCTION 287
#define PROCEDURE 288
#define SUBPROGRAMDEC_PREC 289
#define SUBDECS_PREC 290
#define NODECS_PREC 291
#define VAR 292
#define UNARY_PREC 293
#define NOT 294
#define EXPR_PREC 295




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 21 "../Parser.y"
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
	Local_Declaration *tLocal_Declaration;
	Local_Declarations *tLocal_Declarations;
	Arguments *tArguments;
	Expression *tExpression;
	Int_Expression *tInt_Expression;
	Real_Expression *tReal_Expression;
	Boolean_Expression *tBoolean_Expression;
	Function_Expression *tFunction_Expression;
	Ident_Expression *tIdent_Expression;
	Expression_Expression *tExpression_Expression;
	Not_Expression *tNot_Expression;
	Expression_List *tExpression_List;
	Procedure_Statement *tProcedure_Statement;
	Statement *tStatement;
	Statement_List *tStatement_List;
	Optional_Statements *tOptional_Statements;
	Compound_Statement *tCompound_Statement;
	Return_Statement *tReturn_Statement;
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
	Logical_expression *tLogical_expression;
	Array_expression *tArray_expression;
	Binary_opreator *tBinary_Opreator;
	Logical_opreator *tLogical_Opreator;
 } YYSTYPE;
/* Line 1447 of yacc.c.  */
#line 163 "../include/Parser.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



