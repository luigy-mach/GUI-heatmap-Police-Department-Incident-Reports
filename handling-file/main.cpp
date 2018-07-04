#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



using namespace std;

#define MYFILE "db.csv"
//#define MYFILE "db-test.csv"
#define LENBUFF 500


struct cmp_str
{
   bool operator()(char const *a, char const *b)
   {
      return std::strcmp(a, b) < 0;
   }
};

typedef double mytype;
typedef std::pair < mytype, mytype  > posLen;
//typedef std::map  < double, posLen > tIndex;
typedef std::map  < string, posLen > tIndex;


string find_pdid(tIndex myindex, string pdid){

	tIndex::iterator it = myindex.find(pdid);

	if( it == myindex.end()){
		return "Error PdId";
	}
	//cout<<"//////////1"<<endl;
	////cout<< it->second.first <<" // "<< it->second.second <<endl;
	//cout << it->first << " " << it->second.first << " " << it->second.second << "\n";
	//cout<<"//////////2"<<endl;
	mytype posPdId = it->second.first;
	mytype lenPdId = it->second.second;


	ifstream file2;
	char buff[LENBUFF];

	//mytype lenHead = 0.0;
	file2.open(MYFILE,ifstream::in);
	//file2.getline(buff,LENBUFF);
	//lenHead = strlen(buff);
	

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

int main(){

	
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

		pt = strtok(buff,",");
		char pdid[LENBUFF];
		while( pt != NULL)
		{
			sprintf(pdid,"%s",pt);
			pt=strtok(NULL,",");

		}
		if(lenCurr){
			//int intPdId = atoi(pdid); // error data > 15 digit
			posLen pltemp = make_pair(count,lenCurr);
			//myindex[intPdId] = pltemp;
			string stringtemp = pdid;
			myindex[stringtemp] = pltemp;
		}
		strcpy(buff, "");

		count+=lenCurr+1;
	}
	
   	file.close();

   	//print_index(myindex);
   	//cout<<find_pdid(myindex,"16091903228160")<<endl;

   	while(1){
   		cout<<"inserte consulta:"<<endl;
   		string myconsul;
   		cin>>myconsul;
	   	cout<<find_pdid(myindex,myconsul)<<endl;
	   	cout<<endl;
   	}


	return 0;
}





















