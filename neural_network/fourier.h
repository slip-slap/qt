#ifndef FOURIER_H
#define FOURIER_H

#include <QMainWindow>

namespace Ui {
class Fourier;
}

class Fourier : public QMainWindow
{
    Q_OBJECT

public:
    explicit Fourier(QWidget *parent = nullptr);
    ~Fourier();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Fourier *ui;
};

#endif // FOURIER_H
