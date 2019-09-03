--USE [buran9955Pa]
--GO

SELECT T1.dtmCreate as 'Дата и время контроля',T1.numFusion as 'Номер плавки', T1.numTube as 'Номер трубы' , 
T3.normDocName as 'Нормативный документ',T4.SopName as 'Настр. СОП' , T5.steelGradeName as 'Марка стали', 
T6.typeSizeName as 'Типоразмер', T7.workShiftName as 'Смена',T2.operatorName as 'Оператор' ,
(case T1.resultT when 0 then 'Годно' when -1 then 'Нет данных' else 'ДЕФЕКТ' end) as 'К. толщины' ,
(case T1.resultC when 0 then 'Годно' when -1 then 'Нет данных' else 'ДЕФЕКТ' end) as 'Поперечный к.' ,
(case T1.resultL when 0 then 'Годно' when -1 then 'Нет данных' else 'ДЕФЕКТ' end) as 'Продольный к.' ,
T1.lengthTube as 'Длина трубы',T1.speedTube as 'Скорость' ,
(case T1.isSOP when 0 then 'Нет' when 1 then 'Да' else 'Неизвестно' end) as 'СОП'  ,
T1.thresholdC1,T1.thresholdC2,T1.thresholdL1,T1.thresholdL2,thresholdTUp,thresholdTDown,
thresholdTNominal,T1.pathFileNameThick as 'Файл МНК1',
T1.pathFileNameCross as 'Файл МНК2',T1.pathFileNameLong as 'Файл МНК3'  
,T1.indOperatorName,T1.indNormDocName,T1.indSopName,T1.indSteelGradeName,T1.indWorkShiftName,
T1.indTypeSize,T1.dtmCreate 	,YEAR(T1.dtmCreate) as Y1, MONTH(T1.dtmCreate) as M1
 , DATEPART( dayofyear , T1.dtmCreate ) as DY1 	,YEAR(T1.dtmCreate) as Y2, MONTH(T1.dtmCreate) as M2 
 , DATEPART( dayofyear , T1.dtmCreate ) as DY2 ,T1.numFusion,T1.resultT,T1.resultC,T1.resultL
  FROM resultTubeShort T1  join operators T2 on(T1.indOperatorName = T2.rec_id) 
  join normDocs T3 on(T1.indNormDocName = T3.rec_id) join Sops T4 on(T1.indSopName = T4.rec_id) 
  join steelGrades T5 on(T1.indSteelGradeName = T5.rec_id) join tubesTypeSize T6 on(T1.indTypeSize = T6.rec_id) 
  join workShifts T7 on(T1.indWorkShiftName = T7.rec_id) 
  where T1.isEmpty=0 and T1.numFusion=6190159  and resultT<>-100  
order by  T1.numFusion, T1.numTube
GO


