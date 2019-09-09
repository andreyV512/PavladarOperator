// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "unShowListTubes.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmShowListTubes *fmShowListTubes;

// ---------------------------------------------------------------------------
__fastcall TfmShowListTubes::TfmShowListTubes(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TfmShowListTubes::FormClose(TObject *Sender, TCloseAction &Action) {
	// int e = DBGridListTubes->Columns->Count;
	// for (int i = 0; i < e; i++) {
	// SqlDBModule->UpdIntSql("gridTubesColWidth", "colWidth", DBGridListTubes->Columns->Items[i]->Width, "colNum=" + IntToStr(i + 1));
	// }
	// queryShowTube->Close();
	// queryShowListTubes->Close();
}

// ---------------------------------------------------------------------------
void __fastcall TfmShowListTubes::menuShowZonesClick(TObject *Sender) {
	int t = queryShowListTubes->FieldByName("����� �����")->AsInteger;
	int f = queryShowListTubes->FieldByName("����� ������")->AsInteger;
	if (f == 0 || t == 0) {
		MessageDlg("������ �� ����� ���!", mtWarning, TMsgDlgButtons() << mbOK, NULL);
		return;
	}
	else {

	}
	ShowZones(Sender);
}

int TfmShowListTubes::ShowZones(TObject *_sender) {
	int err = 0;
	AnsiString title = "";
	AnsiString strOut = "";
	double tmpD = 0;
	double nominal = 0;
	try {
		timerRefresh->Enabled = false;
		if (fmShowZones == NULL) {
			fmShowZones = new TfmShowZones(NULL, queryShowListTubes);
			fmShowZones->ShowZones();
			fmShowZones->ShowModal();
		}
		else {
			// fmShowZones->ShowZones();
		}
		delete fmShowZones;
		fmShowZones = NULL;
		timerRefresh->Enabled = true;
		// // T6.typeSizeName as '���������� �����',T7.workShiftName as '�����',T1.numTube as '����� �����'"
		// title = " ����� ������:";
		// title += queryShowListTubes->FieldByName("����� ������")->AsString;
		// title += " ����� �����:";
		// title += queryShowListTubes->FieldByName("����� �����")->AsString;
		// fmShowZones->Caption = title;
		// title += " ����������:";
		// title += queryShowListTubes->FieldByName("����������")->AsString;
		// // fmShowZones->queryDirectory->Close();
		// // fmShowZones->queryDirectory->SQL->Text=strSql;
		// // fmShowZones->queryDirectory->Open();
		// strOut = "��������� �������� ����. ����� �������: ";
		// strOut += FloatToStr(queryShowListTubes->FieldByName("thresholdC1")->AsFloat);
		// strOut += "%";
		// strOut += " ����. ����� �������: ";
		// strOut += FloatToStr(queryShowListTubes->FieldByName("thresholdC2")->AsFloat);
		// strOut += "%";
		// // strOut+=" ��� ��������������:";
		// // strOut+="5";
		// strOut += " ���������:";
		// strOut += queryShowListTubes->FieldByName("���������� �.")->AsString;
		// fmShowZones->edtCross->Text = strOut;
		// strOut = "��������� �������� ����. ����� �������: ";
		// strOut += FloatToStr(queryShowListTubes->FieldByName("thresholdL1")->AsFloat);
		// strOut += "%";
		// strOut += " ����. ����� �������: ";
		// strOut += FloatToStr(queryShowListTubes->FieldByName("thresholdL2")->AsFloat);
		// strOut += "%";
		// // strOut+=" ��� ��������������:";
		// // strOut+="5";
		// strOut += " ���������:";
		// strOut += queryShowListTubes->FieldByName("���������� �.")->AsString;
		// fmShowZones->edtLong->Text = strOut;
		// strOut = "��������� �������� ����������� �������: ";
		// strOut += FloatToStr(queryShowListTubes->FieldByName("thresholdTNominal")->AsFloat);
		// strOut += " ��";
		// strOut += " ����������� �������: ";
		// nominal = queryShowListTubes->FieldByName("thresholdTNominal")->AsFloat;
		// tmpD = queryShowListTubes->FieldByName("thresholdTDown")->AsFloat;
		// tmpD = RoundTo((nominal - (tmpD * nominal / 100.0)), -1);
		// strOut += FloatToStr(tmpD);
		// strOut += " ��";
		// strOut += " ������������ �������: ";
		// tmpD = queryShowListTubes->FieldByName("thresholdTUp")->AsFloat;
		// tmpD = RoundTo((nominal + (tmpD * nominal / 100.0)), -1);
		// strOut += FloatToStr(tmpD);
		// strOut += " ��";
		// // strOut+=" ��� ��������������:";
		// // strOut+="5";
		// strOut += " ���������:";
		// strOut += queryShowListTubes->FieldByName("�. �������")->AsString;
		// fmShowZones->edtThick->Text = strOut;
		// // TGlSettings::thresholdC1 = queryShowListTubes->FieldByName("thresholdC1")->AsFloat;
		// // TGlSettings::thresholdC2 = queryShowListTubes->FieldByName("thresholdC2")->AsFloat;
		// // TGlSettings::thresholdL1 = queryShowListTubes->FieldByName("thresholdL1")->AsFloat;
		// // TGlSettings::thresholdL2 = queryShowListTubes->FieldByName("thresholdL2")->AsFloat;
		// // TGlSettings::thresholdTUp = queryShowListTubes->FieldByName("thresholdTUp")->AsFloat;
		// // TGlSettings::thresholdTDown = queryShowListTubes->FieldByName("thresholdTDown")->AsFloat;
		// // AnsiString a = queryShowListTubes->SQL->Text;
		// // TGlSettings::thresholdTNominal = queryShowListTubes->FieldByName("thresholdTNominal")->AsFloat;
		// // fmShowZones->numFusion=queryShowTubes->FieldByName("����� ������")->AsString;
		// // fmShowZones->numTube=queryShowTubes->FieldByName("����� �����")->AsString;
		// // fmShowZones->numTube = queryShowListTubes->FieldByName("numTube")->AsInteger;
		// fmShowZones->numTubeShow = queryShowListTubes->FieldByName("����� �����")->AsInteger;
		// fmShowZones->numFusionShow = queryShowListTubes->FieldByName("����� ������")->AsInteger;
		// fmShowZones->FillTitle(fmShowZones->numFusionShow, fmShowZones->numTubeShow);
		// //fmShowZones->RecalcData(fmShowZones->numFusionShow, fmShowZones->numTubeShow);
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
	return err;
}
// ---------------------------------------------------------------------------

void __fastcall TfmShowListTubes::FormCreate(TObject *Sender) {
	int err = 0;
	AnsiString strSqlF = "";
	AnsiString strSql = "";
	try {
	/*
		strSqlGlobal = " SELECT T1.dtmCreate as '���� � ����� ��������'";
		strSqlGlobal += ",T1.numFusion as '����� ������'";
		strSqlGlobal += ", T1.numTube as '����� �����' ";
		strSqlGlobal += ", T3.normDocName as '����������� ��������'";
		strSqlGlobal += ",T4.SopName as '�����. ���' ";
		strSqlGlobal += ", T5.steelGradeName as '����� �����', T6.typeSizeName as '����������', T7.workShiftName as '�����'";
		strSqlGlobal += ",T2.operatorName as '��������' ";
		strSqlGlobal += ",(case T1.resultT when 0 then '�����' when -1 then '��� ������' else '������' end) as '�. �������' ";
		strSqlGlobal += ",(case T1.resultC when 0 then '�����' when -1 then '��� ������' else '������' end) as '���������� �.' ";
		strSqlGlobal += ",(case T1.resultL when 0 then '�����' when -1 then '��� ������' else '������' end) as '���������� �.' ";
		strSqlGlobal += ",T1.lengthTube as '����� �����',T1.speedTube as '��������' ";
		strSqlGlobal += ",(case T1.isSOP when 0 then '���' when 1 then '��' else '����������' end) as '���' ";
		strSqlGlobal += " ,T1.thresholdC1,T1.thresholdC2,T1.thresholdL1,T1.thresholdL2,thresholdTUp,thresholdTDown,thresholdTNominal";
		strSqlGlobal += ",T1.pathFileNameThick as '���� ���1'";
		strSqlGlobal += ",T1.pathFileNameCross as '���� ���2'";
		strSqlGlobal += ",T1.pathFileNameLong as '���� ���3' ";
		strSqlGlobal +=
			" ,T1.indOperatorName,T1.indNormDocName,T1.indSopName,T1.indSteelGradeName,T1.indWorkShiftName,T1.indTypeSize,T1.dtmCreate ";
		strSqlGlobal += "	,YEAR(T1.dtmCreate) as Y1, MONTH(T1.dtmCreate) as M1 , DATEPART( dayofyear , T1.dtmCreate ) as DY1 ";
		strSqlGlobal += "	,YEAR(T1.dtmCreate) as Y2, MONTH(T1.dtmCreate) as M2 , DATEPART( dayofyear , T1.dtmCreate ) as DY2 ";
		strSqlGlobal += ",T1.numFusion";
		strSqlGlobal += ",T1.resultT";
		strSqlGlobal += ",T1.resultC";
		strSqlGlobal += ",T1.resultL";
		strSqlGlobal += ",T1.isSOP";
		strSqlGlobal += " FROM resultTubeShort T1 ";
		strSqlGlobal += " join operators T2 on(T1.indOperatorName = T2.rec_id)";
		strSqlGlobal += " join normDocs T3 on(T1.indNormDocName = T3.rec_id)";
		strSqlGlobal += " join Sops T4 on(T1.indSopName = T4.rec_id)";
		strSqlGlobal += " join steelGrades T5 on(T1.indSteelGradeName = T5.rec_id)";
		strSqlGlobal += " join tubesTypeSize T6 on(T1.indTypeSize = T6.rec_id)";
		strSqlGlobal += " join workShifts T7 on(T1.indWorkShiftName = T7.rec_id)";
		strSqlGlobal += " where numTube>0 and T1.isEmpty=0 and T1.numFusion=:pnumFusion  and resultT<>-100 ";
		// strSqlGlobal += " where T1.isEmpty=0";



		// strSql += " join resultLong T8 on(T1.numFusion = T8.numFusion and T1.numTube = T8.numTube and T1.sensorNum = T8.sensorNum)";
		// strSql += " join resultThick T9 on(T1.numFusion = T9.numFusion and T1.numTube = T9.numTube and T1.sensorNum = T9.sensorNum)";
		strSqlGlobal += " order by  T1.numFusion, T1.numTube ";
		*/
	   //	/*
  strSqlGlobal =
    "SELECT T1.dtmCreate as '���� � ����� ��������'"\
	",T1.numFusion as '����� ������'"\
	", T1.numTube as '����� �����'"\
	", T3.normDocName as '����������� ��������'"\
	",T4.SopName as '�����. ���'"\
	", T5.steelGradeName as '����� �����', T6.typeSizeName as '����������', T7.workShiftName as '�����'"\
	",T2.operatorName as '��������'"\
	",(case (SELECT count(*) FROM resultThick where numFusion=T1.numFusion and numTube=T1.numTube) when 0 then '��� ������' else"\
	" case T1.resultT when 0 then '�����' when -1 then '��� ������' else '������' end end) as '�. �������'"\
	",(case (SELECT  count(*) FROM resultCross where numFusion=T1.numFusion and numTube=T1.numTube) when 0 then '��� ������' else"\
	"    case T1.resultC when 0 then '�����' when -1 then '��� ������' else '������' end end) as '���������� �.'"\
	",(case (SELECT count(*) FROM resultLong where numFusion=T1.numFusion and numTube=T1.numTube) when 0 then '��� ������' else"\
	"    case T1.resultL when 0 then '�����' when -1 then '��� ������' else '������' end end) as '���������� �.'"\
	",T1.lengthTube as '����� �����',T1.speedTube as '��������'"\
	",(case T1.isSOP when 0 then '���' when 1 then '��' else '����������' end) as '���'"\
	" ,T1.thresholdC1,T1.thresholdC2,T1.thresholdL1,T1.thresholdL2,thresholdTUp,thresholdTDown,thresholdTNominal"\
	",T1.pathFileNameThick as '���� ���1'"\
	",T1.pathFileNameCross as '���� ���2'"\
	",T1.pathFileNameLong as '���� ���3'"\
	",T1.indOperatorName,T1.indNormDocName,T1.indSopName,T1.indSteelGradeName,T1.indWorkShiftName,T1.indTypeSize,T1.dtmCreate"\
	"		,YEAR(T1.dtmCreate) as Y1, MONTH(T1.dtmCreate) as M1 , DATEPART( dayofyear , T1.dtmCreate ) as DY1"\
	"		,YEAR(T1.dtmCreate) as Y2, MONTH(T1.dtmCreate) as M2 , DATEPART( dayofyear , T1.dtmCreate ) as DY2"\
	"	,T1.resultC   "\
	"	,T1.numFusion "\
	"	,T1.resultL   "\
	"	,T1.resultT   "\
	"	,T1.isSOP     "\
	"	 FROM resultTubeShort T1"\
	"	 join operators T2 on(T1.indOperatorName = T2.rec_id)"\
	"	 join normDocs T3 on(T1.indNormDocName = T3.rec_id)"\
	"	 join Sops T4 on(T1.indSopName = T4.rec_id)"\
	"	 join steelGrades T5 on(T1.indSteelGradeName = T5.rec_id)"\
	"	 join tubesTypeSize T6 on(T1.indTypeSize = T6.rec_id)"\
	"	 join workShifts T7 on(T1.indWorkShiftName = T7.rec_id)"\
	"	 where T1.numTube>0 and T1.isEmpty=0 and T1.numFusion=:pnumFusion  and resultT<>-100"\
	" order by  T1.numFusion, T1.numTube ";
	  //	  */

		lbeFuzion->Text = IntToStr(TGlSettings::currFusion);
		queryShowListTubes->Close();
		queryShowListTubes->SQL->Text = strSqlGlobal;
		queryShowListTubes->Parameters->ParamByName("pnumFusion")->Value = StrToInt(lbeFuzion->Text);
		queryShowListTubes->Open();
		// ������� �������� �������
		for (int i = 0; i < DBGridListTubes->Columns->Count; i++) {
			if (DBGridListTubes->Columns->Items[i]->Index > 15) {
				DBGridListTubes->Columns->Items[i]->Visible = false;
			}
			else {
				//
			}
		}
		strSqlF = strSql;
		// �������� ������ ��������
		SqlDBModule->queryQuick->Close();
		strSql = " SELECT colNum,colWidth FROM gridTubesColWidth order by colNum ";
		SqlDBModule->queryQuick->SQL->Text = strSql;
		SqlDBModule->queryQuick->Open();
		SqlDBModule->queryQuick->First();
		for (int i = 0; i < DBGridListTubes->Columns->Count; i++) {
			DBGridListTubes->Columns->Items[i]->Width = SqlDBModule->queryQuick->FieldByName("colWidth")->AsInteger;
			SqlDBModule->queryQuick->Next();
		}
		SqlDBModule->queryQuick->Close();
		// --------
		SqlDBModule->FillComboBox("operators", "operatorName", "isActive=1", cbxOperators);
		cbxOperators->AddItem("�� �������", NULL);
		cbxOperators->ItemIndex = (cbxOperators->Items->Count - 1);
		// --------
		SqlDBModule->FillComboBox("normDocs", "normDocName", "isActive=1", cbxNormDocs);
		cbxNormDocs->AddItem("�� �������", NULL);
		cbxNormDocs->ItemIndex = (cbxNormDocs->Items->Count - 1);
		// --------
		SqlDBModule->FillComboBox("Sops", "SopName", "isActive=1", cbxSops);
		cbxSops->AddItem("�� �������", NULL);
		cbxSops->ItemIndex = (cbxSops->Items->Count - 1);
		// --------
		SqlDBModule->FillComboBox("tubesTypeSize", "typeSizeName", "isActive=1", cbxFTubesTypeSize);
		cbxFTubesTypeSize->AddItem("�� �������", NULL);
		cbxFTubesTypeSize->ItemIndex = (cbxFTubesTypeSize->Items->Count - 1);
		// cbxSteelGrades
		SqlDBModule->FillComboBox("steelGrades", "steelGradeName", "isActive=1", cbxSteelGrades);
		cbxSteelGrades->AddItem("�� �������", NULL);
		cbxSteelGrades->ItemIndex = (cbxSteelGrades->Items->Count - 1);
		dtpEnd->Date = Now();
		DecodeDate(dtpEnd->Date, myYear, myMonth, dayYear);
		dayYear = DayOfTheYear(dtpEnd->Date);
		// strFilter="Y1>="+ IntToStr(myYear);
		// strFilter+=" and M1>="+ IntToStr(myMonth);
		// strFilter+=" and D1>="+ IntToStr(myMonth);
		dtpBegin->Date = EncodeDate(myYear, myMonth, 1);
		// DecodeDate(dtpEnd->Date , endYear, endMonth, endDay);
		// strFilter+=" and Y1<="+ IntToStr(endYear);
		// strFilter+=" and M1<="+ IntToStr(endMonth);
		// strFilter+=" and D1<="+ IntToStr(endDay);
		strFilter = " Y1=" + IntToStr(myYear);
		strFilter += " and M1=" + IntToStr(myMonth);
		// dtpBegin->Date=myDate;
		// myDay=1;
		// //������� � ������ ������
		// dtpBegin->Date= EncodeDate(myYear,myMonth,myDay);
		// dtpBegin->Time=StrToTime("00:00");
		// queryShowListTubes->Filtered=false;
		// strFilter="YEAR([���� � ����� ��������])="+ IntToStr(myYear);
		// strFilter+=" and MONTH([���� � ����� ��������])"+ IntToStr(myMonth);
		queryShowListTubes->Filter = strFilter;
		queryShowListTubes->Filtered = true;
		bbtFiltered->Caption = "������ �������:" + IntToStr(queryShowListTubes->RecordCount) + " �������";
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
	// return err;
}

// ---------------------------------------------------------------------------
void __fastcall TfmShowListTubes::bbtFilteredClick(TObject *Sender) {
	AnsiString strTmp = "";
	AnsiString strSql = "";
	int err = 0;
	TReplaceFlags ReplaceFlags;
	// AnsiString strSql;
	try {
		// for (int i = 0; i < queryShowListTubes->FieldCount; i++) {
		// strFilter=queryShowListTubes->Fields->FieldByNumber(i+1)->FieldName;//������ ����� ���������� � 1
		// }
		bbtResetFiltr->Font->Color = clRed;
		strFilter = "";
		numRec = queryShowListTubes->RecNo;
		queryShowListTubes->Close();
		queryShowListTubes->Filtered = false;
		if (lbeFuzion->Text == "���" || lbeFuzion->Text == "*") {
			queryShowListTubes->Close();
			strSqlGlobal = StringReplace(strSqlGlobal, "T1.numFusion=:pnumFusion", "T1.numFusion is Not NULL",
				ReplaceFlags << rfReplaceAll << rfIgnoreCase);
			// //queryShowListTubes->Close();

		}
		else {
			// strFilter += " and [����� ������] LIKE '%" + lbeFuzion->Text + "%'";
			// strFilter += " and [����� ������] = " + (AnsiString)lbeFuzion->Text;
			strSqlGlobal = StringReplace(strSqlGlobal, "T1.numFusion is Not NULL", "T1.numFusion=:pnumFusion",
				ReplaceFlags << rfReplaceAll << rfIgnoreCase);

			queryShowListTubes->SQL->Text = strSqlGlobal;
			queryShowListTubes->Parameters->ParamByName("pnumFusion")->Value = StrToInt(lbeFuzion->Text);
		}
		// ----------------------
		if (cbxBrackAll->Checked) {
			// strFilter += " and [�. �������] LIKE  '%������%'";
			// strSqlGlobal+=" and (resultT>0 or resultC>0 or resultL>0) ";

			strSqlGlobal = StringReplace(strSqlGlobal, " and resultT<>-100 ", " and (resultT>0 or resultC>0 or resultL>0) ",
				ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		}
		else {
			strSqlGlobal = StringReplace(strSqlGlobal, " and (resultT>0 or resultC>0 or resultL>0) ", " and resultT<>-100 ",
				ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		}
		queryShowListTubes->SQL->Text = strSqlGlobal;
		queryShowListTubes->Open();
		// �������� ������ ��������
		SqlDBModule->queryQuick->Close();
		strSql = " SELECT colNum,colWidth FROM gridTubesColWidth order by colNum ";
		SqlDBModule->queryQuick->SQL->Text = strSql;
		SqlDBModule->queryQuick->Open();
		SqlDBModule->queryQuick->First();
		for (int i = 0; i < DBGridListTubes->Columns->Count; i++) {
			DBGridListTubes->Columns->Items[i]->Width = SqlDBModule->queryQuick->FieldByName("colWidth")->AsInteger;
			SqlDBModule->queryQuick->Next();
		}
		SqlDBModule->queryQuick->Close();
		// --------- serg1
		// DecodeDate(dtpBegin->Date, myYear, myMonth, dayYear);
		// dayYear = DayOfTheYear(dtpBegin->Date);
		// strFilter = "Y1>=" + IntToStr(myYear);
		// strFilter += " and DY1>=" + IntToStr(dayYear);
		// DecodeDate(dtpEnd->Date, endYear, endMonth, endDayYear);
		// endDayYear = DayOfTheYear(dtpEnd->Date);
		// strFilter += " AND Y2<=" + IntToStr(endYear);
		// strFilter += " and DY2<=" + IntToStr(endDayYear);
		// --------- T1.dtmCreate
		strFilter += " dtmCreate >=";
		strFilter += DateToStr(dtpBegin->Date);
		strFilter += " AND dtmCreate <=";
		strFilter += DateToStr(dtpEnd->Date + 1);
		// strTmp=
		queryShowListTubes->Filter = strFilter;
		queryShowListTubes->Filtered = true;
		queryShowListTubes->Filtered = false;
		queryShowListTubes->Filter = strFilter;
		if (lbeFuzion->Text == "���" || lbeFuzion->Text == "*") {
			//
		}
		else {
			// strFilter += " and [����� ������] LIKE '%" + lbeFuzion->Text + "%'";
			strFilter += " and [����� ������] = " + (AnsiString)lbeFuzion->Text;
			// queryShowListTubes->Parameters->ParamByName("pnumFusion")->Value = StrToInt(lbeFuzion->Text);
		}
		if (lbeNumTube->Text == "���" || lbeNumTube->Text == "*") {
			//
		}
		else {
			// strFilter += " and [����� �����] LIKE '%" + lbeNumTube->Text + "%'";
			strFilter += " and [����� �����] = " + lbeNumTube->Text;
		}
		if (cbxOperators->ItemIndex == (cbxOperators->Items->Count - 1)) {
			//
		}
		else {
			strFilter += " and [indOperatorName] = " + IntToStr((int)cbxOperators->Items->Objects[cbxOperators->ItemIndex]);
		}
		if (cbxNormDocs->ItemIndex == (cbxNormDocs->Items->Count - 1)) {
			//
		}
		else {
			strFilter += " and [indNormDocName] = " + IntToStr((int)cbxNormDocs->Items->Objects[cbxNormDocs->ItemIndex]);
		}
		if (cbxSops->ItemIndex == (cbxSops->Items->Count - 1)) {
			//
		}
		else {
			strFilter += " and [indSopName] = " + IntToStr((int)cbxSops->Items->Objects[cbxSops->ItemIndex]);
		}
		if (cbxSteelGrades->ItemIndex == (cbxSteelGrades->Items->Count - 1)) {
			//
		}
		else {
			strFilter += " and [indSteelGradeName] = " + IntToStr((int)cbxSteelGrades->Items->Objects[cbxSteelGrades->ItemIndex]);
		}
		if (cbxFTubesTypeSize->ItemIndex == (cbxFTubesTypeSize->Items->Count - 1)) {
			//
		}
		else {
			strFilter += " and [indTypeSize] = " + IntToStr((int)cbxFTubesTypeSize->Items->Objects[cbxFTubesTypeSize->ItemIndex]);
		}
		// strSqlGlobal = StringReplace(strSqlGlobal," and (resultT>0 or resultC>0 or resultL>0) ", " ",
		// ReplaceFlags << rfReplaceAll << rfIgnoreCase);
		if (cbxBrackT->Checked) {
			strFilter += " and [�. �������] LIKE  '%������%'";
			// strSqlGlobal+=" and (resultT>0 or resultC>0 or resultL>0) ";
		}
		else {
			//
		}
		if (cbxBrackC->Checked) {
			strFilter += " and [���������� �.] LIKE  '%������%'";
			// strSqlGlobal+=" and (resultT>0 or resultC>0 or resultL>0) ";
		}
		else {
			//
		}
		if (cbxBrackL->Checked) {
			strFilter += " and [���������� �.] LIKE  '%������%'";
			// strSqlGlobal+=" and (resultT>0 or resultC>0 or resultL>0) ";
		}
		else {
			//
		}
		if (cbxWithSOP->Checked) {
			//
		}
		else {
			// strFilter += " and [isSOP]>1'";
			strFilter += " and [isSOP] = " + IntToStr(0);
		}
		queryShowListTubes->Filter = strFilter;
		queryShowListTubes->Filtered = true;
		bbtFiltered->Caption = "������ �������:" + IntToStr(queryShowListTubes->RecordCount) + " �������";
		// SqlDBModule->queryQuick->Refresh();
		err = 0;
		// AnsiString strSql = " SELECT T1.rec_id as 'TubeID', T2.operatorName as '', T3.normDocName as '����������� ��������',";
		// strSql += "T4.SopName as '������������� ���' ";
		// strSql += ", T5.steelGradeName as '����� �����', T6.typeSizeName as '���������� �����', T7.workShiftName as '�����',";
		// strSql += "	T1.numTube as '' ";
		// strSql += ", T1.numFusion as '����� ������', T1.dtmCreate as '���� � ����� ��������', T1.pathFileNameLong as '���� � ������' ";
		// strSql += ", T1.speedTube as '��������', T1.lengthTube as '����� �����' ";
		// strSql += ", (case T1.resultC when 0 then '�����' else '������' end) as '����������' ";
		// strSql += ", (case T1.resultL when 0 then '�����'";
		// strSql += "	else '������' end) as '����������' ";
		// strSql += ",(case T1.resultT when 0 then '�����'";
		// strSql += "	else '������' end) as '����������' ";
		// strSql += " FROM resultTubeShort T1 ";
		// strSql += " join operators T2 on(T1. = T2.rec_id)";
		// strSql += " join normDocs T3 on(T1. = T3.rec_id)";
		// strSql += " join Sops T4 on(T1. = T4.rec_id)";
		// strSql += " join steelGrades T5 on(T1. = T5.rec_id)";
		// strSql += " join tubesTypeSize T6 on(T1.indTypeSize = T6.rec_id)";
		// strSql += " join workShifts T7 on(T1.indWorkShiftName = T7.rec_id)";
		// //
		// // strSql += " join resultLong T8 on(T1.numFusion = T8.numFusion and T1.numTube = T8.numTube and T1.sensorNum = T8.sensorNum)";
		// // strSql += " join resultThick T9 on(T1.numFusion = T9.numFusion and T1.numTube = T9.numTube and T1.sensorNum = T9.sensorNum)";
		// strSql += " order by T1.rec_id, T1.numFusion, T1.numTube ";
		bbtFiltered->Font->Color = clBlack;
		if (numRec > 0 && numRec < queryShowListTubes->RecordCount) {
			queryShowListTubes->RecNo = numRec;
		}
		else {
			//
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
	// return err;
}

// ---------------------------------------------------------------------------
void __fastcall TfmShowListTubes::bbtResetFiltrClick(TObject *Sender) {
	int err = 0;
	TReplaceFlags ReplaceFlags;
	AnsiString strSql;
	try {
		err = queryShowListTubes->Filter.Length();
		if (err != 0) {
			bbtResetFiltr->Font->Color = clBlack;
			queryShowListTubes->Filter = "";
			strFilter = "";
			// lbeFuzion->Text == "*";
			lbeNumTube->Text == "*";
			cbxOperators->ItemIndex = (cbxOperators->Items->Count - 1);
			cbxNormDocs->ItemIndex = (cbxNormDocs->Items->Count - 1);
			cbxSops->ItemIndex = (cbxSops->Items->Count - 1);
			cbxSteelGrades->ItemIndex = (cbxSteelGrades->Items->Count - 1);
			cbxFTubesTypeSize->ItemIndex = (cbxFTubesTypeSize->Items->Count - 1);
			queryShowListTubes->Filtered = false;
			cbxBrackT->Checked = false;
			cbxBrackC->Checked = false;
			cbxBrackL->Checked = false;
			cbxBrackAll->Checked = false;
			strSqlGlobal = StringReplace(strSqlGlobal, "T1.numFusion=:pnumFusion", "T1.numFusion is Not NULL",
				ReplaceFlags << rfReplaceAll << rfIgnoreCase);
			strSqlGlobal = StringReplace(strSqlGlobal, " and (resultT>0 or resultC>0 or resultL>0) ", " and resultT<>-100 ",
				ReplaceFlags << rfReplaceAll << rfIgnoreCase);
			lbeFuzion->Text = "*";
			queryShowListTubes->Close();
			queryShowListTubes->SQL->Text = strSqlGlobal;
			queryShowListTubes->Open();
			bbtFiltered->Caption = "������ �������:" + IntToStr(queryShowListTubes->RecordCount) + " �������";
			// �������� ������ ��������
			SqlDBModule->queryQuick->Close();
			strSql = " SELECT colNum,colWidth FROM gridTubesColWidth order by colNum ";
			SqlDBModule->queryQuick->SQL->Text = strSql;
			SqlDBModule->queryQuick->Open();
			SqlDBModule->queryQuick->First();
			for (int i = 0; i < DBGridListTubes->Columns->Count; i++) {
				DBGridListTubes->Columns->Items[i]->Width = SqlDBModule->queryQuick->FieldByName("colWidth")->AsInteger;
				SqlDBModule->queryQuick->Next();
			}
			SqlDBModule->queryQuick->Close();
		}
		else {
			//
		}
		bbtFiltered->Font->Color = clGreen;
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

void __fastcall TfmShowListTubes::mnuPrintSelectedClick(TObject *Sender) {
	fmReport = new TfmReport(this, queryShowTube);
	// OutToRtf();
	OutToRtfStream();
	fmReport->ShowModal();
	delete fmReport;

}

// ---------------------------------------------------------------------------
int TfmShowListTubes::OutToRtf() {
	int err = 0;
	AnsiString strOut = "";
	AnsiString strTmp = "";
	fmReport->RichEdit->Clear();
	// int numPage=0;
	fmReport->RichEdit->Lines->Add(strOut);
	strOut = "\t����� 9955 ������� ����� �������������� �������� ��: " + FormatDateTime("yyyy.mm.dd hh:mm", Now());
	fmReport->RichEdit->Lines->Add(strOut);
	strOut = "";
	fmReport->RichEdit->Lines->Add(strOut);
	// fmReport->RichEdit->Lines->Add(strOut);
	// for (int i = 0; i < queryShowListTubes->RecordCount; i++) {
	queryShowListTubes->First();

	strOut = "\t����� ������";
	strOut += "\t����������";
	strOut += "\t\t����������� ��������";
	strOut += "\t����� �����";
	// strOut += "\t����������";
	fmReport->RichEdit->Lines->Add(strOut);
	// ------------------------------
	strOut = "\t" + queryShowListTubes->FieldByName("����� ������")->AsString;
	strOut += "\t\t" + queryShowListTubes->FieldByName("����������")->AsString;
	strOut += "\t\t" + Trim(queryShowListTubes->FieldByName("����������� ��������")->AsString);
	strTmp = Trim(queryShowListTubes->FieldByName("����������� ��������")->AsString);
	int tt = strTmp.Length();
	// if (strTmp.Length() < 8) {
	// strOut += "\t\t\t" + Trim(queryShowListTubes->FieldByName("����� �����")->AsString);
	// }
	// else {
	// strOut += "\t" + Trim(queryShowListTubes->FieldByName("����� �����")->AsString);
	// }
	strOut += "\t\t" + Trim(queryShowListTubes->FieldByName("����� �����")->AsString);
	// strOut +=  queryShowListTubes->FieldByName("����� �����")->AsString;
	fmReport->RichEdit->Lines->Add(strOut);
	// ----------------------------
	strOut = "";
	fmReport->RichEdit->Lines->Add(strOut);
	// --------------------------------
	strOut = "\t�����. ���";
	strOut += "\t��������";
	strOut += "\t\t���������� ����";
	fmReport->RichEdit->Lines->Add(strOut);
	// ----------------------
	strOut = "\t" + queryShowListTubes->FieldByName("�����. ���")->AsString;
	strOut += "\t\t\t" + queryShowListTubes->FieldByName("��������")->AsString;
	strOut += "\t\t" + IntToStr(queryShowListTubes->RecordCount);
	fmReport->RichEdit->Lines->Add(strOut);
	// --------------------------------------
	strOut = "";
	fmReport->RichEdit->Lines->Add(strOut);
	strOut = "\t�����";
	strOut += "\t���� � ����� ��������";
	strOut += "\t����� �����";
	// fmReport->RichEdit->Lines->Add(strOut);
	strOut += "\t�������� ���1";
	strOut += "\t�������� ���2";
	strOut += "\t�������� ���3";
	fmReport->RichEdit->Lines->Add(strOut);
	// ---------------------------
	while (!queryShowListTubes->Eof) {
		strOut = "\t" + queryShowListTubes->FieldByName("����� �����")->AsString;
		strOut += "\t\t" + queryShowListTubes->FieldByName("���� � ����� ��������")->AsString;
		strOut += "\t\t" + queryShowListTubes->FieldByName("����� �����")->AsString;
		strTmp = queryShowListTubes->FieldByName("����� �����")->AsString;
		if (strTmp.Length() > 5) {
			strOut += "\t\t" + queryShowListTubes->FieldByName("�. �������")->AsString;
		}
		else {
			strOut += "\t\t\t" + queryShowListTubes->FieldByName("�. �������")->AsString;
		}
		// fmReport->RichEdit->Lines->Add(strOut);
		// strTmp = queryShowListTubes->FieldByName("�. �������")->AsString;
		if (strTmp.Length() > 5) {
			strOut += "\t\t\t" + queryShowListTubes->FieldByName("���������� �.")->AsString;
		}
		else {
			strOut += "\t\t" + queryShowListTubes->FieldByName("���������� �.")->AsString;
		}
		// strOut += "\t\t" + queryShowListTubes->FieldByName("��������� ���2(C)")->AsString;
		// strTmp = queryShowListTubes->FieldByName("���������� �.")->AsString;
		if (strTmp.Length() > 5) {
			strOut += "\t\t\t" + queryShowListTubes->FieldByName("���������� �.")->AsString;
		}
		else {
			strOut += "\t\t" + queryShowListTubes->FieldByName("���������� �.")->AsString;
		}
		// strOut += "\t\t" + queryShowListTubes->FieldByName("��������� ���3(L)")->AsString;
		fmReport->RichEdit->Lines->Add(strOut);
		// -----------------------
		// strOut = "";
		// fmReport->RichEdit->Lines->Add(strOut);
		// fmReport->RichEdit->Lines->Add(strOut);
		// -------------------------
		queryShowListTubes->Next();
	}
	return err;
}

int TfmShowListTubes::OutToRtfStream() {
	int err = 0;
	AnsiString strOut = "";
	AnsiString strTmp = "";
	int numPage = 1;
	fmReport->RichEdit->Clear();
	try {
		if (fmReport->streamRtf) {
			delete fmReport->streamRtf;
			fmReport->streamRtf = NULL;
		}
		else {
			fmReport->streamRtf = new TStringStream();
		}
		fmReport->streamRtf->WriteString("{\\rtf1\\ansi\\ansicpg1251\\deff0\\nouicompat\\deflang1049\\deflangfe1049\\deftab708 \n");
		fmReport->streamRtf->WriteString("{\\fonttbl \n"); // ������
		fmReport->streamRtf->WriteString("{\\f0\\fmodern\\fprq1\\fcharset204 Courier New;} \n");
		fmReport->streamRtf->WriteString("{\\f1\\fmodern\\fprq1\\fcharset204 Courier New;}} \n"); // ������
		fmReport->streamRtf->WriteString("{\\colortbl ;\\red0\\green0\\blue255;} \n"); // 0-�����
		fmReport->streamRtf->WriteString("\\viewkind4\\uc1 \n");
		fmReport->streamRtf->WriteString("\\par \n");
		fmReport->streamRtf->WriteString("\\pard\\nowidctlpar\\f0\\fs28\\par \n");
		fmReport->streamRtf->WriteString("\\pard\\widctlpar\\li-567\\sa200\\sl276\\slmult1\\qc \n");
		fmReport->streamRtf->WriteString("����� 9955 ������� ����� �������������� �������� ");
		fmReport->streamRtf->WriteString("\\par");
		fmReport->streamRtf->WriteString("\\pard\\widctlpar\\fi1275\\li-567\\sa200\\sl276\\slmult1\\fs24 \n");
		fmReport->streamRtf->WriteString("������: ");
		fmReport->streamRtf->WriteString(FormatDateTime("yyyy.mm.dd hh:mm", Now()));
		fmReport->streamRtf->WriteString("\\par\n");
		fmReport->streamRtf->WriteString("���������� ���� � ������: ");
		fmReport->streamRtf->WriteString(IntToStr(queryShowListTubes->RecordCount));
		fmReport->streamRtf->WriteString("\\par\n");
		// ������� ���������
		fmReport->streamRtf->WriteString("\\trowd\\trgaph108\\trleft176\\trbrdrl\\brdrs\\brdrw10 \\trbrdrt\\brdrs\\brdrw10 \n");
		fmReport->streamRtf->WriteString
			("\\trbrdrr\\brdrs\\brdrw10 \\trbrdrb\\brdrs\\brdrw10 \\trpaddl108\\trpaddr108\\trpaddfl3\\trpaddfr3 \n");
		fmReport->streamRtf->WriteString
			("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs\n");
		fmReport->streamRtf->WriteString("\\cellx2127\n"); // 1 cell
		fmReport->streamRtf->WriteString
			("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
		fmReport->streamRtf->WriteString("\\cellx4395\n"); // 2 cell
		fmReport->streamRtf->WriteString
			("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
		fmReport->streamRtf->WriteString("\\cellx7797\n"); // 3 cell //4 cell //5 cell
		fmReport->streamRtf->WriteString
			("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
		fmReport->streamRtf->WriteString("\\cellx10065\n");
		fmReport->streamRtf->WriteString("\\pard\\intbl\\widctlpar");
		fmReport->streamRtf->WriteString("����� ������");
		fmReport->streamRtf->WriteString("\\cell");
		fmReport->streamRtf->WriteString("����������");
		fmReport->streamRtf->WriteString("\\cell");
		fmReport->streamRtf->WriteString("����������� ��������");
		fmReport->streamRtf->WriteString("\\cell");
		fmReport->streamRtf->WriteString("����� �����");
		fmReport->streamRtf->WriteString("\\cell\\row\n"); // ����� ������ 1
		// --------------------------
		fmReport->streamRtf->WriteString("\\trowd\\trgaph108\\trleft176\\trbrdrl\\brdrs\\brdrw10 \\trbrdrt\\brdrs\\brdrw10 \n");
		fmReport->streamRtf->WriteString
			("\\trbrdrr\\brdrs\\brdrw10 \\trbrdrb\\brdrs\\brdrw10 \\trpaddl108\\trpaddr108\\trpaddfl3\\trpaddfr3 \n");
		fmReport->streamRtf->WriteString
			("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs\n");
		fmReport->streamRtf->WriteString("\\cellx2127\n"); // 1 cell
		fmReport->streamRtf->WriteString
			("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
		fmReport->streamRtf->WriteString("\\cellx4395\n"); // 2 cell
		fmReport->streamRtf->WriteString
			("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
		fmReport->streamRtf->WriteString("\\cellx7797\n"); // 3 cell //4 cell //5 cell
		fmReport->streamRtf->WriteString
			("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
		fmReport->streamRtf->WriteString("\\cellx10065\n");
		fmReport->streamRtf->WriteString("\\pard\\intbl\\widctlpar");
		fmReport->streamRtf->WriteString(" " + queryShowListTubes->FieldByName("����� ������")->AsString);
		fmReport->streamRtf->WriteString("\\cell");
		fmReport->streamRtf->WriteString(" " + Trim(queryShowListTubes->FieldByName("����������")->AsString));
		fmReport->streamRtf->WriteString("\\cell");
		fmReport->streamRtf->WriteString(" " + Trim(queryShowListTubes->FieldByName("����������� ��������")->AsString));
		fmReport->streamRtf->WriteString("\\cell");
		fmReport->streamRtf->WriteString(" " + Trim(queryShowListTubes->FieldByName("����� �����")->AsString));
		fmReport->streamRtf->WriteString("\\cell\\row\n"); // ����� ������ 2
		// ----------------
		fmReport->streamRtf->WriteString("\\pard\\widctlpar\\li-567\\sa200\\sl276\\slmult1\\par "); // ����� �������
		fmReport->streamRtf->WriteString("\\par\n");
		// // ----------------------------
		// ������� 2 ���������
		fmReport->streamRtf->WriteString("\\trowd\\trgaph108\\trleft176\\trbrdrl\\brdrs\\brdrw10 \\trbrdrt\\brdrs\\brdrw10 \n");
		fmReport->streamRtf->WriteString
			("\\trbrdrr\\brdrs\\brdrw10 \\trbrdrb\\brdrs\\brdrw10 \\trpaddl108\\trpaddr108\\trpaddfl3\\trpaddfr3 \n");
		fmReport->streamRtf->WriteString
			("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs\n");
		fmReport->streamRtf->WriteString("\\cellx2127\n"); // 1 cell
		fmReport->streamRtf->WriteString
			("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
		fmReport->streamRtf->WriteString("\\cellx7797\n"); // 2 cell
		fmReport->streamRtf->WriteString("\\pard\\intbl\\widctlpar");
		fmReport->streamRtf->WriteString("���");
		fmReport->streamRtf->WriteString("\\cell");
		fmReport->streamRtf->WriteString("��������");
		fmReport->streamRtf->WriteString("\\cell\\row"); // ����� ������ 1
		// --------------------------
		fmReport->streamRtf->WriteString("\\trowd\\trgaph108\\trleft176\\trbrdrl\\brdrs\\brdrw10 \\trbrdrt\\brdrs\\brdrw10 \n");
		fmReport->streamRtf->WriteString
			("\\trbrdrr\\brdrs\\brdrw10 \\trbrdrb\\brdrs\\brdrw10 \\trpaddl108\\trpaddr108\\trpaddfl3\\trpaddfr3 \n");
		fmReport->streamRtf->WriteString
			("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs\n");
		fmReport->streamRtf->WriteString("\\cellx2127\n"); // 1 cell
		fmReport->streamRtf->WriteString
			("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
		fmReport->streamRtf->WriteString("\\cellx7797\n"); // 2 cell
		fmReport->streamRtf->WriteString("\\pard\\intbl\\widctlpar");
		fmReport->streamRtf->WriteString(" " + Trim(queryShowListTubes->FieldByName("�����. ���")->AsString));
		fmReport->streamRtf->WriteString("\\cell");
		fmReport->streamRtf->WriteString(" " + Trim(queryShowListTubes->FieldByName("��������")->AsString));
		fmReport->streamRtf->WriteString("\\cell\\row"); // ����� ������ 2
		// ----------------
		fmReport->streamRtf->WriteString("\\pard\\widctlpar\\li-567\\sa200\\sl276\\slmult1\\par "); // ����� �������
		// ------------------  ������� 3 ������ ���������
		fmReport->streamRtf->WriteString("\\trowd\\trgaph108\\trleft176\\trbrdrl\\brdrs\\brdrw10 \\trbrdrt\\brdrs\\brdrw10 \n");
		fmReport->streamRtf->WriteString
			("\\trbrdrr\\brdrs\\brdrw10 \\trbrdrb\\brdrs\\brdrw10 \\trpaddl108\\trpaddr108\\trpaddfl3\\trpaddfr3 \n");
		fmReport->streamRtf->WriteString
			("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs\n");
		fmReport->streamRtf->WriteString("\\cellx3119\n"); // 1 cell
		fmReport->streamRtf->WriteString
			("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
		fmReport->streamRtf->WriteString("\\cellx4253\n"); // 2 cell
		fmReport->streamRtf->WriteString
			("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
		fmReport->streamRtf->WriteString("\\cellx6096\n"); // 3 cell //4 cell //5 cell
		fmReport->streamRtf->WriteString
			("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
		fmReport->streamRtf->WriteString("\\cellx8222\n");
		fmReport->streamRtf->WriteString
			("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
		fmReport->streamRtf->WriteString("\\cellx10348\n");
		fmReport->streamRtf->WriteString("\\pard\\intbl\\widctlpar");
		fmReport->streamRtf->WriteString("���� � �����");
		fmReport->streamRtf->WriteString("\\cell");
		fmReport->streamRtf->WriteString("�����");
		fmReport->streamRtf->WriteString("\\cell");
		fmReport->streamRtf->WriteString("�. �������");
		fmReport->streamRtf->WriteString("\\cell");
		fmReport->streamRtf->WriteString("���������� �.");
		fmReport->streamRtf->WriteString("\\cell");
		fmReport->streamRtf->WriteString("���������� �.");
		fmReport->streamRtf->WriteString("\\cell\\row\n"); // ����� ������ ����������
		// --------------------------
		queryShowListTubes->First();
		int rr = queryShowListTubes->RecordCount;
		while (!queryShowListTubes->Eof) {
			if (queryShowListTubes->RecNo % countRows1 == 0 && numPage == 1) {
				numPage++;
				fmReport->streamRtf->WriteString("\\par\n");
				fmReport->streamRtf->WriteString("\\pard\\widctlpar\\li-567\\sa200\\sl276\\slmult1\\par "); // ����� �������
				fmReport->streamRtf->WriteString("\\par\n");
				fmReport->streamRtf->WriteString("����� 9955 ������� ����� �������������� �������� ");
				fmReport->streamRtf->WriteString("\\par");
				fmReport->streamRtf->WriteString("\\pard\\widctlpar\\fi1275\\li-567\\sa200\\sl276\\slmult1\\fs24 \n");
				fmReport->streamRtf->WriteString("������: ");
				fmReport->streamRtf->WriteString(FormatDateTime("yyyy.mm.dd hh:mm", Now()));
				fmReport->streamRtf->WriteString("\\par\n");
				fmReport->streamRtf->WriteString("���������� ���� � ������: ");
				fmReport->streamRtf->WriteString(IntToStr(queryShowListTubes->RecordCount));
				fmReport->streamRtf->WriteString("\\par\n");
				fmReport->streamRtf->WriteString("\\trowd\\trgaph108\\trleft176\\trbrdrl\\brdrs\\brdrw10 \\trbrdrt\\brdrs\\brdrw10 \n");
				fmReport->streamRtf->WriteString
					("\\trbrdrr\\brdrs\\brdrw10 \\trbrdrb\\brdrs\\brdrw10 \\trpaddl108\\trpaddr108\\trpaddfl3\\trpaddfr3 \n");
				fmReport->streamRtf->WriteString
					("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs\n");
				fmReport->streamRtf->WriteString("\\cellx3119\n"); // 1 cell
				fmReport->streamRtf->WriteString
					("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
				fmReport->streamRtf->WriteString("\\cellx4253\n"); // 2 cell
				fmReport->streamRtf->WriteString
					("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
				fmReport->streamRtf->WriteString("\\cellx6096\n"); // 3 cell //4 cell //5 cell
				fmReport->streamRtf->WriteString
					("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
				fmReport->streamRtf->WriteString("\\cellx8222\n");
				fmReport->streamRtf->WriteString
					("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
				fmReport->streamRtf->WriteString("\\cellx10348\n");
				fmReport->streamRtf->WriteString("\\pard\\intbl\\widctlpar");
				fmReport->streamRtf->WriteString("���� � �����");
				fmReport->streamRtf->WriteString("\\cell");
				fmReport->streamRtf->WriteString("�����");
				fmReport->streamRtf->WriteString("\\cell");
				fmReport->streamRtf->WriteString("�. �������");
				fmReport->streamRtf->WriteString("\\cell");
				fmReport->streamRtf->WriteString("���������� �.");
				fmReport->streamRtf->WriteString("\\cell");
				fmReport->streamRtf->WriteString("���������� �.");
				fmReport->streamRtf->WriteString("\\cell\\row\n"); // ����� ������ ����������

			}
			else {
				if ((queryShowListTubes->RecNo - countRows1) % countRows2 == 0 && numPage > 1) {
					numPage++;
					fmReport->streamRtf->WriteString("\\par\n");
					fmReport->streamRtf->WriteString("\\pard\\widctlpar\\li-567\\sa200\\sl276\\slmult1\\par "); // ����� �������
					fmReport->streamRtf->WriteString("\\par\n");
					fmReport->streamRtf->WriteString("����� 9955 ������� ����� �������������� �������� ");
					fmReport->streamRtf->WriteString("\\par");
					fmReport->streamRtf->WriteString("\\pard\\widctlpar\\fi1275\\li-567\\sa200\\sl276\\slmult1\\fs24 \n");
					fmReport->streamRtf->WriteString("������: ");
					fmReport->streamRtf->WriteString(FormatDateTime("yyyy.mm.dd hh:mm", Now()));
					fmReport->streamRtf->WriteString("\\par\n");
					fmReport->streamRtf->WriteString("���������� ���� � ������: ");
					fmReport->streamRtf->WriteString(IntToStr(queryShowListTubes->RecordCount));
					fmReport->streamRtf->WriteString("\\par\n");
					fmReport->streamRtf->WriteString("\\trowd\\trgaph108\\trleft176\\trbrdrl\\brdrs\\brdrw10 \\trbrdrt\\brdrs\\brdrw10 \n");
					fmReport->streamRtf->WriteString
						("\\trbrdrr\\brdrs\\brdrw10 \\trbrdrb\\brdrs\\brdrw10 \\trpaddl108\\trpaddr108\\trpaddfl3\\trpaddfr3 \n");
					fmReport->streamRtf->WriteString
						("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs\n");
					fmReport->streamRtf->WriteString("\\cellx3119\n"); // 1 cell
					fmReport->streamRtf->WriteString
						("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
					fmReport->streamRtf->WriteString("\\cellx4253\n"); // 2 cell
					fmReport->streamRtf->WriteString
						("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
					fmReport->streamRtf->WriteString("\\cellx6096\n"); // 3 cell //4 cell //5 cell
					fmReport->streamRtf->WriteString
						("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
					fmReport->streamRtf->WriteString("\\cellx8222\n");
					fmReport->streamRtf->WriteString
						("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
					fmReport->streamRtf->WriteString("\\cellx10348\n");
					fmReport->streamRtf->WriteString("\\pard\\intbl\\widctlpar");
					fmReport->streamRtf->WriteString("���� � �����");
					fmReport->streamRtf->WriteString("\\cell");
					fmReport->streamRtf->WriteString("�����");
					fmReport->streamRtf->WriteString("\\cell");
					fmReport->streamRtf->WriteString("�. �������");
					fmReport->streamRtf->WriteString("\\cell");
					fmReport->streamRtf->WriteString("���������� �.");
					fmReport->streamRtf->WriteString("\\cell");
					fmReport->streamRtf->WriteString("���������� �.");
					fmReport->streamRtf->WriteString("\\cell\\row\n"); // ����� ������ ����������
				}
				else {
					//
				}
			}
			fmReport->streamRtf->WriteString("\\trowd\\trgaph108\\trleft176\\trbrdrl\\brdrs\\brdrw10 \\trbrdrt\\brdrs\\brdrw10 \n");
			fmReport->streamRtf->WriteString
				("\\trbrdrr\\brdrs\\brdrw10 \\trbrdrb\\brdrs\\brdrw10 \\trpaddl108\\trpaddr108\\trpaddfl3\\trpaddfr3 \n");
			fmReport->streamRtf->WriteString
				("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs\n");
			fmReport->streamRtf->WriteString("\\cellx3119\n"); // 1 cell
			fmReport->streamRtf->WriteString
				("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
			fmReport->streamRtf->WriteString("\\cellx4253\n"); // 2 cell
			fmReport->streamRtf->WriteString
				("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
			fmReport->streamRtf->WriteString("\\cellx6096\n"); // 3 cell //4 cell //5 cell
			fmReport->streamRtf->WriteString
				("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
			fmReport->streamRtf->WriteString("\\cellx8222\n");
			fmReport->streamRtf->WriteString
				("\\clbrdrl\\brdrw10\\brdrs\\clbrdrt\\brdrw10\\brdrs\\clbrdrr\\brdrw10\\brdrs\\clbrdrb\\brdrw10\\brdrs \n");
			fmReport->streamRtf->WriteString("\\cellx10348\n");
			fmReport->streamRtf->WriteString("\\pard\\intbl\\widctlpar");
			fmReport->streamRtf->WriteString(" " + FormatDateTime("yyyy.mm.dd hh:mm",
				queryShowListTubes->FieldByName("���� � ����� ��������")->AsDateTime));
			fmReport->streamRtf->WriteString("\\cell");
			fmReport->streamRtf->WriteString(" " + queryShowListTubes->FieldByName("����� �����")->AsString);
			fmReport->streamRtf->WriteString("\\cell");
			fmReport->streamRtf->WriteString(queryShowListTubes->FieldByName("�. �������")->AsString);
			fmReport->streamRtf->WriteString("\\cell");
			fmReport->streamRtf->WriteString(queryShowListTubes->FieldByName("���������� �.")->AsString);
			fmReport->streamRtf->WriteString("\\cell");
			fmReport->streamRtf->WriteString(queryShowListTubes->FieldByName("���������� �.")->AsString);
			fmReport->streamRtf->WriteString("\\cell\\row\n"); ; // ����� ������ 2
			// ----------------
			queryShowListTubes->Next();
		}
		fmReport->streamRtf->WriteString("\\pard\\widctlpar\\li-567\\sa200\\sl276\\slmult1\\par "); // ����� �������
		fmReport->streamRtf->WriteString("\\par\n");
		// --------------------
		fmReport->streamRtf->WriteString("}"); // �����������;
		// // --------------------------------
		// // --------------------------------------

		// // ---------------------------
		// while (!queryShowListTubes->Eof) {
		// strOut = "\t" + queryShowListTubes->FieldByName("����� �����")->AsString;
		// strOut += "\t\t" + queryShowListTubes->FieldByName("���� � ����� ��������")->AsString;
		// strOut += "\t\t" + queryShowListTubes->FieldByName("����� �����")->AsString;
		// strTmp = queryShowListTubes->FieldByName("����� �����")->AsString;
		// if (strTmp.Length() > 5) {
		// strOut += "\t\t" + queryShowListTubes->FieldByName("��������� ���1(T)")->AsString;
		// }else{
		// strOut += "\t\t\t" + queryShowListTubes->FieldByName("��������� ���1(T)")->AsString;
		// }
		// //fmReport->RichEdit->Lines->Add(strOut);
		// strTmp = queryShowListTubes->FieldByName("��������� ���1(T)")->AsString;
		// if (strTmp.Length() > 5) {
		// strOut += "\t\t\t" + queryShowListTubes->FieldByName("��������� ���2(C)")->AsString;
		// }
		// else {
		// strOut += "\t\t" + queryShowListTubes->FieldByName("��������� ���2(C)")->AsString;
		// }
		// //strOut += "\t\t" + queryShowListTubes->FieldByName("��������� ���2(C)")->AsString;
		// strTmp = queryShowListTubes->FieldByName("��������� ���2(C)")->AsString;
		// if (strTmp.Length() > 5) {
		// strOut += "\t\t\t" + queryShowListTubes->FieldByName("��������� ���3(L)")->AsString;
		// }
		// else {
		// strOut += "\t\t" + queryShowListTubes->FieldByName("��������� ���3(L)")->AsString;
		// }
		// //strOut += "\t\t" + queryShowListTubes->FieldByName("��������� ���3(L)")->AsString;
		// fmReport->RichEdit->Lines->Add(strOut);
		// // -----------------------
		// // strOut = "";
		// // fmReport->RichEdit->Lines->Add(strOut);
		// // fmReport->RichEdit->Lines->Add(strOut);
		// // -------------------------
		// queryShowListTubes->Next();
		// }
		// fmReport->streamRtf->WriteString(strOut);
		// RichEdit->Lines->SaveToStream(streamRtf);
		int L = fmReport->streamRtf->Position;
		fmReport->streamRtf->Seek((int)0, (Word)soBeginning);
		fmReport->streamRtf->SaveToFile("e:\\PRG\\BURAN-9955PaWork\\Help\\stream.rtf");
		L = fmReport->streamRtf->Position;
		// streamRtf->;
		fmReport->RichEdit->Clear();
		fmReport->RichEdit->Lines->LoadFromStream(fmReport->streamRtf);
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
//////////////

void __fastcall TfmShowListTubes::DBGridListTubesCellClick(TColumn *Column) {
	if (DBGridListTubes->SelectedRows->Count == 0) {
		menuShowZones->Enabled = true;
	}
	else {
		menuShowZones->Enabled = false;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfmShowListTubes::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift) {
	TShiftState shift;
	TMouseButton Button;
	if (Key == VK_ESCAPE) {
		fmShowListTubes->Close();
	}
	else {
		//
	}
	if (Key == VK_RETURN && queryShowListTubes->RecNo < queryShowListTubes->RecordCount && queryShowListTubes->RecNo > 0) {
		int t = queryShowListTubes->FieldByName("����� �����")->AsInteger;
		int f = queryShowListTubes->FieldByName("����� ������")->AsInteger;
		if (f == 0 || t == 0) {
			MessageDlg("������ �� ����� ���!", mtWarning, TMsgDlgButtons() << mbOK, NULL);
			return;
		}
		else {

		}
		ShowZones(Sender);
	}
	else {
		//
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfmShowListTubes::cbxBrackTClick(TObject *Sender) {
	// cbxBrackT->Checked = !cbxBrackT->Checked;
}
// ---------------------------------------------------------------------------

void __fastcall TfmShowListTubes::cbxBrackCClick(TObject *Sender) {
	// cbxBrackC->Checked = !cbxBrackC->Checked;
}
// ---------------------------------------------------------------------------

void __fastcall TfmShowListTubes::cbxBrackLClick(TObject *Sender) {
	// cbxBrackL->Checked = !cbxBrackL->Checked;
}

// ---------------------------------------------------------------------------
void __fastcall TfmShowListTubes::timerFilterTimer(TObject *Sender) {
	// timerFilter->Enabled = false;
	// bbtFilteredClick(bbtFiltered);
	// timerFilter->Enabled = true;
}

// ---------------------------------------------------------------------------
void __fastcall TfmShowListTubes::FormResize(TObject *Sender) {
	int err = 0;
	for (int i = 0; i < DBGridListTubes->Columns->Count; i++) {
		if (DBGridListTubes->Columns->Items[i]->Index > 15) {
			DBGridListTubes->Columns->Items[i]->Visible = false;
		}
		else {
			//
		}
	}
	countRows1 = SqlDBModule->GetIntFieldSQL("currentSettings", "ParamValueFloat",
		"isActual = 1 and UPPER(ParamName) = UPPER('countRows1')", 0, err);
	countRows2 = SqlDBModule->GetIntFieldSQL("currentSettings", "ParamValueFloat",
		"isActual = 1 and UPPER(ParamName) = UPPER('countRows2')", 0, err);
}

// ---------------------------------------------------------------------------
void __fastcall TfmShowListTubes::DBGridListTubesDblClick(TObject *Sender) {
	int t = queryShowListTubes->FieldByName("����� �����")->AsInteger;
	int f = queryShowListTubes->FieldByName("����� ������")->AsInteger;
	if (f == 0 || t == 0) {
		MessageDlg("������ �� ����� ���!", mtWarning, TMsgDlgButtons() << mbOK, NULL);
		return;
	}
	else {

	}
	ShowZones(Sender);
}
// ---------------------------------------------------------------------------

void __fastcall TfmShowListTubes::timerRefreshTimer(TObject *Sender) {
	timerRefresh->Enabled = false;
	if (numRec <= queryShowListTubes->RecordCount) {
		numRec = queryShowListTubes->RecNo;
	}
	else {
		numRec = 0;
	}
	bbtFilteredClick(bbtFiltered);
	queryShowListTubes->RecNo = numRec;
	timerRefresh->Enabled = true;
}
// ---------------------------------------------------------------------------

void __fastcall TfmShowListTubes::queryShowListTubesAfterOpen(TDataSet *DataSet) {
	for (int i = 0; i < DBGridListTubes->Columns->Count; i++) {
		if (DBGridListTubes->Columns->Items[i]->Index > 15) {
			DBGridListTubes->Columns->Items[i]->Visible = false;
		}
		else {
			//
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfmShowListTubes::FormCloseQuery(TObject *Sender, bool &CanClose) {
	int e = DBGridListTubes->Columns->Count;
	for (int i = 0; i < e; i++) {
		SqlDBModule->UpdIntSql("gridTubesColWidth", "colWidth", DBGridListTubes->Columns->Items[i]->Width, "colNum=" + IntToStr(i + 1));
	}
	queryShowTube->Close();
	queryShowListTubes->Close();
}
// ---------------------------------------------------------------------------

