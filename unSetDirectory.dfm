object fmSetDirectory: TfmSetDirectory
  Left = 0
  Top = 0
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1086#1074
  ClientHeight = 299
  ClientWidth = 911
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object DBNavigator: TDBNavigator
    Left = 0
    Top = 274
    Width = 911
    Height = 25
    DataSource = DataSource
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast, nbInsert, nbPost, nbCancel]
    Align = alBottom
    TabOrder = 0
  end
  object DBGridDirectory: TDBGrid
    Left = 0
    Top = 0
    Width = 911
    Height = 274
    Hint = #1044#1074#1086#1081#1085#1086#1081' '#1082#1083#1080#1082' '#1076#1083#1103' '#1088#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1103
    Align = alClient
    DataSource = DataSource
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ParentShowHint = False
    ReadOnly = True
    ShowHint = True
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -16
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnDblClick = DBGridDirectoryDblClick
  end
  object lbxFields: TListBox
    Left = 680
    Top = 128
    Width = 121
    Height = 97
    ItemHeight = 13
    TabOrder = 2
    Visible = False
  end
  object DataSource: TDataSource
    DataSet = queryDirectory
    Left = 88
    Top = 200
  end
  object queryDirectory: TADOQuery
    Connection = SqlDBModule.ADOConnectionDB
    BeforePost = queryDirectoryBeforePost
    Parameters = <>
    Left = 136
    Top = 144
  end
  object ApplicationEvents: TApplicationEvents
    OnMessage = ApplicationEventsMessage
    Left = 448
    Top = 144
  end
end
