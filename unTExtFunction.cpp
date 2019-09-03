// ---------------------------------------------------------------------------

#pragma hdrstop

#include "unTExtFunction.h"
#include "unSQLDbModule.h"
#include "unTUtils.h"
#include "unFmMessage.h"
// ---------------------------------------------------------------------------

// -------------------------
TExtFunction::TExtFunction() {

}

TExtFunction::~TExtFunction(void) {

}

// настраиваем чарты одноообразно, длинно муторно, но полезно
void TExtFunction::PrepareThickBarChart(int _minY, int _maxY, int _countSensors, int _maxZones, TChart* _chart) {
	int err = 0;
	_chart->BackWall->Color = clBtnFace;
	_chart->BackWall->Transparent = false;
	_chart->BottomWall->Visible = false;
	_chart->Foot->AdjustFrame = false;
	_chart->Foot->Alignment = taLeftJustify;
	_chart->Foot->Visible = false;
	_chart->LeftWall->Visible = false;
	_chart->Legend->Visible = false;
	_chart->MarginBottom = 0;
	_chart->MarginLeft = 0;
	_chart->MarginRight = 5;
	_chart->MarginTop = 0;
	_chart->MarginUnits = muPixels;
	_chart->PrintProportional = false;
	_chart->SubFoot->Alignment = taLeftJustify;
	_chart->SubFoot->Visible = false;
	_chart->SubTitle->Alignment = taLeftJustify;
	_chart->SubTitle->Visible = false;
	_chart->Title->Alignment = taLeftJustify;
	// убрать прокрутку по колесу мыши
	// _chart->AllowPanning = Vcltee::Teeprocs::pmNone;
	_chart->AllowPanning = Teeprocs::pmNone;
	// _chart->Title->Text = (L"");
	// _chart->Title->Visible = false;
	_chart->BottomAxis->Automatic = false;
	_chart->BottomAxis->AutomaticMaximum = false;
	_chart->BottomAxis->AutomaticMinimum = false;
	_chart->BottomAxis->Axis->Width = 1;
	_chart->BottomAxis->ExactDateTime = false;
	_chart->BottomAxis->Increment = 1;
	_chart->BottomAxis->Maximum = _maxZones;
	_chart->BottomAxis->MaximumOffset = 1;
	// _chart->BottomAxis->MinorTickCount = 0;
	// _chart->DepthAxis->Automatic = false;
	// _chart->DepthAxis->AutomaticMaximum = false;
	// _chart->DepthAxis->AutomaticMinimum = false;
	// _chart->DepthAxis->ExactDateTime = false;
	// _chart->DepthAxis->Increment = 1;
	// _chart->DepthTopAxis->Automatic = false;
	// _chart->DepthTopAxis->AutomaticMaximum = false;
	// _chart->DepthTopAxis->AutomaticMinimum = false;
	// _chart->DepthTopAxis->ExactDateTime = false;
	// _chart->DepthTopAxis->Increment = 1;
	_chart->Emboss->Color = clLime;
	_chart->LeftAxis->Automatic = false;
	_chart->LeftAxis->AutomaticMaximum = false;
	_chart->LeftAxis->AutomaticMinimum = false;
	_chart->LeftAxis->AxisValuesFormat = "#,##";
	_chart->LeftAxis->ExactDateTime = false;
	_chart->LeftAxis->LabelsMultiLine = true;
	_chart->LeftAxis->LabelsOnAxis = false;
	_chart->LeftAxis->MinorTicks->Visible = false;
	_chart->Pages->AutoScale = true;
	// _chart->Pages->MaxPointsPerPage = 8;
	_chart->RightAxis->Automatic = false;
	_chart->RightAxis->AutomaticMaximum = false;
	_chart->RightAxis->AutomaticMinimum = false;
	_chart->RightAxis->Visible = false;
	_chart->Shadow->Color = clRed;
	_chart->Shadow->Visible = false;
	_chart->TopAxis->Automatic = false;
	_chart->TopAxis->AutomaticMaximum = false;
	_chart->TopAxis->AutomaticMinimum = false;
	_chart->TopAxis->Visible = false;
	_chart->View3D = false;
	_chart->Zoom->Allow = false;
	_chart->Align = alClient;
	_chart->BevelOuter = bvNone;
	// series
	_chart->SeriesList->Clear();
	for (int i = 0; i < _countSensors; i++) {
		TBarSeries* series = new TBarSeries(_chart);
		// TChartSeries* series = new TChartSeries(_chart);
		series->Depth = 0;
		series->ColorEachPoint = true;
		series->Marks->Visible = true;
		series->Marks->Arrow->Visible = false;
		series->Marks->Callout->Brush->Color = clBlack;
		series->Marks->Callout->Arrow->Visible = false;
		series->Marks->Margins->Left = 44;
		series->ShowInLegend = false;
		series->AutoMarkPosition = false;
		series->BarRound = brNone;
		// series->AutoRepaint = false;
		// ---------------------------дополнительные
		// int a = series->BarWidth;
		if (_maxZones < 50) {
			series->CustomBarWidth = 60; // ширина метки в пикселах
		}
		else {
			series->CustomBarWidth = 30;
		}
		if (_maxZones < 25) {
			series->CustomBarWidth = 90; // ширина метки в пикселах
		}
		else {
			series->CustomBarWidth = 65;
		}
		if (_maxZones < 15) {
			series->CustomBarWidth = 120; // ширина метки в пикселах
		}
		else {
			series->CustomBarWidth = 85;
		}
		// series->BarWidthPercent = 50; //в процентах работает криво
		series->BarStyle = bsRectangle; // примитив метки
		// градиент нафиг, ибо записывается цвет криво
		// series->BarStyle = bsRectGradient;
		// series->BarWidthPercent = 100;
		// series->CustomHorizAxis=
		// ---------------------------дополнительные
		series->Dark3D = false;
		series->MarksOnBar = true;
		series->OffsetPercent = 50;
		series->Shadow->Visible = false;
		series->YOrigin = 3.0;
		series->XValues->Name = "X";
		series->Emboss->Color = clWhite; //
		series->Emboss->HorizSize = 4;
		// series->MultiBar = mbStacked;  { mbNone, mbSide, mbStacked, mbStacked100, mbSideAll, mbSelfStack };
		series->MultiBar = Vcltee::Series::mbStacked;
		series->SideMargins = false;
		series->XValues->Order = loAscending;
		series->YValues->Name = "Bar";
		series->YValues->Order = loNone;
		// ---------------------------дополнительные
		series->Emboss->Visible = true;
		// series->BarWidthPercent = 5;
		// series->CustomBarWidth=1;
		// Series1->CustomBarWidth
		// series->Shadow->HorizSize = 4;
		// series->Shadow->VertSize = 5;
		// привязка событий к серии
		// series->OnClick=_chart->
		// series->OnDblClick = _chart->;
		// -----------------
		_chart->AddSeries(series);
	}
	err = _chart->SeriesCount();
	_chart->LeftAxis->Minimum = _minY;
	_chart->LeftAxis->Maximum = _maxY;
	_chart->Axes->Behind = false;
	// _chart->LeftAxis->Maximum = 1;
	_chart->Refresh();
}

