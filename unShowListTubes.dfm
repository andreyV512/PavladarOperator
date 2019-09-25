object fmShowListTubes: TfmShowListTubes
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = #1057#1087#1080#1089#1086#1082' '#1090#1088#1091#1073
  ClientHeight = 482
  ClientWidth = 1202
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poMainFormCenter
  WindowState = wsMaximized
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object DBNavigator1: TDBNavigator
    Left = 0
    Top = 416
    Width = 1202
    Height = 25
    DataSource = DataSource
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
    Align = alBottom
    TabOrder = 0
  end
  object PanelBottom: TPanel
    Left = 0
    Top = 441
    Width = 1202
    Height = 41
    Align = alBottom
    TabOrder = 1
  end
  object DBGridListTubes: TDBGrid
    Left = 0
    Top = 129
    Width = 1202
    Height = 287
    Align = alClient
    DataSource = DataSource
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    ParentFont = False
    PopupMenu = PopupMenuSLT
    ReadOnly = True
    TabOrder = 2
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnCellClick = DBGridListTubesCellClick
    OnDblClick = DBGridListTubesDblClick
  end
  object PanelFilter: TPanel
    Left = 0
    Top = 0
    Width = 1202
    Height = 129
    Align = alTop
    TabOrder = 3
    object bbtFiltered: TBitBtn
      Left = 944
      Top = 1
      Width = 136
      Height = 127
      Align = alRight
      Caption = #1060#1080#1083#1100#1090#1088
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      WordWrap = True
      OnClick = bbtFilteredClick
    end
    object bbtResetFiltr: TBitBtn
      Left = 1080
      Top = 1
      Width = 121
      Height = 127
      Align = alRight
      Caption = #1057#1073#1088#1086#1089#1080#1090#1100' '#1092#1080#1083#1100#1090#1088
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      WordWrap = True
      OnClick = bbtResetFiltrClick
    end
    object PanelDates: TPanel
      Left = 844
      Top = 1
      Width = 100
      Height = 127
      Align = alRight
      TabOrder = 2
      object dtpBegin: TDateTimePicker
        Left = 1
        Top = 1
        Width = 98
        Height = 24
        Align = alTop
        Date = 43342.500000000000000000
        Time = 43342.500000000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object dtpEnd: TDateTimePicker
        Left = 1
        Top = 25
        Width = 98
        Height = 24
        Align = alTop
        Date = 43342.500000000000000000
        Time = 43342.500000000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
    end
    object Panel1: TPanel
      Left = 791
      Top = 1
      Width = 53
      Height = 127
      Align = alRight
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      object Label4: TLabel
        Left = 1
        Top = 17
        Width = 49
        Height = 16
        Align = alTop
        Alignment = taCenter
        Caption = #1087#1086' '#1076#1072#1090#1091':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label5: TLabel
        Left = 1
        Top = 1
        Width = 50
        Height = 16
        Align = alTop
        Alignment = taCenter
        Caption = #1057' '#1076#1072#1090#1099': '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
    end
    object grbParams: TGroupBox
      Left = 1
      Top = 1
      Width = 790
      Height = 127
      Align = alClient
      Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1092#1080#1083#1100#1090#1088#1072#1094#1080#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      object Label8: TLabel
        Left = 159
        Top = 16
        Width = 117
        Height = 16
        Caption = #1042#1099#1073#1086#1088' '#1090#1080#1087#1086#1088#1072#1079#1084#1077#1088#1072
      end
      object Label1: TLabel
        Left = 661
        Top = 16
        Width = 57
        Height = 16
        Caption = #1054#1087#1077#1088#1072#1090#1086#1088
      end
      object Label2: TLabel
        Left = 333
        Top = 16
        Width = 138
        Height = 16
        Caption = #1053#1086#1088#1084#1072#1090#1080#1074#1085#1099#1081' '#1076#1086#1082#1091#1084#1077#1085#1090
      end
      object Label3: TLabel
        Left = 501
        Top = 16
        Width = 121
        Height = 16
        Caption = #1048#1089#1087#1086#1083#1100#1079#1086#1074#1072#1085#1099#1081' '#1057#1054#1055
      end
      object Label9: TLabel
        Left = 159
        Top = 68
        Width = 113
        Height = 16
        Caption = #1042#1099#1073#1086#1088' '#1084#1072#1088#1082#1080' '#1089#1090#1072#1083#1080
      end
      object lbeFuzion: TLabeledEdit
        Left = 8
        Top = 38
        Width = 121
        Height = 24
        Hint = #1044#1083#1103' '#1074#1099#1073#1086#1088#1072' '#1074#1089#1077#1093' '#1074#1087#1080#1096#1080#1090#1077' *.'
        Alignment = taCenter
        CharCase = ecUpperCase
        EditLabel.Width = 82
        EditLabel.Height = 16
        EditLabel.Caption = #1053#1086#1084#1077#1088' '#1087#1083#1072#1074#1082#1080
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        Text = '*'
      end
      object lbeNumTube: TLabeledEdit
        Left = 8
        Top = 90
        Width = 121
        Height = 24
        Hint = #1044#1083#1103' '#1074#1092#1099#1073#1086#1088#1072' '#1074#1089#1077#1093' '#1074#1087#1080#1096#1080#1090#1077' *.'
        Alignment = taCenter
        CharCase = ecUpperCase
        EditLabel.Width = 76
        EditLabel.Height = 16
        EditLabel.Caption = #1053#1086#1084#1077#1088' '#1090#1088#1091#1073#1099
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        Text = '*'
      end
      object cbxFTubesTypeSize: TComboBox
        Left = 159
        Top = 38
        Width = 145
        Height = 24
        TabOrder = 2
        Text = #1085#1077' '#1074#1099#1073#1088#1072#1085#1086
      end
      object cbxOperators: TComboBox
        Left = 661
        Top = 38
        Width = 145
        Height = 24
        TabOrder = 3
        Text = #1085#1077' '#1074#1099#1073#1088#1072#1085#1086
      end
      object cbxNormDocs: TComboBox
        Left = 333
        Top = 38
        Width = 145
        Height = 24
        TabOrder = 4
        Text = #1085#1077' '#1074#1099#1073#1088#1072#1085#1086
      end
      object cbxSops: TComboBox
        Left = 501
        Top = 38
        Width = 145
        Height = 24
        TabOrder = 5
        Text = #1085#1077' '#1074#1099#1073#1088#1072#1085#1086
      end
      object cbxSteelGrades: TComboBox
        Left = 159
        Top = 90
        Width = 145
        Height = 24
        TabOrder = 6
        Text = #1085#1077' '#1074#1099#1073#1088#1072#1085#1086
      end
      object cbxBrackAll: TCheckBox
        Left = 333
        Top = 68
        Width = 138
        Height = 17
        Caption = #1042#1057#1045' '#1044#1045#1060#1045#1050#1058#1067
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 7
        OnClick = cbxBrackTClick
      end
      object cbxWithSOP: TCheckBox
        Left = 501
        Top = 68
        Width = 138
        Height = 17
        Caption = #1042#1052#1045#1057#1058#1045' '#1089' '#1057#1054#1055
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 8
        OnClick = cbxBrackTClick
      end
    end
    object cbxBrackT: TCheckBox
      Left = 334
      Top = 98
      Width = 138
      Height = 17
      Caption = #1044#1045#1060#1045#1050#1058' '#1058#1054#1051#1065#1048#1053#1067
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      OnClick = cbxBrackTClick
    end
    object cbxBrackL: TCheckBox
      Left = 662
      Top = 98
      Width = 155
      Height = 17
      Caption = #1055#1056#1054#1044#1054#1051#1068#1053#1067#1049' '#1044#1045#1060#1045#1050#1058
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      OnClick = cbxBrackLClick
    end
    object cbxBrackC: TCheckBox
      Left = 502
      Top = 98
      Width = 154
      Height = 17
      Caption = #1055#1054#1055#1045#1056#1045#1063#1053#1067#1049' '#1044#1045#1060#1045#1050#1058
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      OnClick = cbxBrackCClick
    end
  end
  object DataSource: TDataSource
    DataSet = queryShowListTubes
    Left = 192
    Top = 192
  end
  object queryShowTube: TADOQuery
    Connection = SqlDBModule.ADOConnectionDB
    Parameters = <>
    Left = 296
    Top = 192
  end
  object PopupMenuSLT: TPopupMenu
    Left = 424
    Top = 184
    object menuShowZones: TMenuItem
      Caption = #1055#1054#1050#1040#1047#1040#1058#1068' '#1042#1067#1041#1056#1040#1053#1053#1059#1070
      OnClick = menuShowZonesClick
    end
    object mnuPrintSelected: TMenuItem
      Caption = #1056#1040#1057#1055#1045#1063#1040#1058#1040#1058#1068' '#1054#1058#1060#1048#1051#1068#1058#1056#1054#1042#1040#1053#1053#1054#1045
      OnClick = mnuPrintSelectedClick
    end
    object miDeleteTube: TMenuItem
      Caption = #1059#1044#1040#1051#1048#1058#1068' '#1058#1056#1059#1041#1059
      OnClick = miDeleteTubeClick
    end
  end
  object queryShowListTubes: TADOQuery
    Connection = SqlDBModule.ADOConnectionDB
    AfterOpen = queryShowListTubesAfterOpen
    Parameters = <>
    Left = 240
    Top = 304
  end
  object timerRefresh: TTimer
    Interval = 20000
    OnTimer = timerRefreshTimer
    Left = 632
    Top = 240
  end
end
