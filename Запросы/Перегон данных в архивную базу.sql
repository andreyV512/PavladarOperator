
--tubesTypeSize
--SELECT [tubeDiam] ,[tubeThick],[isOk],[typeSizeName],[isActive],[rec_id]
--      FROM [buran9955Pa].[dbo].[tubesTypeSize]
declare @dbDest varchar(256);
set @dbDest='';
GO
delete FROM [buran9955PaArhClear].[dbo].[tubesTypeSize]
GO
INSERT INTO [buran9955PaArhClear].[dbo].[tubesTypeSize]
           ([tubeDiam],[tubeThick],[isOk],[typeSizeName],[isActive],[rec_id])
     (SELECT [tubeDiam] ,[tubeThick],[isOk],[typeSizeName],[isActive],[rec_id]
      FROM [buran9955Pa].[dbo].[tubesTypeSize])
GO
--[workShifts]
--
DELETE FROM [buran9955PaArhClear].[dbo].[workShifts]
INSERT INTO [buran9955PaArhClear].[dbo].[workShifts]
           ([workShiftName],[isActive],[rec_id])
(SELECT [workShiftName],[isActive],[rec_id] FROM [buran9955Pa].[dbo].[workShifts])
GO
--TypeSizesParams
DELETE FROM [buran9955PaArhClear].[dbo].[TypeSizesParams]
GO
INSERT INTO [buran9955PaArhClear].[dbo].[TypeSizesParams]
 ([rec_id],[indTypeSize],[thresholdL1],[thresholdL2],[currMagnetL],[thresholdC1],[thresholdC2],[currMagnetC]
,[thresholdTUp],[thresholdTDown],[currMagnetT],[speedRotor])
(SELECT 
 [rec_id],[indTypeSize],[thresholdL1],[thresholdL2],[currMagnetL],[thresholdC1],[thresholdC2],[currMagnetC]
,[thresholdTUp],[thresholdTDown],[currMagnetT],[speedRotor] FROM [buran9955Pa].[dbo].[TypeSizesParams])
GO
--steelGrades
DELETE FROM [buran9955PaArhClear].[dbo].[steelGrades]
GO
INSERT INTO [buran9955PaArhClear].[dbo].[steelGrades]([steelGradeName],[isActive],[rec_id])
(SELECT [steelGradeName],[isActive],[rec_id] FROM [buran9955Pa].[dbo].[steelGrades])
GO
--Sops
DELETE FROM [buran9955PaArhClear].[dbo].[Sops]
GO
INSERT INTO [buran9955PaArhClear].[dbo].[Sops]
([SopName],[isActive],[rec_id])
(SELECT [SopName],[isActive],[rec_id] FROM [buran9955Pa].[dbo].[Sops])
GO
--operators
DELETE FROM [buran9955PaArhClear].[dbo].[operators]
GO
INSERT INTO [buran9955PaArhClear].[dbo].[operators]
([operatorName],[isActive],[rec_id])
(SELECT [operatorName],[isActive],[rec_id] FROM [buran9955Pa].[dbo].[operators])
GO
--[normDocs]
DELETE FROM [buran9955PaArhClear].[dbo].[normDocs]
GO
INSERT INTO [buran9955PaArhClear].[dbo].[normDocs]
([normDocName],[isActive],[rec_id])
(SELECT [normDocName],[isActive],[rec_id] FROM [buran9955Pa].[dbo].[normDocs])
GO
--gridTubesColWidth
DELETE FROM [buran9955PaArhClear].[dbo].[gridTubesColWidth]
GO
INSERT INTO [buran9955PaArhClear].[dbo].[gridTubesColWidth]
([colNum],[colWidth])
(SELECT [colNum],[colWidth] FROM [buran9955Pa].[dbo].[gridTubesColWidth])
GO
--flags
DELETE FROM [buran9955PaArhClear].[dbo].[flags]
GO
INSERT INTO [buran9955PaArhClear].[dbo].[flags]
([isReady],[isActual],[isTransportReady],[isDefectoskopReady],[isDataSendCompleet]
,[isSOP],[isWorkState],[isBackupProcess])
values (0,1,0,0,0,0,0,0)
GO
DELETE FROM [buran9955PaArhClear].[dbo].[currentSettings]
GO
INSERT INTO [buran9955PaArhClear].[dbo].[currentSettings]
([rec_id],[isActual],[RusName],[ParamName],[ParamValueFloat],[ParamValueStr])
(SELECT [rec_id],[isActual],[RusName],[ParamName],[ParamValueFloat],[ParamValueStr]
  FROM [buran9955Pa].[dbo].[currentSettings])