void TExtFunction::PrepareBarChart(int _countSensors, int _maxZones, TChart* _chart) {
	int err = 0;
	_chart->BackWall->Color = clBtnFace;
	_chart->BackWall->Transparent = false;
	_chart->BottomWall->Visible = false;
	_chart->Foot->AdjustFrame = false;
	_chart->Foot->Alignment = taLeftJustify;
	_chart->Foot->Visible = false;
	_chart->LeftWall->Visible = false;
	_chart->Legend->Visible = false;
	_chart->MarginBottom = 0;
	_chart->MarginLeft = 0;
	_chart->MarginRight = 5;
	_chart->MarginTop = 0;
	_chart->MarginUnits = muPixels;
	_chart->PrintProportional = false;
	_chart->SubFoot->Alignment = taLeftJustify;
	_chart->SubFoot->Visible = false;
	_chart->SubTitle->Alignment = taLeftJustify;
	_chart->SubTitle->Visible = false;
	_chart->Title->Alignment = taLeftJustify;
	// убрать прокрутку по колесу мыши
	// _chart->AllowPanning = Vcltee::Teeprocs::pmNone;
	_chart->AllowPanning = Teeprocs::pmNone;
	// _chart->Title->Text = (L"");
	// _chart->Title->Visible = false;
	_chart->BottomAxis->Automatic = false;
	_chart->BottomAxis->AutomaticMaximum = false;
	_chart->BottomAxis->AutomaticMinimum = false;
	_chart->BottomAxis->Axis->Width = 1;
	_chart->BottomAxis->ExactDateTime = false;
	_chart->BottomAxis->Increment = 1;
	_chart->BottomAxis->Maximum = _maxZones;
	_chart->BottomAxis->MaximumOffset = 1;
	// _chart->BottomAxis->MinorTickCount = 0;
	// _chart->DepthAxis->Automatic = false;
	// _chart->DepthAxis->AutomaticMaximum = false;
	// _chart->DepthAxis->AutomaticMinimum = false;
	// _chart->DepthAxis->ExactDateTime = false;
	// _chart->DepthAxis->Increment = 1;
	// _chart->DepthTopAxis->Automatic = false;
	// _chart->DepthTopAxis->AutomaticMaximum = false;
	// _chart->DepthTopAxis->AutomaticMinimum = false;
	// _chart->DepthTopAxis->ExactDateTime = false;
	// _chart->DepthTopAxis->Increment = 1;
	_chart->Emboss->Color = clLime;
	_chart->LeftAxis->Automatic = false;
	_chart->LeftAxis->AutomaticMaximum = false;
	_chart->LeftAxis->AutomaticMinimum = false;
	_chart->LeftAxis->AxisValuesFormat = "#,##";
	_chart->LeftAxis->ExactDateTime = false;
	_chart->LeftAxis->LabelsMultiLine = true;
	_chart->LeftAxis->LabelsOnAxis = false;
	_chart->LeftAxis->MinorTicks->Visible = false;
	_chart->Pages->AutoScale = true;
	// _chart->Pages->MaxPointsPerPage = 8;
	_chart->RightAxis->Automatic = false;
	_chart->RightAxis->AutomaticMaximum = false;
	_chart->RightAxis->AutomaticMinimum = false;
	_chart->RightAxis->Visible = false;
	_chart->Shadow->Color = clRed;
	_chart->Shadow->Visible = false;
	_chart->TopAxis->Automatic = false;
	_chart->TopAxis->AutomaticMaximum = false;
	_chart->TopAxis->AutomaticMinimum = false;
	_chart->TopAxis->Visible = false;
	_chart->View3D = false;
	_chart->Zoom->Allow = false;
	_chart->Align = alClient;
	_chart->BevelOuter = bvNone;
	// series
	_chart->SeriesList->Clear();
	for (int i = 0; i < _countSensors; i++) {
		TBarSeries* series = new TBarSeries(_chart);
		// TChartSeries* series = new TChartSeries(_chart);
		series->Depth = 0;
		series->ColorEachPoint = true;
		series->Marks->Visible = false;
		series->Marks->Arrow->Visible = false;
		series->Marks->Callout->Brush->Color = clBlack;
		series->Marks->Callout->Arrow->Visible = false;
		series->Marks->Margins->Left = 44;
		series->ShowInLegend = false;
		series->AutoMarkPosition = false;
		series->BarRound = brNone;
		// series->AutoRepaint = false;
		// ---------------------------дополнительные
		// int a = series->BarWidth;
		if (_maxZones < 50) {
			series->CustomBarWidth = 60; // ширина метки в пикселах
		}
		else {
			series->CustomBarWidth = 30;
		}
		if (_maxZones < 25) {
			series->CustomBarWidth = 90; // ширина метки в пикселах
		}
		else {
			series->CustomBarWidth = 65;
		}
		if (_maxZones < 15) {
			series->CustomBarWidth = 120; // ширина метки в пикселах
		}
		else {
			series->CustomBarWidth = 85;
		}
		// series->BarWidthPercent = 50; //в процентах работает криво
		series->BarStyle = bsRectangle; // примитив метки
		// градиент нафиг, ибо записывается цвет криво
		// series->BarStyle = bsRectGradient;
		// series->BarWidthPercent = 100;
		// series->CustomHorizAxis=
		// ---------------------------дополнительные
		series->Dark3D = false;
		series->MarksOnBar = true;
		series->MultiBar = mbStacked;
		series->OffsetPercent = 50;
		series->Shadow->Visible = false;
		series->YOrigin = 3.0;
		series->XValues->Name = "X";
		series->Emboss->Color = clWhite; //
		series->Emboss->HorizSize = 4;
		series->MultiBar = mbStacked;
		series->SideMargins = false;
		series->XValues->Order = loAscending;
		series->YValues->Name = "Bar";
		series->YValues->Order = loNone;
		// ---------------------------дополнительные
		series->Emboss->Visible = true;
		// series->BarWidthPercent = 5;
		// series->CustomBarWidth=1;
		// Series1->CustomBarWidth
		// series->Shadow->HorizSize = 4;
		// series->Shadow->VertSize = 5;
		// привязка событий к серии
		// series->OnClick=_chart->
		// series->OnDblClick = _chart->;
		// -----------------
		_chart->AddSeries(series);
	}
	err = _chart->SeriesCount();
	_chart->LeftAxis->Minimum = 0;
	_chart->LeftAxis->Maximum = _countSensors + 1;
	_chart->Axes->Behind = false;
	// _chart->LeftAxis->Maximum = 1;
	_chart->Refresh();
}

