//---------------------------------------------------------------------------

#ifndef unFmGSettingsH
#define unFmGSettingsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------
#include "unSQLDbModule.h"
#include "unTGlSettings.h"
#include "unTUtils.h"

//---------------------------------------------------------------------------
class TfmGSettings : public TForm
{
__published:	// IDE-managed Components
	TADOQuery *queryGSettings;
	TDBGrid *gridGSettings;
	TDBNavigator *navGSettings;
	TDataSource *dsGSettings;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall gridGSettingsDblClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfmGSettings(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmGSettings *fmGSettings;
//---------------------------------------------------------------------------
#endif
