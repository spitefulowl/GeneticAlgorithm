#include "GeneticAlgorithm.h"
#include <qdebug.h>
#include <QStandardItemModel>
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>
#include <qdebug.h>
#include "Logger.h"
GeneticAlgorithm::GeneticAlgorithm(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.matrixView->setVisible(false);
	connect(ui.rndButton, SIGNAL(clicked()), SLOT(set_random_matrix()));
	connect(ui.actionOpen, &QAction::triggered, [this]() {
		matrix_name = QFileDialog::getOpenFileName(this, "Open a file").toStdString();
		set_matrix();
	});
	connect(ui.actionExit, &QAction::triggered, [this]() { this->close(); });
	this->setFixedSize(QSize(615, 350));
	connect(ui.proportionalRadio, SIGNAL(clicked()), this, SLOT(set_prop()));
	connect(ui.tournamentRadio, SIGNAL(clicked()), this, SLOT(set_tour()));
	connect(ui.testButton, &QPushButton::clicked, [this]() {
		int betta = ui.bettaEdit->text().toInt();
		int probability = ui.probabilityEdit->text().toInt();
		int iterations = ui.iterationsEdit->text().toInt();
		QMessageBox msg_box;
		msg_box.setWindowTitle("Error");
		msg_box.setText("Empty filename");
		if (this->matrix_name == "") {
			msg_box.exec();
			return;
		}
		msg_box.setText("Empty or incorrect field");
		if (!(probability && iterations && betta)) {
			msg_box.exec();
			return;
		}
		std::vector<BaseGeneration*> gen_list{new RandomGeneration, new GreedyGeneration};
		std::vector<BaseCrossover*> cros_list{new OrdinalCrossover, new PartialCrossover};
		std::vector<BaseMutation*> mut_list{new PointMutation, new InversionMutation};
		std::vector<BaseSelection*> sel_list{new BettaTournament, new ProportionalSelection};
		logger* log = new logger;
		for (auto* gen : gen_list) {
			for (auto* cros : cros_list) {
				for (auto* mut : mut_list) {
					for (auto* sel : sel_list) {
						for (int size = 5; size <= 15; size += 5) {
							for (int iter = 0; iter < 10; ++iter) {
								log->set_conf(gen, cros, mut, sel);
								GenAlg* genetic = new GenAlg(gen, cros, mut, sel, this->matrix_name, iterations, size, probability, betta);
								auto* results = genetic->execute();
								log->log(results, iter);
							}
						}
					}
				}
			}
		}
		delete log;
	});
	connect(ui.startButton, &QPushButton::clicked, [this]() {
		int betta = ui.bettaEdit->text().toInt();
		int probability = ui.probabilityEdit->text().toInt();
		int population = ui.populationEdit->text().toInt();
		int iterations = ui.iterationsEdit->text().toInt();
		QMessageBox msg_box;
		msg_box.setWindowTitle("Error");
		msg_box.setText("Empty filename");
		if (this->matrix_name == "") {
			msg_box.exec();
			return;
		}
		msg_box.setText("Empty or incorrect field");
		if (!(probability && population && iterations)) {
			msg_box.exec();
			return;
		}
		BaseGeneration* generation = nullptr;
		BaseCrossover* crossover = nullptr;
		BaseMutation* mutation = nullptr;
		BaseSelection* selection = nullptr;
		if (ui.RandomRadio->isChecked()) {
			generation = new RandomGeneration;
		}
		else {
			generation = new GreedyGeneration;
		}
		if (ui.ordinalRadio->isChecked()) {
			crossover = new OrdinalCrossover;
		}
		else {
			crossover = new PartialCrossover;
		}
		if (ui.pointRadio->isChecked()) {
			mutation = new PointMutation;
		}
		else {
			mutation = new InversionMutation;
		}
		if (ui.tournamentRadio->isChecked()) {
			if (!betta) {
				msg_box.exec();
				return;
			}
			selection = new BettaTournament;
		}
		else {
			selection = new ProportionalSelection;
		}
		GenAlg* genetic = new GenAlg(generation, crossover, mutation, selection, this->matrix_name, iterations, population, probability, betta);
		auto* results = genetic->execute();
		if (results) {
			ResultListWindow* result_window = new ResultListWindow(Q_NULLPTR, results);
			result_window->show();
		}
	});

	/*
	QStandardItemModel* model = new QStandardItemModel(5, 5, this);
	model->setHeaderData(0, Qt::Horizontal, "test");
	ui.tableView->setModel(model);*/
}

