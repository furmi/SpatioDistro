#include "graphic/spatiodistro.h"
#include "graphic/PositionForm.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
	//gestion des accents
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

	QApplication a(argc, argv);
	
	PositionForm fenetre;
	fenetre.show();

	return a.exec();
}