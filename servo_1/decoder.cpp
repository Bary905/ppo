#include "strings.h"
#include "decoder.h"

#define NULL 0

Decoder::Decoder(unsigned char ucMaxTokens, struct Keyword * pasKeywordArray, unsigned char ucKeywordArraySize) {
   ucMaxTokenNr = ucMaxTokens;
   pasTokens = new Token[ucMaxTokenNr];
   pasKeywords = pasKeywordArray;
   ucKeywordNr = ucKeywordArraySize;
}

char Decoder::ucFindTokensInString(char * String) {
   enum State {DELIMETER,TOKEN};

   unsigned char ucCharCtr;
   char cCurrrChar;
   unsigned char ucTokenNr = 0;	 
   enum State eState = DELIMETER;

   for (ucCharCtr = 0;; ucCharCtr++) {
      cCurrrChar = String[ucCharCtr];
      switch (eState) {
         case TOKEN:
            if (' ' == cCurrrChar) {
               eState = DELIMETER;
            } else if (NULL == cCurrrChar) {
               return ucTokenNr;
            } else if (ucMaxTokenNr == ucTokenNr) {
               return ucTokenNr;
            } else {
               eState = TOKEN;
            }
            break;
         case DELIMETER:
            if (' ' == cCurrrChar) {
               eState = DELIMETER;
            } else if (NULL == cCurrrChar) {
               return ucTokenNr;
            } else {
               pasTokens[ucTokenNr].uValue.pcString = String + ucCharCtr;
               ucTokenNr++;
               eState = TOKEN;
            }
            break;
         }
   }
}

enum Result Decoder::eSringToKeyword(char cStr[], enum KeywordCode * peKeyword) {
   unsigned char ucKeywordCtr;
   for (ucKeywordCtr = 0; ucKeywordCtr < ucKeywordNr; ucKeywordCtr++) {
      if (EQUAL == eCompareString(cStr, pasKeywords[ucKeywordCtr].cString)) {
         * peKeyword = pasKeywords[ucKeywordCtr].eCode;
         return OK;
      }
   }
   return ERROR;
}

void Decoder::DecodeTokens(void) {
   unsigned char ucTokenCtr;
   struct Token * psToken;

   for (ucTokenCtr = 0; ucTokenCtr < ucTokenNr; ucTokenCtr++) {
      psToken = & pasTokens[ucTokenCtr];
      if (OK == eSringToKeyword(psToken -> uValue.pcString, &psToken -> uValue.eKeywordCode)) {
         psToken -> eType = KEYWORD;
      } else if (OK == eHexStringToUInt(psToken -> uValue.pcString, &psToken -> uValue.uiNumber)) {
         psToken -> eType = NUMBER;
      } else {
         psToken -> eType = NUMBER;
      }
   }
}

void Decoder::DecodeMsg(char * String) {
   ucTokenNr = ucFindTokensInString(String);
   ReplaceCharacterInString(String, ' ', NULL);
   DecodeTokens();
}
