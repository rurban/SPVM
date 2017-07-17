/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_SPVM_YY_SPVM_YACC_TAB_H_INCLUDED
# define YY_SPVM_YY_SPVM_YACC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int SPVM_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MY = 258,
    HAS = 259,
    SUB = 260,
    PACKAGE = 261,
    IF = 262,
    ELSIF = 263,
    ELSE = 264,
    RETURN = 265,
    FOR = 266,
    WHILE = 267,
    USE = 268,
    MALLOC = 269,
    LAST = 270,
    NEXT = 271,
    NAME = 272,
    VAR = 273,
    CONSTANT = 274,
    ENUM = 275,
    DESCRIPTOR = 276,
    CORETYPE = 277,
    UNDEF = 278,
    DIE = 279,
    SWITCH = 280,
    CASE = 281,
    DEFAULT = 282,
    VOID = 283,
    EVAL = 284,
    EXCEPTION_VAR = 285,
    ASSIGN = 286,
    OR = 287,
    AND = 288,
    BIT_OR = 289,
    BIT_XOR = 290,
    BIT_AND = 291,
    REL = 292,
    SHIFT = 293,
    MULTIPLY = 294,
    DIVIDE = 295,
    REMAINDER = 296,
    NOT = 297,
    ARRAY_LENGTH = 298,
    UMINUS = 299,
    INC = 300,
    DEC = 301,
    ARROW = 302
  };
#endif

/* Value type.  */



int SPVM_yyparse (SPVM_COMPILER* compiler);

#endif /* !YY_SPVM_YY_SPVM_YACC_TAB_H_INCLUDED  */
