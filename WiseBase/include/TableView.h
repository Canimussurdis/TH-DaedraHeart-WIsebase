#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include "TableHeader.h"
#include "Note.h"

class TableView {
public:
    void displayHeaders(TableHeader* header);
    void displayTitleOfNote(Note* title_note);
    void setTitleOfTable(QString title_table);
    void FormatAllHeaders();
    void AddNote(Note* note);
    void deleteNote(Note* note);
    void openNote(Note* note);

private slots:
    void onAddNoteButtonClicked();
    void onDeleteNoteButtonClicked();
    void onOpenNoteButtonClicked();
private:
    QString title_table;
};

#endif // TABLEVIEW_H
