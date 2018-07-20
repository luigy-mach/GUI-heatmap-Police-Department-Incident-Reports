#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

#include <stdlib.h>
#include <iomanip>



using namespace std;

#define MYFILE "db.csv"
//#define MYFILE "db-test2.csv"
#define LENBUFF 500


struct cmp_str
{
   bool operator()(char const *a, char const *b)
   {
      return std::strcmp(a, b) < 0;
   }
};

typedef long double mytype;
typedef std::pair < mytype, mytype  > posLen;
typedef std::map  < string, posLen > tIndex;


string find_pdid(tIndex myindex, string pdid){

	tIndex::iterator it = myindex.find(pdid);

	if( it == myindex.end()){
		return "Error PdId";
	}

	mytype posPdId = it->second.first;
	mytype lenPdId = it->second.second;

	ifstream file2;
	char buff[LENBUFF];

	file2.open(MYFILE,ifstream::in);

    char temp[LENBUFF]="";
    file2.seekg (posPdId+1,file2.beg);
    file2.read(temp,lenPdId);
    
    string stringtemp = temp;
    file2.close();
	return stringtemp;
}

void print_index(tIndex myindex){


	tIndex::iterator it;
	for( it = myindex.begin();it != myindex.end(); ++it)
	{
    	cout << it->first << " " << it->second.first << " " << it->second.second << "\n";
	}

   return;
}



struct orderbyx
{
	mytype x;
	mytype pdid;
	bool operator<(const orderbyx& rhs) const
    {
        return x < rhs.x;
    }
};

struct orderbyy
{
	mytype y;
	mytype pdid;
    bool operator<(const orderbyy& rhs) const
    {
        return y < rhs.y;
    }
};



struct compare_x
{
  bool operator()(const orderbyx& l, const orderbyx& r)
  {
      return l.x < r.x;
  }
};

struct compare_y
{
  bool operator()(const orderbyy& l, const orderbyy& r)
  {
      return l.y < r.y;
  }
};


typedef priority_queue< orderbyx ,vector<orderbyx>, compare_x > Xqueue;
typedef priority_queue< orderbyy ,vector<orderbyy>, compare_y > Yqueue;



//typedef std::priority_queue< orderbyx > Xqueue;
//typedef std::priority_queue< orderbyy > Yqueue;






