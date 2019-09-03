object fmViewZone: TfmViewZone
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = 'fmViewZone'
  ClientHeight = 623
  ClientWidth = 1270
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnDestroy = FormDestroy
  OnKeyPress = FormKeyPress
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object ChartVZ: TChart
    Left = 0
    Top = 0
    Width = 1270
    Height = 623
    BackWall.Color = clGray
    BackWall.Transparency = 30
    BackWall.Transparent = False
    Legend.Visible = False
    MarginBottom = 16
    MarginLeft = 0
    MarginRight = 2
    MarginTop = 7
    MarginUnits = muPixels
    Title.Text.Strings = (
      'TChart')
    Title.Visible = False
    BottomAxis.LabelsAlign = alOpposite
    BottomAxis.LabelsAlternate = True
    BottomAxis.LabelsSeparation = 20
    BottomAxis.LabelStyle = talValue
    LeftAxis.Automatic = False
    LeftAxis.AutomaticMaximum = False
    LeftAxis.AutomaticMinimum = False
    LeftAxis.Maximum = 100.000000000000000000
    View3D = False
    Align = alClient
    PopupMenu = popupMenuChartZone
    TabOrder = 0
    OnMouseMove = ChartVZMouseMove
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object SBMedian: TSpeedButton
      Left = 60
      Top = 8
      Width = 17
      Height = 17
      Hint = #1052#1077#1076#1080#1072#1085#1085#1072#1103' '#1092#1080#1083#1100#1090#1088#1072#1094#1080#1103
      AllowAllUp = True
      GroupIndex = 2
      Caption = #1052
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      Visible = False
    end
    object SBFilterIn: TSpeedButton
      Left = 106
      Top = 8
      Width = 17
      Height = 17
      Hint = #1063#1072#1089#1090#1086#1090#1085#1072#1103' '#1092#1080#1083#1100#1090#1088#1072#1094#1080#1103' '#1074#1085#1091#1090#1088#1077#1085#1085#1103#1103' '
      AllowAllUp = True
      GroupIndex = 4
      Caption = #1092
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      Visible = False
    end
    object SBFilterOut: TSpeedButton
      Left = 83
      Top = 8
      Width = 17
      Height = 17
      Hint = #1063#1072#1089#1090#1086#1090#1085#1072#1103' '#1092#1080#1083#1100#1090#1088#1072#1094#1080#1103' '#1074#1085#1077#1096#1085#1103#1103
      AllowAllUp = True
      GroupIndex = 3
      Caption = #1060
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      Visible = False
    end
    object SBSource: TSpeedButton
      Left = 37
      Top = 8
      Width = 17
      Height = 17
      Hint = #1048#1089#1093#1086#1076#1085#1099#1077' '#1076#1072#1085#1085#1099#1077
      AllowAllUp = True
      GroupIndex = 1
      Caption = #1048
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      Visible = False
    end
    object StatusBar: TStatusBar
      Left = 1
      Top = 603
      Width = 1268
      Height = 19
      Panels = <
        item
          Text = #1056#1072#1089#1089#1090#1086#1103#1085#1080#1077':'
          Width = 50
        end>
    end
    object Panel1: TPanel
      Left = 1046
      Top = 8
      Width = 197
      Height = 33
      TabOrder = 1
      object cbEtalonTubeDefects: TComboBox
        Left = 7
        Top = 7
        Width = 184
        Height = 21
        Style = csDropDownList
        TabOrder = 0
        Visible = False
        OnKeyPress = FormKeyPress
        OnKeyUp = cbEtalonTubeDefectsKeyUp
      end
    end
    object BarOut: TBarSeries
      BarPen.Visible = False
      ColorEachPoint = True
      Marks.Visible = False
      BarWidthPercent = 100
      Emboss.Color = 8618883
      Shadow.Color = 8618883
      SideMargins = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
    object BarIn: TBarSeries
      BarPen.Visible = False
      ColorEachPoint = True
      Marks.Visible = False
      BarWidthPercent = 100
      Emboss.Color = 8750469
      Shadow.Color = 8750469
      SideMargins = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
    object Out1: TLineSeries
      Brush.BackColor = clDefault
      LinePen.Color = 1330417
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Out2: TLineSeries
      Brush.BackColor = clDefault
      LinePen.Color = 11048782
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object In1: TLineSeries
      Brush.BackColor = clDefault
      LinePen.Color = 7028779
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object In2: TLineSeries
      Brush.BackColor = clDefault
      LinePen.Color = 6519581
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Zero: TLineSeries
      Marks.Emboss.Color = 8487297
      Marks.Shadow.Color = 8487297
      Brush.BackColor = clDefault
      LinePen.Color = 919731
      Pointer.Brush.Gradient.EndColor = 919731
      Pointer.Gradient.EndColor = 919731
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Devider1: TLineSeries
      SeriesColor = 11048782
      Title = 'Devider1'
      Brush.BackColor = clDefault
      LinePen.Color = 11048782
      Pointer.Brush.Gradient.EndColor = 11048782
      Pointer.Gradient.EndColor = 11048782
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Devider2: TLineSeries
      SeriesColor = 11048782
      Title = 'Devider2'
      Brush.BackColor = clDefault
      LinePen.Color = 11048782
      Pointer.Brush.Gradient.EndColor = 11048782
      Pointer.Gradient.EndColor = 11048782
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object DeviderIn1: TLineSeries
      SeriesColor = 11048782
      Title = 'DeviderIn1'
      Brush.BackColor = clDefault
      LinePen.Color = 11048782
      Pointer.Brush.Gradient.EndColor = 11048782
      Pointer.Gradient.EndColor = 11048782
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object DeviderIn2: TLineSeries
      SeriesColor = 11048782
      Title = 'DeviderIn2'
      Brush.BackColor = clDefault
      LinePen.Color = 11048782
      Pointer.Brush.Gradient.EndColor = 11048782
      Pointer.Gradient.EndColor = 11048782
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Arrow: TArrowSeries
      Legend.Visible = False
      ColorEachPoint = True
      Marks.Emboss.Color = clLime
      Marks.Font.Emboss.SmoothBlur = -23
      Marks.Font.Shadow.Visible = False
      Marks.Frame.Visible = False
      Marks.Shadow.Color = 8947848
      Marks.Shadow.Visible = False
      Marks.Transparent = True
      Marks.Margins.Left = 0
      Marks.Margins.Right = 25
      Marks.Arrow.Visible = False
      Marks.BackColor = clWhite
      Marks.Callout.Arrow.Visible = False
      Marks.Symbol.Brush.Image.Data = {
        07544269746D61707E000000424D7E000000000000003E000000280000001000
        0000100000000100010000000000400000000000000000000000020000000200
        000000000000FFFFFF0000000000AAAA000000000000AAAA000000000000AAAA
        000000000000AAAA000000000000AAAA000000000000AAAA000000000000AAAA
        000000000000AAAA0000}
      Marks.Symbol.Shadow.Visible = False
      Marks.TextAlign = taLeftJustify
      Marks.Color = clWhite
      ShowInLegend = False
      ClickableLine = False
      Pointer.Brush.Gradient.EndColor = 6144242
      Pointer.Gradient.EndColor = 6144242
      Pointer.HorizSize = 1
      Pointer.InflateMargins = False
      Pointer.Pen.Width = 2
      Pointer.Style = psRectangle
      Pointer.VertSize = 1
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
      EndXValues.Name = 'EndX'
      EndXValues.Order = loNone
      EndYValues.Name = 'EndY'
      EndYValues.Order = loNone
      StartXValues.Name = 'X'
      StartXValues.Order = loAscending
      StartYValues.Name = 'Y'
      StartYValues.Order = loNone
    end
    object Mark: TBubbleSeries
      Legend.Visible = False
      Marks.Emboss.Clip = True
      Marks.Font.Emboss.Smooth = False
      Marks.Font.Shadow.Smooth = False
      Marks.Font.Shadow.Visible = False
      Marks.Frame.Visible = False
      Marks.Shadow.Clip = True
      Marks.Visible = True
      Marks.Clip = True
      Marks.Symbol.Shadow.Visible = False
      ShowInLegend = False
      ClickableLine = False
      Pointer.Brush.Gradient.EndColor = 6144242
      Pointer.Gradient.EndColor = 6144242
      Pointer.HorizSize = 1099
      Pointer.InflateMargins = False
      Pointer.Style = psNothing
      Pointer.VertSize = 1099
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
      RadiusValues.Name = 'Radius'
      RadiusValues.Order = loNone
    end
  end
  object popupMenuChartZone: TPopupMenu
    Left = 608
    Top = 120
    object ZoomUp: TMenuItem
      Caption = #1059#1074#1077#1083#1080#1095#1080#1090#1100' '#1085#1072' 1,5'
      OnClick = ZoomUpClick
    end
    object ZoomDown: TMenuItem
      Caption = #1059#1084#1077#1085#1100#1096#1080#1090#1100' '#1085#1072' 1,5'
      OnClick = ZoomDownClick
    end
    object mnuZoomReset: TMenuItem
      Caption = #1057#1073#1088#1086#1089#1080#1090#1100' '#1091#1074#1077#1083#1080#1095#1077#1085#1080#1077
      OnClick = mnuZoomResetClick
    end
  end
end
