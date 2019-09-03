--USE [buran9955Pa]
--GO

SELECT T1.dtmCreate as '���� � ����� ��������',T1.numFusion as '����� ������', T1.numTube as '����� �����' , 
T3.normDocName as '����������� ��������',T4.SopName as '�����. ���' , T5.steelGradeName as '����� �����', 
T6.typeSizeName as '����������', T7.workShiftName as '�����',T2.operatorName as '��������' ,
(case T1.resultT when 0 then '�����' when -1 then '��� ������' else '������' end) as '�. �������' ,
(case T1.resultC when 0 then '�����' when -1 then '��� ������' else '������' end) as '���������� �.' ,
(case T1.resultL when 0 then '�����' when -1 then '��� ������' else '������' end) as '���������� �.' ,
T1.lengthTube as '����� �����',T1.speedTube as '��������' ,
(case T1.isSOP when 0 then '���' when 1 then '��' else '����������' end) as '���'  ,
T1.thresholdC1,T1.thresholdC2,T1.thresholdL1,T1.thresholdL2,thresholdTUp,thresholdTDown,
thresholdTNominal,T1.pathFileNameThick as '���� ���1',
T1.pathFileNameCross as '���� ���2',T1.pathFileNameLong as '���� ���3'  
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


