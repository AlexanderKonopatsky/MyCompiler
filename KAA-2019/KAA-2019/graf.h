#pragma once
#include "stdafx.h"

#define FST_BYTE 5, \
	FST::NODE(1, FST::RELATION('b', 1)),\
	FST::NODE(1, FST::RELATION('y', 2)),\
	FST::NODE(1, FST::RELATION('t', 3)),\
	FST::NODE(1, FST::RELATION('e', 4)),\
	FST::NODE()

#define FST_STRING 7, \
	FST::NODE(1, FST::RELATION('s', 1)),\
	FST::NODE(1, FST::RELATION('t', 2)),\
	FST::NODE(1, FST::RELATION('r', 3)),\
	FST::NODE(1, FST::RELATION('i', 4)),\
	FST::NODE(1, FST::RELATION('n', 5)),\
	FST::NODE(1, FST::RELATION('g', 6)),\
	FST::NODE()

#define FST_BOOL 5, \
	FST::NODE(1, FST::RELATION('b', 1)),\
	FST::NODE(1, FST::RELATION('o', 2)),\
	FST::NODE(1, FST::RELATION('o', 3)),\
	FST::NODE(1, FST::RELATION('l', 4)),\
	FST::NODE()

#define FST_FUNC 5, \
    FST::NODE(1, FST::RELATION('f', 1)),\
    FST::NODE(1, FST::RELATION('u', 2)),\
    FST::NODE(1, FST::RELATION('n', 3)),\
    FST::NODE(1, FST::RELATION('c', 4)),\
    FST::NODE()

#define FST_RETURN 7, \
	FST::NODE(1, FST::RELATION('r', 1)),\
	FST::NODE(1, FST::RELATION('e', 2)),\
	FST::NODE(1, FST::RELATION('t', 3)),\
	FST::NODE(1, FST::RELATION('u', 4)),\
	FST::NODE(1, FST::RELATION('r', 5)),\
	FST::NODE(1, FST::RELATION('n', 6)),\
	FST::NODE()

#define FST_PRINT 6, \
	FST::NODE(1, FST::RELATION('p', 1)),\
	FST::NODE(1, FST::RELATION('r', 2)),\
	FST::NODE(1, FST::RELATION('i', 3)),\
	FST::NODE(1, FST::RELATION('n', 4)),\
	FST::NODE(1, FST::RELATION('t', 5)),\
	FST::NODE()

#define FST_PROGRAM 8, \
	FST::NODE(1, FST::RELATION('p', 1)),\
	FST::NODE(1, FST::RELATION('r', 2)),\
	FST::NODE(1, FST::RELATION('o', 3)),\
	FST::NODE(1, FST::RELATION('g', 4)),\
	FST::NODE(1, FST::RELATION('r', 5)),\
	FST::NODE(1, FST::RELATION('a', 6)),\
	FST::NODE(1, FST::RELATION('m', 7)),\
	FST::NODE()

#define FST_IF 3, \
   FST::NODE(1, FST::RELATION('i',1)),\
   FST::NODE(1, FST::RELATION('f',2)),\
   FST::NODE()

#define FST_ELSE 5, \
	FST::NODE(1, FST::RELATION('e', 1)),\
	FST::NODE(1, FST::RELATION('l', 2)),\
	FST::NODE(1, FST::RELATION('s', 3)),\
	FST::NODE(1, FST::RELATION('e', 4)),\
	FST::NODE()

#define FST_STRCPY 7,\
    FST::NODE(1, FST::RELATION('s',1)),\
    FST::NODE(1, FST::RELATION('t',2)),\
    FST::NODE(1, FST::RELATION('r',3)),\
    FST::NODE(1, FST::RELATION('c',4)),\
    FST::NODE(1, FST::RELATION('p',5)),\
    FST::NODE(1, FST::RELATION('y',6)),\
    FST::NODE()

