// ---------------------------------------------------------------------------

#ifndef unTSensoDH
#define unTSensoDH
#include <System.hpp>
#include <Windows.hpp>
#include <SysUtils.hpp>
#include <Classes.hpp>

// ---------------------------------------------------------------------------
//класс значений датчика
class TSensorD {
public:
	TSensorD();
	~TSensorD();
     //номер датчика
	int numSensor;
	int numZone;
	int numModule;
    	//значение датчика
	double valSensorAbcolute;
	//превышение в % от значения порога
	double valProcent;
	//цвет отображения датчика
	TColor color;
private:
 int a;
	};
#endif
