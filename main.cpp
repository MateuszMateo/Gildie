#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <deque>
#include <functional>
#include <vector>
#include <map>

using namespace std;

int n;
const int MAX_N = 200000;
vector<int> tablica_sasiedztwa[MAX_N+1];
bool wynik[MAX_N+1];
bool dodane[MAX_N+1];

int znajdz_nieprzejrzane_miasto(){
    for(int i=0;i<n;++i){
        if(dodane[i]==false){
            return i;
        }
    }
    return -1;
}

void dfs(int miasto){

    //cout << "sprawdzam miasto " << miasto << endl;
    dodane[miasto]=true;
    for(int i=0;i<tablica_sasiedztwa[miasto].size();++i){
        if(!dodane[tablica_sasiedztwa[miasto][i]]){
//            if(wynik[miasto]){
//                wynik[tablica_sasiedztwa[miasto][i]]=false;
//            }else{
//                wynik[tablica_sasiedztwa[miasto][i]]=true;
//            }
            wynik[tablica_sasiedztwa[miasto][i]] = !wynik[miasto];
            dfs(tablica_sasiedztwa[miasto][i]);
        }
    }
}

//void bfs(int start) {
//    for(int i=0;i<MAX_N;++i){
//        dodane[i]=false;
//    }
//    deque<int> kolejka;
//    while(1){
//        int miasto_poczatkowe = znajdz_nieprzejrzane_miasto();
//        if(miasto_poczatkowe == -1) {
//            break;
//        }
//        wynik[miasto_poczatkowe]=true;
//        dodane[miasto_poczatkowe]=true;
//        kolejka.push_back(miasto_poczatkowe);
//        while(kolejka.size() > 0){
//            int numer_miasta= kolejka.front();
//            kolejka.pop_front(); // kolejka[0];
//            for(int i=0;i<tablica_sasiedztwa[numer_miasta].size();++i){
//                if(dodane[tablica_sasiedztwa[numer_miasta][i]]==false){
//                    kolejka.push_back(tablica_sasiedztwa[numer_miasta][i]);
//                    dodane[tablica_sasiedztwa[numer_miasta][i]]=true;
//                    if(wynik[numer_miasta]==true){
//                        wynik[tablica_sasiedztwa[numer_miasta][i]]=false;
//                    }else{
//                        wynik[tablica_sasiedztwa[numer_miasta][i]]=true;
//                    }
//                }
//            }
//        }
//    }
//}

int main()
{
    int m;
    cin >> n;
    cin >> m;
    for(int i=0;i<m;++i){
        int j;
        int k;
        cin>>j;
        cin>>k;
        tablica_sasiedztwa[j-1].push_back(k-1);
        tablica_sasiedztwa[k-1].push_back(j-1);
    }
    //    for(int i=0;i<n;++i){
    //        cout<<"miasto numer:"<<i<<endl;
    //        for(int j=0;j<tablica_sasiedztwa[i].size();j++){
    //            cout<<tablica_sasiedztwa[i][j]<<" ";
    //        }
    //        cout<<endl;
    //    }
    for(int i=0; i<n; ++i){
        if(tablica_sasiedztwa[i].size()==0){
            cout<<"NIE"<<endl;
            return 0;
        }
    }
    cout<<"TAK"<<endl;

    wynik[0]=true;
    for(int i=0;i<MAX_N;++i){
        dodane[i]=false;
    }
    while(1){
        int miasto_poczatkowe = znajdz_nieprzejrzane_miasto();
        if(miasto_poczatkowe == -1) {
            break;
        }
        wynik[miasto_poczatkowe]=true;
        dfs(miasto_poczatkowe);
    }
    for(int i=0;i<n;++i){
        if(wynik[i]){
            cout<<"S"<<endl;
        }else{
            cout<<"K"<<endl;
        }
    }


    return 0;
}

