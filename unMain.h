// ---------------------------------------------------------------------------

#ifndef unMainH
#define unMainH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include "unFmBackup.h"
// -----------
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
// -----------
#include "unSQLDbModule.h"
#include "unTExtFunction.h"
#include "ABOUT_NTC_NK_URAN.h"
#include "unFmMessage.h"
#include "unSQLDbModule.h"
#include "unTUtils.h"
#include <SysUtils.hpp>
#include "unSetDirectory.h"
#include "unShowListTubes.h"
#include "unTGlSettings.h"
#include <Vcl.DBCtrls.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Data.Win.ADODB.hpp>
#include <winsock.h>
#include <Vcl.AppEvnts.hpp>
#include <Xml.Win.msxmldom.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.Dialogs.hpp>
#include <vector>
#include <iterator>
using namespace std;
// ---------
#include "unTGlSettings.h"
#include "unFmInfo.h"
#include "unFmGSettings.h"
#include "unFmReport.h"
#include "ThreadWork.h"
#include "unFmModifyRecord.h"
#include <map>

// ---------------------------------------------------------------------------
class TfmMain : public TForm {
__published: // IDE-managed Components
	TMainMenu *MainMenu;
	TMenuItem *menuFile;
	TMenuItem *menuExit;
	TMenuItem *menuSettings;
	TMenuItem *menuTools;
	TMenuItem *menuhelp;
	TMenuItem *menuAbout;
	TPanel *PanelTopChoice;
	TComboBox *cbxTubesTypeSize;
	TComboBox *cbxSteelGrades;
	TComboBox *cbxNormDocs;
	TLabeledEdit *lbeNumFusion;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TComboBox *cbxOperators;
	TLabel *Label5;
	TComboBox *cbxWorkShifts;
	TComboBox *cbxSops;
	TLabel *Label6;
	TPanel *PanelButtonsTop;
	TBitBtn *bbtSave;
	TBitBtn *bbtReady;
	TBitBtn *bbtStop;
	TMenuItem *mnuOperators;
	TMenuItem *menuWorkShifts;
	TMenuItem *menuTubesTypeSize;
	TMenuItem *menuSteelGrades;
	TMenuItem *menuSops;
	TMenuItem *menuNormDocs;
	TMenuItem *menuListTubes;
	TMenuItem *menuBackup;
	TMenuItem *mnuArhive;
	TPanel *PanelClient;
	TBitBtn *bbtlistTubes;
	TMenuItem *menuExtInfo;
	TTimer *TimerUpdateState;
	TApplicationEvents *ApplicationEvents;
	TBitBtn *bbtBrakThick;
	TBitBtn *bblBrakLong;
	TBitBtn *bbtBrakCross;
	TBitBtn *bbtBrakALL;
	TBitBtn *bbtCountControl;
	TBitBtn *bbtMode;
	TMenuItem *menuGSettings;
	TTimer *timerFreeSpase;
	TPanel *pnlButtons;
	TBitBtn *BitBtn1;
	TXMLDocument *XMLDocument;
	TBitBtn *bbtForseReady;
	TADOQuery *queryXML;
	TPanel *pnlMsg;
	TPanel *pnlLeft;
	TListBox *lbxInfo;
	TPanel *PanelCross;
	TChart *chartCross;
	TBarSeries *BarSeries1;
	TFastLineSeries *Series3;
	TFastLineSeries *Series6;
	TPanel *PanelLong;
	TChart *chartLong;
	TBarSeries *Series2;
	TFastLineSeries *Series4;
	TFastLineSeries *Series5;
	TPanel *PanelThick;
	TChart *chartThick;
	TBarSeries *BarSeries2;
	TBarSeries *Series1;
	TFastLineSeries *Series7;
	TFastLineSeries *Series8;
	TSplitter *SplitterMid;
	TSplitter *SplitterTop;
	TPanel *pnlCharts;
	TADOQuery *queryTSize;
	TBitBtn *bbtTest;
	TBitBtn *bbtCounter;
	TMenuItem *menuRepeatControl;
	TMenuItem *menuSOP;
	TPanel *pnlTopLeft;
	TADOQuery *queryClear;
	TMenuItem *menuShowLog;
	TTimer *timerBackup;
	TMenuItem *menuViewArh;
	TOpenDialog *dialogOpenArh;
	TMenuItem *menuModify;
	TMenuItem *menuViewLog;
	TCheckBox *cbCross;
	TCheckBox *cbLong;
	TCheckBox *cbThick;

