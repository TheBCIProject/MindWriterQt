#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QStatusBar>
#include <QMenuBar>
#include <QAction>
#include <QLabel>
#include <QPair>
#include <QVector>


#include "keyboardwidget.h"
#include "predictionwidget.h"

namespace defaultColorScheme
{
    static const QColor LETTER_OFF = QColor(255,255,255,130);
    static const QColor LABEL_OFF = QColor(40,40,40,200);

    static const QColor LETTER_ON = QColor(0,0,0,255);
    static const QColor LABEL_ON = QColor(255,255,255,200);

    static const QColor BACKGROUND = QColor(50,50,50,200);
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QMainWindow *parent = 0);

    /**
     * @brief the delay between each flash
     */
    static const int DELAY = 300;

    enum FlashMode {
        OneByOne, /**< Flash one label after the other. */
        LineByLine /**< Flash one row/column after the other. */
    };
    
signals:
    
public slots:

    /**
     * @brief update the KeyboardWidget and PredictionWidget
     * according to the present configuration. \n
     * Called when timer_ reach DELAY
     */
    void updateFlash();

private:
    void createActions();

    KeyboardWidget *keyboardW;
    PredictionWidget *predictionW;
    QTextEdit *textEdit;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *settingMenu;
    QMenu *keyboardMenu;
    QAction *qwertyAct;
    QAction *azertyAct;
    QAction *selectKeyboardAct;

    QTimer timer_; ///< Timer use to control the label. Details.
    FlashMode flashMode_;

    int flashIndex_;
    /**
     * @brief QVector containing the coordinate of all the QLabels
     */
    QVector<QPair<int, int>> vLabelCoordinate;

private slots:
    void selectKeyboardLayout();
    void selectQWERTYKeyboardLayout();
    void selectAZERTYKeyboardLayout();
    
};

#endif // MAINWINDOW_H
