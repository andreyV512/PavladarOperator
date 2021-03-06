USE [buran9955Pa]
GO
/****** Object:  UserDefinedFunction [dbo].[GetBorder1]    Script Date: 07.02.2019 10:00:45 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
alter FUNCTION [dbo].[GetCurrDemagnet]
(
	@typeSz varchar(256)
)
returns varchar(256)
as 
BEGIN
	declare @ret1 varchar(256)
	SELECT @ret1=[Path] FROM [buran9955Pa].[dbo].[Parameters]  
	where Path like('ParAll.ST.TSSet%Name') and Val=@typeSz
    declare @ret2 int
	SELECT  @ret2=[Val]FROM [buran9955Pa].[dbo].[Parameters] 
    where Path like(substring(@ret1,1,15)+ '%Rectifier.NominalI')	
	RETURN 	@ret2
END