#define FST_STRCAT 7,\
    FST::NODE(1, FST::RELATION('s',1)),\
    FST::NODE(1, FST::RELATION('t',2)),\
    FST::NODE(1, FST::RELATION('r',3)),\
    FST::NODE(1, FST::RELATION('c',4)),\
    FST::NODE(1, FST::RELATION('a',5)),\
    FST::NODE(1, FST::RELATION('t',6)),\
    FST::NODE()

#define FST_ID 2, \
	FST::NODE(52, \
	FST::RELATION('a', 0), FST::RELATION('b', 0), FST::RELATION('c', 0), FST::RELATION('d', 0), FST::RELATION('e', 0), FST::RELATION('f', 0),\
	FST::RELATION('g', 0), FST::RELATION('h', 0), FST::RELATION('i', 0), FST::RELATION('j', 0), FST::RELATION('k', 0), FST::RELATION('l', 0),\
	FST::RELATION('m', 0), FST::RELATION('n', 0), FST::RELATION('o', 0), FST::RELATION('p', 0), FST::RELATION('q', 0), FST::RELATION('r', 0),\
	FST::RELATION('s', 0), FST::RELATION('t', 0), FST::RELATION('u', 0), FST::RELATION('v', 0), FST::RELATION('w', 0), FST::RELATION('x', 0),\
	FST::RELATION('y', 0), FST::RELATION('z', 0),\
	\
	FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1), FST::RELATION('e', 1), FST::RELATION('f', 1),\
	FST::RELATION('g', 1), FST::RELATION('h', 1), FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1),\
	FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1), FST::RELATION('q', 1), FST::RELATION('r', 1),\
	FST::RELATION('s', 1), FST::RELATION('t', 1), FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1),\
	FST::RELATION('y', 1), FST::RELATION('z', 1)),\
    FST::NODE()

#define FST_INTLIT 2, \
	FST::NODE(20, \
	FST::RELATION('1', 0), FST::RELATION('2', 0), FST::RELATION('3', 0), FST::RELATION('4', 0), FST::RELATION('5', 0), FST::RELATION('6', 0),\
	FST::RELATION('7', 0), FST::RELATION('8', 0), FST::RELATION('9', 0), FST::RELATION('0', 0),\
	\
	FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1),\
	FST::RELATION('7', 1), FST::RELATION('8', 1), FST::RELATION('9', 1), FST::RELATION('0', 1)),\
	FST::NODE()

#define FST_STRLIT 4, \
	FST::NODE(1, FST::RELATION('"', 1)),\
	FST::NODE(156, \
	FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1), FST::RELATION('e', 1), FST::RELATION('f', 1),\
	FST::RELATION('g', 1), FST::RELATION('h', 1), FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1),\
	FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1), FST::RELATION('q', 1), FST::RELATION('r', 1),\
	FST::RELATION('s', 1), FST::RELATION('t', 1), FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1),\
	FST::RELATION('y', 1), FST::RELATION('z', 1), FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1),\
	FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1), FST::RELATION('8', 1), FST::RELATION('9', 1), FST::RELATION('0', 1),\
	\
	FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
	FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
	FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
	FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
	FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
	FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION(' ', 1), FST::RELATION('.', 1), FST::RELATION(',', 1),\
	FST::RELATION('?', 1), FST::RELATION('!', 1), FST::RELATION(';', 1), FST::RELATION(':', 1), FST::RELATION('-', 1), FST::RELATION(' ', 1), \
	\
	FST::RELATION('a', 2), FST::RELATION('b', 2), FST::RELATION('c', 2), FST::RELATION('d', 2), FST::RELATION('e', 2), FST::RELATION('f', 2),\
	FST::RELATION('g', 2), FST::RELATION('h', 2), FST::RELATION('i', 2), FST::RELATION('j', 2), FST::RELATION('k', 2), FST::RELATION('l', 2),\
	FST::RELATION('m', 2), FST::RELATION('n', 2), FST::RELATION('o', 2), FST::RELATION('p', 2), FST::RELATION('q', 2), FST::RELATION('r', 2),\
	FST::RELATION('s', 2), FST::RELATION('t', 2), FST::RELATION('u', 2), FST::RELATION('v', 2), FST::RELATION('w', 2), FST::RELATION('x', 2),\
	FST::RELATION('y', 2), FST::RELATION('z', 2), FST::RELATION('1', 2), FST::RELATION('2', 2), FST::RELATION('3', 2), FST::RELATION('4', 2),\
	FST::RELATION('5', 2), FST::RELATION('6', 2), FST::RELATION('7', 2), FST::RELATION('8', 2), FST::RELATION('9', 2), FST::RELATION('0', 2),\
	\
	FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),\
	FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),\
	FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),\
	FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),\
	FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),\
	FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION(' ', 2), FST::RELATION('.', 2), FST::RELATION(',', 2),\
	FST::RELATION('?', 2), FST::RELATION('!', 2), FST::RELATION(';', 2), FST::RELATION(':', 2), FST::RELATION('-', 2), FST::RELATION(' ', 2)),\
    \
	FST::NODE(1, FST::RELATION('"', 3)),\
	FST::NODE()

