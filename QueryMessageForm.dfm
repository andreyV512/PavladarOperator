object MessageForm: TMessageForm
  Left = 0
  Top = 0
  BorderIcons = []
  ClientHeight = 110
  ClientWidth = 664
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -32
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 39
  object labelText: TLabel
    Left = 32
    Top = 32
    Width = 313
    Height = 39
    Caption = #1042#1099#1087#1086#1083#1085#1103#1077#1090#1089#1103' '#1079#1072#1087#1088#1086#1089
  end
  object labelTime: TLabel
    Left = 392
    Top = 32
    Width = 10
    Height = 39
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 160
    Top = 80
  end
end
