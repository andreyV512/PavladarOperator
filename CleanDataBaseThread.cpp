// ---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "CleanDataBaseThread.h"
#include "QueryMessageForm.h"
#include "unSQLDbModule.h"
#include "unMain.h"
#pragma package(smart_init)
// ---------------------------------------------------------------------------

// Important: Methods and properties of objects in VCL can only be
// used in a method called using Synchronize, for example:
//
// Synchronize(&UpdateCaption);
//
// where UpdateCaption could look like:
//
// void __fastcall CleanDataBaseThread::UpdateCaption()
// {
// Form1->Caption = "Updated in a thread";
// }
// ---------------------------------------------------------------------------

__fastcall CleanDataBaseThread::CleanDataBaseThread(void *f)
	: TThread(false), f(f) {
}

// ---------------------------------------------------------------------------
void __fastcall CleanDataBaseThread::Execute() {
	HANDLE sem = CreateSemaphore(0, 0, 1, L"CleanDataBaseThread");
	if (GetLastError() != ERROR_ALREADY_EXISTS) {
		SqlDBModule->queryQuick->Close();

		AnsiString query = "DELETE  FROM resultTubeShort";
		SqlDBModule->queryQuick->SQL->Text = query;
		SqlDBModule->queryQuick->ExecSQL();
		SqlDBModule->queryQuick->Close();

		query = "DBCC SHRINKDATABASE(buran9955Pa, 10)";
		SqlDBModule->queryQuick->SQL->Text = query;
		SqlDBModule->queryQuick->ExecSQL();
		SqlDBModule->queryQuick->Close();

		query = "UPDATE flags SET isBackupProcess = 0 WHERE rec_id=1";
		SqlDBModule->queryQuick->SQL->Text = query;
		SqlDBModule->queryQuick->ExecSQL();
		SqlDBModule->queryQuick->Close();
	}
	PostMessage(Application->Handle, WM_USER_PROC, (unsigned)CloseWindow, (unsigned)f);
	CloseHandle(sem);
	delete this;
}
// ---------------------------------------------------------------------------
void CleanDataBaseThread::CloseWindow(void *param)
{
	delete ((TMessageForm *)param);
}
