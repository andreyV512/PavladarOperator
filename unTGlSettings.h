// ---------------------------------------------------------------------------

#ifndef unTGlSettingsH
#define unTGlSettingsH
#include <System.hpp>
#include <Windows.hpp>
#include <SysUtils.hpp>
#include <Classes.hpp>
//---------
#include "unSQLDbModule.h"

// ---------------------------------------------------------------------------
class TGlSettings {
public:
	TGlSettings();
	~TGlSettings(void);

	static int countZones;
	static int countRecordsThick;
	static int countSensorsLong;
	static int countSensorsCross;
	static UINT msgFmViewZone;
	static UINT msgReloadSettings;
	static AnsiString myIP;
	static AnsiString fullNameBkpFile;
	static AnsiString passwordEdit;
	static int currFusion;
	static int currFusionOld;
	static int numTube;
	static int numTubeOld;
	static int indTypeSize;
	static int indSteelGradeName;
	static int indNormDocName;
	static int indOperatorName;
	static int indWorkShiftName;
	static int indSopName;
	static double thresholdC1;
	static double thresholdC2;
	static double thresholdL1;
	static double thresholdL2;
	static double thresholdTUp;
	static double thresholdTDown;
	static double thresholdTNominal;
	static bool isWorkState;
	static double currMagnetC;
	static double currMagnetL;
	static double currMagnetT;
    static double speedRotor;
	static int countBrakC;
	static int countBrakL;
	static int countBrakT;
	static int countBrakALL;
	//static bool repeatControl;
    static int repeatControlNumTube;
	//static int isSOP;
	//---------------
	static double tmpThresholdTUp;
	static double tmpThresholdTDown;
	//static int countTubesFusion;
private:
	//
	};
// ----
int TGlSettings::countZones;
int TGlSettings::countRecordsThick;
int TGlSettings::countSensorsLong;
int TGlSettings::countSensorsCross;
//UINT TGlSettings::msgFmViewZone = WM_USER + 11;
UINT TGlSettings::msgReloadSettings=WM_APP+10;
UINT TGlSettings::msgFmViewZone = WM_APP+11;
AnsiString TGlSettings::myIP = "127.0.0.1";
AnsiString TGlSettings::fullNameBkpFile;
AnsiString TGlSettings::passwordEdit;
int TGlSettings::currFusion;
int TGlSettings::currFusionOld;
int TGlSettings::numTube;
int TGlSettings::numTubeOld;
int TGlSettings::indTypeSize;
int TGlSettings::indSteelGradeName;
int TGlSettings::indNormDocName;
int TGlSettings::indOperatorName;
int TGlSettings::indWorkShiftName;
int TGlSettings::indSopName;
double TGlSettings::thresholdC1;
double TGlSettings::thresholdC2;
double TGlSettings::thresholdL1;
double TGlSettings::thresholdL2;
double TGlSettings::thresholdTUp;
double TGlSettings::thresholdTDown;
double TGlSettings::thresholdTNominal;
bool TGlSettings::isWorkState;
//bool TGlSettings::repeatControl;
int TGlSettings::repeatControlNumTube;
//int TGlSettings::countTubesFusion;
int TGlSettings::countBrakC;
int TGlSettings::countBrakL;
int TGlSettings::countBrakT;
int TGlSettings::countBrakALL;
double TGlSettings::currMagnetC;
double TGlSettings::currMagnetL;
double TGlSettings::currMagnetT;
double TGlSettings::speedRotor;
//int TGlSettings::isSOP;
//----------
double TGlSettings::tmpThresholdTUp;
double TGlSettings::tmpThresholdTDown;
#endif
