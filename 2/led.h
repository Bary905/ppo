#ifndef LED_H
#define LED_H

class Led
{
    public:
        void StepRight(void);
        void StepLeft(void);
        void Init(void);

    private:
        unsigned char ucLedCtr;
        void Step(enum Step);
        void On(unsigned char);
};
#endif
