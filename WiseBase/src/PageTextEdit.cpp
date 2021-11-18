#include "include/PageTextEdit.h"

#include <QAbstractTextDocumentLayout>
#include <QPainter>
#include <QScrollBar>
#include <QTextFrame>

PageTextEdit::PageTextEdit(QWidget *parent) :
    QTextEdit(parent),
    m_document(0),
    m_usePageMode(false),
    m_addBottomSpace(true){
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

}

void PageTextEdit::setPageFormat(QPageSize::PageSizeId _pageFormat){

}

void PageTextEdit::setPageMargins(const QMarginsF& _margins){

}

bool PageTextEdit::usePageMode() const {
}

void PageTextEdit::setUsePageMode(bool _use) {

}

void PageTextEdit::setAddSpaceToBottom(bool _addSpace){

}

void PageTextEdit::paintEvent(QPaintEvent* _event){

}

void PageTextEdit::resizeEvent(QResizeEvent* _event){

}

void PageTextEdit::updateViewportMargins(){

}

void PageTextEdit::updateVerticalScrollRange(){

}

void PageTextEdit::paintPagesView(){

}

void PageTextEdit::aboutVerticalScrollRangeChanged(int _minimum, int _maximum){

}

void PageTextEdit::aboutDocumentChanged(){

}

void PageTextEdit::aboutUpdateDocumentGeometry(){

}
