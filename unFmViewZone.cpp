// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <Math.hpp>
#include "unFmViewZone.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmViewZone *fmViewZone;
// ---------------------------------------------------------------------------



__fastcall TfmViewZone::TfmViewZone(TComponent* Owner) : TForm(Owner) {

	KeyPreview = true;
	// colorsSeries[]={ clMaroon, clGreen, clOlive, clNavy, clPurple, clTeal, clSilver, clRed, clLime, clYellow, clBlue, clAqua, clFuchsia, clCream,clWhite, clBlack};
}


// ---------------------------------------------------------------------------
// закроем форму по Esc
void __fastcall TfmViewZone::FormKeyPress(TObject *Sender, wchar_t &Key) {
	if (Key == VK_ESCAPE)
		Close();
}

// ---------------------------------------------------------------------------
void TfmViewZone::SetInner(bool _v) {
	if (_v)
		ChartVZ->LeftAxis->Minimum = -100;
	else
		ChartVZ->LeftAxis->Minimum = 0;
}

// ---------------------------------------------------------------------------
void __fastcall TfmViewZone::FormDestroy(TObject *Sender) {
	PostMessage(Application->Handle,TGlSettings::msgFmViewZone,0,0);
}

// ---------------------------------------------------------------------------
void TfmViewZone::SetCaption(AnsiString _cap) {
	Caption = title + _cap;
}

void TfmViewZone::SetMetric(double _start, double _zone_size) {
	start = _start;
	zone_size = _zone_size;
	if (start < 0)
		start = 0;
	if (zone_size < 0)
		zone_size = 0;
}

void TfmViewZone::Clear(void) {
	for (int i = 0; i < ChartVZ->SeriesCount(); i++)
		ChartVZ->Series[i]->Clear();
	Arrow->Clear();
	Mark->Clear();
};

// ---------------------------------------------------------------------------
void TfmViewZone::SetBorder(TLineSeries* _series, double _level, TColor _color) {
	_series->Clear();
	_series->AddXY(0, _level, "", _color);
	_series->AddXY(BarOut->MaxXValue(), _level, "", _color);
}

void TfmViewZone::SetCurrPoint(int _curr_zone, int _curr_sens, bool _IsLinear) {
	curr_zone = _curr_zone;
	curr_sens = _curr_sens;
	IsLinear = _IsLinear;
}
// ---------------------------------------------------------------------------

void TfmViewZone::ViewEtalonCheck() {
	//
}

// ---------------------------------------------------------------------------
int TfmViewZone::CalcMeasFromRange(int _x) {
	//
}

// ---------------------------------------------------------------------------
void TfmViewZone::SetBrackBorder(int _startMeas, int _finalMeas, double _Border, TColor _color, AnsiString _mark) {
	Arrow->AddArrow(_startMeas, _Border, _finalMeas, _Border, "", _color);
	Mark->AddBubble(_startMeas + (_finalMeas - _startMeas) / 2, _Border, 5, _mark, _color);
}
// ---------------------------------------------------------------------------

void __fastcall TfmViewZone::cbEtalonTubeDefectsKeyUp(TObject *Sender, WORD &Key, TShiftState Shift) {
	if (Key != VK_ESCAPE) {
		cbEtalonTubeDefects->ItemIndex = curr_defect;
		KeyUpFlag = true;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfmViewZone::ChartVZMouseMove(TObject *Sender, TShiftState Shift, int X, int Y) {
	//
}

// ---------------------------------------------------------------------------

int __fastcall TfmViewZone::PrepareZoneToShow(int _selZone, int _selSensor, AnsiString _title) {

	//serg
	int err = -1;
	// TZoneData selZone=TZoneData
	try {

	}
	catch (Exception *ex) {
		err = -2;
		TLog::ErrFullSaveLog(ex);
		// TExtFunction::UpdateStatusBar(StatusBarBottom, strStatus, ex->Message, programSettings.colorBrak);
		// MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);

	}
	return err;

}

int __fastcall TfmViewZone::PrepareSensor(int _selZone, int _selSensor) {
	int err = -1;
	// TZoneData selZone=TZoneData
	try {
		// -
		err = 0;
	}
	catch (Exception *ex) {
		err = -2;
		TLog::ErrFullSaveLog(ex);
		// TExtFunction::UpdateStatusBar(StatusBarBottom, strStatus, ex->Message, programSettings.colorBrak);
		// MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);

	}
	return err;
}

void __fastcall TfmViewZone::FormShow(TObject * Sender) {
	int err = -1;
	try {

	}
	catch (Exception *ex) {
		err = -2;
		TLog::ErrFullSaveLog(ex);
		// TExtFunction::UpdateStatusBar(StatusBarBottom, strStatus, ex->Message, programSettings.colorBrak);
		// MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfmViewZone::ZoomUpClick(TObject *Sender) {
	ChartVZ->LeftAxis->Maximum = (int)ChartVZ->LeftAxis->Maximum / 1.5;
	ChartVZ->LeftAxis->Minimum = (int)ChartVZ->LeftAxis->Minimum / 1.5;
}
// ---------------------------------------------------------------------------

void __fastcall TfmViewZone::mnuZoomResetClick(TObject *Sender) {
	ChartVZ->LeftAxis->Maximum = savedLeftAxisMaximum;
	ChartVZ->LeftAxis->Minimum = savedLeftAxisMinimum;
}
// ---------------------------------------------------------------------------

void __fastcall TfmViewZone::ZoomDownClick(TObject *Sender) {
	ChartVZ->LeftAxis->Maximum = (int)ChartVZ->LeftAxis->Maximum * 1.5;
	ChartVZ->LeftAxis->Minimum = (int)ChartVZ->LeftAxis->Minimum * 1.5;
}
// ---------------------------------------------------------------------------
