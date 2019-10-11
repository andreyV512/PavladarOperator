// ---------------------------------------------------------------------------

#pragma hdrstop

#include "ThreadWork.h"
#include <IOUtils.hpp>
#include "unTExtFunction.h"
#include "unSQLDbModule.h"
#include "unTGlSettings.h"
// ---------------------------------------------------------------------------
#include <Math.hpp>
// #include <math.h>
#pragma package(smart_init)

// ----конструктор - переносим внешние переменные на внутренние---------------
__fastcall ThreadWork::ThreadWork(bool _pisWork, TBitBtn *_pbbtMode, TBitBtn *_pbbtCounter) {
	try {
		pbbtMode = _pbbtMode;
		isWork = _pisWork;
		int err = 0;
		counter = 0;
		critSect = new TCriticalSection();

		// Synchronize(UpdateControlsAndSignals);
		// UpdateControlsAndSignals();
	}
	catch (Exception *ex) {
		TLog::ErrFullSaveLog(ex);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
}

// ---------------------------------------------------------------------------
__fastcall ThreadWork::~ThreadWork(void) {
	delete critSect;
	Terminate();
	WaitFor();
}

//
void __fastcall ThreadWork::UpdateControlsAndSignals() {
	int err = 0;
	try {
		bool isReady = (bool)SqlDBModule->GetIntFieldSQL("flags", "isReady", "isActual=1", 0, err);
		//int repeatControl = TGlSettings::repeatControl;

		if (isReady) {
			// counter++;
			// pbbtCounter->Caption = IntToStr(counter);
			// pbbtCounter->Refresh();
			pbbtMode->Font->Color = clGreen;
		}
		else {
			// counter--;
			counter++;
			// pbbtCounter->Caption = IntToStr(counter);
			// pbbtCounter->Refresh();
			pbbtMode->Font->Color = clBlack;
		}
		//----------------------
	
		Application->ProcessMessages();
	}
	catch (Exception *ex) {
		TLog::ErrFullSaveLog(ex);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
}

// -----запуск потока работы--------------------------------------------------
void __fastcall ThreadWork::Execute() {
	while (true) {
		if (isWork) {
			Sleep(1000);
			// SetCaption();
			Synchronize(UpdateControlsAndSignals);
		}
		else {
			break;
		}
	}
}

// ---------------------------------------------------------------------------
// void ThreadWork::Post(WPARAM _w, LPARAM _l) {
// // PostMessage(, WM_USER + 101, 33, 0);
// if (PostMessage(Application->Handle, pGlobalSettings->threadMsg, _w, _l) == 0)
// TExtFunction::FATAL("ThreadOnLine::Post: не могу послать сообщение");
// AnsiString a = "ThreadOnLine::Post: послали ";
// a += _w;
// a += " ";
// a += _l;
// TProtocol::ProtocolSave(a);
// }

void ThreadWork::PostMsg(UINT _msg, WPARAM _wp, LPARAM _lp) {
	// PostMessage(, WM_USER + 101, 33, 0);
	AnsiString a = "";
	if (PostMessage(Application->Handle, _msg, _wp, _lp) == 0) {
		a = "ThreadOnLine::Post: не могу послать сообщение";
		TLog::SaveStrMsgLog(a);
		TExtFunction::FATAL(a);
	}
	else {
		a = "ThreadOnLine::Post: послали ";
		a += _msg;
		a += " ";
		a += _wp;
		a += " ";
		a += _lp;
		TLog::SaveStrMsgLog(a);
	}

}

// void ThreadWork::ErrFinally(AnsiString _msg, bool* _Collect, bool* _result) {
// Finally();
// *_Collect = false;
// *_result = false;
// //TProtocol::ProtocolSave(_msg);
// SetMsg(_msg);
// // Post(UPDATE_STATUS);
// PostMsg(pGlobalSettings->Msg_UPDATE_STATUS);
// }

void ThreadWork::SetCaption() {
	if (critSect) {
		critSect->Enter();
		pbbtCounter->Caption = IntToStr(counter);
		critSect->Leave();
	}
	else {
		//
	}

}
//
//
//// ----------------------------------------------------------------------------
// void ThreadWork::SetSG(CSG _csg) {
// critSect->Enter();
// csg = _csg;
// critSect->Leave();
// }
