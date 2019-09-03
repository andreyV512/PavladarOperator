object fmGSettings: TfmGSettings
  Left = 0
  Top = 0
  Caption = #1054#1073#1097#1080#1077' '#1085#1072#1089#1090#1088#1086#1081#1082#1080
  ClientHeight = 467
  ClientWidth = 796
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object gridGSettings: TDBGrid
    Left = 0
    Top = 0
    Width = 796
    Height = 400
    Align = alClient
    DataSource = dsGSettings
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnDblClick = gridGSettingsDblClick
  end
  object navGSettings: TDBNavigator
    Left = 0
    Top = 400
    Width = 796
    Height = 67
    DataSource = dsGSettings
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast, nbPost, nbCancel]
    Align = alBottom
    TabOrder = 1
  end
  object queryGSettings: TADOQuery
    Connection = SqlDBModule.ADOConnectionDB
    Parameters = <>
    SQL.Strings = (
      
        'SELECT isActual,RusName,ParamName,ParamValueFloat,ParamValueStr ' +
        'FROM currentSettings')
    Left = 392
    Top = 248
  end
  object dsGSettings: TDataSource
    DataSet = queryGSettings
    Left = 448
    Top = 112
  end
end
