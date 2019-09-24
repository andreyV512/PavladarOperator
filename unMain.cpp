// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "unMain.h"
#include <windows.h>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define strStatus="Статус";
TfmMain *fmMain;

// ---------------------------------------------------------------------------
__fastcall TfmMain::TfmMain(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TfmMain::menuExitClick(TObject *Sender) {
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall TfmMain::menuAboutClick(TObject *Sender) {
	fmAboutBox = new TfmAboutBox(this);
	fmAboutBox->ShowModal();
	fmAboutBox->Close();
	fmAboutBox = NULL;
}

// ---------------------------------------------------------------------------
	void TfmMain::InsertCrossRow(int _numTube, int _numFusion)
	{
    if(cbCross->Checked)for (int i = 0; i < TGlSettings::countSensorsCross; i++) {
				AnsiString strSql = "INSERT INTO resultCross(";
				strSql += "sensorNum, numTube,numFusion)";
				strSql += " VALUES(";
				strSql += IntToStr(i + 1);
				strSql += ",";
				strSql += IntToStr(_numTube);
				strSql += ",";
				strSql += IntToStr(_numFusion);
				strSql += ")";
				SqlDBModule->queryQuick->SQL->Text = strSql;
				SqlDBModule->queryQuick->ExecSQL();
				SqlDBModule->queryQuick->Close();
			}
			else
			{
				AnsiString strSql = "DELETE FROM resultCross WHERE numTube=";
				strSql += IntToStr(_numTube);
				strSql += " AND numFusion=";
				strSql += IntToStr(_numFusion);
				SqlDBModule->queryQuick->SQL->Text = strSql;
				SqlDBModule->queryQuick->ExecSQL();
				SqlDBModule->queryQuick->Close();
            }
	}
	void TfmMain::InsertLongRow(int _numTube, int _numFusion)
	{
    if(cbLong->Checked)for (int i = 0; i < TGlSettings::countSensorsLong; i++) {
			   AnsiString	strSql = "INSERT INTO resultLong(";
				strSql += "sensorNum, numTube,numFusion)";
				strSql += " VALUES(";
				strSql += IntToStr(i + 1);
				strSql += ",";
				strSql += _numTube;
				strSql += ",";
				strSql += _numFusion;
				strSql += ")";
				SqlDBModule->queryQuick->SQL->Text = strSql;
				SqlDBModule->queryQuick->ExecSQL();
				SqlDBModule->queryQuick->Close();
			}
            else
			{
				AnsiString strSql = "DELETE FROM resultLong WHERE numTube=";
				strSql += IntToStr(_numTube);
				strSql += " AND numFusion=";
				strSql += IntToStr(_numFusion);
				SqlDBModule->queryQuick->SQL->Text = strSql;
				SqlDBModule->queryQuick->ExecSQL();
				SqlDBModule->queryQuick->Close();
			}
	}
	void TfmMain::InsertThickRow(int _numTube, int _numFusion)
	{
    if(cbThick->Checked)for (int i = 0; i < TGlSettings::countRecordsThick; i++) {
			   AnsiString	strSql = "INSERT INTO resultThick(";
				strSql += "sensorNum, numTube,numFusion)";
				strSql += " VALUES(";
				strSql += IntToStr(i + 1);
				strSql += ",";
				strSql += _numTube;
				strSql += ",";
				strSql += _numFusion;
				strSql += ")";
				SqlDBModule->queryQuick->SQL->Text = strSql;
				SqlDBModule->queryQuick->ExecSQL();
				SqlDBModule->queryQuick->Close();
			}
            else
			{
				AnsiString strSql = "DELETE FROM resultThick WHERE numTube=";
				strSql += IntToStr(_numTube);
				strSql += " AND numFusion=";
				strSql += IntToStr(_numFusion);
				SqlDBModule->queryQuick->SQL->Text = strSql;
				SqlDBModule->queryQuick->ExecSQL();
				SqlDBModule->queryQuick->Close();
			}
	}

int TfmMain::CreateTables(int _numFusion, int _numTube) {
	AnsiString strSql = "";
	int err = 0;
	int tmpInt = 0;
	try {
		// защита от пересоздания
		SqlDBModule->queryQuick->Close();
		strSql = "SELECT numFusion from resultTubeShort where numTube>0 and numTube=:pnumTube and numFusion=:pnumFusion";
		SqlDBModule->queryQuick->SQL->Text = strSql;
		SqlDBModule->queryQuick->Parameters->ParamByName("pnumTube")->Value = _numTube;
		SqlDBModule->queryQuick->Parameters->ParamByName("pnumFusion")->Value = _numFusion;
		SqlDBModule->queryQuick->Open();
		if (SqlDBModule->queryQuick->RecordCount == 0) {
			SqlDBModule->queryQuick->Close();
			// таблицы для данных
			strSql = "INSERT INTO resultTubeShort(indTypeSize,indSteelGradeName,indNormDocName,indOperatorName,indWorkShiftName,indSopName";
			strSql += ",numTube,numFusion,dtmCreate,pathFileNameLong,countZones,speedTube,lengthTube ,resultL,resultT,resultC";
			strSql +=
				",thresholdC1,thresholdC2,thresholdL1,thresholdL2,thresholdTUp,thresholdTDown,thresholdTNominal,isEmpty,currentMagnetC";
			strSql += ",isSOP";
			strSql += ",currentMagnetL,currentMagnetT)";
			strSql += "VALUES (";
			strSql += ":pindTypeSize";
			strSql += ",:pindSteelGradeName";
			strSql += ",:pindNormDocName";
			strSql += ",:pindOperatorName";
			strSql += ",:pindWorkShiftName";
			strSql += ",:pindSopName";
			strSql += ",:pnumTube";
			strSql += ",:pcurrFusion";
			// strSql += ",'";
			// strSql += FormatDateTime("yyyy-dd-mm hh:mm:ss", Now());
			// strSql += "'";
			strSql += ",:pDateCreate";
			strSql += ",:ppathFileNameLong";
			strSql += ",:pcountZones";
			strSql += ",:pspeedTube,:plengthTube";
			strSql += ",0,0,0"; // браки
			strSql += ",:pthresholdC1,:pthresholdC2,:pthresholdL1,:pthresholdL2,:pthresholdTUp,:pthresholdTDown,:pthresholdTNominal";
			strSql += ",1"; // пустая
			strSql += ",:pcurrMagnetC";
			strSql += ",:pisSop";
			strSql += ",:pcurrMagnetL,:pcurrMagnetT)";
			SqlDBModule->queryQuick->SQL->Text = strSql;
			SqlDBModule->queryQuick->Parameters->ParamByName("pindTypeSize")->Value = TGlSettings::indTypeSize;
			SqlDBModule->queryQuick->Parameters->ParamByName("pindSteelGradeName")->Value = TGlSettings::indSteelGradeName;
			SqlDBModule->queryQuick->Parameters->ParamByName("pindNormDocName")->Value = TGlSettings::indNormDocName;
			SqlDBModule->queryQuick->Parameters->ParamByName("pindOperatorName")->Value = TGlSettings::indOperatorName;
			SqlDBModule->queryQuick->Parameters->ParamByName("pindWorkShiftName")->Value = TGlSettings::indWorkShiftName;
			SqlDBModule->queryQuick->Parameters->ParamByName("pindSopName")->Value = TGlSettings::indSopName;
			SqlDBModule->queryQuick->Parameters->ParamByName("pnumTube")->Value = _numTube;
			SqlDBModule->queryQuick->Parameters->ParamByName("pcurrFusion")->Value = _numFusion;
			SqlDBModule->queryQuick->Parameters->ParamByName("pDateCreate")->Value = Now();
			SqlDBModule->queryQuick->Parameters->ParamByName("ppathFileNameLong")->Value = "none";

			SqlDBModule->queryQuick->Parameters->ParamByName("pspeedTube")->Value = 0;
			SqlDBModule->queryQuick->Parameters->ParamByName("plengthTube")->Value = 0;
			SqlDBModule->queryQuick->Parameters->ParamByName("pthresholdC1")->Value = TGlSettings::thresholdC1;
			SqlDBModule->queryQuick->Parameters->ParamByName("pthresholdC2")->Value = TGlSettings::thresholdC2;
			// -----------
			SqlDBModule->queryQuick->Parameters->ParamByName("pthresholdL1")->Value = TGlSettings::thresholdL1;
			tmpInt = TGlSettings::thresholdL2;
			SqlDBModule->queryQuick->Parameters->ParamByName("pthresholdL2")->Value = TGlSettings::thresholdL2;
			// ------------
			SqlDBModule->queryQuick->Parameters->ParamByName("pthresholdTUp")->Value = TGlSettings::thresholdTUp;
			SqlDBModule->queryQuick->Parameters->ParamByName("pthresholdTDown")->Value = TGlSettings::thresholdTDown;
			tmpInt = TGlSettings::thresholdTNominal;
			SqlDBModule->queryQuick->Parameters->ParamByName("pthresholdTNominal")->Value = TGlSettings::thresholdTNominal;
			SqlDBModule->queryQuick->Parameters->ParamByName("pcountZones")->Value = TGlSettings::countZones;
			SqlDBModule->queryQuick->Parameters->ParamByName("pcurrMagnetC")->Value = TGlSettings::currMagnetC;
			// int tt = TGlSettings::isSOP;
			// if (TGlSettings::isSOP==1) {
			if (menuSOP->Checked) {
				// СОП
				SqlDBModule->queryQuick->Parameters->ParamByName("pisSop")->Value = 1;
			}
			else {
				SqlDBModule->queryQuick->Parameters->ParamByName("pisSop")->Value = 0;
			}
			SqlDBModule->queryQuick->Parameters->ParamByName("pcurrMagnetL")->Value = TGlSettings::currMagnetL;
			SqlDBModule->queryQuick->Parameters->ParamByName("pcurrMagnetT")->Value = TGlSettings::currMagnetT;
			SqlDBModule->queryQuick->ExecSQL();
			SqlDBModule->queryQuick->Parameters->Clear();
			// для возможности внешнего ключа старое
			// strSql = "SELECT @@IDENTITY AS 'LAST_ID';";
			// SqlDBModule->queryQuick->Close();
			// SqlDBModule->queryQuick->SQL->Text = strSql;
			// SqlDBModule->queryQuick->Open();
			// id_tube = SqlDBModule->queryQuick->FieldByName("LAST_ID")->AsInteger;
			// SqlDBModule->queryQuick->Close();
			// --------
			// 12 по поперечнику
			InsertCrossRow(_numTube, _numFusion);
			// 32 по продольнику
			InsertLongRow(_numTube, _numFusion);
			InsertThickRow(_numTube, _numFusion);

		}
		err = 0;
		// ----------------
	}
	catch (Exception *ex) {
		err = -1;
		TLog::ErrFullSaveLog(ex);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
	return err;
}

void __fastcall TfmMain::bbtReadyClick(TObject *Sender) {
	int err = 0;
	int rec_id = 0;
	AnsiString strSql = "";
	AnsiString strSqlWhere = "";
	try {
		bool isBackupProcess = SqlDBModule->GetBoolFieldSQL("flags", "isBackupProcess", "isActual=1", 0, err);
		if (isBackupProcess) {
			TExtFunction::ShowBigModalMessage("Идет создание резервной копии, работа невозможна!", clRed);
			return;
		}
		else {

		}

			if (menuRepeatControl->Checked) {
				if (MessageDlg("ВКЛЮЧЕН РЕЖИМ ПОВТОРНОГО КОНТРОЛЯ!\n ПРОДОЛЖИТЬ?", mtWarning, TMsgDlgButtons() << mbOK << mbCancel,
					0) == mrOk) {
					//
				}
				else {
					return;
				}
			}

			if (menuSOP->Checked) {
				if (MessageDlg("ВКЛЮЧЕН РЕЖИМ  СОП!\n ПРОДОЛЖИТЬ?", mtWarning, TMsgDlgButtons() << mbOK << mbCancel, 0) == mrOk) {
					//
				}
				else {
					return;
				}
			}
			else {
				//
			}
			if (MessageDlg("ТАКОЙ НОМЕР ПЛАВКИ УЖЕ БЫЛ\n ПРОДОЛЖИТЬ?", mtWarning, TMsgDlgButtons() << mbOK << mbCancel, 0) == mrOk) {
				// if (TGlSettings::isSOP == 1) {
				if (menuSOP->Checked) {
					// СОП
					strSql = "select max(numTube) as F1 from resultTubeShort where numTube>5000 and numFusion=" +
						IntToStr(TGlSettings::currFusion);
					TGlSettings::numTube = SqlDBModule->GetIntFromSql(strSql);
			  //		rc = TGlSettings::numTube;
					if (TGlSettings::numTube == 0) {
						TGlSettings::numTube = 5001;
					}
				}
				else {
					//
					strSql = "select max(numTube) as F1 from resultTubeShort where numTube>0 and numTube < 5000 and numFusion=" +
						IntToStr(TGlSettings::currFusion);
					TGlSettings::numTube = SqlDBModule->GetIntFromSql(strSql);
					UnicodeString NewString = IntToStr(TGlSettings::numTube);

                    AnsiString mess = "Номер трубы может быть больше 1 и меньше " + NewString + ":";
					if (InputQuery("Текущий номер трубы", mess.c_str(), NewString)) {
						int n = StrToInt(NewString);
                        NewString = "";
						if(n < TGlSettings::numTube)
						{
							if (InputQuery("Запрос пароля", "Введите пароль:", NewString)) {
							if (NewString != TGlSettings::passwordEdit) {
								MessageDlg("Неверный пароль!", mtError, TMsgDlgButtons() << mbOK, NULL);
								return;
							 }

							TGlSettings::numTube = n;
							AnsiString query = "DELETE FROM resultTubeShort WHERE numTube >=";
							query += IntToStr(TGlSettings::numTube);
							query += "and numFusion=";
							query += IntToStr(TGlSettings::currFusion);

							SqlDBModule->queryQuick->Close();
                            SqlDBModule->queryQuick->SQL->Text = query;
							SqlDBModule->queryQuick->ExecSQL();
							SqlDBModule->queryQuick->Close();
							CreateTables(TGlSettings::currFusion, TGlSettings::numTube);
						}
					}
					 }
				}

				if (TGlSettings::numTube == 0) {
					TGlSettings::numTube++;
				}
			}
		SqlDBModule->UpdBoolSql("flags", "isDataSendCompleet", 0, "isActual=1");
		TGlSettings::thresholdTNominal = SqlDBModule->GetFloatFieldSQL("tubesTypeSize", "tubeThick",
			"isActive = 1 and rec_id=" + IntToStr(TGlSettings::indTypeSize), 1, err);
		double a = TGlSettings::thresholdTNominal;
		if (TGlSettings::numTube > 5000) {
			bbtCountControl->Caption = "ПРОКОНТРОЛИРОВАНО: " + IntToStr(TGlSettings::numTube - 5001);
		}
		else {
			bbtCountControl->Caption = "ПРОКОНТРОЛИРОВАНО: " + IntToStr(TGlSettings::numTube - 1);
		}

		// BitBtn1->Enabled = true;
		PanelTopChoice->Enabled = false;
		bbtReady->Enabled = false;
		bbtSave->Enabled = false;
		// повторный контроль
		// if (TGlSettings::repeatControl) {
		if (menuRepeatControl->Checked) {
			TGlSettings::numTube = TGlSettings::repeatControlNumTube;
			strSqlWhere = "numFusion=" + IntToStr(TGlSettings::currFusion) + " and numTube=" + IntToStr(TGlSettings::numTube);
			SqlDBModule->queryQuick->Close();
			SqlDBModule->queryQuick->SQL->Text="DELETE FROM resultTubeShort WHERE numFusion=:pnumFusion and numTube=:pnumTube";
			SqlDBModule->queryQuick->Parameters->ParamByName("pnumFusion")->Value=TGlSettings::currFusion;
			SqlDBModule->queryQuick->Parameters->ParamByName("pnumTube")->Value=-(TGlSettings::numTube + 3000);
            SqlDBModule->queryQuick->ExecSQL();
			// прибили переконтролируемую создали вместо нее пустую
			SqlDBModule->UpdFloatSql("resultTubeShort", "numTube", -(TGlSettings::numTube + 3000), strSqlWhere);
			err = CreateTables(TGlSettings::currFusion, TGlSettings::numTube);
		}
		else {
			CreateTables(TGlSettings::currFusion, TGlSettings::numTube);
		}
		int aa = TGlSettings::numTube;
		// Sleep(2000);
		// serg5
		SqlDBModule->UpdIntSql("currentSettings", "ParamValueFloat", TGlSettings::currFusion, "UPPER(ParamName)=UPPER('numCurrFuzion')");
		SqlDBModule->UpdFloatSql("currentSettings", "ParamValueFloat", TGlSettings::numTube, "UPPER(ParamName)=UPPER('numCurrTube')");
		err = CheckBrakCount(TGlSettings::currFusion);
		// -----
		menuSettings->Enabled = false;
		menuTools->Enabled = false;
		TimerUpdateState->Enabled = true;
		SqlDBModule->UpdBoolSql("flags", "isWorkState", 1, "isActual=1");
		SqlDBModule->UpdIntSql("flags", "isReady", 1, NULL);
		//!!!  200
		Sleep(200);
		lbxInfo->AddItem("isReady=1", NULL);
		lbxInfo->AddItem("Выставляем готовность при старте", NULL);
		Application->ProcessMessages();
		InitCharts();
		// if (TGlSettings::isSOP == 1) {
		if (menuSOP->Checked) {
			bbtMode->Caption = "РЕЖИМ СОП";
			bbtMode->Font->Color = clBlue;
			lbxInfo->AddItem("РЕЖИМ СОП", NULL);
		}
		else {
			//
		}
		// pThreadWork = new ThreadWork(true, bbtMode, bbtCounter);
		secYearBeginWait = SecondOfTheYear(Now());
		continueWait = false;
		lbxInfo->AddItem("continueWait = false", NULL);
		TGlSettings::isWorkState = true;
		lbxInfo->AddItem("isWorkState = true", NULL);
		err = 0;
	}
	catch (Exception *ex) {
		err = -1;
		TLog::ErrFullSaveLog(ex);
		// AnsiString msg
		// programSettings.colorMSG = programSettings.colorBrak;
		// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
}
// ---------------------------------------------------------------------------
class __store_base__: public TfmMain
{
public:
	void operator()(int &err);
	bool IsExist(bool crossBool, bool longBool, bool thickBool);
	void Clean(const char *s);
	void CleanThick();
};
void __fastcall TfmMain::bbtStopClick(TObject *Sender) {
	int err = 0;
		if (errT > 0 || errC > 0 || errL > 0) {
				Application->ProcessMessages();
				TGlSettings::isWorkState = false;
				lbxInfo->AddItem("Отработали останов", NULL);
				SqlDBModule->UpdIntSql(" flags ", " isReady ", 0, NULL);
				Application->ProcessMessages();
			}

	PanelTopChoice->Enabled = true;
	bbtReady->Enabled = false;
	bbtStop->Enabled = false;
	bbtSave->Enabled = true;
	SqlDBModule->UpdIntSql("flags", "isReady", 0, NULL);
	lbxInfo->AddItem("isReady=0", NULL);
	// serg4
	TGlSettings::currFusionOld = TGlSettings::currFusion;
	// testCounter = 0;
	// BitBtn1->Enabled = false;
	menuSettings->Enabled = true;
	menuTools->Enabled = true;
	TGlSettings::isWorkState = false;
	SqlDBModule->UpdBoolSql("flags", "isWorkState", 0, "isActual=1");
	lbxInfo->AddItem("isWorkState=0", NULL);

	TimerUpdateState->Enabled = false;
	secYearBeginWait = SecondOfTheYear(Now());
	bool isReady = (bool)SqlDBModule->GetIntFieldSQL("flags", "isReady", "isActual=1", 0, err);
	lbxInfo->AddItem("Сброс готовности по останову", NULL);
	Application->ProcessMessages();
	bbtMode->Font->Color = clBlack;
	int xerr = 0;

	__store_base__ *sb = (__store_base__ *)this;
	if(sb->IsExist(cbCross->Checked, cbLong->Checked, cbThick->Checked)
		&& MessageDlg("ОСТАВИТЬ ТРУБУ БЕЗ РЕЗУЛЬТАТА ПО МОДУЛЮ?", mtWarning, TMsgDlgButtons() << mbOK << mbCancel, 0) == mrCancel
	)
	{
		(*sb)(xerr);
	}
	else
	{
	   if(cbCross->Checked) sb->Clean("resultCross");
	   if(cbLong->Checked) sb->Clean("resultLong");
	   if(cbThick->Checked) sb->CleanThick();
    }
}
class PathIni
{
	wchar_t path[1024];
public:
	PathIni()
	{
	   GetModuleFileName(0, path, 1024);
		int  len = wcslen(path);
		wcscpy(&path[len - 3], L"ini");
	}
	 wchar_t *operator()()
	 {
		 return path;
     }

};
void __fastcall TfmMain::CheckBox(TObject *Sender)
{
	TCheckBox *c = (TCheckBox *) Sender;
	wchar_t buf[32];
	_itow(c->Checked, buf, 10);
	WritePrivateProfileString(L"CheckBoxs", c->Name.c_str(), buf, PathIni()());
	(this->*checkPros[c->Name.c_str()])(TGlSettings::numTube, TGlSettings::currFusion);
}
// ---------------------------------------------------------------------------
void __fastcall TfmMain::FormCreate(TObject *Sender) {
//------------загружаем чекбоксы
	PathIni path;
	cbCross->Checked = 0 != GetPrivateProfileInt(L"CheckBoxs", cbCross->Name.c_str(), 0, path());
	cbLong->Checked = 0 != GetPrivateProfileInt(L"CheckBoxs", cbLong->Name.c_str(), 0, path());
	cbThick->Checked = 0 != GetPrivateProfileInt(L"CheckBoxs", cbThick->Name.c_str(), 0, path());

	cbCross->OnClick = CheckBox;
	cbLong->OnClick = CheckBox;
	cbThick->OnClick = CheckBox;

	checkPros[cbCross->Name.c_str()] = &TfmMain::InsertCrossRow;
	checkPros[cbLong->Name.c_str()] = &TfmMain::InsertLongRow;
	checkPros[cbThick->Name.c_str()] = &TfmMain::InsertThickRow;
//-----------------------
	int err = 0;
	lbeNumFusion->Text = " ";
	TGlSettings::passwordEdit = "1234";
	AnsiString strTmp = "";
	try {
		// SqlDBModule->FillComboBox("tubesTypeSize ", "typeSizeName", "isActive = 1 ", cbxTubesTypeSize);
		// SqlDBModule->FillComboBox("SteelGrades", "steelGradeName", "isActive = 1 ", cbxSteelGrades);
		// SqlDBModule->FillComboBox("NormDocs", "normDocName", " isActive = 1 ", cbxNormDocs);
		// SqlDBModule->FillComboBox("Operators", "operatorName", "isActive = 1 ", cbxOperators);
		// SqlDBModule->FillComboBox("WorkShifts", "workShiftName", "isActive = 1 ", cbxWorkShifts);
		// SqlDBModule->FillComboBox("Sops", "SopName", "isActive = 1 ", cbxSops);
		SqlDBModule->UpdBoolSql("flags", "isDataSendCompleet", 0, "isActual=1");
		SqlDBModule->UpdIntSql("flags", "isReady", 0, NULL);
		lbxInfo->AddItem("isReady=0", NULL);
		lbxInfo->AddItem("Сброс готовности при запуске ПО", NULL);
		Application->ProcessMessages();
		TGlSettings::currFusion = SqlDBModule->GetIntFieldSQL("currentSettings", "ParamValueFloat",
			"isActual = 1 and UPPER(ParamName) = UPPER('numCurrFuzion')", 0, err);
		lbeNumFusion->Text = IntToStr(TGlSettings::currFusion);
		FillComboboxses();
		LoadInitSettings();
		GetAndSendIP_MAC();
		// testCounter = 0;
	}
	catch (Exception *ex) {
		err = -1;
		TLog::ErrFullSaveLog(ex);
		// AnsiString msg
		// programSettings.colorMSG = programSettings.colorBrak;
		// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
	InitCharts();
	// TGlSettings::isSOP = 0;
	menuSOP->Checked = false;
}

void __fastcall TfmMain::ApplicationEventsMessage(tagMSG &Msg, bool &Handled) {
	int ind = 0;
	AnsiString str = "";
	// if (Msg.message == WM_HOTKEY) { // сообщение по включению редактирования настроек
	// if (Msg.wParam == 0x00E) // идентификатор наш
	// {
	// WinExec("hh ..\\..\\help\\Help.chm", SW_RESTORE);
	// Handled = true;
	// }
	// }
	switch (Msg.message) {

	case 12: {
			break;
		}
		// case TGlSettings::msgFmViewZone: {
		// str = "Сообщение: расчет треда, код: ";
		// // serg time
		// // UpdateStatus(str, str);
		// str += Msg.lParam;
		// // TLog::SaveStrMsgLog(str);
		// // if (threadWork != NULL)
		// break;
		// }
		// case TGlSettings::msgReloadSettings: {
		// str = "Сообщение: расчет треда, код: ";
		// break;
		// }
	default:
		break;
	}

	if (Msg.message == TGlSettings::msgReloadSettings) {
		// str = "Сообщение: расчет треда, код: ";
		// FormCreate(TObject *Sender);
		FillComboboxses();
		MessageDlg("Обновили справочники", mtInformation, TMsgDlgButtons() << mbOK, NULL);
	}
	else {
		//
	}

}

int TfmMain::FillComboboxses() {
	int err = 0;
	try {
		lbxInfo->AddItem("FillComboboxses()", NULL);
		SqlDBModule->FillComboBox("tubesTypeSize ", "typeSizeName", "isActive = 1 ", cbxTubesTypeSize);
		SqlDBModule->FillComboBox("SteelGrades", "steelGradeName", "isActive = 1 ", cbxSteelGrades);
		SqlDBModule->FillComboBox("NormDocs", "normDocName", " isActive = 1 ", cbxNormDocs);
		SqlDBModule->FillComboBox("Operators", "operatorName", "isActive = 1 ", cbxOperators);
		SqlDBModule->FillComboBox("WorkShifts", "workShiftName", "isActive = 1 ", cbxWorkShifts);
		SqlDBModule->FillComboBox("Sops", "SopName", "isActive = 1 ", cbxSops);
		SqlDBModule->UpdBoolSql("flags", "isDataSendCompleet", 0, "isActual=1");
		SqlDBModule->UpdIntSql("flags", "isReady", 0, NULL);
		lbxInfo->AddItem("Сброс готовности по обновлению справочников", NULL);
		Application->ProcessMessages();
	}
	catch (Exception *ex) {
		err = -1;
		TLog::ErrFullSaveLog(ex);
		// AnsiString msg
		// programSettings.colorMSG = programSettings.colorBrak;
		// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
	return err;
}

// ---------------------------------------------------------------------------
int TfmMain::LoadInitSettings() {
	// считаем прошлые установки
	int err = 0;
	int rec_id = 1;
	AnsiString strSql = "";
	try {
		lbxInfo->AddItem("LoadInitSettings()", NULL);
		// cbxTubesTypeSize->ItemIndex=
		// int GetIntFieldSQL(AnsiString _tableName, AnsiString _fieldName, AnsiString _where, int _default,int &err);
		TGlSettings::indTypeSize = SqlDBModule->GetIntFieldSQL("currentSettings", "ParamValueFloat",
			"isActual = 1 and UPPER(ParamName) = UPPER('indTypeSize')", 0, err);
		cbxTubesTypeSize->ItemIndex = GetIndexCbx(TGlSettings::indTypeSize, cbxTubesTypeSize);
		// --
		TGlSettings::indSteelGradeName = SqlDBModule->GetIntFieldSQL("currentSettings", "ParamValueFloat",
			"isActual = 1 and UPPER(ParamName) = UPPER('indSteelGradeName')", 0, err);
		cbxSteelGrades->ItemIndex = GetIndexCbx(TGlSettings::indSteelGradeName, cbxSteelGrades);
		// --
		TGlSettings::indNormDocName = SqlDBModule->GetIntFieldSQL("currentSettings", "ParamValueFloat",
			"isActual = 1 and UPPER(ParamName) = UPPER('indNormDocName')", 0, err);
		cbxNormDocs->ItemIndex = GetIndexCbx(TGlSettings::indNormDocName, cbxNormDocs);
		// --
		TGlSettings::indOperatorName = SqlDBModule->GetIntFieldSQL("currentSettings", "ParamValueFloat",
			"isActual = 1 and UPPER(ParamName) = UPPER('indOperatorName')", 0, err);
		cbxOperators->ItemIndex = GetIndexCbx(TGlSettings::indOperatorName, cbxOperators);
		// --
		TGlSettings::indWorkShiftName = SqlDBModule->GetIntFieldSQL("currentSettings", "ParamValueFloat",
			"isActual = 1 and UPPER(ParamName) = UPPER('indWorkShiftName')", 0, err);
		cbxWorkShifts->ItemIndex = GetIndexCbx(TGlSettings::indWorkShiftName, cbxWorkShifts);
		//
		TGlSettings::indSopName = SqlDBModule->GetIntFieldSQL("currentSettings", "ParamValueFloat",
			" isActual = 1 and UPPER(ParamName) = UPPER('indSopName')", 0, err);
		cbxSops->ItemIndex = GetIndexCbx(TGlSettings::indSopName, cbxSops);
		TGlSettings::countZones = SqlDBModule->GetIntFieldSQL("currentSettings", "ParamValueFloat",
			"isActual = 1 and UPPER(ParamName) =UPPER('countZones')", 0, err);
		// ------
		TGlSettings::countSensorsCross = SqlDBModule->GetIntFieldSQL("currentSettings", "ParamValueFloat",
			" isActual = 1 and UPPER(ParamName) =UPPER('countSensorsCross')", 0, err);
		// --------
		TGlSettings::countRecordsThick = SqlDBModule->GetIntFieldSQL("currentSettings", "ParamValueFloat",
			" isActual = 1 and UPPER(ParamName) =UPPER('countRecordsThick')", 0, err);
		// -----
		TGlSettings::countSensorsLong = SqlDBModule->GetIntFieldSQL("currentSettings", "ParamValueFloat",
			" isActual = 1 and UPPER(ParamName) =UPPER('countSensorsLong')", 0, err);
		// ---------настройки типоразмеров
		TGlSettings::thresholdTNominal = SqlDBModule->GetFloatFieldSQL("tubesTypeSize", "tubeThick",
			"isActive = 1 and rec_id=" + IntToStr(TGlSettings::indTypeSize), 3, err);
		lbxInfo->AddItem("ReLoadInitSettings()", NULL);
		ReLoadInitSettings();
		// ---
		// strSql = "SELECT [dbo].[GetCurrDemagnet] ('";
		// strSql += IntToStr(TGlSettings::indTypeSize);
		// strSql += "') as F1";
		// TGlSettings::currDemagnet = SqlDBModule->GetIntFromFunctionSql(strSql, err);
		// // -----------
		// strSql = "SELECT [dbo].[GetBorder1Cross] ('";
		// strSql += IntToStr(TGlSettings::indTypeSize);
		// strSql += "') as F1";
		// TGlSettings::thresholdC1 = SqlDBModule->GetIntFromFunctionSql(strSql, err);
		// int bb = TGlSettings::thresholdC1;
		// ----
		// TGlSettings::thresholdC1 = SqlDBModule->GetFloatFieldSQL("settingsTypeSz", "thresholdC1",
		// "isActual = 1 and indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 5, err);
		// TGlSettings::thresholdC2 = SqlDBModule->GetFloatFieldSQL("settingsTypeSz", "thresholdC2",
		// "isActual = 1 and indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 5, err);
		// TGlSettings::thresholdL1 = SqlDBModule->GetFloatFieldSQL("settingsTypeSz", "thresholdL1",
		// "isActual = 1 and indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 5, err);
		// TGlSettings::thresholdL2 = SqlDBModule->GetFloatFieldSQL("settingsTypeSz", "thresholdL2",
		// "isActual = 1 and indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 5, err);
		// TGlSettings::thresholdTDown = SqlDBModule->GetFloatFieldSQL("settingsTypeSz", "thresholdTDown",
		// "isActual = 1 and indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 5, err);
		// ------
		// TGlSettings::thresholdTUp = SqlDBModule->GetFloatFieldSQL("settingsTypeSz", "thresholdTUp",
		// "isActual = 1 and indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 5, err);
		// -------
	}
	catch (Exception *ex) {
		err = -1;
		lbxInfo->AddItem("TLog::ErrFullSaveLog(ex)", NULL);
		TLog::ErrFullSaveLog(ex);
		// AnsiString msg
		// programSettings.colorMSG = programSettings.colorBrak;
		// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
	return err;
}

int TfmMain::ReLoadInitSettings() {
	// обновление настроек
	int err = 0;
	int rec_id = 1;
	int tmpInt = 0;
	double tmpDouble = 0;
	AnsiString strSql = "";
	AnsiString strTmp = "";
	TReplaceFlags ReplaceFlags;
	lbxInfo->AddItem("ReLoadInitSettings()", NULL);
	try {
		strSql = "select max(numTube) as F1 from resultTubeShort where numTube>0 and numFusion=" + IntToStr(TGlSettings::currFusion);
		TGlSettings::numTube = SqlDBModule->GetIntFromSql(strSql);
		tmpInt = TGlSettings::numTube;
		// ---------настройки типоразмеров
		TGlSettings::thresholdTNominal = SqlDBModule->GetFloatFieldSQL("tubesTypeSize", "tubeThick",
			"isActive = 1 and rec_id=" + IntToStr(TGlSettings::indTypeSize), 3, err);
		// tmpInt = TGlSettings::thresholdTNominal;
		// ---
		strSql = "SELECT [dbo].[GetCurrMagnetT] ('";
		strSql += IntToStr(TGlSettings::indTypeSize);
		strSql += "') as F1";
		strTmp = SqlDBModule->GetStrFromFunctionSql(strSql, err);
		strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		TGlSettings::currMagnetT = StrToFloat(strTmp);
		// strTmp=SqlDBModule->GetStrFromFunctionSql(strSql, err);
		// strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		// TGlSettings::currMagnetC = StrToFloat(strTmp);
		if (err != 0 || TGlSettings::currMagnetT == -1) {
			// TGlSettings::currMagnetC = 5;
			// double GetFloatFieldSQL(AnsiString _tableName,AnsiString _fieldName, AnsiString _where, double _default,int &err);
			TGlSettings::currMagnetT = SqlDBModule->GetFloatFieldSQL("TypeSizesParams", "currMagnetT",
				"indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 5, err);
		}
		else {
			//
		}
		//
		// strSql = "SELECT [dbo].[GetBorderThickUpXML] (";
		// int aa = TGlSettings::currFusion;
		// strSql += IntToStr(TGlSettings::currFusion);
		// strSql += ",";
		// aa = TGlSettings::numTube - 1;
		// strSql += IntToStr(TGlSettings::numTube - 1);
		// strSql += ") as F1";
		strSql = "SELECT [dbo].[GetTzBorderTUp] (";
		strSql += IntToStr(TGlSettings::indTypeSize);
		strSql += ") as F1";
		strTmp = SqlDBModule->GetStrFromFunctionSql(strSql, err);
		strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		TGlSettings::thresholdTUp = StrToFloat(strTmp);
		if (err != 0 || TGlSettings::thresholdTUp == -1) {
			// TGlSettings::currMagnetC = 5;
			TGlSettings::thresholdTUp = SqlDBModule->GetFloatFieldSQL("TypeSizesParams", "thresholdTUp",
				"indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 20, err);
			tmpDouble = TGlSettings::thresholdTUp;
		}
		else {
			//
		}
		// ----------------------
		// strSql = "SELECT [dbo].[GetBorderThickDownXML] (";
		// strSql += IntToStr(TGlSettings::currFusion);
		// strSql += ",";
		// strSql += IntToStr(TGlSettings::numTube - 1);
		// strSql += ") as F1";
		strSql = "SELECT [dbo].[GetTzBorderTDown] (";
		strSql += IntToStr(TGlSettings::indTypeSize);
		strSql += ") as F1";
		strTmp = SqlDBModule->GetStrFromFunctionSql(strSql, err);
		strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		TGlSettings::thresholdTDown = StrToFloat(strTmp);
		if (err != 0 || TGlSettings::thresholdTDown == -1) {
			// TGlSettings::currMagnetC = 5;
			TGlSettings::thresholdTDown = SqlDBModule->GetFloatFieldSQL("TypeSizesParams", "thresholdTDown",
				"indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 12.5, err);
			tmpDouble = TGlSettings::thresholdTDown;
		}
		else {
			//
		}
		// -----------------------
		strSql = "SELECT [dbo].[GetCurrMagnetC] ('";
		strSql += IntToStr(TGlSettings::indTypeSize);
		strSql += "') as F1";
		strTmp = SqlDBModule->GetStrFromFunctionSql(strSql, err);
		strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		TGlSettings::currMagnetC = StrToFloat(strTmp);
		if (err != 0 || TGlSettings::currMagnetC == -1) {
			// TGlSettings::currMagnetC = 5;
			TGlSettings::currMagnetC = SqlDBModule->GetFloatFieldSQL("TypeSizesParams", "currMagnetC",
				"indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 5, err);
		}
		else {
			//
		}
		// ----------------
		// strSql = "SELECT [dbo].[GetBorderCrossXML1] (";
		// strSql += IntToStr(TGlSettings::currFusion);
		// strSql += ",";
		// strSql += IntToStr(TGlSettings::numTube - 1);
		// strSql += ") as F1";
		strSql = "SELECT [dbo].[GetTzBorderC1] (";
		strSql += IntToStr(TGlSettings::indTypeSize);
		strSql += ") as F1";
		strTmp = SqlDBModule->GetStrFromFunctionSql(strSql, err);
		strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		TGlSettings::thresholdC1 = StrToFloat(strTmp);
		if (err != 0 || TGlSettings::thresholdC1 == -1) {
			// TGlSettings::currMagnetC = 5;
			TGlSettings::thresholdC1 = SqlDBModule->GetFloatFieldSQL("TypeSizesParams", "thresholdC1",
				"indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 20, err);
			tmpDouble = TGlSettings::thresholdC1;
		}
		else {
			//
		}
		// --------------
		// strSql = "SELECT [dbo].[GetBorderCrossXML2] (";
		// strSql += IntToStr(TGlSettings::currFusion);
		// strSql += ",";
		// strSql += IntToStr(TGlSettings::numTube - 1);
		// strSql += ") as F1";
		strSql = "SELECT [dbo].[GetTzBorderC2] (";
		strSql += IntToStr(TGlSettings::indTypeSize);
		strSql += ") as F1";
		strTmp = SqlDBModule->GetStrFromFunctionSql(strSql, err);
		strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		TGlSettings::thresholdC2 = StrToFloat(strTmp);
		if (err != 0 || TGlSettings::thresholdC2 == -1) {
			// TGlSettings::currMagnetC = 5;
			TGlSettings::thresholdC2 = SqlDBModule->GetFloatFieldSQL("TypeSizesParams", "thresholdC2",
				"indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 10, err);
			tmpDouble = TGlSettings::thresholdC2;
		}
		else {
			//
		}
		// ---------------
		strSql = "SELECT [dbo].[GetCurrMagnetL] ('";
		strSql += IntToStr(TGlSettings::indTypeSize);
		strSql += "') as F1";
		strTmp = SqlDBModule->GetStrFromFunctionSql(strSql, err);
		strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		TGlSettings::currMagnetL = StrToFloat(strTmp);
		if (err != 0 || TGlSettings::currMagnetL == -1) {
			// TGlSettings::currMagnetC = 5;
			TGlSettings::currMagnetL = SqlDBModule->GetFloatFieldSQL("TypeSizesParams", "currMagnetL",
				"indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 5, err);
		}
		else {
			//
		}
		// strSql = "SELECT [dbo].[GetBorderLongXML1] (";
		// strSql += IntToStr(TGlSettings::currFusion);
		// strSql += ",";
		// strSql += IntToStr(TGlSettings::numTube - 1);
		// strSql += ") as F1";
		strSql = "SELECT [dbo].[GetTzBorderL1] (";
		strSql += IntToStr(TGlSettings::indTypeSize);
		strSql += ") as F1";
		strTmp = SqlDBModule->GetStrFromFunctionSql(strSql, err);
		strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		TGlSettings::thresholdL1 = StrToFloat(strTmp);
		if (err != 0 || TGlSettings::thresholdL1 == -1) {
			// TGlSettings::currMagnetC = 5;
			TGlSettings::thresholdL1 = SqlDBModule->GetFloatFieldSQL("TypeSizesParams", "thresholdL1",
				"indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 55, err);
			tmpDouble = TGlSettings::thresholdL1;
		}
		else {
			//
		}
		// ---------------
		// strSql = "SELECT [dbo].[GetBorderLongXML2] (";
		// strSql += IntToStr(TGlSettings::currFusion);
		// strSql += ",";
		// strSql += IntToStr(TGlSettings::numTube - 1);
		// strSql += ") as F1";
		strSql = "SELECT [dbo].[GetTzBorderL2] (";
		strSql += IntToStr(TGlSettings::indTypeSize);
		strSql += ") as F1";
		strTmp = SqlDBModule->GetStrFromFunctionSql(strSql, err);
		strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		TGlSettings::thresholdL2 = StrToFloat(strTmp);
		if (err != 0 || TGlSettings::thresholdL2 == -1) {
			// TGlSettings::currMagnetC = 5;
			TGlSettings::thresholdL2 = SqlDBModule->GetFloatFieldSQL("TypeSizesParams", "thresholdL2",
				"indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 0, err);
			tmpDouble = TGlSettings::thresholdL2;
		}
		else {
			//
		}
		// ---------------
		err = 0;
	}
	catch (Exception *ex) {
		err = -1;
		lbxInfo->AddItem("TLog::ErrFullSaveLog(ex)", NULL);
		TLog::ErrFullSaveLog(ex);
		// AnsiString msg
		// programSettings.colorMSG = programSettings.colorBrak;
		// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
	return err;
}

int TfmMain::GetIndexCbx(int _rec_id, TComboBox *_cbx) {
	lbxInfo->AddItem("GetIndexCbx", NULL);
	int ind = 0;
	for (int i = 0; i < _cbx->Items->Count; i++) {
		int cc = (int)_cbx->Items->Objects[i];
		if (cc == _rec_id) {
			ind = i;
			break;
		}
		else {
			//
		}
	}
	return ind;
}

void __fastcall TfmMain::bbtSaveClick(TObject *Sender) {
	lbxInfo->AddItem("TfmMain::bbtSaveClick", NULL);
	int err = 0;
	AnsiString strSql;
	try {
		AnsiString s = Trim(AnsiUpperCase(lbeNumFusion->Text));
		// TryStrToInt(s,TGlSettings::currFusion);
		if (!TryStrToInt(s, TGlSettings::currFusion)) {
			err = -2;
			MessageDlg(" Некорректный номер плавки \n Только целое число больше 0 !!!", mtError, TMsgDlgButtons() << mbOK, NULL);
			return;
		}
		else {
			if (TGlSettings::currFusion < 1) {
				MessageDlg(" Некорректный номер плавки \n Только целое число больше 0 !!!", mtError, TMsgDlgButtons() << mbOK, NULL);
				return;
			}
			else {
				//
			}
		}
		// Replace(const System::WideChar OldChar, const System::WideChar NewChar, int StartIndex, int Count)
		// Replace(' ','_',0,s.Length());
		TGlSettings::indTypeSize = (int)cbxTubesTypeSize->Items->Objects[cbxTubesTypeSize->ItemIndex];
		lbxInfo->Clear();
		lbxInfo->AddItem("TfmMain::bbtSaveClick", NULL);
		SqlDBModule->UpdIntSql("currentSettings", "ParamValueFloat", TGlSettings::indTypeSize,
			"isActual = 1 and UPPER(ParamName) = UPPER('indTypeSize')");
		// if (TGlSettings::isSOP == 1) {
		if (menuSOP->Checked) {
			bbtMode->Caption = "РЕЖИМ СОП (типоразмер:" + IntToStr(TGlSettings::indTypeSize) + ")";
		}
		else {
			bbtMode->Caption = "РЕЖИМ КОНТРОЛЯ (типоразмер:" + IntToStr(TGlSettings::indTypeSize) + ")";
		}
		lbxInfo->AddItem(bbtMode->Caption, NULL);
		if (cbxSteelGrades->ItemIndex < 0) {
			MessageDlg("Не выбрана Марка стали!", mtError, TMsgDlgButtons() << mbOK, NULL);
			return;
		}
		else {
			//
		}
		TGlSettings::indSteelGradeName = (int)cbxSteelGrades->Items->Objects[cbxSteelGrades->ItemIndex];
		SqlDBModule->UpdIntSql("currentSettings", "ParamValueFloat", TGlSettings::indSteelGradeName,
			" isActual =1 and UPPER(ParamName) = UPPER('indSteelGradeName')");
		lbxInfo->AddItem("TGlSettings::indSteelGradeName =" + IntToStr(TGlSettings::indSteelGradeName), NULL);
		// ---------------
		if (cbxNormDocs->ItemIndex < 0) {
			MessageDlg("Не выбран Нормативный документ!", mtError, TMsgDlgButtons() << mbOK, NULL);
			return;
		}
		else {
			//
		}
		TGlSettings::indNormDocName = (int)cbxNormDocs->Items->Objects[cbxNormDocs->ItemIndex];
		SqlDBModule->UpdIntSql("currentSettings", "ParamValueFloat", TGlSettings::indNormDocName,
			"isActual =1 and UPPER(ParamName) = UPPER('indNormDocName')");
		// -----------------
		if (cbxOperators->ItemIndex < 0) {
			MessageDlg("Не выбран Оператор!", mtError, TMsgDlgButtons() << mbOK, NULL);
			return;
		}
		else {
			//
		}
		TGlSettings::indOperatorName = (int)cbxOperators->Items->Objects[cbxOperators->ItemIndex];
		SqlDBModule->UpdIntSql("currentSettings", "ParamValueFloat", TGlSettings::indOperatorName,
			"isActual =1 and UPPER(ParamName) = UPPER('indOperatorName')");
		// -------------------------
		if (cbxWorkShifts->ItemIndex < 0) {
			MessageDlg("Не выбрана Смена!", mtError, TMsgDlgButtons() << mbOK, NULL);
			return;
		}
		else {
			//
		}
		TGlSettings::indWorkShiftName = (int)cbxWorkShifts->Items->Objects[cbxWorkShifts->ItemIndex];
		SqlDBModule->UpdIntSql("currentSettings", "ParamValueFloat", TGlSettings::indWorkShiftName,
			"isActual =1 and UPPER(ParamName) = UPPER('indWorkShiftName')");
		// -------------
		if (cbxSops->ItemIndex < 0) {
			MessageDlg("Не выбран СОП!", mtError, TMsgDlgButtons() << mbOK, NULL);
			return;
		}
		else {
			//
		}
		TGlSettings::indSopName = (int)cbxSops->Items->Objects[cbxSops->ItemIndex];
		SqlDBModule->UpdIntSql("currentSettings", "ParamValueFloat", TGlSettings::indSopName,
			" isActual =1 and UPPER(ParamName) = UPPER('indSopName')");
		// ---------------------
		TGlSettings::currFusion = StrToInt(lbeNumFusion->Text);
		SqlDBModule->UpdIntSql("currentSettings", "ParamValueFloat", TGlSettings::currFusion,
			"isActual = 1 and UPPER(ParamName) = UPPER('numCurrFuzion')");
		// SqlDBModule->UpdIntSql("currentSettings", "ParamValueFloat", TGlSettings::numTube,
		// "isActual = 1 and UPPER(ParamName) = UPPER('numCurrTube')");
		// ---------настройки типоразмеров
		// TGlSettings::thresholdC1 = SqlDBModule->GetFloatFieldSQL("settingsTypeSz", "thresholdC1",
		// "isActual = 1 and indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 5, err);
		// TGlSettings::thresholdC2 = SqlDBModule->GetFloatFieldSQL("settingsTypeSz", "thresholdC2",
		// "isActual = 1 and indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 5, err);
		// TGlSettings::thresholdL1 = SqlDBModule->GetFloatFieldSQL("settingsTypeSz", "thresholdL1",
		// "isActual = 1 and indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 5, err);
		// TGlSettings::thresholdL2 = SqlDBModule->GetFloatFieldSQL("settingsTypeSz", "thresholdL2",
		// "isActual = 1 and indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 5, err);
		// TGlSettings::thresholdTDown = SqlDBModule->GetFloatFieldSQL("settingsTypeSz", "thresholdTDown",
		// "isActual = 1 and indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 5, err);
		// TGlSettings::thresholdTUp = SqlDBModule->GetFloatFieldSQL("settingsTypeSz", "thresholdTUp",
		// "isActual = 1 and indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 5, err);
		// TGlSettings::thresholdTNominal = SqlDBModule->GetFloatFieldSQL("settingsTypeSz", "thresholdTNominal",
		// "isActual = 1 and indTypeSize=" + IntToStr(TGlSettings::indTypeSize), 5, err);
		if (menuSOP->Checked) {
			// СОП
			strSql = "select max(numTube) as F1 from resultTubeShort where numTube>0 and isEmpty=0 and isSOP=1 and numFusion=" +
				IntToStr(TGlSettings::currFusion);
		}
		else {
			strSql = "select max(numTube) as F1 from resultTubeShort where numTube>0 and isEmpty=0 and isSOP=0 and numFusion=" +
				IntToStr(TGlSettings::currFusion);
		}
		TGlSettings::numTube = SqlDBModule->GetIntFromSql(strSql);
		int tmpInt = TGlSettings::numTube;
		if (menuRepeatControl->Checked) { // если повторный контроль
			TGlSettings::numTube = TGlSettings::repeatControlNumTube;
		}
		else {
			//
		}
		bbtReady->Enabled = true;
		bbtStop->Enabled = true;
		TimerUpdateState->Enabled = true;
		// serg3
		// TryStrToInt(lbeNumFusion->Text, TGlSettings::currFusion);

	}

	catch (Exception *ex) {
		lbxInfo->AddItem("TLog::ErrFullSaveLog(ex);", NULL);
		err = -1;
		TLog::ErrFullSaveLog(ex);
		// AnsiString msg
		// programSettings.colorMSG = programSettings.colorBrak;
		// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
		// MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
}
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

void __fastcall TfmMain::mnuOperatorsClick(TObject *Sender) {
	int err = 0;
	// AnsiString strSql = " SELECT rec_id as '№', operatorName as 'Оператор', isActive as 'Активный' FROM operators order by rec_id ";
	AnsiString strSql = " SELECT operatorName as 'Оператор', isActive as 'Активный' FROM operators order by rec_id,operatorName ";
	try {
		fmSetDirectory = new TfmSetDirectory(NULL);
		fmSetDirectory->queryDirectory->Close();
		fmSetDirectory->queryDirectory->SQL->Text = strSql;
		fmSetDirectory->queryDirectory->Open();
		fmSetDirectory->ShowModal();
		delete fmSetDirectory;
	}
	catch (Exception *ex) {
		err = -1;
		TLog::ErrFullSaveLog(ex);
		// AnsiString msg
		// programSettings.colorMSG = programSettings.colorBrak;
		// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfmMain::menuWorkShiftsClick(TObject *Sender) {
	// AnsiString strSql = " SELECT rec_id as '№', workShiftName as 'Смены', isActive as 'Активный' FROM WorkShifts order by rec_id ";
	AnsiString strSql = " SELECT workShiftName as 'Смены', isActive as 'Активный' FROM WorkShifts order by rec_id,workShiftName ";
	fmSetDirectory = new TfmSetDirectory(NULL);
	fmSetDirectory->queryDirectory->Close();
	fmSetDirectory->queryDirectory->SQL->Text = strSql;
	fmSetDirectory->queryDirectory->Open();
	fmSetDirectory->ShowModal();
	delete fmSetDirectory;
}
// ---------------------------------------------------------------------------

void __fastcall TfmMain::menuTubesTypeSizeClick(TObject *Sender) {

	AnsiString strSql = " SELECT rec_id as '№', typeSizeName as 'Наименование типоразмера', tubeDiam as 'Диаметр внеш, мм' ";
	strSql +=
		", tubeThick as 'Толщ. стенки, мм', isOk as 'Есть выcаженная часть', isActive as 'Активный' FROM tubesTypeSize order by rec_id,tubeThick ";
	fmSetDirectory = new TfmSetDirectory(NULL);
	fmSetDirectory->queryDirectory->Close();
	fmSetDirectory->queryDirectory->SQL->Text = strSql;
	fmSetDirectory->queryDirectory->Open();
	fmSetDirectory->DBGridDirectory->Columns->Items[0]->ReadOnly = true;
	fmSetDirectory->ShowModal();
	delete fmSetDirectory;
}
// ---------------------------------------------------------------------------

void __fastcall TfmMain::menuSteelGradesClick(TObject *Sender) {
	AnsiString strSql = " SELECT steelGradeName as 'Марка', isActive as 'Активный' FROM steelGrades order by rec_id,steelGradeName ";
	fmSetDirectory = new TfmSetDirectory(NULL);
	fmSetDirectory->queryDirectory->Close();
	fmSetDirectory->queryDirectory->SQL->Text = strSql;
	fmSetDirectory->queryDirectory->Open();
	fmSetDirectory->ShowModal();
	delete fmSetDirectory;
}
// ---------------------------------------------------------------------------

void __fastcall TfmMain::menuSopsClick(TObject *Sender) {
	AnsiString strSql = " SELECT SopName as 'Наименование СОП', isActive as 'Активный' FROM Sops order by rec_id,SopName ";
	fmSetDirectory = new TfmSetDirectory(NULL);
	fmSetDirectory->queryDirectory->Close();
	fmSetDirectory->queryDirectory->SQL->Text = strSql;
	fmSetDirectory->queryDirectory->Open();
	fmSetDirectory->ShowModal();
	delete fmSetDirectory;
}
// ---------------------------------------------------------------------------

void __fastcall TfmMain::menuNormDocsClick(TObject *Sender) {
	AnsiString strSql = " SELECT normDocName as 'Наименование документа', isActive as 'Активный' FROM normDocs order by normDocName ";
	fmSetDirectory = new TfmSetDirectory(NULL);
	fmSetDirectory->queryDirectory->Close();
	fmSetDirectory->queryDirectory->SQL->Text = strSql;
	fmSetDirectory->queryDirectory->Open();
	fmSetDirectory->ShowModal();
	delete fmSetDirectory;
}
// ---------------------------------------------------------------------------

void __fastcall TfmMain::menuListTubesClick(TObject *Sender) {
	int err = 0;
	try {
		fmShowListTubes = new TfmShowListTubes(NULL);
		fmShowListTubes->ShowModal();
		delete fmShowListTubes;
	}
	catch (Exception *ex) {
		err = -1;
		TLog::ErrFullSaveLog(ex);
		// AnsiString msg
		// programSettings.colorMSG = programSettings.colorBrak;
		// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfmMain::menuBackupClick(TObject *Sender) {
	lbxInfo->AddItem("TfmMain::menuBackupClick", NULL);
	int err = 0;
	AnsiString strSql = "";
	AnsiString strTst = "";
	try {
		bool isWorkState = SqlDBModule->GetBoolFieldSQL("flags", "isWorkState", "isActual=1", 0, err);
		if (isWorkState) {
			TExtFunction::ShowBigModalMessage("Выставлен режим контроля,\n создание резервной копии невозможно!", clRed);
			return;
		}
		else {

		}
		// fmCreateBackup = new TfmCreateBackup(this);
		// fmCreateBackup->ShowModal();
		// fmCreateBackup->Close();
		// fmCreateBackup = NULL;
		// ExtractFilePath(Application->ExeName);

		// S := SysUtils.FormatDateTime('" The meeting is on " dddd, mmmm d, yyyy, " at " hh:mm AM/PM', IncHour(Now(), 3));
		// TGlSettings::fullNameBkpFile = ExtractFileDir(Application->ExeName) + "\\BkpBase\\";
		SqlDBModule->queryQuick->Close();
		TGlSettings::fullNameBkpFile = SqlDBModule->GetStrFieldSQL("currentSettings", "ParamValueStr",
			"isActual=1 and UPPER(ParamName)=UPPER('backupPath')", "E:\\MSQSL-BD\\BACKUP\\", err);
		strTst = TGlSettings::fullNameBkpFile;

		// strSql="E:\\MSQSL-BD\\BACKUP\\
		// SqlDBModule->queryQuick->SQL->Text = strSql;
		// TGlSettings::fullNameBkpFile = "E:\\MSQSL-BD\\BACKUP\\";
		if (!DirectoryExists(TGlSettings::fullNameBkpFile)) {
			CreateDir(TGlSettings::fullNameBkpFile);
		}
		else {
			//
		}
		TGlSettings::fullNameBkpFile += FormatDateTime("yyyy_mm_dd_", Now());
		TGlSettings::fullNameBkpFile += "buran9955Pa.bak ";
		strSql = " BACKUP DATABASE[buran9955Pa]TO DISK = N'";
		strSql += TGlSettings::fullNameBkpFile;
		if (MessageDlg("Резервная копия БД будет сохранена в файл:\n" + TGlSettings::fullNameBkpFile + " \n ПРОДОЛЖИТЬ?", mtError,
			TMsgDlgButtons() << mbOK << mbCancel, 0) == mrOk) {
			//
		}
		else {
			return;
		}
		strSql += "' WITH NOFORMAT, INIT, NAME = N'buran9955Pa-Полное Резервное копирование', SKIP, NOREWIND, NOUNLOAD, STATS = 10 ";
		SqlDBModule->queryQuick->Close();
		SqlDBModule->queryQuick->SQL->Text = strSql;
		SqlDBModule->queryQuick->ExecSQL();
		err = SqlDBModule->queryQuick->RowsAffected;
		MessageDlg(" Успешно завершено.", mtInformation, TMsgDlgButtons() << mbOK, NULL);
		int err = 0;
	}
	catch (Exception *ex) {
		err = -1;
		TLog::ErrFullSaveLog(ex);
		// AnsiString msg
		// programSettings.colorMSG = programSettings.colorBrak;
		// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
}

// ---------------------------------------------------------------------------
int TfmMain::GetAndSendIP_MAC() {
	int err = 0;
	try {
		const int WSVer = 0x101;
		WSAData wsaData;
		hostent *h;
		char Buf[128];
		if (WSAStartup(WSVer, &wsaData) == 0) {
			if (gethostname(&Buf[0], 128) == 0) {
				h = gethostbyname(&Buf[0]);
				if (h != NULL)
					// MessageBox(0,inet_ntoa(*(reinterpret_cast<in_addr *>(*(h->h_addr_list)))), 0, 0);
					// MessageDlg(inet_ntoa(*(reinterpret_cast<in_addr *>(*(h->h_addr_list)))), mtError, TMsgDlgButtons() << mbOK, NULL);
						TGlSettings::myIP = inet_ntoa(*(reinterpret_cast<in_addr*>(*(h->h_addr_list))));
				// GetAdaptersInfo.
				else
					// MessageBox(0, " Вы не в сети.И IP адреса у вас нет.", 0, 0);
						MessageDlg(" Вы не в сети.И IP адреса у вас нет.", mtError, TMsgDlgButtons() << mbOK, NULL);
			}
			WSACleanup;
		}

	}
	catch (Exception *ex) {
		err = -1;
		TLog::ErrFullSaveLog(ex);
		// AnsiString msg
		// programSettings.colorMSG = programSettings.colorBrak;
		// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
	return err;
}

void __fastcall TfmMain::FormClose(TObject *Sender, TCloseAction &Action) {
	// int err = gridTubes->Columns->Count;
	int res;
	int err;
	try {
		SqlDBModule->UpdIntSql(" flags ", "isReady", 0, NULL);
		lbxInfo->AddItem("isReady=0", NULL);
		SqlDBModule->UpdBoolSql("flags", "isDataSendCompleet", 0, "isActual=1");
		// ---
		// for (int i = 0; i < err; i++) {
		// SqlDBModule->UpdIntSql(" gridTubesColWidth ", " colWidth ", gridTubes->Columns->Items[i]->Width,
		// " colNum = " + IntToStr(i + 1));
		// }

		// err = 0;
	}
	catch (Exception *ex) {
		// err = -1;
		TLog::ErrFullSaveLog(ex);
		// AnsiString msg
		// programSettings.colorMSG = programSettings.colorBrak;
		// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
}

void __fastcall TfmMain::menuExtInfoClick(TObject *Sender) {
	fmInfo = new TfmInfo(this);
	fmInfo->ShowModal();
	delete fmInfo;
}

// ---------------------------------------------------------------------------
	void __store_base__::operator()(int &err)
	{

		AnsiString strSqlWhere = "numFusion=" + IntToStr(TGlSettings::currFusion) + " and numTube=" + IntToStr(TGlSettings::numTube);
         pnlMsg->Caption = "ПОЛУЧИЛИ ДАННЫЕ ПО ТРУБЕ № " + IntToStr(TGlSettings::numTube);
				pnlMsg->Font->Color = clGreen;
				pnlMsg->Refresh();
				AnsiString strSql = "SELECT [dbo].[GetCountRoundXML] ('";
				strSql += IntToStr(TGlSettings::currFusion);
				strSql += "','";
				strSql += IntToStr(TGlSettings::numTube);
				strSql += "') as F1";
				AnsiString strTmp = SqlDBModule->GetStrFromFunctionSql(strSql, err);
				double speedRound = 0;
				if (TryStrToFloat(strTmp, speedRound)) {
					if (speedRound < 0) {
						speedRound = 0;
					}
					else {
						//
					}
				}
				else {
					speedRound = 0;
				}
				SqlDBModule->UpdFloatSql("resultTubeShort", "speedRound", speedRound, strSqlWhere);
				// новая труба создание
				TGlSettings::numTube++;
				double tmpDouble = TGlSettings::numTube;
				err = CreateTables(TGlSettings::currFusion, TGlSettings::numTube);
				lbxInfo->AddItem("Новая труба создание", NULL);
				lbxInfo->AddItem("Ожидание 0.1 сек", NULL);
				Application->ProcessMessages();
				// if (menuRepeatControl->Checked) {
				// SqlDBModule->UpdIntSql(" flags ", " isReady ", 0, NULL);
				// bbtStopClick(bbtStop);
				// }else{
				// //
				// }   100
				Sleep(100);
				SqlDBModule->UpdFloatSql("currentSettings", "ParamValueFloat", TGlSettings::numTube,
					"UPPER(ParamName)=UPPER('numCurrTube')");
				Sleep (100);
				SqlDBModule->UpdIntSql(" flags ", " isReady ", 1, NULL);
				lbxInfo->AddItem("isReady=1", NULL);
				lbxInfo->AddItem("Выставили готовность все данные", NULL);
				// Sleep(2000);
				Application->ProcessMessages();
				if (menuSOP->Checked) {
					// СОП
					strSql = "select max(numTube) as F1 from resultTubeShort where numTube>0 and isEmpty=0 and isSOP=1 and numFusion=" +
						IntToStr(TGlSettings::currFusion);
				}
				else {
					strSql = "select max(numTube) as F1 from resultTubeShort where numTube>0 and isEmpty=0 and isSOP=0 and numFusion=" +
						IntToStr(TGlSettings::currFusion);
				}
				countControls = SqlDBModule->GetIntFromSql(strSql);
				if (countControls > 5000) {
					bbtCountControl->Caption = "ПРОКОНТРОЛИРОВАНО: " + IntToStr(countControls - 5000);
				}
				else {
					bbtCountControl->Caption = "ПРОКОНТРОЛИРОВАНО: " + IntToStr(countControls);
				}
				if (menuSOP->Checked || menuRepeatControl->Checked) {
					bbtStopClick(bbtStop);
					// menuRepeatControl->Checked = false;
					return;
				}

				secYearBeginWait = SecondOfTheYear(Now());
	}
	
	bool __store_base__::IsExist(bool crossBool, bool longBool, bool thickBool)
	{
		 if(crossBool)
		 {
			 AnsiString strSql =
			 "SELECT count(*) as F1"\
			 " FROM [dbo].[resultCross] where numTube=";
			 strSql+=  IntToStr(TGlSettings::numTube);
			 strSql+= " and numFusion=";
			 strSql += IntToStr(TGlSettings::currFusion);
			 strSql += " and Z1 is not NULL"\
			 " and Z2 is not NULL"\
			 " and Z3 is not NULL"\
			 " and Z4 is not NULL";
			 if(SqlDBModule->GetIntFromSql(strSql) > 0) return true;
		 }
		 if(longBool)
		 {
			 AnsiString strSql =
			 "SELECT count(*) as F1"\
			 " FROM [dbo].[resultLong] where numTube=";
			 strSql+=  IntToStr(TGlSettings::numTube);
			 strSql+= " and numFusion=";
			 strSql += IntToStr(TGlSettings::currFusion);
			 strSql += " and Z1 is not NULL"\
			 " and Z2 is not NULL"\
			 " and Z3 is not NULL"\
			 " and Z4 is not NULL";
			 if(SqlDBModule->GetIntFromSql(strSql) > 0) return true;
		 }
		 if(thickBool)
		 {
			 AnsiString strSql =
			 "SELECT count(*) as F1"\
			 " FROM [dbo].[resultThick] where numTube=";
			 strSql+=  IntToStr(TGlSettings::numTube);
			 strSql+= " and numFusion=";
			 strSql += IntToStr(TGlSettings::currFusion);
			 strSql += " and Min1 is not NULL"\
			 " and Min2 is not NULL"\
			 " and Min3 is not NULL"\
			 " and Min4 is not NULL";
			 if(SqlDBModule->GetIntFromSql(strSql) > 0) return true;
		 }
         return false;
	}
	void __store_base__::Clean(const char *s)
	{
		AnsiString str = "UPDATE " + AnsiString(s);
str += " SET [Z1] = NULL"\
" ,[Z2] = NULL"\
" ,[Z3] = NULL"\
" ,[Z4] = NULL"\
" ,[Z5] = NULL"\
" ,[Z6] = NULL"\
" ,[Z7] = NULL"\
" ,[Z8] = NULL"\
" ,[Z9] = NULL"\
" ,[Z10] = NULL"\
" ,[Z11] = NULL"\
" ,[Z12] = NULL"\
" ,[Z13] = NULL"\
" ,[Z14] = NULL"\
" ,[Z15] = NULL"\
" ,[Z16] = NULL"\
" ,[Z17] = NULL"\
" ,[Z18] = NULL"\
" ,[Z19] = NULL"\
" ,[Z20] = NULL"\
" ,[Z21] = NULL"\
" ,[Z22] = NULL"\
" ,[Z23] = NULL"\
" ,[Z24] = NULL"\
" ,[Z25] = NULL"\
" ,[Z26] = NULL"\
" ,[Z27] = NULL"\
" ,[Z28] = NULL"\
" ,[Z29] = NULL"\
" ,[Z30] = NULL"\
" ,[Z31] = NULL"\
" ,[Z32] = NULL"\
" ,[Z33] = NULL"\
" ,[Z34] = NULL"\
" ,[Z35] = NULL"\
" ,[Z36] = NULL"\
" ,[Z37] = NULL"\
" ,[Z38] = NULL"\
" ,[Z39] = NULL"\
" ,[Z40] = NULL"\
" ,[Z41] = NULL"\
" ,[Z42] = NULL"\
" ,[Z43] = NULL"\
" ,[Z44] = NULL"\
" ,[Z45] = NULL"\
" ,[Z46] = NULL"\
" ,[Z47] = NULL"\
" ,[Z48] = NULL"\
" ,[Z49] = NULL"\
" ,[Z50] = NULL"\
" ,[Z51] = NULL"\
" ,[Z52] = NULL"\
" ,[Z53] = NULL"\
" ,[Z54] = NULL"\
" ,[Z55] = NULL"\
" ,[Z56] = NULL"\
" ,[Z57] = NULL"\
" ,[Z58] = NULL"\
" ,[Z59] = NULL"\
" ,[Z60] = NULL"\
" ,[Z61] = NULL"\
" ,[Z62] = NULL"\
" ,[Z63] = NULL"\
" ,[Z64] = NULL"\
" ,[Z65] = NULL"\
" ,[Z66] = NULL"\
" ,[Z67] = NULL"\
" ,[Z68] = NULL"\
" ,[Z69] = NULL"\
" ,[Z70] = NULL"\
" ,[Z71] = NULL"\
" ,[Z72] = NULL"\
" ,[Z73] = NULL"\
" ,[Z74] = NULL"\
" ,[Z75] = NULL"\
" ,[Z76] = NULL"\
" ,[Z77] = NULL"\
" ,[Z78] = NULL"\
" ,[Z79] = NULL"\
" ,[Z80] = NULL"\
" ,[Z81] = NULL"\
" ,[Z82] = NULL"\
" ,[Z83] = NULL"\
" ,[Z84] = NULL"\
" ,[Z85] = NULL"\
" ,[Z86] = NULL"\
" ,[Z87] = NULL"\
" ,[Z88] = NULL"\
" ,[Z89] = NULL"\
" ,[Z90] = NULL"\
" ,[Z91] = NULL"\
" ,[Z92] = NULL"\
" ,[Z93] = NULL"\
" ,[Z94] = NULL"\
" ,[Z95] = NULL"\
" ,[Z96] = NULL"\
" ,[Z97] = NULL"\
" ,[Z98] = NULL"\
" ,[Z99] = NULL"\
" ,[Z100] = NULL"\
" ,[Z101] = NULL"\
" ,[Z102] = NULL"\
" ,[Z103] = NULL"\
" ,[Z104] = NULL"\
" ,[Z105] = NULL"\
" ,[Z106] = NULL"\
" ,[Z107] = NULL"\
" ,[Z108] = NULL"\
" ,[Z109] = NULL"\
" ,[Z110] = NULL"\
" ,[Z111] = NULL"\
" ,[Z112] = NULL"\
" ,[Z113] = NULL"\
" ,[Z114] = NULL"\
" ,[Z115] = NULL"\
" ,[Z116] = NULL"\
" ,[Z117] = NULL"\
" ,[Z118] = NULL"\
" ,[Z119] = NULL"\
" ,[Z120] = NULL"\
" ,[Z121] = NULL"\
" ,[Z122] = NULL"\
" ,[Z123] = NULL"\
" ,[Z124] = NULL"\
" ,[Z125] = NULL"\
" ,[Z126] = NULL"\
" ,[Z127] = NULL"\
" ,[Z128] = NULL"\
" ,[Z129] = NULL"\
" ,[Z130] = NULL"\
" ,[Z131] = NULL"\
" ,[Z132] = NULL"\
" ,[Z133] = NULL"\
" ,[Z134] = NULL"\
" ,[Z135] = NULL"\
" ,[Z136] = NULL"\
" ,[Z137] = NULL"\
" ,[Z138] = NULL"\
" ,[Z139] = NULL"\
" ,[Z140] = NULL"\
" ,[Z141] = NULL"\
" ,[Z142] = NULL"\
" ,[Z143] = NULL"\
" ,[Z144] = NULL"\
" ,[Z145] = NULL"\
" WHERE numTube=";
str += IntToStr(TGlSettings::numTube);
str += " and numFusion=";
str += IntToStr(TGlSettings::currFusion);

		SqlDBModule->queryForChart->Close();
		SqlDBModule->queryForChart->SQL->Text = str;
		SqlDBModule->queryForChart->ExecSQL();
		SqlDBModule->queryForChart->Close();
	}
void __store_base__::CleanThick()
{
   AnsiString str = "UPDATE [dbo].[resultThick]"\
" SET [Min1] = NULL"\
" ,[Min2] = NULL"\
" ,[Min3] = NULL"\
" ,[Min4] = NULL"\
" ,[Min5] = NULL"\
" ,[Min6] = NULL"\
" ,[Min7] = NULL"\
" ,[Min8] = NULL"\
" ,[Min9] = NULL"\
" ,[Min10] = NULL"\
" ,[Min11] = NULL"\
" ,[Min12] = NULL"\
" ,[Min13] = NULL"\
" ,[Min14] = NULL"\
" ,[Min15] = NULL"\
" ,[Min16] = NULL"\
" ,[Min17] = NULL"\
" ,[Min18] = NULL"\
" ,[Min19] = NULL"\
" ,[Min20] = NULL"\
" ,[Min21] = NULL"\
" ,[Min22] = NULL"\
" ,[Min23] = NULL"\
" ,[Min24] = NULL"\
" ,[Min25] = NULL"\
" ,[Min26] = NULL"\
" ,[Min27] = NULL"\
" ,[Min28] = NULL"\
" ,[Min29] = NULL"\
" ,[Min30] = NULL"\
" ,[Min31] = NULL"\
" ,[Min32] = NULL"\
" ,[Min33] = NULL"\
" ,[Min34] = NULL"\
" ,[Min35] = NULL"\
" ,[Min36] = NULL"\
" ,[Min37] = NULL"\
" ,[Min38] = NULL"\
" ,[Min39] = NULL"\
" ,[Min40] = NULL"\
" ,[Min41] = NULL"\
" ,[Min42] = NULL"\
" ,[Min43] = NULL"\
" ,[Min44] = NULL"\
" ,[Min45] = NULL"\
" ,[Min46] = NULL"\
" ,[Min47] = NULL"\
" ,[Min48] = NULL"\
" ,[Min49] = NULL"\
" ,[Min50] = NULL"\
" ,[Min51] = NULL"\
" ,[Min52] = NULL"\
" ,[Min53] = NULL"\
" ,[Min54] = NULL"\
" ,[Min55] = NULL"\
" ,[Min56] = NULL"\
" ,[Min57] = NULL"\
" ,[Min58] = NULL"\
" ,[Min59] = NULL"\
" ,[Min60] = NULL"\
" ,[Min61] = NULL"\
" ,[Min62] = NULL"\
" ,[Min63] = NULL"\
" ,[Min64] = NULL"\
" ,[Min65] = NULL"\
" ,[Min66] = NULL"\
" ,[Min67] = NULL"\
" ,[Min68] = NULL"\
" ,[Min69] = NULL"\
" ,[Min70] = NULL"\
" ,[Min71] = NULL"\
" ,[Min72] = NULL"\
" ,[Min73] = NULL"\
" ,[Min74] = NULL"\
" ,[Min75] = NULL"\
" ,[Min76] = NULL"\
" ,[Min77] = NULL"\
" ,[Min78] = NULL"\
" ,[Min79] = NULL"\
" ,[Min80] = NULL"\
" ,[Min81] = NULL"\
" ,[Min82] = NULL"\
" ,[Min83] = NULL"\
" ,[Min84] = NULL"\
" ,[Min85] = NULL"\
" ,[Min86] = NULL"\
" ,[Min87] = NULL"\
" ,[Min88] = NULL"\
" ,[Min89] = NULL"\
" ,[Min90] = NULL"\
" ,[Min91] = NULL"\
" ,[Min92] = NULL"\
" ,[Min93] = NULL"\
" ,[Min94] = NULL"\
" ,[Min95] = NULL"\
" ,[Min96] = NULL"\
" ,[Min97] = NULL"\
" ,[Min98] = NULL"\
" ,[Min99] = NULL"\
" ,[Min100] = NULL"\
" ,[Min101] = NULL"\
" ,[Min102] = NULL"\
" ,[Min103] = NULL"\
" ,[Min104] = NULL"\
" ,[Min105] = NULL"\
" ,[Min106] = NULL"\
" ,[Min107] = NULL"\
" ,[Min108] = NULL"\
" ,[Min109] = NULL"\
" ,[Min110] = NULL"\
" ,[Min111] = NULL"\
" ,[Min112] = NULL"\
" ,[Min113] = NULL"\
" ,[Min114] = NULL"\
" ,[Min115] = NULL"\
" ,[Min116] = NULL"\
" ,[Min117] = NULL"\
" ,[Min118] = NULL"\
" ,[Min119] = NULL"\
" ,[Min120] = NULL"\
" ,[Min121] = NULL"\
" ,[Min122] = NULL"\
" ,[Min123] = NULL"\
" ,[Min124] = NULL"\
" ,[Min125] = NULL"\
" ,[Min126] = NULL"\
" ,[Min127] = NULL"\
" ,[Min128] = NULL"\
" ,[Min129] = NULL"\
" ,[Min130] = NULL"\
" ,[Min131] = NULL"\
" ,[Min132] = NULL"\
" ,[Min133] = NULL"\
" ,[Min134] = NULL"\
" ,[Min135] = NULL"\
" ,[Min136] = NULL"\
" ,[Min137] = NULL"\
" ,[Min138] = NULL"\
" ,[Min139] = NULL"\
" ,[Min140] = NULL"\
" ,[Min141] = NULL"\
" ,[Min142] = NULL"\
" ,[Min143] = NULL"\
" ,[Min144] = NULL"\
" ,[Min145] = NULL"\
" ,[Max1] = NULL"\
" ,[Max2] = NULL"\
" ,[Max3] = NULL"\
" ,[Max4] = NULL"\
" ,[Max5] = NULL"\
" ,[Max6] = NULL"\
" ,[Max7] = NULL"\
" ,[Max8] = NULL"\
" ,[Max9] = NULL"\
" ,[Max10] = NULL"\
" ,[Max11] = NULL"\
" ,[Max12] = NULL"\
" ,[Max13] = NULL"\
" ,[Max14] = NULL"\
" ,[Max15] = NULL"\
" ,[Max16] = NULL"\
" ,[Max17] = NULL"\
" ,[Max18] = NULL"\
" ,[Max19] = NULL"\
" ,[Max20] = NULL"\
" ,[Max21] = NULL"\
" ,[Max22] = NULL"\
" ,[Max23] = NULL"\
" ,[Max24] = NULL"\
" ,[Max25] = NULL"\
" ,[Max26] = NULL"\
" ,[Max27] = NULL"\
" ,[Max28] = NULL"\
" ,[Max29] = NULL"\
" ,[Max30] = NULL"\
" ,[Max31] = NULL"\
" ,[Max32] = NULL"\
" ,[Max33] = NULL"\
" ,[Max34] = NULL"\
" ,[Max35] = NULL"\
" ,[Max36] = NULL"\
" ,[Max37] = NULL"\
" ,[Max38] = NULL"\
" ,[Max39] = NULL"\
" ,[Max40] = NULL"\
" ,[Max41] = NULL"\
" ,[Max42] = NULL"\
" ,[Max43] = NULL"\
" ,[Max44] = NULL"\
" ,[Max45] = NULL"\
" ,[Max46] = NULL"\
" ,[Max47] = NULL"\
" ,[Max48] = NULL"\
" ,[Max49] = NULL"\
" ,[Max50] = NULL"\
" ,[Max51] = NULL"\
" ,[Max52] = NULL"\
" ,[Max53] = NULL"\
" ,[Max54] = NULL"\
" ,[Max55] = NULL"\
" ,[Max56] = NULL"\
" ,[Max57] = NULL"\
" ,[Max58] = NULL"\
" ,[Max59] = NULL"\
" ,[Max60] = NULL"\
" ,[Max61] = NULL"\
" ,[Max62] = NULL"\
" ,[Max63] = NULL"\
" ,[Max64] = NULL"\
" ,[Max65] = NULL"\
" ,[Max66] = NULL"\
" ,[Max67] = NULL"\
" ,[Max68] = NULL"\
" ,[Max69] = NULL"\
" ,[Max70] = NULL"\
" ,[Max71] = NULL"\
" ,[Max72] = NULL"\
" ,[Max73] = NULL"\
" ,[Max74] = NULL"\
" ,[Max75] = NULL"\
" ,[Max76] = NULL"\
" ,[Max77] = NULL"\
" ,[Max78] = NULL"\
" ,[Max79] = NULL"\
" ,[Max80] = NULL"\
" ,[Max81] = NULL"\
" ,[Max82] = NULL"\
" ,[Max83] = NULL"\
" ,[Max84] = NULL"\
" ,[Max85] = NULL"\
" ,[Max86] = NULL"\
" ,[Max87] = NULL"\
" ,[Max88] = NULL"\
" ,[Max89] = NULL"\
" ,[Max90] = NULL"\
" ,[Max91] = NULL"\
" ,[Max92] = NULL"\
" ,[Max93] = NULL"\
" ,[Max94] = NULL"\
" ,[Max95] = NULL"\
" ,[Max96] = NULL"\
" ,[Max97] = NULL"\
" ,[Max98] = NULL"\
" ,[Max99] = NULL"\
" ,[Max100] = NULL"\
" ,[Max101] = NULL"\
" ,[Max102] = NULL"\
" ,[Max103] = NULL"\
" ,[Max104] = NULL"\
" ,[Max105] = NULL"\
" ,[Max106] = NULL"\
" ,[Max107] = NULL"\
" ,[Max108] = NULL"\
" ,[Max109] = NULL"\
" ,[Max110] = NULL"\
" ,[Max111] = NULL"\
" ,[Max112] = NULL"\
" ,[Max113] = NULL"\
" ,[Max114] = NULL"\
" ,[Max115] = NULL"\
" ,[Max116] = NULL"\
" ,[Max117] = NULL"\
" ,[Max118] = NULL"\
" ,[Max119] = NULL"\
" ,[Max120] = NULL"\
" ,[Max121] = NULL"\
" ,[Max122] = NULL"\
" ,[Max123] = NULL"\
" ,[Max124] = NULL"\
" ,[Max125] = NULL"\
" ,[Max126] = NULL"\
" ,[Max127] = NULL"\
" ,[Max128] = NULL"\
" ,[Max129] = NULL"\
" ,[Max130] = NULL"\
" ,[Max131] = NULL"\
" ,[Max132] = NULL"\
" ,[Max133] = NULL"\
" ,[Max134] = NULL"\
" ,[Max135] = NULL"\
" ,[Max136] = NULL"\
" ,[Max137] = NULL"\
" ,[Max138] = NULL"\
" ,[Max139] = NULL"\
" ,[Max140] = NULL"\
" ,[Max141] = NULL"\
" ,[Max142] = NULL"\
" ,[Max143] = NULL"\
" ,[Max144] = NULL"\
" ,[Max145] = NULL"\
" WHERE numTube=";

str += IntToStr(TGlSettings::numTube);
str += " and numFusion=";
str += IntToStr(TGlSettings::currFusion);

		SqlDBModule->queryForChart->Close();
		SqlDBModule->queryForChart->SQL->Text = str;
		SqlDBModule->queryForChart->ExecSQL();
		SqlDBModule->queryForChart->Close();
}

void __fastcall TfmMain::TimerUpdateStateTimer(TObject *Sender) {
	int err = 0;
	TimerUpdateState->Enabled = false;
	AnsiString strSql = "";
	AnsiString strSqlWhere = "";
	AnsiString strTmp = "";
	int tmpInt = 0;
	TReplaceFlags ReplaceFlags;
	double tmpDouble = 0;
	bool isDataSendCompleet;
	errT = 0;
	errC = 0;
	errL = 0;
	try {
		strTmp = "ОЖИДАЕМ ДАННЫЕ ПО ";
		strTmp += "ТРУБЕ № ";
		strTmp += IntToStr(TGlSettings::numTube);
		pnlMsg->Caption = strTmp;
		pnlMsg->Font->Color = clBlack;
		pnlMsg->Refresh();
		lbxInfo->AddItem(pnlMsg->Caption, NULL);
		if (lbxInfo->Items->Count > 40) {
			lbxInfo->Clear();

		}
		
		if (TGlSettings::isWorkState) {
			bbtMode->Font->Color = clGreen;
		}
		else {
			bbtMode->Font->Color = clBlack;
		}
		// ----------------------
		if (TGlSettings::isWorkState && menuSOP->Checked) {
			bbtMode->Font->Color = clBlue;
			bbtMode->Caption = "РЕЖИМ СОП (типоразмер:" + IntToStr(TGlSettings::indTypeSize) + ")";
		}
		if (TGlSettings::isWorkState && menuRepeatControl->Checked) {
			bbtMode->Font->Color = clRed;
			bbtMode->Caption = "ПОВТОР КОНТРОЛЯ (типоразмер:" + IntToStr(TGlSettings::indTypeSize) + ")";
		}
		if (TGlSettings::isWorkState && menuRepeatControl->Checked && menuRepeatControl->Checked) {
			bbtMode->Font->Color = clRed;
			bbtMode->Caption = "ПОВТОР КОНТРОЛЯ СОП(типоразмер:" + IntToStr(TGlSettings::indTypeSize) + ")";
		}
		
		isDataSendCompleet = SqlDBModule->GetBoolFieldSQL("flags", "isDataSendCompleet", "isActual=1", 0, err);
		if (TGlSettings::isWorkState || menuRepeatControl->Checked) {
			// if (isDataSendCompleet && (TGlSettings::isWorkState || menuRepeatControl->Checked)) {
			SqlDBModule->UpdBoolSql("flags", "isDataSendCompleet", 0, "isActual=1");
			strSqlWhere = "numFusion=" + IntToStr(TGlSettings::currFusion) + " and numTube=" + IntToStr(TGlSettings::numTube);
			// !!!100
			Sleep(100);
			strSql = "SELECT [dbo].[GetCurrMagnetT] ('";
			strSql += IntToStr(TGlSettings::indTypeSize);
			strSql += "') as F1";
			strTmp = SqlDBModule->GetStrFromFunctionSql(strSql, err);
			strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
			TGlSettings::currMagnetT = StrToFloat(strTmp);
			lbxInfo->AddItem("currMagnetT", NULL);
			// !!!
			Sleep(100);
			strSql = "SELECT [dbo].[GetCurrMagnetC] ('";
			strSql += IntToStr(TGlSettings::indTypeSize);
			strSql += "') as F1";
			strTmp = SqlDBModule->GetStrFromFunctionSql(strSql, err);
			strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
			TGlSettings::currMagnetC = StrToFloat(strTmp);
			lbxInfo->AddItem("currMagnetC", NULL);
			//!!!100
			Sleep(100);
			strSql = "SELECT [dbo].[GetCurrMagnetL] ('";
			strSql += IntToStr(TGlSettings::indTypeSize);
			strSql += "') as F1";
			strTmp = SqlDBModule->GetStrFromFunctionSql(strSql, err);
			strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
			TGlSettings::currMagnetL = StrToFloat(strTmp);
			lbxInfo->AddItem("currMagnetL", NULL);
			// lbxInfo->AddItem("flags  isReady=" + IntToStr(SqlDBModule->GetIntFieldSQL("flags", "isReady", "isActual=1", 0, err)), NULL);
			// -----
			lbxInfo->AddItem("GetBordersT", NULL);
			// Sleep(1000);
			GetBordersT(TGlSettings::indTypeSize, TGlSettings::currFusion, TGlSettings::numTube);
			// SqlDBModule->UpdBoolSql("flags", "isDataSendCompleet", 0, "isActual=1");
			// -------------
			// Sleep(1000);
			lbxInfo->AddItem("GetBordersC", NULL);
			GetBordersC(TGlSettings::indTypeSize, TGlSettings::currFusion, TGlSettings::numTube);
			// SqlDBModule->UpdBoolSql("flags", "isDataSendCompleet", 0, "isActual=1");
			// -------------
			// Sleep(1000);
			lbxInfo->AddItem("GetBordersL", NULL);
			GetBordersL(TGlSettings::indTypeSize, TGlSettings::currFusion, TGlSettings::numTube);
			ViewCurrentBorders(TGlSettings::currFusion, TGlSettings::numTube);
			SqlDBModule->UpdBoolSql("flags", "isDataSendCompleet", 0, "isActual=1");
			// ----------
			// Thick
			SqlDBModule->UpdFloatSql("resultTubeShort", "thresholdTNominal", TGlSettings::thresholdTNominal, strSqlWhere);
			SqlDBModule->UpdFloatSql("resultTubeShort", "thresholdTUp", TGlSettings::thresholdTUp, strSqlWhere);
			SqlDBModule->UpdFloatSql("resultTubeShort", "thresholdTDown", TGlSettings::thresholdTDown, strSqlWhere);
			SqlDBModule->UpdFloatSql("resultTubeShort", "currentMagnetT", TGlSettings::currMagnetT, strSqlWhere);
			// -------
			SqlDBModule->UpdFloatSql("resultTubeShort", "currentMagnetC", TGlSettings::currMagnetC, strSqlWhere);
			SqlDBModule->UpdFloatSql("resultTubeShort", "thresholdC1", TGlSettings::thresholdC1, strSqlWhere);
			SqlDBModule->UpdFloatSql("resultTubeShort", "thresholdC2", TGlSettings::thresholdC2, strSqlWhere);
			// --------Long
			SqlDBModule->UpdFloatSql("resultTubeShort", "currentMagnetL", TGlSettings::currMagnetL, strSqlWhere);
			SqlDBModule->UpdFloatSql("resultTubeShort", "thresholdL1", TGlSettings::thresholdL1, strSqlWhere);
			SqlDBModule->UpdFloatSql("resultTubeShort", "thresholdL2", TGlSettings::thresholdL2, strSqlWhere);
			// обновим дату внесения данных
			SqlDBModule->UpdFloatSql("resultTubeShort", "dtmCreate", Now(), strSqlWhere);
			bbtStop->Enabled = false;
			//!!!200
			Sleep(100);
			Application->ProcessMessages();
			int st = 0;
			strSql = "SELECT countZones";
			strSql += " FROM resultTubeShort where numTube=:pnumTube and numFusion=:pnumFusion order by numFusion,numTube";
			SqlDBModule->queryForChart->Close();
			SqlDBModule->queryForChart->SQL->Text = strSql;
			SqlDBModule->queryForChart->Parameters->ParamByName("pnumTube")->Value = TGlSettings::numTube;
			SqlDBModule->queryForChart->Parameters->ParamByName("pnumFusion")->Value = TGlSettings::currFusion;
			SqlDBModule->queryForChart->Open();
			countZones = SqlDBModule->queryForChart->FieldByName("countZones")->AsInteger;
			err = RecalcData(TGlSettings::currFusion, TGlSettings::numTube, TGlSettings::thresholdTNominal, TGlSettings::thresholdTUp,
				TGlSettings::thresholdTDown, TGlSettings::thresholdC1, TGlSettings::thresholdC2, TGlSettings::thresholdL1,
				TGlSettings::thresholdL2);
			//!!!200
			Sleep(100);
			bbtStop->Enabled = true;
			Application->ProcessMessages();
			int z = SqlDBModule->GetIntFieldSQL("resultTubeShort", "countZones", strSqlWhere, 0, err);
			int lt = z * 100;
			SqlDBModule->UpdFloatSql("resultTubeShort", "lengthTube", lt, strSqlWhere);
			// ------
			// lbxInfo->Clear();
			lbxInfo->AddItem("SqlDBModule->UpdFloatSql(resultTubeShort, lengthTube, lt, strSqlWhere);", NULL);
			// ViewCurrentBorders(TGlSettings::currFusion, TGlSettings::numTube);
			double valBorderTMin =
				RoundTo((TGlSettings::thresholdTNominal - TGlSettings::thresholdTDown * TGlSettings::thresholdTNominal / 100.0), -1);
			double valBorderTMax =
				RoundTo((TGlSettings::thresholdTNominal + TGlSettings::thresholdTUp * TGlSettings::thresholdTNominal / 100.0), -1);

			// lbxInfo->AddItem("flags  isReady=" + IntToStr(SqlDBModule->GetIntFieldSQL("flags", "isReady", "isActual=1", 0, err)), NULL);
			// if (!TGlSettings::repeatControl) {
			if (!menuRepeatControl->Checked) { // если не повторный контроль
				SqlDBModule->queryQuick->Close();
				if (menuSOP->Checked) {
					strSql = "select max(numTube) as F1 from resultTubeShort where numTube>0 and isSop=1 and numFusion=" +
						IntToStr(TGlSettings::currFusion);
				}
				else {
					strSql = "select max(numTube) as F1 from resultTubeShort where numTube>0 and isSop=0 and numFusion=" +
						IntToStr(TGlSettings::currFusion);
				}

				TGlSettings::numTube = SqlDBModule->GetIntFromSql(strSql);
				tmpInt = TGlSettings::numTube;
				// ------------------------------

			}
			else {
				TGlSettings::numTube = TGlSettings::repeatControlNumTube;
				int aa = TGlSettings::numTube;
			}
			bool bT = cbThick->Checked;
			bool bC = cbCross->Checked;
			bool bL = cbLong->Checked;
			if (bT && errT == 0 || bC && errC == 0 || bL && errL == 0) { // что-то пришло
				SqlDBModule->UpdIntSql(" flags ", " isReady ", 0, NULL);
				SqlDBModule->UpdIntSql("resultTubeShort", "isEmpty", 0, strSqlWhere);
				lbxInfo->AddItem("Сняли готовность по первым данным", NULL);
				bbtMode->Font->Color = clYellow;
				Application->ProcessMessages();
				// TimerUpdateState->Enabled = true;
				Sleep(500);
				// return;
			}
			else {
				//
			}
			if (bT && errT > 0 || bC && errC > 0 || bL && errL > 0) {
				if(bT)lbxInfo->AddItem("errT isEmpty code=" + IntToStr(errT), NULL);
				if(bC)lbxInfo->AddItem("errC isEmpty code=" + IntToStr(errC), NULL);
				if(bL)lbxInfo->AddItem("errL isEmpty code=" + IntToStr(errL), NULL);
				if ((bool)SqlDBModule->GetIntFieldSQL("flags", "isReady", "isActual=1", 0, err)) {
					lbxInfo->AddItem("Состояние готовность = 1", NULL);
				}
				else {
					lbxInfo->AddItem("Состояние готовность = 0", NULL);
				}
				Application->ProcessMessages();
				// err = CreateTables(TGlSettings::currFusion, (TGlSettings::numTube+1));
				// bbtStopClick(bbtStop);
				// return;
				if (continueWait) {
					//
				}
				else {
					secYearBeginWait = SecondOfTheYear(Now());
					continueWait = true;
				}
				LongWord secNowWait = SecondOfTheYear(Now());
			}
			else if(bT || bC || bL){
				   (*(__store_base__ *)this)(err);
			}
			err = CheckBrakCount(TGlSettings::currFusion);
		}

		TimerUpdateState->Enabled = true;
		err = 0;
	}
	catch (Exception *ex) {
		// err = -1;
		TLog::ErrFullSaveLog(ex);
		// AnsiString msg
		// programSettings.colorMSG = programSettings.colorBrak;
		// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}

}

// ---------------------------------------------------------------------------
void __fastcall TfmMain::BitBtn1Click(TObject *Sender) {
	// if (intTstFuz1 != intTstFuz2) {
	// testCounter++;
	// }
	// else {
	// // testCounter = 0;
	// testCounter++;
	// }
	// TGlSettings::numTube = testCounter + 1;
	// bbtCountControl->Caption = " ПРОКОНТРОЛИРОВАНО " + IntToStr(testCounter);
	// SqlDBModule->UpdFloatSql("currentSettings", "ParamValueFloat", testCounter, "UPPER(ParamName)=UPPER('numCurrTube')");
	// CreateTables();
	// int f = 34;
	// int t = 11;
	// int cc = 0;
	// // CheckBrakLong(f, t);
	// // CheckBrakCross(f, t);
	// SqlDBModule->queryQuick->Close();
	// SqlDBModule->queryQuick->SQL->Text = "select count(*) as F1 from resultTubeShort where numFusion=34";
	// SqlDBModule->queryQuick->Open();
	// cc = SqlDBModule->queryQuick->FieldByName("F1")->AsInteger;
	// SqlDBModule->queryQuick->Close();
	// TGlSettings::thresholdTUp = 20;
	// TGlSettings::thresholdTDown = 12.5;
	// for (int i = 1; i < (cc + 1); i++) {
	// CheckBrakThick(34, i);
	// }
	// GetDataThick(22112, 3);
}
// ---------------------------------------------------------------------------

void __fastcall TfmMain::menuGSettingsClick(TObject *Sender) {
	// AnsiString strSql =
	// " SELECT rec_id as '№', normDocName as 'Наименование документа', isActive as 'Активный' FROM normDocs order by normDocName ";
	// fmSetDirectory = new TfmSetDirectory(NULL);
	// fmSetDirectory->queryDirectory->Close();
	// fmSetDirectory->queryDirectory->SQL->Text = strSql;
	// fmSetDirectory->queryDirectory->Open();
	// fmSetDirectory->ShowModal();
	// delete fmSetDirectory
	fmGSettings = new TfmGSettings(this);
	fmGSettings->ShowModal();
	delete fmGSettings;
}
// ---------------------------------------------------------------------------

void __fastcall TfmMain::FormCloseQuery(TObject *Sender, bool &CanClose) {

	if (TGlSettings::isWorkState) {
		MessageDlg("Программа в рабочем режиме, закрытие невозможно!", mtError, TMsgDlgButtons() << mbOK, NULL);
		CanClose = false;
		return;
	}
	else {
		//
	}
	if (MessageDlg("Закрыть программу?", mtWarning, TMsgDlgButtons() << mbOK << mbCancel, 0) == mrOk) {
		CanClose = true;
	}
	else {
		CanClose = false;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfmMain::cbxTubesTypeSizeSelect(TObject *Sender) {
	int err = 0;
	// TGlSettings::thresholdTNominal = SqlDBModule->GetFloatFieldSQL("tubesTypeSize", "tubeThick",
	// "isActive = 1 and rec_id=" + IntToStr(TGlSettings::indTypeSize), 3, err);
	ReLoadInitSettings();
}

// ---------------------------------------------------------------------------
void __fastcall TfmMain::timerFreeSpaseTimer(TObject *Sender) {
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
		// lbeIp4->Text = strIp;
		lbxInfo->AddItem("IP4 " + strIp, NULL);
		GetLogicalDrives();
		spaceF = (__int64)DiskFree(0) / 1024 / 1024;
		// lbeFreeSpaceM->Text = IntToStr((int)spaceF) + " Mb";
		spaceT = (__int64)DiskSize(0) / 1024 / 1024;
		perc = (double)spaceF / spaceT * 100.0;
		// lbeFreeSpaceP->Font->Color = clBlack;
		// lbeFreeSpaceP->Color = clMoneyGreen;
		if (perc < 10) {
			// lbeFreeSpaceP->Color = clRed;
		}
		else {
			if (perc < 20) {
				// lbeFreeSpaceP->Color = clYellow;
			}
			else {
				// lbeFreeSpaceP->Color = clMoneyGreen;
			}
		}

		// lbeFreeSpaceP->Text = FloatToStrF(perc, ffFixed, 4, 2) + " %";
		lbxInfo->AddItem("Свободно " + FloatToStrF(perc, ffFixed, 4, 2) + " %", NULL);
		// -----------------------------
		strSql = "SELECT [dbo].[GetDBSizeMb]() as F1";
		szDb = SqlDBModule->GetDoubleFromFunctionSql(strSql, err);
		// lbeSzDB->Text = FloatToStrF(szDb, ffFixed, 6, 2);
		lbxInfo->AddItem("Размер БД " + FloatToStrF(szDb, ffFixed, 6, 2) + " Мб", NULL);
		double limit = 10.0; // 10 Gb
		if (szDb > ((limit - 1) * 1024)) {
			// lbeFreeSpaceP->Color = clRed;
		}
		else {
			if (szDb > ((limit - 2) * 1024)) {
				// lbeFreeSpaceP->Color = clYellow;
			}
			else {
				// lbeFreeSpaceP->Color = clMoneyGreen;
			}
		}
		err = 0;
	}
	catch (Exception *ex) {
		err = -2;
		TLog::ErrFullSaveLog(ex);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);

	}
}

// ---------------------------------------------------------------------------
int TfmMain::GetNodesBorders(int _indTypeSize, int _numFusion, int _numTube) {
	int err = 0;
	TReplaceFlags ReplaceFlags;
	try {
		int err = 0;
		int count = 0;
		double tmpD = 0;
		UnicodeString strXml = "";
		UnicodeString strSql = "";
		UnicodeString strTmp = "";
		// Толщиномер
		// strSql="SELECT PCross FROM ResultPars where TypeSize=3 and Fusion=11 and Tube=7";
		lbxInfo->Clear();
		lbxInfo->AddItem("Толщиномер", NULL);
		// strSql = "SELECT PThick FROM ResultPars where TypeSize=3 and Fusion=12 and Tube=1";
		strSql = "SELECT PThick from ResultPars where ";
		strSql += " TypeSize=" + IntToStr(_indTypeSize);
		strSql += " and Fusion=" + IntToStr(_numFusion);
		strSql += " and Tube=" + IntToStr(_numTube);
		queryXML->Close();
		queryXML->SQL->Text = strSql;
		queryXML->Open();
		count = queryXML->RecordCount;
		strXml = queryXML->FieldByName("PThick")->AsString;
		if (strXml == "") {
			lbxInfo->AddItem("Нет настроек T!", NULL);
			// TGlSettings::thresholdTUp = 20;
			// TGlSettings::thresholdTDown = 12.5;
		}
		else {
			XMLDocument->LoadFromXML(strXml);
			queryXML->Close();
			// strTmp = XMLDocument->DocumentElement->GetNodeName();
			// _di_IXMLNode nodeUp = XMLDocument->DocumentElement->GetChildNodes()->FindNode("ABorders");
			// count = nodeUp->GetChildNodes()->GetCount();
			// _di_IXMLNode nodeChild1 = nodeUp->GetChildNodes()->Get(0);
			// strTmp = nodeChild1->GetNodeValue();
			// _di_IXMLNode nodeChild2 = nodeUp->GetChildNodes()->Get(1);
			// strTmp = nodeChild2->GetNodeValue();
			// ListBox1->AddItem(XMLDocument->DocumentElement->GetNodeName(), NULL);
			_di_IXMLNode Upper = XMLDocument->DocumentElement->GetChildNodes()->FindNode("rtTS");
			count = Upper->GetChildNodes()->GetCount();
			// ListBox1->AddItem(Upper->GetNodeName(), NULL);
			// --------------------
			_di_IXMLNode Child1 = Upper->GetChildNodes()->Get(2);
			lbxInfo->AddItem(Child1->GetNodeName(), NULL);
			lbxInfo->AddItem(Child1->GetNodeValue(), NULL);
			strTmp = Child1->GetNodeValue();
			strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
			TGlSettings::thresholdTUp = StrToFloat(strTmp);
			// // --------
			_di_IXMLNode Child2 = Upper->GetChildNodes()->Get(3);
			lbxInfo->AddItem(Child2->GetNodeName(), NULL);
			lbxInfo->AddItem(Child2->GetNodeValue(), NULL);
			strTmp = Child2->GetNodeValue();
			// function StringReplace(const S, OldPattern, NewPattern: AnsiString; Flags: TReplaceFlags): AnsiString;
			// To work with UnicodeString variables, use the System.SysUtils.StringReplace function.
			// TReplaceFlags = set of (rfReplaceAll, rfIgnoreCase);
			strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
			// tmpD = StrToFloat(strTmp);
			TGlSettings::thresholdTDown = StrToFloat(strTmp);
		}
		// ----------------------------
		// поперечник
		lbxInfo->AddItem("Поперечник", NULL);
		strSql = "SELECT PCross from ResultPars where ";
		strSql += " TypeSize=" + IntToStr(_indTypeSize);
		strSql += " and Fusion=" + IntToStr(_numFusion);
		strSql += " and Tube=" + IntToStr(_numTube);
		queryXML->Close();
		queryXML->SQL->Text = strSql;
		queryXML->Open();
		count = queryXML->RecordCount;
		strXml = queryXML->FieldByName("PCross")->AsString;
		if (strXml == "") {
			// TGlSettings::thresholdC1 = 15;
			// TGlSettings::thresholdC2 = 0;
			err = -3;
			lbxInfo->AddItem("Нет настроек C!", NULL);
			return err;
		}
		else {
			//
		}
		XMLDocument->LoadFromXML(strXml);
		queryXML->Close();
		strTmp = XMLDocument->DocumentElement->GetNodeName();
		_di_IXMLNode nodeUp = XMLDocument->DocumentElement->GetChildNodes()->FindNode("borders");
		count = nodeUp->GetChildNodes()->GetCount();
		_di_IXMLNode nodeChild1 = nodeUp->GetChildNodes()->Get(0);
		lbxInfo->AddItem(nodeChild1->GetNodeName(), NULL);
		lbxInfo->AddItem(nodeChild1->GetNodeValue(), NULL);
		strTmp = nodeChild1->GetNodeValue();
		strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		// tmpD = StrToFloat(strTmp);
		TGlSettings::thresholdC1 = StrToFloat(strTmp);
		// ----------------------------
		_di_IXMLNode nodeChild2 = nodeUp->GetChildNodes()->Get(1);
		lbxInfo->AddItem(nodeChild2->GetNodeName(), NULL);
		lbxInfo->AddItem(nodeChild2->GetNodeValue(), NULL);
		strTmp = nodeChild2->GetNodeValue();
		strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		tmpD = StrToFloat(strTmp);
		TGlSettings::thresholdC2 = StrToFloat(strTmp);
		// ----------------------
		// продольник
		lbxInfo->AddItem("Продольник", NULL);
		// strSql="SELECT PCross FROM ResultPars where TypeSize=3 and Fusion=11 and Tube=7";
		// strSql="SELECT PCross FROM ResultPars where TypeSize=3 and Fusion=12 and Tube=1";
		strSql = "SELECT PLine from ResultPars where ";
		strSql += " TypeSize=" + IntToStr(_indTypeSize);
		strSql += " and Fusion=" + IntToStr(_numFusion);
		strSql += " and Tube=" + IntToStr(_numTube);
		queryXML->Close();
		queryXML->SQL->Text = strSql;
		queryXML->Open();
		count = queryXML->RecordCount;
		strXml = queryXML->FieldByName("PLine")->AsString;
		if (strXml == "") {
			// TGlSettings::thresholdL1 = 50;
			// TGlSettings::thresholdL2 = 0;
			err = -3;
			lbxInfo->AddItem("Нет настроек L!", NULL);
			return err;
		}
		else {
			//
		}
		XMLDocument->LoadFromXML(strXml);
		queryXML->Close();
		strTmp = XMLDocument->DocumentElement->GetNodeName();
		nodeUp = XMLDocument->DocumentElement->GetChildNodes()->FindNode("borders");
		count = nodeUp->GetChildNodes()->GetCount();
		nodeChild1 = nodeUp->GetChildNodes()->Get(0);
		lbxInfo->AddItem(nodeChild1->GetNodeName(), NULL);
		lbxInfo->AddItem(nodeChild1->GetNodeValue(), NULL);
		strTmp = nodeChild1->GetNodeValue();
		strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		TGlSettings::thresholdL1 = StrToFloat(strTmp);
		nodeChild2 = nodeUp->GetChildNodes()->Get(1);
		lbxInfo->AddItem(nodeChild2->GetNodeName(), NULL);
		lbxInfo->AddItem(nodeChild2->GetNodeValue(), NULL);
		strTmp = nodeChild2->GetNodeValue();
		strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		// tmpD=StrToFloat(strTmp);
		TGlSettings::thresholdL2 = StrToFloat(strTmp);
		ViewCurrentBorders(TGlSettings::currFusion, TGlSettings::numTube - 1);
	}
	catch (Exception *ex) {
		err = -2;
		TLog::ErrFullSaveLog(ex);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);

	}
}

int TfmMain::CheckBrakCross(int _numFusion, int _numTube, int &_status) {
	int err = 0;
	AnsiString strSql = "";
	int itmp = 0;
	std::vector<double>::iterator result;
	int indMax;
	vector<double>vecMaxCh;
	AnsiString strWhere = "";
	AnsiString strTmp = "";
	int countNulls = 0;
	int countBrack = 0;
	// "Fusion="+IntToStr(TGlSettings::currFusion);
	// strWhere = "Fusion=" + IntToStr(11);
	// strWhere += " and ";
	// strWhere+=" tube= "+IntToStr(TGlSettings::_numTube);
	try {
		strWhere = "numFusion=" + IntToStr(_numFusion);
		strWhere += " and ";
		strWhere += " numTube= " + IntToStr(_numTube);
		strSql = "SELECT numFusion, numTube";
		for (int i = 0; i < TGlSettings::countZones; i++) {
			strSql += ",Z" + IntToStr(i + 1);
		}
		strSql += ",sensorNum";
		strSql += " FROM resultCross where numTube=:pnumTube and numFusion=:pnumFusion order by numFusion,numTube,sensorNum";
		// по зонам поперечник
		SqlDBModule->queryQuick->Close();
		SqlDBModule->queryQuick->SQL->Text = strSql;
		SqlDBModule->queryQuick->Parameters->ParamByName("pnumTube")->Value = _numTube;
		SqlDBModule->queryQuick->Parameters->ParamByName("pnumFusion")->Value = _numFusion;
		SqlDBModule->queryQuick->Open();
		if (SqlDBModule->queryQuick->RecordCount == 0) {
			// MessageDlg("Данных по дефектам МНК2 нет!", mtWarning, TMsgDlgButtons() << mbOK, NULL);
		}
		else {
			// // подготовим вектор
			// for (int i = 0; i < TGlSettings::countSensorsCross; i++) {
			// vecMaxCh.push_back(0);
		}
		// // // заберем данные по поперечнику
		SqlDBModule->queryQuick->First();
		int s = 0;
		// // // while (!SqlDBModule->queryQuick->Eof) {
		itmp = TGlSettings::countSensorsCross;
		for (int i = 0; i < TGlSettings::countSensorsCross; i++) {
			// vector<double>vecTmp;
			for (int z = 0; z < TGlSettings::countZones; z++) {
				double val = 0;
				AnsiString fn = "Z" + IntToStr(z + 1);
				strTmp = SqlDBModule->queryQuick->FieldByName("Z" + IntToStr(z + 1))->AsString;
				if (strTmp == "") {
					countNulls++;
					val = 0;
				}
				else {
					val = SqlDBModule->queryQuick->FieldByName("Z" + IntToStr(z + 1))->AsFloat;
					if (val > 100) {
						val = 100;
					}
					else {
						// // //
					}
					if (val > TGlSettings::thresholdC1) {
						countBrack++;
						// SqlDBModule->UpdIntSql("resultTubeShort", "resultC", countBrack, strWhere);
						// break;
					}
					else {
						//
					}
				}
				// // vecTmp.push_back(val);
			}
			// sensorsDataCross.push_back(vecTmp);
			SqlDBModule->queryQuick->Next();
		}
		if (countNulls == (TGlSettings::countZones * TGlSettings::countSensorsCross)) {
			_status = -1;
			SqlDBModule->UpdIntSql("resultTubeShort", "resultC", _status, strWhere);
		}
		else {
			SqlDBModule->UpdIntSql("resultTubeShort", "resultC", countBrack, strWhere);
		}
		SqlDBModule->queryQuick->Close();
		int err = 0;
	}
	catch (Exception *ex) {
		err = -2;
		TLog::ErrFullSaveLog(ex);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);

	}
	return err;
}

int TfmMain::CheckBrakLong(int _numFusion, int _numTube, int &_status) {
	int err = 0;
	AnsiString strSql = "";
	int itmp = 0;
	std::vector<double>::iterator result;
	int indMax;
	vector<double>vecMaxCh;
	AnsiString strWhere = "";
	AnsiString strTmp = "";
	int countNulls = 0;
	int countBrack = 0;
	// "Fusion="+IntToStr(TGlSettings::currFusion);
	// strWhere = "Fusion=" + IntToStr(11);
	// strWhere += " and ";
	// strWhere+=" tube= "+IntToStr(TGlSettings::numTube);
	try {
		_status = 0;
		strWhere = "numFusion=" + IntToStr(_numFusion);
		strWhere += " and ";
		strWhere += " numTube= " + IntToStr(_numTube);
		strSql = "SELECT numFusion, numTube";
		for (int i = 0; i < TGlSettings::countZones; i++) {
			strSql += ",Z" + IntToStr(i + 1);
		}
		strSql += ",sensorNum";
		strSql += " FROM resultLong where numTube=:pnumTube and numFusion=:pnumFusion order by numFusion,numTube,sensorNum";
		// по зонам поперечник
		SqlDBModule->queryQuick->Close();
		SqlDBModule->queryQuick->SQL->Text = strSql;
		SqlDBModule->queryQuick->Parameters->ParamByName("pnumTube")->Value = _numTube;
		SqlDBModule->queryQuick->Parameters->ParamByName("pnumFusion")->Value = _numFusion;
		SqlDBModule->queryQuick->Open();
		if (SqlDBModule->queryQuick->RecordCount == 0) {
			// MessageDlg("Данных по дефектам МНК2 нет!", mtWarning, TMsgDlgButtons() << mbOK, NULL);
		}
		else {
			// // подготовим вектор
			// for (int i = 0; i < TGlSettings::countSensorsCross; i++) {
			// vecMaxCh.push_back(0);
		}
		// // // заберем данные по поперечнику
		SqlDBModule->queryQuick->First();
		int s = 0;
		// // // while (!SqlDBModule->queryQuick->Eof) {
		itmp = TGlSettings::countSensorsCross;
		for (int i = 0; i < TGlSettings::countSensorsLong; i++) {
			// vector<double>vecTmp;
			for (int z = 0; z < TGlSettings::countZones; z++) {
				double val = 0;
				AnsiString fn = "Z" + IntToStr(z + 1);
				strTmp = SqlDBModule->queryQuick->FieldByName("Z" + IntToStr(z + 1))->AsString;
				if (strTmp == "") {
					countNulls++;
					val = 0;
				}
				else {
					val = SqlDBModule->queryQuick->FieldByName("Z" + IntToStr(z + 1))->AsFloat;
					if (val > 100) {
						val = 100;
					}
					else {
						// // //
					}
					if (val > TGlSettings::thresholdL1) {
						// SqlDBModule->UpdIntSql("resultTubeShort", "resultL", _status, strWhere);
						countBrack++;
						// break;
					}
					else {
						//
					}
				}
				// // vecTmp.push_back(val);
			}
			// sensorsDataCross.push_back(vecTmp);
			SqlDBModule->queryQuick->Next();
		}
		if (countNulls == (TGlSettings::countZones * TGlSettings::countSensorsLong)) {
			_status = -1;
			SqlDBModule->UpdIntSql("resultTubeShort", "resultL", _status, strWhere);
		}
		else {
			SqlDBModule->UpdIntSql("resultTubeShort", "resultL", countBrack, strWhere);
		}
		SqlDBModule->queryQuick->Close();
		err = 0;
	}
	catch (Exception *ex) {
		err = -2;
		TLog::ErrFullSaveLog(ex);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);

	}
	return err;
}

//
int TfmMain::CheckBrakThick(int _numFusion, int _numTube, int &_status) {
	// strWhere = "numFusion=" + IntToStr(11);
	// strWhere += " and ";
	// strWhere+=" numTube= "+IntToStr(TGlSettings::numTube);
	AnsiString strSql = "";
	int err = 0;
	int itmp = 0;
	double tmpD = 0;
	std::vector<double>::iterator result;
	int indMax;
	double valBborderProcUp = 0;
	double valBborderProcD = 0;
	double valBorderMin = 0;
	double valBorderMax = 0;
	double valChart = 0;
	double valT = 0;
	int countNulls = 0;
	AnsiString strWhere = "";
	AnsiString strTmp = "";
	int countBrack;
	try {
		_status = 0;
		strWhere = "numFusion=" + IntToStr(_numFusion);
		strWhere += " and ";
		strWhere += " numTube= " + IntToStr(_numTube);
		SqlDBModule->queryQuick->Close();
		// TGlSettings::thresholdTDown = 12.5;
		// TGlSettings::thresholdTUp = 30;
		valBborderProcUp = TGlSettings::thresholdTUp;
		valBborderProcD = TGlSettings::thresholdTDown;
		tmpD = TGlSettings::thresholdTNominal;
		tmpD = valBborderProcD * TGlSettings::thresholdTNominal / 100.0;
		tmpD = valBborderProcUp * TGlSettings::thresholdTNominal / 100.0;
		valBorderMin = RoundTo((TGlSettings::thresholdTNominal - valBborderProcD * TGlSettings::thresholdTNominal / 100.0), -1);
		valBorderMax = RoundTo((TGlSettings::thresholdTNominal + valBborderProcUp * TGlSettings::thresholdTNominal / 100.0), -1);
		SqlDBModule->queryQuick->Close();
		strSql = "SELECT numFusion, numTube";
		for (int i = 0; i < TGlSettings::countZones; i++) {
			strSql += ",Min" + IntToStr(i + 1);
		}
		for (int i = 0; i < TGlSettings::countZones; i++) {
			strSql += ",Max" + IntToStr(i + 1);
		}
		strSql += ",sensorNum";
		strSql += " FROM resultThick where numTube=:pnumTube and numFusion=:pnumFusion order by numFusion,numTube,sensorNum";
		SqlDBModule->queryQuick->SQL->Text = strSql;
		SqlDBModule->queryQuick->Parameters->ParamByName("pnumTube")->Value = _numTube;
		SqlDBModule->queryQuick->Parameters->ParamByName("pnumFusion")->Value = _numFusion;
		SqlDBModule->queryQuick->Open();
		// ---------------- min
		SqlDBModule->queryQuick->First();
		if (SqlDBModule->queryQuick->RecordCount == 0) {
			// MessageDlg("МНК 1 - данных нет!", mtWarning, TMsgDlgButtons() << mbOK, NULL);
			err = 0;
			return err;
		}
		else {
			//
		}
		// // заберем данные по толщиномеру min
		// while (!SqlDBModule->queryQuick->Eof) {
		itmp = TGlSettings::countRecordsThick;
		for (int i = 0; i < TGlSettings::countRecordsThick; i++) {
			vector<double>vecTmp;
			for (int z = 0; z < TGlSettings::countZones; z++) {
				AnsiString fn = "Min" + IntToStr(z + 1);
				strTmp = SqlDBModule->queryQuick->FieldByName("Min" + IntToStr(z + 1))->AsString;
				if (strTmp == "") {
					// val = -1;
					countNulls++;
					valT = TGlSettings::thresholdTNominal;
				}
				else {
					valT = SqlDBModule->queryQuick->FieldByName("Min" + IntToStr(z + 1))->AsFloat;

					if (valT == -1) {
						valT = TGlSettings::thresholdTNominal;
					}
					else {
						//
					}
				}
				//
				// TGlSettings::thresholdTNominal
				vecTmp.push_back(valT);
				if (valT < valBorderMin) {
					// strTmp = "Min" + IntToStr(z + 1) + " s=" + IntToStr(i) + " val=" + FloatToStr(valT);
					countBrack++;
				}
				else {
					//
				}
			}
			SqlDBModule->queryQuick->Next();
		}
		// ---------------- max
		// заберем данные по толщиномеру
		SqlDBModule->queryQuick->First();
		// while (!SqlDBModule->queryQuick->Eof) {
		itmp = TGlSettings::countRecordsThick;
		for (int i = 0; i < TGlSettings::countRecordsThick; i++) {
			vector<double>vecTmp;
			for (int z = 0; z < TGlSettings::countZones; z++) {
				AnsiString fn = "Max" + IntToStr(z + 1);
				strTmp = SqlDBModule->queryQuick->FieldByName("Max" + IntToStr(z + 1))->AsString;
				if (strTmp == "") {
					// val = -1;
					valT = TGlSettings::thresholdTNominal;
				}
				else {
					if (valT < 0) {
						valT = TGlSettings::thresholdTNominal;
					}
					else {
						valT = SqlDBModule->queryQuick->FieldByName("Max" + IntToStr(z + 1))->AsFloat;
					}

				}
				vecTmp.push_back(valT);
				if (valT > valBorderMax) {
					// SqlDBModule->UpdIntSql("resultTubeShort", "resultT", 1, strWhere);
					countBrack++;
				}
				else {
					//
				}
			}
			SqlDBModule->queryQuick->Next();
		}
		if (countNulls == (TGlSettings::countZones * TGlSettings::countRecordsThick)) {
			_status = -1;
			SqlDBModule->UpdIntSql("resultTubeShort", "resultT", _status, strWhere);
		}
		else {
			SqlDBModule->UpdIntSql("resultTubeShort", "resultT", countBrack, strWhere);
		}

		SqlDBModule->queryQuick->Close();
		err = 0;
	}
	catch (Exception *ex) {
		err = -2;
		TLog::ErrFullSaveLog(ex);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);

	}
}

int TfmMain::CheckBrakCount(int _numFusion) {
	int err = 0;
	AnsiString strSql = "";
	try {
		strSql = "select count(*) as F1 from resultTubeShort  where numTube>0 and numFusion=";
		strSql += IntToStr(_numFusion);
		strSql += " and resultT>0 and isEmpty=0";
		TGlSettings::countBrakT = SqlDBModule->GetIntFromSql(strSql);
		bbtBrakThick->Caption = "ДЕФЕКТ МНК1          " + IntToStr(TGlSettings::countBrakT);
		// ---
		strSql = "select count(*) as F1 from resultTubeShort  where numTube>0 and numFusion=";
		strSql += IntToStr(_numFusion);
		strSql += " and resultC>0 and isEmpty=0";
		TGlSettings::countBrakC = SqlDBModule->GetIntFromSql(strSql);
		bbtBrakCross->Caption = "ДЕФЕКТ МНК2          " + IntToStr(TGlSettings::countBrakC);
		// ---
		strSql = "select count(*) as F1 from resultTubeShort where numTube>0 and numFusion=";
		strSql += IntToStr(TGlSettings::currFusion);
		strSql += " and resultL>0 and isEmpty=0";
		TGlSettings::countBrakL = SqlDBModule->GetIntFromSql(strSql);
		bblBrakLong->Caption = "ДЕФЕКТ МНК3           " + IntToStr(TGlSettings::countBrakL);
		// ----
		strSql = "select count(*) as F1 from resultTubeShort where numTube>0 and numFusion=";
		strSql += IntToStr(_numFusion);
		strSql += " and (resultC>0 ";
		strSql += " or resultL>0 ";
		strSql += " or resultT>0) and isEmpty=0";
		TGlSettings::countBrakALL = SqlDBModule->GetIntFromSql(strSql);
		// TGlSettings::countBrakALL = TGlSettings:  :countBrakC + TGlSettings::countBrakL + TGlSettings::countBrakT;
		bbtBrakALL->Caption = "ДЕФЕКТ        ВСЕГО          " + IntToStr(TGlSettings::countBrakALL);
		// --
		// TGlSettings::countTubesFusion++;
	}
	catch (Exception *ex) {
		err = -2;
		TLog::ErrFullSaveLog(ex);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);

	}
}

int TfmMain::GetBordersC(int _indTypeSize, int _numFusion, int _numTube) {
	int err = 0;
	int count = 0;
	UnicodeString strXml = "";
	UnicodeString strSql = "";
	UnicodeString strTmp = "";
	TReplaceFlags ReplaceFlags;
	try {
		// strSql="SELECT PCross FROM ResultPars where TypeSize=3 and Fusion=11 and Tube=7";
		// strSql="SELECT PCross FROM ResultPars where TypeSize=3 and Fusion=12 and Tube=1";
		// strSql = "SELECT PCross from ResultPars where ";
		// strSql += " Fusion=" + IntToStr(_numFusion);
		// strSql += " and Tube=" + IntToStr(_numTube);
		// queryXML->Close();
		// queryXML->SQL->Text = strSql;
		// queryXML->Open();
		// count = queryXML->RecordCount;
		// strXml = queryXML->FieldByName("PCross")->AsString;
		// ------------------------+
		// strSql = "SELECT [dbo].[GetBorderCrossXML1] (";
		// strSql += IntToStr(TGlSettings::currFusion);
		// strSql += ",";
		// strSql += IntToStr(TGlSettings::numTube);
		// strSql += ") as F1";
		strSql = "SELECT [dbo].[GetTzBorderC1] (";
		strSql += IntToStr(TGlSettings::indTypeSize);
		strSql += ") as F1";
		strTmp = SqlDBModule->GetStrFromFunctionSql(strSql, err);
		strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		TGlSettings::thresholdC1 = StrToFloat(strTmp);
		// strSql = "SELECT [dbo].[GetBorderCrossXML2] (";
		// strSql += IntToStr(TGlSettings::currFusion);
		// strSql += ",";
		// strSql += IntToStr(TGlSettings::numTube);
		// strSql += ") as F1";
		strSql = "SELECT [dbo].[GetTzBorderC2] (";
		strSql += IntToStr(TGlSettings::indTypeSize);
		strSql += ") as F1";
		AnsiString strTmp2 = SqlDBModule->GetStrFromFunctionSql(strSql, err);
		strTmp2 = StringReplace(strTmp2, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		if (strTmp2 == -1) {
			TGlSettings::thresholdC2 = 0;
		}
		else {
			TGlSettings::thresholdC2 = StrToFloat(strTmp2);
		}
		// ----------------------
		if (strTmp == "" || (strTmp == -1 && strTmp2 == -1)) {
			// TGlSettings::thresholdC1 = 15;
			// TGlSettings::thresholdC2 = 0;
			err = -3;
			lbxInfo->AddItem("Нет настроек поперечника!", NULL);
			// pnlMsg->Caption = "Нет настроек поперечника!";
			// pnlMsg->Font->Color=clBlack;
			// pnlMsg->Refresh();
			// TLog::SaveStrMsgLog("Не дождались настроек поперечника!");
			// пробуем загрузить дефолтовые
			AnsiString strSql = " SELECT thresholdC1";
			strSql += ",thresholdC2";
			strSql += ",currMagnetC";
			strSql += ",speedRotor";
			strSql += " FROM TypeSizesParams";
			strSql += " WHERE indTypeSize =:pindTypeSize";
			queryTSize->Close();
			queryTSize->SQL->Text = strSql;
			queryTSize->Parameters->ParamByName("pindTypeSize")->Value = TGlSettings::indTypeSize;
			queryTSize->Open();
			if (queryTSize->RecordCount == 0) { // нет записей
				strSql = "INSERT INTO TypeSizesParams (";
				strSql += "indTypeSize";
				strSql += ",thresholdC1";
				strSql += ",thresholdC2";
				strSql += ",currMagnetC";
				strSql += ",speedRotor)";
				strSql += " VALUES(";
				strSql += ":pindTypeSize";
				strSql += ",:pthresholdC1";
				strSql += ",:pthresholdC2";
				strSql += ",:pcurrMagnetC";
				strSql += ",:pspeedRotor)";
				queryTSize->Close();
				queryTSize->SQL->Text = strSql;
				TGlSettings::thresholdC1 = 15;
				TGlSettings::thresholdL2 = 0;
				queryTSize->Parameters->ParamByName("pindTypeSize")->Value = TGlSettings::indTypeSize;
				queryTSize->Parameters->ParamByName("pthresholdC1")->Value = TGlSettings::thresholdC1;
				queryTSize->Parameters->ParamByName("pthresholdC2")->Value = TGlSettings::thresholdC2;
				queryTSize->Parameters->ParamByName("pcurrMagnetC")->Value = 6;
				queryTSize->ExecSQL();
			}
			strTmp = queryTSize->FieldByName("thresholdC1")->AsString;
			// поле пустое, обновим
			if (strTmp == "") {
				strSql = "UPDATE TypeSizesParams";
				strSql += " SET thresholdC1 = :pthresholdC1";
				strSql += ",thresholdC2 = :pthresholdC2";
				strSql += ",currMagnetC = :pcurrMagnetC";
				strSql += ",speedRotor =  :pspeedRotor";
				strSql += " WHERE indTypeSize =:pindTypeSize";
				queryTSize->Close();
				queryTSize->SQL->Text = strSql;
				queryTSize->Parameters->ParamByName("pthresholdC1")->Value = TGlSettings::thresholdC1;
				queryTSize->Parameters->ParamByName("pthresholdC2")->Value = TGlSettings::thresholdC2;
				queryTSize->Parameters->ParamByName("pindTypeSize")->Value = TGlSettings::indTypeSize;
				queryTSize->ExecSQL();
			}
			else {
				// заберем данные
				TGlSettings::thresholdC1 = queryTSize->FieldByName("thresholdC1")->AsFloat;
				TGlSettings::thresholdC2 = queryTSize->FieldByName("thresholdC2")->AsFloat;
				queryTSize->Close();
				err = 1;
			}
			return err;
		}
		else {

			// XMLDocument->LoadFromXML(strXml);
			// queryXML->Close();
			// strTmp = XMLDocument->DocumentElement->GetNodeName();
			// _di_IXMLNode nodeUp = XMLDocument->DocumentElement->GetChildNodes()->FindNode("borders");
			// count = nodeUp->GetChildNodes()->GetCount();
			// _di_IXMLNode nodeChild1 = nodeUp->GetChildNodes()->Get(0);
			// strTmp = nodeChild1->GetNodeValue();
			// TReplaceFlags ReplaceFlags;
			// strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
			// TGlSettings::thresholdC1 = StrToFloat(strTmp);
			// _di_IXMLNode nodeChild2 = nodeUp->GetChildNodes()->Get(1);
			// strTmp = nodeChild2->GetNodeValue();
			// strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
			// TGlSettings::thresholdC2 = StrToFloat(strTmp);
			// -------------
			strSql = "UPDATE TypeSizesParams";
			strSql += " SET thresholdC1 = :pthresholdC1";
			strSql += ",thresholdC2 = :pthresholdC2";
			strSql += ",currMagnetC = :pcurrMagnetC";
			strSql += ",speedRotor =  :pspeedRotor";
			strSql += " WHERE indTypeSize =:pindTypeSize";
			queryTSize->Close();
			queryTSize->SQL->Text = strSql;
			queryTSize->Parameters->ParamByName("pcurrMagnetC")->Value = TGlSettings::currMagnetC;
			queryTSize->Parameters->ParamByName("pthresholdC1")->Value = TGlSettings::thresholdC1;
			queryTSize->Parameters->ParamByName("pthresholdC2")->Value = TGlSettings::thresholdC2;
			queryTSize->Parameters->ParamByName("pindTypeSize")->Value = TGlSettings::indTypeSize;
			queryTSize->ExecSQL();
			// если не было вставим
			if (queryTSize->RowsAffected == 0) {
				strSql = "INSERT INTO TypeSizesParams (";
				strSql += "indTypeSize";
				strSql += ",thresholdC1";
				strSql += ",thresholdC2";
				strSql += ",currMagnetC";
				strSql += ",speedRotor)";
				strSql += " VALUES(";
				strSql += ":pindTypeSize";
				strSql += ",:pthresholdC1";
				strSql += ",:pthresholdC2";
				strSql += ",:pcurrMagnetC";
				strSql += ",:pspeedRotor)";
				queryTSize->Close();
				queryTSize->SQL->Text = strSql;
				queryTSize->Parameters->ParamByName("pcurrMagnetC")->Value = TGlSettings::currMagnetC;
				queryTSize->Parameters->ParamByName("pthresholdC1")->Value = TGlSettings::thresholdC1;
				queryTSize->Parameters->ParamByName("pthresholdC2")->Value = TGlSettings::thresholdC2;
				queryTSize->Parameters->ParamByName("pindTypeSize")->Value = TGlSettings::indTypeSize;
				queryTSize->ExecSQL();
			}
			else {

			}
		}
		err = 0;
	}
	catch (Exception *ex) {
		err = -2;
		TLog::ErrFullSaveLog(ex);
		TGlSettings::thresholdC1 = 15;
		TGlSettings::thresholdC2 = 0;
		// MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);

	}
	return err;
}

int TfmMain::GetBordersL(int _indTypeSize, int _numFusion, int _numTube) {
	int err = 0;
	int count = 0;
	UnicodeString strXml = "";
	UnicodeString strSql = "";
	UnicodeString strTmp = "";
	TReplaceFlags ReplaceFlags;
	try {
		// strSql="SELECT PCross FROM ResultPars where TypeSize=3 and Fusion=11 and Tube=7";
		// strSql="SELECT PCross FROM ResultPars where TypeSize=3 and Fusion=12 and Tube=1";
		// strSql = "SELECT PLine from ResultPars where ";
		// strSql += " Fusion=" + IntToStr(_numFusion);
		// strSql += " and Tube=" + IntToStr(_numTube);
		// queryXML->Close();
		// queryXML->SQL->Text = strSql;
		// queryXML->Open();
		// count = queryXML->RecordCount;
		// strXml = queryXML->FieldByName("PLine")->AsString;
		// strSql = "SELECT [dbo].[GetBorderLongXML1] (";
		// strSql += IntToStr(TGlSettings::currFusion);
		// strSql += ",";
		// strSql += IntToStr(TGlSettings::numTube);
		// strSql += ") as F1";
		strSql = "SELECT [dbo].[GetTzBorderL1] (";
		strSql += IntToStr(TGlSettings::indTypeSize);
		strSql += ") as F1";
		strTmp = SqlDBModule->GetStrFromFunctionSql(strSql, err);
		strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		TGlSettings::thresholdL1 = StrToFloat(strTmp);
		//
		// strSql = "SELECT [dbo].[GetBorderLongXML2] (";
		// strSql += IntToStr(TGlSettings::currFusion);
		// strSql += ",";
		// strSql += IntToStr(TGlSettings::numTube);
		// strSql += ") as F1";
		strSql = "SELECT [dbo].[GetTzBorderL2] (";
		strSql += IntToStr(TGlSettings::indTypeSize);
		strSql += ") as F1";
		AnsiString strTmp2 = SqlDBModule->GetStrFromFunctionSql(strSql, err);
		strTmp2 = StringReplace(strTmp2, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		if (strTmp2 == -1) {
			TGlSettings::thresholdL2 = 0;
		}
		else {
			TGlSettings::thresholdL2 = StrToFloat(strTmp2);
		}
		// ----------------------
		if (strTmp == "" || (strTmp == -1 && strTmp2 == -1)) {
			// if (strTmp == "" || strTmp == -1) {
			// pnlMsg->Caption = "Нет настроек продольника!";
			// pnlMsg->Color=clBlue;
			// pnlMsg->Refresh();
			lbxInfo->AddItem("Нет настроек продольника!", NULL);
			// пробуем загрузить дефолтовые
			AnsiString strSql = " SELECT thresholdL1";
			strSql += ",thresholdL2";
			strSql += ",currMagnetL";
			strSql += ",speedRotor";
			strSql += " FROM TypeSizesParams";
			strSql += " WHERE indTypeSize =:pindTypeSize";
			queryTSize->Close();
			queryTSize->SQL->Text = strSql;
			queryTSize->Parameters->ParamByName("pindTypeSize")->Value = TGlSettings::indTypeSize;
			queryTSize->Open();
			if (queryTSize->RecordCount == 0) { // нет записей
				strSql = "INSERT INTO TypeSizesParams (";
				strSql += "indTypeSize";
				strSql += ",thresholdL1";
				strSql += ",thresholdL2";
				strSql += ",currMagnetL";
				strSql += ",speedRotor)";
				strSql += " VALUES(";
				strSql += ":pindTypeSize";
				strSql += ",:pthresholdL1";
				strSql += ",:pthresholdL2";
				strSql += ",:pcurrMagnetL";
				strSql += ",:pspeedRotor)";
				queryTSize->Close();
				queryTSize->SQL->Text = strSql;
				TGlSettings::thresholdL1 = 55;
				TGlSettings::thresholdL2 = 0;
				queryTSize->Parameters->ParamByName("pindTypeSize")->Value = TGlSettings::indTypeSize;
				queryTSize->Parameters->ParamByName("pthresholdL1")->Value = TGlSettings::thresholdL1;
				queryTSize->Parameters->ParamByName("pthresholdL2")->Value = TGlSettings::thresholdL2;
				queryTSize->Parameters->ParamByName("pcurrMagnetL")->Value = 7;
				queryTSize->ExecSQL();
			}

			strTmp = queryTSize->FieldByName("thresholdL1")->AsString;
			// поле пустое, обновим
			if (strTmp == "") {
				strSql = "UPDATE TypeSizesParams";
				strSql += " SET thresholdL1 = :pthresholdL1";
				strSql += ",thresholdL2 = :pthresholdL2";
				strSql += ",currMagnetL = :pcurrMagnetL";
				strSql += ",speedRotor =  :pspeedRotor";
				strSql += " WHERE indTypeSize =:pindTypeSize";
				queryTSize->Close();
				queryTSize->SQL->Text = strSql;
				queryTSize->Parameters->ParamByName("pthresholdL1")->Value = TGlSettings::thresholdL1;
				queryTSize->Parameters->ParamByName("pthresholdL2")->Value = TGlSettings::thresholdL2;
				queryTSize->Parameters->ParamByName("pindTypeSize")->Value = TGlSettings::indTypeSize;
				queryTSize->ExecSQL();
			}
			else {
				// заберем данные
				TGlSettings::thresholdL1 = queryTSize->FieldByName("thresholdL1")->AsFloat;
				TGlSettings::thresholdL2 = queryTSize->FieldByName("thresholdL2")->AsFloat;
				queryTSize->Close();
				err = 1;
				return err;
			}
		}
		else {
			// XMLDocument->LoadFromXML(strXml);
			// queryXML->Close();
			// strTmp = XMLDocument->DocumentElement->GetNodeName();
			// _di_IXMLNode nodeUp = XMLDocument->DocumentElement->GetChildNodes()->FindNode("borders");
			// count = nodeUp->GetChildNodes()->GetCount();
			// _di_IXMLNode nodeChild1 = nodeUp->GetChildNodes()->Get(0);
			// TReplaceFlags ReplaceFlags;
			// strTmp = nodeChild1->GetNodeValue();
			// strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
			// TGlSettings::thresholdL1 = StrToFloat(strTmp);
			// _di_IXMLNode nodeChild2 = nodeUp->GetChildNodes()->Get(1);
			// strTmp = nodeChild2->GetNodeValue();
			// strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
			// // tmpD=StrToFloat(strTmp);
			// TGlSettings::thresholdL2 = StrToFloat(strTmp);
			// -------------
			strSql = "UPDATE TypeSizesParams";
			strSql += " SET thresholdL1 = :pthresholdL1";
			strSql += ",thresholdL2 = :pthresholdL2";
			strSql += ",currMagnetL = :pcurrMagnetL";
			strSql += ",speedRotor =  :pspeedRotor";
			strSql += " WHERE indTypeSize =:pindTypeSize";
			queryTSize->Close();
			queryTSize->SQL->Text = strSql;
			queryTSize->Parameters->ParamByName("pcurrMagnetL")->Value = TGlSettings::currMagnetL;
			queryTSize->Parameters->ParamByName("pthresholdL1")->Value = TGlSettings::thresholdL1;
			queryTSize->Parameters->ParamByName("pthresholdL2")->Value = TGlSettings::thresholdL2;
			queryTSize->Parameters->ParamByName("pindTypeSize")->Value = TGlSettings::indTypeSize;
			queryTSize->ExecSQL();
			// если не было вставим
			if (queryTSize->RowsAffected == 0) {
				strSql = "INSERT INTO TypeSizesParams (";
				strSql += "indTypeSize";
				strSql += ",thresholdL1";
				strSql += ",thresholdL2";
				strSql += ",currMagnetL";
				strSql += ",speedRotor)";
				strSql += " VALUES(";
				strSql += ":pindTypeSize";
				strSql += ",:pthresholdL1";
				strSql += ",:pthresholdL2";
				strSql += ",:pcurrMagnetL";
				strSql += ",:pspeedRotor)";
				queryTSize->Close();
				queryTSize->SQL->Text = strSql;
				queryTSize->Parameters->ParamByName("pcurrMagnetL")->Value = TGlSettings::currMagnetL;
				queryTSize->Parameters->ParamByName("pthresholdL1")->Value = TGlSettings::thresholdL1;
				queryTSize->Parameters->ParamByName("pthresholdL2")->Value = TGlSettings::thresholdL2;
				queryTSize->Parameters->ParamByName("pindTypeSize")->Value = TGlSettings::indTypeSize;
				queryTSize->ExecSQL();
			}
			else {

			}
		}

		err = 0;
	}
	catch (Exception *ex) {
		err = -2;
		TLog::ErrFullSaveLog(ex);
		TGlSettings::thresholdL1 = 55;
		TGlSettings::thresholdL2 = 0;
		// MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);

	}
	return err;
}

int TfmMain::GetBordersT(int _indTypeSize, int _numFusion, int _numTube) {
	int err = 0;
	int count = 0;
	UnicodeString strXml = "";
	UnicodeString strSql = "";
	UnicodeString strTmp = "";
	TReplaceFlags ReplaceFlags;
	try {
		// strSql="SELECT PCross FROM ResultPars where TypeSize=3 and Fusion=11 and Tube=7";
		// strSql="SELECT PCross FROM ResultPars where TypeSize=3 and Fusion=12 and Tube=1";
		// strSql = "SELECT PThick from ResultPars where ";
		// strSql += " Fusion=" + IntToStr(_numFusion);
		// strSql += " and Tube=" + IntToStr(_numTube);
		// Sleep(1000);
		// queryXML->Close();
		// queryXML->SQL->Text = strSql;
		// queryXML->Open();
		// count = queryXML->RecordCount;
		// strXml = queryXML->FieldByName("PThick")->AsString;
		// strSql = "SELECT [dbo].[GetBorderThickUpXML] (";
		// strSql += IntToStr(TGlSettings::currFusion);
		// strSql += ",";
		// strSql += IntToStr(TGlSettings::numTube);
		// strSql += ") as F1";
		strSql = "SELECT [dbo].[GetTzBorderTUp] (";
		strSql += IntToStr(TGlSettings::indTypeSize);
		strSql += ") as F1";
		strTmp = SqlDBModule->GetStrFromFunctionSql(strSql, err);
		strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		TGlSettings::thresholdTUp = StrToFloat(strTmp);
		// strSql = "SELECT [dbo].[GetBorderThickDownXML] (";
		// strSql += IntToStr(TGlSettings::currFusion);
		// strSql += ",";
		// strSql += IntToStr(TGlSettings::numTube);
		// strSql += ") as F1";
		strSql = "SELECT [dbo].[GetTzBorderTDown] (";
		strSql += IntToStr(TGlSettings::indTypeSize);
		strSql += ") as F1";
		strTmp = SqlDBModule->GetStrFromFunctionSql(strSql, err);
		strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		TGlSettings::thresholdTDown = StrToFloat(strTmp);
		// ------------------------------------------
		if (strTmp == "" || strTmp == -1) {
			// pnlMsg->Caption = "Нет настроек толщиномера!";
			// pnlMsg->Refresh();
			lbxInfo->AddItem("Нет настроек толщиномера!", NULL);
			// //TLog::SaveStrMsgLog("Нет настроек толщиномера!");
			// // // пробуем загрузить дефолтовые
			AnsiString strSql = " SELECT thresholdTUp";
			strSql += ",thresholdTDown";
			strSql += ",currMagnetT";
			strSql += ",speedRotor";
			strSql += " FROM TypeSizesParams";
			strSql += " WHERE indTypeSize =:pindTypeSize";
			queryTSize->Close();
			queryTSize->SQL->Text = strSql;
			queryTSize->Parameters->ParamByName("pindTypeSize")->Value = TGlSettings::indTypeSize;
			queryTSize->Open();
			// -------------------------------

			if (queryTSize->RecordCount == 0) { // нет записей
				strSql = "INSERT INTO TypeSizesParams (";
				strSql += "indTypeSize";
				strSql += ",thresholdTUp";
				strSql += ",thresholdTDown";
				strSql += ",currMagnetT";
				strSql += ",speedRotor)";
				strSql += " VALUES(";
				strSql += ":pindTypeSize";
				strSql += ",:pthresholdTUp";
				strSql += ",:pthresholdTDown";
				strSql += ",:pcurrMagnetT";
				strSql += ",:pspeedRotor)";
				queryTSize->Close();
				queryTSize->SQL->Text = strSql;
				TGlSettings::thresholdTDown = 12.5;
				TGlSettings::thresholdTUp = 20;
				queryTSize->Parameters->ParamByName("pindTypeSize")->Value = TGlSettings::indTypeSize;
				queryTSize->Parameters->ParamByName("pthresholdTUp")->Value = TGlSettings::thresholdTUp;
				queryTSize->Parameters->ParamByName("pthresholdTDown")->Value = TGlSettings::thresholdTDown;
				queryTSize->Parameters->ParamByName("pcurrMagnetT")->Value = 10;
				queryTSize->ExecSQL();
			}
			else {
				//
			}
			strTmp = queryTSize->FieldByName("thresholdTUp")->AsString;
			// поле пустое, обновим
			if (strTmp == "") {
				strSql = "UPDATE TypeSizesParams";
				strSql += " SET thresholdTUp = :pthresholdTUp";
				strSql += ",thresholdTDown = :pthresholdTDown";
				strSql += ",currMagnetT = :pcurrMagnetT";
				strSql += ",speedRotor =  :pspeedRotor";
				strSql += " WHERE indTypeSize =:pindTypeSize";
				queryTSize->Close();
				queryTSize->SQL->Text = strSql;
				queryTSize->Parameters->ParamByName("pthresholdTUp")->Value = TGlSettings::thresholdTUp;
				queryTSize->Parameters->ParamByName("pthresholdTDown")->Value = TGlSettings::thresholdTDown;
				queryTSize->Parameters->ParamByName("pindTypeSize")->Value = TGlSettings::indTypeSize;
				queryTSize->ExecSQL();
			}
			else {
				// заберем данные
				TGlSettings::thresholdTUp = queryTSize->FieldByName("thresholdTUp")->AsFloat;
				TGlSettings::thresholdTDown = queryTSize->FieldByName("thresholdTDown")->AsFloat;
				queryTSize->Close();
				err = 1;
				return err;
			}
		}
		else {
			// XMLDocument->LoadFromXML(strXml);
			// queryXML->Close();
			// strTmp = XMLDocument->DocumentElement->GetNodeName();
			// Sleep(100);
			// _di_IXMLNode nodeUp = XMLDocument->DocumentElement->GetChildNodes()->FindNode("rtTS");
			// count = nodeUp->GetChildNodes()->GetCount();
			// Sleep(100);
			// _di_IXMLNode nodeChild1 = nodeUp->GetChildNodes()->Get(2);
			// strTmp = nodeChild1->GetNodeValue();
			// TReplaceFlags ReplaceFlags;
			// strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
			// // tmpD = StrToFloat(strTmp);
			// TGlSettings::thresholdTUp = StrToFloat(strTmp);
			// Sleep(100);
			// _di_IXMLNode nodeChild2 = nodeUp->GetChildNodes()->Get(3);
			// strTmp = nodeChild2->GetNodeValue();
			// ReplaceFlags;
			// strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
			// // tmpD = StrToFloat(strTmp);
			// // TGlSettings::thresholdTDown = StrToFloat("12,5");
			// TGlSettings::thresholdTDown = StrToFloat(strTmp);

			strSql = "UPDATE TypeSizesParams";
			strSql += " SET thresholdTUp = :pthresholdTUp";
			strSql += ",thresholdTDown = :pthresholdTDown";
			strSql += ",currMagnetT = :pcurrMagnetT";
			strSql += ",speedRotor =  :pspeedRotor";
			strSql += " WHERE indTypeSize =:pindTypeSize";
			queryTSize->Close();
			queryTSize->SQL->Text = strSql;
			queryTSize->Parameters->ParamByName("pcurrMagnetT")->Value = TGlSettings::currMagnetT;
			queryTSize->Parameters->ParamByName("pthresholdTUp")->Value = TGlSettings::thresholdTUp;
			queryTSize->Parameters->ParamByName("pthresholdTDown")->Value = TGlSettings::thresholdTDown;
			queryTSize->Parameters->ParamByName("pindTypeSize")->Value = TGlSettings::indTypeSize;
			queryTSize->ExecSQL();
			// если не было вставим
			if (queryTSize->RowsAffected == 0) {
				strSql = "INSERT INTO TypeSizesParams (";
				strSql += "thresholdTUp";
				strSql += ",thresholdTDown";
				strSql += ",currMagnetT";
				strSql += ",speedRotor";
				strSql += ",indTypeSize)";
				strSql += " VALUES(";
				strSql += ":pthresholdTUp";
				strSql += ",:pthresholdTDown";
				strSql += ",:pcurrMagnetT";
				strSql += ",:pspeedRotor";
				strSql += ",:pindTypeSize)";
				queryTSize->Close();
				queryTSize->SQL->Text = strSql;
				queryTSize->Parameters->ParamByName("pcurrMagnetT")->Value = TGlSettings::currMagnetT;
				queryTSize->Parameters->ParamByName("pthresholdTUp")->Value = TGlSettings::thresholdTUp;
				queryTSize->Parameters->ParamByName("pthresholdTDown")->Value = TGlSettings::thresholdTDown;
				queryTSize->Parameters->ParamByName("pindTypeSize")->Value = TGlSettings::indTypeSize;
				queryTSize->ExecSQL();
			}
			else {

			}
		}
		err = 0;
	}
	catch (Exception *ex) {
		err = -2;
		TLog::ErrFullSaveLog(ex);
		TGlSettings::thresholdTUp = 20;
		TGlSettings::thresholdTDown = 12.5;
		// MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);

	}
	return err;
}

void __fastcall TfmMain::bbtForseReadyClick(TObject *Sender) {
	// GetNodesBorders(3, 34, 41);
   //	ViewCurrentBorders(TGlSettings::currFusion, TGlSettings::numTube - 1);
	// ------------------------
    	UnicodeString newString;
	if (InputQuery((UnicodeString)"Запрос пароля", (UnicodeString)"Введите пароль:", newString)) {
		if (newString != TGlSettings::passwordEdit) {
			MessageDlg("Неверный пароль!", mtError, TMsgDlgButtons() << mbOK, NULL);
			return;
		}
		else {
			SqlDBModule->UpdIntSql("flags", "isReady", 1, NULL);
			Sleep(1000);
			SqlDBModule->UpdIntSql("flags", "isReady", 0, NULL);
		}
	}
	else {
		//
	}
}

int TfmMain::ViewCurrentBorders(int _numFusion, int _numTube) {
	AnsiString tmpStr;
	lbxInfo->Clear();
	double tmpD = 0;
	int ind = TGlSettings::indTypeSize;
	int ff = TGlSettings::currFusion;
	int inttd = TGlSettings::numTube;
	// GetNodesBorders(TGlSettings::indTypeSize, TGlSettings::currFusion, TGlSettings::numTube);
	lbxInfo->Clear();
	tmpStr = "Плавка=";
	tmpStr += IntToStr(_numFusion);
	lbxInfo->AddItem(tmpStr, NULL);
	// ---------------
	tmpStr = "Труба=";
	tmpStr += IntToStr(_numTube);
	lbxInfo->AddItem(tmpStr, NULL);
	// ---------------
	tmpStr = "thresholdTNominal=";
	tmpStr += FloatToStr(TGlSettings::thresholdTNominal);
	tmpStr += " мм";
	lbxInfo->AddItem(tmpStr, NULL);
	// ---------------
	tmpStr = "thresholdTDown=";
	tmpStr += FloatToStr(TGlSettings::thresholdTDown);
	tmpStr += "% ";
	tmpD = RoundTo((TGlSettings::thresholdTNominal - TGlSettings::thresholdTNominal * TGlSettings::thresholdTDown / 100.0), -1);
	tmpStr += FloatToStr(tmpD);
	tmpStr += " мм";
	lbxInfo->AddItem(tmpStr, NULL);
	// ----------------
	tmpStr = "thresholdTUp=";
	tmpStr += FloatToStr(TGlSettings::thresholdTUp);
	tmpStr += "% ";
	tmpD = RoundTo((TGlSettings::thresholdTNominal + TGlSettings::thresholdTNominal * TGlSettings::thresholdTUp / 100.0), -1);
	tmpStr += FloatToStr(tmpD);
	tmpStr += " мм";
	lbxInfo->AddItem(tmpStr, NULL);
	// ------------------------------
	tmpStr = "currMagnetT=";
	tmpStr += FloatToStr(TGlSettings::currMagnetT);
	tmpStr += " А";
	lbxInfo->AddItem(tmpStr, NULL);
	// -------------------------
	tmpStr = "thresholdC1=";
	tmpStr += FloatToStr(TGlSettings::thresholdC1);
	tmpStr += " %";
	lbxInfo->AddItem(tmpStr, NULL);
	// -------------------------
	tmpStr = "thresholdC2=";
	tmpStr += FloatToStr(TGlSettings::thresholdC2);
	tmpStr += " %";
	lbxInfo->AddItem(tmpStr, NULL);
	// ------------------------
	tmpStr = "currMagnetC=";
	tmpStr += FloatToStr(TGlSettings::currMagnetC);
	tmpStr += " А";
	lbxInfo->AddItem(tmpStr, NULL);
	// ------------------------
	tmpStr = "thresholdL1=";
	tmpStr += FloatToStr(TGlSettings::thresholdL1);
	tmpStr += " %";
	lbxInfo->AddItem(tmpStr, NULL);
	// -------------------------
	tmpStr = "thresholdL2=";
	tmpStr += FloatToStr(TGlSettings::thresholdL2);
	tmpStr += " %";
	lbxInfo->AddItem(tmpStr, NULL);
	// ------------------------
	tmpStr = "currMagnetC=";
	tmpStr += FloatToStr(TGlSettings::currMagnetL);
	tmpStr += " А";
	lbxInfo->AddItem(tmpStr, NULL);
}

// ----------------------serg12
int TfmMain::GetDataCross(int _numFusion, int _numTube, double _thresholdC1, double _thresholdC2) {
	AnsiString strSql = "";
	AnsiString strTmp = "";
	int err = 0;
	int itmp = 0;
	std::vector<double>::iterator result;
	int indMax;
	AnsiString strTitleC = "ПОПЕРЕЧНЫЕ ДЕФЕКТЫ (MHK2(C))";
	AnsiString strNoDataC = "Данных по дефектам МНК2(C) нет!";
	TColor colorC = clGreen;
	int countNullsC = 0;
	AnsiString strWhere;
	bool isYellow = false;
	int countBrak = 0;
	try {
		strWhere = "numFusion=" + IntToStr(_numFusion);
		strWhere += " and ";
		strWhere += " numTube= " + IntToStr(_numTube);
		// пороги
		// strSql = "SELECT thresholdC1, thresholdC2";
		// strSql += " FROM resultTubeShort where numTube=:pnumTube and numFusion=:pnumFusion order by numFusion,numTube";
		// SqlDBModule->queryForChart->Close();
		// SqlDBModule->queryForChart->SQL->Text = strSql;
		// SqlDBModule->queryForChart->Parameters->ParamByName("pnumTube")->Value = _numTube;
		// SqlDBModule->queryForChart->Parameters->ParamByName("pnumFusion")->Value = _numFusion;
		// SqlDBModule->queryForChart->Open();
		// valBborder1 = SqlDBModule->queryForChart->FieldByName("thresholdC1")->AsFloat;
		// valBborder2 = SqlDBModule->queryForChart->FieldByName("thresholdC2")->AsFloat;
		// --------------
		chartCross->Title->Clear();
		chartCross->Title->Text->Add(strTitleC);
		chartCross->BottomAxis->Maximum = TGlSettings::countZones;
		strSql = "SELECT numFusion, numTube";
		for (int i = 0; i < TGlSettings::countZones; i++) {
			strSql += ",Z" + IntToStr(i + 1);
		}
		strSql += ",sensorNum";
		strSql += " FROM resultCross where numTube=:pnumTube and numFusion=:pnumFusion order by numFusion,numTube,sensorNum";
		// по зонам поперечник
		SqlDBModule->queryForChart->Close();
		SqlDBModule->queryForChart->SQL->Text = strSql;
		SqlDBModule->queryForChart->Parameters->ParamByName("pnumFusion")->Value = _numFusion;
		SqlDBModule->queryForChart->Parameters->ParamByName("pnumTube")->Value = _numTube;

		SqlDBModule->queryForChart->Open();
		if (SqlDBModule->queryForChart->RecordCount == 0) {
		  //	MessageDlg(strNoDataC, mtWarning, TMsgDlgButtons() << mbOK, NULL);
			chartCross->Title->Clear();
			chartCross->Title->Text->Add(strTitleC);
			chartCross->Title->Text->Add(strNoDataC);
			err = 0;
			return err;
		}
		else {
			//
		}
		chartCross->Series[1]->Title = "Порог 1= " + FloatToStr(RoundTo(_thresholdC1, -2)) + " %";
		chartCross->Series[2]->Title = "Порог 2= " + FloatToStr(RoundTo(_thresholdC2, -2)) + " %";
		// подготовим вектор
		vecMaxCh.clear();
		for (int i = 0; i < TGlSettings::countSensorsCross; i++) {
			vecMaxCh.push_back(0);
		}
		dataCross.clear();
		for (int i = 0; i < sensorsDataCross.size(); i++) {
			sensorsDataCross[i].clear();
		}
		sensorsDataCross.clear();
		// заберем данные по поперечнику
		SqlDBModule->queryForChart->First();
		// while (!SqlDBModule->queryForChart->Eof) {
		itmp = TGlSettings::countSensorsCross;
		for (int i = 0; i < TGlSettings::countSensorsCross; i++) {
			vector<double>vecTmp;
			for (int z = 0; z < TGlSettings::countZones; z++) {
				double val = 0;
				AnsiString fn = "Z" + IntToStr(z + 1);
				strTmp = SqlDBModule->queryForChart->FieldByName("Z" + IntToStr(z + 1))->AsString;
				if (strTmp == "") {
					countNullsC++;
					val = 0;
				}
				else {
					val = SqlDBModule->queryForChart->FieldByName("Z" + IntToStr(z + 1))->AsFloat;
					if (val > 100) {
						val = 100;
					}
					else {
						//
					}
				}
				vecTmp.push_back(val);
			}
			sensorsDataCross.push_back(vecTmp);
			SqlDBModule->queryForChart->Next();
		}
		SqlDBModule->queryForChart->Close();
		// максимальное значание и заполнение конечного вектора
		itmp = sensorsDataCross.size();
		itmp = sensorsDataCross[0].size();
		dataCross.push_back(0); // иммитация сдвига
		for (int i = 0; i < TGlSettings::countZones; i++) {
			for (int j = 0; j < TGlSettings::countSensorsCross; j++) {
				vecMaxCh[j] = sensorsDataCross[j][i];
			}
			result = std::max_element(vecMaxCh.begin(), vecMaxCh.end());
			indMax = std::distance(vecMaxCh.begin(), result);
			dataCross.push_back(vecMaxCh[indMax]);
		}
		chartCross->BottomAxis->Maximum = TGlSettings::countZones;
		chartCross->Series[0]->Clear();
		chartCross->Series[1]->Clear();
		chartCross->Series[2]->Clear();
		chartCross->Series[1]->Color = clRed;
		chartCross->Series[2]->Color = clYellow;
		for (int i = 0; i < TGlSettings::countZones; i++) {
			isYellow = false;
			if (dataCross[i] > 0) {
				if (dataCross[i] > _thresholdC1 && _thresholdC1 > 0) {
					// chartLong->Series[0]->Add(dataLong[i], "", clYellow);
					colorC = clRed;
					countBrak++;
					// SqlDBModule->UpdIntSql("resultTubeShort", "resultC", countBrak, strWhere);
				}
				else {
					if (dataCross[i] > _thresholdC2 && _thresholdC2 > 0) {
						// chartLong->Series[0]->Add(dataLong[i], "", clRed);
						countBrak++;
						colorC = clYellow;
						// SqlDBModule->UpdIntSql("resultTubeShort", "resultC", countBrak, strWhere);
					}
					else {
						colorC = clGreen;
					}
				}
				chartCross->Series[0]->Add(dataCross[i], "", colorC);
			}
			else {
				chartCross->Series[0]->Add(0, "", clBlack);
			}
			chartCross->Series[1]->Add(_thresholdC1, "", clRed);
			chartCross->Series[2]->Add(_thresholdC2, "", clYellow);
		}
		err = 0;
		if (countNullsC == TGlSettings::countZones * TGlSettings::countSensorsCross) {
			err = 21;
			chartCross->Title->Clear();
			chartCross->Title->Text->Add(strTitleC);
			chartCross->Title->Text->Add(strNoDataC);
			SqlDBModule->UpdIntSql("resultTubeShort", "resultC", -1, strWhere);
		}
		else {
			SqlDBModule->UpdIntSql("resultTubeShort", "resultC", countBrak, strWhere);
		}
	}
	catch (Exception *ex) {
		err = -1;
		TLog::ErrFullSaveLog(ex);
		// AnsiString msg
		// programSettings.colorMSG = programSettings.colorBrak;
		// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
	return err;
}

int TfmMain::GetDataLong(int _numFusion, int _numTube, double _thresholdL1, double _thresholdL2) {
	AnsiString strSql = "";
	int err = 0;
	int itmp = 0;
	int countNulls = 0;
	std::vector<double>::iterator result;
	int indMax;
	AnsiString strTitleL = "ПРОДОЛЬНЫЕ ДЕФЕКТЫ (MHK3(L))";
	AnsiString strNoDataL = "Данных по дефектам МНК3(L) нет!";
	TColor colorL = clGreen;
	AnsiString strWhere = "";
	AnsiString strTmp = "";
	int countBrak = 0;
	bool isYellow = false;
	try {
		strWhere = "numFusion=" + IntToStr(_numFusion);
		strWhere += " and ";
		strWhere += " numTube= " + IntToStr(_numTube);
		chartLong->Title->Clear();
		chartLong->Title->Text->Add(strTitleL);
		chartLong->BottomAxis->Maximum = TGlSettings::countZones;
		SqlDBModule->queryForChart->Close();
		strSql = "SELECT numFusion, numTube";
		for (int i = 0; i < TGlSettings::countZones; i++) {
			strSql += ",Z" + IntToStr(i + 1);
		}
		strSql += ",sensorNum";
		strSql += " FROM resultLong where numTube=:pnumTube and numFusion=:pnumFusion order by numFusion,numTube,sensorNum";
		SqlDBModule->queryForChart->SQL->Text = strSql;
		SqlDBModule->queryForChart->Parameters->ParamByName("pnumFusion")->Value = _numFusion;
		SqlDBModule->queryForChart->Parameters->ParamByName("pnumTube")->Value = _numTube;

		SqlDBModule->queryForChart->Open();
		if (SqlDBModule->queryForChart->RecordCount == 0) {
			//MessageDlg(strNoDataL, mtWarning, TMsgDlgButtons() << mbOK, NULL);
			chartLong->Title->Clear();
			chartLong->Title->Text->Add(strTitleL);
			chartLong->Title->Text->Add(strNoDataL);
			return 0;
		}
		else {
			//
		}
		chartLong->Series[1]->Title = "Порог 1= " + FloatToStr(RoundTo(_thresholdL1, -2)) + " %";
		chartLong->Series[2]->Title = "Порог 2= " + FloatToStr(RoundTo(_thresholdL2, -2)) + " %";
		SqlDBModule->queryForChart->First();
		// подготовим вектор
		vecMaxCh.clear();
		for (int i = 0; i < TGlSettings::countSensorsLong; i++) {
			vecMaxCh.push_back(0);
		}
		dataLong.clear();
		for (int i = 0; i < sensorsDataLong.size(); i++) {
			sensorsDataLong[i].clear();
		}
		sensorsDataLong.clear();
		// заберем данные по продольнику
		SqlDBModule->queryForChart->First();
		itmp = TGlSettings::countSensorsLong;
		for (int i = 0; i < TGlSettings::countSensorsLong; i++) {
			vector<double>vecTmp;
			for (int z = 0; z < TGlSettings::countZones; z++) {
				double val = 0;
				AnsiString fn = "Z" + IntToStr(z + 1);
				strTmp = SqlDBModule->queryForChart->FieldByName("Z" + IntToStr(z + 1))->AsString;
				if (strTmp == "") {
					countNulls++;
					val = 0;
				}
				else {
					val = SqlDBModule->queryForChart->FieldByName("Z" + IntToStr(z + 1))->AsFloat;
					if (val > 100) {
						val = 100;
					}
					else {
						//
					}
				}
				vecTmp.push_back(val);
			}
			sensorsDataLong.push_back(vecTmp);
			SqlDBModule->queryForChart->Next();
		}

		SqlDBModule->queryForChart->Close();
		// максимальное значание и заполнение конечного вектора
		itmp = sensorsDataLong.size();
		itmp = sensorsDataLong[0].size();
		dataLong.push_back(0);
		for (int i = 0; i < TGlSettings::countZones; i++) {
			for (int j = 0; j < TGlSettings::countSensorsLong; j++) {
				vecMaxCh[j] = sensorsDataLong[j][i];
			}
			result = std::max_element(vecMaxCh.begin(), vecMaxCh.end());
			indMax = std::distance(vecMaxCh.begin(), result);
			dataLong.push_back(vecMaxCh[indMax]);
		}
		chartLong->BottomAxis->Maximum = TGlSettings::countZones;
		chartLong->Series[0]->Clear();
		chartLong->Series[1]->Clear();
		chartLong->Series[2]->Clear();
		chartLong->Series[1]->Color = clRed;
		chartLong->Series[2]->Color = clYellow;
		for (int i = 0; i < TGlSettings::countZones; i++) {
			isYellow = false;
			if (dataLong[i] > 0) {
				if (dataLong[i] > _thresholdL1 && _thresholdL1 > 0) {
					// chartLong->Series[0]->Add(dataLong[i], "", clYellow);
					colorL = clRed;
					// isYellow = true;
					countBrak++;
					// SqlDBModule->UpdIntSql("resultTubeShort", "resultL", countBrak, strWhere);
				}
				else {
					if (dataLong[i] > _thresholdL2 && _thresholdL2 > 0) {
						// chartLong->Series[0]->Add(dataLong[i], "", clRed);
						countBrak++;
						colorL = clYellow;
						// SqlDBModule->UpdIntSql("resultTubeShort", "resultL", countBrak, strWhere);
					}
					else {
						colorL = clGreen;
					}
				}
				chartLong->Series[0]->Add(dataLong[i], "", colorL);
			}
			else {
				chartLong->Series[0]->Add(0, "", clBlack);
			}
			itmp = TGlSettings::thresholdL2;
			chartLong->Series[1]->Add(_thresholdL1, "", clRed);
			chartLong->Series[2]->Add(_thresholdL2, "", clYellow);
		}
		err = 0;
		int ff = TGlSettings::countZones * TGlSettings::countSensorsLong;
		if (countNulls == TGlSettings::countZones * TGlSettings::countSensorsLong) {
			err = 31;
			chartLong->Title->Clear();
			chartLong->Title->Text->Add(strTitleL);
			chartLong->Title->Text->Add(strNoDataL);
			SqlDBModule->UpdIntSql("resultTubeShort", "resultL", -1, strWhere);
		}
		else {
			SqlDBModule->UpdIntSql("resultTubeShort", "resultL", countBrak, strWhere);
		}
	}
	catch (Exception *ex) {
		err = -1;
		TLog::ErrFullSaveLog(ex);
		// AnsiString msg
		// programSettings.colorMSG = programSettings.colorBrak;
		// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
	return err;
}

// ------------------- new

int TfmMain::GetDataThick(int _numFusion, int _numTube, double _thresholdTNominal, double _thresholdTUp, double _thresholdTDown) {
	AnsiString strSql = "";
	int err = 0;
	int itmp = 0;
	int intTmp = 0;
	double tmpD = 0;
	std::vector<double>::iterator result;
	int indMax;
	// double valBborderProcUp = 0;
	// double valBborderProcD = 0;
	double valBorderMin = 0;
	double valBorderMax = 0;
	double valChart = 0;
	double val = 0;
	double valR = 0;
	double scale = 20.0;
	int countNullsMin = 0;
	int countNullsMax = 0;
	TColor colorT = clGreen;
	AnsiString strTmp;
	AnsiString strTitleT = "ДЕФЕКТЫ ТОЛЩИНЫ (MHK1(T))";
	AnsiString strNoDataT = "Данных по дефектам МНК1(T) нет!";
	AnsiString strWhere;
	int countBrakT = 0;
	try {
		strWhere = "numFusion=" + IntToStr(_numFusion);
		strWhere += " and ";
		strWhere += " numTube= " + IntToStr(_numTube);
		// scale = 20.0;
		chartThick->Title->Clear();
		chartThick->Series[0]->Clear();
		chartThick->Series[0]->Legend->Visible = false;
		chartThick->Series[1]->Clear();
		chartThick->Series[1]->Legend->Visible = false;
		chartThick->Series[2]->Clear();
		chartThick->Series[2]->Legend->Visible = true;
		chartThick->Series[3]->Clear();
		chartThick->Series[3]->Legend->Visible = true;
		chartThick->Title->Text->Add(strTitleT);
		chartThick->LeftAxis->Title->Caption = FloatToStr(_thresholdTNominal) + " мм";
		chartThick->LeftAxis->Title->Angle = 0;
		chartThick->BottomAxis->Maximum = TGlSettings::countZones;
		tmpD = TGlSettings::thresholdTNominal;
		// tmpD = valBborderProcD * TGlSettings::thresholdTNominal / 100.0;
		// tmpD = valBborderProcUp * TGlSettings::thresholdTNominal / 100.0;
		valBorderMax = _thresholdTNominal + _thresholdTUp * _thresholdTNominal / 100.0;
		chartThick->Series[3]->Title = "Макс порог: " + FloatToStr(RoundTo(valBorderMax, -1)) + " мм";
		// -----------------
		valBorderMin = _thresholdTNominal - _thresholdTDown * _thresholdTNominal / 100.0;
		chartThick->Series[2]->Title = "Мин порог: " + FloatToStr(RoundTo(valBorderMin, -1)) + " мм";

		SqlDBModule->queryForChart->Close();
		strSql = "SELECT numFusion, numTube";
		for (int i = 0; i < TGlSettings::countZones; i++) {
			strSql += ",Min" + IntToStr(i + 1);
		}
		for (int i = 0; i < TGlSettings::countZones; i++) {
			strSql += ",Max" + IntToStr(i + 1);
		}
		strSql += ",sensorNum";
		strSql += " FROM resultThick where numTube=:pnumTube and numFusion=:pnumFusion order by numFusion,numTube,sensorNum";
		SqlDBModule->queryForChart->SQL->Text = strSql;
		SqlDBModule->queryForChart->Parameters->ParamByName("pnumTube")->Value = _numTube;
		SqlDBModule->queryForChart->Parameters->ParamByName("pnumFusion")->Value = _numFusion;
		SqlDBModule->queryForChart->Open();
		// ---------------- min
		SqlDBModule->queryForChart->First();
		if (SqlDBModule->queryForChart->RecordCount == 0) {
			//MessageDlg(strNoDataT, mtWarning, TMsgDlgButtons() << mbOK, NULL);
			chartThick->Title->Clear();
			chartThick->Title->Text->Add(strTitleT);
			chartThick->Title->Text->Add(strNoDataT);
			err = 0;
			return err;
		}
		else {
			//
		}
		// подготовим вектор
		vecMaxCh.clear();
		for (int i = 0; i < TGlSettings::countRecordsThick; i++) {
			vecMaxCh.push_back(0);
		}
		vecMaxChR.clear();
		for (int i = 0; i < TGlSettings::countRecordsThick; i++) {
			vecMaxChR.push_back(0);
		}
		for (int i = 0; i < sensorsDataThickMin.size(); i++) {
			sensorsDataThickMin[i].clear();
		}
		sensorsDataThickMin.clear();
		for (int i = 0; i < sensorsDataThickMinR.size(); i++) {
			sensorsDataThickMinR[i].clear();
		}
		sensorsDataThickMinR.clear();
		for (int i = 0; i < dataThickMin.size(); i++) {
			dataThickMin[i].clear();
		}
		dataThickMin.clear();
		// --------------------
		// // заберем данные по толщиномеру min
		// while (!SqlDBModule->queryForChart->Eof) {
		itmp = TGlSettings::countRecordsThick;
		for (int i = 0; i < TGlSettings::countRecordsThick; i++) {
			vector<double>vecTmp;
			vector<double>vecTmpR;
			for (int z = 0; z < TGlSettings::countZones; z++) {
				AnsiString fn = "Min" + IntToStr(z + 1);
				strTmp = SqlDBModule->queryForChart->FieldByName("Min" + IntToStr(z + 1))->AsString;
				if (strTmp == "") {
					countNullsMin++;
					valR = -1;
					val = _thresholdTNominal;
				}
				else {
					val = SqlDBModule->queryForChart->FieldByName("Min" + IntToStr(z + 1))->AsFloat;
					if (val < 0) {
						valR = -1;
						val = _thresholdTNominal;
					}
					else {
						valR = 1;
					}
				}
				//
				// TGlSettings::thresholdTNominal
				vecTmp.push_back(val);
				vecTmpR.push_back(valR);
			}
			sensorsDataThickMin.push_back(vecTmp);
			sensorsDataThickMinR.push_back(vecTmpR);
			SqlDBModule->queryForChart->Next();
		}

		// минимальное значание и заполнение конечного вектора
		// ----------------------
		for (int i = 0; i < dataThickMin.size(); i++) {
			dataThickMin[i].clear();
		}
		dataThickMin.clear();
		for (int i = 0; i < 2; i++) {
			vector<double>vekMin;
			dataThickMin.push_back(vekMin);
		}
		// убежим с 0
		dataThickMin[0].push_back(0);
		dataThickMin[1].push_back(0);
		itmp = sensorsDataThickMin.size();
		itmp = sensorsDataThickMinR.size();
		itmp = sensorsDataThickMin[0].size();
		itmp = sensorsDataThickMinR[0].size();
		itmp = dataThickMin.size();
		itmp = dataThickMin[0].size();
		itmp = vecMaxCh.size();
		itmp = vecMaxChR.size();
		for (int i = 0; i < TGlSettings::countZones; i++) {
			for (int j = 0; j < TGlSettings::countRecordsThick; j++) {
				vecMaxCh[j] = sensorsDataThickMin[j][i];
				vecMaxChR[j] = sensorsDataThickMinR[j][i];
			}
			result = std::min_element(vecMaxCh.begin(), vecMaxCh.end());
			indMax = std::distance(vecMaxCh.begin(), result);
			tmpD = vecMaxCh[indMax];
			dataThickMin[0].push_back(RoundTo(vecMaxCh[indMax], -1));
			// -------------
			int countDead = 0;
			for (int rj = 0; rj < TGlSettings::countRecordsThick; rj++) {
				valR = vecMaxChR[rj];
				if (vecMaxChR[rj] < 0) {
					countDead++;
				}
				else {
					//
				}
			}
			if (countDead == TGlSettings::countRecordsThick) {
				dataThickMin[1].push_back(-1);
			}
			else {
				dataThickMin[1].push_back(1);
			}
		}
		//
		chartThick->BottomAxis->Maximum = TGlSettings::countZones;
		chartThick->Series[0]->Clear();
		chartThick->Series[2]->Clear();
		chartThick->Series[2]->Color = clBlue;
		// chartThick->Series[2]->Title
		// chartThick->Series[2]->Legend->Text = FloatToStr(valBorderMin) + " 1мм";
		// chartThick->Series[2]->Legend->Visible = true;
		// chartThick->Series[2]->Title->
		for (int i = 0; i < TGlSettings::countZones; i++) {
			if (dataThickMin[0][i] > 0) {
				if (RoundTo(dataThickMin[0][i], -1) < RoundTo(valBorderMin, -1)) {
					valChart = (dataThickMin[0][i] - _thresholdTNominal) * scale;
					chartThick->Series[0]->Add(valChart, "", clBlue);
					countBrakT++;
					// SqlDBModule->UpdIntSql("resultTubeShort", "resultT", countBrak, strWhere);
				}
				else {
					valChart = dataThickMin[0][i];
					valChart = (dataThickMin[0][i] - _thresholdTNominal);
					valChart = (dataThickMin[0][i] - _thresholdTNominal) * scale;
					chartThick->Series[0]->Add(valChart, "", clGreen);
				}
			}
			else {
				chartThick->Series[0]->Add(0, "", clBlack);
			}
			// порог
			chartThick->Series[2]->Add((valBorderMin - _thresholdTNominal)*scale, "", clBlue);
		}
		chartThick->Legend->Visible = true;
		// ---------------- max
		// подготовим вектор
		for (int i = 0; i < dataThickMax.size(); i++) {
			dataThickMax[i].clear();
		}
		dataThickMax.clear();
		// ---
		for (int i = 0; i < sensorsDataThickMax.size(); i++) {
			sensorsDataThickMax[i].clear();
		}
		sensorsDataThickMax.clear();
		for (int i = 0; i < sensorsDataThickMaxR.size(); i++) {
			sensorsDataThickMaxR[i].clear();
		}
		sensorsDataThickMaxR.clear();
		vecMaxCh.clear();
		for (int i = 0; i < TGlSettings::countRecordsThick; i++) {
			vecMaxCh.push_back(0);
		}
		vecMaxChR.clear();
		for (int i = 0; i < TGlSettings::countRecordsThick; i++) {
			vecMaxChR.push_back(0);
		}
		// заберем данные по толщиномеру
		SqlDBModule->queryForChart->First();
		// while (!SqlDBModule->queryForChart->Eof) {
		itmp = TGlSettings::countRecordsThick;
		for (int i = 0; i < TGlSettings::countRecordsThick; i++) {
			vector<double>vecTmp;
			vector<double>vecTmpR;
			for (int z = 0; z < TGlSettings::countZones; z++) {
				AnsiString fn = "Max" + IntToStr(z + 1);
				strTmp = SqlDBModule->queryForChart->FieldByName("Max" + IntToStr(z + 1))->AsString;
				if (strTmp == "") {
					valR = -1;
					countNullsMax++;
					val = _thresholdTNominal;
				}
				else {
					val = SqlDBModule->queryForChart->FieldByName("Max" + IntToStr(z + 1))->AsFloat;
					if (val < 0) {
						val = TGlSettings::thresholdTNominal;
						valR = -1;
					}
					else {
						valR = 1;
					}

				}
				vecTmp.push_back(val);
				vecTmpR.push_back(valR);
			}
			sensorsDataThickMax.push_back(vecTmp);
			sensorsDataThickMaxR.push_back(vecTmpR);
			SqlDBModule->queryForChart->Next();
		}
		SqlDBModule->queryForChart->Close();
		// максимальное значение и заполнение конечного вектора
		for (int i = 0; i < 2; i++) {
			vector<double>vekMax;
			dataThickMax.push_back(vekMax);
		}
		dataThickMax[0].push_back(0);
		dataThickMax[1].push_back(0);
		itmp = sensorsDataThickMax.size();
		itmp = sensorsDataThickMaxR.size();
		itmp = sensorsDataThickMax[0].size();
		itmp = sensorsDataThickMaxR[0].size();
		itmp = dataThickMax.size();
		itmp = dataThickMax[0].size();
		itmp = vecMaxCh.size();
		itmp = vecMaxChR.size();
		for (int i = 0; i < TGlSettings::countZones; i++) {
			for (int j = 0; j < TGlSettings::countRecordsThick; j++) {
				vecMaxCh[j] = sensorsDataThickMax[j][i];
				vecMaxChR[j] = sensorsDataThickMaxR[j][i];
			}
			result = std::max_element(vecMaxCh.begin(), vecMaxCh.end());
			indMax = std::distance(vecMaxCh.begin(), result);
			dataThickMax[0].push_back(RoundTo(vecMaxCh[indMax], -1));
			// --------------
			int countDead = 0;
			for (int rj = 0; rj < TGlSettings::countRecordsThick; rj++) {
				valR = vecMaxChR[rj];
				if (vecMaxChR[rj] < 0) {
					countDead++;
				}
				else {
					//
				}
			}
			if (countDead == TGlSettings::countRecordsThick) {
				dataThickMax[1].push_back(-1);
			}
			else {
				dataThickMax[1].push_back(1);
			}
		}
		// itmp = dataThickMax.size();
		// itmp = dataThickMax[0].size();
		// itmp = dataThickMax[1].size();
		// itmp = dataThickMin.size();
		// itmp = dataThickMin[0].size();
		// itmp = dataThickMin[1].size();
		// chartThick->BottomAxis->Maximum = TGlSettings::countZones;
		chartThick->Series[1]->Clear();
		chartThick->Series[3]->Clear();
		chartThick->Series[3]->Color = clRed;
		for (int i = 0; i < TGlSettings::countZones; i++) {
			valChart = dataThickMax[0][i];
			if (dataThickMax[0][i] > 0) {
				if (RoundTo(dataThickMax[0][i], -1) > (RoundTo(valBorderMax, -1) + 0.01)) {
					valChart = (dataThickMax[0][i] - _thresholdTNominal) * scale;
					chartThick->Series[1]->Add(valChart, "", clRed);
					countBrakT++;
					// SqlDBModule->UpdIntSql("resultTubeShort", "resultT", countBrak, strWhere);
				}
				else {
					valChart = (dataThickMax[0][i] - _thresholdTNominal) * scale;
					chartThick->Series[1]->Add(valChart, "", clGreen);
				}
			}
			else {
				chartThick->Series[1]->Add(0, "", clBlack);
			}
			valChart = valBorderMax - _thresholdTNominal;
			valChart = (valBorderMax - _thresholdTNominal) * scale;
			chartThick->Series[3]->Add(valChart, "", clRed);
		}
		err = 0;
		if (countNullsMin == TGlSettings::countZones * TGlSettings::countRecordsThick) {
			err = 11;
			SqlDBModule->UpdIntSql("resultTubeShort", "resultT", -1, strWhere);
		}
		else {
			SqlDBModule->UpdIntSql("resultTubeShort", "resultT", countBrakT, strWhere);
		}
		if (countNullsMax == TGlSettings::countZones * TGlSettings::countRecordsThick) {
			err = 12;
			SqlDBModule->UpdIntSql("resultTubeShort", "resultT", -1, strWhere);
		}
		else {
			SqlDBModule->UpdIntSql("resultTubeShort", "resultT", countBrakT, strWhere);
		}
		if (countNullsMin == TGlSettings::countZones * TGlSettings::countRecordsThick && countNullsMax == TGlSettings::countZones *
			TGlSettings::countRecordsThick) {
			err = 13;
			chartThick->Title->Clear();
			chartThick->Title->Text->Add(strTitleT);
			chartThick->Title->Text->Add(strNoDataT);
		}
		else {
			// err = 3;
			// SqlDBModule->UpdIntSql("resultTubeShort", "resultT", countBrakT, strWhere);
		}
		return err;
	}

	catch (Exception *ex) {
		err = -1;
		TLog::ErrFullSaveLog(ex);
		// AnsiString msg
		// programSettings.colorMSG = programSettings.colorBrak;
		// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
	return err;
}

int TfmMain::RecalcData(int _numFusion, int _numTube, double _thresholdTNominal, double _thresholdTUp, double _thresholdTDown,
	double _thresholdC1, double _thresholdC2, double _thresholdL1, double _thresholdL2) {
	AnsiString strSql = "";
	AnsiString tmpStr = "";
	int err = 0;
	int itmp = 0;
	std::vector<double>::iterator result;
	int indMax;
	int summErr = 0;
	isZoneMarkedT = false;
	isZoneMarkedC = false;
	isZoneMarkedL = false;
	try {
		// isLoadFm = true;
		// serg
		for (int i = 0; i < sensorsDataLong.size(); i++) {
			sensorsDataLong[i].clear();
		}
		sensorsDataLong.clear();
		// --
		for (int i = 0; i < sensorsDataCross.size(); i++) {
			sensorsDataCross[i].clear();
		}
		sensorsDataCross.clear();
		// ---
		for (int i = 0; i < sensorsDataThickMin.size(); i++) {
			sensorsDataThickMin[i].clear();
		}
		sensorsDataThickMin.clear();
		// ---
		for (int i = 0; i < sensorsDataThickMax.size(); i++) {
			sensorsDataThickMax[i].clear();
		}
		sensorsDataThickMax.clear();
		// ------------------

		tmpStr = "GetDataThick";
		lbxInfo->AddItem(tmpStr, NULL);
		errT = GetDataThick(_numFusion, _numTube, _thresholdTNominal, _thresholdTUp, _thresholdTDown);
		tmpStr = "GetDataThick Err=" + IntToStr(summErr);
		lbxInfo->AddItem(tmpStr, NULL);
		Application->ProcessMessages();
		//!!!300
		Sleep(150);
		tmpStr = "GetDataCross";
		lbxInfo->AddItem(tmpStr, NULL);
		errC = GetDataCross(_numFusion, _numTube, _thresholdC1, _thresholdC2);
		tmpStr = "GetDataCross Err=" + IntToStr(summErr);
		lbxInfo->AddItem(tmpStr, NULL);
		Application->ProcessMessages();
		//!!!300
		Sleep(150);
		// по зонам Продольник
		tmpStr = "GetDataLong";
		lbxInfo->AddItem(tmpStr, NULL);
		errL = GetDataLong(_numFusion, _numTube, _thresholdL1, _thresholdL2);
		Application->ProcessMessages();
		tmpStr = "GetDataLong Err=" + IntToStr(summErr);
		lbxInfo->AddItem(tmpStr, NULL);
		Application->ProcessMessages();
		//!!!300
		Sleep(150);
		// -------------------- Толщиномер
		for (int i = 0; i < sensorsDataLong.size(); i++) {
			sensorsDataLong[i].clear();
		}
		sensorsDataLong.clear();
		// --
		for (int i = 0; i < sensorsDataCross.size(); i++) {
			sensorsDataCross[i].clear();
		}
		sensorsDataCross.clear();
		// ---
		for (int i = 0; i < sensorsDataThickMin.size(); i++) {
			sensorsDataThickMin[i].clear();
		}
		sensorsDataThickMin.clear();
		// ---
		for (int i = 0; i < sensorsDataThickMax.size(); i++) {
			sensorsDataThickMax[i].clear();
		}
		sensorsDataThickMax.clear();

		err = errT + errC + errL;
	}
	catch (Exception *ex) {
		err = -1;
		TLog::ErrFullSaveLog(ex);
		// AnsiString msg
		// programSettings.colorMSG = programSettings.colorBrak;
		// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
	return err;
}

// ----------------------
void __fastcall TfmMain::chartCrossClickSeries(TCustomChart *Sender, TChartSeries *Series, int ValueIndex, TMouseButton Button,
	TShiftState Shift, int X, int Y) {
	int zoneNum = ValueIndex;
	int sensorNum = Series->SeriesIndex;
	TChart* pChart = static_cast<TChart*>(Sender);
	TChartSeries *pSeries0 = pChart->Series[0];
	if (Button == mbLeft) {
		selectZoneC = ValueIndex;
	}
	else {

	}
	if (ValueIndex == 0) {
		return;
	}
	else {
		//
	}
	// valZone = dataCross[ValueIndex];
	AnsiString tmpStr = "";
	pChart->Title->Clear();
	// pChart->Title->Text->Add("ПОПЕРЕЧНЫЕ ДЕФЕКТЫ (МНК 2)");
	tmpStr = "ПОПЕРЕЧНЫЙ КОНТРОЛЬ(МНК2)";
	tmpStr += " Порог 1=";
	tmpStr += FloatToStr(TGlSettings::thresholdC1);
	tmpStr += "%";
	tmpStr += " Порог 2=";
	tmpStr += FloatToStr(TGlSettings::thresholdC2);
	tmpStr += "%";
	pChart->Title->Text->Add(tmpStr);
	tmpStr = " Зона: " + IntToStr(ValueIndex) + " (";
	tmpStr += IntToStr((ValueIndex - 1) * 100);
	tmpStr += " - ";
	tmpStr += IntToStr(ValueIndex * 100) + " мм)";
	tmpStr += " Макс сигнал:";
	if (dataCross[ValueIndex] < 0) {
		tmpStr += " XXX";
	}
	else {
		tmpStr += FloatToStrF(dataCross[ValueIndex], ffFixed, 4, 1) + "%";
	}
	colorMark = clFuchsia;
	if (selectZoneC > 0 && selectZoneC < countZones) {
		// ChartCross->Series[selectSensor]->ValueColor[selectZone] = colorMark
		if (isZoneMarkedC) {
			pSeries0->ValueColor[oldSelectZoneC] = oldColorC0;
			// ----------
		}
		else {
			// oldColorC0 = pSeries0->ValueColor[selectZoneC];
			if (oldColorC0 == 0) {
				oldColorC0 = clGreen;
			}
			else {

			}
			pSeries0->ValueColor[selectZoneC] = oldColorC0;
			isZoneMarkedC = true;
		}
		// oldColor0 = pSeries0->ValueColor[selectZone];
		oldColorC0 = pSeries0->ValueColor[selectZoneC];
		oldSelectZoneC = selectZoneC;
		pSeries0->ValueColor[selectZoneC] = colorMark;
		// ------------
	}
	pChart->Title->Text->Add(tmpStr);

}
// ---------------------------------------------------------------------------

void __fastcall TfmMain::chartLongClickSeries(TCustomChart *Sender, TChartSeries *Series, int ValueIndex, TMouseButton Button,
	TShiftState Shift, int X, int Y) {
	int zoneNum = ValueIndex;
	int sensorNum = Series->SeriesIndex;
	TChart* pChart = static_cast<TChart*>(Sender);
	TChartSeries *pSeries0 = pChart->Series[0];
	AnsiString tmpStr = "";
	if (Button == mbLeft) {
		selectZoneL = ValueIndex;
	}
	else {

	}
	if (ValueIndex == 0) {
		return;
	}
	else {
		//
	}
	// valZone = dataLong[ValueIndex];
	pChart->Title->Clear();
	// pChart->Title->Text->Add("ПРОДОЛЬНЫЕ ДЕФЕКТЫ (МНК3(L))");
	tmpStr = "ПРОДОЛЬНЫЙ КОНТРОЛЬ(МНК3)";
	tmpStr += " Порог 1=";
	tmpStr += FloatToStr(TGlSettings::thresholdL1);
	tmpStr += "%";
	tmpStr += " Порог 2=";
	tmpStr += FloatToStr(TGlSettings::thresholdL2);
	tmpStr += "%";
	pChart->Title->Text->Add(tmpStr);
	tmpStr = " Зона: " + IntToStr(ValueIndex) + " (";
	tmpStr += IntToStr((ValueIndex - 1) * 100);
	tmpStr += " - ";
	tmpStr += IntToStr((ValueIndex) * 100) + " мм)";
	tmpStr += " Макс сигнал=";
	if (dataLong[ValueIndex] < 0) {
		tmpStr += "XXX";
	}
	else {
		tmpStr += FloatToStrF(dataLong[ValueIndex], ffFixed, 4, 1) + "%";
	}
	colorMark = clFuchsia;
	if (selectZoneL > 0 || selectZoneL < countZones) {
		// ChartCross->Series[selectSensor]->ValueColor[selectZone] = colorMark
		if (isZoneMarkedL) {
			pSeries0->ValueColor[oldSelectZoneL] = oldColorL0;
			// ----------
		}
		else {
			// oldColorL0 = pSeries0->ValueColor[selectZoneL];
			if (oldColorL0 == 0) {
				oldColorL0 = clGreen;

			}
			else {

			}
			pSeries0->ValueColor[selectZoneL] = oldColorL0;
			isZoneMarkedL = true;
		}
		// oldColor0 = pSeries0->ValueColor[selectZone];
		oldColorL0 = pSeries0->ValueColor[selectZoneL];
		oldSelectZoneL = selectZoneL;
		pSeries0->ValueColor[selectZoneL] = colorMark;
		// ------------
	}
	pChart->Title->Text->Add(tmpStr);
}
// ---------------------------------------------------------------------------

void __fastcall TfmMain::chartThickClickSeries(TCustomChart *Sender, TChartSeries *Series, int ValueIndex, TMouseButton Button,
	TShiftState Shift, int X, int Y) {
	// int zoneNum = ValueIndex;
	// int sensorNum = Series->SeriesIndex;
	int intTmp = 0;
	double valZoneMax = 0;
	double valZoneMin = 0;
	TChart* pChart = static_cast<TChart*>(Sender);
	TChartSeries *pSeries0 = pChart->Series[0];
	TChartSeries *pSeries1 = pChart->Series[1];
	AnsiString tmpStr = "";
	if (Button == mbLeft) {
		selectZoneT = ValueIndex;
	}
	else {

	}
	if (ValueIndex == 0) {
		return;
	}
	else {
		//
	}
	valZoneMax = dataThickMax[1][ValueIndex];
	valZoneMin = dataThickMin[1][ValueIndex];
	pChart->Title->Clear();
	TGlSettings::tmpThresholdTUp =
		RoundTo((TGlSettings::thresholdTNominal + TGlSettings::thresholdTUp * TGlSettings::thresholdTNominal / 100.0), -1);
	TGlSettings::tmpThresholdTDown =
		RoundTo((TGlSettings::thresholdTNominal - TGlSettings::thresholdTDown * TGlSettings::thresholdTNominal / 100.0), -1);
	// pChart->Title->Text->Add("ДЕФЕКТЫ ТОЛЩИНЫ (МНК1(T))");
	tmpStr = "КОНТРОЛЬ ТОЛЩИНЫ(МНК1)";
	// tmpStr += " Порог макс=";
	// tmpStr += FloatToStrF(TGlSettings::tmpThresholdTUp, ffFixed, 4, 2);
	// tmpStr += "мм, ";
	// tmpStr += " Порог мин=";
	// // //pChart->Title->Text->Add(tmpStr);
	// tmpStr += "мм";
	// tmpStr += FloatToStrF(TGlSettings::tmpThresholdTDown, ffFixed, 4, 2);
	pChart->Title->Text->Add(tmpStr);
	tmpStr = " Зона: " + IntToStr(ValueIndex) + " (";
	tmpStr += IntToStr((ValueIndex - 1) * 100);
	tmpStr += " - ";
	tmpStr += IntToStr(ValueIndex * 100) + " мм)";
	if (valZoneMax < 0) {
		tmpStr += " Максимум:";
		tmpStr += "XXX";
		tmpStr += " мм";
		tmpStr += " Минимум: XXX мм";
	}
	else {
		tmpStr += " Максимум:" + FloatToStrF(dataThickMax[0][ValueIndex], ffFixed, 4, 2) + " мм";
		tmpStr += " Минимум:" + FloatToStrF(dataThickMin[0][ValueIndex], ffFixed, 4, 2) + " мм";
	}
	colorMark = clFuchsia;
	if (selectZoneT > 0 && selectZoneT < countZones) {
		// ChartCross->Series[selectSensor]->ValueColor[selectZone] = colorMark
		if (isZoneMarkedT) {
			pSeries0->ValueColor[oldSelectZoneT] = oldColorT0;
			pSeries1->ValueColor[oldSelectZoneT] = oldColorT1;
			// ----------
		}
		else {
			oldColorT0 = pSeries0->ValueColor[selectZoneT];
			oldColorT1 = pSeries1->ValueColor[selectZoneT];
			// pSeries0->ValueColor[oldSelectZoneT] = oldColorT0;
			// pSeries1->ValueColor[oldSelectZoneT] = oldColorT1;
			isZoneMarkedT = true;
		}
		oldColorT0 = pSeries0->ValueColor[selectZoneT];
		oldColorT1 = pSeries1->ValueColor[selectZoneT];
		oldSelectZoneT = selectZoneT;
		pSeries0->ValueColor[selectZoneT] = colorMark;
		pSeries1->ValueColor[selectZoneT] = colorMark;
		// ------------
	}
	pChart->Title->Text->Add(tmpStr);
}

// ---------------------------------------------------------------------------
void __fastcall TfmMain::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift) {
	// TfmMain::chartCrossClickSeries(TCustomChart *Sender, TChartSeries *Series, int ValueIndex, TMouseButton Button,TShiftState Shift, int X, int Y)
	TShiftState shift;
	TMouseButton button;
	if (Key == VK_ESCAPE) {
		fmShowZones->Close();
	}
	else {
		//
	}
	if (Key == VK_LEFT && selectZoneT > 1 && isZoneMarkedT) {
		selectZoneT--;
		chartThickClickSeries(chartThick, chartThick->Series[0], selectZoneT, button, shift, 0, 0);
	}
	else {
		//
	}
	// -----
	if (Key == VK_RIGHT && selectZoneT < countZones && isZoneMarkedT) {
		selectZoneT++;
		chartThickClickSeries(chartThick, chartThick->Series[0], selectZoneT, button, shift, 0, 0);
	}
	else {
		//
	}
	// --------------------------------------------

	if (Key == VK_LEFT && selectZoneC > 1 && isZoneMarkedC) {
		selectZoneC--;
		chartCrossClickSeries(chartCross, chartCross->Series[0], selectZoneC, button, shift, 0, 0);
	}
	else {
		//
	}
	// -----
	if (Key == VK_RIGHT && selectZoneC < countZones && isZoneMarkedC) {
		selectZoneC++;
		chartCrossClickSeries(chartCross, chartCross->Series[0], selectZoneC, button, shift, 0, 0);
	}
	else {
		//
	}
	// ------------------

	if (Key == VK_LEFT && selectZoneL > 1 && selectZoneC < countZones && isZoneMarkedL) {
		selectZoneL--;
		chartLongClickSeries(chartLong, chartLong->Series[0], selectZoneL, button, shift, 0, 0);
	}
	else {
		//
	}
	// -----
	if (Key == VK_RIGHT && selectZoneL < countZones && isZoneMarkedL) {
		selectZoneL++;
		chartLongClickSeries(chartLong, chartLong->Series[0], selectZoneL, button, shift, 0, 0);
	}
	else {
		//
	}
	// ------------------

}

// ---------------------------------------------------------------------------
void __fastcall TfmMain::menuRepeatControlClick(TObject *Sender) {
	menuRepeatControl->Checked = !menuRepeatControl->Checked;
	// TGlSettings::repeatControl = menuRepeatControl->Checked;
	AnsiString strSqlWhere = "";
	UnicodeString NewString = "";
	AnsiString strSql = "";
	AnsiString strTmp = "";
	int intTmp = 0;
	int newNum = 0;
	// if (TGlSettings::repeatControl) {
	if (menuRepeatControl->Checked) {
		bbtMode->Caption = "ПОВТОРНЫЙ КОНТРОЛЬ! (типоразмер:" + IntToStr(TGlSettings::indTypeSize) + ")";
		bbtMode->Font->Color = clRed;
		InputQuery("Запрос номера трубы", "Введите номер:", NewString);
		if (TryStrToInt(Trim(NewString), newNum)) {
			//
		}
		else {
			MessageDlg("Неверный номер трубы!", mtError, TMsgDlgButtons() << mbOK, NULL);
			return;
		}
		strSql = "select count(*) as F1 from resultTubeShort where isEmpty=0 and numFusion=";
		strSql += IntToStr(TGlSettings::currFusion);
		strSql += " and numTube=";
		strSql += IntToStr(newNum);
		intTmp = SqlDBModule->GetIntFromSql(strSql);
		if (intTmp == 0) {
			MessageDlg("Трубы с таким номером в плавке нет!", mtError, TMsgDlgButtons() << mbOK, NULL);
			return;
		}
		else {
			//
		}
		TGlSettings::repeatControlNumTube = newNum;
		// TGlSettings::numTube = newNum;
		strSqlWhere = " numFusion=" + IntToStr(TGlSettings::currFusion) + " and numTube=" + IntToStr(TGlSettings::numTube);
		SqlDBModule->UpdIntSql("resultTubeShort", "isEmpty", 1, strSqlWhere);
		// SqlDBModule->UpdFloatSql("currentSettings", "ParamValueFloat", TGlSettings::numTube, "UPPER(ParamName)=UPPER('numCurrTube')");
		// menuRepeatControl->
	}
	else {
		bbtMode->Caption = "РЕЖИМ КОНТРОЛЯ (типоразмер:" + IntToStr(TGlSettings::indTypeSize) + ")";
		bbtMode->Font->Color = clBlack;

		strSqlWhere = " numFusion=" + IntToStr(TGlSettings::currFusion) + " and numTube=" + IntToStr(TGlSettings::numTube);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfmMain::FormResize(TObject *Sender) {
	PanelThick->Height = (int)(pnlCharts->Height / 3);
	PanelLong->Height = (int)(pnlCharts->Height / 3);
}

// ---------------------------------------------------------------------------
int TfmMain::InitCharts() {
	int err = 0;
	try {
		chartCross->Series[0]->Clear();
		chartCross->Series[0]->Legend->Visible = false;
		// ----------
		chartCross->Series[1]->Clear();
		chartCross->Series[1]->Legend->Visible = true;
		chartCross->Series[1]->Title = "Порог 1=" + FloatToStr(TGlSettings::thresholdC1) + "%";
		// ----
		chartCross->Series[2]->Clear();
		chartCross->Series[2]->Title = "Порог 2=" + FloatToStr(TGlSettings::thresholdC2) + "%";
		chartCross->Series[2]->Legend->Visible = true;
		// ---------
		chartLong->Series[0]->Clear();
		chartLong->Series[0]->Legend->Visible = false;
		chartLong->Series[1]->Clear();
		chartLong->Series[1]->Legend->Visible = true;
		chartLong->Series[1]->Title = "Порог 1=" + FloatToStr(TGlSettings::thresholdL1) + "%";
		chartLong->Series[2]->Clear();
		chartLong->Series[2]->Legend->Visible = true;
		chartLong->Series[2]->Title = "Порог 2=" + FloatToStr(TGlSettings::thresholdL2) + "%";
		// ---------------------
		chartThick->Series[0]->Clear();
		chartThick->Series[1]->Clear();
		chartThick->Series[2]->Clear();
		chartThick->Series[3]->Clear();
		chartThick->Series[0]->Legend->Visible = false;
		chartThick->Series[1]->Legend->Visible = false;
		// ------------------------------
		chartThick->Series[2]->Legend->Visible = true;
		double valMinT = RoundTo((TGlSettings::thresholdTNominal - TGlSettings::thresholdTDown * TGlSettings::thresholdTNominal / 100), -1);
		chartThick->Series[2]->Title = "Порог мин=" + FloatToStr(valMinT) + " мм";
		chartThick->Series[2]->Color = clBlue;
		chartThick->Series[3]->Legend->Visible = true;
		double valMaxT = RoundTo((TGlSettings::thresholdTNominal + TGlSettings::thresholdTUp * TGlSettings::thresholdTNominal / 100), -1);
		chartThick->Series[3]->Title = "Порог макс=" + FloatToStr(valMaxT) + " мм"; ;
		chartThick->Series[3]->Color = clRed;
		chartThick->Title->Clear();
		chartThick->Title->Text->Add("КОНТРОЛЬ ТОЛЩИНЫ(МНК1)");
		chartThick->LeftAxis->Title->Caption = FloatToStr(TGlSettings::thresholdTNominal) + " мм";
		chartThick->LeftAxis->Title->Angle = 0;
		menuViewLog->Checked = false;
		pnlLeft->Width = 0;
	}
	catch (Exception *ex) {
		err = -1;
		TLog::ErrFullSaveLog(ex);
		// AnsiString msg
		// programSettings.colorMSG = programSettings.colorBrak;
		// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
	return err;
}

void __fastcall TfmMain::menuSOPClick(TObject *Sender) {
	menuSOP->Checked = !menuSOP->Checked;
	if (menuSOP->Checked) {
		// TGlSettings::isSOP = 1;
		bbtMode->Font->Color = clBlue;
	}
	else {
		// TGlSettings::isSOP = 0;
	}
	// if (TGlSettings::isSOP == 1) {
	if (menuSOP->Checked) {
		bbtMode->Caption = "РЕЖИМ СОП (типоразмер:" + IntToStr(TGlSettings::indTypeSize) + ")";
		SqlDBModule->UpdIntSql("flags", "isSop", 1, NULL);
	}
	else {
		bbtMode->Caption = "РЕЖИМ КОНТРОЛЯ (типоразмер:" + IntToStr(TGlSettings::indTypeSize) + ")";
		SqlDBModule->UpdIntSql("flags", "isSop", 0, NULL);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfmMain::menuShowLogClick(TObject *Sender) {
	menuShowLog->Checked = !menuShowLog->Checked;
	if (!menuShowLog->Checked) {
		// pnlLeft->Align=alLeft;
		pnlLeft->Width = 0;
		lbxInfo->Visible = false;

	}
	else {
		// lbxInfo->Align=alClient;
		pnlLeft->Width = 300;
		lbxInfo->Visible = true;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfmMain::bbtTestClick(TObject *Sender) {
	AnsiString strTmp = "";
	int err = 0;
	TReplaceFlags ReplaceFlags;
	// AnsiString strSqlWhere = "numFusion=324  and numTube=160";
	// // --------------
	// strTmp = "select rec_id,numTube,numFusion,thresholdTUp,thresholdTDown";
	// strTmp +=
	// ",thresholdC1,thresholdC2,thresholdL1,thresholdL2 from numTube>0 and resultTubeShort where numFusion=61901481 and isEmpty=0 order by numTube";
	// // strTmp +="and isSop=0 and isEmpty=0 order by dtmCreate";
	// SqlDBModule->queryQuick->Close();
	// SqlDBModule->queryQuick->SQL->Text = strTmp;
	// SqlDBModule->queryQuick->Open();
	// for (int i = 0; i < SqlDBModule->queryQuick->RecordCount; i++) {
	// // int id = SqlDBModule->queryQuick->FieldByName("rec_id")->AsInteger;
	// // SqlDBModule->UpdIntSql("resultTubeShort", "numTube", (i + 1), "rec_id=" + IntToStr(id));
	// // int ff = SqlDBModule->queryQuick->FieldByName("numFusion")->AsInteger;
	// int tt = SqlDBModule->queryQuick->FieldByName("numTube")->AsInteger;
	// double T1 = SqlDBModule->queryQuick->FieldByName("thresholdTUp")->AsFloat;
	// double T2 = SqlDBModule->queryQuick->FieldByName("thresholdTDown")->AsFloat;
	// // --------------
	// double C1 = SqlDBModule->queryQuick->FieldByName("thresholdC1")->AsFloat;
	// double C2 = SqlDBModule->queryQuick->FieldByName("thresholdC2")->AsFloat;
	// // ------------
	// double L1 = SqlDBModule->queryQuick->FieldByName("thresholdL1")->AsFloat;
	// double L2 = SqlDBModule->queryQuick->FieldByName("thresholdL2")->AsFloat;
	// // RecalcData(
	// RecalcData(61901481, tt, 5.51, T1, T2, C1, C2, L1, L2);
	// SqlDBModule->queryQuick->Next();
	// }
	// SqlDBModule->queryQuick->Close();
	// 61901481
	// 61901482
	// 61901483
	// RecalcData(61901483, 17, 5.51, 20, 10, 55, 0, 33, 0);
	// // // strTmp = "SELECT [dbo].[GetBorderThickDownXML] (";
	// // // strTmp += IntToStr(34);
	// // // strTmp += ",";
	// // // strTmp += IntToStr(1);
	// // // strTmp += ") as F1";
	// // // strTmp = SqlDBModule->GetStrFromFunctionSql(strTmp, err);
	// // // strTmp = StringReplace(strTmp, ".", ",", ReplaceFlags << rfReplaceAll << rfIgnoreCase);
	// // // TGlSettings::thresholdL1 = StrToFloat(strTmp);
	// SqlDBModule->UpdFloatSql("resultTubeShort", "dtmCreate", Now(), strSqlWhere);
}

// ---------------------------------------------------------------------------
void __fastcall TfmMain::timerBackupTimer(TObject *Sender) {
	// strOut = "\tБУРАН 9955 Сводный отчет неразрушающего контроля от: " + FormatDateTime("yyyy.mm.dd hh:mm", Now());
	Word hour = 0;
	Word min = 0;
	Word sec = 0;
	Word mSec = 0;
	int err = 0;
	AnsiString strSql = "";
	AnsiString strTst = "";
	// procedure DecodeTime(const DateTime: TDateTime; var Hour, Min, Sec, MSec: Word);
	timerBackup->Enabled = false;
	DecodeTime(Now(), hour, min, sec, mSec);
	if ((hour == 8 && min < 10)) {
		lbxInfo->AddItem("TfmMain::timerBackupTimer", NULL);
		// try {
		// SqlDBModule->queryQuick->Close();
		// TGlSettings::fullNameBkpFile = SqlDBModule->GetStrFieldSQL("currentSettings", "ParamValueStr",
		// "isActual=1 and UPPER(ParamName)=UPPER('backupPath')", "E:\\MSQSL-BD\\BACKUP\\", err);
		// strTst = TGlSettings::fullNameBkpFile;
		//
		// // strSql="E:\\MSQSL-BD\\BACKUP\\
		// // SqlDBModule->queryQuick->SQL->Text = strSql;
		// // TGlSettings::fullNameBkpFile = "E:\\MSQSL-BD\\BACKUP\\";
		// if (!DirectoryExists(TGlSettings::fullNameBkpFile)) {
		// CreateDir(TGlSettings::fullNameBkpFile);
		// }
		// else {
		// //
		// }
		// TGlSettings::fullNameBkpFile += FormatDateTime("yyyy_mm_dd_", Now());
		// TGlSettings::fullNameBkpFile += "buran9955Pa.bak ";
		// strSql = " BACKUP DATABASE[buran9955Pa]TO DISK = N'";
		// strSql += TGlSettings::fullNameBkpFile;
		// // if (MessageDlg("Резервная копия БД будет сохранена в файл:\n" + TGlSettings::fullNameBkpFile + " \n ПРОДОЛЖИТЬ?", mtError,
		// // TMsgDlgButtons() << mbOK << mbCancel, 0) == mrOk) {
		// // //
		// // }
		// // else {
		// // return;
		// // }
		// strSql += "' WITH NOFORMAT, INIT, NAME = N'buran9955Pa-Полное Резервное копирование', SKIP, NOREWIND, NOUNLOAD, STATS = 10 ";
		// SqlDBModule->queryQuick->Close();
		// SqlDBModule->queryQuick->SQL->Text = strSql;
		// SqlDBModule->queryQuick->ExecSQL();
		// err = SqlDBModule->queryQuick->RowsAffected;
		// // MessageDlg(" Успешно завершено.", mtInformation, TMsgDlgButtons() << mbOK, NULL);
		// int err = 0;
		// }
		// catch (Exception *ex) {
		// err = -1;
		// TLog::ErrFullSaveLog(ex);
		// // AnsiString msg
		// // programSettings.colorMSG = programSettings.colorBrak;
		// // TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
		// // MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
		// }
	}
	else {
		//
	}
	timerBackup->Enabled = true;
}

// ---------------------------------------------------------------------------
void __fastcall TfmMain::menuViewArhClick(TObject *Sender) {
	// menuViewArh->Checked=!menuViewArh->Checked;
	// if (dialogOpenArh->Execute()) {
	// if (dialogOpenArh->FileName == "") {
	// return;
	// }
	// else {
	// //
	// }
	// }
	// else {
	// //
	// }
}

// ---------------------------------------------------------------------------
void __fastcall TfmMain::menuModifyClick(TObject *Sender) {
	UnicodeString newString;
	if (InputQuery((UnicodeString)"Запрос пароля", (UnicodeString)"Введите пароль:", newString)) {
		if (newString != TGlSettings::passwordEdit) {
			MessageDlg("Неверный пароль!", mtError, TMsgDlgButtons() << mbOK, NULL);
			return;
		}
		else {
			fmModifyRecord = new TfmModifyRecord(this);
			fmModifyRecord->ShowModal();
			delete fmModifyRecord;
		}
	}
	else {
		//
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfmMain::menuViewLogClick(TObject *Sender) {
	menuViewLog->Checked = !menuViewLog->Checked;
	if (menuViewLog->Checked) {
		pnlLeft->Width = 240;

	}
	else {
		pnlLeft->Width = 0;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfmMain::menuSetReadySecClick(TObject *Sender) {
	UnicodeString newString;
	if (InputQuery((UnicodeString)"Запрос пароля", (UnicodeString)"Введите пароль:", newString)) {
		if (newString != TGlSettings::passwordEdit) {
			MessageDlg("Неверный пароль!", mtError, TMsgDlgButtons() << mbOK, NULL);
			return;
		}
		else {
			SqlDBModule->UpdIntSql("flags", "isReady", 1, NULL);
			Sleep(1000);
			SqlDBModule->UpdIntSql("flags", "isReady", 0, NULL);
		}
	}
	else {
		//
	}

}
// ---------------------------------------------------------------------------
 //void CheckboxClick




