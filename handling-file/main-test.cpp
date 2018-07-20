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
#define MYFILEIN "db.csv"
#define MYFILEOUT "myoutput.csv"
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

typedef map < string, posLen > indexPdId;
typedef map < string, vecString > indexTime;
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
		char PdDistrict[LENBUFF];
		char Category[LENBUFF];
		char Time[LENBUFF];
		char PdId[LENBUFF];



		pt = strtok(buff,",");//IncidntNum
		//sprintf(temp_buff,"%s",pt);
		//if(temp_buff[0]=='\"'){
		//	while(pt!=NULL){
		//		pt = strtok(NULL,",");
		//		sprintf(temp_buff,"%s",pt);
		//		int len = strlen(temp_buff);
		//		if(temp_buff[len-1]=='\"'){
		//			break;
		//		}
		//	}
		//}

		pt = strtok(NULL,",");//Category
		sprintf(Category,"%s",pt);
		//sprintf(temp_buff,"%s",pt);
		//if(temp_buff[0]=='\"'){
		//	while(pt!=NULL){
		//		pt = strtok(NULL,",");
		//		sprintf(temp_buff,"%s",pt);
		//		int len = strlen(temp_buff);
		//		if(temp_buff[len-1]=='\"'){
		//			break;
		//		}
		//	}
		//}

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
		//sprintf(temp_buff,"%s",pt);
		//if(temp_buff[0]=='\"'){
		//	while(pt!=NULL){
		//		pt = strtok(NULL,",");
		//		sprintf(temp_buff,"%s",pt);
		//		int len = strlen(temp_buff);
		//		if(temp_buff[len-1]=='\"'){
		//			break;
		//		}
		//	}
		//}

		pt = strtok(NULL,",");//Date
		//sprintf(temp_buff,"%s",pt);
		//if(temp_buff[0]=='\"'){
		//	while(pt!=NULL){
		//		pt = strtok(NULL,",");
		//		sprintf(temp_buff,"%s",pt);
		//		int len = strlen(temp_buff);
		//		if(temp_buff[len-1]=='\"'){
		//			break;
		//		}
		//	}
		//}


		pt = strtok(NULL,",");//Time
		sprintf(Time,"%s",pt);
		//sprintf(temp_buff,"%s",pt);
		//if(temp_buff[0]=='\"'){
		//	while(pt!=NULL){
		//		pt = strtok(NULL,",");
		//		sprintf(temp_buff,"%s",pt);
		//		int len = strlen(temp_buff);
		//		if(temp_buff[len-1]=='\"'){
		//			break;
		//		}
		//	}
		//}

		pt = strtok(NULL,",");//PdDistrict
		sprintf(PdDistrict,"%s",pt);
		//sprintf(temp_buff,"%s",pt);
		//if(temp_buff[0]=='\"'){
		//	while(pt!=NULL){
		//		pt = strtok(NULL,",");
		//		sprintf(temp_buff,"%s",pt);
		//		int len = strlen(temp_buff);
		//		if(temp_buff[len-1]=='\"'){
		//			break;
		//		}
		//	}
		//}


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




//PdDistrict, Category , Time 



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

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3));

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
	return "todo bien";
}

int main(){



	open_db();
	


	cout<<"-------------------------------"<<endl;
	vecString temp_Time = find_Time(myindexTime,"14:00");
	cout<<"-------------------------------"<<endl;
	vecString temp_PdDistrict = find_PdDistrict(myindexPdDistrict,"PARK");
	cout<<"-------------------------------"<<endl;
	vecString temp_Category = find_Category(myindexCategory,"NON-CRIMINAL");
	cout<<"-------------------------------"<<endl;
	


	vecString temp1 = vecString_intersection(temp_PdDistrict,temp_Category);
	vecString temp2 = vecString_intersection(temp_Time,temp_Category);
	vecString myresult = vecString_intersection(temp1,temp2);

	cout<<"-------------------------------"<<endl;

	print_file_myresult(myresult);
	
	cout<<"-------------------------------"<<endl;

    
    system("python genarate-heatmap.py");



	return 0;
}





















