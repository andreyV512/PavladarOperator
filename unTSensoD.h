// ---------------------------------------------------------------------------

#ifndef unTSensoDH
#define unTSensoDH
#include <System.hpp>
#include <Windows.hpp>
#include <SysUtils.hpp>
#include <Classes.hpp>

// ---------------------------------------------------------------------------
//����� �������� �������
class TSensorD {
public:
	TSensorD();
	~TSensorD();
     //����� �������
	int numSensor;
	int numZone;
	int numModule;
    	//�������� �������
	double valSensorAbcolute;
	//���������� � % �� �������� ������
	double valProcent;
	//���� ����������� �������
	TColor color;
private:
 int a;
	};
#endif
