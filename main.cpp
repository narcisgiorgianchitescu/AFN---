#include <fstream>
#include <vector>
#include <string>
using namespace std;
ifstream f("..\\date.in");
ofstream g("..\\date.out");
int start , nr_stari_finale, n, m, i, x, z;
char y;
int finale[100];
int  mat[100][100][100];    //matricea de muchii. unde o muchie reprezinta o productie
string cuvant;   //cuvantul care trebuie verificat
char stiva[1001];   //stiva folosita pentru revenirea din apelurile recursive
int gasit;   //variabila in care retin daca am gasit o stare finala odata cu epuizarea literelor cuvantului

//problema este modelata cu ajutorul grafurilor, productiile sunt reprezentate intern astfel
//daca din starea 1 se poate ajunge in starea 2 cu b, atunci mat[1]['b'-'a'+1][1] = 2;

//general, mat[x][y][z] contine nodurile in care se poate ajunge din x folosind 'y'-'a'+1 (eticheta)

/**
 *
 * @param nod //reprezinta nodul curent
 * @param cuv  //reprezinta literele cuvantului ramas de parcurs
 * @param k   //reprezinta nivelul in stiva
 */
void verifica_validitate ( int nod , string cuv , int k ){
    if ( cuv.size() and !gasit ) {
        int x = cuv[0] - 'a' + 1;
        stiva[k] = cuv[0];
        for ( int i = 1 ; i <= mat[nod][x][0] ; i++ ){
            cuv.erase(cuv.begin() , cuv.begin()+1 ) ;
            verifica_validitate(mat[nod][x][i] , cuv , k+1 );
            cuv.insert(cuv.begin(), stiva[k]) ;
        }
    }else{
        if (!gasit)
            for ( int i = 0 ; i < nr_stari_finale ; i++ )
                if ( finale[i] == nod ){
                    g << "Acceptat!" ;
                    gasit = 1;
                }
    }
}
int main(){
    ////========== citirea datelor
    f >> start >> nr_stari_finale ;
    f >> n >> m ;
    for ( i = 0 ; i < m ; i++ ){
        f >> x >> y >> z;
        mat[x][y-'a'+1][++mat[x][y-'a'+1][0]] = z;   //memoram muchiile grafului
    }
    for ( i = 0 ; i < nr_stari_finale ; i++ )
        f >> finale[i];
    f >> cuvant;
    //===== verificare si afisare rezultat
    verifica_validitate(start , cuvant, 0);
    if ( !gasit )
        g << "Neacceptat!";
    return 0;
}
