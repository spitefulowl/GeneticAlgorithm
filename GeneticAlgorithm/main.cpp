#include "GeneticAlgorithm.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GeneticAlgorithm w;
	w.show();
	return a.exec();
}
