// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "unFmBackup.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmCreateBackup *fmCreateBackup;

// ---------------------------------------------------------------------------
__fastcall TfmCreateBackup::TfmCreateBackup(TComponent* Owner) : TForm(Owner)

{
	strFile = "";

	int err = 0;
	AnsiString strSql = "";
	try {

		strFile =
			"C:\Program Files (x86)\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\buran9955Pa.bak";
		strSql = "BACKUP DATABASE [buran9955Pa] TO  DISK = N'" + strFile +
			" WITH NOFORMAT, NOINIT,  NAME = N'buran9955Pa-Полная База данных Резервное копирование', SKIP, NOREWIND, NOUNLOAD,  STATS = 10";
		// BACKUP DATABASE [buran9955Pa] TO  DISK = N'C:\Program Files (x86)\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\buran9955Pa.bak' WITH NOFORMAT, NOINIT,  NAME = N'buran9955Pa-Полная База данных Резервное копирование', SKIP, NOREWIND, NOUNLOAD,  STATS = 10
		lblPath->Caption = strFile;
		strFile += strSql;
		gueryBkp->SQL->Text = strSql;
		gueryBkp->ExecSQL();
	}
	catch (Exception *ex) {
		err = -1;
		TLog::ErrFullSaveLog(ex);
		// AnsiString msg
		// programSettings.colorMSG = programSettings.colorBrak;
		// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
		MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
	}

}

// ---------------------------------------------------------------------------
void __fastcall TfmCreateBackup::bbtCreateClick(TObject *Sender) {
int err = 0;
AnsiString strSql = "";
//GetIntFieldSQL(AnsiString _tableName, AnsiString _fieldName, AnsiString _where, int _default, int &err)
try {
	strFile =SqlDBModule->GetStrFieldSQL("currentSettings","ParamValueStr","isActual=1  and UPPER(ParamName)=UPPER('backupPath')",1,err);

	strSql+= "BACKUP DATABASE [buran9955Pa] TO  DISK = N'" + strFile +
		" WITH NOFORMAT, NOINIT,  NAME = N'buran9955Pa-Полная База данных Резервное копирование', SKIP, NOREWIND, NOUNLOAD,  STATS = 10";
	// BACKUP DATABASE [buran9955Pa] TO  DISK = N'C:\Program Files (x86)\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\buran9955Pa.bak' WITH NOFORMAT, NOINIT,  NAME = N'buran9955Pa-Полная База данных Резервное копирование', SKIP, NOREWIND, NOUNLOAD,  STATS = 10
	lblPath->Caption = strFile;
	strFile += strSql;
	gueryBkp->SQL->Text = strSql;
	gueryBkp->ExecSQL();
}
catch (Exception *ex) {
	err = -1;
	TLog::ErrFullSaveLog(ex);
	// AnsiString msg
	// programSettings.colorMSG = programSettings.colorBrak;
	// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
	MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
}
}
// ---------------------------------------------------------------------------

void __fastcall TfmCreateBackup::FormCreate(TObject * Sender) {
int err = 0;
try {
	AnsiString strSql = "";
	AnsiString strBkbFile = "";
	// strSql="BACKUP DATABASE [buran9955Pa] TO  DISK = N";
	// strFile
	strFile = "BACKUP DATABASE [buran9955Pa] TO  DISK = N";
	// strSql+="C:\Program Files (x86)\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\buran9955Pa.bak";
	strSql +
		" WITH NOFORMAT, NOINIT,  NAME = N'buran9955Pa-Полная База данных Резервное копирование', SKIP, NOREWIND, NOUNLOAD,  STATS = 10";
	strBkbFile = "";
	lblPath->Caption = "Путь и имя файла резервной копии:";
	lblPath->Caption = strSql;
}
catch (Exception *ex) {
	err = -1;
	TLog::ErrFullSaveLog(ex);
	// AnsiString msg
	// programSettings.colorMSG = programSettings.colorBrak;
	// TExtFunction::UpdateStatusBar(programSettings.gsStatusBar, strStatus, _msg, programSettings.colorMSG);
	MessageDlg(ex->Message, mtError, TMsgDlgButtons() << mbOK, NULL);
}
}
// ---------------------------------------------------------------------------
