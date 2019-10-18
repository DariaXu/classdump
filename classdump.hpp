#include <string>
using namespace std;

string getBytes(FILE *fp , int n);
short getShort(FILE *fp);
int getInt(FILE *fp);
long getLong(FILE *fp);
void printBytes(string in);
void cp(short constant_pool_count,FILE *fp);
void af(short access_flags );

struct CONSTANT_Utf8_info {
    char tag;
    short length;
    char* data;
};

struct CONSTANT_Integer_info {
    char tag;
    int data;
};

struct CONSTANT_Float_info {
    char tag;
    float data;
};

struct CONSTANT_Long_info {
    char tag;
    long data;
};

struct CONSTANT_Double_info {
    char tag;
  double data;
};

struct CONSTANT_Class_info {
    char tag;
    short name_index;
};

struct CONSTANT_String_info {
    char tag;
    short string_index;
};

struct CONSTANT_Fieldref_info {
    char tag;
    short class_index;
    short name_and_type_index;
};

struct CONSTANT_Methodref_info {
    char tag;
    short class_index;
    short name_and_type_index;
};

struct CONSTANT_InterfaceMethodref_info {
    char tag;
    short class_index;
    short name_and_type_index;
};

struct CONSTANT_NameAndType_info {
    char tag;
    short name_index;
    short descriptor_index;
};

struct CONSTANT_MethodHandle_info {
    char tag;
    char reference_kind;
    short reference_index;
};

struct CONSTANT_MethodType_info {
    char tag;
    short descriptor_index;
};

struct CONSTANT_InvokeDynamic_info {
    char tag;
    short bootstrap_method_attr_index;
    short name_and_type_index;
};
