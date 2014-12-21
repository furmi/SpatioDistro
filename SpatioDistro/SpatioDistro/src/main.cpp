#include "graphic/spatiodistro.h"
#include "graphic/PositionForm.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	PositionForm fenetre;
	fenetre.show();

	return a.exec();
}