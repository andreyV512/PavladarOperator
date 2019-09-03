//---------------------------------------------------------------------------

#ifndef unFmInfoH
#define unFmInfoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
#include "unTExtFunction.h"
#include "unTUtils.h"
#include "unSQLDbModule.h"

class TfmInfo : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TBitBtn *bbtClose;
	TLabeledEdit *lbeIp4;
	TLabeledEdit *lbeFreeSpaceM;
	TLabeledEdit *lbeFreeSpaceP;
	TLabeledEdit *lbeSzDB;
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfmInfo(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmInfo *fmInfo;
//---------------------------------------------------------------------------
#endif
