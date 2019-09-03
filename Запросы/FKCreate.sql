USE [buran9955Pa]
GO

ALTER TABLE [dbo].[resultThick] DROP CONSTRAINT [FK_resultThick_resultTubeShort]
GO

ALTER TABLE [dbo].[resultThick]  WITH CHECK ADD  CONSTRAINT [FK_resultThick_resultTubeShort] FOREIGN KEY([numFusion], [numTube])
REFERENCES [dbo].[resultTubeShort] ([numFusion], [numTube])
ON UPDATE CASCADE
ON DELETE CASCADE
GO

ALTER TABLE [dbo].[resultThick] CHECK CONSTRAINT [FK_resultThick_resultTubeShort]
GO


