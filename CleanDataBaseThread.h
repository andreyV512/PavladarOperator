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
public:
	__fastcall CleanDataBaseThread(void *f);
    static void CloseWindow(void *param);
};
//---------------------------------------------------------------------------
#endif
