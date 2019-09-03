object fmShowZones: TfmShowZones
  Left = 0
  Top = 100
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #1055#1088#1086#1089#1084#1086#1090#1088' '#1079#1086#1085' '#1041#1059#1056#1040#1053' 9955'
  ClientHeight = 750
  ClientWidth = 1469
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  PopupMenu = popMenuShowZ
  Position = poMainFormCenter
  WindowState = wsMaximized
  OnClose = FormClose
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object SplitterMid: TSplitter
    Left = 0
    Top = 524
    Width = 1469
    Height = 4
    Cursor = crVSplit
    Align = alBottom
    Color = clHotLight
    ParentColor = False
    OnMoved = SplitterMidMoved
    ExplicitLeft = -3
    ExplicitTop = 842
  end
  object SplitterTop: TSplitter
    Left = 0
    Top = 410
    Width = 1469
    Height = 4
    Cursor = crVSplit
    Align = alTop
    Color = clHotLight
    ParentColor = False
    OnMoved = SplitterTopMoved
    ExplicitLeft = 8
    ExplicitTop = 267
  end
  object PanelTop: TPanel
    Left = 0
    Top = 0
    Width = 1469
    Height = 145
    Align = alTop
    TabOrder = 0
    object pnlTopLeft: TPanel
      Left = 1
      Top = 113
      Width = 112
      Height = 31
      Align = alLeft
      Caption = #1041#1059#1056#1040#1053' 9955'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object dbGridTitle1: TDBGrid
      Left = 1
      Top = 1
      Width = 1467
      Height = 56
      Align = alTop
      DataSource = dsTitle
      FixedColor = clInfoBk
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      Options = [dgTitles, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
      ParentFont = False
      ReadOnly = True
      TabOrder = 1
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -16
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
      Columns = <
        item
          Expanded = False
          FieldName = #1044#1072#1090#1072' '#1080' '#1074#1088#1077#1084#1103' '#1082#1086#1085#1090#1088#1086#1083#1103
          Visible = True
        end
        item
          Expanded = False
          FieldName = #8470' '#1087#1083#1072#1074#1082#1080
          Visible = True
        end
        item
          Expanded = False
          FieldName = #8470' '#1090#1088#1091#1073#1099
          Visible = True
        end
        item
          Expanded = False
          FieldName = #1058#1080#1087#1086#1088#1072#1079#1084#1077#1088
          Visible = True
        end
        item
          Expanded = False
          FieldName = #1053#1086#1088#1084'. '#1076#1086#1082#1091#1084#1077#1085#1090
          Visible = True
        end
        item
          Expanded = False
          FieldName = #1053#1072#1089#1090#1088'. '#1057#1054#1055
          Visible = True
        end
        item
          Expanded = False
          FieldName = #1052#1072#1088#1082#1072' '#1089#1090#1072#1083#1080
          Visible = True
        end
        item
          Expanded = False
          FieldName = #1050'. '#1058#1086#1083#1097#1080#1085#1099
          Visible = True
        end
        item
          Expanded = False
          FieldName = #1055#1086#1087#1077#1088#1077#1095#1085#1099#1081' '#1082'.'
          Visible = True
        end
        item
          Expanded = False
          FieldName = #1055#1088#1086#1076#1086#1083#1100#1085#1099#1081' '#1082'.'
          Visible = True
        end
        item
          Expanded = False
          FieldName = #1044#1083#1080#1085#1072', '#1084#1084
          Visible = True
        end>
    end
    object dbGridTitle2: TDBGrid
      Left = 1
      Top = 57
      Width = 1467
      Height = 56
      Align = alTop
      DataSource = dsTitle
      FixedColor = clInfoBk
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      Options = [dgTitles, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
      ParentFont = False
      ReadOnly = True
      TabOrder = 2
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -16
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
      Columns = <
        item
          Expanded = False
          FieldName = #1052#1053#1050'3 '#1086#1073'/'#1084#1080#1085
          Width = 86
          Visible = True
        end
        item
          Expanded = False
          FieldName = #1054#1087#1077#1088#1072#1090#1086#1088
          Visible = True
        end
        item
          Expanded = False
          FieldName = #1057#1084#1077#1085#1072
          Visible = True
        end>
    end
  end
  object PanelThick: TPanel
    Left = 0
    Top = 145
    Width = 1469
    Height = 265
    Align = alTop
    TabOrder = 1
    object chartThick: TChart
      Left = 1
      Top = 55
      Width = 1467
      Height = 209
      AllowPanning = pmNone
      Legend.Visible = False
      Title.Font.Charset = RUSSIAN_CHARSET
      Title.Font.Color = clBlack
      Title.Font.Height = -16
      Title.Font.Style = [fsBold]
      Title.Text.Strings = (
        #1050#1054#1053#1058#1056#1054#1051#1068' '#1058#1054#1051#1065#1048#1053#1067'('#1052#1053#1050'1)')
      OnClickSeries = chartThickClickSeries
      BottomAxis.GridCentered = True
      BottomAxis.MinorTickCount = 1
      LeftAxis.Automatic = False
      LeftAxis.AutomaticMaximum = False
      LeftAxis.AutomaticMinimum = False
      LeftAxis.Labels = False
      LeftAxis.LabelsFormat.Visible = False
      LeftAxis.LabelsMultiLine = True
      LeftAxis.Maximum = 50.000000000000000000
      LeftAxis.Minimum = -50.000000000000000000
      LeftAxis.MinorGrid.Visible = True
      LeftAxis.MinorTickCount = 1
      LeftAxis.MinorTickLength = 4
      LeftAxis.TickLength = 6
      LeftAxis.TickOnLabelsOnly = False
      LeftAxis.Title.Caption = '012'
      View3D = False
      View3DWalls = False
      Align = alClient
      TabOrder = 0
      DefaultCanvas = 'TGDIPlusCanvas'
      ColorPaletteIndex = 13
      object BarSeries2: TBarSeries
        BarBrush.Gradient.EndColor = 6519581
        BarBrush.Gradient.Visible = True
        ColorEachPoint = True
        Marks.Visible = False
        Title = 'Min'
        BarStyle = bsRectGradient
        BarWidthPercent = 100
        Gradient.EndColor = 6519581
        Gradient.Visible = True
        MultiBar = mbNone
        Shadow.Visible = False
        SideMargins = False
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Bar'
        YValues.Order = loNone
        Data = {
          0006000000000000000080514000000000000054400000000000003740000000
          000040514000000000008058400000000000805340}
        Detail = {0000000000}
      end
      object Series1: TBarSeries
        BarBrush.Gradient.EndColor = 6519581
        BarBrush.Gradient.Visible = True
        ColorEachPoint = True
        Marks.Visible = False
        Title = 'Max'
        BarStyle = bsRectGradient
        BarWidthPercent = 100
        Gradient.EndColor = 6519581
        Gradient.Visible = True
        MultiBar = mbNone
        Shadow.Visible = False
        SideMargins = False
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Bar'
        YValues.Order = loNone
        Data = {
          0006000000000000000080514000000000000054400000000000003740000000
          000040514000000000008058400000000000805340}
      end
      object Series7: TFastLineSeries
        Legend.Text = '0 '#1084#1084
        LegendTitle = '0 '#1084#1084
        Title = 'BorderMin'
        LinePen.Color = 1330417
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object Series8: TFastLineSeries
        Title = 'BorderMax'
        LinePen.Color = 11048782
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
    end
    object edtThick: TEdit
      Left = 1
      Top = 1
      Width = 1467
      Height = 27
      Align = alTop
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 1
      Text = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1082#1086#1085#1090#1088#1086#1083#1103':'
    end
    object edThickDop: TEdit
      Left = 1
      Top = 28
      Width = 1467
      Height = 27
      Align = alTop
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 2
      Text = #1055#1086' '#1090#1088#1091#1073#1077' '#1084#1080#1085#1080#1084#1091#1084'=00 '#1084#1084' '#1084#1072#1082#1089#1080#1084#1091#1084'=00 '#1084#1084' '#1089#1088#1077#1076#1085#1077#1077'=00 '#1084#1084
    end
  end
  object PanelLong: TPanel
    Left = 0
    Top = 528
    Width = 1469
    Height = 222
    Align = alBottom
    TabOrder = 2
    object memoBrack: TMemo
      Left = 304
      Top = 32
      Width = 889
      Height = 89
      Lines.Strings = (
        'memoBrack')
      TabOrder = 2
      Visible = False
      WordWrap = False
    end
    object chartLong: TChart
      Left = 1
      Top = 28
      Width = 1467
      Height = 193
      AllowPanning = pmNone
      Legend.Visible = False
      Title.Font.Charset = RUSSIAN_CHARSET
      Title.Font.Color = clBlack
      Title.Font.Height = -16
      Title.Font.Style = [fsBold]
      Title.Text.Strings = (
        #1055#1056#1054#1044#1054#1051#1068#1053#1067#1049' '#1050#1054#1053#1058#1056#1054#1051#1068'('#1052#1053#1050'3)')
      OnClickSeries = chartLongClickSeries
      BottomAxis.GridCentered = True
      BottomAxis.MinorTickCount = 1
      LeftAxis.Automatic = False
      LeftAxis.AutomaticMaximum = False
      LeftAxis.AutomaticMinimum = False
      LeftAxis.Maximum = 100.000000000000000000
      LeftAxis.MinorTickCount = 4
      View3D = False
      View3DWalls = False
      Align = alClient
      TabOrder = 0
      DefaultCanvas = 'TGDIPlusCanvas'
      ColorPaletteIndex = 13
      object Series2: TBarSeries
        BarBrush.Gradient.EndColor = 6519581
        BarBrush.Gradient.Visible = True
        ColorEachPoint = True
        Marks.Visible = False
        Title = 'Result'
        BarStyle = bsRectGradient
        BarWidthPercent = 100
        Gradient.EndColor = 6519581
        Gradient.Visible = True
        MultiBar = mbNone
        Shadow.Visible = False
        SideMargins = False
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Bar'
        YValues.Order = loNone
        Data = {
          0006000000000000000080514000000000000054400000000000003740000000
          000040514000000000008058400000000000805340}
        Detail = {0000000000}
      end
      object Series4: TFastLineSeries
        Title = 'Border1'
        LinePen.Color = 3513587
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object Series5: TFastLineSeries
        Title = 'Border2'
        LinePen.Color = 3513587
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
    end
    object edtLong: TEdit
      Left = 1
      Top = 1
      Width = 1467
      Height = 27
      Align = alTop
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 1
      Text = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1082#1086#1085#1090#1088#1086#1083#1103':'
    end
  end
  object PanelCross: TPanel
    Left = 0
    Top = 414
    Width = 1469
    Height = 110
    Align = alClient
    BorderStyle = bsSingle
    TabOrder = 3
    object chartCross: TChart
      Left = 1
      Top = 28
      Width = 1463
      Height = 77
      AllowPanning = pmNone
      Legend.Visible = False
      Title.Font.Charset = RUSSIAN_CHARSET
      Title.Font.Color = clBlack
      Title.Font.Height = -16
      Title.Font.Style = [fsBold]
      Title.Text.Strings = (
        #1055#1054#1055#1045#1056#1045#1063#1053#1067#1049' '#1050#1054#1053#1058#1056#1054#1051#1068'('#1052#1053#1050'2)')
      OnClickSeries = ChartCrossClickSeries
      BottomAxis.GridCentered = True
      BottomAxis.LabelsMultiLine = True
      BottomAxis.LabelsSeparation = 0
      BottomAxis.MinorTickCount = 1
      LeftAxis.Automatic = False
      LeftAxis.AutomaticMaximum = False
      LeftAxis.AutomaticMinimum = False
      LeftAxis.Maximum = 100.000000000000000000
      LeftAxis.MinorTickCount = 4
      View3D = False
      View3DWalls = False
      Align = alClient
      TabOrder = 0
      DefaultCanvas = 'TGDIPlusCanvas'
      ColorPaletteIndex = 13
      object BarSeries1: TBarSeries
        BarBrush.Gradient.EndColor = 6519581
        BarBrush.Gradient.Visible = True
        ColorEachPoint = True
        Marks.Visible = False
        Title = 'Result'
        BarStyle = bsRectGradient
        BarWidthPercent = 100
        Gradient.EndColor = 6519581
        Gradient.Visible = True
        MultiBar = mbNone
        Shadow.Visible = False
        SideMargins = False
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Bar'
        YValues.Order = loNone
        Data = {
          0006000000000000000080514000000000000054400000000000003740000000
          000040514000000000008058400000000000805340}
        Detail = {0000000000}
      end
      object Series3: TFastLineSeries
        Title = 'Border1'
        LinePen.Color = 3513587
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object Series6: TFastLineSeries
        Title = 'Border2'
        LinePen.Color = 3513587
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
    end
    object edtCross: TEdit
      Left = 1
      Top = 1
      Width = 1463
      Height = 27
      Align = alTop
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 1
      Text = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1082#1086#1085#1090#1088#1086#1083#1103':'
    end
  end
  object PrintDialog: TPrintDialog
    Options = [poPageNums]
    Left = 1112
    Top = 406
  end
  object ApplicationEvents: TApplicationEvents
    OnMessage = ApplicationEventsMessage
    Left = 792
    Top = 481
  end
  object OpenDialogFromFile: TOpenDialog
    DefaultExt = '*.bindkb'
    Options = [ofEnableSizing]
    Left = 688
    Top = 136
  end
  object popMenuShowZ: TPopupMenu
    Left = 656
    Top = 80
    object menuPrint: TMenuItem
      Caption = #1056#1040#1057#1055#1045#1063#1040#1058#1040#1058#1068' '#1055#1056#1054#1058#1054#1050#1054#1051
      OnClick = menuPrintClick
    end
  end
  object queryTitle: TADOQuery
    Connection = SqlDBModule.ADOConnectionDB
    Parameters = <>
    Left = 384
    Top = 208
  end
  object dsTitle: TDataSource
    DataSet = queryTitle
    Left = 528
    Top = 152
  end
end
