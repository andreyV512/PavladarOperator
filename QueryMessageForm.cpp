// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "QueryMessageForm.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMessageForm *MessageForm;

// ---------------------------------------------------------------------------
__fastcall TMessageForm::TMessageForm(TComponent* Owner) : TForm(Owner) {
	currentTime = 0;
	Application->NormalizeTopMosts();
	Application->ProcessMessages();
}

// ---------------------------------------------------------------------------
void __fastcall TMessageForm::Timer1Timer(TObject *Sender) {
	currentTime++;

	TVarRec args[] = {currentTime / 60, currentTime % 60};
	labelTime->Caption = Format("%02d:%02d", args, 2);
	//labelTime->Refresh();
}

// ---------------------------------------------------------------------------
void __fastcall TMessageForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    Application->RestoreTopMosts();
}
//---------------------------------------------------------------------------

