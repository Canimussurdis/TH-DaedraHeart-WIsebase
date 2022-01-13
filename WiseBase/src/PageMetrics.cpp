#include "include/PageMetrics.h"

#include <QApplication>
#include <QDesktopWidget>


namespace {
    static qreal mmToInches(qreal mm) { return mm * 0.039370147; }
}

qreal PageMetrics::mmToPx(qreal _mm, bool _x){

}

QPageSize::PageSizeId PageMetrics::pageSizeIdFromString(const QString& _from){

}

QString PageMetrics::stringFromPageSizeId(QPageSize::PageSizeId _pageSize){

}

PageMetrics::PageMetrics(QPageSize::PageSizeId _pageFormat, QMarginsF _mmPageMargins){

}

void PageMetrics::update(QPageSize::PageSizeId _pageFormat, QMarginsF _mmPageMargins){

}

QPageSize::PageSizeId PageMetrics::pageFormat() const{

}

QSizeF PageMetrics::mmPageSize() const{

}

QMarginsF PageMetrics::mmPageMargins() const {

}

QSizeF PageMetrics::pxPageSize() const{

}

QMarginsF PageMetrics::pxPageMargins() const{

}
