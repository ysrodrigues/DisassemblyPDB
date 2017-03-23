#include "disassembly.h"

Disassembly::Disassembly()
{

}

void Disassembly::setName(QString fileName)
{
    this->fileName = fileName;
}

void Disassembly::process(QString line)
{
    int count = 0;
    QStringList::const_iterator it;
    QStringList splitFiles = line.split("MODEL");
    QString modelFileName;

    for(it = splitFiles.constBegin(); it != splitFiles.constEnd(); ++it)
    {
        modelFileName = "model_";
        modelFileName.append(QString::number(count));
        modelFileName.append("_");
        modelFileName.append(this->fileName);

        this->file.setFileName(modelFileName);

        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream writeFile(&file);
        writeFile << "MODEL" << (*it).toLocal8Bit().constData();
        file.close();

        if(count == 0)
            QFile::remove(modelFileName);

        ++count;
    }
}
