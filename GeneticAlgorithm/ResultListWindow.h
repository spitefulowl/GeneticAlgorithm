#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_ResultListWindow.h"

class ResultListWindow : public QMainWindow
{
	Q_OBJECT

public:
	ResultListWindow(QWidget *parent, std::vector<std::pair<std::vector<std::vector<int>>, std::vector<double>>>* results);

private:
	Ui::ResultList ui;
};
