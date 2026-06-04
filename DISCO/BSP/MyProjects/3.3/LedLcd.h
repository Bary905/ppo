#ifndef LEDLCD_H
#define LEDLCD_H

class LedLcd {

	public:
		LedLcd(uint8_t kol);
		void On(uint8_t index);
	private:
		uint8_t kolumna;
};

#endif /*LEDLCD_H*/
