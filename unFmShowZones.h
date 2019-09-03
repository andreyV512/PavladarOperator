// ---------------------------------------------------------------------------

#ifndef unFmShowZonesH
#define unFmShowZonesH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
// ----------------------
#include "unFmViewZone.h"
// -------------------
#include "unTSensoD.h"
#include "unTGlSettings.h"
#include "unTExtFunction.h"
#include <Vcl.Buttons.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.AppEvnts.hpp>
#include <Vcl.Graphics.hpp>
#include <Math.hpp>
#include <Vcl.Menus.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <vector>
#include <iterator>
using namespace std;

// ---------------------------------------------------------------------------
class TfmShowZones : public TForm {
__published: // IDE-managed Components
	TPanel *PanelTop;
	TPanel *PanelThick;
	TSplitter *SplitterTop;
	TSplitter *SplitterMid;
	TPanel *PanelLong;
	TPrintDialog *PrintDialog;
	TApplicationEvents *ApplicationEvents;
	TOpenDialog *OpenDialogFromFile;
	TChart *chartLong;
	TPanel *pnlTopLeft;
	TBarSeries *Series2;
	TChart *chartThick;
	TBarSeries *BarSeries2;
	TBarSeries *Series1;
	TFastLineSeries *Series4;
	TFastLineSeries *Series5;
	TFastLineSeries *Series7;
	TFastLineSeries *Series8;
	TEdit *edtLong;
	TEdit *edtThick;
	TMemo *memoBrack;
	TPopupMenu *popMenuShowZ;
	TMenuItem *menuPrint;
	TPanel *PanelCross;
	TChart *chartCross;
	TBarSeries *BarSeries1;
	TFastLineSeries *Series3;
	TFastLineSeries *Series6;
	TEdit *edtCross;
	TADOQuery *queryTitle;
	TDBGrid *dbGridTitle1;
	TDataSource *dsTitle;
	TDBGrid *dbGridTitle2;
	TEdit *edThickDop;

	void __fastcall EcrossBorder10Exit(TObject *Sender);
	void __fastcall EcrossBorder10KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall ChartCrossClickSeries(TCustomChart *Sender, TChartSeries *Series, int ValueIndex,
		TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall SplitterTopMoved(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall SplitterMidMoved(TObject *Sender);
	void __fastcall bbtPrintClick(TObject *Sender);
	void __fastcall strGridCrossDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect, TGridDrawState State);
	void __fastcall ApplicationEventsMessage(tagMSG &Msg, bool &Handled);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall strGridLongDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect, TGridDrawState State);
	void __fastcall strGridThickDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect, TGridDrawState State);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall strGridCrossSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall chartLongClickSeries(TCustomChart *Sender, TChartSeries *Series, int ValueIndex, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall chartThickClickSeries(TCustomChart *Sender, TChartSeries *Series, int ValueIndex, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall menuPrintClick(TObject *Sender);


private: // User declarations
	// переменные
	TColor oldColorCell;
	int selACol;
	int selARow;
	TGridDrawState gridState;
	bool canSelect;
	bool isLoadFm;
	// функции
	void SaveBorders();
	int ShowZoneData(int _zone, int _sensor);
	void MarkerSet(int _zone, int _sensor);
	void MarkerOff(void);

	// vector <TSensorD*> sensorsTh;
	// vector <TSensorD*> sensorsL;
	// vector <TSensorD*> sensorsC;
	TPrinter* printer;
	TImage* image;

	UINT msgFmViewZone;

	int PrintImage(TImage* _image, AnsiString _filename, TPrinter* _printer, TPrinterOrientation _orientation,
		int _beginPrinterXmm, int _beginPrinterYmm, int _widgthIcon, int _heightIcon, bool _isPrinting);
	int PrintGridCanvas(TStringGrid *_grid, TPrinter* _printer, TPrinterOrientation _orientation, int _beginPrinterXmm,
		int _beginPrinterYmm, int _widgthMm, int _heigtMm, bool _isPrinting);
	int PrintGrid(AnsiString _title, TStringGrid *_grid, TPrinter* _printer, TPrinterOrientation _orientation,
		int _beginPrinterXmm, int _beginPrinterYmm, int headerSizeMm, int footerSizeMm, int _colPerPage,
		bool _isPrinting);
	int PrintResult(TPrinter* _printer, TPrinterOrientation _orientation, int _beginPrinterXPmm, int _beginPrinterYPmm);

	vector<int>VZoneLength;
	int ZoneLength;
	// ! Кол-во отображаемых зон в результате
	int zones;
	// ! Кол-во активных сенсоров (датчиков)
	//int sensors_a;
	// ! массивы итоговых значений по зонам
	vector<double>dataLong;
	vector<double>dataCross;
    //0 - откорректированные данные 1 - качество результат
	vector<vector<double> >dataThickMax;
	//vector<double>dataThickMaxR;
	vector<vector<double> >dataThickMin;
	//vector<double>dataThickMinR;
	// ! массив значений по датчикам
	//vector<vector<double> >sensorsDataLong;
	//vector<vector<double> >sensorsDataCross;
	//vector<vector<double> >sensorsDataThickMin;
	//vector<vector<double> >sensorsDataThickMinR;
	//vector<vector<double> >sensorsDataThickMax;
    //vector<vector<double> >sensorsDataThicMaxR;
	//вектор по всем датчикам зоны для поиска максимума
	vector<double>vecMaxCh;
    vector<double>vecMaxChR;
	// зона.датчик.измерение
	//vector<vector<vector<double> > >Source_Data;
    int nomThick;
	int GetDataCross(int _numFusion,int _numTube);
	int GetDataLong(int _numFusion,int _numTube);
	int GetDataThick(int _numFusion,int _numTube);
    	// -------------------
    int PrintResult2(TPrinter* _printer,TPrinterOrientation _orientation, int _beginPrinterXPmm, int _beginPrinterYPmm);
	double scale;
	double nominalThick;
	double valBorderMin;
	double valBorderMax;
	double valBborderC1;
	double valBborderC2;
	double valBborderL1;
	double valBborderL2;
	//int currentZone;
    	int countZones;
	// выбранная зона
	int selectZoneT;
	int selectZoneC;
    int selectZoneL;
	// выбранный сенсор
	int selectSensor;
	// есть выбранная зона
	bool isZoneMarkedT;
	bool isZoneMarkedC;
	bool isZoneMarkedL;
	// цвет выбранной зоны
	TColor colorMark;
    //старые цвета
	TColor oldColorC0;
	TColor oldColorL0;
	TColor oldColorT0;
	TColor oldColorT1;
	int oldSelectZoneT;
	int oldSelectZoneC;
	int oldSelectZoneL;
	//int oldZone;
	//TColor oldColor;
    TColor markColor;
	TADOQuery *pQueryShowListTubes;
    int RecalcData(int _numFusion,int _numTube);
public: // User declarations
	// -------------------
	__fastcall TfmShowZones(TComponent* Owner,TADOQuery *_queryShowListTubes);
    //заполнение чартов

	int ShowZones();
	//заполнение заголовка
	int FillTitle(int _numFuzion,int _numTube);
	int numTubeShow; // указатель на трубу
    int numFusionShow; // указатель на трубу

};

// ---------------------------------------------------------------------------
extern PACKAGE TfmShowZones *fmShowZones;
// ---------------------------------------------------------------------------
#endif