void TExtFunction::PrepareBarChartLCPav(int _countSensors, int _maxZones, TChart* _chart) {
	int err = 0;
	_chart->BackWall->Color = clBtnFace;
	_chart->BackWall->Transparent = false;
	_chart->BottomWall->Visible = false;
	_chart->Foot->AdjustFrame = false;
	_chart->Foot->Alignment = taLeftJustify;
	_chart->Foot->Visible = false;
	_chart->LeftWall->Visible = false;
	_chart->Legend->Visible = false;
	_chart->MarginBottom = 0;
	_chart->MarginLeft = 0;
	_chart->MarginRight = 5;
	_chart->MarginTop = 0;
	_chart->MarginUnits = muPixels;
	_chart->PrintProportional = false;
	_chart->SubFoot->Alignment = taLeftJustify;
	_chart->SubFoot->Visible = false;
	_chart->SubTitle->Alignment = taLeftJustify;
	_chart->SubTitle->Visible = false;
	_chart->Title->Alignment = taLeftJustify;
	// убрать прокрутку по колесу мыши
	// _chart->AllowPanning = Vcltee::Teeprocs::pmNone;
	_chart->AllowPanning = Teeprocs::pmNone;
	// _chart->Title->Text = (L"");
	// _chart->Title->Visible = false;
	_chart->BottomAxis->Automatic = false;
	_chart->BottomAxis->AutomaticMaximum = false;
	_chart->BottomAxis->AutomaticMinimum = false;
	_chart->BottomAxis->Axis->Width = 1;
	_chart->BottomAxis->ExactDateTime = false;
	_chart->BottomAxis->Increment = 1;
	_chart->BottomAxis->Maximum = _maxZones;
	_chart->BottomAxis->MaximumOffset = 1;
	_chart->BottomAxis->LabelsMultiLine = false;
	_chart->BottomAxis->MinorTicks->Visible = false;
	// _chart->DepthAxis->Automatic = false;
	// _chart->DepthAxis->AutomaticMaximum = false;
	// _chart->DepthAxis->AutomaticMinimum = false;
	// _chart->DepthAxis->ExactDateTime = false;
	// _chart->DepthAxis->Increment = 1;
	// _chart->DepthTopAxis->Automatic = false;
	// _chart->DepthTopAxis->AutomaticMaximum = false;
	// _chart->DepthTopAxis->AutomaticMinimum = false;
	// _chart->DepthTopAxis->ExactDateTime = false;
	// _chart->DepthTopAxis->Increment = 1;
	_chart->Emboss->Color = clLime;
    //serg 11
	//_chart->LeftAxis->Automatic = false;
	_chart->LeftAxis->Automatic = true;
	//_chart->LeftAxis->AutomaticMaximum = false;
	//_chart->LeftAxis->AutomaticMinimum = false;
	_chart->LeftAxis->AxisValuesFormat = "#,##";
	_chart->LeftAxis->ExactDateTime = false;
	//_chart->LeftAxis->LabelsMultiLine = true;
	_chart->LeftAxis->LabelsMultiLine = false;
	_chart->LeftAxis->LabelsOnAxis = false;
	_chart->LeftAxis->MinorTicks->Visible = false;
	_chart->Pages->AutoScale = true;
	// _chart->Pages->MaxPointsPerPage = 8;
	_chart->RightAxis->Automatic = false;
	_chart->RightAxis->AutomaticMaximum = false;
	_chart->RightAxis->AutomaticMinimum = false;
	_chart->RightAxis->Visible = false;
	_chart->Shadow->Color = clRed;
	_chart->Shadow->Visible = false;
	_chart->TopAxis->Automatic = false;
	_chart->TopAxis->AutomaticMaximum = false;
	_chart->TopAxis->AutomaticMinimum = false;
	_chart->TopAxis->Visible = false;
	_chart->View3D = false;
	_chart->Zoom->Allow = false;
	_chart->Align = alClient;
	_chart->BevelOuter = bvNone;
	// series
	_chart->SeriesList->Clear();
	for (int i = 0; i < _countSensors; i++) {
		TBarSeries* series = new TBarSeries(_chart);
		// TChartSeries* series = new TChartSeries(_chart);
		series->Depth = 0;
		series->ColorEachPoint = true;
		series->Marks->Visible = false;
		series->Marks->Arrow->Visible = false;
		series->Marks->Callout->Brush->Color = clBlack;
		series->Marks->Callout->Arrow->Visible = false;
		series->Marks->Margins->Left = 44;
		series->ShowInLegend = false;
		series->AutoMarkPosition = false;
		series->BarRound = brNone;
		// series->AutoRepaint = false;
		// ---------------------------дополнительные
		// int a = series->BarWidth;
		if (_maxZones < 50) {
			series->CustomBarWidth = 60; // ширина метки в пикселах
		}
		else {
			series->CustomBarWidth = 30;
		}
		if (_maxZones < 25) {
			series->CustomBarWidth = 90; // ширина метки в пикселах
		}
		else {
			series->CustomBarWidth = 65;
		}
		if (_maxZones < 15) {
			series->CustomBarWidth = 120; // ширина метки в пикселах
		}
		else {
			series->CustomBarWidth = 85;
		}
		// series->BarWidthPercent = 50; //в процентах работает криво
		series->BarStyle = bsRectangle; // примитив метки
		// градиент нафиг, ибо записывается цвет криво
		 series->BarStyle = bsRectGradient;
		// series->BarWidthPercent = 100;
		// series->CustomHorizAxis=
		// ---------------------------дополнительные
		series->Dark3D = false;
		series->MarksOnBar = true;
		series->MultiBar = mbStacked;
		series->OffsetPercent = 50;
		series->Shadow->Visible = false;
		series->YOrigin = 3.0;
		series->XValues->Name = "X";
		series->Emboss->Color = clWhite; //
		series->Emboss->HorizSize = 4;
		series->SideMargins = false;
		series->XValues->Order = loAscending;
		series->YValues->Name = "Bar";
		series->YValues->Order = loNone;
		// ---------------------------дополнительные
		series->Emboss->Visible = true;
		// series->BarWidthPercent = 5;
		// series->CustomBarWidth=1;
		// Series1->CustomBarWidth
		// series->Shadow->HorizSize = 4;
		// series->Shadow->VertSize = 5;
		// привязка событий к серии
		// series->OnClick=_chart->
		// series->OnDblClick = _chart->;
		// -----------------
		_chart->AddSeries(series);
	}
	err = _chart->SeriesCount();
	_chart->LeftAxis->Minimum = 0;
	_chart->LeftAxis->Maximum = _countSensors + 1;
	_chart->Axes->Behind = false;
	// _chart->LeftAxis->Maximum = 1;
	_chart->Refresh();
}


void TExtFunction::PrepareFastLineChart(int _countSensors, int _maxX, int _maxY, int _minY, TChart* _chart) {
	_chart->BackWall->Color = clBtnFace;
	_chart->BackWall->Transparent = false;
	_chart->BottomWall->Visible = false;
	_chart->Foot->AdjustFrame = false;
	_chart->Foot->Alignment = taLeftJustify;
	_chart->Foot->Visible = false;
	_chart->LeftWall->Visible = false;
	_chart->Legend->Visible = false;
	_chart->MarginBottom = 0;
	_chart->MarginLeft = 0;
	_chart->MarginRight = 5;
	_chart->MarginTop = 0;
	_chart->MarginUnits = muPixels;
	_chart->PrintProportional = false;
	_chart->SubFoot->Alignment = taLeftJustify;
	_chart->SubFoot->Visible = false;
	_chart->SubTitle->Alignment = taLeftJustify;
	_chart->SubTitle->Visible = false;
	_chart->Title->Alignment = taLeftJustify;
	// убрать прокрутку по колесу мыши
	// _chart->AllowPanning = Vcltee::Teeprocs::pmNone;
	_chart->AllowPanning = Teeprocs::pmNone;
	// _chart->Title->Text = (L"");
	_chart->Title->Visible = false;
	_chart->BottomAxis->Automatic = false;
	_chart->BottomAxis->AutomaticMaximum = false;
	_chart->BottomAxis->AutomaticMinimum = false;
	_chart->BottomAxis->Axis->Width = 1;
	_chart->BottomAxis->ExactDateTime = false;
	_chart->BottomAxis->Increment = 1;
	_chart->BottomAxis->Maximum = _maxX;
	_chart->BottomAxis->MaximumOffset = 1;
	_chart->LeftAxis->Maximum = _maxY;
	_chart->LeftAxis->Minimum = _minY;

	// _chart->BottomAxis->MinorTickCount = 0;
	// _chart->DepthAxis->Automatic = false;
	// _chart->DepthAxis->AutomaticMaximum = false;
	// _chart->DepthAxis->AutomaticMinimum = false;
	// _chart->DepthAxis->ExactDateTime = false;
	// _chart->DepthAxis->Increment = 1;
	// _chart->DepthTopAxis->Automatic = false;
	// _chart->DepthTopAxis->AutomaticMaximum = false;
	// _chart->DepthTopAxis->AutomaticMinimum = false;
	// _chart->DepthTopAxis->ExactDateTime = false;
	// _chart->DepthTopAxis->Increment = 1;
	_chart->Emboss->Color = clLime;
	_chart->LeftAxis->Automatic = false;
	_chart->LeftAxis->AutomaticMaximum = false;
	_chart->LeftAxis->AutomaticMinimum = false;
	_chart->LeftAxis->AxisValuesFormat = "#,##";
	_chart->LeftAxis->ExactDateTime = false;
	_chart->LeftAxis->LabelsMultiLine = true;
	_chart->LeftAxis->LabelsOnAxis = false;
	_chart->LeftAxis->MinorTicks->Visible = false;
	_chart->Pages->AutoScale = true;
	// _chart->Pages->MaxPointsPerPage = 8;
	_chart->RightAxis->Automatic = false;
	_chart->RightAxis->AutomaticMaximum = false;
	_chart->RightAxis->AutomaticMinimum = false;
	_chart->RightAxis->Visible = false;
	_chart->Shadow->Color = clRed;
	_chart->Shadow->Visible = false;
	_chart->TopAxis->Automatic = false;
	_chart->TopAxis->AutomaticMaximum = false;
	_chart->TopAxis->AutomaticMinimum = false;
	_chart->TopAxis->Visible = false;
	_chart->View3D = false;
	_chart->Zoom->Allow = false;
	_chart->Align = alClient;
	_chart->BevelOuter = bvNone;
	// series
	_chart->SeriesList->Clear();
	for (int i = 0; i < _countSensors; i++) {
		TFastLineSeries* series = new TFastLineSeries(_chart);
		// TChartSeries* series = new TChartSeries(_chart);
		series->Depth = 0;
		series->ColorEachPoint = true;
		series->Marks->Visible = false;
		series->Marks->Arrow->Visible = false;
		series->Marks->Callout->Brush->Color = clBlack;
		series->Marks->Callout->Arrow->Visible = false;
		series->Marks->Margins->Left = 44;
		series->ShowInLegend = true;
		// series->AutoRepaint = false;

		// градиент нафиг, ибо записывается цвет криво
		// series->BarStyle = bsRectGradient;
		// series->BarWidthPercent = 100;
		// series->CustomHorizAxis=
		// ---------------------------дополнительные
		// series->Dark3D = false;
		// series->MarksOnBar = true;
		// series->MultiBar = mbStacked;
		// series->OffsetPercent = 50;
		// series->Shadow->Visible = false;
		// series->YOrigin = 3.0;
		series->XValues->Name = "X";
		series->XValues->Order = loAscending;
		series->YValues->Name = "Bar";
		series->YValues->Order = loNone;
		// ---------------------------дополнительные
		// series->BarWidthPercent = 5;
		// series->CustomBarWidth=1;
		// Series1->CustomBarWidth
		// series->Shadow->HorizSize = 4;
		// series->Shadow->VertSize = 5;
		// привязка событий к серии
		// series->OnClick=_chart->
		// series->OnDblClick = _chart->;
		// -----------------
		_chart->AddSeries(series);
	}
	_chart->LeftAxis->Minimum = 0;
	_chart->LeftAxis->Maximum = _countSensors + 1;
	_chart->Axes->Behind = false;
	// _chart->LeftAxis->Maximum = 1;
	_chart->Refresh();
}

