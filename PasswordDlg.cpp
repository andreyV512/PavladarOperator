//---------------------------------------------------------------------------

#pragma hdrstop

#include "PasswordDlg.h"
#include "unTGlSettings.h"
#include <dialogs.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)

bool PasswordDlg()
{
	bool res = true;
	UnicodeString newString;
	if (InputQuery((UnicodeString)"������ ������", (UnicodeString)"������� ������:", newString)) {
		if (newString != TGlSettings::passwordEdit) {
			MessageDlg("�������� ������!", mtError, TMsgDlgButtons() << mbOK, NULL);
			res = false;
		}
	}
	else {
		res = false;
	}
	return res;
}
