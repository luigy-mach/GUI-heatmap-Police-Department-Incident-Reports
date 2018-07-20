#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>

#include <QDebug>

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>

#include <stdlib.h>
#include <iomanip>


//#include <iostream>     // std::cout
#include <algorithm>    // std::set_intersection, std::sort
//#include <vector>       // std::vector
#include <bits/stdc++.h>

using namespace std;

//#define MYFILEIN "db.csv"
#define MYFILEIN "/home/luigy/Desktop/pollo/utils/GUI-heatmap/heatmap-luigy/db.csv"
#define MYFILEOUT "/home/luigy/Desktop/pollo/utils/GUI-heatmap/heatmap-luigy/myoutput.csv"
#define LENBUFF 500


struct cmp_str
{
   bool operator()(char const *a, char const *b)
   {
      return std::strcmp(a, b) < 0;
   }
};


typedef long double typelong;
typedef int typeshort;


typedef pair < typelong, typelong  > posLen;
typedef pair < string, string  > mypairString;

typedef vector<string> vecString;



typedef map < string, posLen >     indexPdId;
typedef map < string, vecString >  indexTime;
typedef map < string, vecString  > indexPdDistrict;
typedef map < string, vecString  > indexCategory;

typedef map < string, posLen >::iterator it_indexPdId;
typedef map < string, vecString >::iterator it_indexTime;
typedef map < string, vecString >::iterator it_indexPdDistrict;
typedef map < string, vecString  >::iterator it_indexCategory;

typedef vector<string>::iterator it_vecString;

indexPdId myindexPdId;
indexTime myindexTime;
indexTime myindexCategory;
indexPdDistrict myindexPdDistrict ;


void insert_in_myIndexTime(indexTime& myindexTime, string Time, string PdId)
{
    it_indexTime it = myindexTime.find(Time);

    if( it == myindexTime.end()){
        vecString tempVec;
        tempVec.push_back(PdId);
        myindexTime.insert(make_pair(Time,tempVec));
        return;
    }
    it->second.push_back(PdId);
    return;
}



void insert_in_myIndexPdDistrict(indexPdDistrict& myindexPdDistrict, string PdDistrict, string PdId)
{
    it_indexPdDistrict it = myindexPdDistrict.find(PdDistrict);

    if( it == myindexPdDistrict.end()){
        vecString tempVec;
        tempVec.push_back(PdId);
        myindexPdDistrict.insert(make_pair(PdDistrict,tempVec));
        return;
    }
    it->second.push_back(PdId);
    return;
}


void insert_in_myIndexCategory(indexCategory& myindexCategory, string Category, string PdId)
{
    it_indexCategory it = myindexCategory.find(Category);

    if( it == myindexCategory.end()){
        vecString tempVec;
        tempVec.push_back(PdId);
        myindexCategory.insert(make_pair(Category,tempVec));
        return;
    }
    it->second.push_back(PdId);
    return;
}






