#include "mainwindow.h"
#include "ui_mainwindow.h"


int MainWindow::getQrow() const
{
    return qrow;
}

void MainWindow::setQrow(int value)
{
    qrow = value;
}






MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionCarregar,SIGNAL(triggered()), this, SLOT(carregar()));
    connect(ui->actionSalvar,SIGNAL(triggered()), this, SLOT(salvar()));




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_inserir_clicked()
{
    QString titulo = ui->le_titulo->text();
    QString preco = ui->le_preco->text();
    QString quantidade = ui->le_quant->text();
    QString autor;

    if( ui->le_autor->text().size()!=0 )
    {
        autor = ui->le_autor->text();
    }else{
        autor = "desconhecido";      // define o autor como desconhecido se o usuário não informar em 'le_autor'
    }

    int row = ui->tbl_date->rowCount();

    if( titulo.size()!=0 && preco.size()!=0 && quantidade.size()!=0 ){
        Livro aux( titulo, preco, autor );
        aux.setQuantidade(quantidade);

        books.inserirLivro( aux );

        inserir(aux,row);

    }
    atualizarEstastisticas();
    ui->le_titulo->clear();
    ui->le_preco->clear();
    ui->le_quant->clear();
    ui->le_autor->clear();

}

void MainWindow::inserir(Livro livro, int n )
{
    if(n>=ui->tbl_date->rowCount()){
        ui->tbl_date->insertRow(n);   //verifica se é necessário inserir uma linha
    }

    ui->tbl_date->setItem( n, 0, new QTableWidgetItem( livro.getTitulo()));
    ui->tbl_date->setItem( n, 1, new QTableWidgetItem( livro.getPreco()));
    ui->tbl_date->setItem( n, 2, new QTableWidgetItem( livro.getQuantidade()));
    ui->tbl_date->setItem( n, 3, new QTableWidgetItem( livro.getAutor()));
    ui->tbl_date->setItem( n, 4, new QTableWidgetItem( livro.getCodigo()));
}

void MainWindow::inserirNaTabela2( QVector<Livro> servant ) //servant possui os indices dos livros correspondentes a pesquisa
{

    ui->tbl_search->clearContents();
    for( int i=0; i<servant.size(); i++ ){
           ui->tbl_search->insertRow(i);

    ui->tbl_search->setItem(i, 0 , new QTableWidgetItem(servant[i].getTitulo()));
    ui->tbl_search->setItem(i, 1 , new QTableWidgetItem(servant[i].getPreco()));
    ui->tbl_search->setItem(i, 2 , new QTableWidgetItem(servant[i].getQuantidade()));
    ui->tbl_search->setItem(i, 3 , new QTableWidgetItem(servant[i].getAutor()));
    ui->tbl_search->setItem(i, 4 , new QTableWidgetItem(servant[i].getCodigo()));

    }

    int exe = ui->tbl_search->rowCount();
    setQrow(exe);

    if( getQrow()>servant.size()){
        for( int i=getQrow(); i>=servant.size(); i-- ){
            ui->tbl_search->removeRow(i);               //remove o excesso de linhas

        }
    }
}

void MainWindow::atualizarEstastisticas()
{

    ui->lb_mais_caro->setText( books.maisCaro());
    ui->lb_menos_caro->setText( books.maisBarato());
    ui->lb_qlivros->setText( QString::number( books.size()) );

}

void MainWindow::on_btn_ordenar_por_titulo_clicked()
{
    books.ordenarPorTitulo();
    ui->tbl_date->clearContents();

    for( int i=0; i< books.size(); i++ ){
        inserir(books[i],i);

    }
}

void MainWindow::on_btn_ordenar_por_preco_clicked()
{

    books.ordenarPorPreco();
    ui->tbl_date->clearContents();

    for( int i=0; i< books.size(); i++ ){
        inserir(books[i],i);

    }

}

void MainWindow::carregar()
{
    QString nomeArquivo = QFileDialog::getOpenFileName(this,"Lista de Livros","","Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");
    books.clear();

    QFile arquivo(nomeArquivo);
    if(arquivo.open(QIODevice::ReadOnly)){
    QTextStream saida(&arquivo);

    QVector<Livro> newlist;

    while( !saida.atEnd() ){
    QString aux = saida.readLine();
    QStringList info =aux.split(",");

    Livro *supp;
    supp = new Livro( info[0], info[1], info[3] );
    supp->setQuantidade(info[2]);
    supp->setCodigo(info[4]);
    newlist.push_back(*supp);

    delete supp;
      }

    books.inserirNewList(newlist);
    ui->tbl_date->clearContents();

    for(int i=0;i<books.size();i++){


        inserir(books[i],i);

    }

    atualizarEstastisticas();
    QMessageBox::information(this, "Carregar Livros","Dados carregados com sucesso!");
    }else{
        QMessageBox::warning(this, "Carregar Livros","Não foi possível carregar os dados!");
    }

}

void MainWindow::salvar()
{
    QString nomeArquivo = QFileDialog::getSaveFileName(this,"Lista de Livros","","Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");

    QFile arquivo(nomeArquivo);

    if( arquivo.open(QIODevice::WriteOnly)){

        QTextStream entrada(&arquivo);

        for( int i=0; i<books.size();  i++ ){
            Livro aux = books[i];

            entrada << aux.getTitulo() << "," << aux.getPreco() << "," << aux.getQuantidade() << ","  << aux.getAutor() << "," << aux.getCodigo() << "\n";

        }
        QMessageBox::information(this, "Salvar Livros","Dados salvos com sucesso!");
    }else{
        QMessageBox::warning(this, "Salvar Livros","Não foi possível salvar os dados");
    }
    arquivo.close();
}

void MainWindow::on_tbl_date_cellChanged(int row, int column)  //se ocorrer alguma mudaça no valor da celula, esse valor será armazenado
{
    QString aux = ui->tbl_date->item(row, column)->text();

    books.editInfo(aux, row, column);                          //modifica o acervo de acordo como o valor de mudança na celula

}

void MainWindow::on_le_search_textChanged(const QString &arg1)   //de acordo com a mudança de 'le_search', ocorrerá a mudança dos valores na tabela
{
    QString aux = arg1.toLower();

    QVector<Livro> servant;

    if( ui->le_search->text().size()!=0 )
    {

        for( int i=0; i<books.size(); i++ ){
            Livro supp = books[i];
            QString titulo = getString(supp.getTitulo().toLower(), aux.size());
            QString autor = getString(supp.getAutor().toLower(), aux.size());;
            QString codigo = getString(supp.getCodigo().toLower(), aux.size());

                if( aux == titulo || aux==autor || aux==codigo ){

                    servant.push_back(supp);

            }
        }
    }
    inserirNaTabela2(servant);        //indices dos livros econtrados, de acordo com o valor le_search até esse determindado momento
                    //para que não ocorra problemas durante essa pesquisa, declarei uma atributo que armazenará um booleano.
                                        //servirá para que não se insira nenhum valor no acervo quando se está pesquisando, tendo que no caso ocorreria mudança em cada célula

}

QString MainWindow::getString( QString s1, int tamanho )  //retornará os valores para que possam ser comparados
{
    QString aux;

    for( int i=0; i<tamanho; i++ ){
        aux.push_back(s1[i]);
    }

    return aux;
}






