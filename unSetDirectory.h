//---------------------------------------------------------------------------

#ifndef unSetDirectoryH
#define unSetDirectoryH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "unSQLDbModule.h"
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.AppEvnts.hpp>
#include "unTGlSettings.h"
//---------------------------------------------------------------------------
class TfmSetDirectory : public TForm
{
__published:	// IDE-managed Components
	TDataSource *DataSource;
	TDBNavigator *DBNavigator;
	TDBGrid *DBGridDirectory;
	TADOQuery *queryDirectory;
	TApplicationEvents *ApplicationEvents;
	TListBox *lbxFields;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall DBGridDirectoryDblClick(TObject *Sender);
	void __fastcall ApplicationEventsMessage(tagMSG &Msg, bool &Handled);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall queryDirectoryBeforePost(TDataSet *DataSet);
	void __fastcall FormResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfmSetDirectory(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmSetDirectory *fmSetDirectory;
//---------------------------------------------------------------------------
#endif
