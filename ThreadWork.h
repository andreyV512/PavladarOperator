#ifndef ThreadWorkH
#define ThreadWorkH
#include <Graphics.hpp>
#include <Vcl.Grids.hpp>
#include "unTUtils.h"
#include <SyncObjs.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>

class ThreadWork : public TThread {
protected:
	void __fastcall Execute();

public:
	__fastcall ThreadWork(bool _pisWork,TBitBtn *_pbbtMode,TBitBtn *_pbbtCounter);
	__fastcall ~ThreadWork(void);
	// static const WPARAM REDRAW = 0;
	// static const WPARAM COMPUTE = 1;
	// static const WPARAM UPDATE_STATUS = 3;
	// static const WPARAM COMPLETE = 5;
	// static const WPARAM NEXT_TUBE = 6;
	// static const WPARAM ALARM = 99;
	AnsiString GetMsg(void);
    void SetCaption();
	// ”становить указанный результат расчета //todo а нужно ли?
	// void SetCalc(); // (bool _IsBrak);
	// ---------------
	bool isWork;
private:
   TBitBtn *pbbtMode;
   TBitBtn *pbbtCounter;
   TCriticalSection* critSect;
	void PostMsg(UINT _msg, WPARAM _wp = 0, LPARAM = 0);
	// обновим сигналы синхронизиру€ с VCL
	void __fastcall UpdateControlsAndSignals();
    int counter;
	int lastErr;
};
// ---------------------------------------------------------------------------

#endif
