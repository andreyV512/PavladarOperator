//---------------------------------------------------------------------------

#ifndef QueryMessageFormH
#define QueryMessageFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMessageForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *labelText;
	TLabel *labelTime;
	TTimer *Timer1;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
    unsigned currentTime;
public:		// User declarations
	__fastcall TMessageForm();
};
//---------------------------------------------------------------------------
#endif