GO
--resultTubeShort
DELETE FROM [buran9955PaArhClear].[dbo].[resultTubeShort]
INSERT INTO [buran9955PaArhClear].[dbo].[resultTubeShort]
([indTypeSize],[indSteelGradeName],[indNormDocName],[indOperatorName]
,[indWorkShiftName],[indSopName],[numTube],[numFusion],[dtmCreate],[pathFileNameLong]
,[resultC],[countZones],[speedTube],[lengthTube],[resultL]
,[resultT],[thresholdC1],[thresholdC2],[thresholdL1],[thresholdL2],[thresholdTUp],[thresholdTDown],[isEmpty]
,[thresholdTNominal],[strParams],[currentMagnetC],[pathFileNameCross],[pathFileNameThick],[countZonesT],[countZonesL],[countZonesC]
,[isSOP],[currMagnetL],[currMagnetT],[speedRound],[currentMagnetL],[currentMagnetT])
(SELECT [indTypeSize],[indSteelGradeName],[indNormDocName],[indOperatorName],[indWorkShiftName],[indSopName],[numTube],[numFusion]
      ,[dtmCreate],[pathFileNameLong],[resultC],[countZones],[speedTube],[lengthTube],[resultL],[resultT],[thresholdC1],[thresholdC2]
      ,[thresholdL1],[thresholdL2],[thresholdTUp],[thresholdTDown]
      ,[isEmpty],[thresholdTNominal],[strParams],[currentMagnetC],[pathFileNameCross],[pathFileNameThick],[countZonesT]
      ,[countZonesL],[countZonesC],[isSOP],[currMagnetL],[currMagnetT],[speedRound],[currentMagnetL],[currentMagnetT]
  FROM [buran9955Pa].[dbo].[resultTubeShort])
  GO
--resultThick
DELETE FROM [buran9955PaArhClear].[dbo].[resultThick]
  GO
