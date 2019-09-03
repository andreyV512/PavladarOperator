// ---------------------------------------------------------------------------

#ifndef unTExtFunctionH
#define unTExtFunctionH
// ---------------------------------------------------------------------------
#include <System.hpp>
#include <Windows.hpp>
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <Vcl.Grids.hpp>
#include <System.IOUtils.hpp>
//-------------
#include <vector>
#include <iterator>
using namespace std;
// ---------
#define  sizeArr 150;

// #include "workWithX502.h"
// ---------------------------------------------------------------------------
// различные вспомогательные функции
enum filterTypes {
	Butterworth = 0, Chebyshev = 1, Elliptic = 2
};

enum filterSubTypes {
	lowPass = 0, highPass = 1, bandPass = 2, bandStop = 3
};

class TExtFunction {
	TExtFunction();
	~TExtFunction();

public:
	// заливка массивов  (*a)[2]
	static int FillArrayModule(AnsiString _tubeNum, int _tubeModule, int _maxZones, int _countSensors, int _arrDataModule[8][100]);
	// показ трубы
	static int ShowArrayModule(int _countSensors, int _maxZones, int _arrDataModule[8][100], TChart* _chart);
	// настраиваем чарты одноообразно, это длинно муторно, но полезно
	static void PrepareBarChart(int _countSensors, int _maxZones, TChart* _chart);
	static void PrepareBarChartLCPav(int _countSensors, int _maxZones, TChart* _chart);
	static void PrepareFastLineChart(int _countSensors, int _maxX, int _maxY, int _minY, TChart* _chart);
	static void PrepareThickBarChart(int _minY, int _maxY, int _countSensors, int _maxZones, TChart* _chart);
	// пишем чарт (трубу) в базу по зонам с учетом каналов и типа модуля
	// _moduleType 1-толщиномер 2 - поперечник 3 - продольник 4 - группа прочности 5 - суммарный резульнат
	static int SaveChartToDB(AnsiString _serialTubeNum, AnsiString _tubeNum, int _codeTubeTypeSize, int _moduleType, int _maxZones, int _codeCustomer, int _codeOperatorU,
		int _codeStatusTube, TChart* _chart);
	// вывод в строку состояния
	static int UpdateStatusBar(TStatusBar *_StatusBar, AnsiString _strTitle, AnsiString _strText, TColor _colorFont);
	// вывод в какою-то метку
	static int UpdateLabelStatus(TLabel *_label, AnsiString _strTitle, AnsiString _strText, TColor _colorFont);
	// вывод сообщения в модальную форму
	static int ShowBigModalMessage(AnsiString _strMsg, TColor _color);
	// непонятная фигня
	static void FATAL(AnsiString _msg);
	// для просмотра графиков диагностики
	static void PrepareChartToTst(TChart *chart, int _countChLog, int _lengthChart, int _maxYChart);
	static double MedianFilter3(double _data0, double _data1, double _data2);
	static double MedianFilter5(double _data0, double _data1, double _data2, double _data3, double _data4);
	static int GetIP_MAC(AnsiString &_strIp4);

	// массив для закачки и просмотра зон - ширина по максимуму на 100 зон, глубина по количеству датчиков 8 (забиваем по макимуму)
	static int arrDataThick[8][100];
	static int arrDataCross[8][100];
	static int arrDataSum[8][100];

	// печать грида
	static int PrintGrid(AnsiString _title, TStringGrid *_grid, TPrinter* _printer, TPrinterOrientation _orientation, int _beginPrinterXPx, int _beginPrinterYPx,
		int countColPerPage, bool _isPrinting);
	// загрузка файла трубы
	static int LoadTubeCrossFromFile(AnsiString _fullFileName, AnsiString _head, short &zones, short &sensors_a, vector<int> &VZoneLength, DynamicArray<double> &zone_data,
		vector<vector<double> > &sensor_data, vector<vector<vector<double> > > &Source_Data);
    static int GetDataCross(TChart *_chart,int _numFusion, int _numTube,int _countZones, int _countSensors,double _thresholdC1,double _thresholdC2);
private:
	// static int a;
	// строка для вывода сообщений
	static void Fread(void* _buf, int _size, int _n, FILE* _df);
	static int LoadINI(FILE* _df);
	static int LoadFilters(FILE* _df);

	AnsiString msgLast;

};

// массивы для хранения признаков по зонам (датчик - зона)
int TExtFunction::arrDataThick[8][100];
int TExtFunction::arrDataCross[8][100];
int TExtFunction::arrDataSum[8][100];

// int TExtFunction::a;
// int TExtFunction::a=0;
#endif
