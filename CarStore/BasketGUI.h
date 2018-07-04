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
#include"Observer.h"
#include<QPaintEvent>
#include<QPainter>
#include<qmainwindow.h>


class BasketGUI : public Observer, public QWidget {
	QListWidget * listBskt;
	QPushButton *btnAddBskt;
	QPushButton *btnDltBskt;
	QPushButton *btnRandBskt;
	QPushButton *btnDone;
	QLineEdit *txtExport;
	QLabel* lbExport;
	QLabel *lbBsktTotal;
	Service& srv;
	QLineEdit* txtRand;
	QWidget* widRand;
	static int total;
	void connectBsktSignalsSlots();
	void update() override;
	void initBsktGUI();
	void randomBasket();

public:

	BasketGUI(Service& srv)
		:srv{ srv }
	{

		initBsktGUI();
		connectBsktSignalsSlots();
		update();

	}
};


class BasketReadOnlyGUI : public QMainWindow, public Observer {
	Q_OBJECT


		void update() override {
		this->hide();
		this->show();
	}
	Service& srv;
public:
	BasketReadOnlyGUI(Service& srv)
		:srv{ srv } {

	}
private:
	/*
	Se afiseaza elementele random
	*/
	void paintEvent(QPaintEvent* ev) override {
		QPainter p{ this };
		this->setFixedSize(700, 350);
		int value = srv.getAllBasketService().size();
		while (value) {
			int x = rand() % 600;
			int y = rand() % 250;
			int h = rand() % 100 + 20;
			int w = rand() % 100 + 20;
			if (x % 2 == 0)				p.fillRect(x, y, w, h, Qt::red);			else
				p.fillRect(x, y, w, h, Qt::blue);
			//p.drawRect(x, y, h, w);
			value--;
		}
		//	qDebug() << "Aici\n";

	}
};
