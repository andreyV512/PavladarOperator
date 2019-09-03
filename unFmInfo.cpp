// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "unFmInfo.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmInfo *fmInfo;

// ---------------------------------------------------------------------------
__fastcall TfmInfo::TfmInfo(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TfmInfo::FormCreate(TObject *Sender) {
	int err = 0;
	__int64 spaceF = 0;
	__int64 spaceT = 0;
	double perc;
	double szDb;
	AnsiString strIp;
	AnsiString current_dir;
	AnsiString strSql;
	// TStringDynArray sda;
	try {
		// получим адрес и посмотрим место на текущем диске - откуда запущена программа
		TExtFunction::GetIP_MAC(strIp);
		lbeIp4->Text = strIp;
		GetLogicalDrives();
		spaceF = (__int64)DiskFree(0) / 1024 / 1024;
		lbeFreeSpaceM->Text = IntToStr((int)spaceF) + " Mb";
		spaceT = (__int64)DiskSize(0) / 1024 / 1024;
		perc = (double)spaceF / spaceT * 100.0;
		lbeFreeSpaceP->Font->Color = clBlack;
		lbeFreeSpaceP->Color = clMoneyGreen;
		if (perc < 10) {
			lbeFreeSpaceP->Color = clRed;
		}
		else {
			if (perc < 20) {
				lbeFreeSpaceP->Color = clYellow;
			}
			else {
				lbeFreeSpaceP->Color = clMoneyGreen;
			}
		}

		lbeFreeSpaceP->Text = FloatToStrF(perc, ffFixed, 4, 2) + " %";
		// -----------------------------
		strSql = "SELECT [dbo].[GetDBSizeMb]() as F1";
		szDb = SqlDBModule->GetDoubleFromFunctionSql(strSql, err);
		lbeSzDB->Text = FloatToStrF(szDb, ffFixed, 6, 2);
		double limit = 10.0; // 10 Gb
		if (szDb > ((limit - 1) * 1024)) {
			lbeFreeSpaceP->Color = clRed;
		}
		else {
			if (szDb > ((limit - 2) * 1024)) {
				lbeFreeSpaceP->Color = clYellow;
			}
			else {
				lbeFreeSpaceP->Color = clMoneyGreen;
			}
		}
	}
	catch (Exception *ex) {
		err = -2;
		TLog::ErrFullSaveLog(ex);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);

	}
}
// ---------------------------------------------------------------------------
