// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "unFmGSettings.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmGSettings *fmGSettings;

// ---------------------------------------------------------------------------
__fastcall TfmGSettings::TfmGSettings(TComponent* Owner) : TForm(Owner) {

}

// ---------------------------------------------------------------------------
void __fastcall TfmGSettings::FormCreate(TObject *Sender) {
	queryGSettings->Open();
	gridGSettings->Columns->Items[0]->Width=200;
}

// ---------------------------------------------------------------------------
void __fastcall TfmGSettings::FormClose(TObject *Sender, TCloseAction &Action) {
	queryGSettings->Close();
}

// ---------------------------------------------------------------------------
void __fastcall TfmGSettings::FormCloseQuery(TObject *Sender, bool &CanClose) {
	if (queryGSettings->State == dsEdit) {
		if (MessageDlg("Есть несохраенные данные, все равно выйти?",
		mtWarning, TMsgDlgButtons() << mbOK << mbCancel,0) == mrOk) {
		   queryGSettings->Cancel();
		   CanClose=true;
		}else{
		   CanClose=false;
		}
	}
	else {

	}
}
// ---------------------------------------------------------------------------
void __fastcall TfmGSettings::gridGSettingsDblClick(TObject *Sender)
{
 	UnicodeString NewString = "";
	if (gridGSettings->ReadOnly == true) {
		if (InputQuery("Запрос пароля", "Введите пароль:", NewString)) {
			if (NewString != TGlSettings::passwordEdit) {
				MessageDlg("Неверный пароль!", mtError,
					TMsgDlgButtons() << mbOK, NULL);
				queryGSettings->Cancel();
			}
			else {
				gridGSettings->ReadOnly = false;
                 gridGSettings->Columns->Items[0]->ReadOnly=true;
				 gridGSettings->Columns->Items[1]->ReadOnly=true;
				gridGSettings->Color = clYellow;
				gridGSettings->FixedColor=clYellow;
				queryGSettings->Edit();
			}
		}
		else {
			//
		}
	}else{
		//
    }
}
//---------------------------------------------------------------------------

void __fastcall TfmGSettings::FormResize(TObject *Sender)
{
 gridGSettings->Columns->Items[0]->ReadOnly=true;
 gridGSettings->Columns->Items[0]->Color=clBtnFace;
 gridGSettings->Columns->Items[1]->ReadOnly=true;
 gridGSettings->Columns->Items[1]->Color=clBtnFace;
}
//---------------------------------------------------------------------------

