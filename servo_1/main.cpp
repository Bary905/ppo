#include "keyboard.h"
#include "servo.h"
#include "uart.h"
#include "strings.h"
#include "decoder.h"
#include "watch.h"
#include "timer_interrupts.h"

extern class Watch sWatch;
extern class Servo sServo;

struct Keyword asKeywords[]={{ID,"id"},{CALLIB,"cal"},{GOTO,"goto"}};
Decoder sDecoder(2, asKeywords, sizeof(asKeywords) / sizeof(asKeywords[0]));

unsigned int dbg;

void Timer0_Handler() {
   sServo.Automate();
}

void Timer1_Handler() {
   sWatch.Update();
}

int main() {

   char fSend_UnknownCommand = 0;
   char fSend_ID = 1;
   char fSend_OK = 1;

   Keyboard_Init();
   UART_Init();
   sServo.Init();
   Timer0Interrupts_Init(1000000 / 10, &Timer0_Handler);
   Timer1Interrupts_Init(1000000, &Timer1_Handler);

   while (1) {

      switch (eKeyboard_Read()) {

         case BUTTON_1:
            sServo.Callib();
            break;

         case BUTTON_2:
            sServo.GoTo(12);
            break;

         case BUTTON_3:
            sServo.GoTo(24);
            break;

         case BUTTON_4:
            sServo.GoTo(36);
            break;

         default:
            break;
         }

      if (READY == eUART_Rx_GetStatus()) {
         char acRxString[RX_BUFFER_SIZE];
         UART_Rx_GetStringCopy(acRxString);
         sDecoder.DecodeMsg(acRxString);

         if ((sDecoder.ucTokenNr != 0) && (sDecoder.pasTokens[0].eType == KEYWORD)) {
            switch (sDecoder.pasTokens[0].uValue.eKeywordCode) {

               case ID:
                  sServo.Callib();
                  fSend_ID = 1;
                  break;

               case CALLIB:
                  sServo.Callib();
                  fSend_OK = 1;
                  break;

               case GOTO:
                  dbg = sDecoder.pasTokens[1].uValue.uiNumber;
                  sServo.GoTo(dbg);
                  fSend_OK = 1;
                  break;

               default:
                  fSend_UnknownCommand = 1;
                  break;
            }
         } else {
            fSend_UnknownCommand = 1;
         }
      }

      if (eUART_Tx_GetStatus() == FREE) {
         char cStringToSend[TX_BUFFER_SIZE];

         if (fSend_ID) {
            fSend_ID = 0;
            UART_Tx_SendString("servo\n");
         } else if (fSend_UnknownCommand) {
            fSend_UnknownCommand = 0;
            UART_Tx_SendString("unknowncommand\n");
         } else if (fSend_OK) {
            fSend_OK = 0;
            UART_Tx_SendString("ok\n");
         } else if (sWatch.fSecondsChanged) {
            sWatch.fSecondsChanged = 0;
            CopyString("sec ", cStringToSend);
            AppendUIntToString(sWatch.ucSeconds, cStringToSend);
            AppendString("\n", cStringToSend);
            UART_Tx_SendString(cStringToSend);
         } else if (sWatch.fMinutesChanged) {
            sWatch.fMinutesChanged = 0;
            CopyString("min ", cStringToSend);
            AppendUIntToString(sWatch.ucMinutes, cStringToSend);
            AppendString("\n", cStringToSend);
            UART_Tx_SendString(cStringToSend);
         }
      }
   }
}
