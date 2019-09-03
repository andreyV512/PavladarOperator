// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "unFmReport.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmReport *fmReport;

// ---------------------------------------------------------------------------
__fastcall TfmReport::TfmReport(TComponent* Owner, TADOQuery *_pqueryShowTube) : TForm(Owner) {
	pqueryShowTube = _pqueryShowTube;
}

// ---------------------------------------------------------------------------
void __fastcall TfmReport::BitBtn1Click(TObject *Sender) {
	RichEdit->Print("Протокол");
}

// ---------------------------------------------------------------------------
void __fastcall TfmReport::bbtTstClick(TObject *Sender) {
//	// RichEdit->PaintTo(&BitBtn2->Handle,0,0 );
//	// RichEdit->pa
//	memoRtf->Clear();
//	AnsiString strOut = "";
//	// memoRtf->sa
//	if (streamRtf = NULL) {
//		//
//	}
//	else {
//		//streamRtf->Free();
//		delete streamRtf;
//		streamRtf = NULL;
//	}
//	streamRtf = new TStringStream();
//	// streamRtf->Clear;
//	//RichEdit->Lines->Add(strOut);
//	//strOut = "{\\rtf1\\ansi\\ansicpg1251";
//	streamRtf->WriteString("{\\rtf1\\ansi\\ansicpg1251");
//	//RichEdit->Lines->Add(strOut);
//	strOut = ;
//	//RichEdit->Lines->Add(strOut);
//	strOut += ;
//	//RichEdit->Lines->Add(strOut);
//	strOut += ;
//	//RichEdit->Lines->Add(strOut);
//	strOut += ;
//	//RichEdit->Lines->Add(strOut);
//	strOut += ;
//	//RichEdit->Lines->Add(strOut);
//	strOut += ;
//	//RichEdit->Lines->Add(strOut);
//	strOut += ;
//	//RichEdit->Lines->Add(strOut);
//	strOut += ;
//	//RichEdit->Lines->Add(strOut);
//	strOut += ;
//	//RichEdit->Lines->Add(strOut);
//	//strOut += "\\cf0\\f0 Text11 Text21 Text31 \\par ";
//	//RichEdit->Lines->Add(strOut);
//	//strOut += "\\cf1\\f1 text12 text22 text32 \\par ";
//	strOut +="\\cf0\\f0 Text1 \\cell text2 \\cell text3 \\row";
//	//RichEdit->Lines->Add(strOut);
//	strOut += "}";
//	//...{\lang1033\cgrid0<содержимое 1-й ячейки>\cell<содержимое 2-й ячейки>\cell}…
//	//\раr - конец абзаца;
//	//\сеll - конец столбца;
//	// \row - конец строки (или таблицы);
//    RichEdit->Clear();
//	//RichEdit->Lines->Add(strOut);
//	streamRtf->WriteString(strOut);
//	//RichEdit->Lines->SaveToStream(streamRtf);
//	int L=streamRtf->Position;
//	streamRtf->Seek((int)0,(Word)soBeginning);
//	streamRtf->SaveToFile("e:\\PRG\\BURAN-9955PaWork\\Help\\stream.rtf");
//    L=streamRtf->Position;
//	//streamRtf->;
//	RichEdit->Clear();
//	RichEdit->Lines->LoadFromStream(streamRtf);
//	//RichEdit->Lines->LoadFromFile("e:\\PRG\\BURAN-9955PaWork\\Help\\rtfl.rtf");
//	//streamRtf->Position=0;
//	// streamRtf->
}
// ---------------------------------------------------------------------------

void __fastcall TfmReport::FormClose(TObject * Sender, TCloseAction & Action) {
	if (streamRtf) {
		//streamRtf->Free();
		delete streamRtf;
		streamRtf = NULL;
	}
	else {

	}
}
// ---------------------------------------------------------------------------
