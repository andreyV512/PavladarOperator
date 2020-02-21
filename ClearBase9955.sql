--очистиь базу с периода меньше @tme

USE [buran9955Pa]
GO

declare @tme varchar(30)
select @tme = '20190501';

delete
  FROM [dbo].[resultThick] 
  where [rec_id] in( 
SELECT 
     c.rec_id 
  FROM [dbo].[resultTubeShort] s
  join [dbo].[resultThick] c
  on s.numTube = c.numFusion and s.numFusion = c.numFusion 
  where  dtmCreate < @tme
  )

  delete
  FROM [dbo].[resultCross] 
  where [rec_id] in( 
SELECT 
     c.rec_id 
  FROM [dbo].[resultTubeShort] s
  join [dbo].[resultCross] c
  on s.numTube = c.numFusion and s.numFusion = c.numFusion 
  where  dtmCreate < @tme
  )

  delete
  FROM [dbo].[resultLong] 
  where [rec_id] in( 
SELECT 
     c.rec_id 
  FROM [dbo].[resultTubeShort] s
  join [dbo].[resultLong] c
  on s.numTube = c.numFusion and s.numFusion = c.numFusion 
  where  dtmCreate < @tme
  )

delete
  FROM [dbo].[resultTubeShort] 
  where  dtmCreate < @tme

GO


