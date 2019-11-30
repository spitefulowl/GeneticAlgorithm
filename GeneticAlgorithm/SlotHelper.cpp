#include <qdebug.h>
#include <QMessageBox>
#include <QGridLayout>
#include <QSpacerItem>
#include <QStandardItemModel>
#include "GeneticAlgorithm.h"
#include "utils.h"

void GeneticAlgorithm::set_random_matrix() {
	QMessageBox msg_box;
	msg_box.setWindowTitle("Error");
	msg_box.setText("Incorrect value");
	int size = ui.matrixSizeEdit->text().toInt();
	int max_value = ui.matrixMaxEdit->text().toInt();
	if (!(size && max_value)) {
		msg_box.exec();
		return;
	}
	std::string filename = utils::random_matrix_generator(size, max_value);
	this->matrix_name = std::string{ filename.c_str() };
	qDebug() << filename.c_str();
	set_matrix();
}

void GeneticAlgorithm::set_matrix() {
	QMessageBox msg_box;
	msg_box.setWindowTitle("Error");
	msg_box.setText("Empty filename");
	if (matrix_name == "") {
		msg_box.exec();
		return;
	}
	utils::FileHandler<double> file(matrix_name.c_str());
	std::vector<std::vector<double>> matrix = *file.GetMatrix();
	auto model = new QStandardItemModel;
	model->setColumnCount(matrix.size());
	model->setRowCount(matrix.size());
	ui.matrixView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.matrixView->setModel(model);
	ui.matrixView->horizontalHeader()->setDefaultSectionSize(35);
	ui.matrixView->verticalHeader()->setDefaultSectionSize(30);
	int cell_width = ui.matrixView->horizontalHeader()->defaultSectionSize();
	int cell_height = ui.matrixView->verticalHeader()->defaultSectionSize();
	ui.matrixView->resize(cell_width * model->columnCount() + 25, cell_height * model->rowCount() + 25);
	for (int row = 0; row < matrix.size(); ++row) {
		for (int column = 0; column < matrix.size(); ++column) {
			auto index = model->index(row, column);
			model->setData(index, matrix[row][column]);
		}
	}
	ui.matrixView->setVisible(true);
	this->setFixedSize(QSize(this->size().rwidth(),
		375 + cell_height * model->rowCount()));
}

void GeneticAlgorithm::set_tour() {
	ui.bettaEdit->setEnabled(true);
}
void GeneticAlgorithm::set_prop() {
	ui.bettaEdit->setEnabled(false);
}