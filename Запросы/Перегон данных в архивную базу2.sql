
--tubesTypeSize
DROP TABLE [buran9955PaArh1].[dbo].[tubesTypeSize]
select * into  [buran9955PaArh1].[dbo].[tubesTypeSize] from [buran9955Pa].[dbo].[tubesTypeSize]; 
--[workShifts]
--
DROP TABLE [buran9955PaArh1].[dbo].[workShifts]
select * into  [buran9955PaArh1].[dbo].[workShifts] from [buran9955Pa].[dbo].[workShifts]; 
--TypeSizesParams
DROP TABLE [buran9955PaArh1].[dbo].[TypeSizesParams]
select * into  [buran9955PaArh1].[dbo].[TypeSizesParams] from [buran9955Pa].[dbo].[TypeSizesParams]; 
--steelGrades
DROP TABLE [buran9955PaArh1].[dbo].[steelGrades];
select * into  [buran9955PaArh1].[dbo].[steelGrades] from [buran9955Pa].[dbo].[steelGrades];
--Sops
DROP TABLE [buran9955PaArh1].[dbo].[Sops];
select * into  [buran9955PaArh1].[dbo].[Sops] from [buran9955Pa].[dbo].[Sops];
--operators
DROP TABLE [buran9955PaArh1].[dbo].[operators];
select * into  [buran9955PaArh1].[dbo].[operators] from [buran9955Pa].[dbo].[operators];
--[normDocs]
DROP TABLE [buran9955PaArh1].[dbo].[normDocs];
select * into  [buran9955PaArh1].[dbo].[normDocs] from [buran9955Pa].[dbo].[normDocs];
--gridTubesColWidth
DROP TABLE [buran9955PaArh1].[dbo].[gridTubesColWidth];
select * into  [buran9955PaArh1].[dbo].[gridTubesColWidth] from [buran9955Pa].[dbo].[gridTubesColWidth];
--flags
DELETE FROM [buran9955PaArh1].[dbo].[flags]
INSERT INTO [buran9955PaArh1].[dbo].[flags]
([isReady],[isActual],[isTransportReady],[isDefectoskopReady],[isDataSendCompleet]
,[isSOP],[isWorkState],[isBackupProcess])
values (0,1,0,0,0,0,0,0)
DROP TABLE [buran9955PaArh1].[dbo].[currentSettings];
select * into  [buran9955PaArh1].[dbo].[currentSettings] from [buran9955Pa].[dbo].[currentSettings];
--resultTubeShort
DROP TABLE [buran9955PaArh1].[dbo].[resultTubeShort];
select * into  [buran9955PaArh1].[dbo].[resultTubeShort] from [buran9955Pa].[dbo].[resultTubeShort];
--resultThick
DROP TABLE [buran9955PaArh1].[dbo].[resultThick];
select * into  [buran9955PaArh1].[dbo].[resultThick] from [buran9955Pa].[dbo].[resultThick];
--[resultCross]
DROP TABLE [buran9955PaArh1].[dbo].[resultCross];
select * into  [buran9955PaArh1].[dbo].[resultCross] from [buran9955Pa].[dbo].[resultCross];
--[resultLong]
DROP TABLE [buran9955PaArh1].[dbo].[resultCross];
select * into  [buran9955PaArh1].[dbo].[resultCross] from [buran9955Pa].[dbo].[resultLong];
--[ResultPars]
DROP TABLE [buran9955PaArh1].[dbo].[ResultPars];
select * into  [buran9955PaArh1].[dbo].[ResultPars] from [buran9955Pa].[dbo].[ResultPars];
USE [buran9955PaArh1]
GO
DBCC SHRINKDATABASE(N'buran9955PaArh1', 10 )
GO





