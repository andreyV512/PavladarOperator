	USE [buran9955Pa]
GO
	
	select PLine from dbo.ResultPars
	where Fusion=6190150 and  tube=200
	--select t.x.value('BorderUp[1]','float') from @xml.nodes('RTPars1/rtTS') as t(x);
	--select @ret1=t.x.value('double[1]','float') FROM @xml.nodes('RDPars1/Revolutions') as t(x)