// лучше, конечно пользовать параметры
// записываем измерения по цветам в базу
int TExtFunction::SaveChartToDB(AnsiString _serialTubeNum, AnsiString _tubeNum, int _codeTubeTypeSize, int _moduleType, int _maxZones, int _codeCustomer, int _codeOperatorU,
	int _codeStatusTube, TChart* _chart) {
	int err = -1;
	int chCount = _chart->SeriesCount();
	TDateTime currentDT;
	// гребаный амеровский формат даты!!!
	AnsiString strCurrentDT = FormatDateTime("yyyy/dd/mm hh:mm:ss", currentDT.CurrentDateTime());
	try {
		for (int s = 0; s < chCount; s++) { // серии
			AnsiString strSQL = "";
			strSQL = "insert into SavedTube ";
			strSQL +=
				"(serialTubeNum,TubeNUM,codeTubeTypeSize,tubeModule, sensorNum,saveDataTime,codeStatusTube,codeCustomer,codeOperatorU,maxZones,Zone0,Zone1,Zone2,Zone3,Zone4,Zone5";
			strSQL += ",Zone6,Zone7,Zone8,Zone9,Zone10,Zone11,Zone12,Zone13,Zone14,Zone15,Zone16,Zone17,Zone18,Zone19,Zone20,Zone21,Zone22,Zone23";
			strSQL += ",Zone24,Zone25,Zone26,Zone27,Zone28,Zone29,Zone30,Zone31,Zone32,Zone33,Zone34,Zone35,Zone36,Zone37";
			strSQL += ",Zone38,Zone39,Zone40,Zone41,Zone42,Zone43,Zone44,Zone45,Zone46,Zone47,Zone48,Zone49,Zone50,Zone51,Zone52,Zone53";
			strSQL += ",Zone54,Zone55,Zone56,Zone57,Zone58,Zone59,Zone60,Zone61,Zone62,Zone63,Zone64,Zone65,Zone66,Zone67,Zone68,Zone69";
			strSQL += ",Zone70,Zone71,Zone72,Zone73,Zone74,Zone75,Zone76,Zone77,Zone78,Zone79,Zone80,Zone81,Zone82,Zone83,Zone84,Zone85";
			strSQL += ",Zone86,Zone87,Zone88,Zone89,Zone90,Zone91,Zone92,Zone93,Zone94,Zone95,Zone96,Zone97,Zone98,Zone99) VALUES (";
			// значения полей
			strSQL += "'" + _serialTubeNum + "'";
			strSQL += ",'" + _tubeNum + "'";
			strSQL += ",";
			strSQL += IntToStr(_codeTubeTypeSize);
			strSQL += ",";
			strSQL += IntToStr(_moduleType); ;
			strSQL += ",";
			strSQL += IntToStr(s);
			strSQL += ",";
			strSQL += "CAST('" + strCurrentDT + "' as datetime)";
			strSQL += "," + IntToStr(_codeTubeTypeSize);
			strSQL += "," + IntToStr(_codeCustomer);
			strSQL += "," + IntToStr(_codeOperatorU);
			strSQL += ",";
			strSQL += IntToStr(_maxZones);
			strSQL += ",";
			for (int z = 0; z < 99; z++) { // зоны записываем цвета из чарта
				if (z > _maxZones) {
					strSQL += IntToStr(clWhite);
				}
				else {
					strSQL += _chart->Series[s]->ValueColor[z];
				}
				strSQL += ",";
			}
			// последняя зона
			if (_maxZones < 100) {
				strSQL += IntToStr(clWhite);
			}
			else {
				strSQL += _chart->Series[s]->ValueColor[99];
			}
			strSQL += ")";
			SqlDBModule->ExecStrSql(strSQL);
			err = 0;
		}
	}
	catch (Exception *ex) {
		err = -2;
		// TLog::SaveStrLog(ex->Message);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
	return err;
}

// int(*_arrDataModule)[8][100]
int TExtFunction::FillArrayModule(AnsiString _tubeNum, int _tubeModule, int _maxZones, int _countSensors, int _arrDataModule[8][100]) {
	int err = -1;
	int rec = 0;
	AnsiString msg;
	try {
		// получим данные по сохраненной трубе
		SqlDBModule->ADOQueryDB->Close();
		AnsiString strSql = "select rec_id,tubeNUM,codeTubeTypeSize,codeStatusTube,codeCustomer,codeOperatorU,TubeModule,sensorNum";
		for (int z = 0; z < _maxZones; z++) {
			strSql += ",zone" + IntToStr(z);
		}
		strSql += " FROM SavedTube where";
		strSql += " TubeNUM='" + _tubeNum + "'";
		strSql += " and TubeModule=" + IntToStr(_tubeModule);
		strSql += " order by tubeNUM,TubeModule,sensorNum";
		SqlDBModule->ADOQueryDB->SQL->Text = strSql;
		SqlDBModule->ADOQueryDB->Open();
		err = SqlDBModule->ADOQueryDB->RecordCount;
		if (err != _countSensors) {
			err = -33;
			msg = "Ошибка чтения данных по датчикам из БД!!!";
			TLog::SaveStrMsgLog(msg);
		}
		else {
			//
		}
		int s = 0; // номер датчика
		while (!SqlDBModule->ADOQueryDB->Eof) {
			// бежим по записям, как по датчикам, а по полям, как по зонам
			for (int z = 0; z < _maxZones; z++) // номер зоны
			{
				rec = SqlDBModule->ADOQueryDB->FieldByName("rec_id")->AsInteger;
				_arrDataModule[s][z] = SqlDBModule->ADOQueryDB->FieldByName("zone" + IntToStr(z))->AsInteger;
				// проверка
				// if (_tubeModule == 2 && z == 3 && s == 3) {
				// int a = _arrDataModule[s][z];
				// int b = _arrDataModule[s][z];
				// }
				// else {
				// }
			}
			SqlDBModule->ADOQueryDB->Next();
			s++;
		}
		err = 0;
		// // иммитация дефекта
		// switch (_tubeModule) {
		// case 1: {
		// _arrDataModule[0][0] = clRed;
		// _arrDataModule[1][1] = clRed;
		// break;
		// }
		// case 2: {
		// _arrDataModule[0][0] = clRed;
		// _arrDataModule[1][1] = clYellow;
		// break;
		// }
		// case 5: {
		// _arrDataModule[0][0] = clRed;
		// _arrDataModule[1][1] = clFuchsia;
		// break;
		// }
		// default:
		// //
		// break;
		// }
	}
	catch (Exception *ex) {
		err = -2;
		TLog::ErrFullSaveLog(ex);
		// +MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
	return err;
}

int TExtFunction::ShowArrayModule(int _countSensors, int _maxZones, int _arrDataModule[8][100], TChart* _chart) {
	for (int s = 0; s < _countSensors; s++) { // серии
		for (int z = 0; z < _maxZones; z++) { // шаги
			if (z < _maxZones) {
				_chart->Series[s]->AddXY(z, 1, "", TColor(_arrDataModule[s][z]));
			}
			else {
				_chart->Series[s]->AddXY(z, 1, "", clWhite);
			}
		};
	};
}

int TExtFunction::UpdateStatusBar(TStatusBar *_StatusBar, AnsiString _strTitle, AnsiString _strText, TColor _colorFont) {
	int err = 0;
	// messColor = _colorFont;
	_StatusBar->Panels->Items[0]->Text = _strTitle;
	_StatusBar->Panels->Items[1]->Text = _strText;
	_StatusBar->Refresh();
	return err;
}

int TExtFunction::UpdateLabelStatus(TLabel *_label, AnsiString _strTitle, AnsiString _strText, TColor _colorFont) {
	int err = -1;
	try {
		_label->Caption = _strTitle + ": " + _strText;
		_label->Font->Color = _colorFont;
		_label->Refresh();
	}
	catch (Exception *ex) {
		err = -2;
		TLog::SaveStrMsgLog(ex->Message);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
	return err;
}

int TExtFunction::ShowBigModalMessage(AnsiString _strMsg, TColor _color) {
	// TfmMessage* fmMsg = static_cast<TfmMessage*>(_msgFm);
	fmMessage = new TfmMessage(NULL, _strMsg, _color);
	fmMessage->ShowModal();
	delete fmMessage;
}

void TExtFunction::FATAL(AnsiString _msg) {
	// WideString w = _msg;
	// Application->MessageBoxW(w.c_bstr(), L"Аварийное завершение", MB_ICONERROR | MB_OK);
	fmMessage = new TfmMessage(NULL, _msg, clRed);
	fmMessage->ShowModal();
	delete fmMessage;
	throw;
}

void TExtFunction::PrepareChartToTst(TChart *chart, int _countChLog, int _lengthChart, int _maxYChart) {
	// настраиваем чарт
	// вырубаем 3Д
	chart->View3D = false;
	chart->View3DWalls = false;
	// вырубаем автоматику
	// chart->AutoRepaint = false;
	chart->BottomAxis->Automatic = false;
	// chart->BottomAxis->Automatic = true;
	chart->BottomAxis->AutomaticMaximum = false;
	if (_lengthChart != 0) {
		chart->BottomAxis->AutomaticMaximum = false;
	}
	else {
		chart->BottomAxis->AutomaticMaximum = true;
	}
	if (_maxYChart != 0) {
		chart->LeftAxis->Automatic = false;
		chart->LeftAxis->AutomaticMaximum = false;
		chart->LeftAxis->AutomaticMinimum = false;
		chart->RightAxis->Automatic = false;
		chart->RightAxis->AutomaticMaximum = false;
		chart->RightAxis->AutomaticMinimum = false;
	}
	else {
		chart->LeftAxis->Automatic = true;
		chart->LeftAxis->AutomaticMaximum = true;
		chart->LeftAxis->AutomaticMinimum = true;
		chart->RightAxis->Automatic = true;
		chart->RightAxis->AutomaticMaximum = true;
		chart->RightAxis->AutomaticMinimum = true;
	}
	// контуры чарта, отступы от края
	// и где бля, присвоение размера?
	// chart->Border->Color = clGreen;
	// chart->Border->Width = 3;
	// chart->Border->Visible = true;
	chart->MarginBottom = 1;
	chart->MarginLeft = 1;
	chart->MarginRight = 1;
	chart->MarginTop = 1;
	chart->MarginUnits = muPixels;
	// цвет фона, видимость координатных линий
	// chart->Color = clMedGray;
	chart->Color = clBtnFace;
	chart->AxisVisible = true;
	// число точек   по вертикали, оси
	if (_maxYChart != 0) {
		chart->LeftAxis->Minimum = -_maxYChart;
		chart->LeftAxis->Maximum = _maxYChart;
		chart->LeftAxis->StartPosition = 1;
		chart->RightAxis->Minimum = -_maxYChart;
		chart->RightAxis->Maximum = _maxYChart;
		chart->RightAxis->StartPosition = 1;
	}
	chart->BottomAxis->Minimum = 0;
	chart->BottomAxis->MinimumOffset = 0; // смещение в начале
	// число точек   по горизонтали забьем, от балды
	if (_lengthChart != 0)
		chart->BottomAxis->Maximum = _lengthChart; // viewOffset;
	chart->Title->Text->Clear();
	chart->Title->Text->Add("Сигналы датчиков");
	// поведение мыши
	chart->Zoom->MouseButton = mbLeft;
	// chart->Zoom->MouseWheel = pmwNormal;
	// chart->ZoomWheel = pmwNormal;
	// настройка легенды
	chart->Legend->CheckBoxes = True;
	chart->Legend->LegendStyle = lsSeries;
	// chart->Legend->Alignment=laTop;
	chart->Legend->Alignment = laRight;
	chart->LeftAxis->PositionUnits = muPixels;
	chart->BackWall->Color = clBtnFace;
	chart->BackWall->Transparent = false;
	chart->BottomAxis->Increment = 0;
	chart->BottomAxis->LabelStyle = talValue;
	// дополнительные оси с помощью свойств StartPosition и EndPosition.
	// chart->BottomAxis->StartPosition = 1;
	// chart->BottomAxis->EndPosition = 100;
	chart->BottomAxis->Axis->Width = 1;
	chart->BottomAxis->ExactDateTime = false;
	chart->BottomAxis->Increment = 1;
	chart->LeftAxis->AxisValuesFormat = "#,##";
	// прокрутка разрешена в обоих направлениях
	chart->AllowPanning = pmBoth;
	// позволяет изменять во время выполнения масштаб изображения, вырезая фрагменты диаграммы или графика курсором мыши
	chart->Zoom->Allow = true;
	// chart->Zoom->Allow = false;
	// chart->Align = alClient;
	chart->BevelOuter = bvNone;
	// series
	chart->SeriesList->Clear();
	// currZoomPercent = 100;
	for (int i = 0; i < _countChLog + 1; i++) {
		// TLineSeries* series = new TLineSeries(ChartTest);
		TFastLineSeries* series = new TFastLineSeries(chart);
		// TFastLineSeries* series = new TFastLineSeries(ChartTest);
		// TChartSeries* series = new TChartSeries(ChartTest);
		// series->HorizAxis = aTopAxis;
		// series->AutoRepaint = false;
		// series->AutoRepaint = false;
		// число дополнительных делений между основными
		// series->Depth = 5;
		series->ColorEachPoint = true;
		series->Marks->Visible = false;
		// скругленный
		// series->DrawStyle = dsCurve;
		// толщина линии
		series->LinePen->Width = 1;

		// series->Title=X+IntToStr(i);
		// series->Dark3D = false;
		// TColor colors[] = {clWhite, clBlack, clMaroon, clGreen, clOlive, clNavy, clPurple, clTeal, clSilver, clRed, clLime, clYellow, clBlue, clAqua, clFuchsia, clCream};
		// if (i < 16) {
		// series->Color = colorsLine[i];
		// }
		// else {
		// series->Color = colorsLine[i - 16];
		// }
		chart->AddSeries(series);
		// нафига нам ось в легенде
		if (i < _countChLog) {
			series->Title = "Вход АЦП: " + IntToStr(i);
			series->ShowInLegend = true;
		}
		else {
			series->ShowInLegend = false;
			series->Color = clBlack;
			series->LinePen->Width = 3;
		}
		// series->Title += " Мюнхаузен"
	}
	// chart->Repaint();
	// chart->Refresh();
	// chart->Series[0]->Title += " Скачки";
	// chart->Series[1]->Title += " Напряжение";
	// chart->Series[2]->Title += " Ток";
}

double TExtFunction::MedianFilter3(double _data0, double _data1, double _data2) {
	try {
		// return middle;

		double middle = 0;
		double a = _data0;
		double b = _data1;
		double c = _data2;
		if ((a <= b) && (a <= c)) {
			middle = (b <= c) ? b : c;
		}
		else if ((b <= a) && (b <= c)) {
			middle = (a <= c) ? a : c;
		}
		else {
			middle = (a <= b) ? a : b;
		}
		return middle;
	}
	catch (Exception *ex) {
		TLog::ErrFullSaveLog(ex);
		TExtFunction::ShowBigModalMessage(ex->Message, clRed);
		// MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
}

double TExtFunction::MedianFilter5(double _data0, double _data1, double _data2, double _data3, double _data4) {
	try {
		// return middle;
		for (int i = 0; i < 5; i++) {

		}
	}
	catch (Exception *ex) {
		TLog::ErrFullSaveLog(ex);
		TExtFunction::ShowBigModalMessage(ex->Message, clRed);
		// MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
}

int TExtFunction::GetIP_MAC(AnsiString &_strIp4) {
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
						_strIp4 = inet_ntoa(*(reinterpret_cast<in_addr*>(*(h->h_addr_list))));
				// GetAdaptersInfo.
				else
					// MessageBox(0, "Вы не в сети. И IP адреса у вас нет.", 0, 0);
						_strIp4 = "Вы не в сети. И IP адреса у вас нет.";
				// MessageDlg("Вы не в сети. И IP адреса у вас нет.", mtError, TMsgDlgButtons() << mbOK, NULL);
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
}

int TExtFunction::PrintGrid(AnsiString _title, TStringGrid *_grid, TPrinter* _printer, TPrinterOrientation _orientation, int _beginPrinterXPx, int _beginPrinterYPx,
	int countColPerPage, bool _isPrinting) {
	int err = 0;
	int P, I, J, YPos, XPos, HorzSize, vertSize, horzSizeDisp;
	int AnzSeiten, Seite, rowCount, HeaderSize, FooterSize, rowSize, FontHeight;
	double mmx, mmy, mmXD, mmYD, mmD;
	AnsiString Footer;
	try {
		// Верхний колонтитул, нижний колонтитул, межстрочный интервал, размер шрифта
		HeaderSize = 100;
		FooterSize = 200;
		rowSize = 18;
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
		mmx = GetDeviceCaps(_printer->Canvas->Handle, PHYSICALWIDTH) / GetDeviceCaps(_printer->Canvas->Handle, LOGPIXELSX) * 25.4; // точек на мм
		mmy = GetDeviceCaps(_printer->Canvas->Handle, PHYSICALHEIGHT) / GetDeviceCaps(_printer->Canvas->Handle, LOGPIXELSY) * 25.4;
		// mmD = fmShowZones->PixelsPerInch / 25.4;
		//
		vertSize = (int)(mmy) * 10; // размер в 0,1 мм
		HorzSize = (int)(mmx) * 10;
		// horzSizeDisp=fmShowZones->Width*mmD;
		SetMapMode(_printer->Canvas->Handle, MM_LOMETRIC);
		//
		// Задайте количество строк
		rowCount = (int)(vertSize - HeaderSize - FooterSize) / rowSize; // div Любой остаток отвергается. Mod  Выполняет целочисленное деление, возвращая остаток
		// Определите количество страниц
		if (_grid->RowCount % rowCount != 0) {
			AnzSeiten = (int)_grid->RowCount / rowCount + 1;
		}
		else {
			AnzSeiten = _grid->RowCount / rowCount;
		}
		//
		Seite = 1;
		// Сетка для печати
		for (int P = 1; P <= AnzSeiten; P++) {
			// //заголовок
			_printer->Canvas->Font->Height = 24;
			_printer->Canvas->TextOut((HorzSize / 2 - (_printer->Canvas->TextWidth(_title) / 2)), -20, _title);
			_printer->Canvas->Pen->Width = 5;
			_printer->Canvas->MoveTo(0, -HeaderSize);
			_printer->Canvas->LineTo(HorzSize, -HeaderSize);
			// //низ
			_printer->Canvas->MoveTo(0, -vertSize + FooterSize);
			_printer->Canvas->LineTo(HorzSize, -vertSize + FooterSize);
			_printer->Canvas->Font->Height = 24;
			Footer = "Страница: " + IntToStr(Seite) + " из " + IntToStr(AnzSeiten);
			_printer->Canvas->TextOut((HorzSize / 2 - (_printer->Canvas->TextWidth(Footer) / 2)), -vertSize + 150, Footer);
			///Печатные линии
			_printer->Canvas->Font->Height = FontHeight;
			YPos = HeaderSize + 10;
			for (int I = 1; I < rowCount; I++) {
				if (_grid->RowCount >= I + (Seite - 1) * rowCount) {
					XPos = 10;
					for (J = 0; J < _grid->ColCount - 1; J++) {
						_printer->Canvas->TextOut(XPos, -YPos, _grid->Cells[J][I + (Seite - 1) * rowCount - 1]);
						XPos = XPos + _grid->ColWidths[J] * 2;
						if (HorzSize - XPos + _grid->ColWidths[J] * 2 < 0) {
							YPos = YPos + (rowSize + 1) * _grid->RowCount;
							break;
						}
						else {

						}
					}
					YPos = YPos + rowSize;
				}
				else {
					//
				}
			}
			// //Добавить страницу
			Seite++;
			if (Seite <= AnzSeiten) {
				_printer->NewPage();
			}
			else {
				//
			}
		}
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

// int TExtFunction::LoadTubeCrossFromFile(AnsiString _fullFileName,short &zones,short &sensors_a,vector<int> &VZoneLength,
// DynamicArray<double> &zone_data,vector<vector<double> > &sensor_data, vector<vector<vector<double> > > &Source_Data) {
int TExtFunction::LoadTubeCrossFromFile(AnsiString _fullFileName, AnsiString _head, short &zones, short &sensors_a, vector<int> &VZoneLength, DynamicArray<double> &zone_data,
	vector<vector<double> > &sensor_data, vector<vector<vector<double> > > &Source_Data) {
	// Формат файла bindkb
	// 4 байта - длина имени пользователя
	// 1 байт[] – имя пользователя
	// 4 байта длина имени типоразмера
	// 1 байт [] – имя типоразмера
	// Поперечный
	// 2 байта  - количество датчиков
	// 8 байт[]  - усиление по количеству датчиков
	// 2 байта  - количество порогов
	// 8 байт[]  - пороги
	// 4 байта – мертвая зона в начале
	// 4 байта - мертвая зона в конце
	int err = -1;
	int binFileHandle = -1;
	FILE* df;
	try {
		try {
			df = fopen(_fullFileName.c_str(), "rb");
			if (df == NULL) {
				Application->MessageBoxW(L"Не удалось загрузить файл", L"Ошибка", MB_ICONERROR | MB_OK);
				return -1;
			}
			// LoadSettings();
			// Singleton->Load(df);
			if (_head != NULL) {
				// title += ", ";
				// title += _head;
			}
			//-------
			//имя пользователя и прочая муть
            LoadINI(df);
			//---
			Fread(&zones, sizeof(zones), 1, df);
			Fread(&sensors_a, sizeof(sensors_a), 1, df);
			for (int z = 0; z < zones; z++) {
				Fread(&zone_data[z], sizeof(zone_data[z]), 1, df);
				Fread(&VZoneLength[z], sizeof(VZoneLength[z]), 1, df);
				int a=sensor_data[0].size();
				//a=sensor_data[0][0].size();
				for (int s = 0; s < sensors_a; s++) {
					Fread(&sensor_data[z][s], sizeof(sensor_data[z][s]), 1, df);
					int size;
					Fread(&size, sizeof(size), 1, df);
					for (int m = 0; m < size; m++) {
						Source_Data[z][s].resize(size);
						Fread(&Source_Data[z][s][m], sizeof(Source_Data[z][s][m]), 1, df);
					}
				}
			}
			return 0;

		}
		catch (Exception *ex) {
			err = -20;
			TLog::ErrFullSaveLog(ex);
			MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);

		}
	}
	__finally {
		fclose(df);
		if (binFileHandle > 0) {
			FileClose(binFileHandle);
		}
		else {
			//
		}
	}
	return err;
}

void TExtFunction::Fread(void* _buf, int _size, int _n, FILE* _df) {
	int err = 0;
	err = fread(_buf, _size, _n, _df);
	if (err != _n) {
		if (feof(_df)) {
			fpos_t pos;
			fgetpos(_df, &pos);
			AnsiString a = "Fread: Неожиданный конец файла: ";
			a += pos;
			throw(Exception(a));
		}
		else
			throw(Exception("Fread: Неизвестная ошибка"));
	}
}

int TExtFunction::LoadINI(FILE* _df) {
	int size;
	char* s;
	double dval;
	int ival;
	short sval;
	bool bval;
    int err=0;
	try {
    // 4 байта - длина имени пользователя
	// 1 байт[] – имя пользователя
		fread(&size, sizeof(size), 1, _df);
		s = new char[size];
		fread(s, size, 1, _df);
		s[size] = '\0';
		AnsiString user = s;
		delete s;
	// 4 байта длина имени типоразмера
	// 1 байт [] – имя типоразмера
		Fread(&size, sizeof(size), 1, _df);
		s = new char[size + 1];
		Fread(s, size, 1, _df);
		s[size] = '\0';
		AnsiString lTypeSize = s;
		delete s;
		// ini->WriteString("Default", "TypeSize", lTypeSize);
		AnsiString sect = "Type_";
		sect += lTypeSize;
		//количество датчиков поперечника
		Fread(&sval, sizeof(sval), 1, _df);
		// ini->WriteInteger(sect, "CrossSensors", sval);
		//усиление по датчикам
		for (int s = 0; s < sval; s++) {
			Fread(&dval, sizeof(dval), 1, _df);
			AnsiString name = "Gain";
			name += s;
			//ini->WriteFloat(sect, name, dval);
		}
		//пороги поперечника
		Fread(&size, sizeof(size), 1, _df);
		for (int i = 0; i < 2; i++) {
			if (i < size)
				fread(&dval, sizeof(dval), 1, _df);
			else
				dval = 0;
			AnsiString name = "CrossBorder";
			name += i + 1;
			//ini->WriteFloat(sect, name, dval);
		}
		//мертвые зоны
		Fread(&ival, sizeof(ival), 1, _df);
		// ini->WriteInteger(sect, "CrossDeadZoneStart", ival);
		Fread(&ival, sizeof(ival), 1, _df);
		// ini->WriteInteger(sect, "CrossDeadZoneFinish", ival);
		//количество датчиков продольника
		Fread(&sval, sizeof(sval), 1, _df);
		// ini->WriteInteger(sect, "LineSensors", sval);
		//усиление продольника
		for (int s = 0; s < sval; s++) {
			Fread(&dval, sizeof(dval), 1, _df);
			AnsiString name = "Gain";
			name += s;
			//ini->WriteFloat("PR", name, dval);
		}
		Fread(&size, sizeof(size), 1, _df);
        //пороги продольника
		for (int i = 0; i < 2; i++) {
			if (i < size)
				fread(&dval, sizeof(dval), 1, _df);
			else
				dval = 0;
			AnsiString name = "LinearBorder";
			name += i + 1;
			//ini->WriteFloat(sect, name, dval);
		}
		//внутренние пороги
		Fread(&size, sizeof(size), 1, _df);
		for (int i = 0; i < 2; i++) {
			if (i < size)
				fread(&dval, sizeof(dval), 1, _df);
			else
				dval = 0;
			AnsiString name = "LinearBorder";
			name += i + 1;
			name += "Inner";
			//ini->WriteFloat(sect, name, dval);
		}
		Fread(&ival, sizeof(ival), 1, _df);
		// ini->WriteInteger(sect, "LinearDeadZoneStart", ival);
		Fread(&ival, sizeof(ival), 1, _df);
		// ini->WriteInteger(sect, "LinearDeadZoneFinish", ival);

		Fread(&size, sizeof(size), 1, _df);
        //пороги толщиномера
		for (int i = 0; i < size; i++) {
			Fread(&dval, sizeof(dval), 1, _df);
			AnsiString name = "ThicknessBorder";
			name += i + 1;
			//ini->WriteFloat(sect, name, dval);
		}
		Fread(&sval, sizeof(sval), 1, _df);
		// ini->WriteInteger(sect, "Min_Good_Length", sval);
		//Filters::Settings FC = Filters::Settings("Pp");
		//FC.Load(_df);
		fpos_t pos;
		fgetpos(_df, &pos);
		LoadFilters(_df);
		fgetpos(_df, &pos);
		//FC.Save(ini);
		//Filters::Settings FLI = Filters::Settings("PrIn");
		//FLI.Load(_df);
		LoadFilters(_df);
		fgetpos(_df, &pos);
		//FLI.Save(ini);
		//Filters::Settings FLO = Filters::Settings("PrOut");
		//FLO.Load(_df);
		LoadFilters(_df);
		fgetpos(_df, &pos);
		//FLO.Save(ini);
		Fread(&ival, sizeof(int), 1, _df);
		fgetpos(_df, &pos);
		// ini->WriteInteger("OtherSettings", "WidthMedianFilter", ival);
		Fread(&bval, sizeof(bool), 1, _df);
		fgetpos(_df, &pos);
		// ini->WriteBool("OtherSettings", "isMedianFilter", bval);
		//_df
		err = 0;
		return (err);
	}
	catch (Exception *ex) {
		TLog::ErrFullSaveLog(ex);
		// AnsiString msg
		// programSettings.colorMSG = programSettings.colorBrak;
		// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
		// TExtFunction::UpdateLabelStatus(programSettings.gsStatusLabel, strStatus, _msg, programSettings.colorMSG);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
        err=-1;
	}
	return err;
}

int TExtFunction::LoadFilters(FILE* _df){
   int err=0;
	bool isFilter;
	filterTypes CurrentType;
	filterSubTypes CurrentSubType;
	int order;
	double sampleRate;
	double cutoffFrequency;
	double centerFrequency;
	double widthFrequency;
	double rippleDb;
	double rolloff;
try{
	fpos_t pos;
	fgetpos(_df, &pos);
  	Fread(&isFilter,sizeof(isFilter),1,_df);
	Fread(&CurrentType,sizeof(CurrentType),1,_df);
	Fread(&CurrentSubType,sizeof(CurrentSubType),1,_df);
	Fread(&order,sizeof(order),1,_df);
	Fread(&cutoffFrequency,sizeof(cutoffFrequency),1,_df);
	Fread(&widthFrequency,sizeof(widthFrequency),1,_df);
	Fread(&centerFrequency,sizeof(centerFrequency),1,_df);
	Fread(&rippleDb,sizeof(rippleDb),1,_df);
	Fread(&rolloff,sizeof(rolloff),1,_df);
	Fread(&sampleRate,sizeof(sampleRate),1,_df);
	fgetpos(_df, &pos);
	err=0;
}	catch (Exception *ex) {
		TLog::ErrFullSaveLog(ex);
		err=-1;
		// AnsiString msg
		// programSettings.colorMSG = programSettings.colorBrak;
		// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
		// TExtFunction::UpdateLabelStatus(programSettings.gsStatusLabel, strStatus, _msg, programSettings.colorMSG);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}
	return err;
}

int TExtFunction::GetDataCross(TChart *_chart,int _numFusion, int _numTube,int _countZones, int _countSensors,double _thresholdC1,double _thresholdC2) {

	AnsiString strSql = "";
	int err = 0;
	int itmp = 0;
	std::vector<double>::iterator result;
	int indMax;
	AnsiString strTmp = "";
	int countNulls = 0;
	AnsiString strWhere;
	int countBrak=0;
	double valBborder1;
	double valBborder2;
	vector<double>vecMaxCh;
	vector<vector<double> >sensorsData;
	vector<double>dataFinal;;
	TChart *pChart;
//	try {
//		TChart* pChart = static_cast<TChart*>(_chart);
//		strWhere = "numFusion=" + IntToStr(_numFusion);
//		strWhere += " and ";
//		strWhere += " numTube= " + IntToStr(_numTube);
//		// пороги
//		strSql = "SELECT thresholdC1, thresholdC2";
//		strSql += " FROM numTube>0 and resultTubeShort where numTube=:pnumTube and numFusion=:pnumFusion order by numFusion,numTube";
//		SqlDBModule->queryForChart->Close();
//		SqlDBModule->queryForChart->SQL->Text = strSql;
//		SqlDBModule->queryForChart->Parameters->ParamByName("pnumTube")->Value = _numTube;
//		SqlDBModule->queryForChart->Parameters->ParamByName("pnumFusion")->Value = _numFusion;
//		SqlDBModule->queryForChart->Open();
//		valBborder1 = _thresholdC1;//SqlDBModule->queryForChart->FieldByName("thresholdC1")->AsFloat;
//		valBborder1 = _thresholdC2;//SqlDBModule->queryForChart->FieldByName("thresholdC2")->AsFloat;
//		// --------------
//		strSql = "SELECT numFusion, numTube";
//		for (int i = 0; i < _countZones; i++) {
//			strSql += ",Z" + IntToStr(i + 1);
//		}
//		strSql += ",sensorNum";
//		strSql += " FROM resultCross where numTube=:pnumTube and numFusion=:pnumFusion order by numFusion,numTube,sensorNum";
//		// по зонам поперечник
//		SqlDBModule->queryForChart->Close();
//		SqlDBModule->queryForChart->SQL->Text = strSql;
//		SqlDBModule->queryForChart->Parameters->ParamByName("pnumTube")->Value = _numTube;
//		SqlDBModule->queryForChart->Parameters->ParamByName("pnumFusion")->Value = _numFusion;
//		SqlDBModule->queryForChart->Open();
//		if (SqlDBModule->queryForChart->RecordCount == 0) {
//			MessageDlg("Данных по дефектам МНК2(C) нет!", mtWarning, TMsgDlgButtons() << mbOK, NULL);
//			_chart->Title->Text->Add("Данных по дефектам МНК2(C) нет!");
//			err = 0;
//			return err;
//		}
//		else {
//			//
//		}
//		// подготовим вектор
//		for (int i = 0; i < _countSensors; i++) {
//			vecMaxCh.push_back(0);
//		}
//		// заберем данные по поперечнику
//		SqlDBModule->queryForChart->First();
//		// while (!SqlDBModule->queryForChart->Eof) {
//		itmp = _countSensors;
//		for (int i = 0; i < _countSensors; i++) {
//			vector<double>vecTmp;
//			for (int z = 0; z < _countZones; z++) {
//				double val = 0;
//				AnsiString fn = "Z" + IntToStr(z + 1);
//				AnsiString strTmp = SqlDBModule->queryForChart->FieldByName("Z" + IntToStr(i + 1))->AsString;
//				if (strTmp == "") {
//					countNulls++;
//					val = 0;
//				}
//				else {
//					val = SqlDBModule->queryForChart->FieldByName("Z" + IntToStr(z + 1))->AsFloat;
//					if (val > 100) {
//						val = 100;
//					}
//					else {
//						//
//					}
//				}
//				vecTmp.push_back(val);
//			}
//			sensorsData.push_back(vecTmp);
//			SqlDBModule->queryForChart->Next();
//		}
//		SqlDBModule->queryForChart->Close();
//		// максимальное значание и заполнение конечного вектора
//		itmp = sensorsData.size();
//		itmp = sensorsData[0].size();
//		dataFinal.push_back(0); // иммитация сдвига
//		for (int i = 0; i < _countZones; i++) {
//			for (int j = 0; j < _countSensors; j++) {
//				vecMaxCh[j] = sensorsData[j][i];
//			}
//			result = std::max_element(vecMaxCh.begin(), vecMaxCh.end());
//			indMax = std::distance(vecMaxCh.begin(), result);
//			dataFinal.push_back(vecMaxCh[indMax]);
//		}
//		pChart->BottomAxis->Maximum = _countZones;
//		pChart->Series[0]->Clear();
//		pChart->Series[1]->Clear();
//		pChart->Series[2]->Clear();
//		pChart->Series[1]->Color = clRed;
//		pChart->Series[2]->Color = clYellow;
//		vecMaxCh.clear();
//		for (int i = 0; i < _countZones; i++) {
//			if (dataFinal[i] > 0) {
//				if (dataFinal[i] > valBborder1 && valBborder1 > 0) {
//					pChart->Series[0]->Add(dataFinal[i], "", clRed);
//					// Ahsistring strWhere=
//					//SqlDBModule->UpdIntSql("resultTubeShort", "resultC", -1, strWhere);
//					strTmp = "ДЕФЕКТ МНК2(C) ";
//					countBrak++;
//					//SqlDBModule->UpdIntSql("resultTubeShort", "countBrak", -1, strWhere);
//					// memoBrack->Lines->Add(strTmp);
//					strTmp += " Зона: " + IntToStr(i) + " (";
//					int ss = i * 100 - 100;
//					strTmp += IntToStr(i * 100 - 100);
//					strTmp += " - ";
//					strTmp += IntToStr((i + 1) * 100 - 100) + " мм)";
//					strTmp += " Предел: ";
//					strTmp += FloatToStr(valBborder1);
//					strTmp += "%";
//					strTmp += " Значение: ";
//					strTmp += FloatToStr(dataCross[i]);
//					strTmp += "%";
//					memoBrack->Lines->Add(strTmp);
//				}
//				else {
//					if (dataCross[i] > valBborder2 && valBborder2 > 0) {
//						chartCross->Series[0]->Add(dataFinal[i], "", clYellow);
//                        countBrak++;
//						//SqlDBModule->UpdIntSql("resultTubeShort", "resultC", countBrak, strWhere);
//						strTmp = "ДЕФЕКТ МНК2(C) ";
//						memoBrack->Lines->Add(strTmp);
//						// strTmp += " Зона: " + IntToStr(i) + " (";
//						int ss = i * 100 - 100;
//						strTmp += IntToStr(i * 100 - 100);
//						strTmp += " - ";
//						strTmp += IntToStr((i + 1) * 100 - 100) + " мм)";
//						strTmp += " Предел: ";
//						strTmp += FloatToStr(valBborder2);
//						strTmp += "%";
//						strTmp += " Значение: ";
//						strTmp += "%";
//						strTmp += FloatToStr(dataFinal[i]);
//						strTmp += "%";
//						memoBrack->Lines->Add(strTmp);
//					}
//					else {
//						pChart->Series[0]->Add(dataFinal[i], "", clGreen);
//					}
//				}
//			}
//			else {
//				pChart->Series[0]->Add(0, "", clBlack);
//			}
//			pChart->Series[1]->Add(valBborderC1, "", clRed);
//			chartCross->Series[2]->Add(valBborderC2, "", clYellow);
//		}
//		int aa=countBrak;
//		if (countNulls == _countZones*TGlSettings::countSensorsCross) {
//			chartCross->Title->Text->Add("Данных по дефектам МНК2(C) нет!");
//			chartCross->Series[0]->Clear();
//			chartCross->Series[1]->Clear();
//			chartCross->Series[2]->Clear();
//			chartCross->BottomAxis->Maximum = _countZones;
//			err = 3;
//			//SqlDBModule->UpdIntSql("resultTubeShort", "resultC", -1, strWhere);
//			// return err;
//		}
//		else {
//			//SqlDBModule->UpdIntSql("resultTubeShort", "resultC", countBrak, strWhere);
//		}
//		err = 0;
//		return err;
//	}
//	catch (Exception *ex) {
//		err = -1;
//		TLog::ErrFullSaveLog(ex);
//		// AnsiString msg
//		// programSettings.colorMSG = programSettings.colorBrak;
//		// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
//		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
//	}
	return err;
}

