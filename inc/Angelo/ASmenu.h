
#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QMainWindow>
#include "JAgame.h"

namespace UI{
	class MainMenu;
}

class MainMenu : public QMainWindow
{
	Q_OBJECT


public:
	explicit MainMenu(QWidget *parent = 0, Game* game = NULL);
	~MainMenu();

private slots:
	void on_pushButton_clicked();

private:
	UI::MainMenu *ui;

};

#endif
