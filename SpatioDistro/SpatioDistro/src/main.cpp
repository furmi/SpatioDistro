#include "graphic/spatiodistro.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SpatioDistro w;
	w.show();
	return a.exec();
}
