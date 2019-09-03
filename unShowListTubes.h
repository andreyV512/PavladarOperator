// ---------------------------------------------------------------------------

#ifndef unShowListTubesH
#define unShowListTubesH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Data.Win.ADODB.hpp>
#include "unSQLDbModule.h"
#include <Vcl.Menus.hpp>
#include "unFmShowZones.h"
#include "unTGlSettings.h"
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <System.DateUtils.hpp>
#include "unFmReport.h"

// ---------------------------------------------------------------------------
class TfmShowListTubes : public TForm {
__published: // IDE-managed Components
	TDataSource *DataSource;
	TDBNavigator *DBNavigator1;
	TPanel *PanelBottom;
	TDBGrid *DBGridListTubes;
	TADOQuery *queryShowTube;
	TPopupMenu *PopupMenuSLT;
	TMenuItem *menuShowZones;
	TPanel *PanelFilter;
	TLabel *Label8;
	TLabel *Label9;
	TComboBox *cbxFTubesTypeSize;
	TBitBtn *bbtFiltered;
	TComboBox *cbxSteelGrades;
	TLabeledEdit *lbeFuzion;
	TLabeledEdit *lbeNumTube;
	TComboBox *cbxOperators;
	TLabel *Label1;
	TLabel *Label2;
	TComboBox *cbxNormDocs;
	TComboBox *cbxSops;
	TLabel *Label3;
	TADOQuery *queryShowListTubes;
	TBitBtn *bbtResetFiltr;
	TPanel *PanelDates;
	TDateTimePicker *dtpBegin;
	TDateTimePicker *dtpEnd;
	TPanel *Panel1;
	TLabel *Label4;
	TLabel *Label5;
	TGroupBox *grbParams;
	TMenuItem *mnuPrintSelected;
	TCheckBox *cbxBrackT;
	TCheckBox *cbxBrackC;
	TCheckBox *cbxBrackL;
	TCheckBox *cbxBrackAll;
	TTimer *timerRefresh;
	TCheckBox *cbxWithSOP;
	// --------------------------

	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall menuShowZonesClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall bbtFilteredClick(TObject *Sender);
	void __fastcall bbtResetFiltrClick(TObject *Sender);
	void __fastcall mnuPrintSelectedClick(TObject *Sender);
	void __fastcall DBGridListTubesCellClick(TColumn *Column);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall cbxBrackTClick(TObject *Sender);
	void __fastcall cbxBrackCClick(TObject *Sender);
	void __fastcall cbxBrackLClick(TObject *Sender);
	void __fastcall timerFilterTimer(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall DBGridListTubesDblClick(TObject *Sender);
	void __fastcall timerRefreshTimer(TObject *Sender);
	void __fastcall queryShowListTubesAfterOpen(TDataSet *DataSet);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);

private: // User declarations
	int ShowZones(TObject *_sender);

	AnsiString strFilter;
	AnsiString strSqlGlobal;
	Word myYear, myMonth, dayYear;
	Word endYear, endMonth, endDayYear;
    int countRows1;
    int countRows2;
	int OutToRtf ();
	int OutToRtfStream();
	int numRec;
	public : // User declarations)
		__fastcall TfmShowListTubes(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TfmShowListTubes *fmShowListTubes;
// ---------------------------------------------------------------------------
#endif
