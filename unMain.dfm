object fmMain: TfmMain
  Left = 0
  Top = 0
  Caption = #1041#1091#1088#1072#1085'9955-191'#1055#1072' v.18072019'
  ClientHeight = 725
  ClientWidth = 1028
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  Menu = MainMenu
  OldCreateOrder = False
  WindowState = wsMaximized
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object PanelTopChoice: TPanel
    Left = 0
    Top = 0
    Width = 1028
    Height = 153
    Align = alTop
    TabOrder = 0
    object Label1: TLabel
      Left = 160
      Top = 67
      Width = 164
      Height = 23
      Caption = #1058#1080#1087#1086#1088#1072#1079#1084#1077#1088' '#1090#1088#1091#1073#1099
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 441
      Top = 1
      Width = 111
      Height = 23
      Caption = #1052#1072#1088#1082#1072' '#1089#1090#1072#1083#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 441
      Top = 67
      Width = 208
      Height = 23
      Caption = #1053#1086#1088#1084#1072#1090#1080#1074#1085#1099#1081' '#1076#1086#1082#1091#1084#1077#1085#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 688
      Top = 67
      Width = 85
      Height = 23
      Caption = #1054#1087#1077#1088#1072#1090#1086#1088
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 956
      Top = 1
      Width = 117
      Height = 23
      Caption = #1053#1086#1084#1077#1088' '#1089#1084#1077#1085#1099
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 688
      Top = 1
      Width = 160
      Height = 23
      Caption = #1053#1072#1089#1090#1088#1086#1077#1095#1085#1099#1081' '#1057#1054#1055
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object cbxTubesTypeSize: TComboBox
      Left = 160
      Top = 96
      Width = 240
      Height = 31
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      Text = 'cbxTubesTypeSize'
      OnSelect = cbxTubesTypeSizeSelect
    end
    object cbxSteelGrades: TComboBox
      Left = 441
      Top = 30
      Width = 226
      Height = 31
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      Text = 'cbxSteelGrades'
    end
    object cbxNormDocs: TComboBox
      Left = 441
      Top = 96
      Width = 226
      Height = 31
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      Text = 'cbxNormDocs'
    end
    object lbeNumFusion: TLabeledEdit
      Left = 161
      Top = 30
      Width = 240
      Height = 31
      AutoSize = False
      CharCase = ecUpperCase
      EditLabel.Width = 124
      EditLabel.Height = 23
      EditLabel.Caption = #1053#1086#1084#1077#1088' '#1087#1083#1072#1074#1082#1080
      EditLabel.Font.Charset = DEFAULT_CHARSET
      EditLabel.Font.Color = clWindowText
      EditLabel.Font.Height = -19
      EditLabel.Font.Name = 'Tahoma'
      EditLabel.Font.Style = []
      EditLabel.ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      Text = #1053#1045#1058' '#1053#1054#1052#1045#1056#1040
    end
    object cbxOperators: TComboBox
      Left = 688
      Top = 96
      Width = 385
      Height = 31
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      Text = 'cbxOperators'
    end
    object cbxSops: TComboBox
      Left = 688
      Top = 30
      Width = 214
      Height = 31
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      Text = 'cbxSops'
    end
    object cbxWorkShifts: TComboBox
      Left = 956
      Top = 30
      Width = 117
      Height = 31
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      Text = 'cbxWorkShifts'
    end
    object bbtMode: TBitBtn
      Left = 848
      Top = 1
      Width = 179
      Height = 151
      Align = alRight
      Caption = #1056#1045#1046#1048#1052' '#1050#1054#1053#1058#1056#1054#1051#1071
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 7
      WordWrap = True
    end
    object pnlTopLeft: TPanel
      Left = 1
      Top = 1
      Width = 154
      Height = 151
      Align = alLeft
      TabOrder = 8
      object bbtlistTubes: TBitBtn
        Left = 1
        Top = 1
        Width = 152
        Height = 149
        Align = alClient
        Caption = #1057#1055#1048#1057#1054#1050' '#1058#1056#1059#1041
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        WordWrap = True
        OnClick = menuListTubesClick
      end
    end
    object cbCross: TCheckBox
      Left = 264
      Top = 130
      Width = 97
      Height = 17
      Caption = #1055#1086#1087#1077#1088#1077#1095#1085#1099#1081
      TabOrder = 9
    end
    object cbLong: TCheckBox
      Left = 377
      Top = 130
      Width = 97
      Height = 17
      Caption = #1055#1088#1086#1076#1086#1083#1100#1085#1099#1081
      TabOrder = 10
    end
    object cbThick: TCheckBox
      Left = 161
      Top = 130
      Width = 97
      Height = 17
      Caption = #1058#1086#1083#1097#1080#1085#1072
      TabOrder = 11
    end
  end
  object PanelButtonsTop: TPanel
    Left = 0
    Top = 153
    Width = 1028
    Height = 128
    Align = alTop
    TabOrder = 1
    object bbtSave: TBitBtn
      Left = 1
      Top = 1
      Width = 146
      Height = 126
      Align = alLeft
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100' '#1085#1072#1089#1090#1088#1086#1081#1082#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      WordWrap = True
      OnClick = bbtSaveClick
    end
    object bbtReady: TBitBtn
      Left = 147
      Top = 1
      Width = 136
      Height = 126
      Align = alLeft
      Caption = #1042#1099#1089#1090#1072#1074#1080#1090#1100' '#1043#1054#1058#1054#1042#1053#1054#1057#1058#1068
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      Margin = 1
      ParentFont = False
      TabOrder = 1
      WordWrap = True
      OnClick = bbtReadyClick
      ExplicitLeft = 141
      ExplicitTop = 0
    end
    object bbtStop: TBitBtn
      Left = 283
      Top = 1
      Width = 141
      Height = 126
      Align = alClient
      Caption = #1057#1058#1054#1055
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      OnClick = bbtStopClick
    end
    object bbtBrakThick: TBitBtn
      Left = 553
      Top = 1
      Width = 158
      Height = 126
      Align = alRight
      Caption = #1044#1045#1060#1045#1050#1058'     '#1052#1053#1050'1 0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      WordWrap = True
    end
    object bblBrakLong: TBitBtn
      Left = 869
      Top = 1
      Width = 158
      Height = 126
      Align = alRight
      Caption = #1044#1045#1060#1045#1050#1058'     '#1052#1053#1050'3 0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      WordWrap = True
    end
    object bbtBrakCross: TBitBtn
      Left = 711
      Top = 1
      Width = 158
      Height = 126
      Align = alRight
      Caption = #1044#1045#1060#1045#1050#1058'    '#1052#1053#1050'2  0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
      WordWrap = True
    end
    object bbtBrakALL: TBitBtn
      Left = 415
      Top = 1
      Width = 138
      Height = 126
      Align = alRight
      Caption = #1044#1045#1060#1045#1050#1058' '#1042#1057#1045#1043#1054' 0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
      WordWrap = True
    end
    object bbtCountControl: TBitBtn
      Left = 172
      Top = 1
      Width = 243
      Height = 126
      Align = alRight
      Caption = ' '#1055#1056#1054#1050#1054#1053#1058#1056#1054#1051#1048#1056#1054#1042#1040#1053#1054':  0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      Margin = 1
      ParentFont = False
      TabOrder = 7
      WordWrap = True
    end
  end
  object PanelClient: TPanel
    Left = 0
    Top = 281
    Width = 1280
    Height = 444
    Align = alLeft
    TabOrder = 2
    object pnlButtons: TPanel
      Left = 1
      Top = 402
      Width = 1278
      Height = 41
      Align = alBottom
      TabOrder = 0
      object BitBtn1: TBitBtn
        Left = 1
        Top = 1
        Width = 75
        Height = 39
        Align = alLeft
        Caption = 'BitBtn1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        Visible = False
      end
      object bbtForseReady: TBitBtn
        Left = 76
        Top = 1
        Width = 75
        Height = 39
        Align = alLeft
        Caption = #1043#1086#1090#1086#1074#1085#1086#1089#1090#1100' 1 '#1089#1077#1082
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        Visible = False
        WordWrap = True
        OnClick = bbtForseReadyClick
      end
      object bbtTest: TBitBtn
        Left = 151
        Top = 1
        Width = 75
        Height = 39
        Align = alLeft
        Caption = 'Test'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        Visible = False
        OnClick = bbtTestClick
      end
      object bbtCounter: TBitBtn
        Left = 226
        Top = 1
        Width = 75
        Height = 39
        Align = alLeft
        Caption = '0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        Visible = False
      end
    end
    object pnlMsg: TPanel
      Left = 1
      Top = 1
      Width = 1278
      Height = 41
      Align = alTop
      Caption = #1057#1090#1072#1090#1091#1089
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object pnlLeft: TPanel
      Left = 1
      Top = 42
      Width = 240
      Height = 360
      Align = alLeft
      TabOrder = 2
      object lbxInfo: TListBox
        Left = 1
        Top = 1
        Width = 238
        Height = 358
        Align = alClient
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
    end
    object pnlCharts: TPanel
      Left = 241
      Top = 42
      Width = 1038
      Height = 360
      Align = alClient
      TabOrder = 3
      object SplitterMid: TSplitter
        Left = 1
        Top = 231
        Width = 1036
        Height = 4
        Cursor = crVSplit
        Align = alBottom
        Color = clHotLight
        ParentColor = False
        ExplicitLeft = 0
        ExplicitTop = 357
      end
      object SplitterTop: TSplitter
        Left = 1
        Top = 145
        Width = 1036
        Height = 4
        Cursor = crVSplit
        Align = alTop
        Color = clHotLight
        ParentColor = False
        ExplicitLeft = 0
        ExplicitTop = 219
      end
      object PanelCross: TPanel
        Left = 1
        Top = 149
        Width = 1036
        Height = 82
        Align = alClient
        BorderStyle = bsSingle
        TabOrder = 0
        object chartCross: TChart
          Left = 1
          Top = 1
          Width = 1030
          Height = 76
          AllowPanning = pmNone
          Legend.Alignment = laTop
          Legend.DividingLines.Visible = True
          Title.Font.Color = clBlack
          Title.Font.Height = -16
          Title.Text.Strings = (
            #1055#1054#1055#1045#1056#1045#1063#1053#1067#1049' '#1050#1054#1053#1058#1056#1054#1051#1068'('#1052#1053#1050'2)')
          OnClickSeries = chartCrossClickSeries
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
            SeriesColor = clRed
            Title = 'Border1'
            LinePen.Color = clRed
            XValues.Name = 'X'
            XValues.Order = loAscending
            YValues.Name = 'Y'
            YValues.Order = loNone
          end
          object Series6: TFastLineSeries
            SeriesColor = clYellow
            Title = 'Border2'
            LinePen.Color = clYellow
            XValues.Name = 'X'
            XValues.Order = loAscending
            YValues.Name = 'Y'
            YValues.Order = loNone
          end
        end
      end
      object PanelLong: TPanel
        Left = 1
        Top = 235
        Width = 1036
        Height = 124
        Align = alBottom
        TabOrder = 1
        object chartLong: TChart
          Left = 1
          Top = 1
          Width = 1034
          Height = 122
          AllowPanning = pmNone
          Legend.Alignment = laTop
          Legend.DividingLines.Visible = True
          Legend.LegendStyle = lsSeries
          Title.Font.Color = clBlack
          Title.Font.Height = -16
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
            SeriesColor = clRed
            Title = 'Border1'
            LinePen.Color = clRed
            XValues.Name = 'X'
            XValues.Order = loAscending
            YValues.Name = 'Y'
            YValues.Order = loNone
          end
          object Series5: TFastLineSeries
            SeriesColor = clYellow
            Title = 'Border2'
            LinePen.Color = clYellow
            XValues.Name = 'X'
            XValues.Order = loAscending
            YValues.Name = 'Y'
            YValues.Order = loNone
          end
        end
      end
      object PanelThick: TPanel
        Left = 1
        Top = 1
        Width = 1036
        Height = 144
        Align = alTop
        TabOrder = 2
        object chartThick: TChart
          Left = 1
          Top = 1
          Width = 1034
          Height = 142
          AllowPanning = pmNone
          Legend.Alignment = laTop
          Legend.DividingLines.Visible = True
          Title.Font.Color = clBlack
          Title.Font.Height = -16
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
          PrintMargins = (
            15
            43
            15
            43)
          ColorPaletteIndex = 13
          object BarSeries2: TBarSeries
            Legend.Visible = False
            BarBrush.Gradient.EndColor = 6519581
            BarBrush.Gradient.Visible = True
            ColorEachPoint = True
            Marks.Visible = False
            ShowInLegend = False
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
            Legend.Visible = False
            BarBrush.Gradient.EndColor = 6519581
            BarBrush.Gradient.Visible = True
            ColorEachPoint = True
            Marks.Visible = False
            ShowInLegend = False
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
            SeriesColor = clBlue
            Title = 'BorderMin'
            LinePen.Color = clBlue
            XValues.Name = 'X'
            XValues.Order = loAscending
            YValues.Name = 'Y'
            YValues.Order = loNone
          end
          object Series8: TFastLineSeries
            SeriesColor = clRed
            Title = 'BorderMax'
            LinePen.Color = clRed
            XValues.Name = 'X'
            XValues.Order = loAscending
            YValues.Name = 'Y'
            YValues.Order = loNone
          end
        end
      end
    end
  end
  object MainMenu: TMainMenu
    Left = 184
    Top = 288
    object menuFile: TMenuItem
      Caption = #1060#1040#1049#1051
      object menuExit: TMenuItem
        Caption = #1042#1067#1061#1054#1044
        OnClick = menuExitClick
      end
    end
    object menuSettings: TMenuItem
      Caption = #1057#1055#1056#1040#1042#1054#1063#1053#1048#1050#1048
      object mnuOperators: TMenuItem
        Caption = #1054#1055#1045#1056#1040#1058#1054#1056#1054#1042
        OnClick = mnuOperatorsClick
      end
      object menuWorkShifts: TMenuItem
        Caption = #1057#1052#1045#1053
        OnClick = menuWorkShiftsClick
      end
      object menuTubesTypeSize: TMenuItem
        Caption = #1058#1048#1055#1054#1056#1040#1047#1052#1045#1056#1054#1042
        OnClick = menuTubesTypeSizeClick
      end
      object menuSteelGrades: TMenuItem
        Caption = #1052#1040#1056#1054#1050' '#1057#1058#1040#1051#1045#1049
        OnClick = menuSteelGradesClick
      end
      object menuSops: TMenuItem
        Caption = #1057#1054#1055
        OnClick = menuSopsClick
      end
      object menuNormDocs: TMenuItem
        Caption = #1053#1054#1056#1052#1040#1058#1048#1042#1053#1067#1061' '#1044#1054#1050#1059#1052#1045#1053#1058#1054#1042
        OnClick = menuNormDocsClick
      end
    end
    object menuTools: TMenuItem
      Caption = #1048#1053#1057#1058#1056#1059#1052#1045#1053#1058#1067
      object menuListTubes: TMenuItem
        Caption = #1057#1055#1048#1057#1054#1050' '#1058#1056#1059#1041
        OnClick = menuListTubesClick
      end
      object menuBackup: TMenuItem
        Caption = #1056#1045#1047#1045#1056#1042#1048#1056#1054#1042#1040#1053#1048#1045' '#1041#1040#1047#1067' '#1044#1040#1053#1053#1067#1061
        OnClick = menuBackupClick
      end
      object mnuArhive: TMenuItem
        Caption = #1040#1056#1061#1048#1042#1048#1056#1054#1042#1040#1053#1048#1045' '#1041#1040#1047#1067' '#1044#1040#1053#1053#1067#1061
        Visible = False
      end
      object menuGSettings: TMenuItem
        Caption = #1054#1041#1065#1048#1045' '#1053#1040#1057#1058#1056#1054#1049#1050#1048
        OnClick = menuGSettingsClick
      end
      object menuRepeatControl: TMenuItem
        Caption = #1055#1054#1042#1058#1054#1056#1053#1067#1049' '#1050#1054#1053#1058#1056#1054#1051#1068
        OnClick = menuRepeatControlClick
      end
      object menuSOP: TMenuItem
        Caption = #1056#1045#1046#1048#1052' '#1057#1054#1055
        OnClick = menuSOPClick
      end
      object menuViewArh: TMenuItem
        Caption = #1055#1056#1054#1057#1052#1054#1058#1056' '#1040#1056#1061#1048#1042#1053#1054#1049' '#1041#1044
        Visible = False
      end
      object menuModify: TMenuItem
        Caption = #1052#1054#1044#1048#1060#1048#1050#1040#1062#1048#1071' '#1047#1040#1055#1048#1057#1045#1049
        Visible = False
        OnClick = menuModifyClick
      end
      object menuViewLog: TMenuItem
        Caption = #1057#1052#1054#1058#1056#1045#1058#1068' '#1057#1054#1041#1067#1058#1048#1071
        OnClick = menuViewLogClick
      end
      object DeleteFromBaseTubeInfo: TMenuItem
        Caption = #1059#1044#1040#1051#1048#1058#1068' '#1048#1047' '#1041#1040#1047#1067' '#1048#1053#1060#1054#1056#1052#1040#1062#1048#1070' '#1055#1054' '#1058#1056#1059#1041#1040#1052
        OnClick = DeleteFromBaseTubeInfoClick
      end
    end
    object menuhelp: TMenuItem
      Caption = #1055#1054#1052#1054#1065#1068
      object menuExtInfo: TMenuItem
        Caption = #1044#1054#1055' '#1048#1053#1060#1054#1056#1052#1040#1062#1048#1071
        OnClick = menuExtInfoClick
      end
      object menuAbout: TMenuItem
        Caption = #1054' '#1055#1056#1054#1043#1056#1040#1052#1052#1045
        OnClick = menuAboutClick
      end
      object menuShowLog: TMenuItem
        Caption = #1055#1054#1050#1040#1047#1040#1058#1068' '#1051#1054#1043
        OnClick = menuShowLogClick
      end
    end
  end
  object TimerUpdateState: TTimer
    Enabled = False
    Interval = 200
    OnTimer = TimerUpdateStateTimer
    Left = 536
    Top = 288
  end
  object ApplicationEvents: TApplicationEvents
    OnMessage = ApplicationEventsMessage
    Left = 32
    Top = 288
  end
  object timerFreeSpase: TTimer
    Interval = 3600000
    OnTimer = timerFreeSpaseTimer
    Left = 288
    Top = 288
  end
  object XMLDocument: TXMLDocument
    FileName = 'C:\Users\USER\Desktop\new-1.xml'
    Options = [doNodeAutoCreate, doNodeAutoIndent, doAttrNull, doAutoPrefix, doNamespaceDecl]
    Left = 424
    Top = 288
    DOMVendorDesc = 'MSXML'
  end
  object queryXML: TADOQuery
    Connection = SqlDBModule.ADOConnectionDB
    Parameters = <>
    Left = 704
    Top = 289
  end
  object queryTSize: TADOQuery
    Connection = SqlDBModule.ADOConnectionDB
    Parameters = <>
    Left = 824
    Top = 289
  end
  object queryClear: TADOQuery
    Connection = SqlDBModule.ADOConnectionDB
    Parameters = <>
    Left = 400
    Top = 481
  end
  object timerBackup: TTimer
    Interval = 540000
    OnTimer = timerBackupTimer
    Left = 536
    Top = 345
  end
  object dialogOpenArh: TOpenDialog
    DefaultExt = '*.udl'
    Filter = #1060#1072#1081#1083' '#1089#1086#1077#1076#1080#1085#1077#1085#1080#1103'|*.udl'
    Options = [ofReadOnly, ofEnableSizing]
    Left = 272
    Top = 424
  end
end
