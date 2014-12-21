#include "PositionForm.h"

QGridLayout* CommonGroupBar::createSelectLayout()
{
	QGridLayout *layout = new QGridLayout();
	QLabel *m_label_ligne = new QLabel("Type : ");
	layout->addWidget(m_label_ligne, 0, 0);
	QRadioButton *boutton_colonie = new QRadioButton("Colonie");
	layout->addWidget(boutton_colonie, 0, 1);
	QRadioButton *boutton_secteur = new QRadioButton("Secteur");
	layout->addWidget(boutton_secteur, 0, 2);

	return layout;
}

QGridLayout* CommonGroupBar::createProdLayout(const QString& desc)
{
	QGridLayout *layout = new QGridLayout();
	QLabel *m_label_ligne = new QLabel(desc);
	layout->addWidget(m_label_ligne, 0, 0);
	QLineEdit *m_enter_metal = new QLineEdit();
	layout->addWidget(m_enter_metal, 0, 1);
	QLabel *m_metal = new QLabel(" Métal");
	layout->addWidget(m_metal, 0, 2);
	QLineEdit *m_enter_tri = new QLineEdit();
	layout->addWidget(m_enter_tri, 0, 3);
	QLabel *m_tri = new QLabel(" Tritium");
	layout->addWidget(m_tri, 0, 4);

	return layout;
}

QGridLayout* CommonGroupBar::createCoordLayout()
{
	QGridLayout *layout = new QGridLayout();
	QLabel *m_label_ligne = new QLabel("Coordonnées : ");
	layout->addWidget(m_label_ligne, 0, 0);
	QLineEdit *m_region = new QLineEdit();
	layout->addWidget(m_region, 0, 1);
	QLineEdit *m_constellation = new QLineEdit();
	layout->addWidget(m_constellation, 0, 2);
	QLineEdit *m_systeme = new QLineEdit();
	layout->addWidget(m_systeme, 0, 3);
	QLineEdit *m_position = new QLineEdit();
	layout->addWidget(m_position, 0, 4);

	return layout;
}

QGridLayout* CommonGroupBar::createSpatioLayout()
{
	QGridLayout *layout = new QGridLayout();
	QLabel *m_label_ligne = new QLabel("Niveau du spatioport : ");
	layout->addWidget(m_label_ligne, 0, 0);
	QLineEdit *m_lvl_spatio = new QLineEdit();
	layout->addWidget(m_lvl_spatio, 0, 1);

	return layout;
}

PositionForm::PositionForm() : QWidget()
{
	m_common = new CommonGroupBar();
	m_main_layout = new QGridLayout(this);
	m_main_layout->addWidget(m_common);
}