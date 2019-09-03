//---------------------------------------------------------------------------

#ifndef unFmModifyRecordH
#define unFmModifyRecordH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//--------------
#include "unSQLDbModule.h"
#include "unTUtils.h"
#include "unTExtFunction.h"
#include "unTGlSettings.h"
//---------------------------------------------------------------------------
class TfmModifyRecord : public TForm
{
__published:	// IDE-managed Components
	TPanel *pnlBottom;
	TBitBtn *bbtModDel;
	TBitBtn *bbtRestore;
	TBitBtn *bbtClose;
	TListBox *lbxDeleted;
	TPanel *pnlLeft;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *edtDelete;
	TEdit *edtRestore;
	TADOQuery *queryDelRestor;
	void __fastcall FormResize(TObject *Sender);
	void __fastcall lbxDeletedClick(TObject *Sender);
	void __fastcall bbtRestoreClick(TObject *Sender);
	void __fastcall bbtCloseClick(TObject *Sender);
	void __fastcall bbtModDelClick(TObject *Sender);
private:	// User declarations
int newNumTube;
int delNumTube;
public:		// User declarations
	__fastcall TfmModifyRecord(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmModifyRecord *fmModifyRecord;
//---------------------------------------------------------------------------
#endif
