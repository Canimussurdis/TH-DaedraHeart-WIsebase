#ifndef TABLEHEADER_H
#define TABLEHEADER_H

#include <QString>

class TableHeader {
public:
    void setTableHeader();
    void deleteHeader();
    void changeHeader();

private:
    QString title_header;
    QString type_of_header;
};

#endif // TABLEHEADER_H
