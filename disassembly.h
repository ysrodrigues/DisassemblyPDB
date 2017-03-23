#ifndef DISASSEMBLY_H
#define DISASSEMBLY_H

#include <QString>
#include <QFile>

class Disassembly
{
public:
    Disassembly();
    void setName(QString);
    void process(QString);
private:
    QString fileName;
};

#endif // DISASSEBLY_H
