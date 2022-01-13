#ifndef PAGEMETRICS_H
#define PAGEMETRICS_H

#include <QString>
#include <QSizeF>
#include <QMarginsF>
#include <QPageSize>

class QPaintDevice;

class PageMetrics {
public:

    // Перевести миллиметры в пикселы ( _x указывает направление (горизонтальное - true или вертикальное - false),
    // в котором необходимо произвести рассчёт
    static qreal mmToPx(qreal _mm, bool _x = true);

    // Получить размер страницы из строки
    static QPageSize::PageSizeId pageSizeIdFromString(const QString& _from);

    // Получить строку из размера страницы
    static QString stringFromPageSizeId(QPageSize::PageSizeId _pageSize);

public:
    PageMetrics(QPageSize::PageSizeId _pageFormat = QPageSize::A4, QMarginsF _mmMargins = QMarginsF());

    // Обновить метрики
    void update(QPageSize::PageSizeId _pageFormat, QMarginsF _mmPageMargins = QMarginsF());

    // Методы доступа к параметрам страницы
    QPageSize::PageSizeId pageFormat() const;
    QSizeF mmPageSize() const;
    QMarginsF mmPageMargins() const;
    QSizeF pxPageSize() const;
    QMarginsF pxPageMargins() const;

private:

    // Формат страницы
    QPageSize::PageSizeId m_pageFormat;

    // Размеры в миллиметрах
    QSizeF m_mmPageSize;
    QMarginsF m_mmPageMargins;

    // Размеры в пикселах
    QSizeF m_pxPageSize;
    QMarginsF m_pxPageMargins;

};


#endif // PAGEMETRICS_H