void open_db()
{
    ifstream file;
    char* pt = NULL;
    char buff[LENBUFF];
    typelong count = 0.0;
    typelong lenCurr = 0.0;


    file.open(MYFILEIN,ifstream::in);

    if (!file) {
        qDebug() << "Unable to open file";
        return;   // call system to stop
    }

    //read headtop text
    file.getline(buff,LENBUFF);
    lenCurr = strlen(buff);
    count+=lenCurr;

    //read body text


    while(!file.eof())
    {
        file.getline(buff,LENBUFF);
        lenCurr = strlen(buff);
        //if(lenCurr==0){
        //    continue;
        //}

        char temp_buff[LENBUFF];
        char PdDistrict[LENBUFF];
        char Category[LENBUFF];
        char Time[LENBUFF];
        char PdId[LENBUFF];



        pt = strtok(buff,",");//IncidntNum
        sprintf(temp_buff,"%s",pt);
        if(temp_buff[0]=='\"'){
            while(pt!=NULL){
                pt = strtok(NULL,",");
                sprintf(temp_buff,"%s",pt);
                int len = strlen(temp_buff);
                if(temp_buff[len-1]=='\"'){
                    break;
                }
            }
        }

        pt = strtok(NULL,",");//Category
        sprintf(Category,"%s",pt);
        sprintf(temp_buff,"%s",pt);
        if(temp_buff[0]=='\"'){
            while(pt!=NULL){
                pt = strtok(NULL,",");
                sprintf(temp_buff,"%s",pt);
                int len = strlen(temp_buff);
                if(temp_buff[len-1]=='\"'){
                    break;
                }
            }
        }

        pt = strtok(NULL,",");//Descript
        sprintf(temp_buff,"%s",pt);
        if(temp_buff[0]=='\"'){
            while(pt!=NULL){
                pt = strtok(NULL,",");
                sprintf(temp_buff,"%s",pt);
                int len = strlen(temp_buff);
                if(temp_buff[len-1]=='\"'){
                    break;
                }
            }
        }

        pt = strtok(NULL,",");//DayOfWeek
        sprintf(temp_buff,"%s",pt);
        if(temp_buff[0]=='\"'){
            while(pt!=NULL){
                pt = strtok(NULL,",");
                sprintf(temp_buff,"%s",pt);
                int len = strlen(temp_buff);
                if(temp_buff[len-1]=='\"'){
                    break;
                }
            }
        }

        pt = strtok(NULL,",");//Date
        sprintf(temp_buff,"%s",pt);
        if(temp_buff[0]=='\"'){
            while(pt!=NULL){
                pt = strtok(NULL,",");
                sprintf(temp_buff,"%s",pt);
                int len = strlen(temp_buff);
                if(temp_buff[len-1]=='\"'){
                    break;
                }
            }
        }


        pt = strtok(NULL,",");//Time
        sprintf(Time,"%s",pt);
        sprintf(temp_buff,"%s",pt);
        if(temp_buff[0]=='\"'){
            while(pt!=NULL){
                pt = strtok(NULL,",");
                sprintf(temp_buff,"%s",pt);
                int len = strlen(temp_buff);
                if(temp_buff[len-1]=='\"'){
                    break;
                }
            }
        }

        pt = strtok(NULL,",");//PdDistrict
        sprintf(PdDistrict,"%s",pt);
        sprintf(temp_buff,"%s",pt);
        if(temp_buff[0]=='\"'){
            while(pt!=NULL){
                pt = strtok(NULL,",");
                sprintf(temp_buff,"%s",pt);
                int len = strlen(temp_buff);
                if(temp_buff[len-1]=='\"'){
                    break;
                }
            }
        }


        pt = strtok(NULL,",");//Resolution

        sprintf(temp_buff,"%s",pt);
        if(temp_buff[0]=='\"'){
            while(pt!=NULL){
                pt = strtok(NULL,",");
                sprintf(temp_buff,"%s",pt);
                int len = strlen(temp_buff);
                if(temp_buff[len-1]=='\"'){
                    break;
                }
            }
        }

        pt = strtok(NULL,",");//Address
        sprintf(temp_buff,"%s",pt);
        if(temp_buff[0]=='\"'){
            while(pt!=NULL){
                pt = strtok(NULL,",");
                sprintf(temp_buff,"%s",pt);
                int len = strlen(temp_buff);
                if(temp_buff[len-1]=='\"'){
                    break;
                }
            }
        }

        pt = strtok(NULL,",");//X
        //sprintf(xx,"%s",pt);

        pt = strtok(NULL,",");//Y
        //sprintf(yy,"%s",pt);


        //Location

        while( pt != NULL )
        {
            sprintf(PdId,"%s",pt); //PdId
            pt=strtok(NULL,",");
        }

        //printf("%s, ",temp_buff );


        //printf("%s, ",Category );
        //printf("%s, ",Time );
        //printf("%s, ",PdDistrict );
        //printf("%s\n",PdId );

        if(lenCurr){
            //int intPdId = atoi(pdid); // error data > 15 digit
            //string stringtemp = PdId;
            //mypairString mypair=;

            //myindexTime.insert(make_pair(PdDistrict,PdId));
            //myindexPdDistrict.insert(make_pair(Time,PdId));
            insert_in_myIndexPdDistrict(myindexTime,Time,PdId);
            insert_in_myIndexTime(myindexPdDistrict,PdDistrict,PdId);
            insert_in_myIndexCategory(myindexCategory,Category,PdId);


            posLen pltemp = make_pair(count,lenCurr);
            myindexPdId[PdId] = pltemp;
        }
        strcpy(buff, "");

        count+=lenCurr+1;


    }
    file.close();

}



