object fmModifyRecord: TfmModifyRecord
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = 'fmModifyRecord'
  ClientHeight = 281
  ClientWidth = 644
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object pnlBottom: TPanel
    Left = 0
    Top = 240
    Width = 644
    Height = 41
    Align = alBottom
    TabOrder = 0
    object bbtModDel: TBitBtn
      Left = 1
      Top = 1
      Width = 224
      Height = 39
      Align = alLeft
      Caption = #1055#1086#1084#1077#1090#1080#1090#1100' '#1082#1072#1082' '#1091#1076#1072#1083#1077#1085#1085#1091#1102
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = bbtModDelClick
    end
    object bbtRestore: TBitBtn
      Left = 225
      Top = 1
      Width = 231
      Height = 39
      Align = alClient
      Caption = #1042#1086#1089#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1091#1076#1072#1083#1077#1085#1085#1091#1102
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = bbtRestoreClick
      ExplicitLeft = 231
      ExplicitTop = 6
    end
    object bbtClose: TBitBtn
      Left = 456
      Top = 1
      Width = 187
      Height = 39
      Align = alRight
      Caption = #1042#1099#1093#1086#1076' '#1073#1077#1079' '#1080#1079#1084#1077#1085#1077#1085#1080#1081
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = bbtCloseClick
    end
  end
  object lbxDeleted: TListBox
    Left = 280
    Top = 0
    Width = 364
    Height = 240
    Align = alRight
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemHeight = 19
    ParentFont = False
    TabOrder = 1
    OnClick = lbxDeletedClick
  end
  object pnlLeft: TPanel
    Left = 0
    Top = 0
    Width = 280
    Height = 240
    Align = alClient
    TabOrder = 2
    object Label1: TLabel
      Left = 8
      Top = 68
      Width = 122
      Height = 38
      Caption = #1053#1086#1084#1077#1088' '#1076#1083#1103' '#1074#1086#1089#1089#1090#1072#1085#1086#1074#1083#1077#1085#1080#1103': '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      WordWrap = True
    end
    object Label2: TLabel
      Left = 8
      Top = 16
      Width = 141
      Height = 38
      Caption = #1053#1086#1084#1077#1088' '#1087#1086#1084#1077#1095#1072#1077#1084#1086#1081' '#1085#1072' '#1091#1076#1072#1083#1077#1085#1080#1077': '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      WordWrap = True
    end
    object edtDelete: TEdit
      Left = 168
      Top = 27
      Width = 97
      Height = 27
      Alignment = taCenter
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      Text = '0'
    end
    object edtRestore: TEdit
      Left = 168
      Top = 79
      Width = 97
      Height = 27
      Alignment = taCenter
      Color = clInactiveCaption
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 1
      Text = '0'
    end
  end
  object queryDelRestor: TADOQuery
    Connection = SqlDBModule.ADOConnectionDB
    Parameters = <
      item
        Name = 'pnumFusion'
        Attributes = [paSigned]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      
        'SELECT dtmCreate,numFusion,numTube FROM dbo.resultTubeShort wher' +
        'e numFusion=:pnumFusion and numTube<0')
    Left = 64
    Top = 160
  end
end
