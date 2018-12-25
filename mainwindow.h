#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>
#include "acervo.h"
#include "livro.h"
#include <QDebug>
#include <QVector>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <algorithm>
#include <QPair>
#include <QTabWidget>
#include <QTableWidgetItem>

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Acervo books;
    int qrow;


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int getQrow() const;
    void setQrow(int value);



private slots:
    void on_btn_inserir_clicked();
    void on_btn_ordenar_por_titulo_clicked();
    void on_btn_ordenar_por_preco_clicked();
    void atualizarEstastisticas();
    void carregar();
    void inserirNaTabela2( QVector<Livro> servant );
    void salvar();
    QString getString( QString s1, int tamanho );
    void inserir(Livro livro, int n );
    void on_tbl_date_cellChanged(int row, int column);
    void on_le_search_textChanged(const QString &arg1);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
