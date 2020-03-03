//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("unSetDirectory.cpp", fmSetDirectory);
USEFORM("unShowListTubes.cpp", fmShowListTubes);
USEFORM("unMain.cpp", fmMain);
USEFORM("unFmViewZone.cpp", fmViewZone);
USEFORM("Unit1.cpp", Form1);
USEFORM("unSQLDbModule.cpp", SqlDBModule); /* TDataModule: File Type */
USEFORM("unFmShowZones.cpp", fmShowZones);
USEFORM("unFmBackup.cpp", fmCreateBackup);
USEFORM("ABOUT_NTC_NK_URAN.cpp", fmAboutBox);
USEFORM("unFmModifyRecord.cpp", fmModifyRecord);
USEFORM("unFmReport.cpp", fmReport);
USEFORM("unFmGSettings.cpp", fmGSettings);
USEFORM("unFmInfo.cpp", fmInfo);
USEFORM("unFmMessage.cpp", fmMessage);
USEFORM("QueryMessageForm.cpp", MessageForm);
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
		Application->CreateForm(__classid(TfmMessage), &fmMessage);
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
