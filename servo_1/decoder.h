#ifndef DECODER_H
#define DECODER_H

#include "strings.h"

#define MAX_KEYWORD_STRING_LTH 10 // mksymalna dlugosc komendy 

enum TokenType {
   KEYWORD,
   NUMBER,
   STRING
};

enum KeywordCode {
   ID,
   CALLIB,
   GOTO,
   STEP
};

struct Keyword {
   enum KeywordCode eCode;
   char cString[MAX_KEYWORD_STRING_LTH + 1];
};

union TokenValue {
   enum KeywordCode eKeywordCode; // jezeli KEYWORD unsigned 
   unsigned int uiNumber;  // jezeli NUMBER 
   char * pcString;        // jezeli STRING 
};

struct Token {
   enum TokenType eType;    // KEYWORD, NUMBER, STRING 
   union TokenValue uValue; // enum, unsigned int, char* 
};

class Decoder {
private:
   char ucFindTokensInString(char * String);
   enum Result eSringToKeyword(char cStr[], enum KeywordCode * peKeyword);
   void DecodeTokens(void);

public:
   unsigned char ucTokenNr;
   unsigned char ucMaxTokenNr;
   unsigned char ucKeywordNr;
   struct Token * pasTokens;
   struct Keyword * pasKeywords;
   Decoder(unsigned char ucMaxTokens, struct Keyword * pasKeywordArray, unsigned char ucKeywordArraySize);
   void DecodeMsg(char * String);
};

#endif // DECODER_H
