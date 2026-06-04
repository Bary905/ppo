#include <cstring>
#include <cstdlib>
#include "decoder.h"

Decoder::Decoder(unsigned char ucMaxTokens, struct Keyword * pasKeywordArray, unsigned char ucKeywordArraySize) {
   ucMaxTokenNr = ucMaxTokens;
   pasTokens = new Token[ucMaxTokenNr];
   pasKeywords = pasKeywordArray;
   ucKeywordNr = ucKeywordArraySize;
}

char Decoder::ucFindTokensInString(char * String) {
   unsigned char ucTokenNr = 0;	 
   char * pToken = std::strtok(String, " ");

   while (pToken != NULL && ucTokenNr < ucMaxTokenNr) {
      pasTokens[ucTokenNr].uValue.pcString = pToken;
      ucTokenNr++;
      pToken = std::strtok(NULL, " ");
   }
   return ucTokenNr;
}

bool Decoder::eSringToKeyword(char cStr[], enum KeywordCode * peKeyword) {
   unsigned char ucKeywordCtr;
   for (ucKeywordCtr = 0; ucKeywordCtr < ucKeywordNr; ucKeywordCtr++) {
      if (0 == std::strcmp(cStr, pasKeywords[ucKeywordCtr].cString)) {
         * peKeyword = pasKeywords[ucKeywordCtr].eCode;
         return true;
      }
   }
   return false;
}

void Decoder::DecodeTokens(void) {
   unsigned char ucTokenCtr;
   struct Token * psToken;

   for (ucTokenCtr = 0; ucTokenCtr < ucTokenNr; ucTokenCtr++) {
      psToken = & pasTokens[ucTokenCtr];
      if (eSringToKeyword(psToken -> uValue.pcString, &psToken -> uValue.eKeywordCode)) {
         psToken -> eType = KEYWORD;
      } else {
         char * pEndPtr;
         psToken -> uValue.uiNumber = std::strtoul(psToken -> uValue.pcString, &pEndPtr, 0);
         if (pEndPtr != psToken -> uValue.pcString && *pEndPtr == '\0') {
            psToken -> eType = NUMBER;
         } else {
            psToken -> eType = STRING;
         }
      }
   }
}

void Decoder::DecodeMsg(char * String) {
   ucTokenNr = ucFindTokensInString(String);
   DecodeTokens();
}
