object fmReport: TfmReport
  Left = 0
  Top = 0
  Caption = #1055#1088#1086#1090#1086#1082#1086#1083
  ClientHeight = 548
  ClientWidth = 915
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  WindowState = wsMaximized
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object RichEdit: TRichEdit
    Left = 0
    Top = 0
    Width = 915
    Height = 480
    Margins.Left = 20
    Align = alClient
    BorderWidth = 1
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Courier New'
    Font.Style = []
    Lines.Strings = (
      #1057#1074#1086#1076#1085#1099#1081' '#1086#1090#1095#1077#1090)
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 0
    WantReturns = False
    WordWrap = False
    Zoom = 100
  end
  object Panel1: TPanel
    Left = 0
    Top = 480
    Width = 915
    Height = 68
    Align = alBottom
    TabOrder = 1
    object BitBtn1: TBitBtn
      Left = 1
      Top = 1
      Width = 75
      Height = 66
      Align = alLeft
      Caption = #1055#1077#1095#1072#1090#1100
      TabOrder = 0
      OnClick = BitBtn1Click
    end
    object bbtTst: TBitBtn
      Left = 76
      Top = 1
      Width = 75
      Height = 66
      Align = alLeft
      Caption = 'TEST'
      TabOrder = 1
      Visible = False
      OnClick = bbtTstClick
    end
  end
  object PrintDialog: TPrintDialog
    Left = 632
    Top = 499
  end
  object PrinterSetupDialog: TPrinterSetupDialog
    Left = 744
    Top = 499
  end
end
