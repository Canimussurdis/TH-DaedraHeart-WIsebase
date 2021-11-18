#ifndef PAGETEXTEDIT_H
#define PAGETEXTEDIT_H

#include <QTextEdit>

#include "PageMetrics.h"

class PageTextEdit : public QTextEdit
{
    Q_OBJECT

public:
    explicit PageTextEdit(QWidget* parent = 0);

    // Установить формат страницы
    void setPageFormat(QPageSize::PageSizeId _pageFormat);

    // Настроить поля страницы
    void setPageMargins(const QMarginsF& _margins);

    // Получить режим отображения текста
    bool usePageMode() const;

public slots:
    // Установить режим отображения текста
    void setUsePageMode(bool _use);

    // Установить значение необходимости добавления дополнительной прокрутки снизу
    void setAddSpaceToBottom(bool _addSpace);

protected:
    // Переопределяется для корректировки документа и прорисовки оформления страниц
    void paintEvent(QPaintEvent* _event);

    // Переопределяется, для корректного обновления размеров вьюпорта
    void resizeEvent(QResizeEvent* _event);

private:
    // Обновить отступы вьювпорта
    void updateViewportMargins();

    // Обновить интервал вертикальной прокрутки
    void updateVerticalScrollRange();

    // Нарисовать оформление страниц документа
    void paintPagesView();

private slots:
    // Изменился интервал вертикальной прокрутки
    void aboutVerticalScrollRangeChanged(int _minimum, int _maximum);

    // Проверка смены документа
    void aboutDocumentChanged();

    // Обновить геометрию документа (чтобы размер документа не сбрасывался)
    void aboutUpdateDocumentGeometry();

private:
    // Ссылка на текущий документ
    QTextDocument* m_document;

    // Режим отображения текста
    bool m_usePageMode;

    bool m_addBottomSpace;

    // Метрика страницы редактора
    PageMetrics m_pageMetrics;
};

#endif // PAGETEXTEDIT_H
