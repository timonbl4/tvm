#ifndef CSCHEMEMEMORYMODULEDATAMODEL_H
#define CSCHEMEMEMORYMODULEDATAMODEL_H

#include <tvm/type.h>
#include <tvm/module.h>

#include <QtWidgets/QLineEdit>

#include <nodes/NodeDataModel>

namespace nVirtualMachine
{

namespace nGui
{

class cSchemeMemoryModuleDataModel : public QtNodes::NodeDataModel
{
	using NodeDataModel = QtNodes::NodeDataModel;
	using PortType = QtNodes::PortType;
	using NodeDataType = QtNodes::NodeDataType;
	using PortIndex = QtNodes::PortIndex;
	using NodeData = QtNodes::NodeData;
	using NodeStyle = QtNodes::NodeStyle;

public:
	cSchemeMemoryModuleDataModel(const QString& moduleFullName,
	                             const PortType& direction);
	~cSchemeMemoryModuleDataModel();

	QJsonObject save() const override;
	void restore(const QJsonObject& jsonObject) override;

public:
	QString caption() const override;
	QString name() const override;
	std::unique_ptr<NodeDataModel> clone() const override;

public:
	unsigned int nPorts(PortType portType) const override;
	NodeDataType dataType(PortType portType,
	                      PortIndex portIndex) const override;

	ConnectionPolicy portInConnectionPolicy(PortIndex portIndex) const override;
	ConnectionPolicy portOutConnectionPolicy(PortIndex) const override;
	bool portCaptionVisible(PortType, PortIndex) const override;
	std::shared_ptr<NodeData> outData(PortIndex) override;
	void setInData(std::shared_ptr<NodeData>, int) override;
	QWidget* embeddedWidget() override;

private:
	QWidget* mainWidget;
	QLineEdit* lineEditName;
	QLineEdit* lineEditType;
	const QString moduleFullName;
	const PortType direction;
};

}

}

#endif // CSCHEMEMEMORYMODULEDATAMODEL_H