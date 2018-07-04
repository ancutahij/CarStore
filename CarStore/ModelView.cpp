#include"ModelView.h"
#include<qdebug.h>
MyListModel::MyListModel(QObject *parent, Service& srv)
	: srv{ srv } {
}


int MyListModel::rowCount(const QModelIndex &parent) const {
	//return srv.getAllService().size();
	return 15;
}
/*
Row and column information is specified with parameter index and the role is set to Qt::DisplayRole.
*/
QVariant MyListModel::data(const QModelIndex &index, int role) const {
	int row = index.row();
	//qDebug() << index.row();

	if (role == Qt::DisplayRole)
	{
		Car c = srv.getCarFromPosition(index.row());
		return QString(QString::fromStdString(c.getRegistration()));
	}
	if (role == Qt::FontRole) {
		QFont f;
		f.setItalic(1);
		return f;
	}
	if (role == Qt::BackgroundRole) {
		{
			if (row % 2 == 0)
			{
				QBrush bg(Qt::lightGray);
				return bg;
			}}
	}
	return QVariant();
}
