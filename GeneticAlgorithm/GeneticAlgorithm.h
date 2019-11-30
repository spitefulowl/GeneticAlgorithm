#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GeneticAlgorithm.h"
#include "GenAlg.h"
#include "ResultListWindow.h"
#include <string>
#include <vector>

class GeneticAlgorithm : public QMainWindow
{
	Q_OBJECT

public:
	GeneticAlgorithm(QWidget *parent = Q_NULLPTR);
	std::string matrix_name;

private:
	Ui::GeneticAlgorithmClass ui;
public slots:
	void set_random_matrix();
	void set_matrix();
	void set_tour();
	void set_prop();
};
