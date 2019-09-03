// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "unSetDirectory.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmSetDirectory *fmSetDirectory;

// ---------------------------------------------------------------------------
__fastcall TfmSetDirectory::TfmSetDirectory(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TfmSetDirectory::FormClose(TObject *Sender,
	TCloseAction &Action) {
	queryDirectory->Close();
	PostMessage(Application->Handle, TGlSettings::msgReloadSettings, 0, 0);
	bool RHKret =	UnregisterHotKey(this->Handle, 0x00F);
}

// ---------------------------------------------------------------------------
void __fastcall TfmSetDirectory::DBGridDirectoryDblClick(TObject *Sender) {
	UnicodeString NewString = "";
	if (DBGridDirectory->ReadOnly == true) {
		if (InputQuery((UnicodeString)"Запрос пароля", (UnicodeString)"Введите пароль:", NewString)) {
			if (NewString != TGlSettings::passwordEdit) {
				MessageDlg("Неверный пароль!", mtError,
					TMsgDlgButtons() << mbOK, NULL);
				queryDirectory->Cancel();
			}
			else {
				DBGridDirectory->ReadOnly = false;
				DBGridDirectory->Color = clInfoBk;
				DBGridDirectory->FixedColor=clYellow;
				queryDirectory->Edit();
			}
		}
		else {
			//
		}
	}else{
		//
    }

}
// ---------------------------------------------------------------------------


void __fastcall TfmSetDirectory::ApplicationEventsMessage(tagMSG &Msg, bool &Handled)
{
 	// Проверяем на нажатие сочетания клавиш Ctrl+Alt+Enter
	if (Msg.message == WM_HOTKEY) // сообщение наше
	{
		//if (Msg.wParam == 0x00F) // идентификатор наш
//		{
//			Handled = true;
//			navA1730Settings->Enabled = !(navA1730Settings->Enabled);
//			gridA1730Settings->ReadOnly = !(gridA1730Settings->ReadOnly);
//			if (gridA1730Settings->ReadOnly) {
//				gridA1730Settings->Color = clInfoBk;
//			}
//			else {
//				gridA1730Settings->Color = clMoneyGreen;
//			}
//			Application->ProcessMessages();
//		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TfmSetDirectory::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if (queryDirectory->State == dsEdit) {
		if (MessageDlg("Есть несохраенные данные, все равно выйти?",
		mtWarning, TMsgDlgButtons() << mbOK << mbCancel,0) == mrOk) {
		   queryDirectory->Cancel();
		   CanClose=true;
		}else{
		   CanClose=false;
		}
	}
	else {

	}
}
//---------------------------------------------------------------------------

void __fastcall TfmSetDirectory::queryDirectoryBeforePost(TDataSet *DataSet)
{
 AnsiString tmpStr =""; //[isActive]
// tmpStr=queryDirectory->FieldByName("isActive")->AsString ;
// if (tmpStr=="") {
//   MessageDlg("Поле Активно обязательно для заполнения!\ 0 - помечена как удаленное \1 - используется в работе",
//		mtWarning, TMsgDlgButtons() << mbOK,0);
// }else{
//  //
// }
}
//---------------------------------------------------------------------------

void __fastcall TfmSetDirectory::FormResize(TObject *Sender)
{
 // int tt=DBGridDirectory->Columns->Count;
// if (queryDirectory-> ) {
//
// }
 DBGridDirectory->Columns->Items[0]->Width=120;
 lbxFields->Clear();
 queryDirectory->GetFieldNames(lbxFields->Items);
 AnsiString ss=lbxFields->Items->Strings[0] ;
 if (ss=="№") {
	DBGridDirectory->Columns->Items[0]->ReadOnly=true;
    DBGridDirectory->Columns->Items[0]->Color=clGray;
 }else{
     //
 }
  //
}
//---------------------------------------------------------------------------

