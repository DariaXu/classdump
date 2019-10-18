#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
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
  short x = fgetc(fp);
  x = x << 8;
  short y = fgetc(fp);
  return (short)x|y;
}

int getInt(FILE *fp){
  int x = getShort(fp);
  x =  x << 16;
  int y = getShort(fp);
  return (int)x|y;
}

long getLong(FILE *fp){
  long lo = 0;
  for(int i = 7; i<=8;i++){
    long temp = fgetc(fp);
    temp = temp << i*8;
    lo = temp | lo;
  }
  return (long)lo;
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

void cp(short constant_pool_count,FILE *fp){
  //constant pool entry
  for (int i = 1; i<(int)constant_pool_count;i++){
    int tag = fgetc(fp);
    cout << "****Entry " << i <<"****"<<endl;
    switch (tag){
      case 1:
        //CONSTANT_Utf8
        struct CONSTANT_Utf8_info stu1;
        stu1.tag = tag;
        stu1.length = getShort(fp);
        stu1.data = strdup(getBytes(fp,stu1.length).c_str());
       // constant_pool[i] = stu;
        cout <<"Constant Type: "<< "CONSTANT_Utf8_info" << endl;
        cout <<"Tag: "<< tag << endl;
        cout <<"Length: "<< stu1.length << endl;
        cout <<"Data: "<< stu1.data << endl;
        cout << endl;
        break;
      case 3:
        //CONSTANT_Integer_info
        struct CONSTANT_Integer_info stu3;
        stu3.tag = tag;
        stu3.data = getInt(fp);
       // constant_pool[i] = stu;
        cout <<"Constant Type: "<< "CONSTANT_Integer_info" << endl;
        cout <<"Tag: "<< tag << endl;
        cout <<"Data: "<< stu3.data << endl;
        cout << endl;
        break;
      case 4:
        //CONSTANT_Float_info
        struct CONSTANT_Float_info stu4;
        stu4.tag = tag;
        stu4.data = (float)getInt(fp);
       // constant_pool[i] = stu;
       cout <<"Constant Type: "<< "CONSTANT_Float_info" << endl;
        cout <<"Tag: "<< tag << endl;
        cout <<"Data: "<< stu4.data << endl;
        cout << endl;
        break;
      case 5:
        //CONSTANT_Long_info
        struct CONSTANT_Long_info stu5;
        stu5.tag = tag;
        stu5.data = getLong(fp);
       // constant_pool[i] = stu;
       cout <<"Constant Type: "<< "CONSTANT_Long_info" << endl;
        cout <<"Tag: "<< tag << endl;
        cout <<"Data: "<< stu5.data << endl;
        cout << endl;
        break;
      case 6:
        //CONSTANT_Double_info
        struct CONSTANT_Double_info stu6;
        stu6.tag = tag;
        stu6.data = (double)getLong(fp);
       // constant_pool[i] = stu;
       cout <<"Constant Type: "<< "CONSTANT_Double_info" << endl;
        cout <<"Tag: "<< tag << endl;
        cout <<"Data: "<< stu6.data << endl;
        cout << endl;
        break;  
      case 7:
        //CONSTANT_Class_info
        struct CONSTANT_Class_info stu7;
        stu7.tag = tag;
        stu7.name_index = getShort(fp);
       // constant_pool[i] = stu;
       cout <<"Constant Type: "<< "CONSTANT_Class_info" << endl;
        cout <<"Tag: "<< tag << endl;
        cout <<"Name Index: "<< stu7.name_index << endl;
        cout << endl;
        break;    
      case 8:
        //CONSTANT_String_info
        struct CONSTANT_String_info stu8;
        stu8.tag = tag;
        stu8.string_index = getShort(fp);
       // constant_pool[i] = stu;
       cout <<"Constant Type: "<< "CONSTANT_String_info" << endl;
        cout <<"Tag: "<< tag << endl;
        cout <<"String Index: "<< stu8.string_index << endl;
        cout << endl;
        break;    
      case 9:
        //CONSTANT_Fieldref_info
        struct CONSTANT_Fieldref_info stu9;
        stu9.tag = tag;
        stu9.class_index = getShort(fp);
        stu9.name_and_type_index = getShort(fp);
       // constant_pool[i] = stu;
       cout <<"Constant Type: "<< "CONSTANT_Fieldref_info" << endl;
        cout <<"Tag: "<< tag << endl;
        cout <<"class_index: "<< stu9.class_index << endl;
        cout <<"name_and_type_index: "<< stu9.name_and_type_index << endl;
        cout << endl;
        break;
      case 10:
        //CONSTANT_Methodref_info
        struct CONSTANT_Methodref_info stu10;
        stu10.tag = tag;
        stu10.class_index = getShort(fp);
        stu10.name_and_type_index = getShort(fp);
       // constant_pool[i] = stu;
       cout <<"Constant Type: "<< "CONSTANT_Methodref_info" << endl;
        cout <<"Tag: "<< tag << endl;
        cout <<"class_index: "<< stu10.class_index << endl;
        cout <<"name_and_type_index: "<< stu10.name_and_type_index << endl;
        cout << endl;
        break;
      case 11:
        //CONSTANT_InterfaceMethodref_info
        struct CONSTANT_InterfaceMethodref_info stu11;
        stu11.tag = tag;
        stu11.class_index = getShort(fp);
        stu11.name_and_type_index = getShort(fp);
       // constant_pool[i] = stu;
       cout <<"Constant Type: "<< "CONSTANT_InterfaceMethodref_info" << endl;
        cout <<"Tag: "<< tag << endl;
        cout <<"class_index: "<< stu11.class_index << endl;
        cout <<"name_and_type_index: "<< stu11.name_and_type_index << endl;
        cout << endl;
        break;
      case 12:
        //CONSTANT_NameAndType_info
        struct CONSTANT_NameAndType_info stu12;
        stu12.tag = tag;
        stu12.name_index = getShort(fp);
        stu12.descriptor_index = getShort(fp);
       // constant_pool[i] = stu;
       cout <<"Constant Type: "<< "CONSTANT_NameAndType_info" << endl;
        cout <<"Tag: "<< tag << endl;
        cout <<"name_index: "<< stu12.name_index << endl;
        cout <<"descriptor_index: "<< stu12.descriptor_index << endl;
        cout << endl;
        break;
      case 15:
        //CONSTANT_MethodHandle_info
        struct CONSTANT_MethodHandle_info stu15;
        stu15.tag = tag;
        stu15.reference_kind = fgetc(fp);
        stu15.reference_index = getShort(fp);
       // constant_pool[i] = stu;
       cout <<"Constant Type: "<< "CONSTANT_MethodHandle_info" << endl;
        cout <<"Tag: "<< tag << endl;
        cout <<"reference_kind: "<< stu15.reference_kind << endl;
        cout <<"reference_index: "<< stu15.reference_index << endl;
        cout << endl;
        break;
      case 16:
        //CONSTANT_MethodType_info
        struct CONSTANT_MethodType_info stu16;
        stu16.tag = tag;
        stu16.descriptor_index = getShort(fp);
       // constant_pool[i] = stu;
       cout <<"Constant Type: "<< "CONSTANT_MethodType_info" << endl;
        cout <<"Tag: "<< tag << endl;
        cout <<"descriptor_index: "<< stu16.descriptor_index << endl;
        cout << endl;
        break;
      case 18:
        //CONSTANT_InvokeDynamic_info
        struct CONSTANT_InvokeDynamic_info stu18;
        stu18.tag = tag;
        stu18.bootstrap_method_attr_index = getShort(fp);
        stu18.name_and_type_index = getShort(fp);
       // constant_pool[i] = stu;
       cout <<"Constant Type: "<< "CONSTANT_InvokeDynamic_info" << endl;
        cout <<"Tag: "<< tag << endl;
        cout <<"bootstrap_method_attr_index: "<< stu18.bootstrap_method_attr_index << endl;
        cout <<"name_and_type_index: "<< stu18.name_and_type_index << endl;
        cout << endl;
        break;
    }
  }
}

void af(short access_flags ){
  //access_flags
  cout << "Access Flags Name: ";
  
    if (access_flags & 0x0001){
      //ACC_PUBLIC
      cout << "ACC_PUBLIC  ";
    }
    if(access_flags & 0x0010){
      //ACC_FINAL 
      cout << "ACC_FINAL  ";
    }
    if(access_flags & 0x0020){
      //ACC_SUPER 
      cout << "ACC_SUPER  ";
    }
    if(access_flags & 0x0200){
     //ACC_INTERFACE 
      cout << "ACC_INTERFACE  ";
    }
    if(access_flags & 0x0400){
      //ACC_ABSTRACT 
      cout << "ACC_ABSTRACT  ";
    }
    if(access_flags & 0x1000){
      //ACC_SYNTHETIC 
      cout << "ACC_SYNTHETIC  ";
    }
    if(access_flags & 0x2000){
      //ACC_ANNOTATION 
      cout << "ACC_ANNOTATION  ";
    }
    if(access_flags & 0x4000){
       //ACC_ENUM 
      cout << "ACC_ENUM  ";
    }
      
  cout<<endl<<endl;
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
  cout<< "------Constant Pool------"<<endl;
  cp(constant_pool_count,fp);
  /*
  struct {
    enum { CONSTANT_Utf8_info, CONSTANT_Integer_info, CONSTANT_Float_info,CONSTANT_Long_info,CONSTANT_Double_info,CONSTANT_Class_info, CONSTANT_Fieldref_info
    ,CONSTANT_Methodref_info,CONSTANT_InterfaceMethodref_info,CONSTANT_String_info,CONSTANT_NameAndType_info,CONSTANT_MethodHandle_info,CONSTANT_MethodType_info,CONSTANT_InvokeDynamic_info,CONSTANT_Module_info,CONSTANT_Package_info} type;
  } constant_pool[constant_pool_count+1];
  */
    
    //access_flags
    cout<< "------Access Flags------"<<endl;
    short access_flags = getShort(fp);
    string flag;
    stringstream ss;
    ss << setw(2) << setfill('0') << hex << access_flags;
    ss >> flag;
    cout << "Access Flags Value: "<< setw(4) << setfill('0') << flag <<endl;
    af(access_flags);

    //this_class
    cout<< "------This Class------"<<endl;
    short this_class = getShort(fp);
    cout << this_class <<endl;
    cout <<endl;

    //super_class
    cout<< "------Super Class------"<<endl;
    short super_class = getShort(fp);
    cout << super_class <<endl;
    cout <<endl;

    //interfaces_count
    cout<< "------Interfaces Count------"<<endl;
    short interfaces_count = getShort(fp);
    cout << interfaces_count <<endl;
    cout <<endl;

  return 0;
}