INSERT INTO [buran9955PaArhClear].[dbo].[resultThick]
([Min1],[Min2],[Min3],[Min4],[Min5],[Min6],[Min7],[Min8],[Min9],[Min10],[Min11],[Min12],[Min13],[Min14],[Min15],[Min16]
,[Min17],[Min18],[Min19],[Min20],[Min21],[Min22],[Min23],[Min24],[Min25],[Min26],[Min27],[Min28],[Min29],[Min30],[Min31]
,[Min32],[Min33],[Min34],[Min35],[Min36],[Min37],[Min38],[Min39],[Min40],[Min41],[Min42],[Min43],[Min44],[Min45],[Min46]
,[Min47],[Min48],[Min49],[Min50],[Min51],[Min52],[Min53],[Min54],[Min55],[Min56],[Min57],[Min58],[Min59],[Min60],[Min61]
,[Min62],[Min63],[Min64],[Min65],[Min66],[Min67],[Min68],[Min69],[Min70],[Min71],[Min72],[Min73],[Min74],[Min75],[Min76]
,[Min77],[Min78],[Min79],[Min80],[Min81],[Min82],[Min83],[Min84],[Min85],[Min86],[Min87],[Min88],[Min89],[Min90],[Min91]
,[Min92],[Min93],[Min94],[Min95],[Min96],[Min97],[Min98],[Min99],[Min100],[Min101],[Min102],[Min103],[Min104],[Min105]
,[Min106],[Min107],[Min108],[Min109],[Min110],[Min111],[Min112],[Min113],[Min114],[Min115],[Min116],[Min117],[Min118]
,[Min119],[Min120],[Min121],[Min122],[Min123],[Min124],[Min125],[Min126],[Min127],[Min128],[Min129],[Min130],[Min131],[Min132]
,[Min133],[Min134],[Min135],[Min136],[Min137],[Min138],[Min139],[Min140],[Min141],[Min142],[Min143],[Min144],[Min145],[Max1]
,[Max2],[Max3],[Max4],[Max5],[Max6],[Max7],[Max8],[Max9],[Max10],[Max11],[Max12],[Max13],[Max14],[Max15],[Max16],[Max17]
,[Max18],[Max19],[Max20],[Max21],[Max22],[Max23],[Max24],[Max25],[Max26],[Max27],[Max28],[Max29],[Max30],[Max31],[Max32]
,[Max33],[Max34],[Max35],[Max36],[Max37],[Max38],[Max39],[Max40],[Max41],[Max42],[Max43],[Max44],[Max45],[Max46],[Max47]
,[Max48],[Max49],[Max50],[Max51],[Max52],[Max53],[Max54],[Max55],[Max56],[Max57],[Max58],[Max59],[Max60],[Max61],[Max62]
,[Max63],[Max64],[Max65],[Max66],[Max67],[Max68],[Max69],[Max70],[Max71],[Max72],[Max73],[Max74],[Max75],[Max76],[Max77]
,[Max78],[Max79],[Max80],[Max81],[Max82],[Max83],[Max84],[Max85],[Max86],[Max87],[Max88],[Max89],[Max90],[Max91],[Max92]
,[Max93],[Max94],[Max95],[Max96],[Max97],[Max98],[Max99],[Max100],[Max101],[Max102],[Max103],[Max104],[Max105],[Max106],[Max107]
,[Max108],[Max109],[Max110],[Max111],[Max112],[Max113],[Max114],[Max115],[Max116],[Max117],[Max118],[Max119],[Max120],[Max121]
,[Max122],[Max123],[Max124],[Max125],[Max126],[Max127],[Max128],[Max129],[Max130],[Max131],[Max132],[Max133],[Max134],[Max135],[Max136]
,[Max137],[Max138],[Max139],[Max140],[Max141],[Max142],[Max143],[Max144],[Max145],[resultSum],[sensorNum],[numTube],[isEmpty],[numFusion]
,[id_tube])
(SELECT [Min1],[Min2],[Min3],[Min4],[Min5],[Min6],[Min7],[Min8],[Min9],[Min10],[Min11],[Min12],[Min13],[Min14],[Min15],[Min16]
      ,[Min17],[Min18],[Min19],[Min20],[Min21],[Min22],[Min23],[Min24],[Min25],[Min26],[Min27],[Min28],[Min29],[Min30],[Min31],[Min32]
      ,[Min33],[Min34],[Min35],[Min36],[Min37],[Min38],[Min39],[Min40],[Min41],[Min42],[Min43],[Min44],[Min45],[Min46],[Min47],[Min48]
      ,[Min49],[Min50],[Min51],[Min52],[Min53],[Min54],[Min55],[Min56],[Min57],[Min58],[Min59],[Min60],[Min61],[Min62],[Min63],[Min64]
      ,[Min65],[Min66],[Min67],[Min68],[Min69],[Min70],[Min71],[Min72],[Min73],[Min74],[Min75],[Min76],[Min77],[Min78],[Min79],[Min80]
      ,[Min81],[Min82],[Min83],[Min84],[Min85],[Min86],[Min87],[Min88],[Min89],[Min90],[Min91],[Min92],[Min93],[Min94],[Min95],[Min96]
      ,[Min97],[Min98],[Min99],[Min100],[Min101],[Min102],[Min103],[Min104],[Min105],[Min106],[Min107],[Min108],[Min109],[Min110],[Min111]
      ,[Min112],[Min113],[Min114],[Min115],[Min116],[Min117],[Min118],[Min119],[Min120],[Min121],[Min122],[Min123],[Min124],[Min125],[Min126]
      ,[Min127],[Min128],[Min129],[Min130],[Min131],[Min132],[Min133],[Min134],[Min135],[Min136],[Min137],[Min138],[Min139],[Min140],[Min141]
      ,[Min142],[Min143],[Min144],[Min145],[Max1],[Max2],[Max3],[Max4],[Max5],[Max6],[Max7],[Max8],[Max9],[Max10],[Max11],[Max12],[Max13],[Max14]
      ,[Max15],[Max16],[Max17],[Max18],[Max19],[Max20],[Max21],[Max22],[Max23],[Max24],[Max25],[Max26],[Max27],[Max28],[Max29],[Max30],[Max31]
      ,[Max32],[Max33],[Max34],[Max35],[Max36],[Max37],[Max38],[Max39],[Max40],[Max41],[Max42],[Max43],[Max44],[Max45],[Max46],[Max47],[Max48]
      ,[Max49],[Max50],[Max51],[Max52],[Max53],[Max54],[Max55],[Max56],[Max57],[Max58],[Max59],[Max60],[Max61],[Max62],[Max63],[Max64],[Max65]
      ,[Max66],[Max67],[Max68],[Max69],[Max70],[Max71],[Max72],[Max73],[Max74],[Max75],[Max76],[Max77],[Max78],[Max79],[Max80],[Max81],[Max82]
      ,[Max83],[Max84],[Max85],[Max86],[Max87],[Max88],[Max89],[Max90],[Max91],[Max92],[Max93],[Max94],[Max95],[Max96],[Max97],[Max98],[Max99]
      ,[Max100],[Max101],[Max102],[Max103],[Max104],[Max105],[Max106],[Max107],[Max108],[Max109],[Max110],[Max111],[Max112],[Max113],[Max114]
      ,[Max115],[Max116],[Max117],[Max118],[Max119],[Max120],[Max121],[Max122],[Max123],[Max124],[Max125],[Max126],[Max127],[Max128],[Max129]
      ,[Max130],[Max131],[Max132],[Max133],[Max134],[Max135],[Max136],[Max137],[Max138],[Max139],[Max140],[Max141],[Max142],[Max143],[Max144]
      ,[Max145],[resultSum],[sensorNum],[numTube],[isEmpty],[numFusion],[id_tube]
  FROM [buran9955Pa].[dbo].[resultThick]
  )
