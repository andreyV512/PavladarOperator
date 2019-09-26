//---------------------------------------------------------------------------

#ifndef CleanDataBaseThreadH
#define CleanDataBaseThreadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class CleanDataBaseThread : public TThread
{
private:
protected:
	void *f;
	void __fastcall Execute();
	void __fastcall UpdateCaption();
public:
	__fastcall CleanDataBaseThread(void *f);
};
//---------------------------------------------------------------------------
#endif