string find_PdId(indexPdId myindexPdId, string PdId){

    it_indexPdId it = myindexPdId.find(PdId);

    if( it == myindexPdId.end()){
        return "Error PdId";
    }

    typelong posPdId = it->second.first;
    typelong lenPdId = it->second.second;

    ifstream file2;
    char buff[LENBUFF];

    file2.open(MYFILEIN,ifstream::in);

    char temp[LENBUFF]="";
    file2.seekg (posPdId+1,file2.beg);
    file2.read(temp,lenPdId);

    string stringtemp = temp;
    file2.close();
    return stringtemp;
}





vecString find_PdDistrict(indexPdDistrict myindexPdDistrict, string PdDistrict){
    it_indexPdDistrict it = myindexPdDistrict.find(PdDistrict);
    if( it == myindexPdDistrict.end()){
        vecString temp;
        temp.push_back("Error PdDistrict");
        return temp;
    }
    return it->second;
}


vecString find_Time(indexTime myindexTime, string Time){
    it_indexTime it = myindexTime.find(Time);
    if( it == myindexTime.end()){
        vecString temp;
        temp.push_back("Error Time");
        return temp;
    }
    return it->second;
}



vecString find_Category(indexCategory myindexCategory, string Category){
    it_indexCategory it = myindexCategory.find(Category);
    if( it == myindexCategory.end()){
        vecString temp;
        temp.push_back("Error Category");
        return temp;
    }
    return it->second;
}





void print_index(indexPdId myindexPdId){


    indexPdId::iterator it;
    for( it = myindexPdId.begin();it != myindexPdId.end(); ++it)
    {
        cout << it->first << " " << it->second.first << " " << it->second.second << "\n";
    }

   return;
}



vecString vecString_intersection(vecString &v1, vecString &v2)
{

    vecString v3;

    if(v1.size()==0 && v2.size()==0)
    {
        qDebug()<<"     caso 0 ambos vacios \n";
        return v3;
    }


    if(v1.size()==0)
    {
        qDebug()<<"     caso 1 \n";
        v3=v2;
        return v3;
    }

    if(v2.size()==0)
    {
        qDebug()<<"     caso 2 \n";
        v3=v1;
        return v3;
    }


    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3));

    return v3;
}



vecString vecString_intersection2(vecString &v1, vecString &v2)
{

    vecString v3;

    if(v1.size()==0 && v2.size()==0)
    {
        qDebug()<<"     caso 0 ambos vacios \n";
        return v3;
    }


    if(v1.size()==0)
    {
        qDebug()<<"     caso 1 \n";
        v3=v2;
        return v3;
    }

    if(v2.size()==0)
    {
        qDebug()<<"     caso 2 \n";
        v3=v1;
        return v3;
    }


    //sort(v1.begin(), v1.end());
    //sort(v2.begin(), v2.end());
    //qDebug()<<"         tengo "<<v1.size()<<"" <<v2.size() <<endl;

    //int max = v1.size()>v2.size()?v1.size():v2.size();

    if(v1.size()>v2.size()){
        for(it_vecString it1 = v1.begin();it1!=v1.end();it1++)
        {
            for(it_vecString it2 = v2.begin();it2!=v2.end();it2++)
            {
                if(*it1==*it2)
                {
                    v3.push_back(*it1);
                }
            }
        }
    }else{
        for(it_vecString it1 = v2.begin();it1!=v2.end();it1++)
        {
            for(it_vecString it2 = v1.begin();it2!=v1.end();it2++)
            {
                if(*it1==*it2)
                {
                    v3.push_back(*it1);
                }
            }
        }


    }

    return v3;
}



