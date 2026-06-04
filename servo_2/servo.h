#ifndef SERVO_H
#define SERVO_H

class Servo {
private:
   enum ServoState { CALLIB, IDDLE, IN_PROGRESS };
   enum DetectorState { ACTIVE, INACTIVE };

   ServoState eState;
   unsigned int uiCurrentPosition;
   unsigned int uiDesiredPosition;

   void DetectorInit(void);
   DetectorState eReadDetector(void);

public:
   void Init(void);
   void Callib(void);
   void GoTo(unsigned int uiPosition);
   void Automate(void);
};

#endif // SERVO_H