GO
DELETE FROM [buran9955PaArhClear].[dbo].[resultCross]
GO
INSERT INTO [buran9955PaArhClear].[dbo].[resultCross]([Z1],[Z2],[Z3],[Z4],[Z5],[Z6],[Z7],[Z8],[Z9],[Z10],[Z11],[Z12],[Z13],[Z14],[Z15],[Z16],[Z17],[Z18],[Z19],[Z20]
,[Z21],[Z22],[Z23],[Z24],[Z25],[Z26],[Z27],[Z28],[Z29],[Z30],[Z31],[Z32],[Z33],[Z34],[Z35],[Z36],[Z37],[Z38],[Z39],[Z40],[Z41],[Z42]
,[Z43],[Z44],[Z45],[Z46],[Z47],[Z48],[Z49],[Z50],[Z51],[Z52],[Z53],[Z54],[Z55],[Z56],[Z57],[Z58],[Z59],[Z60],[Z61],[Z62],[Z63],[Z64]
,[Z65],[Z66],[Z67],[Z68],[Z69],[Z70],[Z71],[Z72],[Z73],[Z74],[Z75],[Z76],[Z77],[Z78],[Z79],[Z80],[Z81],[Z82],[Z83],[Z84],[Z85],[Z86]
,[Z87],[Z88],[Z89],[Z90],[Z91],[Z92],[Z93],[Z94],[Z95],[Z96],[Z97],[Z98],[Z99],[Z100],[Z101],[Z102],[Z103],[Z104],[Z105],[Z106],[Z107]
,[Z108],[Z109],[Z110],[Z111],[Z112],[Z113],[Z114],[Z115],[Z116],[Z117],[Z118],[Z119],[Z120],[Z121],[Z122],[Z123],[Z124],[Z125],[Z126]
,[Z127],[Z128],[Z129],[Z130],[Z131],[Z132],[Z133],[Z134],[Z135],[Z136],[Z137],[Z138],[Z139],[Z140],[Z141],[sensorNum],[numTube],[numFusion]
,[id_tube],[isEmpty],[Z142],[Z143],[Z144],[Z145])
(SELECT [Z1],[Z2],[Z3],[Z4],[Z5],[Z6],[Z7],[Z8],[Z9],[Z10],[Z11],[Z12],[Z13],[Z14],[Z15],[Z16],[Z17],[Z18],[Z19],[Z20],[Z21],[Z22]
      ,[Z23],[Z24],[Z25],[Z26],[Z27],[Z28],[Z29],[Z30],[Z31],[Z32],[Z33],[Z34],[Z35],[Z36],[Z37],[Z38],[Z39],[Z40],[Z41],[Z42],[Z43],[Z44]
      ,[Z45],[Z46],[Z47],[Z48],[Z49],[Z50],[Z51],[Z52],[Z53],[Z54],[Z55],[Z56],[Z57],[Z58],[Z59],[Z60],[Z61],[Z62],[Z63],[Z64],[Z65],[Z66]
      ,[Z67],[Z68],[Z69],[Z70],[Z71],[Z72],[Z73],[Z74],[Z75],[Z76],[Z77],[Z78],[Z79],[Z80],[Z81],[Z82],[Z83],[Z84],[Z85],[Z86],[Z87],[Z88]
      ,[Z89],[Z90],[Z91],[Z92],[Z93],[Z94],[Z95],[Z96],[Z97],[Z98],[Z99],[Z100],[Z101],[Z102],[Z103],[Z104],[Z105],[Z106],[Z107],[Z108],[Z109]
      ,[Z110],[Z111],[Z112],[Z113],[Z114],[Z115],[Z116],[Z117],[Z118],[Z119],[Z120],[Z121],[Z122],[Z123],[Z124],[Z125],[Z126],[Z127],[Z128]
      ,[Z129],[Z130],[Z131],[Z132],[Z133],[Z134],[Z135],[Z136],[Z137],[Z138],[Z139],[Z140],[Z141]
      ,[sensorNum],[numTube],[numFusion],[id_tube],[isEmpty],[Z142],[Z143],[Z144],[Z145]
  FROM [buran9955Pa].[dbo].[resultCross]
  )