int main(){


	Xqueue my_x_queue;
	Yqueue my_y_queue;

	
	ifstream file;
	char* pt = NULL;
	char buff[LENBUFF];
	tIndex myindex;
	mytype count = 0.0;
	mytype lenCurr = 0.0;


	file.open(MYFILE,ifstream::in);

	//read headtop text
	file.getline(buff,LENBUFF);
	lenCurr = strlen(buff);
	count+=lenCurr;

	//read body text


	while(!file.eof())
	{	
		file.getline(buff,LENBUFF);
		lenCurr = strlen(buff);
		
		char temp_buff[LENBUFF];
		char xx[LENBUFF];
		char yy[LENBUFF];
		char pdid[LENBUFF];


		pt = strtok(buff,",");//1
		sprintf(temp_buff,"%s",pt);
		if(temp_buff[0]=='\"'){
			while(pt!=NULL){
				pt = strtok(NULL,",");//3
				sprintf(temp_buff,"%s",pt);
				int len = strlen(temp_buff);
				if(temp_buff[len-1]=='\"'){
					break;
				}
			}
		}

		pt = strtok(NULL,",");//2
		sprintf(temp_buff,"%s",pt);
		if(temp_buff[0]=='\"'){
			while(pt!=NULL){
				pt = strtok(NULL,",");//3
				sprintf(temp_buff,"%s",pt);
				int len = strlen(temp_buff);
				if(temp_buff[len-1]=='\"'){
					break;
				}
			}
		}

		pt = strtok(NULL,",");//3
		sprintf(temp_buff,"%s",pt);
		if(temp_buff[0]=='\"'){
			while(pt!=NULL){
				pt = strtok(NULL,",");//3
				sprintf(temp_buff,"%s",pt);
				int len = strlen(temp_buff);
				if(temp_buff[len-1]=='\"'){
					break;
				}
			}
		}

		pt = strtok(NULL,",");//4
		sprintf(temp_buff,"%s",pt);
		if(temp_buff[0]=='\"'){
			while(pt!=NULL){
				pt = strtok(NULL,",");//3
				sprintf(temp_buff,"%s",pt);
				int len = strlen(temp_buff);
				if(temp_buff[len-1]=='\"'){
					break;
				}
			}
		}

		pt = strtok(NULL,",");//5
		sprintf(temp_buff,"%s",pt);
		if(temp_buff[0]=='\"'){
			while(pt!=NULL){
				pt = strtok(NULL,",");//3
				sprintf(temp_buff,"%s",pt);
				int len = strlen(temp_buff);
				if(temp_buff[len-1]=='\"'){
					break;
				}
			}
		}
		pt = strtok(NULL,",");//6
		sprintf(temp_buff,"%s",pt);
		if(temp_buff[0]=='\"'){
			while(pt!=NULL){
				pt = strtok(NULL,",");//3
				sprintf(temp_buff,"%s",pt);
				int len = strlen(temp_buff);
				if(temp_buff[len-1]=='\"'){
					break;
				}
			}
		}
		pt = strtok(NULL,",");//7
		sprintf(temp_buff,"%s",pt);
		if(temp_buff[0]=='\"'){
			while(pt!=NULL){
				pt = strtok(NULL,",");//3
				sprintf(temp_buff,"%s",pt);
				int len = strlen(temp_buff);
				if(temp_buff[len-1]=='\"'){
					break;
				}
			}
		}
		pt = strtok(NULL,",");//8

		sprintf(temp_buff,"%s",pt);
		if(temp_buff[0]=='\"'){
			while(pt!=NULL){
				pt = strtok(NULL,",");//3
				sprintf(temp_buff,"%s",pt);
				int len = strlen(temp_buff);
				if(temp_buff[len-1]=='\"'){
					break;
				}
			}
		}

		pt = strtok(NULL,",");//9
		sprintf(temp_buff,"%s",pt);
		if(temp_buff[0]=='\"'){
			while(pt!=NULL){
				pt = strtok(NULL,",");//3
				sprintf(temp_buff,"%s",pt);
				int len = strlen(temp_buff);
				if(temp_buff[len-1]=='\"'){
					break;
				}
			}
		}
		pt = strtok(NULL,",");//10
		sprintf(xx,"%s",pt);
		
		pt = strtok(NULL,",");//11
		sprintf(yy,"%s",pt);
		
		

		while( pt != NULL )
		{
			sprintf(pdid,"%s",pt);
			pt=strtok(NULL,",");
		}

		
		
		if(lenCurr){
			cout << std::fixed;
    		cout << std::setprecision(15);	

			orderbyx x;
			x.x = atof(xx);
			x.pdid = atof(pdid);
			my_x_queue.push(x);

			orderbyy y;
			y.y = atof(yy);
			y.pdid = atof(pdid);
			my_y_queue.push(y);
		}
	 				
	}
	
   	file.close();

   	mytype distance_x =100.000; 
   	mytype distance_y =100.000; 


   	while(!my_x_queue.empty()){
   		orderbyx x1;
   		x1.x 	= my_x_queue.top().x;
   		x1.pdid = my_x_queue.top().pdid;
   		my_x_queue.pop();
   		
   		orderbyx x2;
   		x2.x 	= my_x_queue.top().x;
   		x2.pdid = my_x_queue.top().pdid;

   		mytype temp = x1.x-x2.x;
   		temp=temp<0?temp*(-1):temp;
   		if( (temp>0) && distance_x>temp){
   			distance_x = temp;
   		}
   	}



   	while(!my_y_queue.empty()){
   		orderbyy y1;
   		y1.y 	= my_y_queue.top().y;
   		y1.pdid = my_y_queue.top().pdid;
   		my_y_queue.pop();

   		orderbyy y2;
   		y2.y 	= my_y_queue.top().y;
   		y2.pdid = my_y_queue.top().pdid;
   		
   		mytype temp = y1.y-y2.y;
   		temp=temp<0?temp*(-1):temp;

   		if( (temp>0) && distance_y>temp){
   			distance_y = temp;
   		}
   	}

   	cout << std::fixed;
    cout << std::setprecision(20);
    cout<<"x: "<<distance_x<<endl;

   	cout << std::fixed;
    cout << std::setprecision(20);
    cout<<"y: "<<distance_y<<endl;
   	


	return 0;
}





















