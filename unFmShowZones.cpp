// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "unFmShowZones.h"
// ----------------------
#include "unSQLDbModule.h"
#include "unTUtils.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmShowZones *fmShowZones;

// ---------------------------------------------------------------------------

__fastcall TfmShowZones::TfmShowZones(TComponent* Owner,TADOQuery *_queryShowListTubes) : TForm(Owner) {

	// -----------------
  pQueryShowListTubes=_queryShowListTubes;
}

// { переводит координаты из мм в пиксели }
int GetYFromMM(int pixelsY, int _mmY) {
	int res = 0;
	res = int(pixelsY / 25.4 * _mmY);
	return res;
}

int GetXFromMM(int pixelsX, int _mmX) {
	int res = 0;
	res = int(pixelsX / 25.4 * _mmX);
	return res;
}

// ---------------------------------------------------------------------------
void __fastcall TfmShowZones::EcrossBorder10Exit(TObject *Sender) {
	TEdit* ed = (TEdit*)Sender;
	double ret = (double)StrToFloatDef(ed->Text, -1);
	if (ret < 0) {
		ed->SetFocus();
		return;
	}
	ed->Font->Color = clWindowText;
	ed->Font->Style = TFontStyles();
	SaveBorders();
}
// ---------------------------------------------------------------------------

void __fastcall TfmShowZones::EcrossBorder10KeyDown(TObject *Sender, WORD &Key, TShiftState Shift) {
	TEdit* ed = (TEdit*)Sender;
	if (Key == VK_RETURN) {
		double ret = (double)StrToFloatDef(ed->Text, -1);
		if (ret < 0) {
			ed->Font->Color = clHotLight;
			ed->Font->Style = TFontStyles() << fsBold;
			return;
		}
		ed->Font->Color = clWindowText;
		ed->Font->Style = TFontStyles();
		SaveBorders();
	}
	else {
		ed->Font->Color = clHotLight;
		ed->Font->Style = TFontStyles() << fsBold;
	}
}

// ---------------------------------------------------------------------------
void TfmShowZones::SaveBorders() {
	// зафикируем значения границ

}

void __fastcall TfmShowZones::ChartCrossClickSeries(TCustomChart *Sender, TChartSeries *Series, int ValueIndex, TMouseButton Button,
	TShiftState Shift, int X, int Y) {
	int zoneNum = ValueIndex;
	int sensorNum = Series->SeriesIndex;
	double valZone = 0;
	TChart* pChart = static_cast<TChart*>(Sender);
	TChartSeries *pSeries0 = pChart->Series[0];
	pSeries0->Clear();

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
	AnsiString tmpStr = "";
	// Series->ValueColor[ValueIndex] = clBlue;
	// fmMain->workX502.workData->ResetAllData(msgLast);
	// MessageDlg("Выбрана зона: " + IntToStr(ValueIndex) + " Значение:" + FloatToStr(valZone), mtInformation,
	// TMsgDlgButtons() << mbOK, NULL);
	// MessageDlg("Выбрана зона: "+IntToStr(ValueIndex), mtInformation, TMsgDlgButtons() << mbOK, NULL);
	pChart->Title->Clear();
	pChart->Title->Text->Add("ПОПЕРЕЧНЫЙ КОНТРОЛЬ(МНК2)");
	tmpStr = " Зона: " + IntToStr(ValueIndex) + " (";
	tmpStr += IntToStr((ValueIndex - 1) * 100);
	tmpStr += " - ";
	tmpStr += IntToStr(ValueIndex * 100) + " мм)";
	tmpStr += " Макс сигнал=";
	if(!dataCross.empty())
	{
	if (dataCross[selectZoneC] < 0) {
		tmpStr += "XXX";
	}
	else {
		tmpStr += FloatToStrF(dataCross[selectZoneC], ffFixed, 4, 1) + "%";
	}
	}
	colorMark = clFuchsia;
	if (selectZoneC > 0 && selectZoneC < countZones) {
		// ChartCross->Series[selectSensor]->ValueColor[selectZone] = colorMark
		if (isZoneMarkedC) {
			pSeries0->ValueColor[oldSelectZoneC] = oldColorC0;
			// ----------
		}
		else {
			oldColorC0 = pSeries0->ValueColor[selectZoneC];
			if (oldColorC0 == 0) {
				oldColorC0 = clGreen;
			}
			else {

			}
			pSeries0->ValueColor[selectZoneC] = oldColorC0;
			isZoneMarkedC = true;
		}
		oldColorC0 = pSeries0->ValueColor[selectZoneC];
		// oldColor1 = pSeries1->ValueColor[selectZone];
		oldSelectZoneC = selectZoneC;
		pSeries0->ValueColor[selectZoneC] = colorMark;
		// ------------
	}
	pChart->Title->Text->Add(tmpStr);

}

