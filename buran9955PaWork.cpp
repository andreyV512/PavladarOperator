//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("unSetDirectory.cpp", fmSetDirectory);
USEFORM("unShowListTubes.cpp", fmShowListTubes);
USEFORM("unMain.cpp", fmMain);
USEFORM("unFmShowZones.cpp", fmShowZones);
USEFORM("unFmViewZone.cpp", fmViewZone);
USEFORM("unSQLDbModule.cpp", SqlDBModule); /* TDataModule: File Type */
USEFORM("unFmBackup.cpp", fmCreateBackup);
USEFORM("ABOUT_NTC_NK_URAN.cpp", fmAboutBox);
USEFORM("unFmModifyRecord.cpp", fmModifyRecord);
USEFORM("unFmReport.cpp", fmReport);
USEFORM("unFmMessage.cpp", fmMessage);
USEFORM("unFmGSettings.cpp", fmGSettings);
USEFORM("unFmInfo.cpp", fmInfo);
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
		Application->CreateForm(__classid(TMessageForm), &MessageForm);
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
