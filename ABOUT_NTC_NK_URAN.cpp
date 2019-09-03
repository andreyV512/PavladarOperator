// ---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ABOUT_NTC_NK_URAN.h"
#include "IOUtils.hpp"
// ---------------------------------------------------------------------
#pragma resource "*.dfm"
TfmAboutBox *fmAboutBox;

// ---------------------------------------------------------------------
__fastcall TfmAboutBox::TfmAboutBox(TComponent* AOwner) : TForm(AOwner) {
}
// ---------------------------------------------------------------------

void __fastcall TfmAboutBox::FormShow(TObject *Sender) {
	TFile *f = new TFile();
	lCreationDate->Caption = "���� ������: " + f->GetLastWriteTime(Application->ExeName);
	delete f;
}
// ---------------------------------------------------------------------------
void __fastcall TfmAboutBox::LabelSendClick(TObject *Sender)
{
	try {
		// Application->MessageBoxW(L"�������� ������!", L"���������!",MB_ICONINFORMATION);
		ShellExecute(Handle, L"open", L"mailto:help.uran@gmail.com", NULL, NULL, SW_SHOWDEFAULT);
		// ShellExecute(Handle, L"open", L"http://uran-ndt.ru/", NULL, NULL, SW_SHOWDEFAULT);
	}
	catch (Exception *ex) {
		Application->MessageBoxW(ex->Message.c_str(), L"������!", MB_ICONERROR);
		// TDateTime currentDT;
		// AnsiString strCurrentDT = FormatDateTime("yyyy.mm.dd hh:mm:ss",currentDT.CurrentDateTime());
		// TPr::prWrite(strCurrentDT+AnsiString("PA: ") + ex->Message)
	}
}
//---------------------------------------------------------------------------

void __fastcall TfmAboutBox::LabelSendMouseEnter(TObject *Sender)
{
	// ������ �����
	LabelSend->Font->Color = clBlue;
	LabelSend->Font->Style = TFontStyles() << fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TfmAboutBox::LabelSendMouseLeave(TObject *Sender)
{
	// ������ �����
	LabelSend->Font->Color = clBlack;
	LabelSend->Font->Style = TFontStyles();
}
//---------------------------------------------------------------------------

void __fastcall TfmAboutBox::LabelOpenSiteDblClick(TObject *Sender)
{
	try {
		ShellExecute(Handle, L"open", L"http://uran-ndt.ru/", NULL, NULL, SW_SHOWDEFAULT);
	}
	catch (Exception *ex) {
		Application->MessageBoxW(ex->Message.c_str(), L"������!", MB_ICONERROR);
	}
}
//---------------------------------------------------------------------------

void __fastcall TfmAboutBox::LabelOpenSiteMouseEnter(TObject *Sender)
{
	// ������ �����
	LabelOpenSite->Font->Color = clBlue;
	LabelOpenSite->Font->Style = TFontStyles() << fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TfmAboutBox::LabelOpenSiteMouseLeave(TObject *Sender)
{
	// ������ �����
	LabelOpenSite->Font->Color = clBlack;
	LabelOpenSite->Font->Style = TFontStyles();
}
//---------------------------------------------------------------------------

