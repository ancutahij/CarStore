#pragma once
#pragma once
#include<qabstractitemview.h>
#include"Service.h"
#include"qdebug.h"
class MyListModel : public QAbstractListModel {
	Service& srv;
public:
	MyListModel(QObject *parent, Service& srv);
	// provide the numbers of rows
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	/*
	* Value at a given position
	*/
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	/*
	* Invoked on edit
	*/
	bool MyListModel::setData(const QModelIndex & index, const QVariant & value, int role) {
		if (role == Qt::EditRole) {
			int row = index.row();

			auto car = srv.getCarFromPosition(index.row());
			//car.setManufacturer(value.toString()) ;
			//srv.replace(row, contact);
			emit(dataChanged(index, index));

			return true;
		}

		return false;

	}
	Qt::ItemFlags MyListModel::flags(const QModelIndex & /*index*/) const {
		return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
	}
	void MyListModel::timerTikTak() {
		QModelIndex topLeft = createIndex(0, 0);
		QModelIndex bottomRight = createIndex(rowCount(), 1);
		emit dataChanged(topLeft, bottomRight);
	}
};