#include <cstdlib> 
#include <iostream>
using namespace std;
int main() 
{ 
		for(int i=0;i<10;i++){
			int random_integer = rand()%10; 
    cout <<"random number"<<random_integer<<"generated" << endl; 
		}
}