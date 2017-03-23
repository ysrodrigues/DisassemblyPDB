#ifndef DISASSEMBLY_H
#define DISASSEMBLY_H

#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>

class Disassembly
{
public:
    Disassembly();
    void setName(QString);
    void process(QString);
private:
    QString fileName;
    QFile file;
};

#endif // DISASSEBLY_H
