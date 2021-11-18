#ifndef NOTE_H
#define NOTE_H

#include "TableHeader.h"
#include "PageMetrics.h"
#include <QString>

class Note {
public:
    Note setHeaders(TableHeader* header);
    void setPage(PageMetrics* _pageMetrics);
    void setTitleOfNote(QString title_note);
    void addNote();
    void openNote();
    void shareNote();

private slots:
    void onAddNoteButtonClicked();
    void onShareButtonClicked();

private:
    PageMetrics* _pageMetrics;
    QString title_note;
};

#endif // NOTE_H
