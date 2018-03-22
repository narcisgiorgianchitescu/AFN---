#include <fstream>
#include <vector>
#include <string>
using namespace std;
ifstream f("..\\date.in");
ofstream g("..\\date.out");
int start , nr_stari_finale, n, m, i, x, z;
char y;
int finale[100];
int  mat[100][100][100];
int viz[101];
string cuvant;
char stack[1001];
int gasit;
void Narcis ( int nod , string cuv , int k ){
    if ( cuv.size() and !gasit ) {
        int x = cuv[0] - 'a' + 1;
        stack[k] = cuv[0];
        for ( int i = 1 ; i <= mat[nod][x][0] ; i++ ){
            viz[mat[nod][x][i]] = 1;
            cuv.erase(cuv.begin() , cuv.begin()+1 ) ;
            Narcis(mat[nod][x][i] , cuv , k+1 );
            cuv.insert(cuv.begin(), stack[k]) ;
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
    f >> start >> nr_stari_finale ;
    f >> n >> m ;
    for ( i = 0 ; i < m ; i++ ){
        f >> x >> y >> z;
        mat[x][y-'a'+1][++mat[x][y-'a'+1][0]] = z;
    }
    for ( i = 0 ; i < nr_stari_finale ; i++ )
        f >> finale[i];
    f >> cuvant;
    Narcis(start , cuvant, 0);
    if ( !gasit )
        g << "Neacceptat!";
    return 0;
}
