������� flags
[rec_id] -- ���������� ����      
,[isReady] -- ������� ���������� � �������� �����     
 ,[isActual] -- ������� ������������ ������  0-�� �������� 1 - ���������
  ,[isTransportReady] - ��������� ����� 1, �� ����� - 0
  ,[isDefectoskopReady] - ����������� ����� 1, �� ����� - 0
 
 ������� resultTubeShort
  [rec_id]-- ���������� ������, ��������� ����      
  ,[indTypeSize]--������ �����������      
  ,[indSteelGradeName]--������ ����� �����      
  ,[indNormDocName]--������ ������������ ���������     
  ,[indOperatorName]--������ ���������      
  ,[indWorkShiftName]--������ ������� �����      
  ,[indSopName]--������ ���� ���      
  ,[numTube]--����� �����      
  ,[numFusion]--����� ������      
  ,[dtmCreate]--���� � ����� �������� ��� �������� ������������ ���� 01-01-3000     
  ,[pathFileName]--���� � ����� � ������� ��������� ��������            
  ,[countZones]--����� ���      
  ,[speedTube]--�������� �����      
  ,[lengthTube]--����� �����
  [currentMagnet]--��� ��������������
  ,[resultC]--��������� �� ����������� ���� �� ���� ��������  ���� ���� �� 1 ����� ����� 1, ������ 1, ���� ���� 2 ����� �����2 ������ 2 ����� 0-�����)  
  ,[resultL]--��������� �� ����������� ���� �� ���� ��������  ���� ���� �� 1 ����� ����� 1, ������ 1, ���� ���� 2 ����� �����2 ������ 2 ����� 0-�����)     
  ,[resultT]--��������� �� ����������� ���� �� ���� ��������  ���� ���� �� 1 ����� ����� 1, ������ 1, ���� ���� 2 ����� �����2 ������ 2 ����� 0-�����)
  ,[thresholdC1]--������� ������ ������ 1 � ��������� �� ����������� 	  
  ,[thresholdC2]--������� ������ ������ 2 � ��������� �� �����������
 ,[thresholdL1]--������� ������ ������ 1 � ��������� �� ����������� 	  
  ,[thresholdL2]--������� ������ ������ 2 � ��������� �� �����������
 ,[thresholdTUp]-- ������ ����� �� ������� � �� 	  
  ,[thresholdTUp]--������� ����� �� ������� � ��
[thresholdTNominal] -- ����������� ������� � ��  
  [isEmpty] - 1 ��� 0 ������� ����, ��� ������ �� ��������� �� ������� ������������ - 1
  ��������� ���������� ����� ����������� ��� ������ � ����� � ���� ������ � �������������, �������� - "��������� �������� 1=2,2 2=3,1 3=1,0 .... ������������ ���������� �������=true ...." �� ����������� ������� �������, ����� ���, �������� �����, ����� �����.
  
  ������� resultCross ������ �������� ����������� 
  [rec_id] -- ���������� ������ �� �������      
  ,[tube_id] �� rec_id resultTubeShort    
  ,[Z1]--�������� ������������� ������ ������� � ��������� �� ���� (���� ���� �� ������������, �� -1) ��� �������� ����������� -1	    
  -- ....     
  ,[Z141]               
  ,[resultSum] -- �������� ��������� �� �������  �� ���� ����� (���� �� ������� �� ���� ����� ���� ������ 1 � ������ 2, �� ������ 0 - �����, ����� 1 ����� ����� 1 ��� 2 ����� �����2 )    
  ,[sensorNum] -- ����� �������      
  [isEmpty] - 1 ��� 0 ������� ����, ��� ������ �� ��������� �� ������� ������������ - 1
  
  paramsMeasureTubes - ������� ���������� �������� �����
      ,[indTypeSize] - ������ ����������� rec_id �� tubesTypeSize
      ,[isActive] - ������������ - 1 �� ������������ 0
      ,[paramName] - ������������ ������������
      ,[paramRusname] - ������������ ������������ ��� �������������
      ,[paramValueFloat] - �������� ��������� ���������
      ,[paramValueStr] - �������� ���������� ���������