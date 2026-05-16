
#include<bits/stdc++.h>
using namespace std;

string clasify(string numero){
    string num_copy = numero;

    int count_zero = 0;
    while(1){
        int back_pos = numero.size()-1;
        if(numero[back_pos]=='0'){
            count_zero++;
            numero.erase(back_pos, 1);
        }else break;
    }
    
    if(count_zero >= 4){

        if(numero=="1"){
            return "10^{"+to_string(count_zero)+"}";
        }else{
            if(numero.size()>1){
                count_zero+=(numero.size()-1);
                numero.insert(1, ".");
            }
            return numero+"\\cdot10^{"+to_string(count_zero)+"}";
        }

    }

    return num_copy;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();
    string output = "";

    for(int i = 0; i < n; i++){

        string line;
        getline(cin, line);

        int count_n = 0;

        for (int j = 0; j < line.size(); j++){

            bool act_isdigit = isdigit(line[j]);
            bool prev_isnotdigit = (j == 0) || !isdigit(line[j-1]);

            if( act_isdigit && prev_isnotdigit ) count_n++;
            
        }

        if(count_n>0){

            string numbers[count_n];
            int positions[count_n][2];
            int i_num = 0;

            for(int j = 0; j < count_n; j++)numbers[j]="";

            for(int j = 0; j < line.size(); j++){

                bool act_isdigit = isdigit(line[j]);

                if(act_isdigit){

                    bool prev_isnotdigit = (j == 0) || !isdigit(line[j-1]);
                    bool next_isnotdigit = (j == line.size()-1) || !isdigit(line[j+1]);
                    numbers[i_num]+=line[j];

                    if(prev_isnotdigit)positions[i_num][0]=j;
                    if(next_isnotdigit){
                        positions[i_num][1]=j;
                        i_num++;
                    }
                    
                }

            }

            for(int j = (count_n-1); j >= 0; j--){
                string temp = numbers[j];
                bool prev_isvoid = (positions[j][0] == 0) || (line[positions[j][0]-1] == ' ');
                bool next_isvoid = (positions[j][1] == ((int)line.size()-1)) || (line[positions[j][1]+1] == ' ');
                if(prev_isvoid && next_isvoid){
                    temp = clasify(numbers[j]);
                }
                line.replace(positions[j][0], (positions[j][1]-positions[j][0]+1), temp);
            }

        }

        output = output + line + "\n";

    }

    cout << output;

    return 0;
}