#define FST_TRUE 5,\
    FST::NODE(1, FST::RELATION('t',1)),\
    FST::NODE(1, FST::RELATION('r',2)),\
    FST::NODE(1, FST::RELATION('u',3)),\
    FST::NODE(1, FST::RELATION('e',4)),\
    FST::NODE()

#define FST_FALSE 6,\
    FST::NODE(1, FST::RELATION('f',1)),\
    FST::NODE(1, FST::RELATION('a',2)),\
    FST::NODE(1, FST::RELATION('l',3)),\
    FST::NODE(1, FST::RELATION('s',4)),\
    FST::NODE(1, FST::RELATION('e',5)),\
    FST::NODE()


#define FST_POINT 2,\
    FST::NODE(1, FST::RELATION('.',1)),\
    FST::NODE()

#define FST_COMMA 2,\
    FST::NODE(1, FST::RELATION(',',1)),\
    FST::NODE()

#define FST_LEFTBRACE 2,\
    FST::NODE(1, FST::RELATION('[',1)),\
    FST::NODE()

#define FST_RIGHTBRACE 2,\
    FST::NODE(1, FST::RELATION(']',1)),\
    FST::NODE()

#define FST_LEFTHESIS 2,	\
	FST::NODE(1, FST::RELATION('(', 1)),\
	FST::NODE()

#define FST_RIGHTHESIS 2,	\
	FST::NODE(1, FST::RELATION(')', 1)),\
	FST::NODE()

#define FST_MORE 2, \
   FST::NODE(1, FST::RELATION('>', 1)),\
   FST::NODE()

#define FST_LESS 2, \
   FST::NODE(1, FST::RELATION('<', 1)),\
   FST::NODE()

#define FST_EQUALLY 2, \
   FST::NODE(1, FST::RELATION('=', 1)),\
   FST::NODE()

#define FST_COMPARE 2, \
   FST::NODE(1, FST::RELATION(':', 1)),\
   FST::NODE()

#define FST_PLUS 2, \
   FST::NODE(1, FST::RELATION('+', 1)),\
   FST::NODE()

#define FST_MINUS 2, \
  FST::NODE(1, FST::RELATION('-', 1)),\
  FST::NODE()

#define FST_STAR 2, \
  FST::NODE(1, FST::RELATION('*', 1)),\
  FST::NODE()

#define FST_DIRSLASH 2, \
  FST::NODE(1, FST::RELATION('/', 1)),\
  FST::NODE()

#define FST_AND 2, \
  FST::NODE(1, FST::RELATION('&', 1)),\
  FST::NODE()

#define FST_OR 2, \
  FST::NODE(1, FST::RELATION('|', 1)),\
  FST::NODE()

#define FST_NOT 2, \
  FST::NODE(1, FST::RELATION('~', 1)),\
  FST::NODE()

