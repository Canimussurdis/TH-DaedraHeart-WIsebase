#ifndef PAGEEDIT_H
#define PAGEEDIT_H

#include "PageTextEdit.h"
#include "Picture.h"

class PageEdit : public PageTextEdit {
public:
    void addPictureToPage(Picture* picture);
    void addDocFileToPage(BaseFileReader* file);
    void resizePicture(Picture* picture);

private:
    PageTextEdit *_page;
};

#endif // PAGEEDIT_H