GO
DELETE FROM [buran9955PaArhClear].[dbo].[resultLong]
GO
INSERT INTO [buran9955PaArhClear].[dbo].[resultLong]([Z1],[Z2],[Z3],[Z4],[Z5],[Z6],[Z7],[Z8],[Z9],[Z10],[Z11],[Z12],[Z13],[Z14],[Z15],[Z16],[Z17],[Z18],[Z19]
,[Z20],[Z21],[Z22],[Z23],[Z24],[Z25],[Z26],[Z27],[Z28],[Z29],[Z30],[Z31],[Z32],[Z33],[Z34],[Z35],[Z36],[Z37],[Z38],[Z39],[Z40]
,[Z41],[Z42],[Z43],[Z44],[Z45],[Z46],[Z47],[Z48],[Z49],[Z50],[Z51],[Z52],[Z53],[Z54],[Z55],[Z56],[Z57],[Z58],[Z59],[Z60],[Z61]
,[Z62],[Z63],[Z64],[Z65],[Z66],[Z67],[Z68],[Z69],[Z70],[Z71],[Z72],[Z73],[Z74],[Z75],[Z76],[Z77],[Z78],[Z79],[Z80],[Z81],[Z82]
,[Z83],[Z84],[Z85],[Z86],[Z87],[Z88],[Z89],[Z90],[Z91],[Z92],[Z93],[Z94],[Z95],[Z96],[Z97],[Z98],[Z99],[Z100],[Z101],[Z102],[Z103]
,[Z104],[Z105],[Z106],[Z107],[Z108],[Z109],[Z110],[Z111],[Z112],[Z113],[Z114],[Z115],[Z116],[Z117],[Z118],[Z119],[Z120],[Z121],[Z122]
,[Z123],[Z124],[Z125],[Z126],[Z127],[Z128],[Z129],[Z130],[Z131],[Z132],[Z133],[Z134],[Z135],[Z136],[Z137],[Z138],[Z139],[Z140],[Z141]
,[sensorNum],[numTube],[isEmpty],[numFusion],[id_tube],[Z142],[Z143],[Z144],[Z145])
(SELECT [Z1],[Z2],[Z3],[Z4],[Z5],[Z6],[Z7],[Z8],[Z9],[Z10],[Z11],[Z12],[Z13],[Z14],[Z15],[Z16],[Z17],[Z18],[Z19],[Z20],[Z21],[Z22]
,[Z23],[Z24],[Z25],[Z26],[Z27],[Z28],[Z29],[Z30],[Z31],[Z32],[Z33],[Z34],[Z35],[Z36],[Z37],[Z38],[Z39],[Z40],[Z41],[Z42],[Z43]
,[Z44],[Z45],[Z46],[Z47],[Z48],[Z49],[Z50],[Z51],[Z52],[Z53],[Z54],[Z55],[Z56],[Z57],[Z58],[Z59],[Z60],[Z61],[Z62],[Z63],[Z64]
,[Z65],[Z66],[Z67],[Z68],[Z69],[Z70],[Z71],[Z72],[Z73],[Z74],[Z75],[Z76],[Z77],[Z78],[Z79],[Z80],[Z81],[Z82],[Z83],[Z84],[Z85]
,[Z86],[Z87],[Z88],[Z89],[Z90],[Z91],[Z92],[Z93],[Z94],[Z95],[Z96],[Z97],[Z98],[Z99],[Z100],[Z101],[Z102],[Z103],[Z104],[Z105]
,[Z106],[Z107],[Z108],[Z109],[Z110],[Z111],[Z112],[Z113],[Z114],[Z115],[Z116],[Z117],[Z118],[Z119],[Z120],[Z121],[Z122],[Z123]
,[Z124],[Z125],[Z126],[Z127],[Z128],[Z129],[Z130],[Z131],[Z132],[Z133],[Z134],[Z135],[Z136],[Z137],[Z138],[Z139],[Z140],[Z141]
,[sensorNum],[numTube],[isEmpty],[numFusion],[id_tube],[Z142],[Z143],[Z144],[Z145]
  FROM [buran9955Pa].[dbo].[resultLong]
  )
GO
USE [buran9955PaClear]
GO
DBCC SHRINKDATABASE(N'buran9955PaArhClear', 10 )
GO





