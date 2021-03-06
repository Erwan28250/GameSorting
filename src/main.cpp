﻿/*
* MIT License
*
* This file is part of the GameSorting
*
* Copyright © 2021 Erwan Saclier de la Bâtie
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "MainWindow.h"
#include "CommonStruct.h"

#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QString>

int main(int argc, char** argv)
{
	// Initialize the resources of the program (images, etc).
	Q_INIT_RESOURCE(gamesorting);

	// Creating an application object.
	QApplication app(argc, argv);
	app.setOrganizationName("Erwan28250");
	app.setApplicationName("GameSorting");
	app.setApplicationVersion(GAMESORTING_VERSION);
	
	// Setting the application icon.
	QIcon appIcon = QIcon(":/Images/GameSorting.ico");
	app.setWindowIcon(appIcon);

	// Parsing command line.
	QCommandLineParser parser;
	parser.addHelpOption();
	parser.addVersionOption();
	parser.addPositionalArgument("gameList", QCoreApplication::translate("main", "Loading a game list file. Only one file can be open."));

	QCommandLineOption noSettings("restoreSettings", QCoreApplication::translate("main", "Restore settings to default."));
	parser.addOption(noSettings);

	parser.process(app);
	
	QString gListFilePath = parser.positionalArguments().size() > 0 ?
		parser.positionalArguments().first() : QString();
	bool bNoSettings = false;
	if (parser.isSet(noSettings))
		bNoSettings = true;

	MainWindow window(gListFilePath, bNoSettings);
	window.show();

	// Running the app main loop.
	return app.exec();
}