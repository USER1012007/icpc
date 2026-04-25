
#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> v1, vector<int> v2){

  int rep;
  bool choose_vec;
  if(v1.size() <= v2.size()){
    rep = v1.size();
    choose_vec = false;
  }else{
    rep = v2.size();
    choose_vec = true;
  }
  
  for(int i = 1; i < rep; i++){
    if(v1[i] != v2[i]){
      if(v1[i] < v2[i]){
        return false;
      }else{
        return true;
      }
    } 
  }

  if(!choose_vec)return false;
  else return true;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_tomes;
    int n_queries;

    cin >> n_tomes >> n_queries;
    

    vector<int> prime_numbers;
    
    //Encontrar los numeros primos dentro el rango de numeros dado
    //y guardarlos en el vector prime_numbers
    for(int i = 2; i <= n_tomes; i++){
        bool is_prime = true;
        for(int j = 2; j < i; j++){
            if( i % j == 0){
                is_prime = false;
                break;
            } 
        }
        if(is_prime)prime_numbers.push_back(i);
    }

    //Hacemos un vector de vectores para guardar los factores de cada numero 
    //Iniciamos el primer vector:
    //Numero(1)  Factores(1)
    //Nunca lo vamos a tocar porque siempre estará en la primera posición
    vector<vector<int>> factors(n_tomes);
    factors[0] = {1, 1};

    //Elegimos los factores de cada número
    for(int i = 2; i <= n_tomes; i++){
        int n = i;
        factors[i-1].push_back(i);
        for(int j = 0; j < prime_numbers.size(); j++){
            if(n % prime_numbers[j] == 0){
                factors[i-1].push_back(prime_numbers[j]);
                n /= prime_numbers[j];
                j--;
            }
        }
    }

    //Elegimos el vector que deberia ir en cada posicion de factors y los intercambiamos
    for(int i = 1; i < n_tomes; i++){
      int index = i;
      for(int j = i+1; j < n_tomes; j++){
        bool swap_index = compare(factors[index] ,factors[j]);
        if(swap_index)index=j;
      }
      swap(factors[i], factors[index]);
    }

    //Mostrar factores ordenados
    //for(int i = 0; i < n_tomes; i++){
    //    cout << endl;
    //    for(int j : factors[i])cout << j << " ";
    //}
    
    vector<int> queries(n_queries);
    for(int i = 0; i < n_queries; i++){
      cin >> queries[i];
    }

    for(int i = 0; i < n_queries; i++){
      int index = factors[queries[i]-1][0];
      cout << index << endl;
    }
   
    return 0;
}
