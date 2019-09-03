USE [buran9955Pa]
GO
set statistics time on
declare @numFus int,@numTub int
set @numFus = 6190015
set @numTub = 22

DELETE FROM [dbo].[resultTubeShort]
      where [numFusion]=0
   and [numTube]=0
--GO
INSERT INTO [dbo].[resultTubeShort]
           ([indTypeSize]
           ,[indSteelGradeName]
           ,[indNormDocName]
           ,[indOperatorName]
           ,[indWorkShiftName]
           ,[indSopName]
           ,[numTube]
           ,[numFusion]
           ,[dtmCreate]
           ,[pathFileNameLong]
           ,[resultC]
           ,[countZones]
           ,[speedTube]
           ,[lengthTube]
           ,[resultL]
           ,[resultT]
           ,[thresholdC1]
           ,[thresholdC2]
           ,[thresholdL1]
           ,[thresholdL2]
           ,[thresholdTUp]
           ,[thresholdTDown]
           ,[isEmpty]
           ,[thresholdTNominal]
           ,[strParams]
           ,[currentMagnetC]
           ,[pathFileNameCross]
           ,[pathFileNameThick]
           ,[countZonesT]
           ,[countZonesL]
           ,[countZonesC]
           ,[isSOP]
           ,[currMagnetL]
           ,[currMagnetT]
           ,[speedRound]
           ,[currentMagnetL]
           ,[currentMagnetT])
     
(SELECT [indTypeSize]
      ,[indSteelGradeName]
      ,[indNormDocName]
      ,[indOperatorName]
      ,[indWorkShiftName]
      ,[indSopName]
      ,0
      ,0
      ,[dtmCreate]
      ,[pathFileNameLong]
      ,[resultC]
      ,[countZones]
      ,[speedTube]
      ,[lengthTube]
      ,[resultL]
      ,[resultT]
      ,[thresholdC1]
      ,[thresholdC2]
      ,[thresholdL1]
      ,[thresholdL2]
      ,[thresholdTUp]
      ,[thresholdTDown]
      ,[isEmpty]
      ,[thresholdTNominal]
      ,[strParams]
      ,[currentMagnetC]
      ,[pathFileNameCross]
      ,[pathFileNameThick]
      ,[countZonesT]
      ,[countZonesL]
      ,[countZonesC]
      ,[isSOP]
      ,[currMagnetL]
      ,[currMagnetT]
      ,[speedRound]
      ,[currentMagnetL]
      ,[currentMagnetT]
  FROM [dbo].[resultTubeShort]
  where [numFusion]= @numFus
   and [numTube]=@numTub)
set statistics time off
GO

 

