#include"GUI.h"
#include<qboxlayout.h>
#include<QFormLayout>
#include<qcheckbox.h>
#include<qradiobutton.h>
#include<qlineedit.h>
#include"qdebug.h"
void CarGUI::initGUI()
{

	QHBoxLayout *ly = new QHBoxLayout;
	setLayout(ly);
	//setFixedSize(900, 500);

	QWidget *widSt = new QWidget;
	QVBoxLayout * vbl = new QVBoxLayout;
	widSt->setLayout(vbl);

	//lst = new QListWidget;
	lst->setEnabled(true);
	//lst->setFixedSize(300, 400);
	vbl->addWidget(lst);

	/*form implementation*/
	QWidget *details = new QWidget;
	QVBoxLayout* boxVly = new QVBoxLayout;
	QFormLayout *form = new QFormLayout;
	details->setLayout(boxVly);

	QWidget *detailsForm = new QWidget;
	detailsForm->setLayout(form);
	//boxVly->addWidget(ly); 
	txtManufacturer = new QLineEdit;
	txtModel = new QLineEdit;
	txtRegisterNR = new QLineEdit;
	txtType = new QLineEdit;
	//txtRegisterNR->setEnabled(false);
	//form->setContentsMargins(QMargins(0, 54, 0, 0));
	form->addRow(new QLabel("Registration NR:"), txtRegisterNR);
	form->addRow(new QLabel("Manufacturer:"), txtManufacturer);
	form->addRow(new QLabel("Model:"), txtModel);
	form->addRow(new QLabel("Type:"), txtType);


	btnAdd = new QPushButton("Add");
	btnDelete = new QPushButton("Delete");
	btnUpdate = new QPushButton("Update");
	btnFind = new QPushButton("Find");
	btnSort = new QPushButton("Sort");
	btnFilter = new QPushButton("Filter");
	btnUndo = new QPushButton("Undo");
	btnExport = new QPushButton("Export");




	QWidget* widH = new QWidget;
	QHBoxLayout* boxH = new QHBoxLayout;
	widH->setLayout(boxH);
	boxH->addWidget(btnAdd);
	boxH->addWidget(btnDelete);
	boxH->addWidget(btnUpdate);

	QWidget* widH2 = new QWidget;
	QHBoxLayout* boxH2 = new QHBoxLayout;
	widH2->setLayout(boxH2);
	boxH2->addWidget(btnFind);
	boxH2->addWidget(btnSort);
	boxH2->addWidget(btnFilter);
	boxH2->addWidget(btnUndo);



	/*
	Basket windows buttons
	*/
	QWidget* widBasket = new QWidget;
	QHBoxLayout* boxBasket = new QHBoxLayout;
	widBasket->setLayout(boxBasket);
	btnNewBkt = new QPushButton("Simple Basket");
	btnPaintBkt = new QPushButton("Paint Basket");
	boxBasket->addWidget(btnNewBkt);
	boxBasket->addWidget(btnPaintBkt);
	//////////////////////////////

	//Basket view main windows commands
	btnAdd2Basket = new QPushButton("Add to basket");
	btnClearBasket = new QPushButton("Clear Basket");
	btnGenerateBskt = new QPushButton("Populate Basket");
	QWidget* widBsktBtns = new QWidget;
	QHBoxLayout* boxBsktBtns = new QHBoxLayout;
	widBsktBtns->setLayout(boxBsktBtns);
	boxBsktBtns->addWidget(btnAdd2Basket);
	boxBsktBtns->addWidget(btnClearBasket);
	boxBsktBtns->addWidget(btnGenerateBskt);

	ly->addWidget(widSt);
	ly->addWidget(details);
	boxVly->addWidget(detailsForm);
	boxVly->addWidget(widH);
	boxVly->addWidget(widBsktBtns);
	boxVly->addWidget(widBasket);


	boxVly->addStretch();


	vbl->addWidget(widH2);

}


void CarGUI::reloadList(const std::vector<Car>& cars)
{
	/*
	OLD CODE SUITABLE FOR QLISTWidget


	lst->clear();
	for (const auto&c : cars)
	{
	QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(c.getManufacturer()), lst);
	item->setData(Qt::UserRole, QString::fromStdString(c.getRegistration()));
	}*/


}

