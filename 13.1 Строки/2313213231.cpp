#include <iostream>

using namespace std;

#define arraySize(a) (sizeof(a)/sizeof((a)[0]))

int main(){
	char str[] = "abababbccbcbababcaabcbcbabcx"; //"abababbccbcbababcaabcbcbabc"
	int str_size = arraySize(str) - 1;
	int i = 0;
	int sit = 0;
	bool done = false;
	char znak = 'a';
	
	cout << str_size;
	
	while(done == false){
		for(int k = 0; k <= str_size; k++){
			int temp = str[k];
			int temp2;
			str[k] = znak;
			
			
		for(int l = 1; l < str_size; l++){
			temp2 = temp;
			temp = str[l];
			str[l] = temp2;
		}
		
		cout << str;
	
		while(str[0] != ' '){
		char X, O;
		
		while(i < str_size){
			while(str[i] == ' ')
				i++;
			X = str[i];
			if(str[i+1] != X)
				O = str[i+1];
			else{
				i++;
				break;
			}
			if(str[i+2] == X && str[i+3] == O){
				for(int j = 0; j < 4; j++){
					str[i+j] = ' ';
				} 
				i = i + 4;
			}else{
				i++;
				break;
			}	
			i = 0;
		}			
		}
		char str[] = "abababbccbcbababcaabcbcbabcx";
		}
	
	cout << "DONE!";
	done = true;
	}
	
	return 0;
}
