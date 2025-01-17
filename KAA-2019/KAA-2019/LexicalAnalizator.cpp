#include "stdafx.h"

namespace LA
{
	void Lexicalanaliz(char inText[], Log::LOG, LEX::LexTable& lextable, ID::IdTable& idtable)
	{
		int line = 0, col = 0, sizeofbuf = 0;
		bool provsep = false;
		bool proverka = false;
		bool newflag = false;
		bool secondflag = false;
		bool flag = false;
		char postfix[LT_MAXSIZE];
		char string[5] = "LTR ";
		char buffer[LT_MAXSIZE];
		char newbuf[LT_MAXSIZE];
		char anotherbuf[LT_MAXSIZE];
		LEX::LexTable* ltable;
		ID::IdTable* itable;
		ID::IDDATATYPE dataType;
		ID::IDTYPE idType;
		ltable = &lextable;
		itable = &idtable;
		for (int i = 0; i < strlen(inText); i++)
		{
			buffer[sizeofbuf] = inText[i];
			sizeofbuf++;
			secondflag = false;
			provsep = false;
			if (newflag)
			{
				line++;
				col = 0;
				newflag = false;
			}
			if (inText[i] == LEX_SPACE || inText[i] == LEX_ENDL || inText[i] == LEX_POINT || inText[i] == LEX_LEFTHESIS || inText[i] == LEX_RIGHTHESIS || inText[i] == LEX_RIGHTBRACE || inText[i] == LEX_LEFTBRACE || inText[i] == LEX_COMMA)
			{
				if (inText[i] == LEX_ENDL)
				{
					newflag = true;
				}
				if (LEX_APOS == buffer[0] && LEX_SPACE == inText[i])
				{
					continue;
				}
				if (inText[i] == LEX_POINT || inText[i] == LEX_LEFTHESIS || inText[i] == LEX_RIGHTHESIS || inText[i] == LEX_RIGHTBRACE || inText[i] == LEX_LEFTBRACE || inText[i] == LEX_COMMA)
				{
					newbuf[0] = buffer[sizeofbuf - 1];
					newbuf[1] = LEX_END;
					secondflag = true;
				}
				if (sizeofbuf == 1)
				{
					buffer[sizeofbuf] = LEX_END;
				}
				else
				{
					buffer[sizeofbuf - 1] = LEX_END;
				}
				sizeofbuf = 0;
				provsep = true;
				if (buffer[sizeofbuf] == LEX_SPACE || buffer[sizeofbuf] == LEX_ENDL)
				{
					continue;
				}
			}
			col++;
			if (provsep)
			{
				FST::FST fstint(buffer, FST_BYTE);
				if (FST::execute(fstint))
				{
					LEX::Entry lEntry = { LEX_BYTE , line, col };
					strcpy(lEntry.buf, buffer);
					LEX::Add(*ltable, lEntry);
					dataType = ID::INT;
					idType = ID::V;
					goto link;
				}
				FST::FST fststr(buffer, FST_STRING);
				if (FST::execute(fststr))
				{
					LEX::Entry lEntry = { LEX_STRING, line, col };
					strcpy(lEntry.buf, buffer);
					LEX::Add(*ltable, lEntry);
					dataType = ID::STR;
					idType = ID::V;
					goto link;
				}
				FST::FST fstbool(buffer, FST_BOOL);
				if (FST::execute(fstbool))
				{
					LEX::Entry lEntry = { LEX_BOOL, line, col };
					strcpy(lEntry.buf, buffer);
					LEX::Add(*ltable, lEntry);
					dataType = ID::BOOL;
					idType = ID::V;
					goto link;
				}
				FST::FST fstfunc(buffer, FST_FUNC);
				if (FST::execute(fstfunc))
				{
					LEX::Entry lEntry = { LEX_FUNCTION, line, col };
					LEX::Add(*ltable, lEntry);
					idType = ID::F;
					goto link;
				}
				FST::FST fstret(buffer, FST_RETURN);
				if (FST::execute(fstret))
				{
					LEX::Entry lEntry = { LEX_RETURN, line, col };
					LEX::Add(*ltable, lEntry);
					idType = ID::V;
					goto link;
				}
				FST::FST fstprint(buffer, FST_PRINT);
				if (FST::execute(fstprint))
				{
					LEX::Entry lEntry = { LEX_PRINT, line, col };
					LEX::Add(*ltable, lEntry);
					idType = ID::V;
					goto link;
				}
				FST::FST fstprogram(buffer, FST_PROGRAM);
				if (FST::execute(fstprogram))
				{
					LEX::Entry lEntry = { LEX_PROGRAM, line, col };
					LEX::Add(*ltable, lEntry);
					strcpy(postfix, buffer);
					SA::OneProgram(*ltable, flag);
					flag = true;
					goto link;
				}
				FST::FST fstif(buffer, FST_IF);
				if (FST::execute(fstif))
				{
					LEX::Entry lEntry = { LEX_IF, line, col };
					LEX::Add(*ltable, lEntry);
					goto link;
				}
				FST::FST fstelse(buffer, FST_ELSE);
				if (FST::execute(fstelse))
				{
					LEX::Entry lEntry = { LEX_ELSE, line, col };
					LEX::Add(*ltable, lEntry);
					goto link;
				}
				FST::FST fststrcpy(buffer, FST_STRCPY);
				if (FST::execute(fststrcpy))
				{
					LEX::Entry lEntry = { LEX_LIBFUNC, line, col, 1 };
					LEX::Add(*ltable, lEntry);
					goto link;
				}
				FST::FST fststrcat(buffer, FST_STRCAT);
				if (FST::execute(fststrcat))
				{
					LEX::Entry lEntry = { LEX_LIBFUNC, line, col, 2 };
					LEX::Add(*ltable, lEntry);
					goto link;
				}
				FST::FST fstlitbool(buffer, FST_FALSE);
				FST::FST fstltbool(buffer, FST_TRUE);
				if (FST::execute(fstlitbool) || FST::execute(fstltbool))
				{
					LEX::Entry lEntry = { LEX_LITERAL, line, col };
					lEntry.znak = -1;
					strcpy(lEntry.buf, buffer);
					LEX::Add(*ltable, lEntry);
					ID::Entry iEntry;
					strcpy(iEntry.id, string);
					iEntry.iddatatype = ID::BOOL;
					iEntry.idtype = ID::L;
					strcpy(iEntry.value.vstr->str, buffer);
					strcpy(iEntry.value.vbool, buffer);
					for (int i = 0; i < itable->size; i++)
					{
						if (strcmp((*itable).table[i].value.vbool, iEntry.value.vbool) == 0)
						{
							proverka = true;
							break;
						}
						else proverka = false;
					}
					iEntry.idxfirstLE = line;
					if (!proverka)
					{
						ID::Add(*itable, iEntry);
					}
					goto link;
				}
				FST::FST fstid(buffer, FST_ID);
				if (FST::execute(fstid))
				{
					if (strlen(buffer) > 20)
						throw ERROR_THROW(122, line, col);
					LEX::Entry lEntry = { LEX_ID, line, col };
					strcpy(lEntry.buf, buffer);
					LEX::Add(*ltable, lEntry);
					ID::Entry iEntry;
					strcpy(anotherbuf, buffer);
					if (idType == ID::F)
					{
						strcpy(postfix, buffer);
					}
					strcpy(iEntry.postfix, postfix);
					bool isExecute = false;
					SA::Proverka(*ltable, *itable);
					SA::Pereobyavl(*ltable, *itable, buffer, postfix, line, col);
					for (int i = 0; i <= (*itable).size; i++)
					{
						if (strcmp((*itable).table[i].id, buffer) == 0)
						{
							isExecute = true;
							if (itable->table[i].idtype == ID::F)
							{
								break;
							}
							if (strcmp((*itable).table[i].postfix, iEntry.postfix) != 0)
							{
								isExecute = false;
							}

						}
					}
					if (!isExecute)						//���� ���������� �� ���������
					{
						strcpy(iEntry.id, buffer);
						iEntry.idtype = idType;
						iEntry.iddatatype = dataType;
						iEntry.value.vint = TI_INT_DEFAULT;
						iEntry.value.vstr->len = TI_STR_DEFAULT;
						strcpy(iEntry.value.vstr->str, "' '");
						iEntry.idxfirstLE = line;
						ID::Add(*itable, iEntry);
					}
					goto link;
				}
				FST::FST fstintlit(buffer, FST_INTLIT);
				if (FST::execute(fstintlit))
				{
					long double bufNum = std::atoi(buffer);
					LEX::Entry lEntry = { LEX_LITERAL, line, col };
					if (buffer[0] == '0' && buffer[1] == '0') 
					{
						lEntry.system = 8;
						SA::CheckOct(*ltable, buffer);
					}
					else
					{
						lEntry.system = 10;
					}
					lEntry.znak = bufNum;
					strcpy(lEntry.buf, buffer);
					LEX::Add(*ltable, lEntry);
					SA::ZeroDivision(*ltable, buffer);
					ID::Entry iEntry;
					strcpy(iEntry.id, string);
					iEntry.iddatatype = ID::INT;
					iEntry.idtype = ID::L;
					if (bufNum >= 255)
					{
						throw ERROR_THROW(121, line, col);
					}
					iEntry.value.vint = (int)bufNum;
					strcpy(iEntry.value.vstr->str, buffer);
					for (int i = 0; i < itable->size; i++)
					{
						if (iEntry.value.vint == (*itable).table[i].value.vint)
						{
							proverka = true;
							break;
						}
						else  proverka = false;
					}
					iEntry.idxfirstLE = line;
					if (!proverka)
					{
						ID::Add(*itable, iEntry);
					}
					goto link;
				}
				FST::FST fststrlit(buffer, FST_STRLIT);
				if (FST::execute(fststrlit))
				{
					LEX::Entry lEntry = { LEX_LITERAL, line, col };
					lEntry.znak = -1;
					strcpy(lEntry.buf, buffer);
					LEX::Add(*ltable, lEntry);
					ID::Entry iEntry;
					strcpy(iEntry.id, string);
					iEntry.iddatatype = ID::STR;
					iEntry.idtype = ID::L;
					if (strlen(buffer) > 255)
						throw ERROR_THROW(120, line, col);
					iEntry.value.vstr->len = strlen(buffer);
					strcpy(iEntry.value.vstr->str, buffer);
					for (int i = 0; i < itable->size; i++)
					{
						if (strcmp(iEntry.value.vstr->str, (*itable).table[i].value.vstr->str) == 0)
						{

							proverka = true;
							break;
						}
						else proverka = false;
					}
					iEntry.idxfirstLE = line;
					if (!proverka)
					{
						ID::Add(*itable, iEntry);
					}
					goto link;
				}
				FST::FST fstpoint(buffer, FST_POINT);
				if (FST::execute(fstpoint))
				{
					LEX::Entry lEntry = { LEX_POINT, line, col };
					LEX::Add(*ltable, lEntry);
					continue;
				}
				FST::FST fstcomma(buffer, FST_COMMA);
				if (FST::execute(fstcomma))
				{
					LEX::Entry lEntry = { LEX_COMMA, line, col };
					lEntry.priority = 1;
					LEX::Add(*ltable, lEntry);
					continue;
				}
				FST::FST fstlbrace(buffer, FST_LEFTBRACE);
				if (FST::execute(fstlbrace))
				{
					LEX::Entry lEntry = { LEX_LEFTBRACE, line, col };
					LEX::Add(*ltable, lEntry);
					continue;
				}
				FST::FST fstrbrace(buffer, FST_RIGHTBRACE);
				if (FST::execute(fstrbrace))
				{
					LEX::Entry lEntry = { LEX_RIGHTBRACE, line, col };
					LEX::Add(*ltable, lEntry);
					continue;
				}
				FST::FST fstlthesis(buffer, FST_LEFTHESIS);
				if (FST::execute(fstlthesis))
				{
					LEX::Entry lEntry = { LEX_LEFTHESIS, line, col };
					lEntry.priority = 0;
					LEX::Add(*ltable, lEntry);
					continue;
				}
				FST::FST fstrthesis(buffer, FST_RIGHTHESIS);
				if (FST::execute(fstrthesis))
				{
					LEX::Entry lEntry = { LEX_RIGHTHESIS, line, col };
					lEntry.priority = 0;
					LEX::Add(*ltable, lEntry);
					continue;
				}
				FST::FST fstmore(buffer, FST_MORE);
				if (FST::execute(fstmore))
				{
					LEX::Entry lEntry = { LEX_MORE, line, col };
					lEntry.znak = 2;
					LEX::Add(*ltable, lEntry);
					goto link;
				}
				FST::FST fstless(buffer, FST_LESS);
				if (FST::execute(fstless))
				{
					LEX::Entry lEntry = { LEX_LESS, line, col };
					lEntry.znak = 2;
					LEX::Add(*ltable, lEntry);
					goto link;
				}
				FST::FST fstequally(buffer, FST_EQUALLY);
				if (FST::execute(fstequally))
				{
					LEX::Entry lEntry = { LEX_EQUALLY, line, col };
					lEntry.znak = 2;
					LEX::Add(*ltable, lEntry);
					goto link;
				}
				FST::FST fstcompare(buffer, FST_COMPARE);
				if (FST::execute(fstcompare))
				{
					LEX::Entry lEntry = { LEX_COMPARE, line, col };
					LEX::Add(*ltable, lEntry);
					goto link;
				}
				FST::FST fstplus(buffer, FST_PLUS);
				if (FST::execute(fstplus))
				{
					LEX::Entry lEntry = { LEX_PLUS, line, col };
					lEntry.znak = 1;
					lEntry.priority = 2;
					LEX::Add(*ltable, lEntry);
					goto link;
				}
				FST::FST fstminus(buffer, FST_MINUS);
				if (FST::execute(fstminus))
				{
					LEX::Entry lEntry = { LEX_MINUS, line, col };
					lEntry.znak = 1;
					lEntry.priority = 2;
					LEX::Add(*ltable, lEntry);
					goto link;
				}
				FST::FST fststar(buffer, FST_STAR);
				if (FST::execute(fststar))
				{
					LEX::Entry lEntry = { LEX_STAR, line, col };
					lEntry.znak = 1;
					lEntry.priority = 3;
					LEX::Add(*ltable, lEntry);
					goto link;
				}
				FST::FST fstslash(buffer, FST_DIRSLASH);
				if (FST::execute(fstslash))
				{
					LEX::Entry lEntry = { LEX_DIRSLASH, line, col };
					lEntry.znak = 1;
					lEntry.priority = 3;
					LEX::Add(*ltable, lEntry);
					goto link;
				}
				FST::FST fstand(buffer, FST_AND);
				if (FST::execute(fstand))
				{
					LEX::Entry lEntry = { LEX_AND, line, col };
					lEntry.znak = 1;
					lEntry.priority = 3;
					LEX::Add(*ltable, lEntry);
					goto link;
				}
				FST::FST fstor(buffer, FST_OR);
				if (FST::execute(fstor))
				{
					LEX::Entry lEntry = { LEX_OR, line, col };
					lEntry.znak = 1;
					lEntry.priority = 2;
					LEX::Add(*ltable, lEntry);
					goto link;
				}
				FST::FST fstnot(buffer, FST_NOT);
				if (FST::execute(fstnot))
				{
					LEX::Entry lEntry = { LEX_NOT, line, col };
					lEntry.znak = 1;
					lEntry.priority = 2;
					LEX::Add(*ltable, lEntry);
					goto link;
				}
			}
		link:
			if (secondflag)
			{
				FST::FST fstp(newbuf, FST_POINT);
				if (FST::execute(fstp))
				{
					LEX::Entry lEntry = { LEX_POINT , line, col };
					LEX::Add(*ltable, lEntry);
					continue;
				}
				FST::FST fstlft(newbuf, FST_LEFTHESIS);
				if (FST::execute(fstlft))
				{
					LEX::Entry lEntry = { LEX_LEFTHESIS , line, col };
					LEX::Add(*ltable, lEntry);
					continue;
				}
				FST::FST fstrft(newbuf, FST_RIGHTHESIS);
				if (FST::execute(fstrft))
				{
					LEX::Entry lEntry = { LEX_RIGHTHESIS , line, col };
					LEX::Add(*ltable, lEntry);
					continue;
				}
				FST::FST fstrb(newbuf, FST_RIGHTBRACE);
				if (FST::execute(fstrb))
				{
					LEX::Entry lEntry = { LEX_RIGHTBRACE , line, col };
					LEX::Add(*ltable, lEntry);
					continue;
				}
				FST::FST fstlb(newbuf, FST_LEFTBRACE);
				if (FST::execute(fstlb))
				{
					LEX::Entry lEntry = { LEX_LEFTBRACE , line, col };
					LEX::Add(*ltable, lEntry);
					continue;
				}
				FST::FST fstc(newbuf, FST_COMMA);
				if (FST::execute(fstc))
				{
					LEX::Entry lEntry = { LEX_COMMA, line, col };
					LEX::Add(*ltable, lEntry);
					continue;
				}
			}
		}
	}
}
