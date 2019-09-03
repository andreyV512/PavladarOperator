object fmCreateBackup: TfmCreateBackup
  Left = 0
  Top = 0
  Caption = #1057#1086#1079#1076#1072#1085#1080#1077' '#1088#1077#1079#1077#1088#1074#1085#1086#1081' '#1082#1086#1087#1080#1080' '#1073#1072#1079#1099' '#1076#1072#1085#1085#1099#1093
  ClientHeight = 99
  ClientWidth = 431
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object panelTop: TPanel
    Left = 0
    Top = 0
    Width = 431
    Height = 99
    Align = alClient
    TabOrder = 0
    object lblPath: TLabel
      Left = 1
      Top = 1
      Width = 432
      Height = 38
      Align = alTop
      Caption = 
        #1055#1091#1090#1100' '#1080' '#1085#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1092#1072#1081#1083#1072' '#1088#1077#1079#1077#1088#1074#1085#1086#1081' '#1082#1086#1087#1080#1080':/n d:\MyPRG\C_XE\'#1041#1091#1088#1072#1085 +
        '-9955-191\Win32\Debug\.backup.bak'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      WordWrap = True
    end
    object PanelButtoms: TPanel
      Left = 1
      Top = -111
      Width = 429
      Height = 209
      Align = alBottom
      TabOrder = 0
      object bbtCreate: TBitBtn
        Left = 1
        Top = 183
        Width = 427
        Height = 25
        Align = alBottom
        Caption = #1057#1086#1079#1076#1072#1090#1100' '#1088#1077#1079#1077#1088#1074#1085#1091#1102' '#1082#1086#1087#1080#1102
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ModalResult = 1
        ParentFont = False
        TabOrder = 0
        WordWrap = True
        OnClick = bbtCreateClick
      end
      object bbtSaveBackup: TBitBtn
        Left = 1
        Top = 158
        Width = 427
        Height = 25
        Align = alBottom
        Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1087#1091#1090#1100' '#1089#1086#1093#1088#1072#1085#1077#1085#1080#1103' '#1088#1077#1079#1077#1088#1074#1085#1086#1081' '#1082#1086#1087#1080#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
    end
  end
  object gueryBkp: TADOQuery
    Parameters = <>
    Left = 297
    Top = 25
  end
end
