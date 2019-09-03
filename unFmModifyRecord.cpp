// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "unFmModifyRecord.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmModifyRecord *fmModifyRecord;

// ---------------------------------------------------------------------------
__fastcall TfmModifyRecord::TfmModifyRecord(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TfmModifyRecord::FormResize(TObject *Sender) {
	AnsiString strTmp = "";
	queryDelRestor->Close();
	queryDelRestor->SQL->Text =
		"SELECT dtmCreate,numFusion,numTube FROM resultTubeShort where  numFusion=:pnumFusion and numTube<0 order by numTube";
	queryDelRestor->Parameters->ParamByName("pnumFusion")->Value = TGlSettings::currFusion;
	queryDelRestor->Open();
	queryDelRestor->First();
	lbxDeleted->Clear();
	while (!queryDelRestor->Eof) {
		strTmp = "Дата ";
		strTmp += queryDelRestor->FieldByName("dtmCreate")->AsString;
		strTmp += " №П ";
		strTmp += queryDelRestor->FieldByName("numFusion")->AsString;
		strTmp += " №Т ";
		strTmp += queryDelRestor->FieldByName("numTube")->AsString;
		lbxDeleted->Items->Add(strTmp);
		queryDelRestor->Next();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfmModifyRecord::lbxDeletedClick(TObject *Sender) {
	int numItem = lbxDeleted->ItemIndex;
	bbtRestore->Enabled = true;
	delNumTube = queryDelRestor->FieldByName("numTube")->AsInteger;
	queryDelRestor->Close();
	queryDelRestor->SQL->Text = "SELECT (max(numTube)-1) as maxNumTube FROM resultTubeShort where numFusion=:pnumFusion and numTube>0";
	queryDelRestor->Parameters->ParamByName("pnumFusion")->Value = TGlSettings::currFusion;
	queryDelRestor->Open();
	edtRestore->Text = IntToStr(queryDelRestor->FieldByName("maxNumTube")->AsInteger);
	newNumTube = queryDelRestor->FieldByName("maxNumTube")->AsInteger;
	queryDelRestor->Close();
	fmModifyRecord->FormResize(fmModifyRecord);
	lbxDeleted->ItemIndex = numItem;
}
// ---------------------------------------------------------------------------

void __fastcall TfmModifyRecord::bbtRestoreClick(TObject * Sender) {
	if (lbxDeleted->ItemIndex < 0) {
		return;
	}
	else {
		// edtRestore->Text=IntToStr(queryDelRestor->FieldByName("numTube")->AsInteger;
		queryDelRestor->Close();
		queryDelRestor->SQL->Text = "update resultTubeShort set numTube=numTube+1 where numFusion=:pnumFusion and numTube>:pNewNumTube";
		queryDelRestor->Parameters->ParamByName("pnumFusion")->Value = TGlSettings::currFusion;
		queryDelRestor->Parameters->ParamByName("pNewNumTube")->Value = (newNumTube-1);
		// queryDelRestor->Parameters->ParamByName("pNewNumTube")->Value = tubeNew;
		queryDelRestor->ExecSQL();
		queryDelRestor->Close();
		queryDelRestor->SQL->Text = "update resultTubeShort set numTube=:pNewNumTube where numFusion=:pnumFusion and numTube=:pDelNumTube";
		queryDelRestor->Parameters->ParamByName("pnumFusion")->Value = TGlSettings::currFusion;
		queryDelRestor->Parameters->ParamByName("pDelNumTube")->Value = delNumTube;
		queryDelRestor->Parameters->ParamByName("pNewNumTube")->Value = newNumTube;
		queryDelRestor->ExecSQL();
		queryDelRestor->Close();
		fmModifyRecord->FormResize(fmModifyRecord);
		// if (tubeNew==0) {
		// tubeNew=-1;
		// }else{
		// //
		// }
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfmModifyRecord::bbtCloseClick(TObject * Sender) {
	fmModifyRecord->Close();
}
// ---------------------------------------------------------------------------

void __fastcall TfmModifyRecord::bbtModDelClick(TObject * Sender) {
	int tubeOld = 0;
	int tubeNew = 0;
	AnsiString strWhere = "";
	int err = 0;
	if (!TryStrToInt(edtDelete->Text, tubeOld)) {
		err = -2;

		MessageDlg(" Некорректный номер трубы \n Только целое число больше 0 !!!", mtError, TMsgDlgButtons() << mbOK, NULL);
		return;
	}
	else {
		if (tubeOld < 1) {
			err = -3;
			MessageDlg(" Некорректный номер трубы \n Только целое число больше 0 !!!", mtError, TMsgDlgButtons() << mbOK, NULL);
			return;
		}
		else {

		}
	}
	if (MessageDlg("ЗАПИСЬ ПО ТРУБЕ\n" + edtDelete->Text + "\n БУДЕТ ПОМЕЧЕНА, КАК УДАЛЕННАЯ! \n ПРОДОЛЖИТЬ?", mtWarning,
		TMsgDlgButtons() << mbOK << mbCancel, 0) == mrOk) {
		queryDelRestor->Close();
		queryDelRestor->SQL->Text = "update resultTubeShort set numTube=:pNewNumTube where numFusion=:pnumFusion and numTube=:pOldNumTube";
		queryDelRestor->Parameters->ParamByName("pnumFusion")->Value = TGlSettings::currFusion;
		queryDelRestor->Parameters->ParamByName("pOldNumTube")->Value = tubeOld;
		queryDelRestor->Parameters->ParamByName("pNewNumTube")->Value = -(tubeOld+10000);
		queryDelRestor->ExecSQL();
		if (queryDelRestor->RowsAffected==0) {
		   MessageDlg("Трубы с таким номером в плавке нет !!!", mtError, TMsgDlgButtons() << mbOK, NULL);
           return;
		}else{
			//
        }
        //SqlDBModule->ADOConnectionDB->CommitTrans();
		queryDelRestor->Close();

		// queryDelRestor->SQL->Text = "update resultTubeShort set numTube=:pNewNumTube where numFusion=:pnumFusion and numTube=:pOldNumTube";
		queryDelRestor->SQL->Text = "select numTube From resultTubeShort  where numFusion=:pnumFusion and numTube>:pOldNumTube order by numTube";
		 queryDelRestor->Parameters->ParamByName("pnumFusion")->Value = TGlSettings::currFusion;
		 queryDelRestor->Parameters->ParamByName("pOldNumTube")->Value = tubeOld;
		// queryDelRestor->Parameters->ParamByName("pNewNumTube")->Value = -tubeOld;
		delNumTube=-(tubeOld+10000);
		// queryDelRestor->ExecSQL();
		queryDelRestor->Open();
		queryDelRestor->First();
		int n = 0;
		strWhere = "numFusion=";
		strWhere += IntToStr(TGlSettings::currFusion);
		strWhere += " and numTube>";
		strWhere += IntToStr(tubeOld);
		while (!queryDelRestor->Eof) {
			//SqlDBModule->UpdIntSql("resultTubeShort", "numTube", tubeOld + n, strWhere);
			queryDelRestor->Edit();
			queryDelRestor->FieldByName("numTube")->Value=(tubeOld + n);
            queryDelRestor->Post();
			n++;
			queryDelRestor->Next();
		}
		MessageDlg("ЗАПИСЬ  ПОМЕЧЕНА, КАК УДАЛЕННАЯ №" + IntToStr(delNumTube), mtInformation, TMsgDlgButtons() << mbOK, 0);
		fmModifyRecord->FormResize(fmModifyRecord);
	}
	else {
		return;
	}
}
// ---------------------------------------------------------------------------