void CarGUI::populateFieldsForm()
{
	//OLD CODE
	/*if (lst->selectedItems().isEmpty())
	{
	txtManufacturer->setText("");
	txtModel->setText("");
	txtType->setText("");
	txtRegisterNR->setText("");
	return;
	}
	QListWidgetItem* selectedItem = lst->selectedItems().at(0);
	QString manufacturer = selectedItem->text();
	txtManufacturer->setText(manufacturer);
	QString registerNR = selectedItem->data(Qt::UserRole).toString();
	txtRegisterNR->setText(registerNR);
	try
	{
	Car c = srv.getElementService(srv.searchElement(registerNR.toStdString()));
	txtModel->setText(QString::fromStdString(c.getModel()));
	txtType->setText(QString::fromStdString(c.getType()));
	}
	catch (RepositoryException& e)
	{
	QMessageBox::warning(this, "WARNING", QString::fromStdString(e.what()));
	}
	*/

	const QItemSelectionModel* selection = lst->selectionModel();
	if (selection->hasSelection()) {
		const QModelIndex index = selection->currentIndex();
		QString regNR = index.data(Qt::DisplayRole).toString();
		try
		{
			Car c = srv.getElementService(srv.searchElement(regNR.toStdString()));
			txtModel->setText(QString::fromStdString(c.getModel()));
			txtType->setText(QString::fromStdString(c.getType()));
			txtRegisterNR->setText(QString::fromStdString(c.getRegistration()));
			txtManufacturer->setText(QString::fromStdString(c.getManufacturer()));
		}
		catch (RepositoryException& e)
		{
			QMessageBox::warning(this, "WARNING", QString::fromStdString(e.what()));
		}
	}
	else {
		txtManufacturer->setText("");
		txtModel->setText("");
		txtType->setText("");
		txtRegisterNR->setText("");
	}
}

