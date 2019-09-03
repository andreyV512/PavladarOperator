//---------------------------------------------------------------------------

#ifndef unFmReportH
#define unFmReportH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Dialogs.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TfmReport : public TForm
{
__published:	// IDE-managed Components
	TRichEdit *RichEdit;
	TPanel *Panel1;
	TBitBtn *BitBtn1;
	TPrintDialog *PrintDialog;
	TPrinterSetupDialog *PrinterSetupDialog;
	TBitBtn *bbtTst;
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall bbtTstClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
TADOQuery *pqueryShowTube;
public:		// User declarations
	__fastcall TfmReport(TComponent* Owner,TADOQuery *_pqueryShowTube);
    TStringStream* streamRtf;
};
//---------------------------------------------------------------------------
extern PACKAGE TfmReport *fmReport;
//---------------------------------------------------------------------------
#endif