	void __fastcall menuExitClick(TObject *Sender);
	void __fastcall menuAboutClick(TObject *Sender);
	void __fastcall bbtReadyClick(TObject *Sender);
	void __fastcall bbtStopClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall bbtSaveClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall mnuOperatorsClick(TObject *Sender);
	void __fastcall menuWorkShiftsClick(TObject *Sender);
	void __fastcall menuTubesTypeSizeClick(TObject *Sender);
	void __fastcall menuSteelGradesClick(TObject *Sender);
	void __fastcall menuSopsClick(TObject *Sender);
	void __fastcall menuNormDocsClick(TObject *Sender);
	void __fastcall menuListTubesClick(TObject *Sender);
	void __fastcall menuBackupClick(TObject *Sender);
	void __fastcall menuExtInfoClick(TObject *Sender);
	void __fastcall TimerUpdateStateTimer(TObject *Sender);
	void __fastcall ApplicationEventsMessage(tagMSG &Msg, bool &Handled);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall menuGSettingsClick(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall cbxTubesTypeSizeSelect(TObject *Sender);
	void __fastcall timerFreeSpaseTimer(TObject *Sender);
	void __fastcall bbtForseReadyClick(TObject *Sender);
	void __fastcall chartCrossClickSeries(TCustomChart *Sender, TChartSeries *Series, int ValueIndex, TMouseButton Button,
		TShiftState Shift, int X, int Y);
	void __fastcall chartLongClickSeries(TCustomChart *Sender, TChartSeries *Series, int ValueIndex, TMouseButton Button, TShiftState Shift,
		int X, int Y);
	void __fastcall chartThickClickSeries(TCustomChart *Sender, TChartSeries *Series, int ValueIndex, TMouseButton Button,
		TShiftState Shift, int X, int Y);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall menuRepeatControlClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall menuSOPClick(TObject *Sender);
	void __fastcall menuShowLogClick(TObject *Sender);
	void __fastcall bbtTestClick(TObject *Sender);
	void __fastcall timerBackupTimer(TObject *Sender);
	void __fastcall menuViewArhClick(TObject *Sender);
	void __fastcall menuModifyClick(TObject *Sender);
	void __fastcall menuViewLogClick(TObject *Sender);
	void __fastcall menuSetReadySecClick(TObject *Sender);

protected: // User declarations
	// считаем прошлые установки
	typedef   void(TfmMain::*TcheckPros)(int, int);
	std::map<AnsiString, TcheckPros>checkPros;

	void InsertCrossRow(int, int);
	void InsertLongRow(int, int);
	void InsertThickRow(int, int);

	int LoadInitSettings();
	int ReLoadInitSettings();
	// get and send IP & MAC
	int GetAndSendIP_MAC();
	// вычислим индекс по значанию ключевого поля
	int GetIndexCbx(int _rec_id, TComboBox *_cbx);
	// int id_tube;//индекс трубы
	// int numFusion; //индекс плавки
	int FillComboboxses();
	// int testCounter;
	// int intTstFuz1;
	// int intTstFuz2;
	int CreateTables(int _numFusion, int _numTube);
	int CheckBrakCross(int _numFusion, int _numTube, int &_status);
	int CheckBrakLong(int _numFusion, int _numTube, int &_status);
	int CheckBrakThick(int _numFusion, int _numTube, int &_status);
	int CheckBrakCount(int _numFusion);
	int GetBordersC(int _indTypeSize, int _numFusion, int _numTube);
	int GetBordersL(int _indTypeSize, int _numFusion, int _numTube);
	int GetBordersT(int _indTypeSize, int _numFusion, int _numTube);
	int GetNodesBorders(int _indTypeSize, int _numFusion, int _numTube);

	// ! массивы итоговых значений по зонам
	vector<double>dataLong;
	vector<double>dataCross;
	vector<vector<double> >dataThickMax;
	vector<vector<double> >dataThickMin;
	// ! массив значений по датчикам
	vector<vector<double> >sensorsDataLong;
	vector<vector<double> >sensorsDataCross;
	vector<vector<double> >sensorsDataThickMin;
	vector<vector<double> >sensorsDataThickMinR;
	vector<vector<double> >sensorsDataThickMax;
    vector<vector<double> >sensorsDataThickMaxR;
	// вектор по всем датчикам зоны для поиска максимума
	vector<double>vecMaxCh;
	vector<double>vecMaxChR;
	// зона.датчик.измерение
	// vector<vector<vector<double> > >Source_Data;
	int GetDataThick(int _numFusion, int _numTube,double _thresholdTNominal,double _thresholdTUp,double _thresholdTDown);
	int GetDataCross(int _numFusion, int _numTube,double _thresholdC1,double _thresholdC2);
	int GetDataLong(int _numFusion, int _numTube,double _thresholdL1,double _thresholdL2);
	int RecalcData(int _numFusion, int _numTube,double _thresholdTNominal,double _thresholdTUp,double _thresholdTDown,
 double _thresholdC1,double _thresholdC2,double _thresholdL1,double _thresholdL2);

	ThreadWork *pThreadWork;
	//int currentZone;
	int InitCharts();
	int ViewCurrentBorders(int _numFusion, int _numTube);
	int selectZoneT;
	int selectZoneC;
    int selectZoneL;
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
	int countZones;
	int countControls;
	int errT;
	int errC;
	int errL;
	LongWord secYearBeginWait;
	bool continueWait;
    int numRepeatControl;

    void __fastcall CheckBox(TObject *Sender);
public: // User declarations
	__fastcall TfmMain(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TfmMain *fmMain;
// ---------------------------------------------------------------------------
#endif
