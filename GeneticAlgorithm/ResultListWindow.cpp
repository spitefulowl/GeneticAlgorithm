#include "ResultListWindow.h"
#include <QStandardItemModel>
#include <QAction>
#include <QMessageBox>
#include <QStringList>
#include <QFileDialog>
#include <sstream>
#include <string>
#include "utils.h"
ResultListWindow::ResultListWindow(QWidget *parent, std::vector<std::pair<std::vector<std::vector<int>>, std::vector<double>>>* results)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	for (int matrix_idx = 0; matrix_idx < results->size(); ++matrix_idx) {
		for (int row = 0; row < (*results)[matrix_idx].first.size(); ++row) {
			std::stringstream stream;
			for (int idx = 0; idx < (*results)[matrix_idx].first[row].size(); ++idx) {
				if (idx != (*results)[matrix_idx].first[row].size() - 1) {
					stream << (*results)[matrix_idx].first[row][idx] << "->";
				}
				else {
					stream << (*results)[matrix_idx].first[row][idx];
				}
			}
			stream << ": " << (*results)[matrix_idx].second[row];
			ui.listWidget->addItem(stream.str().c_str());
		}
		ui.listWidget->addItem("------------------------------------------");
		ui.listWidget->addItem("------------------------------------------");
	}
	delete results;
}