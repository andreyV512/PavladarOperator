//---------------------------------------------------------------------------

#ifndef unFmBackupH
#define unFmBackupH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include "unTUtils.h"
#include "unSQLDbModule.h"
//---------------------------------------------------------------------------
class TfmCreateBackup : public TForm
{
__published:	// IDE-managed Components
	TPanel *panelTop;
	TLabel *lblPath;
	TPanel *PanelButtoms;
	TBitBtn *bbtCreate;
	TBitBtn *bbtSaveBackup;
	TADOQuery *gueryBkp;
	void __fastcall bbtCreateClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
AnsiString strFile;
public:		// User declarations
	__fastcall TfmCreateBackup(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmCreateBackup *fmCreateBackup;
//---------------------------------------------------------------------------
#endif
