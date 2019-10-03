//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("unMain.cpp", fmMain);
USEFORM("unSetDirectory.cpp", fmSetDirectory);
USEFORM("unFmViewZone.cpp", fmViewZone);
USEFORM("unFmReport.cpp", fmReport);
USEFORM("unFmShowZones.cpp", fmShowZones);
USEFORM("unShowListTubes.cpp", fmShowListTubes);
USEFORM("unSQLDbModule.cpp", SqlDBModule); /* TDataModule: File Type */
USEFORM("unFmModifyRecord.cpp", fmModifyRecord);
USEFORM("ABOUT_NTC_NK_URAN.cpp", fmAboutBox);
USEFORM("QueryMessageForm.cpp", MessageForm);
USEFORM("unFmInfo.cpp", fmInfo);
USEFORM("unFmMessage.cpp", fmMessage);
USEFORM("unFmGSettings.cpp", fmGSettings);
USEFORM("unFmBackup.cpp", fmCreateBackup);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TSqlDBModule), &SqlDBModule);
		Application->CreateForm(__classid(TfmMain), &fmMain);
		Application->CreateForm(__classid(TfmModifyRecord), &fmModifyRecord);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
