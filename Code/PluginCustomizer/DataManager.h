/**********************************************************************************

���ܣ����ݹ����࣬ϵͳ����Ҫ�趨�����в������ɴ������
������xvdongming
���ڣ�2019-11
�޸ĺ�ά����xvdongming

**********************************************************************************/


#ifndef DATAMANGER_H
#define DATAMANGER_H
#include <QObject>
#include <QMap>
#include <QTreeWidgetItem>

#include "DataProperty/modelTreeItemType.h"

namespace ConfigOption
{
	class BCConfig;
	class DataConfig;
	class GlobalConfig;
	class GeometryConfig;
	class MeshConfig;
	class PostConfig;
	class SolverOption;
	class ObserverConfig;
	class MaterialConfig;
	class ProjectTreeConfig;
	class ProjectTreeInfo;
	class TreeItem;
}

namespace FastCAEDesigner
{
	class ModelBase;
}

namespace FastCAEDesigner
{
	class DataManager : public QObject
	{
		Q_OBJECT
	private:
		DataManager(QObject *parent = 0);
		~DataManager();

	public:
		
		static DataManager* getInstance();
		bool ReadInfoFromServerToLocal();              //��ϵͳ��ȡ������Ϣ������
		bool WriteInfoToServerPath();                  //д������Ϣ��ϵͳ
		void SetPhysicsList(QList<ModelBase*> list); 
		void SetMaterialList(QList<ModelBase*> list);

		ConfigOption::GlobalConfig* getGlobalConfig(); //��ȡ����������Ϣ 
		ConfigOption::GeometryConfig* getGeoConfig();
		ConfigOption::MeshConfig* getMeshConfig();
		ConfigOption::ProjectTreeConfig* GetProjectTreeConfig();
		//���Բ�������
		QString GetLogoFileName();                     //��ȡLogo�ļ�����
		void SetLogoFileName(QString fileName);        //����Logo�ļ�����  
		QString GetWelcomeFileName();                  //��ȡwelcome�ļ�����
		void SetWelcomeFileName(QString fileName);     //����welcome�ļ�����
		QString GetUserManual();
		void SetUserManual(QString userManual);
		//���Բ�������

		void SetGeometryFeatureModeling(bool on);
		void SetGeometryFeatureOperatins(bool on);
		void SetGeometryCreateSketch(bool on);
		void SetImportGeometry(QString suffix);
		void SetExportGeometry(QString suffix);

		void SetSurfaceMesh(bool on);
		void SetSolidMesh(bool on);
		void SetMeshCreateSet(bool on);
		void SetCheckMesh(bool on);
		void SetImportMesh(QString suffix);
		void SetExportMesh(QString suffix);
		
		QString GetGeoSuffix();
		void SetGeoSuffix(QString suffix);

		//����geometry��mesh�����Ϣ
		bool GetGeometryFeatureModeling();
		bool GetGeometryFeatureOperatins();
		bool GetGeometryCreateSketch();
		bool GetSurfaceMesh();
		bool GetSolidMesh();
		bool GetMeshCreateSet();
		bool GetCheckMesh();
		QString GetImportGeometrySuffix();
		QString GetExportGeometrySuffix();
		QString GetImportMeshSuffix();
		QString GetExportMeshSuffix();

		QMap<QTreeWidgetItem*, ModelBase*> DictTreeItemToModel;		

		void ClearModelDict();
		ModelBase* GetModelFromDict(QTreeWidgetItem* treeItem);
		void InsertModelToDict(QTreeWidgetItem*, ModelBase*);
		void DeleteModelToDict(QTreeWidgetItem*);
		void DeleteModelToDict(QList<QTreeWidgetItem*> treeItemList);
		void CopyFileToSystem(QString fileName, QString path);

	private:
		bool ReadGlobalConfig();                       //��ȡ����������Ϣ
		bool ReadGeometryConfig();

		void Init();                                   //��ʼ��
		void CopyLogoAndWelcomImageToSystem();         //����logo��welcome�ļ���ϵͳ����Ŀ¼��
		void CopyUserManualToSystem();
		void CopyFileToSystem(QString fileName, QString path, QString destFileName);

		bool ReadGeoConfig();		//��ȡ������Ϣ
		bool ReadMeshConfig();		//��ȡ������Ϣ
		bool ReadProjectTreeConfig();
		//bool ReadProjectTreeInfo();
		QList<ModelBase*> GetSpecifiedTypeModelList(QList<ModelBase*> modelList, TreeItemType type);

	private:
		static DataManager* _instance;
		ConfigOption::BCConfig* _bcConfig{};
		ConfigOption::DataConfig* _dataConfig{};
		ConfigOption::GlobalConfig* _globalConfig{};
		ConfigOption::GeometryConfig* _geoConfig{};
		ConfigOption::MeshConfig* _meshConfig{};
		ConfigOption::PostConfig* _postConfig{};
		ConfigOption::SolverOption* _solverOption{};
		ConfigOption::ObserverConfig* _observerConfig{};
		ConfigOption::MaterialConfig* _materialConfig{};
		ConfigOption::ProjectTreeConfig* _projectTreeConfig{};
		ConfigOption::ProjectTreeInfo* _projectTreeInformation{};

		bool _isGeoModeling{ false };	//Geometry modeling
		bool _isGeoOperations{ false };	//Geometry operations
		bool _isCreateSketch{ false };	//Create Sketch

		QString _logoFileName{};     //logo�ļ�����
		QString _welcomeFileName{};  //welcome�ļ�����
		QString _userManual{};       //�û��ֲ�
		QString _GeoSuffix;   

		QString _importGeoSuffix;	//import geometry suffix
		QString _exportGeoSuffix;	//export geometry suffix
		QString _importMeshSuffix;	//import mesh suffix
		QString _exportMeshSuffix;	//export mesh suffix

		bool _isSurfaceMesh{ false };	//surface mesh
		bool _isSolidMesh{ false };		//solid mesh
		bool _isCheckMesh{ false };		//check mesh
		bool _isCreateSet{ false };		//create set

		QList<ModelBase*> _physicsList;  //�����б�
		QList<ModelBase*> _materialList; //�����б�
	};
}

#endif // DATAMANGER_H