int TfmShowZones::ShowZoneData(int _zone, int _sensor) {
	int err = 0;
	// serg
	try {

		// // PrepareZoneToShow(TWorkX502* _vzWorkX502, int _moduleType, int _selZone, int _selSensor,AnsiString _title);
		// int res = pFmViewZone->PrepareZoneToShow(crossWorkX502, 2, _zone, realSensorNum, "Показ зоны: " + IntToStr(_zone + 1) + " датчик: " + IntToStr(_sensor + 1));
		// if (res < 0) {
		// MessageDlg("Детализация отсутствует или некорректна!!!\n Просмотр невозможен!", mtError, TMsgDlgButtons() << mbOK, NULL);
		// }
		// else {
		fmViewZone = new TfmViewZone(NULL);
		fmViewZone->ShowModal();
		delete fmViewZone;
		// //закрылась форма с просмотром
		// PostMessage(Application->Handle, WM_USER + 500, 33, 0);
		// }
		// return 0;
		// }
		// __finally {
		// MarkerOff();
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
void TfmShowZones::MarkerSet(int _zone, int _sensor) {
	MarkerOff();
	// serg
	// int s = ChartCross->SeriesCount();
	// if (_sensor < 0 || _sensor >= ChartCross->SeriesCount())
	// return;
	// int z = ChartCross->Series[_sensor]->Count();
	// if (_zone < 0 || _zone >= ChartCross->Series[_sensor]->Count())
	// return;
	// selectZone = _zone;
	// selectSensor = _sensor;
	// colorMark = chartCross->Series[_sensor]->ValueColor[_zone];
	// isZoneMarked = true;
	// chartCross->Series[_sensor]->ValueColor[_zone] = clBlue;
}

void TfmShowZones::MarkerOff(void) {
	// serg
	// if (!isZoneMarked)
	// return;
	// isZoneMarked = false;
	// // if (ChartCross->Series[selectSensor]->Count() > selectZone)
	// // ChartCross->Series[selectSensor]->ValueColor[selectZone] = colorMark;
}

void __fastcall TfmShowZones::SplitterTopMoved(TObject *Sender) {
	// PanelCross->Height = SplitterTop->Top;
	// PanelLong->Height = SplitterTop->Top + SplitterTop->Height;
}
// ---------------------------------------------------------------------------

void __fastcall TfmShowZones::FormCreate(TObject *Sender) {
	PanelLong->Align = alNone;
	scale = 20.0;
	memoBrack->Clear();
}
// ---------------------------------------------------------------------------

void __fastcall TfmShowZones::FormClose(TObject *Sender, TCloseAction &Action) {
	int err = 0;
	AnsiString strTmp = "";
	AnsiString strWhere = "";
	try {
		SqlDBModule->UpdIntSql("currentSettings", "ParamValueFloat", PanelThick->Height,
			"isActual=1 and UPPER(ParamName)=UPPER('PanelThickHeight')");
		SqlDBModule->UpdIntSql("currentSettings", "ParamValueFloat", PanelLong->Height,
			"isActual=1 and UPPER(ParamName)=UPPER('PanelLongHeight')");
		// -----------
		for (int i = 0; i < dbGridTitle1->Columns->Count; i++) {
			// GetStrFieldSQL(AnsiString _tableName, AnsiString _fieldName, AnsiString _where, AnsiString _default, int &err)
			strTmp = SqlDBModule->GetStrFieldSQL("currentSettings", "ParamValueFloat",
				"isActual=1 and UPPER(ParamName)=UPPER('dbGridTitleCol1" + IntToStr(i) + "')", "", err);
			if (strTmp == "") {
				strTmp = "INSERT INTO dbo.currentSettings(isActual,RusName,ParamName,ParamValueFloat,ParamValueStr)";
				strTmp += "VALUES(1";
				// strTmp+=":pRusName";
				// strTmp+=":pParamName";
				// strTmp+=":pParamValueFloat";
				// strTmp+=":pParamValueStr";
				strTmp += ",'Ширина колонки dbGridTitleCol1'";
				strTmp += ",'dbGridTitleCol1";
				strTmp += IntToStr(i);
				strTmp += "',";
				int w = dbGridTitle1->Columns->Items[i]->Width;
				strTmp += IntToStr(w);
				strTmp += ",'')";
				SqlDBModule->ExecStrSql(strTmp);
			}
			else {
				int w = dbGridTitle1->Columns->Items[i]->Width;
				SqlDBModule->UpdIntSql("currentSettings", "ParamValueFloat", w, "isActual=1 and UPPER(ParamName)=UPPER('dbGridTitleCol1" +
					IntToStr(i) + "')");
			}
		}
		for (int i = 0; i < dbGridTitle2->Columns->Count; i++) {
			// GetStrFieldSQL(AnsiString _tableName, AnsiString _fieldName, AnsiString _where, AnsiString _default, int &err)
			strTmp = SqlDBModule->GetStrFieldSQL("currentSettings", "ParamValueFloat",
				"isActual=1 and UPPER(ParamName)=UPPER('dbGridTitleCol2" + IntToStr(i) + "')", "", err);
			if (strTmp == "") {
				strTmp = "INSERT INTO dbo.currentSettings(isActual,RusName,ParamName,ParamValueFloat,ParamValueStr)";
				strTmp += "VALUES(1";
				// strTmp+=":pRusName";
				// strTmp+=":pParamName";
				// strTmp+=":pParamValueFloat";
				// strTmp+=":pParamValueStr";
				strTmp += ",'Ширина колонки dbGridTitleCol2'";
				strTmp += ",'dbGridTitleCol2";
				strTmp += IntToStr(i);
				strTmp += "',";
				int w = dbGridTitle2->Columns->Items[i]->Width;
				strTmp += IntToStr(w);
				strTmp += ",'')";
				SqlDBModule->ExecStrSql(strTmp);
			}
			else {
				int w = dbGridTitle1->Columns->Items[i]->Width;
				SqlDBModule->UpdIntSql("currentSettings", "ParamValueFloat", w, "isActual=1 and UPPER(ParamName)=UPPER('dbGridTitleCol2" +
					IntToStr(i) + "')");
			}
		}
		// ---------
		dataLong.clear();
		dataCross.clear();
		for (int i = 0; i < dataThickMax.size(); i++) {
			dataThickMax[i].clear();
		}
		dataThickMax.clear();
		// -----------------------------
		for (int i = 0; i < dataThickMin.size(); i++) {
			dataThickMin[i].clear();
		}
		dataThickMin.clear();
		// currentZone = 1;
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
void __fastcall TfmShowZones::SplitterMidMoved(TObject *Sender) {
	// PanelLong->Height = SplitterMid->Top;
	// PanelThick->Height = SplitterMid->Top + SplitterMid->Height;
}

// ---------------------------------------------------------------------------
void __fastcall TfmShowZones::bbtPrintClick(TObject *Sender) {
	printer = Printer();
	// PrintResult(printer, poPortrait, 20, 10);
	// PrintResult2(printer, poPortrait, 20, 10);
	// PrintResult2(printer, poLandscape, 20, 10);
}

int TfmShowZones::PrintResult2(TPrinter* _printer, TPrinterOrientation _orientation, int _beginPrinterXPmm, int _beginPrinterYPmm) {
	int err = 0;
	AnsiString strOut;
	TPoint curPos;
	int mmx, mmy;
	int mode = 0;
	int szStep = 0;
	int szFont = 0;
	int numPage = 0;
	try {

		if (PrintDialog->Execute()) {
			// fmShowZones->Print();
			_printer->Title = "Буран 9955 Протокол Общего результата контроля";
			_printer->BeginDoc();
			mmx = GetDeviceCaps(_printer->Canvas->Handle, PHYSICALWIDTH) / GetDeviceCaps(_printer->Canvas->Handle, LOGPIXELSX) * 25.4;
			mmy = GetDeviceCaps(_printer->Canvas->Handle, PHYSICALHEIGHT) / GetDeviceCaps(_printer->Canvas->Handle, LOGPIXELSY) * 25.4;
			// проверка на установку режима, должен быть
			mode = GetMapMode(_printer->Canvas->Handle);
			// высота строки в пикселах
			_printer->Canvas->Font->Size = 10;
			szFont = _printer->Canvas->Font->Size;
			strOut = "Буран 9955 Протокол неразрушающего контроля от: " + FormatDateTime("yyyy.mm.dd hh:mm", Now());
			_printer->Canvas->TextOutW(25*_beginPrinterXPmm, szFont*1*_beginPrinterYPmm, strOut);
			// положение зависит от установленного dpi принтера
			// ----------------
			// strOut = "Параметры контроля:";
			// _printer->Canvas->TextOutW(25*_beginPrinterXPmm, szStep*2*_beginPrinterYPmm, strOut);
			// strOut = " Номинальная толщина:" + FloatToStr(nominalThick) + " мм";
			// strOut += "МНК1 Верхний порог по толщине:" + FloatToStr(valBorderMax) + " мм";
			// strOut += "МНК1 Нижний порог по толщине:" + FloatToStr(valBorderMin) + " мм";
			// _printer->Canvas->TextOutW(25*_beginPrinterXPmm, szStep*3*_beginPrinterYPmm, strOut);
			// strOut = " Пороги по поперечным дефектам:" + FloatToStr(nominalThick) + " мм";
			// strOut += "МНК2 Верхний порог:" + FloatToStr(valBborderС1) + "%";
			// strOut += "МНК2 Нижний порог:" + FloatToStr(valBborderС2) + "%";
			// strOut = " Пороги по продольным дефектам:" + FloatToStr(nominalThick) + " мм";
			// strOut += "МНК3 Верхний порог:" + FloatToStr(valBborderL1) + "%";
			// strOut += "МНК3 Нижний порог:" + FloatToStr(valBborderL2) + "%";
			// _printer->Canvas->TextOutW(25*_beginPrinterXPmm, szStep*4*_beginPrinterYPmm, strOut);

			// _printer->Canvas->TextOut(150**_beginPrinterXPmm, 500*_beginPrinterYPmm, strOut);
			SetStretchBltMode(_printer->Canvas->Handle, HALFTONE);
			// будем считать, что у нас всегда формат А4
			curPos = printer->Canvas->PenPos;
			// каждая mmx*1 сдвиг на 2 см
			double hPict = 14 * mmy;
			err = StretchBlt(printer->Canvas->Handle, // дескриптор приемного DC
				25 * _beginPrinterXPmm, // x-коорд. верхнего левого угла приёмника
				curPos.Y + 6 * szFont * 2, // y-коорд. верхнего левого угла приёмника
				21 * mmx, // ширина приёмного прямоугольника
				hPict, // высота приёмного прямоугольника.
				fmShowZones->Canvas->Handle, // дескриптор исходного DC
				0, // x-коорд.верхнего левого угла источника
				0, // y-коорд.верхнего левого угла источника
				fmShowZones->Width, // ширина исходного прямоугольника
				fmShowZones->Height, // высота исходного прямоугольника
				SRCCOPY); // код растровой операции
			curPos = printer->Canvas->PenPos;
			szStep = 150;
			int curPosY = hPict + szStep;
			numPage = 1;
			if (memoBrack->Lines->Count > 0) {

				_printer->NewPage();
				strOut = "Буран 9955 Протокол неразрушающего контроля от: " + FormatDateTime("yyyy.mm.dd hh:mm", Now());
				_printer->Canvas->TextOutW(25*_beginPrinterXPmm, _printer->Canvas->Font->Size*1*_beginPrinterYPmm, strOut);
				curPosY = _printer->Canvas->Font->Size * 1 * _beginPrinterYPmm + szStep;
				numPage++;
				for (int i = 0; i < memoBrack->Lines->Count; i++) {
					// for (int i = 0; i < 80; i++) {
					strOut = memoBrack->Lines->Strings[i];
					// strOut = IntToStr(i + 1) + memoBrack->Lines->Strings[0];
					curPosY += szStep;
					_printer->Canvas->TextOutW(25*_beginPrinterXPmm, curPosY, strOut);
					if (i != 0 && i % 44 == 0 && numPage > 1) {
						_printer->NewPage();
						strOut = "Буран 9955 Протокол неразрушающего контроля от: " + FormatDateTime("yyyy.mm.dd hh:mm", Now());
						_printer->Canvas->TextOutW(25*_beginPrinterXPmm, _printer->Canvas->Font->Size*1*_beginPrinterYPmm, strOut);
						curPosY = _printer->Canvas->Font->Size * 1 * _beginPrinterYPmm + szStep;
						numPage++;
					}
					else {

					}
					// _printer->Canvas->TextOutW(25*_beginPrinterXPmm, curPosY+szStep*(i+1)*10, strOut);
				}
			}
			else {
				//
			}
			_printer->EndDoc();
			if (err == 0) {
				MessageDlg("Ошибка растрирования!", mtError, TMsgDlgButtons() << mbOK, NULL);
				err = -2;
			}
			else {
				err = 0;
			}
		}
		else {

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

int TfmShowZones::PrintResult(TPrinter* _printer, TPrinterOrientation _orientation, int _beginPrinterXPmm, int _beginPrinterYPmm) {
	int err = 0;
	int resPrinterY;
	int resPrinterX;
	int beginPrinterX = _beginPrinterXPmm * 10;
	int beginPrinterY = _beginPrinterYPmm * 10;
	div_t scaleY;
	div_t scaleX;
	AnsiString strOut;
	TPoint curPos;
	int m = 0;
	int dd = 10;
	int beginText;
	int mmx, mmy, vertSize, HorzSize;
	try {
		if (PrintDialog->Execute()) {
			_printer->Title = "Протокол Общего результата контроля";
			_printer->BeginDoc();
			// serg
			// SetMapMode(_printer->Canvas->Handle, MM_TEXT);
			// m = GetMapMode(_printer->Canvas->Handle);
			// в этом режиме лог пиксел=0,1 мм, отчет по осям идет вправо и вверх
			SetMapMode(_printer->Canvas->Handle, MM_LOMETRIC);
			mmx = GetDeviceCaps(_printer->Canvas->Handle, PHYSICALWIDTH) / GetDeviceCaps(_printer->Canvas->Handle, LOGPIXELSX) * 25.4;
			// точек на мм
			mmy = GetDeviceCaps(_printer->Canvas->Handle, PHYSICALHEIGHT) / GetDeviceCaps(_printer->Canvas->Handle, LOGPIXELSY) * 25.4;
			// размер печатного поля в 0,1 мм
			vertSize = (int)(mmy) * 10; // в 0,1 мм
			HorzSize = (int)(mmx) * 10;
			// проверка на установку режима, должен быть 2
			m = GetMapMode(_printer->Canvas->Handle);
			// высота строки в мм
			_printer->Canvas->Font->Size = 5;
			// { Получить информацию о принтере }
			resPrinterX = GetDeviceCaps(_printer->Canvas->Handle, LOGPIXELSX);
			resPrinterY = GetDeviceCaps(_printer->Canvas->Handle, LOGPIXELSY);
			// вернем цвет пера и кисти
			printer->Canvas->Pen->Color = clBlack;
			printer->Canvas->Brush->Color = clWhite;
			// сдвинем перо
			printer->Canvas->MoveTo(beginPrinterX + 450, -beginPrinterY);
			curPos = printer->Canvas->PenPos;
			// -----------
			strOut = "Протокол неразрушающего контроля от: " + FormatDateTime("yyyy.mm.dd hh:mm", Now());
			_printer->Canvas->TextOut(beginPrinterX + 450, printer->Canvas->PenPos.Y, strOut);
			// --------1-1
			beginText = beginPrinterX + 50;
			// SRCCOPY обеспечивает нормальное копирование, SRCINVERT конвертирует пиксели источника и приемника при помощи операнда ИЛИ, SRCAND связывает пиксели при помощи операнда И.
			SetStretchBltMode(_printer->Canvas->Handle, HALFTONE);
			// будем считать, что у нас всегда формат А4
			// StretchBlt(printer->Canvas->Handle, beginPrinterX, (int)(printer->Canvas->PenPos.Y - (hStr + hInterStr)),
			// (int)iconW / 10, -iconH, fmShowZones->Canvas->Handle, 0, 0, fmShowZones->Width, fmShowZones->Height,SRCCOPY);
			// ------------
			curPos = printer->Canvas->PenPos;
			err = StretchBlt(printer->Canvas->Handle, // дескриптор приемного DC
				beginPrinterX, // x-коорд. верхнего левого угла приёмника
				curPos.Y, // y-коорд. верхнего левого угла приёмника
				HorzSize, // ширина приёмного прямоугольника
				vertSize, // высота приёмного прямоугольника.
				fmShowZones->Canvas->Handle, // дескриптор исходного DC
				0, // x-коорд.верхнего левого угла источника
				0, // y-коорд.верхнего левого угла источника
				fmShowZones->Width, // ширина исходного прямоугольника
				fmShowZones->Height, // высота исходного прямоугольника
				SRCCOPY); // код растровой операции
			_printer->EndDoc();
			if (err == 0) {
				MessageDlg("Ошибка растрирования!", mtError, TMsgDlgButtons() << mbOK, NULL);
			}
			else {
				//
			}
		}
		else {
			//
		}
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
	// -------------------
}

// ---------------------------------------------------------------------------

// ----------
int TfmShowZones::PrintImage(TImage* _image, AnsiString _filename, TPrinter* _printer, TPrinterOrientation _orientation,
	int _beginPrinterXmm, int _beginPrinterYmm, int _widgthIcon, int _heightIcon, bool _isPrinting) {
	int err = 0;
	double widgthMm = 0;
	double heigtMm = 0;
	TPoint curPos;
	int beginPrinterX = _beginPrinterXmm * 10;
	int beginPrinterY = _beginPrinterYmm * 10;
	try {
		if (_filename != NULL) {
			_image->Picture->LoadFromFile(_filename);
		}
		else {
			//
		}
		if (_isPrinting) {
			_printer->BeginDoc();
			_printer->Orientation = _orientation;
		}
		else {
			//
		}
		SetMapMode(_printer->Canvas->Handle, MM_LOMETRIC);
		SetStretchBltMode(printer->Canvas->Handle, HALFTONE);
		_printer->Canvas->Pen->Width = 3;
		_printer->Canvas->Pen->Color = clBlue;
		_printer->Canvas->Brush->Color = clWhite;
		curPos = _printer->Canvas->PenPos;
		_printer->Canvas->FrameRect(Rect(500, -600, 1000, -1000));
		// вторая пара правый нижний угол
		_printer->Canvas->Rectangle(Rect(beginPrinterX, -beginPrinterY, beginPrinterX + _widgthIcon, -(_heightIcon + beginPrinterY)));
		// а тут начала, длина и ширина
		StretchBlt(_printer->Canvas->Handle, beginPrinterX, -beginPrinterY, _widgthIcon, -_heightIcon, fmShowZones->Canvas->Handle,
			_image->Left, _image->Top, _image->Width, _image->Height, SRCCOPY);
		if (_isPrinting) {
			_printer->EndDoc();
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
	return err;
}

void __fastcall TfmShowZones::strGridCrossDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect, TGridDrawState State) {
	TStringGrid* grid = static_cast<TStringGrid*>(Sender);
	int err = 0;
	double val = 0;
	try {
		if (ACol > 0 && ARow > 0) {
			AnsiString aStr = grid->Cells[ACol][ARow];
			// function TryStrToFloat(const S: string; out Value: Extended; const AFormatSettings: TFormatSettings): Boolean;
			if (TryStrToFloat(grid->Cells[ACol][ARow], val)) {
				//
			}
			else {
				val = -1;
			}
			if (val > TGlSettings::thresholdC1) {
				grid->Canvas->Brush->Color = clRed;
			}
			else {
				grid->Canvas->Brush->Color = clMoneyGreen;
			}
			if (val == -1) {
				grid->Canvas->Brush->Color = clWhite;
			}
			else {
				//
			}
			grid->Canvas->FillRect(Rect);
			grid->Canvas->TextOut(Rect.Left, Rect.Top, grid->Cells[ACol][ARow]);
		}
		else {
			//
		}

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
void __fastcall TfmShowZones::ApplicationEventsMessage(tagMSG &Msg, bool &Handled) {
	if (Msg.message == TGlSettings::msgFmViewZone) {
		// isZoneMarked=false;
		if (Msg.message == TGlSettings::msgFmViewZone) // идентификатор наш
		{
			// WinExec(" hh. .\\. .\\ help \\ Help.chm ", SW_RESTORE);
			// strGridCrossSelectCell(strGridCross, selACol, selARow, canSelect);
			Handled = true;

		}
		else {
			//
		}
	}
	else {
		//
	}

}

// ---------------------------------------------------------------------------
void __fastcall TfmShowZones::FormShow(TObject *Sender) {
	int err = 0;
	try {
		// stringGridTop->Align = alClient;
		// stringGridTop->ColCount = 11;
		// stringGridTop->RowCount = 2;
		// stringGridTop->DefaultRowHeight = (int)stringGridTop->Height / stringGridTop->RowCount;
		// stringGridTop->DefaultColWidth = (int)stringGridTop->Width / stringGridTop->ColCount * 1.3;
		// stringGridTop->ColWidths[1]-> = (int)stringGridTop->Width / stringGridTop->ColCount * 1.2;
		// stringGridTop->Columns->Items[1]->Width=80;
		// serg
		// TGlSettings::thresholdTNom=6.0;
		// ------------

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

int TfmShowZones::GetDataCross(int _numFusion, int _numTube) {
	AnsiString strSql = "";
	int err = 0;
	int itmp = 0;
	std::vector<double>::iterator result;
	int indMax;
	AnsiString strTmp = "";
	int countNulls = 0;
	AnsiString strWhere;
	int countBrak = 0;
    vector<vector<double> >sensorsDataCross;
	try {
		strWhere = "numFusion=" + IntToStr(_numFusion);
		strWhere += " and ";
		strWhere += " numTube= " + IntToStr(_numTube);
		// пороги
		strSql = "SELECT thresholdC1, thresholdC2";
		strSql += " FROM resultTubeShort where numTube>0 and numTube=:pnumTube and numFusion=:pnumFusion order by numFusion,numTube";
		SqlDBModule->queryForChart->Close();
		SqlDBModule->queryForChart->SQL->Text = strSql;
		SqlDBModule->queryForChart->Parameters->ParamByName("pnumTube")->Value = _numTube;
		SqlDBModule->queryForChart->Parameters->ParamByName("pnumFusion")->Value = _numFusion;
		SqlDBModule->queryForChart->Open();
		valBborderC1 = SqlDBModule->queryForChart->FieldByName("thresholdC1")->AsFloat;
		valBborderC2 = SqlDBModule->queryForChart->FieldByName("thresholdC2")->AsFloat;
		// --------------
		strSql = "SELECT numFusion, numTube";
		for (int i = 0; i < TGlSettings::countZones; i++) {
			strSql += ",Z" + IntToStr(i + 1);
		}
		strSql += ",sensorNum";
		strSql += " FROM resultCross where numTube=:pnumTube and numFusion=:pnumFusion order by numFusion,numTube,sensorNum";
		// по зонам поперечник
		SqlDBModule->queryForChart->Close();
		SqlDBModule->queryForChart->SQL->Text = strSql;
		SqlDBModule->queryForChart->Parameters->ParamByName("pnumTube")->Value = _numTube;
		SqlDBModule->queryForChart->Parameters->ParamByName("pnumFusion")->Value = _numFusion;
		SqlDBModule->queryForChart->Open();

		// подготовим вектор
		for (int i = 0; i < sensorsDataCross.size(); i++) {
			sensorsDataCross[i].clear();
		}

        //-------------------------
		sensorsDataCross.clear();
        dataCross.clear();
		vecMaxCh.clear();
		for (int i = 0; i < TGlSettings::countSensorsCross; i++) {
			vecMaxCh.push_back(0);
		}
        if (SqlDBModule->queryForChart->RecordCount == 0) {
		   //	MessageDlg("Данных по дефектам МНК2 нет!", mtWarning, TMsgDlgButtons() << mbOK, NULL);
			//chartCross->Title->Text->Add("Данных по дефектам МНК2(C) нет!");
			err = 0;
            chartCross->Series[0]->Clear();
		chartCross->Series[1]->Clear();
		chartCross->Series[2]->Clear();
			return err;
		}
		// заберем данные по поперечнику
		SqlDBModule->queryForChart->First();
		// while (!SqlDBModule->queryForChart->Eof) {
		itmp = TGlSettings::countSensorsCross;
		for (int i = 0; i < TGlSettings::countSensorsCross; i++) {
			vector<double>vecTmp;
			for (int z = 0; z < TGlSettings::countZones; z++) {
				double val = 0;
				AnsiString fn = "Z" + IntToStr(z + 1);
				AnsiString strTmp = SqlDBModule->queryForChart->FieldByName("Z" + IntToStr(i + 1))->AsString;
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
			if (dataCross[i] > 0) {
				if (dataCross[i] > valBborderC1 && valBborderC1 > 0) {
					chartCross->Series[0]->Add(dataCross[i], "", clRed);
					// Ahsistring strWhere=
					strTmp = "ДЕФЕКТ МНК2 ";
					countBrak++;
					strTmp += " Зона: " + IntToStr(i) + " (";
					int ss = i * 100 - 100;
					strTmp += IntToStr(i * 100 - 100);
					strTmp += " - ";
					strTmp += IntToStr((i + 1) * 100 - 100) + " мм)";
					strTmp += " Предел: ";
					strTmp += FloatToStr(valBborderC1);
					strTmp += "%";
					strTmp += " Значение: ";
					strTmp += FloatToStr(dataCross[i]);
					strTmp += "%";
					memoBrack->Lines->Add(strTmp);
				}
				else {
					if (dataCross[i] > valBborderC2 && valBborderC2 > 0) {
						chartCross->Series[0]->Add(dataCross[i], "", clYellow);
						countBrak++;
						strTmp = "ДЕФЕКТ МНК2 ";
						memoBrack->Lines->Add(strTmp);
						int ss = i * 100 - 100;
						strTmp += IntToStr(i * 100 - 100);
						strTmp += " - ";
						strTmp += IntToStr((i + 1) * 100 - 100) + " мм)";
						strTmp += " Предел: ";
						strTmp += FloatToStr(valBborderC2);
						strTmp += "%";
						strTmp += " Значение: ";
						strTmp += "%";
						strTmp += FloatToStr(dataCross[i]);
						strTmp += "%";
						memoBrack->Lines->Add(strTmp);
					}
					else {
						chartCross->Series[0]->Add(dataCross[i], "", clGreen);
					}
				}
			}
			else {
				chartCross->Series[0]->Add(0, "", clBlack);
			}
			chartCross->Series[1]->Add(valBborderC1, "", clRed);
			chartCross->Series[2]->Add(valBborderC2, "", clYellow);
		}
		int aa = countBrak;
		if (countNulls == TGlSettings::countZones * TGlSettings::countSensorsCross) {
		  //	chartCross->Title->Text->Add("Данных по дефектам МНК2 нет!");
			chartCross->Series[0]->Clear();
			chartCross->Series[1]->Clear();
			chartCross->Series[2]->Clear();
			chartCross->BottomAxis->Maximum = TGlSettings::countZones;
			err = 3;
			SqlDBModule->UpdIntSql("resultTubeShort", "resultC", -1, strWhere);
			// return err;
		}
		else {
			SqlDBModule->UpdIntSql("resultTubeShort", "resultC", countBrak, strWhere);
		}

		for (int i = 0; i < sensorsDataCross.size(); i++) {
			sensorsDataCross[i].clear();
		}
		sensorsDataCross.clear();
		err = 0;
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

int TfmShowZones::GetDataLong(int _numFusion, int _numTube) {
	AnsiString strSql = "";
	AnsiString strTmp = "";
	int err = 0;
	int itmp = 0;
	int countNulls = 0;
	std::vector<double>::iterator result;
	int indMax;
	AnsiString strWhere;
	int countBrak = 0;
    vector<vector<double> >sensorsDataLong;
	try {
		strWhere = "numFusion=" + IntToStr(_numFusion);
		strWhere += " and ";
		strWhere += " numTube= " + IntToStr(_numTube);
		// пороги
		strSql = "SELECT thresholdL1, thresholdL2";
		strSql += " FROM resultTubeShort where numTube>0 and numTube=:pnumTube and numFusion=:pnumFusion order by numFusion,numTube";
		SqlDBModule->queryForChart->Close();
		SqlDBModule->queryForChart->SQL->Text = strSql;
		SqlDBModule->queryForChart->Parameters->ParamByName("pnumTube")->Value = _numTube;
		SqlDBModule->queryForChart->Parameters->ParamByName("pnumFusion")->Value = _numFusion;
		SqlDBModule->queryForChart->Open();
		valBborderL1 = SqlDBModule->queryForChart->FieldByName("thresholdL1")->AsFloat;
		valBborderL2 = SqlDBModule->queryForChart->FieldByName("thresholdL2")->AsFloat;
		SqlDBModule->queryForChart->Close();
		strSql = "SELECT numFusion, numTube";
		for (int i = 0; i < TGlSettings::countZones; i++) {
			strSql += ",Z" + IntToStr(i + 1);
		}
		strSql += ",sensorNum";
		strSql += " FROM resultLong where numTube=:pnumTube and numFusion=:pnumFusion order by numFusion,numTube,sensorNum";
		SqlDBModule->queryForChart->SQL->Text = strSql;
		SqlDBModule->queryForChart->Parameters->ParamByName("pnumTube")->Value = _numTube;
		SqlDBModule->queryForChart->Parameters->ParamByName("pnumFusion")->Value = _numFusion;
		SqlDBModule->queryForChart->Open();

		SqlDBModule->queryForChart->First();
		// подготовим вектор
		for (int i = 0; i < sensorsDataLong.size(); i++) {
			sensorsDataLong[i].clear();
		}
		sensorsDataLong.clear();
		//----------
        dataLong.clear();
        //---------------------------
		vecMaxCh.clear();
		for (int i = 0; i < TGlSettings::countSensorsLong; i++) {
			vecMaxCh.push_back(0);
		}
        if (SqlDBModule->queryForChart->RecordCount == 0) {
		 //	MessageDlg("Данных по МНК3 нет!", mtWarning, TMsgDlgButtons() << mbOK, NULL);
		   //	chartCross->Title->Text->Add("Данных по дефектам МНК3 нет!");
           chartLong->Series[0]->Clear();
		chartLong->Series[1]->Clear();
		chartLong->Series[2]->Clear();
			return 0;
		}
		// заберем данные по продольнику
		SqlDBModule->queryForChart->First();
		// while (!SqlDBModule->queryForChart->Eof) {
		itmp = TGlSettings::countSensorsLong;
		for (int i = 0; i < TGlSettings::countSensorsLong; i++) {
			vector<double>vecTmp;
			for (int z = 0; z < TGlSettings::countZones; z++) {
				double val = 0;
				AnsiString fn = "Z" + IntToStr(z + 1);
				strTmp = SqlDBModule->queryForChart->FieldByName("Z" + IntToStr(i + 1))->AsString;
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
			if (dataLong[i] > 0) {

				if (dataLong[i] > valBborderL1 && valBborderL1 > 0) {
					chartLong->Series[0]->Add(dataLong[i], "", clRed);
					countBrak++;
					strTmp = "ДЕФЕКТ МНК3";
					// memoBrack->Lines->Add(strTmp);
					strTmp = " Зона: " + IntToStr(i) + " (";
					int ss = i * 100 - 100;
					strTmp += IntToStr(i * 100 - 100);
					strTmp += " - ";
					strTmp += IntToStr((i + 1) * 100 - 100) + " мм)";
					strTmp += " Предел: ";
					strTmp += FloatToStr(valBborderL1);
					strTmp += "%";
					strTmp += " Значение: ";
					strTmp += FloatToStr(dataLong[i]);
					strTmp += "%";
					memoBrack->Lines->Add(strTmp);
				}
				else {
					if (dataLong[i] > valBborderL2 && valBborderL2 > 0) {
						chartLong->Series[0]->Add(dataLong[i], "", clYellow);
						countBrak++;
						strTmp = "ДЕФЕКТ МНК3 ";
						// memoBrack->Lines->Add(strTmp);
						strTmp += " Зона: " + IntToStr(i) + " (";
						int ss = i * 100 - 100;
						strTmp += IntToStr(i * 100 - 100);
						strTmp += " - ";
						strTmp += IntToStr((i + 1) * 100 - 100) + " мм)";
						strTmp += " Предел: ";
						strTmp += FloatToStr(valBborderL2);
						strTmp += "%";
						strTmp += " Значение: ";
						strTmp += FloatToStr(dataLong[i]);
						strTmp += "%";
						memoBrack->Lines->Add(strTmp);
					}
					else {
						chartLong->Series[0]->Add(dataLong[i], "", clGreen);
					}
				}
			}
			else {
				chartLong->Series[0]->Add(0, "", clBlack);
			}
			itmp = valBborderL2;
			chartLong->Series[1]->Add(valBborderL1, "", clRed);
			chartLong->Series[2]->Add(valBborderL2, "", clYellow);
		}
		int aa = countBrak;
		err = 0;
		if (countNulls == TGlSettings::countZones * TGlSettings::countSensorsLong) {
		  //	chartLong->Title->Text->Add("Данных по дефектам МНК3 нет!");
			chartLong->Series[0]->Clear();
			chartLong->Series[1]->Clear();
			chartLong->Series[2]->Clear();
			chartLong->BottomAxis->Maximum = TGlSettings::countZones;
			err = 3;
			SqlDBModule->UpdIntSql("resultTubeShort", "resultL", -1, strWhere);
		}
		else {
			SqlDBModule->UpdIntSql("resultTubeShort", "resultL", countBrak, strWhere);
		}
		// -----------------
		for (int i = 0; i < sensorsDataLong.size(); i++) {
			sensorsDataLong[i].clear();
		}
		sensorsDataLong.clear();
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

// -----------new
int TfmShowZones::GetDataThick(int _numFusion, int _numTube) {
	AnsiString strSql = "";
	int err = 0;
	int itmp = 0;
	double tmpDouble = 0;
	std::vector<double>::iterator result;
	int indMax;
	double valBborderProcUp = 0;
	double valBborderProcD = 0;
	double valChart = 0;
	double val = 0;
	double valR = 0;
	int countNullsMin = 0;
	int countNullsMax = 0;
	AnsiString strTmp = "";
	AnsiString strWhere = "";
	TColor colorT;
	int countBrak = 0;
	vector<vector<double> >sensorsDataThickMin;
	vector<vector<double> >sensorsDataThickMinR;
	vector<vector<double> >sensorsDataThickMax;
    vector<vector<double> >sensorsDataThickMaxR;
	try {
		chartThick->Series[0]->Clear();
		chartThick->Series[1]->Clear();
		chartThick->Series[2]->Clear();
		chartThick->Series[3]->Clear();
		scale = 20.0;
		strWhere = "numFusion=" + IntToStr(_numFusion);
		strWhere += " and ";
		strWhere += " numTube= " + IntToStr(_numTube);
		// пороги
		strSql = "SELECT thresholdTUp, thresholdTDown,thresholdTNominal";
		strSql += " FROM resultTubeShort where numTube=:pnumTube and numFusion=:pnumFusion order by numFusion,numTube";
		SqlDBModule->queryForChart->Close();
		SqlDBModule->queryForChart->SQL->Text = strSql;
		SqlDBModule->queryForChart->Parameters->ParamByName("pnumTube")->Value = _numTube;
		SqlDBModule->queryForChart->Parameters->ParamByName("pnumFusion")->Value = _numFusion;
		SqlDBModule->queryForChart->Open();
		nominalThick = SqlDBModule->queryForChart->FieldByName("thresholdTNominal")->AsFloat;
		valBborderProcUp = SqlDBModule->queryForChart->FieldByName("thresholdTUp")->AsFloat;
		valBborderProcD = SqlDBModule->queryForChart->FieldByName("thresholdTDown")->AsFloat;
		SqlDBModule->queryForChart->Close();
		// TGlSettings::thresholdTDown = 12.5;
		// TGlSettings::thresholdTUp = 30;
		chartThick->LeftAxis->Title->Caption = FloatToStr(nominalThick) + " мм";
		chartThick->LeftAxis->Title->Angle = 0;
		// tmpD = nominalThick;
		// tmpD = valBborderProcD * nominalThick / 100.0;
		// tmpD = valBborderProcUp * nominalThick / 100.0;
		valBorderMin = RoundTo((nominalThick - valBborderProcD * nominalThick / 100.0), -1);
		valBorderMax = RoundTo((nominalThick + valBborderProcUp * nominalThick / 100.0), -1);
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

		// подготовим вектор
        		// ---
		for (int i = 0; i < sensorsDataThickMin.size(); i++) {
			sensorsDataThickMin[i].clear();
		}
		sensorsDataThickMin.clear();
		for (int i = 0; i < sensorsDataThickMinR.size(); i++) {
			sensorsDataThickMinR[i].clear();
		}
		sensorsDataThickMinR.clear();
		//-------------
		for (int i = 0; i < dataThickMin.size(); i++) {
		   dataThickMin[i].clear();
		}
        dataThickMin.clear();
		//-------------------
		vecMaxCh.clear();
		for (int i = 0; i < TGlSettings::countRecordsThick; i++) {
			vecMaxCh.push_back(0);
		}
		// ------------
		vecMaxChR.clear();
		for (int i = 0; i < TGlSettings::countRecordsThick; i++) {
			vecMaxChR.push_back(0);
		}
        if (SqlDBModule->queryForChart->RecordCount == 0) {
			// MessageDlg("МНК1(T) - данных нет!", mtWarning, TMsgDlgButtons() << mbOK, NULL);
		  //	chartThick->Title->Clear();
		  //	chartThick->Title->Text->Add("Данных по дефектам МНК1 нет!");
			err = 11;
            chartThick->Series[0]->Clear();
		chartThick->Series[2]->Clear();
			return err;
		}


		for (int i = 0; i < 2; i++) {
			vector<double>vekMin;
			dataThickMin.push_back(vekMin);
		}
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
					// val = -1;
					countNullsMin++;
					val = nominalThick;
					valR = -1;
				}
				else {
					val = SqlDBModule->queryForChart->FieldByName("Min" + IntToStr(z + 1))->AsFloat;
					if (val < 0) {
						valR = -1;
						val = nominalThick;
					}
					else {
						// valR = SqlDBModule->queryForChart->FieldByName("Min" + IntToStr(z + 1))->AsFloat;
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
		itmp = sensorsDataThickMin.size();
		itmp = sensorsDataThickMin[0].size();
		// dataThickMin[0].push_back(0);
		dataThickMin[0].push_back(nominalThick);
		dataThickMin[1].push_back(-1);
		// dataThickMin[1].push_back(0);
		for (int i = 0; i < TGlSettings::countZones; i++) {
			for (int j = 0; j < TGlSettings::countRecordsThick; j++) {
				vecMaxCh[j] = sensorsDataThickMin[j][i];
				valR = sensorsDataThickMin[j][i];
				vecMaxChR[j] = sensorsDataThickMinR[j][i];
				valR = sensorsDataThickMinR[j][i];
			}
			result = std::min_element(vecMaxCh.begin(), vecMaxCh.end());
			indMax = std::distance(vecMaxCh.begin(), result);
			dataThickMin[0].push_back(vecMaxCh[indMax]);
			val = vecMaxCh[indMax];
			// ----------
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
		chartThick->Series[2]->Title = FloatToStr(valBorderMin) + " мм";
		// chartThick->Series[2]->Title
		chartThick->Series[2]->Legend->Text = FloatToStr(valBorderMin) + " мм";
		chartThick->Series[2]->Legend->Visible = true;
		// chartThick->Series[2]->Title->
		int ss = 0;
		for (int i = 0; i < TGlSettings::countZones; i++) {
			if (dataThickMin[0][i] > 0) {
				if (RoundTo(dataThickMin[0][i],-1) < RoundTo(valBorderMin,-1)) {
					valChart = (dataThickMin[0][i] - nominalThick) * scale;
					chartThick->Series[0]->Add(valChart, "", clBlue);
					countBrak++;
					strTmp = "ДЕФЕКТ МНК1 ниже порога";
					strTmp += " Зона: " + IntToStr(i) + " (";
					strTmp += IntToStr(i * 100 - 100);
					strTmp += " - ";
					strTmp += IntToStr((i + 1) * 100 - 100) + " мм)";
					strTmp += " Предел: ";
					strTmp += FloatToStr(valBorderMin);
					strTmp += "мм Значение: ";
					strTmp += FloatToStr(dataThickMin[0][i]);
					strTmp += " мм"; ;
					memoBrack->Lines->Add(strTmp);
				}
				else {
					valChart = dataThickMin[0][i];
					valChart = (dataThickMin[0][i] - nominalThick) * scale;
					chartThick->Series[0]->Add(valChart, "", clGreen);
				}
			}
			else {
				chartThick->Series[0]->Add(0, "", clBlack);
			}
			// порог
			chartThick->Series[2]->Add((valBorderMin - nominalThick)*scale, "", clBlue);
		}
		int sz=dataThickMin[0].size();
		result = std::min_element(dataThickMin[0].begin(), dataThickMin[0].end());
		indMax = std::distance(dataThickMin[0].begin(), result);
		val = dataThickMin[0][indMax];
		strTmp="По трубе минимум="+FloatToStr(RoundTo(val,-1))+" мм";
		edThickDop->Text=strTmp;
		// ---
		for (int i = 0; i < sensorsDataThickMin.size(); i++) {
			sensorsDataThickMin[i].clear();
		}
		sensorsDataThickMin.clear();
		for (int i = 0; i < sensorsDataThickMinR.size(); i++) {
			sensorsDataThickMinR[i].clear();
		}
		sensorsDataThickMinR.clear();
		// ---------------- max
		// подготовим вектор
		for (int i = 0; i < sensorsDataThickMax.size(); i++) {
			sensorsDataThickMax[i].clear();
		}
		sensorsDataThickMax.clear();
		//------
		for (int i = 0; i < dataThickMax.size(); i++) {
		   dataThickMax[i].clear();
		}
		dataThickMax.clear();
        //----------
		for (int i = 0; i < sensorsDataThickMaxR.size(); i++) {
			sensorsDataThickMaxR[i].clear();
		}
		sensorsDataThickMaxR.clear();
        //------------
		vecMaxCh.clear();
		for (int i = 0; i < TGlSettings::countRecordsThick; i++) {
			vecMaxCh.push_back(0);
		}
		// ------------
		vecMaxChR.clear();
		for (int i = 0; i < TGlSettings::countRecordsThick; i++) {
			vecMaxChR.push_back(0);
		}
		// for (int i = 0;i<2; i++) {
		// vector<double> vecMax;
		// dataThickMax[i].dataThickMax(vecMax);
		// }
		for (int i = 0; i < 2; i++) {
			vector<double>vekMax;
			dataThickMax.push_back(vekMax);
		}
		// заберем данные по толщиномеру
		SqlDBModule->queryForChart->First();
		// while (!SqlDBModule->queryForChart->Eof) {
		itmp = TGlSettings::countRecordsThick;
		for (int i = 0; i < TGlSettings::countRecordsThick; i++) {
			vector<double>vecTmp;
			vector<double>vecTmpR;
			itmp = vecTmp.size();
			for (int z = 0; z < TGlSettings::countZones; z++) {
				AnsiString fn = "Max" + IntToStr(z + 1);
				strTmp = SqlDBModule->queryForChart->FieldByName("Max" + IntToStr(z + 1))->AsString;
				if (strTmp == "") {
					// val = -1;
					countNullsMax++;
					val = nominalThick;
					valR = -1;
				}
				else {
					val = SqlDBModule->queryForChart->FieldByName("Max" + IntToStr(z + 1))->AsFloat;
					if (val < 0) {
						val = nominalThick;
						valR = -1;
					}
					else {
						val = SqlDBModule->queryForChart->FieldByName("Max" + IntToStr(z + 1))->AsFloat;
						valR = 1;
					}

				}
				vecTmp.push_back(val);
				vecTmpR.push_back(valR);
			}
			itmp = vecTmp.size();
			sensorsDataThickMax.push_back(vecTmp);
			sensorsDataThickMaxR.push_back(vecTmpR);
			itmp = sensorsDataThickMax[i].size();
			SqlDBModule->queryForChart->Next();
		}

		SqlDBModule->queryForChart->Close();
		// максимальное значение и заполнение конечного вектора
		itmp = sensorsDataThickMax.size();
		itmp = sensorsDataThickMax[0].size();
		// сдвиг 0
		dataThickMax[0].push_back(0);
		dataThickMax[1].push_back(0);
		itmp = TGlSettings::countRecordsThick;
		for (int i = 0; i < TGlSettings::countZones; i++) {
			for (int j = 0; j < TGlSettings::countRecordsThick; j++) {
				vecMaxCh[j] = sensorsDataThickMax[j][i];
				vecMaxChR[j] = sensorsDataThickMaxR[j][i];
			}
			itmp = vecMaxCh.size();
			result = std::max_element(vecMaxCh.begin(), vecMaxCh.end());
			indMax = std::distance(vecMaxCh.begin(), result);
			dataThickMax[0].push_back(vecMaxCh[indMax]);
			// -----------------
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

		// chartThick->BottomAxis->Maximum = TGlSettings::countZones;
		chartThick->Series[1]->Clear();
		chartThick->Series[3]->Clear();
		chartThick->Series[3]->Color = clRed;
		for (int i = 0; i < TGlSettings::countZones; i++) {
			if (dataThickMax[0][i] > 0) {
				if (RoundTo(dataThickMax[0][i],-1) > (RoundTo(valBorderMax,-1)+0.01)) {   //костыль +0,01
					valChart = (dataThickMax[0][i] - nominalThick) * scale;
					chartThick->Series[1]->Add(valChart, "", clRed);
					countBrak++;
					strTmp = "ДЕФЕКТ МНК1 выше порога";
					strTmp += " Зона: " + IntToStr(i) + " (";
					strTmp += IntToStr(i * 100 - 100);
					strTmp += " - ";
					strTmp += IntToStr((i + 1) * 100 - 100) + " мм)";
					strTmp += " Предел: ";
					strTmp += FloatToStr(RoundTo(valBorderMax,-1));
					strTmp += "мм Значение: ";
					strTmp += FloatToStr(RoundTo(dataThickMax[0][i],-1));
					strTmp += " мм"; ;
					memoBrack->Lines->Add(strTmp);
				}
				else {
					valChart = (dataThickMax[0][i] - nominalThick) * scale;
					chartThick->Series[1]->Add(valChart, "", clGreen);
				}
			}
			else {
				chartThick->Series[1]->Add(0, "", clBlack);
			}
			valChart = valBorderMax - nominalThick;
			valChart = (valBorderMax - nominalThick) * scale;
			chartThick->Series[3]->Add(valChart, "", clRed);
		}
		result = std::max_element(dataThickMax[0].begin(), dataThickMax[0].end());
		indMax = std::distance(dataThickMax[0].begin(), result);
		val = dataThickMax[0][indMax];
		strTmp=edThickDop->Text;
		strTmp+=" максимум="+FloatToStr(RoundTo(val,-1))+" мм";
		edThickDop->Text=strTmp;
		int aa = countBrak;
		for (int i = 0; i < sensorsDataThickMax.size(); i++) {
			sensorsDataThickMax[i].clear();
		}
		sensorsDataThickMax.clear();
        //----------
		for (int i = 0; i < sensorsDataThickMaxR.size(); i++) {
			sensorsDataThickMaxR[i].clear();
		}
		sensorsDataThickMaxR.clear();
		err = 0;
		if (countNullsMin == TGlSettings::countZones * TGlSettings::countRecordsThick) {
		  //	chartThick->Title->Text->Add("Данных по дефектам МНК1 нет!");
			err = 11;
			SqlDBModule->UpdIntSql("resultTubeShort", "resultT", -1, strWhere);
			// return err;
		}
		else {
			// SqlDBModule->UpdIntSql("resultTubeShort", "resultT", countBrak, strWhere);
		}
		if (countNullsMax == TGlSettings::countZones * TGlSettings::countRecordsThick) {
		   //	chartThick->Title->Text->Add("Данных по дефектам МНК1 нет!");
			err = 12;
			SqlDBModule->UpdIntSql("resultTubeShort", "resultT", -1, strWhere);
			// return err;
		}
		else {
			SqlDBModule->UpdIntSql("resultTubeShort", "resultT", countBrak, strWhere);
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

// --------------

int TfmShowZones::RecalcData(int _numFusion, int _numTube) {
	AnsiString strSql = "";
	int err = 0;
	int itmp = 0;
	std::vector<double>::iterator result;
	int indMax;
	try {
		isLoadFm = true;
		strSql = "SELECT countZones";
		strSql += " FROM resultTubeShort where numTube>0 and numTube=:pnumTube and numFusion=:pnumFusion order by numFusion,numTube";
		SqlDBModule->queryForChart->Close();
		SqlDBModule->queryForChart->SQL->Text = strSql;
		SqlDBModule->queryForChart->Parameters->ParamByName("pnumTube")->Value = numTubeShow;
		SqlDBModule->queryForChart->Parameters->ParamByName("pnumFusion")->Value = numFusionShow;
		SqlDBModule->queryForChart->Open();
		countZones = SqlDBModule->queryForChart->FieldByName("countZones")->AsInteger;
		// serg
		GetDataCross(_numFusion, _numTube);
		// по зонам Продольник
		GetDataLong(_numFusion, _numTube);
		// -------------------- Толщиномер
		GetDataThick(_numFusion, _numTube);

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

// ------------------------
int TfmShowZones::PrintGrid(AnsiString _title, TStringGrid *_grid, TPrinter* _printer, TPrinterOrientation _orientation,
	int _beginPrinterXmm, int _beginPrinterYmm, int headerSizeMm, int footerSizeMm, int _colPerPage, bool _isPrinting) {
	int err = 0;
	int P, I, J, YPos, XPos, HorzSize, vertSize, horzSizeDisp;
	int countPage, numPage, rowCount, HeaderSize, FooterSize, rowHeight, FontHeight;
	int beginX = _beginPrinterXmm * 10;
	int beginY = _beginPrinterYmm * 10;
	double mmx, mmy, mmXD, mmYD, mmD;
	AnsiString Footer;
	TPoint curPos;
	int heightGrid = 0;
	int widthCol = 0;
	bool isNewGroup = false;
	try {
		// Верхний колонтитул, нижний колонтитул, межстрочный интервал, размер шрифта
		HeaderSize = headerSizeMm * 10;
		FooterSize = footerSizeMm * 10;
		rowHeight = 18;
		heightGrid = _grid->RowCount * rowHeight;
		FontHeight = 18;
		// Инициализировать принтер
		if (_isPrinting) {
			_printer->Orientation = _orientation;
			_printer->Title = _title;
			_printer->BeginDoc();
		}
		else {

		}

		// Установите шаг на мм
		mmx = GetDeviceCaps(_printer->Canvas->Handle, PHYSICALWIDTH) / GetDeviceCaps(_printer->Canvas->Handle, LOGPIXELSX) * 25.4;
		// точек на мм
		mmy = GetDeviceCaps(_printer->Canvas->Handle, PHYSICALHEIGHT) / GetDeviceCaps(_printer->Canvas->Handle, LOGPIXELSY) * 25.4;
		mmD = fmShowZones->PixelsPerInch / 25.4;
		// размер печатного поля в 0,1 мм
		vertSize = (int)(mmy) * 10 + beginY; // в 0,1 мм
		HorzSize = (int)(mmx) * 10 - beginX;
		horzSizeDisp = fmShowZones->Width * mmD;
		SetMapMode(_printer->Canvas->Handle, MM_LOMETRIC);
		// Задайте количество строк, которые влезут на лист
		rowCount = (int)(vertSize - HeaderSize - FooterSize) / rowHeight;
		// div Любой остаток отвергается. Mod  Выполняет целочисленное деление, возвращая остаток
		// Определите количество страниц
		if (_grid->RowCount % rowCount != 0) {
			countPage = (int)_grid->RowCount / rowCount + 1;
		}
		else {
			countPage = _grid->RowCount / rowCount;
		}
		//
		numPage = 1;
		// Сетка для печати
		// for (int P = 1; P <= countPage; P++) {
		// заголовок
		_printer->Canvas->Font->Height = 24;
		_printer->Canvas->TextOut((HorzSize / 2 - (_printer->Canvas->TextWidth(_title) / 2)), beginY - HeaderSize + 30, _title);
		_printer->Canvas->Pen->Width = 2;
		// _printer->Canvas->MoveTo(beginX, beginY - HeaderSize);
		// _printer->Canvas->LineTo(HorzSize, beginY - HeaderSize);
		// низ
		// _printer->Canvas->MoveTo(beginX, beginY-(vertSize + FooterSize));
		// _printer->Canvas->LineTo(HorzSize, beginY-(vertSize + FooterSize));
		_printer->Canvas->Font->Height = 24;
		Footer = "Страница: " + IntToStr(numPage) + " из " + IntToStr(countPage);
		_printer->Canvas->TextOut((HorzSize / 2 - (_printer->Canvas->TextWidth(Footer) / 2)), beginY - (vertSize + FooterSize), Footer);
		// ///Печатные линии
		_printer->Canvas->Font->Height = FontHeight;
		// for (int I = 1; I < rowCount; I++) {
		// if (_grid->RowCount >= I + (numPage - 1) * rowCount) {
		// XPos = beginX;
		// // for (J = 0; J < _grid->ColCount - 1; J++) {
		// for (J = 0; J < _colPerPage; J++) {
		// _printer->Canvas->TextOut(XPos, -YPos, _grid->Cells[J][I + (numPage - 1) * rowCount - 1]);
		// TPoint curPos = _printer->Canvas->PenPos;
		// _printer->Canvas->FrameRect(TRect(XPos, -YPos, curPos.X, -curPos.Y));
		// XPos = XPos + _grid->ColWidths[J] * 2;
		// curPos = _printer->Canvas->PenPos;
		// _printer->Canvas->LineTo(HorzSize, -YPos);
		// // if (HorzSize - XPos + _grid->ColWidths[J] * 2 < 0) {
		// // YPos = YPos + (rowSize + 1) * _grid->RowCount;
		// // break;
		// // }
		// // else {
		// //
		// // }
		// }
		// YPos = YPos + rowHeight;
		// }
		// else {
		// //
		// }
		// }
		// // //Добавить страницу
		// numPage++;
		// if (numPage <= countPage) {
		// _printer->NewPage();
		// }
		// else {
		// //
		// }
		// }
		// --------------------------
		int nc = 0;
		XPos = beginX;
		YPos = beginY - HeaderSize - 50;
		_printer->Canvas->MoveTo(XPos, YPos);
		widthCol = (int)(HorzSize - beginX) / _colPerPage;
		for (int c = 0; c < (TGlSettings::countZones + 1); c++) {
			curPos = _printer->Canvas->PenPos;
			// // проверка по вертикали
			// int p = YPos;
			// int e = -(vertSize + FooterSize);
			// if (p < e && isNewGroup) {
			// _printer->NewPage();
			// numPage++;
			// XPos = beginX;
			// YPos = -HeaderSize - 10;
			// }
			// else {
			// //
			// }
			for (int r = 0; r < _grid->RowCount; r++) {
				AnsiString out = "";
				if (_grid->Cells[c][r].Length() == 0) {
					out = "NULL";
				}
				else {
					out = _grid->Cells[c][r];
				}
				_printer->Canvas->TextOut(XPos, YPos, out);
				// _grid->ColWidths[J] * 2 < 0)
				YPos = YPos - rowHeight;
			}
			int t = (c) % (_colPerPage + 1);
			if ((c % _colPerPage == 0) && (c != 0)) {
				XPos = beginX;
				YPos = YPos - 50;
				// проверка по вертикали
				int p = YPos;
				int e = -(vertSize + FooterSize);
				if (p < e) {
					_printer->NewPage();
					numPage++;
					XPos = beginX;
					YPos = -HeaderSize - 10;
				}
				else {
					//
				}
				// выведем первый столбец для второй и последующих групп
				for (int r = 0; r < _grid->RowCount; r++) {
					AnsiString out = "";
					if (_grid->Cells[0][r].Length() == 0) {
						out = "NULL";
					}
					else {
						out = _grid->Cells[0][r];
					}
					_printer->Canvas->TextOut(XPos, YPos, out);
					// _grid->ColWidths[J] * 2 < 0)
					YPos = YPos - rowHeight;
				}
				XPos = XPos + widthCol;
				YPos = YPos + heightGrid;
			}
			else {
				isNewGroup = false;
				XPos = XPos + widthCol;
				YPos = YPos + heightGrid;
			}
		}
		// ---------------
		if (_isPrinting) {
			_printer->EndDoc();
		}
		else {

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

	//
	// //Example
	// procedure TForm1.Button1Click(Sender: TObject);
	// begin
	// //Drucken im Querformat
	// PrintStringGrid(Grid, 'StringGrid Print Landscape', poLandscape);
	// //Drucken im Hochformat
	// PrintStringGrid(Grid, 'StringGrid Print Portrait', poPortrait);
}

// ---------------------------------------------------------------------------
int TfmShowZones::PrintGridCanvas(TStringGrid *_grid, TPrinter* _printer, TPrinterOrientation _orientation, int _beginPrinterXmm,
	int _beginPrinterYmm, int _widgthMm, int _heigtMm, bool _independently) {
	int err = 0;
	int mmX, mmY, vertSizePage, horzSizePage, canCol, maxWidthGrid, maxHeghtGrid;
	TPoint curPos;
	try {
		if (_independently) {
			_printer->BeginDoc();
			_printer->Orientation = _orientation;
		}
		else {
			//
		}
		SetMapMode(_printer->Canvas->Handle, MM_LOMETRIC);
		SetStretchBltMode(_printer->Canvas->Handle, HALFTONE);
		curPos = _printer->Canvas->PenPos;
		// Масштабирование
		mmX = GetDeviceCaps(_printer->Canvas->Handle, PHYSICALWIDTH) / GetDeviceCaps(_printer->Canvas->Handle, LOGPIXELSX) * 25.4;
		mmY = GetDeviceCaps(_printer->Canvas->Handle, PHYSICALHEIGHT) / GetDeviceCaps(_printer->Canvas->Handle, LOGPIXELSY) * 25.4;
		vertSizePage = (int)((mmY) - _beginPrinterYmm) * 10;
		horzSizePage = (int)((mmX) - _beginPrinterXmm - 10) * 10;
		canCol = 20;
		maxWidthGrid = canCol * _grid->DefaultColWidth;
		maxHeghtGrid = _grid->Height * 1.2;
		if ((curPos.Y + maxHeghtGrid) < horzSizePage) {
			StretchBlt(_printer->Canvas->Handle, _beginPrinterXmm*10, -_beginPrinterYmm*10, horzSizePage, -maxHeghtGrid,
				_grid->Canvas->Handle, _grid->Left, _grid->Top, maxWidthGrid, _grid->Height, SRCCOPY);
			_printer->Canvas->MoveTo(_beginPrinterXmm*10, (curPos.Y - _grid->Height - 10));
		}
		else {
			//
		}
		if (_independently) {
			_printer->EndDoc();
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
	return err;
}

void __fastcall TfmShowZones::strGridLongDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect, TGridDrawState State) {
	TStringGrid* grid = static_cast<TStringGrid*>(Sender);
	int err = 0;
	double val = 0;
	try { // не трогаем заголовки и первый столбец
		if (ACol > 0 && ARow > 0) {
			AnsiString aStr = grid->Cells[ACol][ARow];
			// function TryStrToFloat(const S: string; out Value: Extended; const AFormatSettings: TFormatSettings): Boolean;
			if (TryStrToFloat(grid->Cells[ACol][ARow], val)) {
				//
			}
			else {
				val = -1;
			}
			if (val > TGlSettings::thresholdL1) {
				grid->Canvas->Brush->Color = clRed;
			}
			else {
				grid->Canvas->Brush->Color = clMoneyGreen;
			}
			if (val == -1) {
				grid->Canvas->Brush->Color = clWhite;
			}
			else {
				//
			}
			grid->Canvas->FillRect(Rect);
			grid->Canvas->TextOut(Rect.Left, Rect.Top, grid->Cells[ACol][ARow]);
		}
		else {
			//
		}

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

void __fastcall TfmShowZones::strGridThickDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect, TGridDrawState State) {
	TStringGrid* grid = static_cast<TStringGrid*>(Sender);
	int err = 0;
	double val = 0;
	try {
		if (ACol > 0 && ARow > 0) {
			AnsiString aStr = grid->Cells[ACol][ARow];
			val = TGlSettings::thresholdTDown;
			val = TGlSettings::thresholdTUp;
			// function TryStrToFloat(const S: string; out Value: Extended; const AFormatSettings: TFormatSettings): Boolean;
			if (TryStrToFloat(grid->Cells[ACol][ARow], val)) {
				if (val < TGlSettings::thresholdTDown || val > TGlSettings::thresholdTUp) {
					grid->Canvas->Brush->Color = clRed;
				}
				else {
					grid->Canvas->Brush->Color = clMoneyGreen;
				}
			}
			else {
				val = -1;
			}

			if (val == -1) {
				grid->Canvas->Brush->Color = clWhite;
			}
			else {
				//
			}
			grid->Canvas->FillRect(Rect);
			grid->Canvas->TextOut(Rect.Left, Rect.Top, grid->Cells[ACol][ARow]);
		}
		else {
			//
		}

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
void __fastcall TfmShowZones::FormResize(TObject *Sender) {
	int err = 0;
	AnsiString strTmp;
	// PanelCross->Align = alNone;
	// PanelCross->Height=240;
	// верх
	PanelThick->Height = SqlDBModule->GetIntFieldSQL("currentSettings", "ParamValueFloat",
		"isActual=1 and UPPER(ParamName)=UPPER('PanelThickHeight')", 150, err);
	SplitterTop->Top = PanelThick->Height;
	// низ  PanelLong
	PanelLong->Align = alBottom;
	PanelLong->Height = SqlDBModule->GetIntFieldSQL("currentSettings", "ParamValueFloat",
		"isActual=1 and UPPER(ParamName)=UPPER('PanelLongHeight')", 150, err);
	SplitterMid->Top = PanelLong->Top + SplitterMid->Height;
	// serg33
	// PanelCross->Top = SplitterTop->Top + SplitterTop->Height;
	// середина
	// PanelCross->Align = alClient;
	if (queryTitle->Active) {
		for (int i = 0; i < dbGridTitle1->Columns->Count; i++) {
			dbGridTitle1->Columns->Items[i]->Width = SqlDBModule->GetIntFieldSQL("currentSettings", "ParamValueFloat",
				"isActual=1 and UPPER(ParamName)=UPPER('dbGridTitleCol1" + IntToStr(i) + "')", 60, err);
		}
		for (int i = 0; i < dbGridTitle2->Columns->Count; i++) {
			dbGridTitle2->Columns->Items[i]->Width = SqlDBModule->GetIntFieldSQL("currentSettings", "ParamValueFloat",
				"isActual=1 and UPPER(ParamName)=UPPER('dbGridTitleCol2" + IntToStr(i) + "')", 60, err);
		}
		// ------------------------
	}
	else {
		//
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfmShowZones::strGridCrossSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect) {
	// static int LoadTubeCrossFromFile(AnsiString _fullFileName,AnsiString _head,short &zones,short &sensors_a,vector<int> &VZoneLength,
	// DynamicArray<double> &zone_data,vector<vector<double> > &sensor_data,vector<vector<vector<double> > > &Source_Data);
	//
	// int gmax_zones = 140;
	// zone_data.set_length(gmax_zones);
	// // Deads.resize(gmax_zones);
	// VZoneLength.resize(gmax_zones);
	// ZoneLength=200;
	// for (int i = 0; i < gmax_zones; i++)
	// VZoneLength[i] = ZoneLength;
	// zones = 0;
	// Source_Data.resize(gmax_zones);
	// sensors_a = 12;
	// sensor_data.resize(gmax_zones);
	// for (int i = 0; i < gmax_zones; i++)
	// {
	// sensor_data[i].resize(sensors_a);
	// Source_Data[i].resize(sensors_a);
	// }
	// if (OpenDialogFromFile->Execute()) {
	// // ReadFromFile();
	// //TExtFunction::LoadTubeCrossFromFile(OpenDialogFromFile->FileName, "", zones, sensors_a, VZoneLength, zone_data, sensor_data, Source_Data);
	// }
	// else{
	// //
	// }
	//
	// //for (int zone = startZone; zone <= finalZone; zone++)
	// //{
	// //	for (int j = 0; j < (int)FilteredOut_Data[zone][sensor].size(); j++)
	// //		_F->AddOut(FilteredOut_Data[zone][sensor][j] * gain[sensor],
	// //		ZoneColor(FilteredOut_Data[zone][sensor][j] * gain[sensor],
	// //			Deads[zone][j]));
	// //	}
}
// ---------------------------------------------------------------------------

void __fastcall TfmShowZones::chartLongClickSeries(TCustomChart *Sender, TChartSeries *Series, int ValueIndex, TMouseButton Button,
	TShiftState Shift, int X, int Y) {
	int zoneNum = ValueIndex;
	int sensorNum = Series->SeriesIndex;
	// double valZone = 0;
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
	pChart->Title->Text->Add("ПРОДОЛЬНЫЙ КОНТРОЛЬ (МНК3)");
	tmpStr = " Зона: " + IntToStr(ValueIndex) + " (";
	tmpStr += IntToStr((ValueIndex - 1) * 100);
	tmpStr += " - ";
	tmpStr += IntToStr((ValueIndex) * 100) + " мм)";
	tmpStr += " Макс сигнал=";
	if(dataLong.empty())
	{
	if (dataLong[ValueIndex] < 0) {
		tmpStr += "XXX";
	}
	else {
		tmpStr += FloatToStrF(dataLong[ValueIndex], ffFixed, 4, 1) + "%";
	}
    }
	colorMark = clFuchsia;
	if (selectZoneL > 0 || selectZoneL < countZones) {
		// ChartCross->Series[selectSensor]->ValueColor[selectZone] = colorMark
		if (isZoneMarkedL) {
			pSeries0->ValueColor[oldSelectZoneL] = oldColorL0;
			// ----------
		}
		else {
			oldColorL0 = pSeries0->ValueColor[selectZoneL];
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

void __fastcall TfmShowZones::chartThickClickSeries(TCustomChart *Sender, TChartSeries *Series, int ValueIndex, TMouseButton Button,
	TShiftState Shift, int X, int Y) {
	int zoneNum = ValueIndex;
	int sensorNum = Series->SeriesIndex;
	double valZoneMax = 0;
	double valZoneMin = 0;
	TChart* pChart = static_cast<TChart*>(Sender);
	TChartSeries *pSeries0 = pChart->Series[0];
	TChartSeries *pSeries1 = pChart->Series[1]; //
	AnsiString tmpStr = "";
	if (Button == mbLeft) {
		selectZoneT = ValueIndex;
		// if (currentZone!=oldZone) {
		// pSeries->Color=oldColor;
		// }else{
		//
		// }
	}
	else {
		//
	}
	if (ValueIndex == 0) {
		return;
	}
	else {
		//
	}
	// valZoneMax = dataThickMax[ValueIndex];
	// valZoneMin = dataThickMin[ValueIndex];
	valZoneMax = dataThickMax[1][ValueIndex];
	valZoneMin = dataThickMin[1][ValueIndex];
	pChart->Title->Clear();
	pChart->Title->Text->Add("КОНТРОЛЬ ТОЛЩИНЫ (МНК1)");
	tmpStr = " Зона: " + IntToStr(ValueIndex) + " (";
	tmpStr += IntToStr((ValueIndex - 1) * 100);
	tmpStr += " - ";
	tmpStr += IntToStr(ValueIndex * 100) + " мм)";
	if (valZoneMax < 0) {
		tmpStr += " Максимум: XXX мм";
	}
	else {
		tmpStr += " Максимум:" + FloatToStrF(dataThickMax[0][ValueIndex], ffFixed, 4, 1) + " мм";
	}
	// ----------
	if (valZoneMin < 0) {
		tmpStr += " Минимум: XXX мм";
	}
	else {
		tmpStr += " Минимум:" + FloatToStrF(dataThickMin[0][ValueIndex], ffFixed, 4, 1) + " мм";
	}
	// tmpStr += " Минимум:" + FloatToStrF(valZoneMin, ffFixed, 4, 1) + " мм";
	colorMark = clFuchsia;
	if (selectZoneT > 0 || selectZoneT < countZones) {
		// ChartCross->Series[selectSensor]->ValueColor[selectZone] = colorMark
		if (isZoneMarkedT) {
			pSeries0->ValueColor[oldSelectZoneT] = oldColorT0;
			pSeries1->ValueColor[oldSelectZoneT] = oldColorT1;
			// ----------
		}
		else {
			oldColorT0 = pSeries0->ValueColor[selectZoneT];
			oldColorT1 = pSeries1->ValueColor[selectZoneT];
			pSeries0->ValueColor[selectZoneT] = oldColorT0;
			pSeries1->ValueColor[selectZoneT] = oldColorT1;
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

void __fastcall TfmShowZones::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift) {
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
		ChartCrossClickSeries(chartCross, chartCross->Series[0], selectZoneC, button, shift, 0, 0);
	}
	else {
		//
	}
	// -----
	if (Key == VK_RIGHT && selectZoneC < countZones && isZoneMarkedC) {
		selectZoneC++;
		ChartCrossClickSeries(chartCross, chartCross->Series[0], selectZoneC, button, shift, 0, 0);
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
	// ---
	bool dd=pQueryShowListTubes->Bof;
	if (Key == VK_UP && pQueryShowListTubes->RecNo>0 ) {
	  pQueryShowListTubes->Prior();
	  pnlTopLeft->Color=clYellow;
	  Application->ProcessMessages();
	  ShowZones();
	  Sleep(200);
	  pnlTopLeft->Color=clMoneyGreen;
      Application->ProcessMessages();
	}else{
		//
	}
	if (Key == VK_DOWN && pQueryShowListTubes->RecNo<pQueryShowListTubes->RecordCount) {
	  pQueryShowListTubes->Next();
	  pnlTopLeft->Color=clYellow;
	  Application->ProcessMessages();
	  ShowZones();
      Sleep(200);
	  pnlTopLeft->Color=clMoneyGreen;
	  Application->ProcessMessages();
	}else{
		//
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfmShowZones::menuPrintClick(TObject *Sender) {
	printer = Printer();
	PrintResult2(printer, poLandscape, 20, 10);
}
// ---------------------------------------------------------------------------

int TfmShowZones::FillTitle(int _numFuzion, int _numTube) {
	int err = 0;
	AnsiString strSql = "";
	strSql = " SELECT T1.dtmCreate as 'Дата и время контроля'";
	strSql += ",T1.numFusion as '№ плавки'";
	strSql += ", T1.numTube as '№ трубы' ";
	strSql += ",T6.typeSizeName as 'Типоразмер'", strSql += ", T3.normDocName as 'Норм. документ'";
	strSql += ",T4.SopName as 'Настр. СОП' ";
	strSql += ", T5.steelGradeName as 'Марка стали',  T7.workShiftName as 'Смена'";
	strSql += ",T2.operatorName as 'Оператор' ";
	strSql += ",(case (SELECT count(*) FROM resultThick where numFusion=T1.numFusion and numTube=T1.numTube) when 0 then 'Нет данных' else"\
	" case T1.resultT when 0 then 'Годно' when -1 then 'Нет данных' else 'ДЕФЕКТ' end end) as 'К. Толщины' ";
	strSql += ",(case (SELECT count(*) FROM resultCross where numFusion=T1.numFusion and numTube=T1.numTube) when 0 then 'Нет данных' else"\
	" case T1.resultC when 0 then 'Годно' when -1 then 'Нет данных' else 'ДЕФЕКТ' end end) as 'Поперечный к.' ";
	strSql += ",(case (SELECT count(*) FROM resultLong where numFusion=T1.numFusion and numTube=T1.numTube) when 0 then 'Нет данных' else"\
	" case T1.resultL when 0 then 'Годно' when -1 then 'Нет данных' else 'ДЕФЕКТ' end end) as 'Продольный к.' ";
	strSql += ",T1.lengthTube as 'Длина, мм' , T1.speedTube as 'Скорость,м/с',T1.speedRound as 'МНК3 об/мин' ";
	// strSql += "	,T1.thresholdC1,T1.thresholdC2,T1.thresholdL1,T1.thresholdL2,thresholdTUp,thresholdTDown,thresholdTNominal";
	// strSql +=
	// " ,T1.indOperatorName,T1.indNormDocName,T1.indSopName,T1.indSteelGradeName,T1.indWorkShiftName,T1.indTypeSize,T1.dtmCreate ";
	strSql += ",T1.numFusion";
	strSql += ",T1.currentMagnetT";
	strSql += ",T1.currentMagnetC";
	strSql += ",T1.currentMagnetL";
	strSql += ",T1.speedTube";
    strSql += ",T1.speedRound";
	strSql += " FROM resultTubeShort T1 ";
	strSql += " join operators T2 on(T1.indOperatorName = T2.rec_id)";
	strSql += " join normDocs T3 on(T1.indNormDocName = T3.rec_id)";
	strSql += " join Sops T4 on(T1.indSopName = T4.rec_id)";
	strSql += " join steelGrades T5 on(T1.indSteelGradeName = T5.rec_id)";
	strSql += " join tubesTypeSize T6 on(T1.indTypeSize = T6.rec_id)";
	strSql += " join workShifts T7 on(T1.indWorkShiftName = T7.rec_id)";
	// strSqlGlobal += " where T1.isEmpty=0 and T1.numFusion=:pnumFusion";
	strSql += " where T1.isEmpty=0";
	strSql += " and T1.numFusion=:pnumFusion";
	strSql += " and T1.numTube=:pnumTube";
	strSql += " order by  T1.numFusion, T1.numTube,T1.dtmCreate ";

	try {
		queryTitle->Close();
		queryTitle->SQL->Text = strSql;
		queryTitle->Parameters->ParamByName("pnumFusion")->Value = numFusionShow;
		queryTitle->Parameters->ParamByName("pnumTube")->Value = numTubeShow;
		queryTitle->Open();
		int rr = queryTitle->RecordCount;
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
//--------------------------
int TfmShowZones::ShowZones() {
	int err = 0;
	AnsiString title = "";
	AnsiString strOut = "";
	double tmpD = 0;
	double nominal = 0;
	try {
		memoBrack->Clear();
//		timerRefresh->Enabled = false;
//		if (fmShowZones == NULL) {
//			fmShowZones = new TfmShowZones(NULL, queryShowListTubes);
//			fmShowZones->ShowModal();
//		}
//		else {
//			//
//		}
//		delete fmShowZones;
//		fmShowZones = NULL;
//		timerRefresh->Enabled = true;
		// T6.typeSizeName as 'Типоразмер трубы',T7.workShiftName as 'Смены',T1.numTube as 'Номер трубы'"
		title = " Номер плавки:";
		title += pQueryShowListTubes->FieldByName("Номер плавки")->AsString;
		title += " Номер трубы:";
		title += pQueryShowListTubes->FieldByName("Номер трубы")->AsString;
		fmShowZones->Caption = title;
		title += " Типоразмер:";
		title += pQueryShowListTubes->FieldByName("Типоразмер")->AsString;

        numTubeShow = pQueryShowListTubes->FieldByName("Номер трубы")->AsInteger;
		numFusionShow = pQueryShowListTubes->FieldByName("Номер плавки")->AsInteger;
		FillTitle(numFusionShow, numTubeShow);
		RecalcData(numFusionShow, numTubeShow);

		strOut = "Параметры контроля Верх. порог сигнала: ";
		strOut += FloatToStr(pQueryShowListTubes->FieldByName("thresholdC1")->AsFloat);
		strOut += "%";
		strOut += " Нижн. порог сигнала: ";
		strOut += FloatToStr(pQueryShowListTubes->FieldByName("thresholdC2")->AsFloat);
		strOut += "%";
		// strOut+=" Ток намагничивания:";
		// strOut+="5";
		strOut += " Результат:";
        if(0 == chartCross->BottomAxis->Maximum)
		{
			strOut += "Нет данных";
		}
		else strOut += pQueryShowListTubes->FieldByName("Поперечный к.")->AsString;
		fmShowZones->edtCross->Text = strOut;
		strOut = "Параметры контроля Верх. порог сигнала: ";
		strOut += FloatToStr(pQueryShowListTubes->FieldByName("thresholdL1")->AsFloat);
		strOut += "%";
		strOut += " Нижн. порог сигнала: ";
		strOut += FloatToStr(pQueryShowListTubes->FieldByName("thresholdL2")->AsFloat);
		strOut += "%";
		// strOut+=" Ток намагничивания:";
		// strOut+="5";
		strOut += " Результат:";
		if(0 == chartLong->BottomAxis->Maximum)
		{
			strOut += "Нет данных";
		}
		else strOut += pQueryShowListTubes->FieldByName("Продольный к.")->AsString;
		fmShowZones->edtLong->Text = strOut;
		strOut = "Параметры контроля Номинальная толщина: ";
		strOut += FloatToStr(pQueryShowListTubes->FieldByName("thresholdTNominal")->AsFloat);
		strOut += " мм";
		strOut += " Минимальная толщина: ";
		nominal = pQueryShowListTubes->FieldByName("thresholdTNominal")->AsFloat;
		tmpD = pQueryShowListTubes->FieldByName("thresholdTDown")->AsFloat;
		tmpD = RoundTo((nominal - (tmpD * nominal / 100.0)), -1);
		strOut += FloatToStr(tmpD);
		strOut += " мм";
		strOut += " Максимальная толщина: ";
		tmpD = pQueryShowListTubes->FieldByName("thresholdTUp")->AsFloat;
		tmpD = RoundTo((nominal + (tmpD * nominal / 100.0)), -1);
		strOut += FloatToStr(tmpD);
		strOut += " мм";
		// strOut+=" Ток намагничивания:";
		// strOut+="5";
		strOut += " Результат:";
		if(0 == chartThick->BottomAxis->Maximum)
		{
			strOut += "Нет данных";
		}
		else strOut += pQueryShowListTubes->FieldByName("К. толщины")->AsString;
		fmShowZones->edtThick->Text = strOut;
		// TGlSettings::thresholdC1 = queryShowListTubes->FieldByName("thresholdC1")->AsFloat;
		// TGlSettings::thresholdC2 = queryShowListTubes->FieldByName("thresholdC2")->AsFloat;
		// TGlSettings::thresholdL1 = queryShowListTubes->FieldByName("thresholdL1")->AsFloat;
		// TGlSettings::thresholdL2 = queryShowListTubes->FieldByName("thresholdL2")->AsFloat;
		// TGlSettings::thresholdTUp = queryShowListTubes->FieldByName("thresholdTUp")->AsFloat;
		// TGlSettings::thresholdTDown = queryShowListTubes->FieldByName("thresholdTDown")->AsFloat;
		// AnsiString a = queryShowListTubes->SQL->Text;
		// TGlSettings::thresholdTNominal = queryShowListTubes->FieldByName("thresholdTNominal")->AsFloat;
		// fmShowZones->numFusion=queryShowTubes->FieldByName("Номер плавки")->AsString;
		// fmShowZones->numTube=queryShowTubes->FieldByName("Номер трубы")->AsString;
		// fmShowZones->numTube = queryShowListTubes->FieldByName("numTube")->AsInteger;
		

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
