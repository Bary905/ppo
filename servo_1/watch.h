#ifndef WATCH_H
#define WATCH_H

class Watch {
public:
   char fSecondsChanged;
   unsigned char ucSeconds;
   char fMinutesChanged;
   unsigned char ucMinutes;

   void Update(void);
};

#endif // WATCH_H

