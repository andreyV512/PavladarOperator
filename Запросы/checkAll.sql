USE [buran9955Pa]
GO

select T1.numFusion,T1.numTube,T2.numFusion as numFusionT,T2.numTube as numTubeT 
from resultTubeShort as T1
--full outer join ResultPars as T2
--on (T1.numFusion=T2.Fusion and T1.numTube=T2.Tube)
--where T1.numFusion is null or T2.Fusion is Null

full outer join resultThick as T2
on (T1.numFusion=T2.numFusion and T1.numTube=T2.numTube)
where T1.numFusion is null or T2.numFusion is Null


order by T1.numFusion

--delete from resultLong
--where numFusion=4816 and numTube=19
--delete from resultThick
--where numFusion=4816 and numTube=19

--delete from resultTubeShort
--where numFusion=6190148 and numTube=19

select T1.numFusion,T1.numTube,T2.numFusion as numFusionL,T2.numTube as numTubeL 
from resultTubeShort as T1
--full outer join ResultPars as T2
--on (T1.numFusion=T2.Fusion and T1.numTube=T2.Tube)
--where T1.numFusion is null or T2.Fusion is Null

full outer join resultLong as T2
on (T1.numFusion=T2.numFusion and T1.numTube=T2.numTube)
where T1.numFusion is null or T2.numFusion is Null



