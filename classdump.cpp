#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <iomanip>
#include "classdump.hpp"

using namespace std;

string getBytes(FILE *fp , int n){
  string bytes = "";
  int temp = 0;
  while (temp < n){
    bytes += fgetc(fp);
    temp += 1;
  }
  return bytes;
}

short getShort(FILE *fp){
  int x = fgetc(fp);
  int y = fgetc(fp);
  return (short)y;
}

void printBytes(string in){
  char temp[in.length()+1];
  strcpy(temp,in.c_str());
  for(int i = 0; i< in.length() +1 ; i++){
    if(temp[i] >0xFFFFFF00){
      cout << setw(2) << setfill('0') <<hex << temp[i] - 0xFFFFFF00 << " ";
    }else{
      cout << setw(2)<< setfill('0') << hex << temp[i] << " ";
    }
  }
  cout<<endl;
}


int main(int argc, char **argv)
{     
  FILE *f = fopen(argv[1], "r");
  cout<< "------Bytecode------ "<<endl;
  int count = 0;
  int i = fgetc(f);
  while( i != EOF){
    if(i >0xFFFFFF00){
      cout << setw(2) << setfill('0') <<hex << i - 0xFFFFFF00 << " ";
    }else{
      cout << setw(2)<< setfill('0') << hex << i << " ";
    }
    i = fgetc(f);
    count +=1;
    if (!(count %8)){
      cout<<endl;
    }
  }
  cout<<endl<<endl;
  fclose(f);
  FILE *fp = fopen(argv[1], "r");

  //magic number
  string magic = getBytes(fp,4);
  cout<< "------Magic Number------ "<<endl;
  printBytes(magic);
   
  //version number
  cout<< "------Version Number------"<<endl;
  cout<< "Minor Version: ";
  short minorVersion = getShort(fp);
  cout << dec << minorVersion << endl;
  cout<< "Major Version: ";
  short majorVersion = getShort(fp);
  cout << dec << majorVersion << endl;

  //constant_pool_count
  cout<< "------Constant Pool Count------"<<endl;
  short constant_pool_count = getShort(fp);
  cout << dec << constant_pool_count << endl;

  //constant_pool[]
  cout<< "------constant_pool------"<<endl;
  int t = fgetc(fp);
  switch (t){
    case 1:
    //CONSTANT_Utf8
    
  }
  cout << t << endl;


  return 0;
}