#include"GUI.h"
#include"qmessagebox.h"
int BasketGUI::total = 0;

void BasketGUI::initBsktGUI() {
	QWidget* widMainBskt = new QWidget;
	QVBoxLayout *boxVBskt = new QVBoxLayout;
	widMainBskt->setLayout(boxVBskt);

	listBskt = new QListWidget;
	btnDltBskt = new QPushButton("Clear Basket");
	btnRandBskt = new QPushButton("Random");

	boxVBskt->addWidget(listBskt);

	QWidget* widBsktunder = new QWidget;
	QHBoxLayout *boxVBsktunder = new QHBoxLayout;
	widBsktunder->setLayout(boxVBsktunder);
	boxVBsktunder->addWidget(btnDltBskt);
	boxVBsktunder->addWidget(btnRandBskt);

	lbExport = new QLabel("Export file name:");
	lbExport->setStyleSheet("font-weight: bold;");
	QWidget* widExportDone = new QWidget;
	QHBoxLayout* boxExportDone = new QHBoxLayout;
	widExportDone->setLayout(boxExportDone);
	btnDone = new QPushButton("Send");
	txtExport = new QLineEdit;
	txtExport->setPlaceholderText("Example: Basket(.html)");
	boxExportDone->addWidget(txtExport);
	boxExportDone->addWidget(btnDone);


	//label that shows the current number of elements from basket
	lbBsktTotal = new QLabel(QString("Total from Basket: ") + QString::number(total));
	lbBsktTotal->setStyleSheet("font-weight: bold;");

	//boxVBskt->addWidget(lbBsktTotal);
	boxVBskt->addWidget(listBskt);
	boxVBskt->addWidget(widBsktunder);
	//boxVBskt->addWidget(lbExport);
	//boxVBskt->addWidget(widExportDone);


	widMainBskt->show();
}


void BasketGUI::connectBsktSignalsSlots() {

	//delete Basket button
	QObject::connect(btnDltBskt, &QPushButton::clicked, [&]() {listBskt->clear(); total = 0; srv.deleteAllService(); });//lbBsktTotal->setText(QString("Total from Basket: ") + QString::number(total)); });


																														//populate Basket randomly 
	QObject::connect(btnRandBskt, &QPushButton::clicked, [&]() {
		randomBasket();

		//lbBsktTotal->show();
	});
}


void BasketGUI::randomBasket()
{

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
			total = srv.getAllBasketService().size();
			widRand->close();

		}
		catch (RepositoryException& e)
		{
			QMessageBox::warning(this, "WARNING", QString::fromStdString(e.what()));

		}
	});
	widRand->show();

}

/*
the basket items are loaded into the basket windows
*/
void BasketGUI::update() {

	listBskt->clear();
	for (const auto&c : srv.getAllBasketService())
	{
		QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(c.getManufacturer()), listBskt);
		item->setData(Qt::UserRole, QString::fromStdString(c.getRegistration()));
	}

	lbBsktTotal->setText(QString("Total from Basket: ") + QString::number(total));
}

