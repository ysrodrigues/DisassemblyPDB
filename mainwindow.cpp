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

    ui->progressBar->setMaximum(fileName.size());
    int count = 0;

    ui->response->setText("Running !!!");

    for(it = fileName.constBegin(); it != fileName.constEnd(); ++it)
    {
        QString name = (*it).toLocal8Bit().constData();
        f.setFileName(name);
        if(!f.open(QIODevice::ReadOnly |  QIODevice::Text))
            return;

        QString dname = name.split("/").last();
        d.setName(dname);

        QTextStream read(&f);
        while(!read.atEnd())
        {
            QString line = read.readAll();

            d.process(line);
        }

        f.close();

        ++count;
        ui->progressBar->setValue(count);

    }

    ui->response->setText("Finish !!!");
}
