#pragma once
#pragma once
#include<qwidget.h>
#include<qlistwidget.h>
#include<qpushbutton.h>
#include<QLineEdit>
#include<QFormLayout>
#include<qlabel.h>
#include<QMessageBox>
#include<qdebug.h>
#include"Service.h"
#include<qradiobutton.h>
#include<qgroupbox.h>
#include<qtreewidget.h>
#include"BaskeGUI.h"
#include"ModelView.h"
class CarGUI : public QWidget
{
	Service& srv;
	//QListWidget* lst;
	QListView *lst;
	QPushButton* btnAdd;
	QPushButton* btnDelete;
	QPushButton* btnUpdate;
	QPushButton* btnFind;
	QPushButton* btnSort;
	QPushButton* btnFilter;
	QPushButton* btnFinnd;
	QPushButton* btnUndo;
	QPushButton* btnExport;
	QPushButton* btnNewBkt;
	QPushButton* btnAdd2Basket;
	QPushButton* btnGenerateBskt;
	QPushButton* btnClearBasket;
	QPushButton* btnPaintBkt;
	QPushButton* btnDone;
	QLineEdit * txtRegisterNR;
	QLineEdit * txtModel;
	QLineEdit * txtType;
	QLineEdit * txtManufacturer;
	QLineEdit *txtFind;
	QLineEdit* txtFilterInside;
	QWidget *widSort;
	QWidget *widFind;
	QWidget *widFilter;
	QWidget* widInsideFilter;
	QGroupBox* boxMain;
	QLineEdit* txtRand;
	QWidget* widRand;
	int flag;
	void initGUI();
	void connectSignalsSlots();
	void reloadList(const std::vector<Car>& cars);
	void populateFieldsForm();
	void addNewCar();
	void updateCar();
	void findCar();
	void sortCars();
	void filterCars();

public:

	CarGUI(Service& srv)
		:srv(srv)
	{

		// list view setting the model
		lst = new QListView();
		MyListModel *myModel = new MyListModel{ lst,srv };
		lst->setModel(myModel);

		initGUI();
		connectSignalsSlots();
		//reloadList(srv.getAllService());


	}
};