void CarGUI::connectSignalsSlots()
{

	//load the form's fields
	QObject::connect(lst, &QListView::clicked, [&]() { populateFieldsForm(); });


	//delete button
	QObject::connect(btnDelete, &QPushButton::clicked, [&]() {
		try {
			/* temporary commented*/
			/*if (txtRegisterNR->text().toStdString() == "")
			{
			QMessageBox::warning(this, "WARNING","No car has been selected.");
			return;
			}*/
			//QListWidgetItem * selectedItem = lst->selectedItems().at(0);
			//QString regNR = selectedItem->data(Qt::UserRole).toString();
			const QItemSelectionModel* selection = lst->selectionModel();
			if (selection->hasSelection()) {
				const QModelIndex index = selection->currentIndex();
				qDebug() << "\nThat's the index " << index;
				QString regNR = index.data(Qt::DisplayRole).toString();
				srv.deleteElementService(regNR.toStdString());
				//reloadList(srv.getAllService());
			}
		}
		catch (ElementException& e)
		{
			QMessageBox::warning(this, "WARNING", QString::fromStdString(e.what()));
		}
		catch (RepositoryException& e)
		{
			QMessageBox::warning(this, "WARNING", QString::fromStdString(e.what()));
		}
	});

	//add button
	QObject::connect(btnAdd, &QPushButton::clicked, this, &CarGUI::addNewCar);

	//update button
	QObject::connect(btnUpdate, &QPushButton::clicked, this, &CarGUI::updateCar);

	//find button
	QObject::connect(btnFind, &QPushButton::clicked, this, &CarGUI::findCar);

	//sort button
	QObject::connect(btnSort, &QPushButton::clicked, this, &CarGUI::sortCars);

	//filter button
	QObject::connect(btnFilter, &QPushButton::clicked, this, &CarGUI::filterCars);

	//export button
	QObject::connect(btnExport, &QPushButton::clicked, this, &CarGUI::filterCars);

	//simple basket button
	QObject::connect(btnNewBkt, &QPushButton::clicked, [&]() {
		BasketGUI *  bkt = new BasketGUI{ srv };
		srv.addObserver(bkt);
		//srv.notification();
		//bkt->show();
	});

	//painted basket button
	QObject::connect(btnPaintBkt, &QPushButton::clicked, [&]() {
		BasketReadOnlyGUI *  bkt = new BasketReadOnlyGUI{ srv };
		srv.addObserver(bkt);
		bkt->show();
	});
	/*
	//export basket action
	QObject::connect(bkt->btnDone, &QPushButton::clicked, [&]() {
	srv.exportHtmlFile(bkt->txtExport->text().toStdString()+".html");
	bkt->txtExport->clear();
	});
	*/
	//undo  action
	QObject::connect(btnUndo, &QPushButton::clicked, [&]() {

		try {
			srv.undo();
			reloadList(srv.getAllService());
		}
		catch (ElementException& e)
		{
			QMessageBox::warning(this, "WARNING", QString::fromStdString(e.what()));

		}
	});

	//generate randomly elements into the basket
	QObject::connect(btnGenerateBskt, &QPushButton::clicked, [&]() {
		QLabel *lbFilter = new QLabel("Number of cars:");
		widRand = new QWidget;
		QHBoxLayout* boxRand = new QHBoxLayout;
		txtRand = new QLineEdit;
		widRand->setLayout(boxRand);
		boxRand->addWidget(lbFilter);
		boxRand->addWidget(txtRand);
		btnDone = new QPushButton("Done");
		boxRand->addWidget(btnDone);
		QObject::connect(btnDone, &QPushButton::clicked, [&]() {
			try
			{
				std::string  number = txtRand->text().toStdString();
				int value = txtRand->text().toInt();
				srv.addRandomToBasket(number);
				//total += value;
				widRand->close();

			}
			catch (RepositoryException& e)
			{
				QMessageBox::warning(this, "WARNING", QString::fromStdString(e.what()));

			}
		});
		widRand->show();
	});
	QObject::connect(btnClearBasket, &QPushButton::clicked, [&]() {
		srv.deleteAllService();
	});

	QObject::connect(btnAdd2Basket, &QPushButton::clicked, [&]() {
		try
		{
			srv.addToBasketService(txtRegisterNR->text().toStdString());
			reloadList(srv.getAllService());
		}
		catch (ElementException& e)
		{
			QMessageBox::warning(this, "WARNING", QString::fromStdString(e.what()));
		}
	});

}
void CarGUI::addNewCar()
{
	try
	{
		srv.addNewElementService(Car(txtRegisterNR->text().toStdString(), txtManufacturer->text().toStdString(), txtModel->text().toStdString(), txtType->text().toStdString()));
		reloadList(srv.getAllService());
	}
	catch (ElementException& e)
	{
		QMessageBox::warning(this, "WARNING", QString::fromStdString(e.what()));
	}
	catch (RepositoryException& e)
	{
		QMessageBox::warning(this, "WARNING", QString::fromStdString(e.what()));
	}
}
void CarGUI::updateCar()
{
	try
	{
		if (txtRegisterNR->text().toStdString() == "")
		{
			QMessageBox::warning(this, "WARNING", "No car has been selected.");
			return;
		}
		Car c{ txtRegisterNR->text().toStdString(), txtManufacturer->text().toStdString() ,txtModel->text().toStdString() ,txtType->text().toStdString() };
		Car initialCar = srv.getElementService(srv.searchElement(txtRegisterNR->text().toStdString()));
		if (c.getManufacturer() != initialCar.getManufacturer())
			srv.updateManufacturerService(c.getRegistration(), c.getManufacturer());
		if (c.getModel() != initialCar.getModel())
			srv.updateModelService(c.getRegistration(), c.getModel());
		if (c.getType() != initialCar.getType())
			srv.updateTypeService(c.getRegistration(), c.getType());
		reloadList(srv.getAllService());

	}
	catch (ElementException& e)
	{
		QMessageBox::warning(this, "WARNING", QString::fromStdString(e.what()));
	}
}


