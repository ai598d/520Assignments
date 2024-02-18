#include <iostream>
#include <vector>
#include <algorithm>
#include "utilities.h"  
#include <fstream>
#include <string>
#include <sstream>
#include <cstring> 
#include <map>

using namespace std;
//void Print_vec(vector<double> &x);
//void sort_by_magnitude(vector<double> &x);

int main(){
    
    // ****************************************Test sort_by_magnitude()

    /*    
    double mydob[] = {32,71,-12,45,-26,-80,53,33};
    vector<double> myvector(mydob,mydob+8);
    cout<<"Print before sorting:"<<endl;
    Print_vec(myvector);
    sort_by_magnitude(myvector);
    cout<<"Print after sorting:"<<endl;
    Print_vec(myvector);
    */
    

    // **********************************************   Test : read_matrix_csv(const string path); && write_matrix_csv(const TypedArray<TypedArray<double>> &matrix, const string path);

    /*
    TypedArray<TypedArray<double>> matrix ;    

    matrix = read_matrix_csv("test.csv"); // read data from test csv

    write_matrix_csv(matrix, "write_result.csv" ); // write to a csv file
    */
 
   
   //*******************************************************  Test :   occurrence_map(const string path);

   
    map<string, int> mp;
    mp = occurrence_map("myfile.txt");
    //cout<<mp.at("coffee")<<endl;
   
    cout<<mp.at("monkey")<<endl;

    

    return 0;
}


void Print_vec(vector<double> &x){

    int vec_len = x.capacity();
    
    for(int i =0;i<vec_len;i++){

        cout<<x.at(i)<<"\n"<<endl;

    }
}

void sort_by_magnitude(vector<double> &x){

    int size_vec = x.capacity();
    sort(x.begin(), x.begin()+size_vec, [](double a, double b){return (abs(a)<abs(b));});

}




void push_back(TypedArray<double>& x,  double y){

    x.set(x.size(),y);
}

void push_backTA(TypedArray<TypedArray<double>>& x,  TypedArray<double>& y){

    x.set(x.size(),y);
}


TypedArray<TypedArray<double>> read_matrix_csv(const string path){

    
    TypedArray<TypedArray<double>> content;
    //TypedArray<string> row;
    string line, word;
 
    fstream file (path, ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            TypedArray<double> row;//row.clear();
 
            stringstream str(line);
 
            while(getline(str, word, ','))
               push_back(row,stod(word));//row.push_back(word);
               push_backTA(content,row); //content.push_back(row);
        }
    }
    else{
        cout<<"Could not open the file\n";
        }

        return content;


}

void write_matrix_csv(const TypedArray<TypedArray<double>> &matrix, const string path){

    ofstream outfile;
	outfile.open(path);

    for(int i=0;i<matrix.size();i++)
    {
        TypedArray<double> p = matrix.safe_get(i);

        for(int j=0;j<p.size();j++)
        {
            outfile<<p.get(j)<<", ";
        }
        outfile<<"\n";
    }



}

char* string_2_char(string &A ){

    
    const int length = A.length(); 
  
    // declaring character array (+1 for null terminator) 
    char* char_array = new char[length + 1]; 
  
    // copying the contents of the 
    // string to char array 
    strcpy(char_array, A.c_str()); 
  
    //for (int i = 0; i < length; i++) 
    //{ 
        //std::cout << char_array[i]; 
    //} 
    
    return char_array; 
    
    
}

bool Does_B_Occur_In_A(string &A , string &B){

    const int length = A.length(); 
    bool B_in_A;
    char* string_A = string_2_char(A);
    char* string_B = string_2_char(B);

    for(int i=0; i<length; i++){


        if(string_A[i] == string_B[0]){
            B_in_A = 1;
            i = length; // found a match. get outta loop;
        }

        else{

            B_in_A = 0;
        }
    }

    delete[] string_A;
    delete[] string_B;
    
    return B_in_A;

}

int How_Many_Times(string &A , const string path){

    ifstream file;
    file.open (path);
    if (!file.is_open()) {return 0;}

    int count=0;
    

    string word;
    while (file >> word)
    {


        //cout<< word << '\n';
        if (A.compare(word) == 0){

            count=count+1;

        }
        
       
    }

    return count;

}

map<string, int> occurrence_map(const string path){

    

    map<string, int> mp;
    string special_char[6]={"%","$","sh","fh","(","_"};
    ifstream file;
    file.open ("myfile.txt");
    //if (!file.is_open()) {return 0;}
    
    bool flag;
    string word;

    //map<string, int>::iterator it = mp.begin();

    while (file >> word)
    {

       flag = 1;
       int count ;
        //cout<< word << '\n';

        // check for special char
        for(int i = 0;i<6;i++){

           // cout<<"spc check"<<endl;

            if(Does_B_Occur_In_A(word,special_char[i])){

                flag = 0;
            }


        }

        if(flag){

            cout<<"cheking mp insert"<<endl;
            count = How_Many_Times(word , path);
            mp.insert(pair<string,int>(word,count));


        }
        
       
    }


 return mp;

}