string print_file_myresult(vecString myresult){

    ofstream fileout;
    fileout.open (MYFILEOUT);

    ifstream file2;
    file2.open(MYFILEIN,ifstream::in);

    for(it_vecString it=myresult.begin();it!=myresult.end();it++)
    {
        it_indexPdId it2 = myindexPdId.find(*it);

        if( it2 == myindexPdId.end())
        {
            return "Error al consultar";
        }

        typelong posPdId = it2->second.first;
        typelong lenPdId = it2->second.second;


        char buff[LENBUFF];


        char temp[LENBUFF]="";
        file2.seekg (posPdId+1,file2.beg);
        file2.read(temp,lenPdId);

        string stringtemp = temp;
        fileout <<stringtemp<<endl;

    }

    file2.close();
    fileout.close();
    return "todo bien salida print";
}





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->webView->load(QUrl::fromLocalFile(QDir::currentPath() + "/../heatmap-luigy/final.html" ));

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{



    string temp_T = ui->comboBox_1->currentText().toUtf8().constData();
    cout << temp_T <<endl;

    vecString temp_Time = find_Time(myindexTime,temp_T);
    qDebug()<< temp_Time.size();

    if(temp_Time.size()==0){
        qDebug()<< "temp_Time vacio ";
        return;

    }

    string temp_D = ui->comboBox_2->currentText().toUtf8().constData();
    cout << temp_D <<endl;
    vecString temp_PdDistrict = find_PdDistrict(myindexPdDistrict,temp_D );
    qDebug()<< temp_PdDistrict.size();
    if(temp_PdDistrict.size()==0){
        qDebug()<< "temp_PdDistrict vacio ";
        return;

    }

    string temp_C = ui->comboBox_3->currentText().toUtf8().constData();
    cout << temp_C <<endl;
    vecString temp_Category = find_Category(myindexCategory,temp_C);
    qDebug()<< temp_Category.size();
    if(temp_Category.size()==0){
        qDebug()<< "Category vacio ";
        return;

    }

    vecString temp1 = vecString_intersection(temp_PdDistrict,temp_Category);
    qDebug()<< temp1.size();


    vecString temp2 = vecString_intersection(temp_Time,temp_Category);
    qDebug()<< temp2.size();

    vecString myresult = vecString_intersection(temp1,temp2);
    qDebug()<< myresult.size();

    if(myresult.size()==0){
        qDebug()<< "vector resultante vacio \n";
        return;
    }


    string temp = print_file_myresult(myresult);

    qDebug() << QString::fromStdString(temp);



    system("python /home/luigy/Desktop/pollo/utils/GUI-heatmap/heatmap-luigy/genarate-heatmap.py");

    ui->webView->load(QUrl::fromLocalFile(QDir::currentPath() + "/../heatmap-luigy/final.html" ));

    qDebug()<<"...fin...";
}

void MainWindow::on_pushButton_2_clicked()
{

      myindexPdId.clear();
      myindexTime.clear();
      myindexPdDistrict.clear();
      myindexCategory.clear();

      open_db();
    for(it_indexTime it=myindexTime.begin();it!=myindexTime.end();it++)
        ui->comboBox_1->addItem(QString::fromStdString(it->first));

    for(it_indexPdDistrict it=myindexPdDistrict.begin();it!=myindexPdDistrict.end();it++)
        ui->comboBox_2->addItem(QString::fromStdString(it->first));

    for(it_indexCategory it=myindexCategory.begin();it!=myindexCategory.end();it++)
        ui->comboBox_3->addItem(QString::fromStdString(it->first));



}