void CarGUI::findCar()
{
	try {
		widFind = new QWidget;
		widFind->setMinimumSize(200, 200);
		//widFind->setGeometry(34, 43, 343, 343);
		QVBoxLayout *boxFind = new QVBoxLayout;
		widFind->setLayout(boxFind);
		widFind->show();

		txtFind = new QLineEdit;
		QLabel *labFind = new QLabel("Register Number:");
		QPushButton *btnFinnd = new QPushButton("Done");
		boxFind->addWidget(labFind);
		boxFind->addWidget(txtFind);
		boxFind->addWidget(btnFinnd);

		widFind->show();

		// done find button
		QObject::connect(btnFinnd, &QPushButton::clicked, [&]() {

			if (txtFind->text().toStdString() == "")
			{
				QMessageBox::warning(this, "WARNING", "THE BOX CANNOT BE EMPTY!");
				return;
			}
			else
			{
				qDebug() << "TEST: " << txtFind->text();
				Car c = srv.getElementService(srv.searchElement(txtFind->text().toStdString()));
				txtManufacturer->setText(QString::fromStdString(c.getManufacturer()));
				txtModel->setText(QString::fromStdString(c.getModel()));
				txtType->setText(QString::fromStdString(c.getType()));
				txtRegisterNR->setText(QString::fromStdString(c.getRegistration()));
				widFind->close();
			}
		});

	}
	catch (RepositoryException& e)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString(e.what()));
	}
	catch (...)
	{
		QMessageBox::warning(this, "Warning", "The car couldn't be found!");

	}


}

void CarGUI::sortCars()
{
	widSort = new QWidget;
	//widSort->setMinimumSize(400, 200);
	QVBoxLayout *boxSort = new QVBoxLayout;
	widSort->setLayout(boxSort);
	widSort->show();

	QLabel *labSort = new QLabel("Sort Options:");
	QRadioButton *btn1 = new QRadioButton("Sort by Register Number");
	QRadioButton *btn2 = new QRadioButton("Sort by Type");
	QRadioButton *btn3 = new QRadioButton("Sort by Manufacturer + Model");

	btnFinnd = new QPushButton("Done");
	boxSort->addWidget(labSort);
	boxSort->addWidget(btn1);
	boxSort->addWidget(btn2);
	boxSort->addWidget(btn3);

	boxSort->addWidget(btnFinnd);

	widSort->show();


	QObject::connect(btn1, &QRadioButton::clicked, [&]() {reloadList(srv.sortRegistrationNumber()); });
	QObject::connect(btn2, &QRadioButton::clicked, [&]() {reloadList(srv.sortType()); });
	QObject::connect(btn3, &QRadioButton::clicked, [&]() {reloadList(srv.sortManufacturerModel()); });
	QObject::connect(btnFinnd, &QPushButton::clicked, [&]() {
		widSort->close();
	});

	// done find button


}

void CarGUI::filterCars()
{
	widFilter = new QWidget;
	widFilter->setMinimumSize(200, 200);
	QVBoxLayout *boxFilter = new QVBoxLayout;
	widFilter->setLayout(boxFilter);
	widFilter->show();

	QLabel *labSort = new QLabel("Filter Options:");
	QRadioButton *btn1 = new QRadioButton("Filter by Manufacturer");
	QRadioButton *btn2 = new QRadioButton("Filter by Type");

	btnFinnd = new QPushButton("Done");
	boxFilter->addWidget(labSort);
	boxFilter->addWidget(btn1);
	boxFilter->addWidget(btn2);

	boxFilter->addWidget(btnFinnd);

	widFilter->show();


	QObject::connect(btn1, &QRadioButton::clicked, [&]() { flag = 1; });
	QObject::connect(btn2, &QRadioButton::clicked, [&]() {flag = 2; });
	QObject::connect(btnFinnd, &QPushButton::clicked, [&]() {
		widFilter->close();
		QLabel *lbFilter = new QLabel("Manufacturer:");
		widInsideFilter = new QWidget;
		QHBoxLayout* boxFilterInside = new QHBoxLayout;
		txtFilterInside = new QLineEdit;
		widInsideFilter->setLayout(boxFilterInside);
		boxFilterInside->addWidget(lbFilter);
		boxFilterInside->addWidget(txtFilterInside);
		btnFinnd = new QPushButton("Done");
		boxFilterInside->addWidget(btnFinnd);
		if (flag == 1)
			QObject::connect(btnFinnd, &QPushButton::clicked, [&]() {reloadList(srv.filterByManufacturer(txtFilterInside->text().toStdString())); widInsideFilter->close(); });
		else
			if (flag == 2)
			{
				lbFilter->setText("Type:");
				QObject::connect(btnFinnd, &QPushButton::clicked, [&]() {reloadList(srv.filterByType(txtFilterInside->text().toStdString())); widInsideFilter->close(); });

			}
		widInsideFilter->show();

	});
}

