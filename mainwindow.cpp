#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSelect_File_triggered()
{
    QStringList fileName;
    QStringList::const_iterator it;
    QFile f;
    Disassembly d;

    fileName = QFileDialog::getOpenFileNames(this, tr("Open PDB File"), QStandardPaths::displayName(QStandardPaths::HomeLocation), tr("PDB File (*.pdb)"));

    for(it = fileName.constBegin(); it != fileName.constEnd(); ++it)
    {
        f.setFileName((*it).toLocal8Bit().constData());
        if(!f.open(QIODevice::ReadOnly |  QIODevice::Text))
            return;

        d.setName((*it).toLocal8Bit().constData());

        QTextStream read(&f);
        while(!read.atEnd())
        {
            QString line = read.readLine();

            d.process(line);
        }

        f.close();
    }
}
